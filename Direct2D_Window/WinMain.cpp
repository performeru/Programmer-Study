#include <windows.h>
#include <d2d1.h>
#include <math.h>

#pragma comment (lib, "d2d1.lib")

const wchar_t gClassName[] = L"MyWindowClass";

ID2D1Factory* gpD2DFactory{};
ID2D1HwndRenderTarget* gpRenderTarget{};

ID2D1SolidColorBrush* gpBrush{};
ID2D1RadialGradientBrush* gpRadiaBrush{};


LRESULT CALLBACK WindowProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);
void OnPaint(HWND hwnd);

int WINAPI WinMain(_In_ HINSTANCE hInstance,
    _In_opt_ HINSTANCE hPrevInstance,
    _In_ LPSTR lpCmdLine,
    _In_ int nShowCmd)
{

    //D2D Factory
    
    HRESULT hr = D2D1CreateFactory(D2D1_FACTORY_TYPE_SINGLE_THREADED, &gpD2DFactory);

    if(FAILED(hr))
    {
        MessageBox(nullptr, L"Failed To CreateFactory", L"Error", MB_OK);
        return 0;
    }



    HWND hwnd;
    WNDCLASSEX wc;
    ZeroMemory(&wc, sizeof(WNDCLASSEX));
    wc.style = CS_HREDRAW | CS_VREDRAW;
    wc.lpszClassName = gClassName;
    wc.hInstance = hInstance;
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
    wc.lpfnWndProc = WindowProc;
    wc.cbSize = sizeof(WNDCLASSEX);
    if (!RegisterClassEx(&wc))
    {
        MessageBox(nullptr, L"Failed to register window class!", L"Error", MB_ICONEXCLAMATION | MB_OK);
        return 0;
    }

    RECT wr = { 0, 0, 1024, 768 };
    AdjustWindowRect(&wr, WS_OVERLAPPEDWINDOW, FALSE);
    hwnd = CreateWindowEx(NULL,
        gClassName,
        L"Direct2D",
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT,
        CW_USEDEFAULT,
        wr.right - wr.left,
        wr.bottom - wr.top,
        NULL,
        NULL,
        hInstance,
        NULL);
    if (hwnd == nullptr)
    {
        MessageBox(nullptr, L"Failed to create window class!", L"Error", MB_ICONEXCLAMATION | MB_OK);
        return 0;
    }

    GetClientRect(hwnd, &wr);

    gpD2DFactory->CreateHwndRenderTarget(
        D2D1::RenderTargetProperties(),
        D2D1::HwndRenderTargetProperties(hwnd, D2D1::SizeU(wr.right - wr.left, wr.bottom - wr.top)),
        &gpRenderTarget
    );

    if(FAILED(hr))
    {
        MessageBox(nullptr, L"Faile To Create HWNDRenderTarget!", L"Error", MB_OK);
        return 0;
    }

    hr = gpRenderTarget->CreateSolidColorBrush(D2D1::ColorF(D2D1::ColorF::Green), &gpBrush);

    D2D1_GRADIENT_STOP stops[2]
    {
        {0.0f, D2D1::ColorF(D2D1::ColorF::Yellow)},
        {1.0f, D2D1::ColorF(D2D1::ColorF::Crimson)}
    };
    ID2D1GradientStopCollection* pGradientStops{};
    hr = gpRenderTarget->CreateGradientStopCollection(
        stops,
        2,
        &pGradientStops
    );

    hr = gpRenderTarget->CreateRadialGradientBrush(
    D2D1::RadialGradientBrushProperties(D2D1::Point2(50.0f, 150.0f),D2D1::Point2F(0.0f, 0.0f),
        50, 50),pGradientStops, &gpRadiaBrush );

    if(pGradientStops != nullptr)
    {
        pGradientStops->Release();
        pGradientStops = nullptr;
    }

    ShowWindow(hwnd, nShowCmd);
    UpdateWindow(hwnd);

    MSG msg;
    while (true)
    {
        if(PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);

            if(msg.message== WM_QUIT)
            {
                break;
            }
            else
            {
                OnPaint(hwnd);
            }
        }
    }

   /* while (GetMessage(&msg, NULL, 0, 0))
    {   
        OnPaint(hwnd);
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }*/
    
    //해제
    if(gpRadiaBrush!=nullptr)
    {
        gpRadiaBrush->Release();
        gpRadiaBrush = nullptr;
    }
    if(gpBrush!=nullptr)
    {
        gpBrush->Release();
        gpBrush = nullptr;
    }

    if(gpRenderTarget!=nullptr)
    {
        gpRenderTarget->Release();
        gpRenderTarget = nullptr;
    }
    if(gpD2DFactory!=nullptr)
    {
        gpD2DFactory->Release();
        gpD2DFactory = nullptr;
    }
  

    return static_cast<int>(msg.wParam);
}

void OnPaint(HWND hwnd)
{
    HDC hdc;
    PAINTSTRUCT ps;
    hdc = BeginPaint(hwnd, &ps);

    //Render Target 그리기
    gpRenderTarget->BeginDraw();
    gpRenderTarget->Clear(D2D1::ColorF(0.0f, 0.2f, 0.4f, 1.0f));

    gpBrush->SetColor(D2D1::ColorF(0.0f, 1.0f, 0.0f));
    gpBrush->SetOpacity(1.0f);
    gpRenderTarget->FillRectangle(D2D1::RectF(0.0f, 0.0f, 100.0f, 100.0f), gpBrush);
   
    gpBrush->SetColor(D2D1::ColorF(0.0f, 0.0f, 1.0f));
    gpBrush->SetOpacity(0.5f);
    gpRenderTarget->FillRectangle(D2D1::RectF(50.0f, 50.0f, 150.0f, 150.0f), gpBrush);

    static float angle = 0.0f;
    
    gpRenderTarget->FillEllipse(D2D1::Ellipse
    (D2D1::Point2F(75.0f + sin(angle) * 25.0f, 150.0f), 50.0f, 50.0f), gpRadiaBrush);
    
    angle += 0.3f;

    gpRenderTarget->EndDraw();

    EndPaint(hwnd, &ps);
}

LRESULT CALLBACK WindowProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_PAINT:
        OnPaint(hwnd);
        break;
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
