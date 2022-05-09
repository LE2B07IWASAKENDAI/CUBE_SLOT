#include "GameScene.h"
#include "Model.h"
#include "Collision.h"
#include <cassert>
#include <sstream>
#include <iomanip>

using namespace DirectX;
GameScene::GameScene()
{
}

GameScene::~GameScene()
{
	for (int i = 1; i < _countof(spriteBG); i++)
	{
		safe_delete(spriteBG[i]);
	}
	safe_delete(objCube);
	for (int i = 1; i < _countof(spriteReel_11); i++)
	{
		safe_delete(spriteReel_11[i]);
	}
	for (int i = 1; i < _countof(spriteReel_12); i++)
	{
		safe_delete(spriteReel_12[i]);
	}
	for (int i = 1; i < _countof(spriteReel_13); i++)
	{
		safe_delete(spriteReel_13[i]);
	}
	for (int i = 1; i < _countof(spriteReel_21); i++)
	{
		safe_delete(spriteReel_21[i]);
	}
	for (int i = 1; i < _countof(spriteReel_22); i++)
	{
		safe_delete(spriteReel_22[i]);
	}
	for (int i = 1; i < _countof(spriteReel_23); i++)
	{
		safe_delete(spriteReel_23[i]);
	}
	for (int i = 1; i < _countof(spriteReel_31); i++)
	{
		safe_delete(spriteReel_31[i]);
	}
	for (int i = 1; i < _countof(spriteReel_32); i++)
	{
		safe_delete(spriteReel_32[i]);
	}
	for (int i = 1; i < _countof(spriteReel_33); i++)
	{
		safe_delete(spriteReel_33[i]);
	}
	for (int i = 1; i < _countof(one_S); i++)
	{
		safe_delete(one_S[i]);
	}
	for (int i = 1; i < _countof(ten_S); i++)
	{
		safe_delete(ten_S[i]);
	}
	for (int i = 1; i < _countof(century_S); i++)
	{
		safe_delete(century_S[i]);
	}
	for (int i = 1; i < _countof(thousand_S); i++)
	{
		safe_delete(thousand_S[i]);
	}
	for (int i = 1; i < _countof(myriad_S); i++)
	{
		safe_delete(myriad_S[i]);
	}
	safe_delete(chec[0]);
	safe_delete(chec[1]);
	
}

void GameScene::Initialize(DirectXCommon* dxCommon, Input* input, Audio * audio)
{
	// nullptrチェック
	assert(dxCommon);
	assert(input);
	assert(audio);

	this->dxCommon = dxCommon;
	this->input = input;
	this->audio = audio;

	// デバッグテキスト用テクスチャ読み込み
	if (!Sprite::LoadTexture(debugTextTexNumber, L"Resources/debugfont.png")) {
		assert(0);
		return ;
	}
	// デバッグテキスト初期化
	debugText.Initialize(debugTextTexNumber);

	
	// 背景スプライト生成
	Sprite::LoadTexture(1, L"Resources/mainback.png");
	Sprite::LoadTexture(23, L"Resources/title.png");
	Sprite::LoadTexture(24, L"Resources/end.png");
	Sprite::LoadTexture(25, L"Resources/bonusback.png");
	spriteBG[title] = Sprite::Create(23, { 0.0f,0.0f });
	spriteBG[game] = Sprite::Create(1, { 0.0f,0.0f });
	spriteBG[end] = Sprite::Create(24, { 0.0f,0.0f });
	spriteBG[gameBonus] = Sprite::Create(25, { 0.0f,0.0f });

	// 3Dオブジェクト生成
	objCube = Object3d::Create(cubePosition_X, cubePosition_Y, 0.0f);
	
	//前景テクスチャの読み込み
	Sprite::LoadTexture(2, L"Resources/tex1.png");
	Sprite::LoadTexture(3, L"Resources/part/hit.png");
	Sprite::LoadTexture(4, L"Resources/part/bar.png");
	Sprite::LoadTexture(5, L"Resources/part/grape.png");
	Sprite::LoadTexture(6, L"Resources/part/bell.png");
	Sprite::LoadTexture(7, L"Resources/part/rePlaye.png");
	Sprite::LoadTexture(8, L"Resources/part/cherry.png");
	Sprite::LoadTexture(9, L"Resources/part/clown.png");
	Sprite::LoadTexture(10, L"Resources/Number/zero.png");
	Sprite::LoadTexture(11, L"Resources/Number/one.png");
	Sprite::LoadTexture(12, L"Resources/Number/two.png");
	Sprite::LoadTexture(13, L"Resources/Number/three.png");
	Sprite::LoadTexture(14, L"Resources/Number/four.png");
	Sprite::LoadTexture(15, L"Resources/Number/five.png");
	Sprite::LoadTexture(16, L"Resources/Number/six.png");
	Sprite::LoadTexture(17, L"Resources/Number/seven.png");
	Sprite::LoadTexture(18, L"Resources/Number/eight.png");
	Sprite::LoadTexture(19, L"Resources/Number/nine.png");
	Sprite::LoadTexture(20, L"Resources/Number/-.png");
	Sprite::LoadTexture(21, L"Resources/BigBonus.png");
	Sprite::LoadTexture(22, L"Resources/RegBonus.png");

	//イラスト
	//リール
	for (int i = 1; i < 8; i++)
	{
		//リール1
		spriteReel_11[i] = Sprite::Create(i + 2, { 55,380 });
		spriteReel_12[i] = Sprite::Create(i + 2, { 55,474 });
		spriteReel_13[i] = Sprite::Create(i + 2, { 55,568 });
		//リール２
		spriteReel_21[i] = Sprite::Create(i + 2, { 230,380 });
		spriteReel_22[i] = Sprite::Create(i + 2, { 230,474 });
		spriteReel_23[i] = Sprite::Create(i + 2, { 230,568 });
		//リール３
		spriteReel_31[i] = Sprite::Create(i + 2, { 405,380 });
		spriteReel_32[i] = Sprite::Create(i + 2, { 405,474 });
		spriteReel_33[i] = Sprite::Create(i + 2, { 405,568 });
	}

	//数字
	for (int i = 0; i < 11; i++)
	{
		one_S[i] = Sprite::Create(i + 10, { 1200,50 });
		ten_S[i] = Sprite::Create(i + 10, { 1140,50 });
		century_S[i] = Sprite::Create(i + 10, { 1080,50 });
		thousand_S[i] = Sprite::Create(i + 10, { 1020,50 });
		myriad_S[i] = Sprite::Create(i + 10, { 960,50 });
	}

	chec[0] = Sprite::Create(21, { 1000,700 });
	chec[1] = Sprite::Create(22, { 1000,700 });

	modelCube[no] = Model::CreateFromOBJ("Cube");
	modelCube[hit] = Model::CreateFromOBJ("Cube_hit");
	modelCube[bar] = Model::CreateFromOBJ("Cube_bar");
	modelCube[grape] = Model::CreateFromOBJ("Cube_grape");
	modelCube[bell] = Model::CreateFromOBJ("Cube_bell");
	modelCube[replay] = Model::CreateFromOBJ("Cube_rePlaye");
	modelCube[cherry] = Model::CreateFromOBJ("Cube_cherry");
	modelCube[clown] = Model::CreateFromOBJ("Cube_clown");
	modelCube[hit_bar] = Model::CreateFromOBJ("Cube_bnuosBAR");
	modelCube[bonusNow] = Model::CreateFromOBJ("Cube_bnuos");

	objCube->SetModel(modelCube[no]);
	
	objCube->SetScale(XMFLOAT3(2.5f,2.5f,2.5f));


	number = new Number();
	role = new Role();

	
}

void GameScene::Update()
{
	objCube->Update();

	if (seccn == title)
	{
		objCube->SetModel(modelCube[no]);
		cubePosition_X = 0.0f;
		cubeRot_Y = cubeRot_Y + 10;
		if (cubePosition_Y > 3.0f)
		{
			cubePosUpDown = 1;
		}
		else if (cubePosition_Y < 2.0f)
		{
			cubePosUpDown = 0;
		}

		if (cubePosUpDown == 0)
		{
			cubePosition_Y += 0.01f;
		}
		else if (cubePosUpDown == 1)
		{
			cubePosition_Y -= 0.01f;
		}
		//移動座標をセット
		objCube->SetPosition(XMFLOAT3(cubePosition_X, cubePosition_Y, 0.0f));
		//回転した値をセット
		objCube->SetRotation(XMFLOAT3(0, cubeRot_Y, 5));

		if (input->TriggerKey(DIK_SPACE))
		{
			seccn = game;
		}
	}

	if (seccn == game || seccn == gameBonus)
	{
		
		cubePosition_X = -4.0f;

		//3Dオブジェクト
		//回転
		if (stop_1 == false || stop_2 == false || stop_3 == false)
		{
			objCube->SetModel(modelCube[no]);
			cubeRot_Y = cubeRot_Y + 10;
		}
		else
		{
			cubeRot_Y = -150.0f;
		}
		//回転した値をセット
		objCube->SetRotation(XMFLOAT3(0, cubeRot_Y, 5));
		//移動
		if (stop_1 == false || stop_2 == false || stop_3 == false)
		{
			cubePosition_Y = 2.5f;
			cubePosUpDown = 0;
		}
		else
		{
			if (cubePosition_Y > 3.0f)
			{
				cubePosUpDown = 1;
			}
			else if(cubePosition_Y <	2.0f )
			{
				cubePosUpDown = 0;
			}

			if (cubePosUpDown == 0)
			{
				cubePosition_Y += 0.02f;
			}
			else if( cubePosUpDown == 1)
			{
				cubePosition_Y -= 0.02f;
			}
		}
		//移動座標をセット
		objCube->SetPosition(XMFLOAT3(cubePosition_X, cubePosition_Y, 0.0f));

		//枚数表示
		//表示のための移動
		medal_N = medal;
		/*medal_PaN = medal;*/
		//マイナスかどうか判定
		negative = number->decision(medal);


		//位ごとに枚数を分ける
		number->operation(medal);
		//正数にした枚数を取得
		medal_PaN = number->GetPNumber();


		if (bonus == noBonus)
		{
			//リールを回す
			if (input->TriggerKey(DIK_SPACE) && stop_1 == true && stop_2 == true && stop_3 == true && bonus == 0)
			{
				medal = medal - 3; //bet
				if (result == hit_bar || result == hit)
				{
					lottery = lottery;

				}
				else
				{
					
					lottery = rand() % 100 + 1; //抽選
					
				}
				stop_1 = false;
				control_1 = true;
				stop_2 = false;
				control_2 = true;
				stop_3 = false;
				control_3 = true;
				stop = false;
			}


			//抽選結果をresultに入れる
			result = role->Distribute(lottery);
			if (result == hit_bar || result == hit)
			{
				seccn = gameBonus;
			}
			

			//リール１
			if (stop_1 == false)
			{
				//リール停止
				if (input->TriggerKey(DIK_1))
				{
					control_1 = false;
				}
				else
				{
					reel_1Number += 1;
					if (reel_1Number > 20)
					{
						reel_1Number = 0;
					}
				}

				//リールに抽選結果を反映
				if (control_1 == false)
				{
					if (result > 0 && result == !hit_bar)
					{
						if (one == result || four == result || seven == result)
						{
							stop_1 = true;
						}
						else
						{
							reel_1Number += 1;
							if (reel_1Number > 20)
							{
								reel_1Number = 0;
							}
						}
					}
					else if (result == hit_bar)
					{
						if (one == hit || four == hit || seven == hit)
						{
							stop_1 = true;
						}
						else
						{
							reel_1Number += 1;
							if (reel_1Number > 20)
							{
								reel_1Number = 0;
							}
						}
					}
					else
					{
						stop_1 = true;
					}
				}

				one = reel_1[reel_1Number];
				four = reel_1[reel_1Number + 1];
				seven = reel_1[reel_1Number + 2];
			}

			//リール2
			if (stop_2 == false)
			{
				//リール停止
				if (input->TriggerKey(DIK_2))
				{
					control_2 = false;
				}
				else
				{
					reel_2Number += 1;
					if (reel_2Number > 20)
					{
						reel_2Number = 0;
					}


				}

				//リールに抽選結果を反映
				if (control_2 == false)
				{
					if (result > 0 && result == !hit_bar)
					{
						if (two == result || five == result || eight == result)
						{
							stop_2 = true;
						}
						else
						{
							reel_2Number += 1;
							if (reel_2Number > 20)
							{
								reel_2Number = 0;
							}
						}
					}
					else if (result == hit_bar)
					{
						if (two == hit || five == hit || eight == hit)
						{
							stop_2 = true;
						}
						else
						{
							reel_2Number += 1;
							if (reel_2Number > 20)
							{
								reel_2Number = 0;
							}
						}
					}
					else
					{
						stop_2 = true;
					}
				}

				two = reel_2[reel_2Number];
				five = reel_2[reel_2Number + 1];
				eight = reel_2[reel_2Number + 2];
			}

			//リール３
			if (stop_3 == false)
			{
				//リール停止
				if (input->TriggerKey(DIK_3))
				{
					control_3 = false;
				}
				else
				{
					reel_3Number += 1;
					if (reel_3Number > 20)
					{
						reel_3Number = 0;
					}
				}

				//リールに抽選結果を反映
				if (control_3 == false)
				{
					if (result > 0 && result == !cherry && result == !hit_bar)
					{
						if (three == result || six == result || nine == result)
						{
							stop_3 = true;
						}
						else
						{
							reel_3Number += 1;
							if (reel_3Number > 20)
							{
								reel_3Number = 0;
							}
						}
					}
					else if (result == hit_bar)
					{
						if (three == bar || six == bar || nine == bar)
						{
							stop_3 = true;
						}
						else
						{
							reel_3Number += 1;
							if (reel_3Number > 20)
							{
								reel_3Number = 0;
							}
						}
					}
					else
					{
						stop_3 = true;
					}
				}

				three = reel_3[reel_3Number];
				six = reel_3[reel_3Number + 1];
				nine = reel_3[reel_3Number + 2];

			}
		}

		//BOUNS処理
		if (bonus > noBonus)
		{


			//ビックボーナス
			if (bonus == bigBonus)
			{
				for (int i = 0; i < 27; i++)
				{
					if (input->TriggerKey(DIK_SPACE) && stop_1 == true && stop_2 == true && stop_3 == true)
					{
						medal = medal - 1; //bet
						bonus_lottery = rand() % 5 + 1; //抽選
						stop_1 = false;
						control_1 = true;
						stop_2 = false;
						control_2 = true;
						stop_3 = false;
						control_3 = true;
						stop = false;
					}

					bonus_result = bonus_lottery;

					//リール１
					if (stop_1 == false)
					{
						//リール停止
						if (input->TriggerKey(DIK_1))
						{
							control_1 = false;
						}
						else
						{
							reel_1Number += 1;
							if (reel_1Number > 20)
							{
								reel_1Number = 0;
							}
						}

						//リールに抽選結果を反映
						if (control_1 == false)
						{
							if (bonus_result == 1 && one == grape)
							{
								stop_1 = true;
							}
							else if (bonus_result == 2 && one == grape)
							{
								stop_1 = true;
							}
							else if (bonus_result == 3 && four == grape)
							{
								stop_1 = true;
							}
							else if (bonus_result == 4 && seven == grape)
							{
								stop_1 = true;
							}
							else if (bonus_result == 5 && seven == grape)
							{
								stop_1 = true;
							}
							else
							{
								reel_1Number += 1;
								if (reel_1Number > 20)
								{
									reel_1Number = 0;
								}
							}

						}

						one = reel_1[reel_1Number];
						four = reel_1[reel_1Number + 1];
						seven = reel_1[reel_1Number + 2];
					}

					//リール2
					if (stop_2 == false)
					{
						//リール停止
						if (input->TriggerKey(DIK_2))
						{
							control_2 = false;
						}
						else
						{
							reel_2Number += 1;
							if (reel_2Number > 20)
							{
								reel_2Number = 0;
							}


						}

						//リールに抽選結果を反映
						if (control_2 == false)
						{
							if (bonus_result == 1 && two == grape)
							{
								stop_2 = true;
							}
							else if (bonus_result == 2 && five == grape)
							{
								stop_2 = true;
							}
							else if (bonus_result == 3 && five == grape)
							{
								stop_2 = true;
							}
							else if (bonus_result == 4 && five == grape)
							{
								stop_2 = true;
							}
							else if (bonus_result == 5 && eight == grape)
							{
								stop_2 = true;
							}
							else
							{
								reel_2Number += 1;
								if (reel_2Number > 20)
								{
									reel_2Number = 0;
								}
							}
						}

						two = reel_2[reel_2Number];
						five = reel_2[reel_2Number + 1];
						eight = reel_2[reel_2Number + 2];
					}

					//リール３
					if (stop_3 == false)
					{
						//リール停止
						if (input->TriggerKey(DIK_3))
						{
							control_3 = false;
						}
						else
						{
							reel_3Number += 1;
							if (reel_3Number > 20)
							{
								reel_3Number = 0;
							}

						}

						//リールに抽選結果を反映
						if (control_3 == false)
						{
							if (bonus_result == 1 && three == grape)
							{
								stop_3 = true;
							}
							else if (bonus_result == 2 && nine == grape)
							{
								stop_3 = true;
							}
							else if (bonus_result == 3 && six == grape)
							{
								stop_3 = true;
							}
							else if (bonus_result == 4 && three == grape)
							{
								stop_3 = true;
							}
							else if (bonus_result == 5 && nine == grape)
							{
								stop_3 = true;
							}
							else
							{
								reel_3Number += 1;
								if (reel_3Number > 20)
								{
									reel_3Number = 0;
								}
							}
						}

						three = reel_3[reel_3Number];
						six = reel_3[reel_3Number + 1];
						nine = reel_3[reel_3Number + 2];

					}

					//役がそろっているかの判定　&　メダルの払い出し枚数の確認
					if (stop_1 == true && stop_2 == true && stop_3 == true && stop == false)
					{
						role->Reset();
						distribute = role->Confirm(one, two, three, four, five, six, seven, eight, nine);
						if (distribute == grape)
						{
							objCube->SetModel(modelCube[bonusNow]);
							medal += bonusGrape_SN;
							bonusMedal += bonusGrape_SN;
							stop = true;
						}

						

					}
					//ボーナス抜ける
					if (bonusMedal >= 364)
					{
						seccn = game;
						lottery = no;
						bonus = noBonus;
						break;
					}
				}
			}
			//レグボーナス
			if (bonus == regBonus)
			{
				for (int i = 0; i < 20; i++)
				{
					if (input->TriggerKey(DIK_SPACE) && stop_1 == true && stop_2 == true && stop_3 == true)
					{
						medal = medal - 1; //bet
						bonus_lottery = rand() % 5 + 1; //抽選
						stop_1 = false;
						control_1 = true;
						stop_2 = false;
						control_2 = true;
						stop_3 = false;
						control_3 = true;
						stop = false;
					}

					bonus_result = bonus_lottery;

					//リール１
					if (stop_1 == false)
					{
						//リール停止
						if (input->TriggerKey(DIK_1))
						{
							control_1 = false;
						}
						else
						{
							reel_1Number += 1;
							if (reel_1Number > 20)
							{
								reel_1Number = 0;
							}
						}

						//リールに抽選結果を反映
						if (control_1 == false)
						{
							if (bonus_result == 1 && one == grape)
							{
								stop_1 = true;
							}
							else if (bonus_result == 2 && one == grape)
							{
								stop_1 = true;
							}
							else if (bonus_result == 3 && four == grape)
							{
								stop_1 = true;
							}
							else if (bonus_result == 4 && seven == grape)
							{
								stop_1 = true;
							}
							else if (bonus_result == 5 && seven == grape)
							{
								stop_1 = true;
							}
							else
							{
								reel_1Number += 1;
								if (reel_1Number > 20)
								{
									reel_1Number = 0;
								}
							}
						}

						one = reel_1[reel_1Number];
						four = reel_1[reel_1Number + 1];
						seven = reel_1[reel_1Number + 2];
					}

					//リール2
					if (stop_2 == false)
					{
						//リール停止
						if (input->TriggerKey(DIK_2))
						{
							control_2 = false;
						}
						else
						{
							reel_2Number += 1;
							if (reel_2Number > 20)
							{
								reel_2Number = 0;
							}
						}

						//リールに抽選結果を反映
						if (control_2 == false)
						{
							if (bonus_result == 1 && two == grape)
							{
								stop_2 = true;
							}
							else if (bonus_result == 2 && five == grape)
							{
								stop_2 = true;
							}
							else if (bonus_result == 3 && five == grape)
							{
								stop_2 = true;
							}
							else if (bonus_result == 4 && five == grape)
							{
								stop_2 = true;
							}
							else if (bonus_result == 5 && eight == grape)
							{
								stop_2 = true;
							}
							else
							{
								reel_2Number += 1;
								if (reel_2Number > 20)
								{
									reel_2Number = 0;
								}
							}
						}

						two = reel_2[reel_2Number];
						five = reel_2[reel_2Number + 1];
						eight = reel_2[reel_2Number + 2];
					}

					//リール３
					if (stop_3 == false)
					{
						//リール停止
						if (input->TriggerKey(DIK_3))
						{
							control_3 = false;
						}
						else
						{
							reel_3Number += 1;
							if (reel_3Number > 20)
							{
								reel_3Number = 0;
							}
						}

						//リールに抽選結果を反映
						if (control_3 == false)
						{
							if (bonus_result == 1 && three == grape)
							{
								stop_3 = true;
							}
							else if (bonus_result == 2 && nine == grape)
							{
								stop_3 = true;
							}
							else if (bonus_result == 3 && six == grape)
							{
								stop_3 = true;
							}
							else if (bonus_result == 4 && three == grape)
							{
								stop_3 = true;
							}
							else if (bonus_result == 5 && nine == grape)
							{
								stop_3 = true;
							}
							else
							{
								reel_3Number += 1;
								if (reel_3Number > 20)
								{
									reel_3Number = 0;
								}
							}
						}

						three = reel_3[reel_3Number];
						six = reel_3[reel_3Number + 1];
						nine = reel_3[reel_3Number + 2];

					}
					//役がそろっているかの判定　&　メダルの払い出し枚数の確認
					if (stop_1 == true && stop_2 == true && stop_3 == true && stop == false)
					{

						role->Reset();
						distribute = role->Confirm(one, two, three, four, five, six, seven, eight, nine);
						if (distribute == grape)
						{
							objCube->SetModel(modelCube[bonusNow]);
							medal += bonusGrape_SN;
							bonusMedal += bonusGrape_SN;
							stop = true;
						}
						
						//レギュラーボーナス抜ける
						if (bonusMedal >= 266)
						{
							seccn = game;
							lottery = no;
							bonus = noBonus;
							break;
						}
					}
				}
			}
		}
		else
		{
			bonusMedal = 0;
		}

		if (bonus == 0)
		{
			//役がそろっているかの判定　&　メダルの払い出し枚数の確認
			if (stop_1 == true && stop_2 == true && stop_3 == true && stop == false)
			{

				role->Reset();
				distribute = role->Confirm(one, two, three, four, five, six, seven, eight, nine);

				if (distribute == cherry) { medal += cherry_SN; objCube->SetModel(modelCube[cherry]) ; stop = true; }
				if (distribute == bigBonus) { bonus = bigBonus; objCube->SetModel(modelCube[hit]); stop = true; }
				if (distribute == bar) { medal += bar_SN; objCube->SetModel(modelCube[bar]); stop = true; }
				if (distribute == grape) { medal += grape_SN; objCube->SetModel(modelCube[grape]); stop = true; }
				if (distribute == bell) { medal += bell_SN; objCube->SetModel(modelCube[bell]); stop = true; }
				if (distribute == replay) { medal += replay_SN; objCube->SetModel(modelCube[replay]); stop = true; }
				if (distribute == clown) { medal += clown_SN; objCube->SetModel(modelCube[clown]); stop = true; }
				if (distribute == regBonus) { bonus = regBonus; objCube->SetModel(modelCube[hit_bar]); stop = true; }

				//ブレイクポイント置き場

			}
		}

		//シーン切り替え
		if (input->TriggerKey(DIK_E))
		{
			seccn = end;
		}

	}

	

	if (seccn == end)
	{
		objCube->SetModel(modelCube[no]);
		cubePosition_X = 0.0f;
		cubeRot_Y = cubeRot_Y + 10;
		if (cubePosition_Y > 3.0f)
		{
			cubePosUpDown = 1;
		}
		else if (cubePosition_Y < 2.0f)
		{
			cubePosUpDown = 0;
		}

		if (cubePosUpDown == 0)
		{
			cubePosition_Y += 0.01f;
		}
		else if (cubePosUpDown == 1)
		{
			cubePosition_Y -= 0.01f;
		}
		//移動座標をセット
		objCube->SetPosition(XMFLOAT3(cubePosition_X, cubePosition_Y, 0.0f));
		//回転した値をセット
		objCube->SetRotation(XMFLOAT3(0, cubeRot_Y, 5));

		if (input->TriggerKey(DIK_SPACE))
		{
			seccn = title;
		}
	}

}

void GameScene::Draw()
{
	// コマンドリストの取得
	ID3D12GraphicsCommandList* cmdList = dxCommon->GetCommandList();

#pragma region 背景スプライト描画
	// 背景スプライト描画前処理
	Sprite::PreDraw(cmdList);
	// 背景スプライト描画
	spriteBG[seccn]->Draw();

	/// <summary>
	/// ここに背景スプライトの描画処理を追加できる
	/// </summary>

	// スプライト描画後処理
	Sprite::PostDraw();
	// 深度バッファクリア
	dxCommon->ClearDepthBuffer();
#pragma endregion

#pragma region 3Dオブジェクト描画
	// 3Dオブジェクト描画前処理
	Object3d::PreDraw(cmdList);

	
	// 3Dオブクジェクトの描画
	objCube->Draw();
	if (seccn == game)
	{
		
	}
	
	
		
	/// <summary>
	/// ここに3Dオブジェクトの描画処理を追加できる
	/// </summary>

	// 3Dオブジェクト描画後処理
	Object3d::PostDraw();
#pragma endregion

#pragma region 前景スプライト描画
	// 前景スプライト描画前処理
	Sprite::PreDraw(cmdList);

	/// <summary>
	/// ここに前景スプライトの描画処理を追加できる
	/// </summary>
	
	//// 描画
	if (seccn == game || seccn == gameBonus)
	{
		//枚数表示

		if (medal_PaN >= 10000)
		{
			myriad_S[number->GetMyriadsPlace()]->Draw();
		}
		else if (medal_PaN >= 1000 && negative == 1)
		{
			myriad_S[negative_N]->Draw();
		}

		if (medal_PaN >= 1000)
		{
			thousand_S[number->GetThousandsPlace()]->Draw();
		}
		else if (medal_PaN >= 100 && negative == 1)
		{
			thousand_S[negative_N]->Draw();
		}

		if (medal_PaN >= 100)
		{
			century_S[number->GetCenturysPlace()]->Draw();
		}
		else if (medal_PaN >= 10 && negative == 1)
		{
			century_S[negative_N]->Draw();
		}

		if (medal_PaN >= 10)
		{
			ten_S[number->GetTensPlace()]->Draw();
		}
		else if (medal_PaN >= 1 && negative == 1)
		{
			ten_S[negative_N]->Draw();
		}

		one_S[number->GetOnesPlace()]->Draw();


		//リール１
		spriteReel_11[one]->Draw();
		spriteReel_12[four]->Draw();
		spriteReel_13[seven]->Draw();
		//リール２
		spriteReel_21[two]->Draw();
		spriteReel_22[five]->Draw();
		spriteReel_23[eight]->Draw();
		//リール３
		spriteReel_31[three]->Draw();
		spriteReel_32[six]->Draw();
		spriteReel_33[nine]->Draw();

		if (bonus == bigBonus)
		{
			chec[0]->Draw();
		}
		else if (bonus == regBonus)
		{
			chec[1]->Draw();
		}

		
	}
	// デバッグテキストの描画
	debugText.DrawAll(cmdList);

	// スプライト描画後処理
	Sprite::PostDraw();
#pragma endregion
}