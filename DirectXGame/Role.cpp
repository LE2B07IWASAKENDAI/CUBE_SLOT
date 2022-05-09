#include "Role.h"

int Role::Distribute(int lottery)
{
	if (lottery >= 30 && lottery < 50)
	{
		result = grape;
	}
	else if (lottery >= 50 && lottery < 70)
	{
		result = replay;
	}
	else if (lottery >= 70 && lottery < 80)
	{
		result = bell;
	}
	else if (lottery >= 80 && lottery < 85)
	{
		result = cherry;
	}
	else if (lottery >= 85 && lottery < 89)
	{
		result = clown;
	}
	else if (lottery >= 89 && lottery < 91)
	{
		result = bar;
	}
	else if (lottery >= 91 && lottery < 96)
	{
		result = hit_bar;
	}
	else if (lottery >= 96)
	{
		result = hit;
	}
	else
	{
		result = no;
	}

	return result;
}

int Role::Confirm(int one, int two, int three, int four, int five, int six, int seven, int eight, int nine)
{


	//上横列
	if (one == two && one == three)
	{
		if (one == hit) { distribute = bigBonus; }
		if (one == bar) { distribute = bar; }
		if (one == grape) { distribute = grape; }
		if (one == bell) { distribute = bell; }
		if (one == replay) { distribute = replay; }
		if (one == clown) { distribute = clown; }

	}//REG
	else if (one == hit && one == two && three == bar)
	{
		distribute = regBonus;
	}
	//左上から右下
	if (one == five && one == nine)
	{
		if (one == hit) { distribute = bigBonus; }
		if (one == bar) { distribute = bar; }
		if (one == grape) { distribute = grape; }
		if (one == bell) { distribute = bell; }
		if (one == replay) { distribute = replay; }
		if (one == clown) { distribute = replay; }
	}//REG
	else if (one == hit && one == five && nine == bar)
	{
		distribute = regBonus;
	}
	//真ん中横
	if (four == five && four == six)
	{
		if (four == hit) { distribute = bigBonus; }
		if (four == bar) { distribute = bar; }
		if (four == grape) { distribute = grape; }
		if (four == bell) { distribute = bell; }
		if (four == replay) { distribute = replay; }
		if (four == clown) { distribute = clown; }
	}//REG
	else if (four == hit && four == five && six == bar)
	{
		distribute = regBonus;
	}
	//下横
	if (seven == eight && seven == nine)
	{
		if (seven == hit) { distribute = bigBonus; }
		if (seven == bar) { distribute = bar; }
		if (seven == grape) { distribute = grape; }
		if (seven == bell) { distribute = bell; }
		if (seven == replay) { distribute = replay; }
		if (seven == clown) { distribute = clown; }
	}//REG
	else if (seven == hit && seven == eight && nine == bar)
	{
		distribute = regBonus;
	}
	//左下から右上
	if (seven == five && seven == three)
	{
		if (seven == hit) { distribute = bigBonus; }
		if (seven == bar) { distribute = bar; }
		if (seven == grape) { distribute = grape; }
		if (seven == bell) { distribute = bell; }
		if (seven == replay) { distribute = replay; }
		if (seven == clown) { distribute = clown; }
	}//REG
	else if (seven == hit && seven == five && three == bar)
	{
		distribute = regBonus;
	}
	//チェリー
	if (distribute == 0)
	{
		if (one == cherry || four == cherry || seven == cherry)
		{
			if (one == two ||
				four == five ||
				seven == eight)
			{
				distribute = cherry;
			}
		}
	}

	return distribute;
}
