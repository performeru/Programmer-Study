#include "BitmapExample.h"

HRESULT BitmapExample::CreateDeviceResources()
{
    D2DFramework::CreateDeviceResources();

    HRESULT hr = mspRenderTarget->CreateBitmap(
        D2D1::SizeU(BITMAP_WIDTH,BITMAP_HEIGHT),
        D2D1::BitmapProperties(D2D1::PixelFormat(DXGI_FORMAT_R8G8B8A8_UNORM, D2D1_ALPHA_MODE_IGNORE)),
        mspFrameBuffer.ReleaseAndGetAddressOf()
    );
    ThrowIfFailed(hr);

    return S_OK;
}

HRESULT BitmapExample::Initialize(HINSTANCE hInstance, LPCWSTR title, UINT w, UINT h)
{
	D2DFramework::Initialize(hInstance, title, w, h);

    mspBackBuffer = std::make_unique<UINT8[]>(BITMAP_WIDTH * BITMAP_HEIGHT * BITMAP_BYTECOUNT);

    

    return S_OK;
}

void BitmapExample::Render()
{
    mspRenderTarget->BeginDraw();
    mspRenderTarget->Clear(D2D1::ColorF(0.0f, 0.2f, 0.4f, 1.0f));

    ClearBuffer(D2D1::ColorF(D2D1::ColorF::LightPink));

    DrawRectangle(0, 0, 100, 100, D2D1::ColorF::Red);
    DrawRectangle(50, 50, 100, 100, D2D1::ColorF(D2D1::ColorF::Green, 0.65f));

    PresentBuffer();

    mspRenderTarget->DrawBitmap(mspFrameBuffer.Get());


    HRESULT hr = mspRenderTarget->EndDraw();

    if (hr == D2DERR_RECREATE_TARGET)
    {
        CreateDeviceResources();
    }
}

void BitmapExample::DrawPixel(int x, int y, D2D1::ColorF color)
{
    int i{ (BITMAP_WIDTH * y + x) * BITMAP_BYTECOUNT };

    float inverse = 1.0f - color.a;

    mspBackBuffer[i] = static_cast<UINT8>(mspBackBuffer[i] * inverse + color.r * 255 * color.a);
    mspBackBuffer[i+1] =  static_cast<UINT8>(mspBackBuffer[i + 1] * inverse + color.g * 255 * color.a);
    mspBackBuffer[i+2] =  static_cast<UINT8>(mspBackBuffer[i + 2] * inverse + color.b * 255 * color.a);
    mspBackBuffer[i+3] =  static_cast<UINT8>(mspBackBuffer[i + 3] * inverse + color.a * 255 * color.a);
}

void BitmapExample::DrawRectangle(int left, int top, int w, int h, D2D1::ColorF color)
{
    for (int x = 0; x < w; ++x)
    {
        for (int y = 0; y < h; ++y)
        {
            DrawPixel(left + x, top + y, color);
        }
    }
}

void BitmapExample::ClearBuffer(D2D1::ColorF color)
{
    UINT8* p = &mspBackBuffer[0];

    for (int i = 0; i < BITMAP_WIDTH * BITMAP_HEIGHT; i++)
    {
        *p++ = static_cast<UINT8>(color.r * 255);
        *p++ = static_cast<UINT8>(color.g * 255);
        *p++ = static_cast<UINT8>(color.b * 255);
        *p++ = static_cast<UINT8>(color.a * 255);
    }
}

void BitmapExample::PresentBuffer()
{
    mspFrameBuffer->CopyFromMemory(nullptr,&mspBackBuffer[0], BITMAP_WIDTH * BITMAP_BYTECOUNT);
}
