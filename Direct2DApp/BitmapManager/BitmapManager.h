#pragma once
#include <map>
#include <string>
#include <wrl/client.h>
#include <d2d1.h>
#include <wincodec.h>
#include "com_exception.h"

class BitmapManager final
{
public:
	static BitmapManager& Instance()
	{
		static BitmapManager instance;
		return instance;
	}
private:
	BitmapManager() {}
	BitmapManager(const BitmapManager&) {}
	void operator = (const BitmapManager&) {}
public:
	~BitmapManager() {}
private:
	ID2D1HwndRenderTarget* mpRenderTarget{};
	Microsoft::WRL::ComPtr<IWICImagingFactory> mspWICFactory{};

	std::map<std::wstring, Microsoft::WRL::ComPtr<ID2D1Bitmap>> mBitmapResources;
private:
	HRESULT LoadWICBitmap(std::wstring filename, ID2D1Bitmap** ppBitmap);
public:
	HRESULT Initialize(ID2D1HwndRenderTarget* pRT);
	void Release();

	ID2D1Bitmap* LoadBitmap(std::wstring filename);
};
