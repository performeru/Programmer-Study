#include "D2DFramework.h"

#pragma comment (lib,"d2d1.lib")
#pragma comment (lib, "WindowsCodecs.lib")

HRESULT D2DFramework::InitWindow(HINSTANCE hInstance, LPCWSTR title, UINT w, UINT h)
{
    HWND hwnd;
    WNDCLASSEX wc;
    ZeroMemory(&wc, sizeof(WNDCLASSEX));
    wc.style = CS_HREDRAW | CS_VREDRAW;
    wc.lpszClassName = gClassName;
    wc.hInstance = hInstance;
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
    wc.lpfnWndProc = D2DFramework::WndProc;
    wc.cbSize = sizeof(WNDCLASSEX);
  
    if (!RegisterClassEx(&wc))
    {
        return E_FAIL;
    }

    RECT wr = { 0, 0, static_cast<LONG>(w), static_cast<LONG>(h) };
    AdjustWindowRect(&wr, WS_OVERLAPPEDWINDOW, FALSE);
    hwnd = CreateWindowEx(NULL, gClassName, title,
    WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT,
    wr.right - wr.left, wr.bottom - wr.top, NULL,
    NULL, hInstance, NULL);
  
    if (hwnd == nullptr)
    {
        return E_FAIL;
    }

    mHwnd = hwnd;

    SetWindowLongPtr(mHwnd, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(this));

    return S_OK;
}

HRESULT D2DFramework::InitD2D(HWND hwnd)
{
    HRESULT hr;

    hr = ::CoCreateInstance(CLSID_WICImagingFactory, nullptr, CLSCTX_INPROC_SERVER, IID_PPV_ARGS(mspWICFactory.GetAddressOf() ));

    hr = D2D1CreateFactory(D2D1_FACTORY_TYPE_SINGLE_THREADED, mspD2DFactory.GetAddressOf());
    ThrowIfFailed(hr);

    hr = CreateDeviceResources();
  
    return S_OK;
}

HRESULT D2DFramework::CreateDeviceResources()
{
    mspRenderTarget.Reset();

    RECT wr;
    GetClientRect(mHwnd, &wr);
    HRESULT hr = mspD2DFactory->CreateHwndRenderTarget(
        D2D1::RenderTargetProperties(),
        D2D1::HwndRenderTargetProperties(mHwnd, D2D1::SizeU(wr.right - wr.left, wr.bottom - wr.top)),
        mspRenderTarget.ReleaseAndGetAddressOf()
    );

    ThrowIfFailed(hr);

    return S_OK;
}

HRESULT D2DFramework::Initialize(HINSTANCE hInstance, LPCWSTR title, UINT w, UINT h)
{
    ThrowIfFailed(CoInitialize(nullptr));
    ThrowIfFailed(InitWindow(hInstance, title, w, h));
    ThrowIfFailed(InitD2D(mHwnd));

    ShowWindow(mHwnd, SW_SHOW);
    UpdateWindow(mHwnd);
    return S_OK;
}

void D2DFramework::Release()
{
    mspRenderTarget.Reset();
    mspD2DFactory.Reset();
    mspWICFactory.Reset();

    CoUninitialize();
}

int D2DFramework::GameLoop()
{
    MSG msg;
    while (true)
    {
        if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);

            if (msg.message == WM_QUIT)
            {
                break;
            }
        }
        else
        {
            Render();
        }
    }

    return static_cast<int>(msg.wParam);
}

void D2DFramework::Render()
{
    mspRenderTarget->BeginDraw();
    mspRenderTarget->Clear(D2D1::ColorF(0.0f, 0.2f, 0.4f, 1.0f));
    HRESULT hr = mspRenderTarget->EndDraw();

    if (hr == D2DERR_RECREATE_TARGET)
    {
        CreateDeviceResources();
    }
}

void D2DFramework::ShowError(LPCWSTR msg, LPCWSTR title)
{
    MessageBox(nullptr, msg, title, MB_OK);
}

LRESULT D2DFramework::WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    D2DFramework* pFramework = reinterpret_cast<D2DFramework*>(GetWindowLongPtr(hwnd, GWLP_USERDATA));

    switch (message)
    {
    case WM_CLOSE:
        DestroyWindow(hwnd);
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hwnd, message, wParam, lParam);
    }
    return 0;
}
