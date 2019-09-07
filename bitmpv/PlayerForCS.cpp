#include "stdafx.h"
#include"PlayerForCS.h"
#include "WinPlayer.h"
#include <thread>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
extern "C" {
#include <SDL.h>
#include "client.h"
#include "render_gl.h"
}
#include"CJsonObject.hpp"
#include<list>
#include"CJsonHelper.h"

// Example low level rendering Unity plugin

#include "NativeRenderingPlugin/PlatformBase.h"
#include "NativeRenderingPlugin/RenderAPI.h"



#include <assert.h>
#include <math.h>
#include <vector>

#include"WindowClient.h"
#include"D3Dinterface.h"
#include<d3d11.h>
#include"WglUtils.h"
#include "NativeRenderingPlugin/Unity/IUnityInterface.h"
#include "NativeRenderingPlugin/Unity/IUnityGraphics.h"
#include "NativeRenderingPlugin/Unity/IUnityGraphicsD3D11.h"
#include "NativeRenderingPlugin/gl3w/gl3w.h"

#pragma comment ( lib, "D3D11.lib")

struct RenderEnv
{
	LeoPlayer::WindowClient* windowWgl;
	LeoPlayer::WindowClient* windowShow;
	LeoPlayer::WglUtils* wglUtils;
	d3dtools::D3DInterface* d3dInterface;
	GLuint fbo;
	GLuint rtvNameGL;
	HANDLE rtvHandleGL;
	ID3D11Texture2D* dxColorBuffer;
	ID3D11Texture2D* unitySharedTexture;
	ID3D11Texture2D* unityTexture;
	int width;
	int height;
	int envType=1;//0 ,opengl to d3d use ,1 opengl to d3d use buffer.
	unsigned char* pixels;
	bool initDevice = false;
	//int videoWidth;
	//int videoHeight;
};

// flag to check if this plugin has initialized.
bool g_hasInitialized = false;
static bool g_isUnity = false;

static bool isStartEvent = false;
static HANDLE g_EventThreadHandle = NULL;
static SESSION *g_Session = NULL;


static RenderEnv g_renderEnv;


static ID3D11Device* g_D3D11Device = nullptr;
static IUnityGraphicsD3D11* d3d = nullptr;

static void* g_TextureHandle = NULL;
static int   g_TextureWidth = 0;
static int   g_TextureHeight = 0;
static IUnityInterfaces* s_UnityInterfaces = NULL;
static IUnityGraphics* s_Graphics = NULL;

void openglSave(void* textureHandle, int width, int height, unsigned char* pxls);

EXPORT_API SESSION* CreateSession()
{

	SESSION* session = (SESSION*)calloc(sizeof(SESSION), 1);
	if (NULL == session)return NULL;
	session->player = new LeoPlayer::WinPlayer();
	session->player->Reset();
	session->sharedTextureMutex_ = new std::mutex();
	g_Session = session;
	gl3wInit();
	return session;
}
EXPORT_API void DestroySession(SESSION* session)
{
	if (NULL == session || session->player == NULL) {
		return;
	}
	session->player->ReleasePlayer();
	delete session->player;
}
EXPORT_API void InitExtendDevice(SESSION* session)
{
	g_renderEnv.envType = 0;
	
	if (g_renderEnv.envType == 0 || g_renderEnv.envType == 1) {

		g_renderEnv.windowShow = new  LeoPlayer::WindowClient();
		g_renderEnv.windowShow->Create(0, 0, 640, 480);
		g_renderEnv.d3dInterface = new d3dtools::D3DInterface(g_renderEnv.windowShow);

		

		if (g_renderEnv.envType == 0) {
			g_renderEnv.windowWgl = new LeoPlayer::WindowClient();
			g_renderEnv.windowWgl->Create(0, 0, 640, 480);
			g_renderEnv.wglUtils = new LeoPlayer::WglUtils();
			g_renderEnv.wglUtils->InitWithWinIdAndDevice(g_renderEnv.windowWgl->GetWindowId(), g_renderEnv.d3dInterface->GetDevice());

		}
		

	}

}
EXPORT_API void SetWindowId(SESSION* session, void*  windowId, bool isTexture)
{
	if (NULL == session || session->player == NULL) {
		return;
	}

	session->player->SetWindowId((int64_t)windowId,isTexture);

	if (g_renderEnv.envType == 0 || g_renderEnv.envType == 1) 
	{
		session->gl = false;
		g_renderEnv.unityTexture = (ID3D11Texture2D*)windowId;
		HANDLE resource;
		D3D11_TEXTURE2D_DESC textureInfo;
		g_renderEnv.unityTexture->GetDesc(&textureInfo);
		HRESULT result;
		textureInfo.MiscFlags = D3D11_RESOURCE_MISC_SHARED;
		g_renderEnv.width = textureInfo.Width;
		g_renderEnv.height = textureInfo.Height;

		g_D3D11Device->CreateTexture2D(&textureInfo, nullptr, &g_renderEnv.unitySharedTexture);
		IDXGIResource* pOtherResource = NULL;
		result = g_renderEnv.unitySharedTexture->QueryInterface(__uuidof(IDXGIResource), (void**)& pOtherResource);
		result = pOtherResource->GetSharedHandle(&resource);
		ID3D11Texture2D* sharedTexture;
		GUID texture_guid = __uuidof(ID3D11Resource);
		result = g_renderEnv.d3dInterface->GetDevice()->OpenSharedResource(resource, texture_guid, (void**)& sharedTexture);
		g_renderEnv.dxColorBuffer = sharedTexture;


		if (g_renderEnv.envType == 0) {
			g_renderEnv.wglUtils->WglCreateFrameBuffer(&g_renderEnv.fbo);
			g_renderEnv.wglUtils->WglCreateTexture(&g_renderEnv.rtvNameGL);
			g_renderEnv.dxColorBuffer->GetDesc(&textureInfo);
			g_renderEnv.wglUtils->WglDXRegisterObjectNV(g_renderEnv.dxColorBuffer, &g_renderEnv.rtvHandleGL, g_renderEnv.rtvNameGL);
			g_renderEnv.wglUtils->BindFrameBufferTexture(g_renderEnv.fbo, GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, g_renderEnv.rtvNameGL, 0);
			if (g_renderEnv.rtvHandleGL == NULL) {
				g_renderEnv.envType == 1;
			}

		}

		if (g_renderEnv.envType == 1) {
			glGenTextures(1, &g_renderEnv.fbo);
			g_renderEnv.pixels = (unsigned char*)malloc( g_renderEnv.width * g_renderEnv.height * 4);

		}
		session->gl = true;
	}

	
	

}
EXPORT_API int OpenMovie(SESSION* session, const char* path) {
	if (NULL == session || session->player == NULL) {
		return -1;
	}
	session->player->SetDataSource(path);
	session->player->Start();
	return 0;
}
EXPORT_API void UpdatePlaybackInfo(SESSION*session)
{
	if (NULL == session || session->player == NULL) {
		return;
	}
	session->player->UpdatePlaybackInfo();

}

EXPORT_API void TogglePause(SESSION* session)
{
	if (NULL == session || session->player == NULL) {
		return;
	}
	session->player->Pause();
}

EXPORT_API void ToggleMute(SESSION* session,bool mute)
{
	if (NULL == session || session->player == NULL) {
		return;
	}
	session->player->SetMute(mute);
}

EXPORT_API bool IsPlaying(SESSION* session)
{
	if (NULL == session || session->player == NULL) {
		return false;
	}
	return session->player->IsPlaying();
}

EXPORT_API double GetCurrentPosition(SESSION* session)
{
	if (NULL == session || session->player == NULL) {
		return 0;
	}
	return session->player->GetCurrentPosition();
}

EXPORT_API double GetDuration(SESSION* session)
{
	if (NULL == session || session->player == NULL) {
		return 0;
	}
	return session->player->GetDuration();
}

EXPORT_API void SeekTo(SESSION* session, double position)
{
	if (NULL == session || session->player==NULL) {
		return;
	}
	session->player->SeekTo(position);
}

EXPORT_API void SetVolume(SESSION* session, double volume)
{
	if (NULL == session || session->player == NULL) {
		return;
	}
	return session->player->SetVolume(volume);
}

EXPORT_API double GetVolume(SESSION* session)
{
	return session->player->GetVolume();
}

EXPORT_API  int __stdcall GetPlaybackInfo(SESSION* session, char* s)
{
	if (NULL == session || session->player == NULL) {
		return NULL;
	}
	LeoPlayer::PlaybackInfo info = session->player->GetPlaybackInfo();
	neb::CJsonObject oJson = CJsonHelper::GetJsonFromPlaybackInfo(info);
	std::string str = oJson.ToString();
	const char* c = str.c_str();
	strcpy(s,c);
	return str.size();
}

EXPORT_API void SetTrack(SESSION* session, int type, int index)
{
	if (NULL == session || session->player == NULL) {
		return;
	}

	return session->player->SetTrack(LeoPlayer::MPVTrack::TrackType (type), index);
}

EXPORT_API int WaitForEvent(SESSION* session)
{

	if (NULL == session || session->player == NULL) {
		return -1;
	}

	SDL_Event event;
	if (SDL_WaitEvent(&event) != 1)
		return -1;

	switch (event.type) {
	case SDL_QUIT:
		//goto done;
	case SDL_WINDOWEVENT:
		//if (event.window.event == SDL_WINDOWEVENT_EXPOSED)

		break;
	case SDL_KEYDOWN:
		if (event.key.keysym.sym == SDLK_SPACE)
			break;
	default:
		// Happens when a new video frame should be rendered, or if the
		// current frame has to be redrawn e.g. due to OSD changes.
		if (event.type == session->player->GetRedrawEvent())
		{
			session->isAvailable = true;
			return 666;
		}
		//Happens when at least 1 new event is in the mpv event queue.
		if (event.type == session->player->GetMpvEvent()) {
			// Handle all remaining mpv events.
			while (1) {
				mpv_event* mp_event = mpv_wait_event((mpv_handle*)session->player->GetMpvHandle(), 0);
				if (mp_event->event_id == MPV_EVENT_NONE)
					break;
				printf("event: %s\n", mpv_event_name(mp_event->event_id));
				if (mp_event->event_id == MPV_EVENT_END_FILE) {
					return -3;
				}
				else if (mp_event->event_id == MPV_EVENT_START_FILE) {
					return 333;
				}
			}
		}
	}

}



//unity plugin



// --------------------------------------------------------------------------
// SetTimeFromUnity, an example function we export which is called by one of the scripts.

static float g_Time;

extern "C" void UNITY_INTERFACE_EXPORT UNITY_INTERFACE_API SetTimeFromUnity(float t) { g_Time = t; }



// --------------------------------------------------------------------------
// SetTextureFromUnity, an example function we export which is called by one of the scripts.


extern "C" void UNITY_INTERFACE_EXPORT UNITY_INTERFACE_API SetTextureFromUnity(void* textureHandle, int w, int h)
{
	// A script calls this at initialization time; just remember the texture pointer here.
	// Will update texture pixels each frame from the plugin rendering event (texture update
	// needs to happen on the rendering thread).
	g_TextureHandle = textureHandle;
	g_TextureWidth = w;
	g_TextureHeight = h;
}



// --------------------------------------------------------------------------
// UnitySetInterfaces

static void UNITY_INTERFACE_API OnGraphicsDeviceEvent(UnityGfxDeviceEventType eventType);



extern "C" void	UNITY_INTERFACE_EXPORT UNITY_INTERFACE_API UnityPluginLoad(IUnityInterfaces* unityInterfaces)
{
	g_isUnity = true;
	s_UnityInterfaces = unityInterfaces;
	s_Graphics = s_UnityInterfaces->Get<IUnityGraphics>();
	s_Graphics->RegisterDeviceEventCallback(OnGraphicsDeviceEvent);


	// Run OnGraphicsDeviceEvent(initialize) manually on plugin load
	OnGraphicsDeviceEvent(kUnityGfxDeviceEventInitialize);
}

extern "C" void UNITY_INTERFACE_EXPORT UNITY_INTERFACE_API UnityPluginUnload()
{
	s_Graphics->UnregisterDeviceEventCallback(OnGraphicsDeviceEvent);
}



// --------------------------------------------------------------------------
// GraphicsDeviceEvent


static RenderAPI* s_CurrentAPI = NULL;
static UnityGfxRenderer s_DeviceType = kUnityGfxRendererNull;


static void UNITY_INTERFACE_API OnGraphicsDeviceEvent(UnityGfxDeviceEventType eventType)
{
	// Create graphics API implementation upon initialization
	if (eventType == kUnityGfxDeviceEventInitialize)
	{
		assert(s_CurrentAPI == NULL);
		s_DeviceType = s_Graphics->GetRenderer();
		s_CurrentAPI = CreateRenderAPI(s_DeviceType);

		if (s_DeviceType == kUnityGfxRendererD3D11)
		{
			d3d = s_UnityInterfaces->Get<IUnityGraphicsD3D11>();
			g_D3D11Device = d3d->GetDevice();
		}
	}

	// Let the implementation process the device related events
	if (s_CurrentAPI)
	{
		s_CurrentAPI->ProcessDeviceEvent(eventType, s_UnityInterfaces);
	}

	// Cleanup graphics API implementation upon shutdown
	if (eventType == kUnityGfxDeviceEventShutdown)
	{
		delete s_CurrentAPI;
		s_CurrentAPI = NULL;
		s_DeviceType = kUnityGfxRendererNull;
	}
}



// --------------------------------------------------------------------------
// OnRenderEvent
// This will be called for GL.IssuePluginEvent script calls; eventID will
// be the integer passed to IssuePluginEvent. In this example, we just ignore
// that value.


EXPORT_API void UpdateRender(SESSION* session)
{
	if (NULL == session) {
		return;
	}
	if (session->gl && session->isAvailable)
	{
		if (g_renderEnv.envType == 0) {
			g_Session->sharedTextureMutex_->lock();
			g_renderEnv.wglUtils->WglDXLockObjectsNV(g_renderEnv.rtvHandleGL);
			g_Session->player->GLRender(g_renderEnv.fbo, g_renderEnv.width, g_renderEnv.height);
			g_renderEnv.wglUtils->WglDXUnLockObjectsNV(g_renderEnv.rtvHandleGL);
			g_Session->sharedTextureMutex_->unlock();
		}
		else if (g_renderEnv.envType == 1) {
			g_Session->sharedTextureMutex_->lock();
			g_Session->player->GLRender(g_renderEnv.fbo, g_renderEnv.width, g_renderEnv.height);
			openglSave(&g_renderEnv.fbo, g_renderEnv.width, g_renderEnv.height, g_renderEnv.pixels);
			g_Session->sharedTextureMutex_->unlock();
		}
		session->isAvailable = false;
		session->shouldRender = true;
	}
}

EXPORT_API void Stop(SESSION* session)
{
	if (NULL == session) {
		return;
	}
	session->player->Stop();
	SDL_Event event;
	event.type = SDL_QUIT;
	SDL_PushEvent(&event);
}


static void UNITY_INTERFACE_API OnRenderEvent(int eventID)
{
	// Unknown / unsupported graphics device type? Do nothing
	if (s_CurrentAPI == NULL)
		return;

	if (eventID == 666) {
		if (g_Session != NULL && g_Session->shouldRender) {
			g_Session->shouldRender = false;
			if (g_renderEnv.envType == 0) {
				g_Session->sharedTextureMutex_->lock();
				ID3D11DeviceContext* deviceContext = NULL;
				g_D3D11Device->GetImmediateContext(&deviceContext);
				deviceContext->CopyResource(g_renderEnv.unityTexture, g_renderEnv.unitySharedTexture);
				deviceContext->Flush();
				g_Session->sharedTextureMutex_->unlock();
			}
			else if (g_renderEnv.envType == 1) {
				g_Session->sharedTextureMutex_->lock();
				
				ID3D11DeviceContext* deviceContext = NULL;
				g_D3D11Device->GetImmediateContext(&deviceContext);
				deviceContext->UpdateSubresource(g_renderEnv.unityTexture, 0, NULL, (const char*)g_renderEnv.pixels, g_renderEnv.width * 4, g_renderEnv.width * g_renderEnv.height * 4);
				deviceContext->Flush();
				g_Session->sharedTextureMutex_->unlock();
			}
		}

	}
}


// --------------------------------------------------------------------------
// GetRenderEventFunc, an example function we export which is used to get a rendering event callback function.

extern "C" UnityRenderingEvent UNITY_INTERFACE_EXPORT UNITY_INTERFACE_API GetRenderEventFunc()
{
	return OnRenderEvent;
}


void openglSave(void* textureHandle, int width, int height, unsigned char* pxls) {
	GLuint gltex = (GLuint)(size_t)(textureHandle);
	GLubyte* pixels = (GLubyte*)pxls;

	GLuint offscreen_framebuffer;
	GLint screen_framebuffer;
	glGetIntegerv(GL_READ_FRAMEBUFFER_BINDING, &screen_framebuffer);
	glGenFramebuffers(1, &offscreen_framebuffer);
	glBindFramebuffer(GL_FRAMEBUFFER, offscreen_framebuffer);

	glBindTexture(GL_TEXTURE_2D, gltex);

	// This line throws the following error: "OPENGL NATIVE PLUG-IN ERROR: GL_INVALID_OPERATION: Operation illegal in current state"
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, NULL);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	//Bind the texture to your FBO
	glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, gltex, 0);

	//Test if everything failed
	GLenum status = glCheckFramebufferStatus(GL_FRAMEBUFFER);
	if (status != GL_FRAMEBUFFER_COMPLETE) {
		printf("failed to make complete framebuffer object %x", status);
	}

	//Bind the FBO
	glBindFramebuffer(GL_FRAMEBUFFER, offscreen_framebuffer);
	// set the viewport as the FBO won't be the same dimension as the screen
	glViewport(0, 0, width, height);

	glReadPixels(0, 0, width, height, GL_RGBA, GL_UNSIGNED_BYTE, pixels);

	//Bind your main FBO again
	glBindFramebuffer(GL_FRAMEBUFFER, screen_framebuffer);
	// set the viewport as the FBO won't be the same dimension as the screen
	glViewport(0, 0, width, height);
}