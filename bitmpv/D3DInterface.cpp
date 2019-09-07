#include "stdafx.h"
#include "D3DInterface.h"

namespace d3dtools {
	D3DInterface::D3DInterface()
	{
		if (isCreated) {
			return;
		}
		CreateDefalutD3DContext();
	}

	D3DInterface::D3DInterface(LeoPlayer::WindowClient *client)
	{

		if (isCreated) {
			return;
		}
		
		if (mSwapChain == NULL) {
			DXGI_SWAP_CHAIN_DESC sc = { 0 };
			sc.BufferCount = 1;

			sc.BufferDesc.Width = client->GetWidth();
			sc.BufferDesc.Height = client->GetHeight();


			sc.BufferDesc.Format = client->GetFormat();
			sc.BufferDesc.RefreshRate.Numerator = 0;
			sc.BufferDesc.RefreshRate.Denominator = 1;
			sc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;//DXGI_USAGE_SHADER_INPUT |DXGI_USAGE_SHARED| | DXGI_USAGE_BACK_BUFFER| DXGI_USAGE_DISCARD_ON_PRESENT;
			sc.OutputWindow = client->GetWindowId();
			sc.SampleDesc.Count = 1;
			sc.SampleDesc.Quality = 0;
			sc.Windowed = true;
			sc.SwapEffect = DXGI_SWAP_EFFECT_DISCARD;
			sc.Flags = DXGI_SWAP_CHAIN_FLAG_ALLOW_MODE_SWITCH;

			HRESULT hr = D3D11CreateDeviceAndSwapChain(NULL, D3D_DRIVER_TYPE_HARDWARE,
				NULL, 0, NULL, 0, D3D11_SDK_VERSION, &sc, &mSwapChain, &mDevice, NULL, &mDeviceContext);

			if (FAILED(hr))
			{
				printf("Unable to create DX11 device and swapchain, hr=0x%x", hr);
				CreateDefalutD3DContext();
				return;
			}
			isWindowClient = true;

		}

	}

	bool D3DInterface::CreateDefalutD3DContext()
	{

		D3D_DRIVER_TYPE driverType_;
		D3D_FEATURE_LEVEL featureLevel_;

		D3D_DRIVER_TYPE driverTypes[] =
		{
			D3D_DRIVER_TYPE_HARDWARE//, D3D_DRIVER_TYPE_WARP, D3D_DRIVER_TYPE_SOFTWARE
		};
		unsigned int totalDriverTypes = ARRAYSIZE(driverTypes);
		D3D_FEATURE_LEVEL featureLevels[] =
		{
			D3D_FEATURE_LEVEL_11_0,
			D3D_FEATURE_LEVEL_10_0,
			D3D_FEATURE_LEVEL_10_1
		};
		unsigned int totalFeatureLevels = ARRAYSIZE(featureLevels);
		unsigned int creationFlags = 0;
		HRESULT result;
		unsigned int driver = 0;

		for (driver = 0; driver < totalDriverTypes; ++driver)
		{
			result = D3D11CreateDevice(NULL, driverTypes[driver], NULL, creationFlags, featureLevels, _countof(featureLevels),
				D3D11_SDK_VERSION, &mDevice, &featureLevel_, &mDeviceContext);

			if (SUCCEEDED(result))
			{
				driverType_ = driverTypes[driver];
				break;
			}
		}

		if (FAILED(result))
		{
			printf_s("创建 Direct3D 设备失败!");
			return false;
		}
		return true;
	}

	D3DInterface::~D3DInterface()
	{
	}
	bool D3DInterface::IsWindowClientContext()
	{
		return isWindowClient;
	}
	ID3D11DeviceContext * D3DInterface::GetDeviceContext()
	{
		return mDeviceContext;
	}
	ID3D11Device * D3DInterface::GetDevice()
	{
		return mDevice;
	}
	void D3DInterface::Present()
	{
		if (isWindowClient&&mSwapChain != NULL) {
			mSwapChain->Present(1, 0);
		}
	}
	ID3D11Texture2D * D3DInterface::GetBackBuffer()
	{
		if (isWindowClient&&mSwapChain != NULL) {

			mSwapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (LPVOID*)&mBackBuffer);
			//D3D11_TEXTURE2D_DESC textureInfo;
			//mBackBuffer->GetDesc(&textureInfo);
			return mBackBuffer;
		}
		return NULL;
	}
	void D3DInterface::UpdateToShareTexture(ID3D11Texture2D * texture)
	{
		if (mDeviceContext != NULL && mSwapChain != NULL) {
			mSwapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (LPVOID*)&mBackBuffer);
			mDeviceContext->CopyResource(texture, mBackBuffer);

		}
	}
	void D3DInterface::UpdateToWindow(ID3D11Texture2D * texture)
	{
		if (mDeviceContext != NULL) {
			mDeviceContext->CopyResource(mBackBuffer, texture);
			Present();
		}
	}
}