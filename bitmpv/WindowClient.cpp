#include "stdafx.h"
#include "WindowClient.h"
#include<tchar.h>
#include <DXGI.h>
#pragma comment ( lib, "D3D11.lib")

namespace LeoPlayer {
	WindowClient::WindowClient()
	{
	}
	WindowClient::~WindowClient()
	{
	}
	int WindowClient::Create(int x,int y,int width, int height,bool isShow, DXGI_FORMAT format)
	{
		if (isCreated)
			return -1;
		isCreated = true;
		mWidth = width;
		mHeight = height;
		mFormat = format;
		// create window (after we know the size of the input file size)
		WNDCLASSEX wc = { sizeof(WNDCLASSEX),  CS_HREDRAW | CS_VREDRAW, MsgProc, 0L, 0L,
			GetModuleHandle(NULL), NULL, NULL, NULL, NULL,
			_T("tmp"), NULL
		};
		RegisterClassEx(&wc);
		// figure out the window size we must create to get a *client* area
			// that is of the size requested by m_dimensions.
		RECT adjustedWindowSize;
		DWORD dwWindowStyle;

		dwWindowStyle = WS_OVERLAPPEDWINDOW | WS_CLIPCHILDREN | WS_CLIPSIBLINGS;
		SetRect(&adjustedWindowSize, x, y, width+x, height+y);
		AdjustWindowRect(&adjustedWindowSize, dwWindowStyle, false);

		int windowWidth = adjustedWindowSize.right - adjustedWindowSize.left;
		int windowHeight = adjustedWindowSize.bottom - adjustedWindowSize.top;

		mHwd = CreateWindow(wc.lpszClassName, _T("tmpwin"),
			dwWindowStyle,
			x, y,
			windowWidth,
			windowHeight,
			NULL, NULL, wc.hInstance, NULL);

	
		

		if (isShow) {
			::ShowWindow(mHwd, SW_SHOW);
		}
		return 0;
	}
	
	HWND WindowClient::GetWindowId()
	{
		if (mHwd != NULL) {
			return mHwd;
		}
		return 0;
	}



	LRESULT  WindowClient::MsgProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
	{

	
		PAINTSTRUCT ps;
		HDC hdc;

		switch (msg)
		{
		case WM_PAINT:
			
			hdc = BeginPaint(hWnd, &ps);
			EndPaint(hWnd, &ps);
			break;

		case WM_DESTROY:
			PostQuitMessage(0);
			break;
		case WM_SIZE:

			break;
		case WM_DISPLAYCHANGE:
		case WM_STYLECHANGING:
		case WM_STYLECHANGED:
		case WM_NCLBUTTONDOWN:  //在非工作区按下右键  
		case WM_NCLBUTTONDBLCLK://在非工作区双击右击  
		case WM_NCRBUTTONDOWN:  //在非工作区按下右键  
		case WM_NCRBUTTONDBLCLK://在非工作区双击右击  
			return 0;
		case 0x666:
			::ShowWindow(hWnd, SW_SHOW);
			UpdateWindow(hWnd);
			return 0;
		case 0x667:
			::ShowWindow(hWnd, SW_HIDE);
			UpdateWindow(hWnd);
			return 0;
		default:
			return DefWindowProc(hWnd, msg, wParam, lParam);
		}

		return 0;
		
	}
	void WindowClient::DispatchMsg()
	{
		MSG msg;
		while (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}
	int WindowClient::GetWidth()
	{
		return mWidth;
	}
	int WindowClient::GetHeight()
	{
		return mHeight;
	}
	DXGI_FORMAT WindowClient::GetFormat()
	{
		return mFormat;
	}
}