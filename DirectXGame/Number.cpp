#include "Number.h"

int Number::decision(int medal)
{
	if (medal < 0)
	{
		negative = 1;
	}
	else
	{
		negative = 0;
	}

	return negative;
}

void Number::operation(int medal)
{
	//+に変更
	if (negative == 1)
	{
		medal = medal * -1;
		
	}

	medal_NN = medal;

	//万の位
	myriad = medal / 10000;
	medal = medal - myriad * 10000;
	//千の位
	thousand = medal / 1000;
	medal = medal - thousand * 1000;
	//百の位
	century = medal / 100;
	medal = medal - century * 100;
	//十の位
	ten = medal / 10;
	medal = medal - ten * 10;
	//一の位
	one = medal;

}
