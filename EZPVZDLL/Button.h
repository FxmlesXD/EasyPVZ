// dllmain.cpp : 定义 DLL 应用程序的入口点。
#include <stdio.h>
#include <psapi.h>
#include <iostream>
#include "dllmain.h"
#define BUTTON_1 3300
#define WINBUTTON 3301
//extern "C" _declspec(dllexport)
LONG OldWindowProc, Button1Proc;
HWND pro_hwnd;               //程序句柄
HANDLE hpro;                //进程句柄
DWORD pro_base = NULL;      //程序基地址
char szBuf[1024] = { 0 };
LRESULT CALLBACK NewWndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

HWND pause;
HWND win;

int kill() {
	pro_hwnd = PVZ::gethwnd();
	DWORD pro_id;
	GetWindowThreadProcessId(pro_hwnd, &pro_id);
	hpro = OpenProcess(PROCESS_CREATE_THREAD | PROCESS_VM_OPERATION | PROCESS_VM_WRITE | PROCESS_VM_READ | PROCESS_QUERY_INFORMATION, FALSE, pro_id);
	HMODULE hModule[200] = { 0 };
	DWORD dwRet = 0;
	int num = 0;
	int bRet = EnumProcessModulesEx(hpro, (HMODULE *)(hModule), sizeof(hModule), &dwRet, NULL);
	num = dwRet / sizeof(HMODULE);
	pro_base = (DWORD)hModule[0];
	return 0;
}

DWORD APIENTRY Msg(LPVOID lpParameter)
{
	char szBuf[1024] = { 0 };
	pause = CreateWindowW(TEXT("BUTTON"), TEXT("暂停"), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 685, 33, 110, 25, pro_hwnd, (HMENU)BUTTON_1, NULL, NULL);
	win = CreateWindowW(TEXT("BUTTON"), TEXT("获胜"), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 685, 66, 50, 50, pro_hwnd, (HMENU)WINBUTTON, NULL, NULL);

	HFONT 微软雅黑 = CreateFont(16, 0, 0, 0,FW_NORMAL , FALSE, FALSE, 0, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_SWISS, TEXT("微软雅黑"));
	HFONT 宋体 = CreateFont(16, 0, 0, 0, FW_NORMAL, FALSE, FALSE, 0, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_SWISS, TEXT("宋体"));
	
	//这里给按钮发送信息：改变字体
	SendMessage(pause, WM_SETFONT, (WPARAM)宋体, TRUE);
	SendMessage(win, WM_SETFONT, (WPARAM)宋体, TRUE);

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
				SendMessage(pause, WM_DELETEITEM, 0, 0);
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
		case WINBUTTON:
				calls::win();
			break;
		default:
			return  CallWindowProc((WNDPROC)OldWindowProc, hWnd, message, wParam, lParam);
		}
		break;
	default:
		return  CallWindowProc((WNDPROC)OldWindowProc, hWnd, message, wParam, lParam);
	}
	return 0;
}

DWORD WINAPI dowhile(LPVOID lpParameter) {
	while (1) {
		int* jjj;
		jjj = memory::P2((int*)0x6a9ec0, 0x768);
		if (*jjj == 0) {
			ShowWindow(pause, 0);
			ShowWindow(win, 0);
		}
		else {
			ShowWindow(pause, 5);
			ShowWindow(win, 5);
		}
		Sleep(1000);
	}
	return 0;
}

//生成在Button.h定义的全部按钮。这部分有点复杂，想要新增按钮又看不懂的可加qq2537237248帮忙。
void Buttons(HMODULE hModule) {
	kill();
	CreateThread(NULL, 0, Msg, hModule, 0, NULL);
	CreateThread(NULL, 0, dowhile, 0, 0, NULL);
}