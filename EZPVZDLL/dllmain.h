#pragma once
#include "pch.h"
#include "memory.h"
#include "Enums.h"
#include <windef.h>

int* memory::P2(int* 基址, int 偏移1)
{
	return (int*)(*基址 + 偏移1);
}
int* memory::P3(int* 基址, int 偏移1, int 偏移2)
{
	return (int*)(*(int*)(*基址 + 偏移1) + 偏移2);
}
int* memory::P4(int* 基址, int 偏移1, int 偏移2, int 偏移3)
{
	return (int*)(*(int*)(*(int*)(*基址 + 偏移1) + 偏移2) + 偏移3);
}
//上面的不用管

///////////////////////////
//         ////    //    //
//  /////////////  //  ////
//       ////////      ////
//  ////////////   //   ///
//  ///////////    //    //
///////////////////////////

namespace PVZ {
	//读取游戏内的阳光
	int* getsun() {
		return memory::P3((int*)0x6a9ec0, 0x768, 0x5560);
	}
	//设置游戏内的阳光
	int setsun(int 要设置的阳光值) {
		int* i = memory::P3((int*)0x6a9ec0, 0x768, 0x5560);
		*i = 要设置的阳光值;
		return 0;
	}
	//可以验证pvz版本是否符合要求，符合返回true，不符合返回false
	bool version() {
		int* i = (int*)0x552013;
		if (*i == 0xC35EDB74)
			return true;
		return false;
	}
	//判断游戏是否在关卡内
	bool baseaddress() {
		int *i = memory::P2((int*)0x6a9ec0, 0x768);
		if (*i != 0)
			return true;
		return false;
	}
	//获取游戏HWND
	HWND gethwnd() {
		int* i = memory::P2((int*)0x6a9ec0, 0x350);
		return (HWND)*i;
	}
	//读取游戏内关卡场景
	SceneType::SceneType getlevelscene() {
		int* i = memory::P3((int*)0x6a9ec0, 0x768, 0x554c);
		return (SceneType::SceneType)*i;
	}
	//设置游戏内关卡场景
	SceneType::SceneType setlevelscene(SceneType::SceneType 场景编号) {
		int* i = memory::P3((int*)0x6a9ec0, 0x768, 0x554c);
		*i = 场景编号;
		return 场景编号;
	}
	//读取游戏是否暂停
	bool getpause() {
		return memory::P3((int*)0x6a9ec0, 0x768, 0x164);
	}
	//设置游戏是否暂停
	int setpause(int _1为是，0为否) {
		int* i = memory::P3((int*)0x6a9ec0, 0x768, 0x164);
		*i = _1为是，0为否;
		return 0;
	}
	//读取游戏当前关卡
	PVZLevel::PVZLevel getlevel() {
		int* i = memory::P2((int*)0x6a9ec0, 0x7F8);
		return (PVZLevel::PVZLevel)*i;
	}
	//设置游戏当前关卡
	PVZLevel::PVZLevel setlevel(PVZLevel::PVZLevel 关卡) {
		int* i = memory::P2((int*)0x6a9ec0, 0x7F8);
		*i = 关卡;
		return 关卡;
	}
}
namespace Creater {
	//创建一个植物 第三个参数填写方法：PlantType::植物类型
	int CreatePlant(int 行, int 列, int 植物类型) {
		int* i = memory::P2((int*)0x6a9ec0, 0x768);
		int j = *i;
		int k = 0x40D120;
		_asm {
			mov ecx,j 
			push 10
			push 植物类型
			mov eax, 行
			push 列
			push ecx
			call k
		}
		return 0;
	}
	int CreateZombie(int 行, signed char 列, int 僵尸类型) {
		int* i = memory::P3((int*)0x6a9ec0, 0x768, 0x160);
		int j = *i;
		int cal = 0x42A0F0;
		_asm {
			mov ecx, j
			mov eax, 行
			push 列
			push 15
			call cal
		}
		return 0;
	}
}
namespace calls {
	//[CALL]直接获胜
	void win() {
		int i = 0x40c3e0;
		int* j = memory::P2((int*)0x6a9ec0, 0x768);
		int k = *j;
		_asm {
			mov ecx, k
			call i
		}
	}
	//[CALL]寒冰菇冻结
	int Freeze() {
		int* i = memory::P3((int*)0x6a9ec0, 0x768, 0xAC);
		int j = *i;
		int cal = 0x466420;
		_asm {
			mov edi,i
			call cal
		}
		return 0;
	}
}