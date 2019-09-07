#include "stdafx.h"
#include "WglUtils.h"
#pragma comment(lib, "dxgi.lib")
#pragma comment(lib, "d3d11.lib")
#pragma comment(lib, "opengl32.lib")
namespace LeoPlayer
{
	WglUtils::WglUtils()
	{
		

	}


	WglUtils::~WglUtils()
	{
	}

	void WglUtils::InitWithWinIdAndDevice(HWND winId, ID3D11Device * device)
	{
		HDC gl_hDC = GetDC(winId);
		PIXELFORMATDESCRIPTOR gl_pfd = {};
		gl_pfd.nSize = sizeof(gl_pfd);
		gl_pfd.nVersion = 1;
		gl_pfd.dwFlags = PFD_SUPPORT_OPENGL;

		int chosenPixelFormat = ChoosePixelFormat(gl_hDC, &gl_pfd);
		SetPixelFormat(gl_hDC, chosenPixelFormat, &gl_pfd);
		HGLRC dummy_hGLRC = wglCreateContext(gl_hDC);
		wglMakeCurrent(gl_hDC, dummy_hGLRC);
		wglCreateContextAttribsARB = (PFNWGLCREATECONTEXTATTRIBSARBPROC)wglGetProcAddress("wglCreateContextAttribsARB");
		int contextFlagsGL = 0;
	#ifdef _DEBUG
		contextFlagsGL |= WGL_CONTEXT_DEBUG_BIT_ARB;
	#endif

		int contextAttribsGL[] = {
			WGL_CONTEXT_MAJOR_VERSION_ARB, 4,
			WGL_CONTEXT_MINOR_VERSION_ARB, 3,
			WGL_CONTEXT_FLAGS_ARB, contextFlagsGL,
			WGL_CONTEXT_PROFILE_MASK_ARB, WGL_CONTEXT_CORE_PROFILE_BIT_ARB,
			0
		};
		HGLRC hGLRC = wglCreateContextAttribsARB(gl_hDC, NULL, contextAttribsGL);
		(hGLRC != NULL);

		// Switch to the new context and ditch the old one
		(wglMakeCurrent(gl_hDC, hGLRC) != FALSE);
		(wglDeleteContext(dummy_hGLRC) != FALSE);

		// Grab WGL functions
		
		wglDXOpenDeviceNV = (PFNWGLDXOPENDEVICENVPROC)wglGetProcAddress("wglDXOpenDeviceNV");
		wglDXRegisterObjectNV = (PFNWGLDXREGISTEROBJECTNVPROC)wglGetProcAddress("wglDXRegisterObjectNV");
		wglDXUnregisterObjectNV = (PFNWGLDXUNREGISTEROBJECTNVPROC)wglGetProcAddress("wglDXUnregisterObjectNV");
		wglDXLockObjectsNV = (PFNWGLDXLOCKOBJECTSNVPROC)wglGetProcAddress("wglDXLockObjectsNV");
		wglDXUnlockObjectsNV = (PFNWGLDXUNLOCKOBJECTSNVPROC)wglGetProcAddress("wglDXUnlockObjectsNV");
		// Fall back to GetProcAddress to get GL 1 functions. wglGetProcAddress returns NULL on those.
		hOpenGL32 = LoadLibrary(TEXT("OpenGL32.dll"));
		// Grab OpenGL functions
		glEnable = (PFNGLENABLEPROC)GetProcAddress(hOpenGL32, "glEnable");
		glDisable = (PFNGLDISABLEPROC)GetProcAddress(hOpenGL32, "glDisable");
		glClear = (PFNGLCLEARPROC)GetProcAddress(hOpenGL32, "glClear");
		glClearColor = (PFNGLCLEARCOLORPROC)GetProcAddress(hOpenGL32, "glClearColor");
		glScissor = (PFNGLSCISSORPROC)GetProcAddress(hOpenGL32, "glScissor");
		glGenTextures = (PFNGLGENTEXTURESPROC)GetProcAddress(hOpenGL32, "glGenTextures");
		glGenFramebuffers = (PFNGLGENFRAMEBUFFERSPROC)wglGetProcAddress("glGenFramebuffers");
		glBindFramebuffer = (PFNGLBINDFRAMEBUFFERPROC)wglGetProcAddress("glBindFramebuffer");
		glFramebufferTexture2D = (PFNGLFRAMEBUFFERTEXTURE2DPROC)wglGetProcAddress("glFramebufferTexture2D");
		glCheckFramebufferStatus = (PFNGLCHECKFRAMEBUFFERSTATUSPROC)wglGetProcAddress("glCheckFramebufferStatus");

		mGLHandleD3D = wglDXOpenDeviceNV(device);
	}

	void WglUtils::WglDXRegisterObjectNV(ID3D11Texture2D * texture, HANDLE * handleGL, GLuint  nameGL)
	{
		//*handleGL
		HANDLE handle= wglDXRegisterObjectNV(mGLHandleD3D, texture, nameGL, GL_TEXTURE_2D, WGL_ACCESS_READ_WRITE_NV);
		*handleGL = handle;
	}

	void WglUtils::WglDXUnregisterObjectNV(HANDLE handleGL)
	{
		wglDXUnregisterObjectNV(mGLHandleD3D, handleGL);
	}

	void WglUtils::WglCreateFrameBuffer(GLuint * fbo)
	{
		glGenFramebuffers(1, fbo);
	}

	void WglUtils::WglCreateTexture(GLuint * name)
	{
		glGenTextures(1, name);
	}

	void WglUtils::BindFrameBufferTexture(GLuint fbo, GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level)
	{
		glBindFramebuffer(GL_FRAMEBUFFER, fbo);
		glFramebufferTexture2D(target, attachment, textarget, texture, 0);
		glBindFramebuffer(GL_FRAMEBUFFER, 0);
	}

	void WglUtils::WglDXLockObjectsNV(HANDLE handleGL)
	{
		wglDXLockObjectsNV(mGLHandleD3D,1, &handleGL);
	}

	void WglUtils::WglDXUnLockObjectsNV(HANDLE handleGL)
	{
		wglDXUnlockObjectsNV(mGLHandleD3D, 1, &handleGL);
	}


}