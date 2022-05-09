#pragma once
#include<Windows.h>

class Number
{

public://// メンバ関数

	///<summary>
	///マイナスかどうかの判断
	/// </summary>
	int decision(int medal);

	///<summary>
	///位ごとの枚数計算
	///</summary>
	void operation(int medal);

	///<summary>
	///メダル枚数正数化の渡し
	/// </summary>
	/// <returns></returns>
	int GetPNumber() { return medal_NN; }

	///<summary>
	///一の位を渡す
	/// </summary>
	/// <returns></returns>
	int GetOnesPlace() { return one; }

	/// <summary>
	/// 十の位を渡す
	/// </summary>
	/// <returns></returns>
	int GetTensPlace() { return ten; }

	/// <summary>
	/// 百の位を渡す
	/// </summary>
	/// <returns></returns>
	int GetCenturysPlace() { return century; }

	/// <summary>
	/// 千の位を渡す
	/// </summary>
	/// <returns></returns>
	int GetThousandsPlace() { return thousand; }

	/// <summary>
	/// 万の位を渡す
	/// </summary>
	/// <returns></returns>
	int GetMyriadsPlace() { return myriad; }

private:// メンバ変数
	int one = 0; //一の位
	int ten = 0; //十の位
	int century = 0; //百の位
	int thousand = 0; //千の位
	int myriad = 0; //万の位
	int negative = 0;//マイナスなら１
	int negative_N = 10;//マイナスなら１
	int medal = 0;//表示のため
	int medal_NN = 0;//表示のため

};

