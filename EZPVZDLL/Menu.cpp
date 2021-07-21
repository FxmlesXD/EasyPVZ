#include "pch.h"
#include "Menu.h"

const char* MenuType::ToString(MenuType scenet)
{
	switch (scenet)
	{
	case MenuType::图鉴:
		return "图鉴";
	case MenuType::暂停:
		return "暂停";
	case MenuType::是否:
		return "是否";
	case MenuType::商店等:
		return "商店等";
	case MenuType::用户管理:
		return "用户管理";
	case MenuType::菜单:
		return "菜单";
	default:
		return "无效的值";
	}
}