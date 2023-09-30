#include <sstream>
#include <Windows.h>
#include <gdiplus.h>

#pragma comment (lib, "Gdiplus.lib")
using namespace std;

const wchar_t gClassName[] = L"MyWindowClass";

LRESULT CALLBACK WindowProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);

int WINAPI WinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPSTR lpCmdLine,
	_In_ int nShowCmd)
{
	Gdiplus::GdiplusStartupInput gpsi;
	ULONG_PTR gdiToken;
	Gdiplus::GdiplusStartup(&gdiToken, &gpsi, nullptr);

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

	HWND hwnd;
	hwnd = CreateWindowEx(0, gClassName, L"Hello Window", WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT,
		640, 480, NULL, NULL, hInstance, NULL);

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

	return msg.wParam;
}

void OnPaint(HWND hwnd)
{
	PAINTSTRUCT ps;
	HDC hdc = BeginPaint(hwnd, &ps);

	HPEN redPen = CreatePen(PS_SOLID, 1, RGB(255, 0, 0));
	HBRUSH hatchBrush = CreateHatchBrush(HS_CROSS, RGB(255, 0, 0));

	SelectObject(hdc, redPen);
	SelectObject(hdc, hatchBrush);
	Rectangle(hdc, 0, 0, 100, 100);

	DeleteObject(hatchBrush);
	DeleteObject(redPen);

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
