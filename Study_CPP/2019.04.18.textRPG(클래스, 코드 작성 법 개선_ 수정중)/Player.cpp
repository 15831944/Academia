#include "stdafx.h"
#include "Player.h"

Player::Player(char * name, int maxHp, int attackDamage)
{
	cout << "Player ������(�Ű�����)" << endl;
	system("pause");
	Init();

	strcpy_s(className, NAME_LEN, name);

	this->maxHp = maxHp;
	hp = maxHp;

	this->attackDamage = attackDamage;
}

Player::Player()
{
	cout << "Player ������" << endl;
}

Player::~Player()
{
	cout << "Player �Ҹ���" << endl;
	system("pause");
}

void Player::Init(void)
{
	level = 1;
	exp = 0;
	maxExp = 100;
	gold = 0;
}

void Player::Progress(void)
{
}

void Player::Release(void)
{
}

void Player::showStatus(void)
{
	cout << "��  ��: " << level << endl;
	cout << "Ŭ����: " << className << endl;
	cout << "ü  ��: " << hp << " / " << maxHp << endl;
	cout << "���ݷ�: " << attackDamage << endl;
	cout << "����ġ: " << exp << " / " << maxExp << endl;
	cout << "��  ��: " << gold << endl;
	cout << "###############################" << endl;
}

void Player::getDamaged(int att)
{
	hp -= att;
}

void Player::resetHp(void)
{
	hp = maxHp;
}

int Player::getAttackDamage(void)
{
	return attackDamage;
}

int Player::getExp(void)
{
	return exp;
}

void Player::setExp(int exp)
{
	this->exp = exp;
}

int Player::getGold(void)
{
	return gold;
}

void Player::setGold(int gold)
{
	this->gold = gold;
}

int Player::getHp(void)
{
	return hp;
}

void Player::setHp(int hp)
{
	this->hp = hp;
}
