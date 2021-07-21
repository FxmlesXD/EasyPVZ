// dllmain.cpp : 定义 DLL 应用程序的入口点。
#include "pch.h"
#include "dllmain.h"
#include <tchar.h>
#include <cstring>
#include "Button.h"
using namespace std;

int 信息框(LPCWSTR 内容,LPCWSTR 标题,UINT 类型（比如按钮_MB_OK和MB_YESNO_或图标MB_ICONERROR）) {
	MessageBoxW(PVZ::gethwnd(), 内容, 标题, 类型（比如按钮_MB_OK和MB_YESNO_或图标MB_ICONERROR）);
	return 0;
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved)
{
	//////!!!!!!!! 编译不成功的 看这里
	//////!!!!!!!! 把“本地Windows调试器”左边的两个东西 第一个改成Release 第二个改成x86 ！！！
	//////////////////////////////////////////////////////////////////////////////////
	///////////////如果编译出现"无法启动程序“XXXXXX”"说明你编译成功了！直接拿dll注入器注入就可以了！
	/////////////////////////////////////////////////////////////////////////////////
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH://dll注入成功执行的代码。
		if (PVZ::version())
		{
			Buttons(hModule);
			if (PVZ::baseaddress()) {
				PVZ::setlevelscene(SceneType::Fog);
				Creater::CreatePlant(1, 1, PlantType::CherryBomb);
				PVZ::setsun(20);
			}
			else
				return 1;
		}
		else
			return 0;
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}