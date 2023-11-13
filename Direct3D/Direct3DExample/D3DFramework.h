#pragma once
#define WIN32_LEAN_AND_MEAN

#include <windows.h>
#include <wrl/client.h>
#include <d3d11.h>
#include <string>

class D3DFramework
{
	const std::wstring CLASSNAME{ L"D3DWindowClass" };
	const std::wstring TITLE{ L"Direct3D Example" };

protected:
	int mScreenWidth{ 800 };
	int mScreenHeight{ 600 };
	bool mMinimized{ false };
	bool mMaximized{ false };
	bool mResizing{ false };

	HWND mHwnd{};
	HINSTANCE mInstance{};

	Microsoft::WRL::ComPtr<IDXGISwapChain> mspSwapChain{};
	Microsoft::WRL::ComPtr<ID3D11Device> mspDevice{};
	Microsoft::WRL::ComPtr<ID3D11DeviceContext> mspDeviceContext{};

	Microsoft::WRL::ComPtr<ID3D11Texture2D> mspRenderTarget{};
	Microsoft::WRL::ComPtr<ID3D11RenderTargetView> mspRenderTargetView{};

	Microsoft::WRL::ComPtr<ID3D11Texture2D> mspDepthStencil{};
	Microsoft::WRL::ComPtr<ID3D11DepthStencilView> mspDepthStencilView{};

private:
	void InitWindow(HINSTANCE hInstance);
	void InitD3D();

protected:
	void OnResize();
	void RenderFrame();
	virtual void Render();

public:
	virtual void Initialize(HINSTANCE hInstance, int width = 800, int height = 600);
	virtual void Destroy();
	void GameLoop();

public:
	LRESULT CALLBACK MessageHandler(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);
};

LRESULT CALLBACK WindowProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);
