#pragma once

#include <d2d1.h>
#include <wrl/client.h>
#include "com_exception.h"
#include "BitmapManager.h"

class D2DFramework
{
private:
	const LPCWSTR gClassName { L"MyWindowClass" };
protected:
	HWND mHwnd{};
protected:
	Microsoft::WRL::ComPtr<ID2D1Factory> mspD2DFactory{};	
	Microsoft::WRL::ComPtr<ID2D1HwndRenderTarget> mspRenderTarget{};	
protected:
	HRESULT InitWindow(HINSTANCE hInstance, LPCWSTR title = L"D2DFramework", UINT  w = 1024, UINT h = 768);
	virtual HRESULT InitD2D(HWND hwnd);
	virtual HRESULT CreateDeviceResources();
public:
	virtual HRESULT Initialize(HINSTANCE hInstance, LPCWSTR title = L"D2DFramework", UINT  w = 1024, UINT h = 768);

	virtual void Release();
	virtual int GameLoop();
	virtual void Render();

	void ShowError(LPCWSTR msg, LPCWSTR title = L"error");

	static LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);
public:
	inline ID2D1HwndRenderTarget* GetRenderTarget()
	{
		return mspRenderTarget.Get();
	}

	inline ID2D1Factory* GetD2DFactory()
	{
		return mspD2DFactory.Get();
	}
};
