#include <windows.h>
#include "ActorExample.h"

int WINAPI WinMain(_In_ HINSTANCE hInstance,
    _In_opt_ HINSTANCE hPrevInstance,
    _In_ LPSTR lpCmdLine,
    _In_ int nShowCmd)
{
    try
    {
     ActorExample myFramework;

    
    myFramework.Initialize(hInstance, L"Framework", 1024, 768);

    int ret= myFramework.GameLoop();

    myFramework.Release();
      
    return ret;
    }
      
    catch(const com_exception& e)
    {
    OutputDebugStringA(e.what());
    MessageBoxA(nullptr, e.what(), "Error", MB_OK);
    }

    return 0;

}
