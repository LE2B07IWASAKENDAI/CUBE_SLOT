#pragma once
#include<Windows.h>

class Role
{
public://// �����o�֐�

	/// <summary>
	/// ���̒��I���ʂ̐U�蕪��
	/// </summary>
	int Distribute(int lottery);

	/// <summary>
	/// ���̓��I�m�F
	/// </summary>
	int Confirm(int one, int two, int three, int four, int five, int six, int seven, int eight, int nine);

	/// <summary>
	/// �O��̓��I�����Z�b�g
	/// </summary>
	void Reset() { distribute = 0; }

private:// �����o�ϐ�
	//��
	int hit = 1;  //7
	int bar = 2;    //BAR
	int grape = 3;  //�u�h�E
	int bell = 4;   //�x��
	int replay = 5; //���v���C
	int cherry = 6; //�`�F���[
	int clown = 7;  //�s�G��
	int hit_bar = 8; //�o�PBIG
	int no = 0;//�����Ȃ�

	int bonus = 0;     //�{�[�i�X���������ǂ���
	int noBonus = 0;   //�{�[�i�X����
	int bigBonus = 1;  //BIG�{�[�i�X
	int regBonus = 9;  //REG�{�[�i�X

	int distribute = 0; //���I������

	//���I
	int result = 0;  //����
};

