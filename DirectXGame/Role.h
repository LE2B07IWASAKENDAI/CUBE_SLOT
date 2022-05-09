#pragma once
#include<Windows.h>

class Role
{
public://// メンバ関数

	/// <summary>
	/// 役の抽選結果の振り分け
	/// </summary>
	int Distribute(int lottery);

	/// <summary>
	/// 役の当選確認
	/// </summary>
	int Confirm(int one, int two, int three, int four, int five, int six, int seven, int eight, int nine);

	/// <summary>
	/// 前回の当選役リセット
	/// </summary>
	void Reset() { distribute = 0; }

private:// メンバ変数
	//役
	int hit = 1;  //7
	int bar = 2;    //BAR
	int grape = 3;  //ブドウ
	int bell = 4;   //ベル
	int replay = 5; //リプレイ
	int cherry = 6; //チェリー
	int clown = 7;  //ピエロ
	int hit_bar = 8; //バケBIG
	int no = 0;//何もなし

	int bonus = 0;     //ボーナス入ったかどうか
	int noBonus = 0;   //ボーナス無し
	int bigBonus = 1;  //BIGボーナス
	int regBonus = 9;  //REGボーナス

	int distribute = 0; //当選した役

	//抽選
	int result = 0;  //結果
};

