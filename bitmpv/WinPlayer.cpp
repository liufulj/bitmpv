#include"stdafx.h"
#include "WinPlayer.h"
#include <thread>
#include <process.h>
#include<SDL.h>
#include "client.h"
#include "render_gl.h"
#pragma comment(lib, "SDL2main.lib")
#pragma comment(lib, "SDL2.lib")
#pragma comment(lib, "dxgi.lib")
#pragma comment(lib, "d3d11.lib")
#pragma comment(lib, "opengl32.lib")
namespace LeoPlayer {

	
	WinPlayer::WinPlayer()
	{
		m_playerCore.StartMPV();
		this->InitSDL();
		
		
	}


	WinPlayer::~WinPlayer()
	{
	}
	void WinPlayer::Reset()
	{
	}
	void WinPlayer::ReleasePlayer()
	{
	}
	void WinPlayer::SetDataSource(const char * url)
	{
		this->m_path = std::string(url);
	}
	void WinPlayer::Start()
	{
		this->m_playerCore.Open(m_path);
		isPause = false;
	}
	void WinPlayer::Stop()
	{
		this->m_playerCore.Stop();
	}
	void WinPlayer::Pause()
	{
		isPause = !isPause;
		this->m_playerCore.TogglePause(isPause);
	}
	int WinPlayer::GetVideoWidth()
	{
		MPVTrack info =this->m_playerCore.GetPlaybackInfo().videoTracks.front();
		return info.demuxW;
	}
	int WinPlayer::GetVideoHeight()
	{
		MPVTrack info = this->m_playerCore.GetPlaybackInfo().videoTracks.front();
		return info.demuxH;
	}
	bool WinPlayer::IsPlaying()
	{
		return !isPause;
	}
	void WinPlayer::SeekTo(double timeS)
	{

		this->m_playerCore.Seek(timeS);
	}
	long WinPlayer::GetCurrentPosition()
	{
		return this->m_playerCore.GetCurrentPosition();
	}
	long WinPlayer::GetDuration()
	{
		return this->m_playerCore.GetDuration();
	}
	void WinPlayer::SetLooping(bool loop)
	{
		this->m_playerCore.SetLoop(loop);
	}
	bool WinPlayer::IsLooping()
	{
		return this->m_playerCore.GetLoop();
	}
	void WinPlayer::SetVolume(double volume)
	{
		this->m_playerCore.SetVolume(volume);
	}
	void WinPlayer::SetMute(bool mute)
	{
		this->m_playerCore.ToggleMute(mute);
	}
	double WinPlayer::GetVolume()
	{
		return this->m_playerCore.GetVolume();
	}
	void WinPlayer::SetWindowId(int64_t data, bool isTexture)
	{
		if (!isTexture) {

			this->m_playerCore.SetWindowId(data);
		}
		else {
			this->InitGL();
		}
	}

	void WinPlayer::UpdatePlaybackInfo()
	{
		this->m_playerCore.GetTrackInfo();
		this->m_playerCore.GetSelectedTracks();
	}
	PlaybackInfo WinPlayer::GetPlaybackInfo()
	{
		return this->m_playerCore.GetPlaybackInfo();
	}
	void WinPlayer::ChangeNextAudio()
	{
		this->m_playerCore.ChangeNextAudio();
	}
	void WinPlayer::ChangeNextSub()
	{
		this->m_playerCore.ChangeNextSub();
	}
	void * WinPlayer::GetMpvHandle()
	{
		
		return (void *)this->m_playerCore.GetMPVHandle();
	
	}

	void WinPlayer::GLRender(unsigned int fbo,int width,int height)
	{
		if (mpv_gl == NULL) {
			printf("mpv gl is null");
			return;
		}
		mpv_opengl_fbo fbo_gl;
		fbo_gl.fbo = fbo;
		fbo_gl.w = width;
		fbo_gl.h = height;
		int flip_y[1];
		flip_y[0] = 0;
		mpv_render_param params[] = {

			{MPV_RENDER_PARAM_OPENGL_FBO, &fbo_gl},

			{MPV_RENDER_PARAM_FLIP_Y, &flip_y},
			{MPV_RENDER_PARAM_INVALID,(void *)0}
		};

		mpv_render_context_render(mpv_gl, params);
	}

	unsigned int WinPlayer::GetRedrawEvent()
	{
		return wakeup_on_mpv_redraw;
	}


	unsigned int WinPlayer::GetMpvEvent()
	{
		return wakeup_on_mpv_events;
	}

	void WinPlayer::InitSDL()
	{
		if (SDL_Init(SDL_INIT_VIDEO) < 0)
		{
			printf("SDL init failed\n");
			return;
		}
		SDL_Window *window = SDL_CreateWindow("hi", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
			480, 320, SDL_WINDOW_OPENGL | SDL_WINDOW_HIDDEN);

		if (!window)
		{
			printf("failed to create SDL window");
			return;
		}
		SDL_GLContext glcontext = SDL_GL_CreateContext(window);
		if (!glcontext)
		{
			printf("failed to create SDL GL context");

		}
		wakeup_on_mpv_redraw = SDL_RegisterEvents(1);
		wakeup_on_mpv_events = SDL_RegisterEvents(1);
    	if (wakeup_on_mpv_redraw == (Uint32)-1 || wakeup_on_mpv_events == (Uint32)-1)
			printf("could not register events");
		mpv_set_wakeup_callback(m_playerCore.GetMPVHandle(), on_mpv_events, NULL);
	}

	void WinPlayer::InitGL()
	{
		mpv_opengl_init_params paramsInit;
		paramsInit.extra_exts = NULL;
		paramsInit.get_proc_address_ctx = NULL;
		paramsInit.get_proc_address = get_proc_address_mpv;

		mpv_render_param params[] = {
			{MPV_RENDER_PARAM_API_TYPE, (void *)MPV_RENDER_API_TYPE_OPENGL},
			{MPV_RENDER_PARAM_OPENGL_INIT_PARAMS, &paramsInit},
			{MPV_RENDER_PARAM_INVALID,(void *)0}
		};
		//       //{0}

		//   // This makes mpv use the currently set GL context. It will use the callback
		//   // (passed via params) to resolve GL builtin functions, as well as extensions.
		
		if (mpv_render_context_create(&mpv_gl, m_playerCore.GetMPVHandle(), params) < 0)
		{
			printf("failed to initialize mpv GL context\n");
			return;
		}
		mpv_render_context_set_update_callback(mpv_gl, on_mpv_redraw, NULL);

	}

	void WinPlayer::on_mpv_events(void *ctx) 
	{
		printf("on_mpv_events\n");
		SDL_Event event;
		event.type = wakeup_on_mpv_events;
		SDL_PushEvent(&event);
	}
	void WinPlayer::on_mpv_redraw(void *ctx)
	{
		//printf("on_mpv_redraw\n");
		SDL_Event event;
		event.type = wakeup_on_mpv_redraw;
		SDL_PushEvent(&event);
	}
	void* WinPlayer::get_proc_address_mpv(void *fn_ctx, const char *name)
	{
		return SDL_GL_GetProcAddress(name);
	}
	unsigned int  WinPlayer::wakeup_on_mpv_redraw = 0;
	unsigned int  WinPlayer::wakeup_on_mpv_events = 0;
}