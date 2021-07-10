// dllmain.cpp : 定义 DLL 应用程序的入口点。
#include <stdio.h>
#include <psapi.h>
#include <iostream>
#include "dllmain.h"
#define BUTTON_1 3300
#define BUTTON_2 3301
//extern "C" _declspec(dllexport)
LONG OldWindowProc, Button1Proc;
HWND pro_hwnd;               //程序句柄
HANDLE hpro;                //进程句柄
DWORD pro_base = NULL;      //程序基地址
char szBuf[1024] = { 0 };
LRESULT CALLBACK NewWndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
HWND pause;
HWND sun;

int kill() {
	pro_hwnd = PVZ::gethwnd();
	DWORD pro_id;
	GetWindowThreadProcessId(pro_hwnd, &pro_id);
	hpro = OpenProcess(PROCESS_CREATE_THREAD | PROCESS_VM_OPERATION | PROCESS_VM_WRITE | PROCESS_VM_READ | PROCESS_QUERY_INFORMATION, FALSE, pro_id);
	if (hpro == 0) {
		printf("无法获取进程句柄");
	}
	printf("进程句柄id: %d\n", hpro);
	HMODULE hModule[200] = { 0 };
	DWORD dwRet = 0;
	int num = 0;
	int bRet = EnumProcessModulesEx(hpro, (HMODULE *)(hModule), sizeof(hModule), &dwRet, NULL);
	if (bRet == 0) {
		printf("EnumProcessModules");
	}
	num = dwRet / sizeof(HMODULE);
	pro_base = (DWORD)hModule[0];
	return 0;
}

DWORD APIENTRY Msg(LPVOID lpParameter)
{
	char szBuf[1024] = { 0 };
	//hwnd = FindWindow(NULL, TEXT("wintest"));
	pause = CreateWindow(TEXT("BUTTON"),
		TEXT("暂停"),
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
		685, 33, 110, 25,
		pro_hwnd,
		(HMENU)BUTTON_1,
		NULL, //(HINSTANCE)GetWindowLongPtr((HWND)lpParameter,GWLP_HWNDPARENT)
		NULL);

	sun = CreateWindow(TEXT("BUTTON"),
		TEXT("增加阳光"),
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
		685, 53, 110, 25,
		pro_hwnd,
		(HMENU)BUTTON_2,
		NULL, //(HINSTANCE)GetWindowLongPtr((HWND)lpParameter,GWLP_HWNDPARENT)
		NULL);

	HFONT hf = CreateFont(24,                                                 //   nHeight 
		0,                                                   //   nWidth 
		0,                                                   //   nEscapement 
		0,                                                   //   nOrientation 
		FW_BOLD,                                       //   nWeight 
		FALSE,                                           //   bItalic 
		FALSE,                                           //   bUnderline 
		0,                                                   //   cStrikeOut 
		DEFAULT_CHARSET,                       //   nCharSet 
		OUT_DEFAULT_PRECIS,                 //   nOutPrecision 
		CLIP_DEFAULT_PRECIS,               //   nClipPrecision 
		DEFAULT_QUALITY,                       //   nQuality 
		DEFAULT_PITCH | FF_SWISS,     //   nPitchAndFamily 
		TEXT("微软雅黑"));                           //   lpszFacename 

	//set font we defined
	SendMessageW(pause, WM_SETFONT, (WPARAM)hf, TRUE);
	SendMessageW(sun, WM_SETFONT, (WPARAM)hf, TRUE);
	OldWindowProc = GetWindowLong(pro_hwnd, GWL_WNDPROC);
	SetWindowLong(pro_hwnd, GWL_WNDPROC, (LONG)NewWndProc);

	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return 0;
}

LRESULT CALLBACK NewWndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	int wmId, wmEvent;
	switch (message)
	{
	case WM_COMMAND:
		wmId = LOWORD(wParam);
		wmEvent = HIWORD(wParam);
		// 分析菜单选择:
		int* i;
		int* jjj;
		switch (wmId)
		{
		case BUTTON_1:
			i = memory::P3((int*)0x6a9ec0, 0x768, 0x164);
			jjj = memory::P2((int*)0x6a9ec0, 0x768);
			if (*jjj == 0) {
				SendMessage(pause, WM_DESTROY, 0, 0);
				break;
			}
			if (*i == 1) {
				*i = 0;
				SendMessageA(pause, WM_SETTEXT, 0, (LPARAM)"暂停");
			}
			else {
				*i = 1;
				SendMessageA(pause, WM_SETTEXT, 0, (LPARAM)"恢复");
			}
			break;
		case BUTTON_2:
			PVZ::setsun((int)PVZ::getsun() + 1000);
		default:
			return  CallWindowProc((WNDPROC)OldWindowProc, hWnd, message, wParam, lParam);
		}
		break;
	default:
		return  CallWindowProc((WNDPROC)OldWindowProc, hWnd, message, wParam, lParam);
	}
	return 0;
}
//生成在Button.h定义的全部按钮。这部分有点复杂，想要新增按钮又看不懂的可加qq2537237248帮忙。
void Buttons(HMODULE hModule) {
	kill();
	CreateThread(NULL, 0, Msg, hModule, 0, NULL);
}