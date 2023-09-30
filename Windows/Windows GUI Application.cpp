#include <sstream>
#include <Windows.h>
#include <gdiplus.h>

#pragma comment (lib, "Gdiplus.lib")
using namespace std;
using namespace Gdiplus;

const wchar_t gClassName[] = L"MyWindowClass";

LRESULT CALLBACK WindowProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);

int WINAPI WinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPSTR lpCmdLine,
	_In_ int nShowCmd)
{
	GdiplusStartupInput gpsi;
	ULONG_PTR gdiToken;
	GdiplusStartup(&gdiToken, &gpsi, nullptr);

	WNDCLASSEX wc{};

	ZeroMemory(&wc, sizeof(WNDCLASSEX));
	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.lpszClassName = gClassName;
	wc.hInstance = hInstance;
	wc.lpfnWndProc = WindowProc;
	wc.cbSize = sizeof(WNDCLASSEX);

	wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);

	if(!RegisterClassExW(&wc))
	{
		MessageBox(nullptr, L"Failled to register", L"Error", MB_OK);
		return 0;
	}

	RECT wr = { 0, 0, 640, 480 };
	AdjustWindowRect(&wr, WS_OVERLAPPEDWINDOW, FALSE);

	HWND hwnd;
	hwnd = CreateWindowEx(0, gClassName, L"Hello Window", 
		WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT,
		wr.right - wr.left, wr.bottom- wr.top,
		NULL, NULL, hInstance, NULL);

	if(!hwnd)
	{
		MessageBox(nullptr, L"Failed to create", L"Error", MB_OK);
		return 0;
	}

	ShowWindow(hwnd, nShowCmd);
	UpdateWindow(hwnd);

	MSG msg;
	while (GetMessage(&msg, NULL,0,0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	Gdiplus::GdiplusShutdown(gdiToken);
	return msg.wParam;
}

void OnPaint(HWND hwnd)
{
	PAINTSTRUCT ps;
	HDC hdc = BeginPaint(hwnd, &ps);

	Pen redPen(Color(255, 255, 0, 0));
	HatchBrush hatchBrush(HatchStyle::HatchStyleCross, Color(255, 255, 0, 0));
	Image image(L"image.png");

	Graphics graphics(hdc);
	graphics.DrawImage(&image, 0, 0, 640, 480);

	EndPaint(hwnd, &ps);
}


LRESULT CALLBACK WindowProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch(message)
	{
	case WM_PAINT:
	{
		OnPaint(hwnd);
		break;
	}
	case WM_KEYDOWN:
	{
		std::ostringstream oss;

		oss << "Virtual keycode" << wParam << endl;
		OutputDebugStringA(oss.str().c_str());
		break;
	}
	case WM_LBUTTONDOWN:
	{
		int x = LOWORD(lParam);
		int y = HIWORD(lParam);
		OutputDebugStringA("Hello\n");
		break;
	}
	case WM_CLOSE:
		DestroyWindow(0);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hwnd, message, wParam, lParam);
		break;

	}
}
