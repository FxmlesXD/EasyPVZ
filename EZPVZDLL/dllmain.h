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
		return memory::P3((int*)0x6B9FE0, 0x768, 0x5560);
	}
	//������Ϸ�ڵ�����
	int setsun(int Ҫ���õ�����ֵ) {
		int* i = memory::P3((int*)0x6B9FE0, 0x768, 0x5560);
		*i = Ҫ���õ�����ֵ;
		return 0;
	}
	//������֤pvz�汾�Ƿ����Ҫ�󣬷��Ϸ���true�������Ϸ���false
	bool version() {
		int* i = (int*)0x552013;
		if (*i == 3892314112)
			return true;
		return false;
	}
	//�ж���Ϸ�Ƿ��ڹؿ���
	bool baseaddress() {
		int* i = memory::P2((int*)0x6B9FE0, 0x768);
		if (*i != 0)
			return true;
		return false;
	}
	//��ȡ��ϷHWND
	HWND gethwnd() {
		int* i = memory::P2((int*)0x6B9FE0, 0x350);
		return (HWND)*i;
	}
	//��ȡ��Ϸ�ڹؿ�����
	SceneType::SceneType getlevelscene() {
		int* i = memory::P3((int*)0x6B9FE0, 0x768, 0x554c);
		return SceneType::Aquarium;
	}
	//������Ϸ�ڹؿ�����
	void setlevelscene(SceneType::SceneType �������) {
		int* i = memory::P3((int*)0x6B9FE0, 0x768, 0x554c);
		*i = �������;
	}
	//��ȡ��Ϸ�Ƿ���ͣ
	bool getpause() {
		return memory::P3((int*)0x6B9FE0, 0x768, 0x164);
	}
	//������Ϸ�Ƿ���ͣ
	int setpause(int _1Ϊ�ǣ�0Ϊ��) {
		int* i = memory::P3((int*)0x6B9FE0, 0x768, 0x164);
		*i = _1Ϊ�ǣ�0Ϊ��;
		return 0;
	}
	//��ȡ��Ϸ��ǰ�ؿ�
	PVZLevel::PVZLevel getlevel() {
		int* i = memory::P2((int*)0x6B9FE0, 0x7F8);
		return (PVZLevel::PVZLevel)*i;
	}
	//������Ϸ��ǰ�ؿ�
	PVZLevel::PVZLevel setlevel(PVZLevel::PVZLevel �ؿ�) {
		int* i = memory::P2((int*)0x6B9FE0, 0x7F8);
		*i = �ؿ�;
		return �ؿ�;
	}
	//�ж��Ƿ���ĳ���� �ɹ�����true ʧ�ܷ���false
	bool ifmenu(MenuType::MenuType ����) {
		int* i = memory::P4((int*)0x6B9FE0, 0x320, 0x94, 0xC);
		if (*i = ����)
			return true;
		return false;
	}
	//�ж��Ƿ��������� �ɹ�����true ʧ�ܷ���false
	bool ifmainmenu() {
		int* i = memory::P2((int*)0x6B9FE0, 0x770);
		if (*i != 0)
			return true;
		return false;
	}
}
namespace Creater {
	//����һ��ֲ�� ������������д������PlantType::ֲ������
	int CreatePlant(int ��, int ��, int ֲ������) {
		int* i = memory::P2((int*)0x6B9FE0, 0x768);
		int j = *i;
		int k = 0x40E620;
		_asm {
			push 0xFFFFFFFF
			push ֲ������
			mov eax, ��
			push ��
			push j
			call k
		}
		return 0;
	}
	int CreateZombie2(int ��, int ��, int ��ʬ����) {
		int cal = 0x42a0f0;
		int* a = memory::P3((int*)0x6a9ec0, 0x768, 0x160);
		int j = *a;
		_asm {
			pushad
			push ��
			push ��ʬ����
			mov eax,��
			mov ecx,a
			call cal
			popad
		}
		return 10;
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
}