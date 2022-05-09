#pragma once

#include "SafeDelete.h"
#include "DirectXCommon.h"
#include <DirectXMath.h>
#include "Input.h"
#include "Sprite.h"
#include "Object3d.h"
#include "DebugText.h"
#include "Audio.h"
#include "Number.h"
#include "Role.h"

/// <summary>
/// ゲームシーン
/// </summary>
class GameScene
{
private: // エイリアス
	// Microsoft::WRL::を省略
	template <class T> using ComPtr = Microsoft::WRL::ComPtr<T>;
	// DirectX::を省略
	using XMFLOAT2 = DirectX::XMFLOAT2;
	using XMFLOAT3 = DirectX::XMFLOAT3;
	using XMFLOAT4 = DirectX::XMFLOAT4;
	using XMMATRIX = DirectX::XMMATRIX;

private: // 静的メンバ変数
	static const int debugTextTexNumber = 0;

public: // メンバ関数

	/// <summary>
	/// コンストクラタ
	/// </summary>
	GameScene();

	/// <summary>
	/// デストラクタ
	/// </summary>
	~GameScene();

	/// <summary>
	/// 初期化
	/// </summary>
	void Initialize(DirectXCommon* dxCommon, Input* input, Audio* audio);

	/// <summary>
	/// 毎フレーム処理
	/// </summary>
	void Update();

	/// <summary>
	/// 描画
	/// </summary>
	void Draw();

private: // メンバ変数
	DirectXCommon* dxCommon = nullptr;
	Input* input = nullptr;
	Audio* audio = nullptr;
	DebugText debugText;
	Number* number = nullptr;
	Role* role = nullptr;

	/// <summary>
	/// ゲームシーン用
	/// </summary>
	
	//シーン
	int title = 1;
	int game = 2;
	int end = 3;
	int gameBonus = 4;
	int seccn = title;
	int saving = title;

	//背景
	Sprite* spriteBG[4];

	//左端リール
	Sprite* spriteReel_11[8];
	Sprite* spriteReel_12[8];
	Sprite* spriteReel_13[8];
	//中央リール
	Sprite* spriteReel_21[8];
	Sprite* spriteReel_22[8];
	Sprite* spriteReel_23[8];
	//右端リール
	Sprite* spriteReel_31[8];
	Sprite* spriteReel_32[8];
	Sprite* spriteReel_33[8];
	//枚数表示
	Sprite* one_S[11]; //一の位
	Sprite* ten_S[11]; //十の位
	Sprite* century_S[11]; //百の位
	Sprite* thousand_S[11]; //千の位
	Sprite* myriad_S[11];   //万の位

	Sprite* chec[10];//試し

	//演習出3Dオブジェクト
	Model* modelCube[11];
	Object3d* objCube = nullptr;

	//スロット配列
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
	int bonusNow = 9;//ボーナス中

	int bonus = 0;     //ボーナス入ったかどうか
	int noBonus = 0;   //ボーナス無し
	int bigBonus = 1;  //BIGボーナス
	int regBonus = 9;  //REGボーナス

	int distribute = 0; //当選した役
	//払い出し枚数
	int bar_SN = 70; //bar枚数
	int grape_SN = 7; //ブドウ枚数
	int bell_SN = 13; //ベル枚数
	int replay_SN = 3; //リプレイ枚数
	int cherry_SN = 1; //チェリー枚数
	int clown_SN = 15; //ピエロ枚数
	int bonusGrape_SN = 14;//ボーナス中ブドウ枚数

	//リール
	//リール＿１　　　BAR  ブドウ　リプレイ ブドウ　ベル　７　   リプレイ　ブドウ　リプレイ　ブドウ　BAR　チェリー　ブドウ　リプレイ　ブドウ　７　  ピエロ　ブドウ　リプレイ　ブドウ　チェリー
	int reel_1[23] = { bar, grape,  replay,  grape,  bell, hit, replay,   grape,  replay,   grape,  bar, cherry,    grape, replay,    grape,   hit, clown,  grape, replay,    grape,  cherry, bar, grape };
	//リール＿_2　　　リプレイ　ベル　ブドウ　チェリー　リプレイ　７　  ブドウ　チェリー　リプレイ　ベル　ブドウ　チェリー　リプレイ　BAR　ブドウ　チェリー　ピエロ　リプレイ　７　ブドウ　チェリー　
	int reel_2[23] = { replay,   bell, grape,  cherry,   replay,   hit, grape,  cherry,   replay,   bell, grape,  cherry,   replay,   bar, grape,  cherry,   clown,  replay,   hit, grape, cherry,replay,   bell };
	//リール＿３　　　ブドウ　ピエロ　ベル　リプレイ　ブドウ　７　  BAR　ベル　リプレイ　ブドウ　ピエロ　ベル　リプレイ　ブドウ　ピエロ　ベル　リプレイ　ブドウ　ピエロ　ベル　リプレイ
	int reel_3[23] = { grape,  clown,  bell, replay,   grape, hit, bar, bell, replay,    grape, clown,  bell, replay,   grape,  clown, bell,  replay,   grape,  clown,  bell, replay, grape,  clown };

	//リールの現在の数
	int reel_1Number = 0;
	int reel_2Number = 0;
	int reel_3Number = 0;

	//止まった役
	int one = reel_1[0];    //リール１ 上の段
	int two = reel_2[0];    //リール２ 上の段
	int three = reel_3[0];    //リール３ 上の段
	int four = reel_1[1];    //リール１ 中の段 
	int five = reel_2[1];    //リール２ 中の段 
	int six = reel_3[1];	  //リール３ 中の段 
	int seven = reel_1[2];    //リール１ 下の段
	int eight = reel_2[2];	  //リール２ 下の段
	int nine = reel_3[2];    //リール３ 下の段


	//リールの動作
	bool stop_1 = true;
	bool stop_2 = true;
	bool stop_3 = true;

	bool control_1 = true;
	bool control_2 = true;
	bool control_3 = true;

	//メダルの枚数
	int medal = 0; //現在獲得しているメダル枚数
	int bonusMedal = 0; //ボーナス中に獲得したメダル枚数
	bool stop = false;
	int one_N = 0; //一の位
	int ten_N = 0; //十の位
	int century_N = 0; //百の位
	int thousand_N = 0; //千の位
	int myriad_N = 0; //万の位
	int negative = 0;//マイナスなら１
	int negative_N = 10;//マイナスなら１
	int medal_N = 0;//表示のため
	int medal_PaN = 0;//表示のため

	//抽選
	int lottery =0;     //抽選（ランダム)
	int result = 0;  //結果
	int bonus_lottery = 0; //ボーナス中そろい方抽選
	int bonus_result = 0;//結果

	//キューブ
	float cubePosition_Y = 2.5f;//Yの座標移動
	float cubePosition_X = -4.0f;
	int cubePosUpDown = 0;//上下移動切り替え
	int cubeRot_Y =125.0f;//Yの回転座標
	int distributeCube = 0; //当選した役

};

