// dllmain.cpp : 定义 DLL 应用程序的入口点。
#include "pch.h"
#include "dllmain.h"
#include <tchar.h>
#include <cstring>
#include "Button.h"
using namespace std;
//6月30日 弹出了第一个dll注入成功窗口

BOOL APIENTRY DllMain(HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved)
{
	
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH://dll注入成功执行的代码。
        DisableThreadLibraryCalls(hModule);
		
        if (version()) 
        {
			Buttons(hModule);
			MessageBoxA(gethwnd(), "注入成功！", "EasyPVZ Framework", MB_OK | MB_ICONASTERISK);
			//在这里写代码
			if (baseaddress()) {
			}
			else
				MessageBoxA(gethwnd(), "不在关卡内。", "NONE", MB_OK | MB_ICONWARNING);
        }
        else
            MessageBoxA(gethwnd(), "注入失败，请检查你的植物大战僵尸版本！", "EasyPVZ Framework", MB_OK|MB_ICONERROR);
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}