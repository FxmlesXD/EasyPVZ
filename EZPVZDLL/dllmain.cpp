// dllmain.cpp : 定义 DLL 应用程序的入口点。
#include "pch.h"
#include "dllmain.h"
#include <tchar.h>
#include <cstring>
#include "Button.h"
using namespace std;
//6月30日 弹出了第一个dll注入成功窗口

int 信息框(LPCSTR 内容,LPCSTR 标题,UINT 类型（比如按钮_MB_OK和MB_YESNO_或图标MB_ICONERROR）) {
	MessageBoxA(PVZ::gethwnd(), 内容, 标题, 类型（比如按钮_MB_OK和MB_YESNO_或图标MB_ICONERROR）);
	return 0;
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved)
{
	
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH://dll注入成功执行的代码。
        DisableThreadLibraryCalls(hModule);
        if (PVZ::version())
        {
			Buttons(hModule);
			信息框("注入成功！", "", MB_OK | MB_ICONASTERISK);
			///
			if (PVZ::baseaddress()) {
				
			}
			else
				return 1;
        }
        else
            MessageBoxA(PVZ::gethwnd(), "注入失败！", "", MB_OK|MB_ICONERROR);
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}