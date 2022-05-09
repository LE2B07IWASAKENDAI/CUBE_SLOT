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
	//+‚É•ÏX
	if (negative == 1)
	{
		medal = medal * -1;
		
	}

	medal_NN = medal;

	//–œ‚ÌˆÊ
	myriad = medal / 10000;
	medal = medal - myriad * 10000;
	//ç‚ÌˆÊ
	thousand = medal / 1000;
	medal = medal - thousand * 1000;
	//•S‚ÌˆÊ
	century = medal / 100;
	medal = medal - century * 100;
	//\‚ÌˆÊ
	ten = medal / 10;
	medal = medal - ten * 10;
	//ˆê‚ÌˆÊ
	one = medal;

}
