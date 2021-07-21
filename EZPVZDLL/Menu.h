#pragma once
namespace MenuType
{
	enum MenuType
	{
		图鉴 = 1,
		暂停 = 2,
		是否 = 3,
		商店等 = 4,
		用户管理 = 6,
		菜单 = 8,
	};

	extern const char* ToString(MenuType scenet);

}