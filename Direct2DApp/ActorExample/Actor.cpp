#include "Actor.h"

Actor::Actor(D2DFramework* pFramework, LPCWSTR filename):
    mpFramework(pFramework),
    mspBitmap(),
    mX(), mY(), mOpacity(1.0f)
{
    LoadWICImage(filename);
}

Actor::Actor(D2DFramework* pFramework, LPCWSTR filename, float x, float y, float opacity) :
    Actor(pFramework, filename)
{
    mX = x;
    mY = y;
    mOpacity = opacity;
}

Actor::~Actor()
{
    mspBitmap.Reset();
}

HRESULT Actor::LoadWICImage(LPCWSTR filename)
{
    Microsoft::WRL::ComPtr<IWICBitmapDecoder> decoder;
    HRESULT hr;

    if (mpFramework == nullptr)
    {
        return E_FAIL;
    }

    auto pWICFactory = mpFramework->GetWICFactory();
    if (pWICFactory == nullptr)
    {
        return E_FAIL;
    }

    hr = pWICFactory->CreateDecoderFromFilename(filename, nullptr, GENERIC_READ,
        WICDecodeMetadataCacheOnLoad, decoder.GetAddressOf());
    ThrowIfFailed(hr);

    Microsoft::WRL::ComPtr<IWICBitmapFrameDecode> frame;
    ThrowIfFailed(decoder->GetFrame(0, frame.GetAddressOf()));

    Microsoft::WRL::ComPtr<IWICFormatConverter> converter;
    ThrowIfFailed(pWICFactory->CreateFormatConverter(converter.GetAddressOf()));

    hr = converter->Initialize(frame.Get(), GUID_WICPixelFormat32bppPBGRA,
        WICBitmapDitherTypeNone, nullptr, 0, WICBitmapPaletteTypeCustom);

    ThrowIfFailed(hr);

    auto pRT = mpFramework->GetRenderTarget();
    if (pRT == nullptr)
    {
        return E_FAIL;
    }

    hr = pRT->CreateBitmapFromWicBitmap(converter.Get(), mspBitmap.GetAddressOf());
    ThrowIfFailed(hr);

    return S_OK;
}

void Actor::Draw(float x, float y, float opacity)
{
    auto pRT = mpFramework->GetRenderTarget();
    if (pRT == nullptr)
    {
        return;
    }
    auto size{ mspBitmap->GetPixelSize() };
    D2D1_RECT_F rect{ x,y, 
        static_cast<float>(x+ size.width),
        static_cast<float>(y+ size.height)};

    pRT->DrawBitmap(mspBitmap.Get(), rect, opacity);
}

void Actor::Draw()
{
    Draw(mX, mY, mOpacity);
}
