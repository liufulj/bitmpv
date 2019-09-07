#pragma once
#include<d3d11.h>
namespace LeoPlayer
{

	class WindowClient 
	{
	public: 
		WindowClient();
		~WindowClient();
		int Create(int x,int y,int width, int height,bool isShow=false, DXGI_FORMAT format= DXGI_FORMAT_B8G8R8A8_UNORM);
		HWND GetWindowId();
		static LRESULT  MsgProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
		static void DispatchMsg();
		int GetWidth();
		int GetHeight();
		DXGI_FORMAT GetFormat();
	private:
		bool isCreated = false;
		HWND mHwd;
		int mWidth;
		int mHeight;
		DXGI_FORMAT mFormat;
		
	};

}