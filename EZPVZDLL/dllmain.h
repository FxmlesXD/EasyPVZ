#pragma once
#include "pch.h"
#include "memory.h"
#include "Enums.h"
#include <windef.h>

int* memory::P2(int* ��ַ, int ƫ��1)
{
	return (int*)(*��ַ + ƫ��1);
}
int* memory::P3(int* ��ַ, int ƫ��1, int ƫ��2)
{
	return (int*)(*(int*)(*��ַ + ƫ��1) + ƫ��2);
}
int* memory::P4(int* ��ַ, int ƫ��1, int ƫ��2, int ƫ��3)
{
	return (int*)(*(int*)(*(int*)(*��ַ + ƫ��1) + ƫ��2) + ƫ��3);
}
//����Ĳ��ù�

///////////////////////////
//         ////    //    //
//  /////////////  //  ////
//       ////////      ////
//  ////////////   //   ///
//  ///////////    //    //
///////////////////////////

namespace PVZ {
	//��ȡ��Ϸ�ڵ�����
	int* getsun() {
		return memory::P3((int*)0x6a9ec0, 0x768, 0x5560);
	}
	//������Ϸ�ڵ�����
	int setsun(int Ҫ���õ�����ֵ) {
		int* i = memory::P3((int*)0x6a9ec0, 0x768, 0x5560);
		*i = Ҫ���õ�����ֵ;
		return 0;
	}
	//������֤pvz�汾�Ƿ����Ҫ�󣬷��Ϸ���true�������Ϸ���false
	bool version() {
		int* i = (int*)0x552013;
		if (*i == 0xC35EDB74)
			return true;
		return false;
	}
	//�ж���Ϸ�Ƿ��ڹؿ���
	bool baseaddress() {
		int *i = memory::P2((int*)0x6a9ec0, 0x768);
		if (*i != 0)
			return true;
		return false;
	}
	//��ȡ��ϷHWND
	HWND gethwnd() {
		int* i = memory::P2((int*)0x6a9ec0, 0x350);
		return (HWND)*i;
	}
	//��ȡ��Ϸ�ڹؿ�����
	SceneType::SceneType getlevelscene() {
		int* i = memory::P3((int*)0x6a9ec0, 0x768, 0x554c);
		return (SceneType::SceneType)*i;
	}
	//������Ϸ�ڹؿ�����
	SceneType::SceneType setlevelscene(SceneType::SceneType �������) {
		int* i = memory::P3((int*)0x6a9ec0, 0x768, 0x554c);
		*i = �������;
		return �������;
	}
	//��ȡ��Ϸ�Ƿ���ͣ
	bool getpause() {
		return memory::P3((int*)0x6a9ec0, 0x768, 0x164);
	}
	//������Ϸ�Ƿ���ͣ
	int setpause(int _1Ϊ�ǣ�0Ϊ��) {
		int* i = memory::P3((int*)0x6a9ec0, 0x768, 0x164);
		*i = _1Ϊ�ǣ�0Ϊ��;
		return 0;
	}
	//��ȡ��Ϸ��ǰ�ؿ�
	PVZLevel::PVZLevel getlevel() {
		int* i = memory::P2((int*)0x6a9ec0, 0x7F8);
		return (PVZLevel::PVZLevel)*i;
	}
	//������Ϸ��ǰ�ؿ�
	PVZLevel::PVZLevel setlevel(PVZLevel::PVZLevel �ؿ�) {
		int* i = memory::P2((int*)0x6a9ec0, 0x7F8);
		*i = �ؿ�;
		return �ؿ�;
	}
}
namespace Creater {
	//����һ��ֲ�� ������������д������PlantType::ֲ������
	int CreatePlant(int ��, int ��, int ֲ������) {
		int* i = memory::P2((int*)0x6a9ec0, 0x768);
		int j = *i;
		int k = 0x40D120;
		_asm {
			mov ecx,j 
			push 10
			push ֲ������
			mov eax, ��
			push ��
			push ecx
			call k
		}
		return 0;
	}
	int CreateZombie(int ��, signed char ��, int ��ʬ����) {
		int* i = memory::P3((int*)0x6a9ec0, 0x768, 0x160);
		int j = *i;
		int cal = 0x42A0F0;
		_asm {
			mov ecx, j
			mov eax, ��
			push ��
			push 15
			call cal
		}
		return 0;
	}
}
namespace calls {
	//[CALL]ֱ�ӻ�ʤ
	void win() {
		int i = 0x40c3e0;
		int* j = memory::P2((int*)0x6a9ec0, 0x768);
		int k = *j;
		_asm {
			mov ecx, k
			call i
		}
	}
	//[CALL]����������
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