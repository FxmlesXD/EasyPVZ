#include "pch.h"
#include "Menu.h"

const char* MenuType::ToString(MenuType scenet)
{
	switch (scenet)
	{
	case MenuType::ͼ��:
		return "ͼ��";
	case MenuType::��ͣ:
		return "��ͣ";
	case MenuType::�Ƿ�:
		return "�Ƿ�";
	case MenuType::�̵��:
		return "�̵��";
	case MenuType::�û�����:
		return "�û�����";
	case MenuType::�˵�:
		return "�˵�";
	default:
		return "��Ч��ֵ";
	}
}