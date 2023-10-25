#include "BitmapManager.h"

#pragma comment(lib, "WindowsCodecs.lib")

using namespace std;
using namespace Microsoft::WRL;

HRESULT BitmapManager::LoadWICBitmap(wstring filename, ID2D1Bitmap** ppBitmap)
{
	Microsoft::WRL::ComPtr<IWICBitmapDecoder> decoder;
	HRESULT hr;

	auto pWICFactory = mspWICFactory.Get();
  
	if (pWICFactory == nullptr)
	{
		return E_FAIL;
	}

	hr = pWICFactory->CreateDecoderFromFilename(filename.c_str(), nullptr, GENERIC_READ,
		WICDecodeMetadataCacheOnLoad, decoder.GetAddressOf());
	ThrowIfFailed(hr);

	Microsoft::WRL::ComPtr<IWICBitmapFrameDecode> frame;
	ThrowIfFailed(decoder->GetFrame(0, frame.GetAddressOf()));

	Microsoft::WRL::ComPtr<IWICFormatConverter> converter;
	ThrowIfFailed(pWICFactory->CreateFormatConverter(converter.GetAddressOf()));

	hr = converter->Initialize(frame.Get(), GUID_WICPixelFormat32bppPBGRA,
		WICBitmapDitherTypeNone, nullptr, 0, WICBitmapPaletteTypeCustom);
	ThrowIfFailed(hr);

	auto pRT = mpRenderTarget;
  
	if (pRT == nullptr)
	{
		return E_FAIL;
	}
	hr = pRT->CreateBitmapFromWicBitmap(converter.Get(), ppBitmap);
	ThrowIfFailed(hr);

	return S_OK;
}

HRESULT BitmapManager::Initialize(ID2D1HwndRenderTarget* pRT)
{
	if (!pRT)
	{
		return E_FAIL;
	}

	mpRenderTarget = pRT;

	HRESULT hr = CoCreateInstance(CLSID_WICImagingFactory, nullptr, CLSCTX_INPROC_SERVER,
		IID_PPV_ARGS(mspWICFactory.GetAddressOf()));
	ThrowIfFailed(hr, "WICFactory Creation failed");

	return hr;
}

void BitmapManager::Release()
{
	mBitmapResources.clear();

	mspWICFactory.Reset();
}

ID2D1Bitmap* BitmapManager::LoadBitmap(wstring filename)
{
	if (!mspWICFactory)
	{
		ThrowIfFailed(E_FAIL, "WICFactory must not null");
		return nullptr;
	}

	auto result = mBitmapResources.insert({filename, nullptr});

	if (result.second)
	{
		auto spBitmap = ComPtr<ID2D1Bitmap>();
		LoadWICBitmap(filename, spBitmap.GetAddressOf());
		result.first->second = spBitmap;
	}
	return result.first->second.Get();
}
