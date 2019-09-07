#pragma once
#include"WindowClient.h"
namespace d3dtools {

	class D3DInterface
	{
	public:
		D3DInterface();
		D3DInterface(LeoPlayer::WindowClient *client);
		~D3DInterface();

		bool IsWindowClientContext();
		ID3D11DeviceContext*GetDeviceContext();
		ID3D11Device *GetDevice();
		void Present();
		ID3D11Texture2D* GetBackBuffer();
		void UpdateToShareTexture(ID3D11Texture2D * texture);
		void UpdateToWindow(ID3D11Texture2D * texture);
	private:
		bool isCreated = false;
		bool CreateDefalutD3DContext();
		bool isWindowClient = false;
		HWND mHwd;
		ID3D11Texture2D *mBackBuffer;
		ID3D11Device* mDevice;
		ID3D11DeviceContext* mDeviceContext;
		IDXGISwapChain *mSwapChain;
	};
}

