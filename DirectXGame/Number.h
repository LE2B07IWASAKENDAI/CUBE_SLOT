#pragma once
#include<Windows.h>

class Number
{

public://// �����o�֐�

	///<summary>
	///�}�C�i�X���ǂ����̔��f
	/// </summary>
	int decision(int medal);

	///<summary>
	///�ʂ��Ƃ̖����v�Z
	///</summary>
	void operation(int medal);

	///<summary>
	///���_�������������̓n��
	/// </summary>
	/// <returns></returns>
	int GetPNumber() { return medal_NN; }

	///<summary>
	///��̈ʂ�n��
	/// </summary>
	/// <returns></returns>
	int GetOnesPlace() { return one; }

	/// <summary>
	/// �\�̈ʂ�n��
	/// </summary>
	/// <returns></returns>
	int GetTensPlace() { return ten; }

	/// <summary>
	/// �S�̈ʂ�n��
	/// </summary>
	/// <returns></returns>
	int GetCenturysPlace() { return century; }

	/// <summary>
	/// ��̈ʂ�n��
	/// </summary>
	/// <returns></returns>
	int GetThousandsPlace() { return thousand; }

	/// <summary>
	/// ���̈ʂ�n��
	/// </summary>
	/// <returns></returns>
	int GetMyriadsPlace() { return myriad; }

private:// �����o�ϐ�
	int one = 0; //��̈�
	int ten = 0; //�\�̈�
	int century = 0; //�S�̈�
	int thousand = 0; //��̈�
	int myriad = 0; //���̈�
	int negative = 0;//�}�C�i�X�Ȃ�P
	int negative_N = 10;//�}�C�i�X�Ȃ�P
	int medal = 0;//�\���̂���
	int medal_NN = 0;//�\���̂���

};

