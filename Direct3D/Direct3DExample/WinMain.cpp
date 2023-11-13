#include "DrawTriangle.h"

int WINAPI WinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPSTR lpCmdLine,
	_In_ int nShowCmd)
{
	DrawTriangle framework;

	framework.Initialize(hInstance);

	framework.GameLoop();

	framework.Destroy();

	return 0;
}
