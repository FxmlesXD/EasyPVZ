#pragma once
#include "pch.h"
#include "memory.h"

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
//��ȡ��Ϸ�ڵ�����
int* getsun() {
	return memory::P3((int*)0x6a9ec0, 0x768, 0x5560);
}
//������Ϸ�ڵ�����
int setsun(int sun) {
	int* i = memory::P3((int*)0x6a9ec0, 0x768, 0x5560);
	*i = sun;
	return sun;
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
//[CALL]ֱ�ӻ�ʤ
void win() {
	int i = 0x40c3e0;
	int* j = memory::P2((int*)0x6a9ec0, 0x768);
	int k = *j;
	_asm {
		mov ecx,k
		call i
	}
}
//��ȡ��ϷHWND
HWND gethwnd() {
	int* i = memory::P2((int*)0x6a9ec0, 0x350);
	return (HWND)*i;
}
//��ȡ��Ϸ�ڹؿ�����
int* getlevelscene() {
	return memory::P3((int*)0x6a9ec0, 0x768, 0x554c);
}
//������Ϸ�ڹؿ�����
int setlevelscene(int Scene) {
	int* i = memory::P3((int*)0x6a9ec0, 0x768, 0x554c);
	*i = Scene;
	return 0;
}
