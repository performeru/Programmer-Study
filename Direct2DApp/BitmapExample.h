#pragma once
#include "D2DFramework.h"
#include <memory>

const int BITMAP_WIDTH = 1024;
const int BITMAP_HEIGHT = 768;
const int BITMAP_BYTECOUNT = 4;

class BitmapExample : public D2DFramework
{
private:
	Microsoft::WRL::ComPtr<ID2D1Bitmap> mspFrameBuffer;
	std::unique_ptr<UINT8[]> mspBackBuffer;

protected:
	virtual HRESULT CreateDeviceResources() override;

public:
	virtual HRESULT Initialize(HINSTANCE hInstance, LPCWSTR title = L"BitmapExample", 
								UINT w = BITMAP_WIDTH, UINT h = BITMAP_HEIGHT) override;
	virtual void Render() override;

	void DrawPixel(int x, int y, D2D1::ColorF color);
	void DrawRectangle(int left, int top, int w, int h, D2D1::ColorF color);
	void ClearBuffer(D2D1::ColorF color);
	void PresentBuffer();
};
