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
	//+�ɕύX
	if (negative == 1)
	{
		medal = medal * -1;
		
	}

	medal_NN = medal;

	//���̈�
	myriad = medal / 10000;
	medal = medal - myriad * 10000;
	//��̈�
	thousand = medal / 1000;
	medal = medal - thousand * 1000;
	//�S�̈�
	century = medal / 100;
	medal = medal - century * 100;
	//�\�̈�
	ten = medal / 10;
	medal = medal - ten * 10;
	//��̈�
	one = medal;

}
