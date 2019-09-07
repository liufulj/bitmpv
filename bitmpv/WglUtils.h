#pragma once
#include<d3d11.h>
namespace LeoPlayer
{


	class WglUtils
	{
	public:
		WglUtils();
		~WglUtils();

		void InitWithWinIdAndDevice(HWND winId, ID3D11Device *device);//winId是随意创建一个窗口的id用来初始化wgl上下文，device是目标纹理的d3d device
		void WglDXRegisterObjectNV(ID3D11Texture2D * texture,HANDLE *handleGL,GLuint nameGL);
		void WglDXUnregisterObjectNV(HANDLE handleGL);
		void WglCreateFrameBuffer(GLuint* fbo);
		void WglCreateTexture(GLuint * name);
		void BindFrameBufferTexture(GLuint fbo, GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
		void WglDXLockObjectsNV(HANDLE handleGL);
		void WglDXUnLockObjectsNV(HANDLE handleGL);
		
	private:
		// Grab WGL functions
		PFNWGLCREATECONTEXTATTRIBSARBPROC wglCreateContextAttribsARB;
		PFNWGLDXOPENDEVICENVPROC wglDXOpenDeviceNV;
		PFNWGLDXREGISTEROBJECTNVPROC wglDXRegisterObjectNV;
		PFNWGLDXUNREGISTEROBJECTNVPROC wglDXUnregisterObjectNV;
		PFNWGLDXLOCKOBJECTSNVPROC wglDXLockObjectsNV;
		PFNWGLDXUNLOCKOBJECTSNVPROC wglDXUnlockObjectsNV;
		// Fall back to GetProcAddress to get GL 1 functions. wglGetProcAddress returns NULL on those.
		HMODULE hOpenGL32;
		// Grab OpenGL functions
		PFNGLENABLEPROC glEnable;
		PFNGLDISABLEPROC glDisable;
		PFNGLCLEARPROC glClear;
		PFNGLCLEARCOLORPROC glClearColor;
		PFNGLSCISSORPROC glScissor;
		PFNGLGENTEXTURESPROC glGenTextures;
		PFNGLGENFRAMEBUFFERSPROC glGenFramebuffers;
		PFNGLBINDFRAMEBUFFERPROC glBindFramebuffer;
		PFNGLFRAMEBUFFERTEXTURE2DPROC glFramebufferTexture2D;
		PFNGLCHECKFRAMEBUFFERSTATUSPROC glCheckFramebufferStatus;

		HANDLE mGLHandleD3D;
	};

}