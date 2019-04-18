#include "stdafx.h"
#include "Monster.h"

Monster::Monster(char *name, int level, int maxHp, int attackDamage)
{
	cout << "Monster(�Ű�����) ������" << endl;
	system("pause");

	strcpy_s(className, NAME_LEN, name);

	this->level = level;
	this->maxHp = maxHp;
	hp = maxHp;

	this->attackDamage = attackDamage;

	exp = ((rand() % 50) + 1) + (50 * (level - 1));
	gold = ((rand() % 30) + 1) + (100 * (level - 1));

}

Monster::~Monster()
{
	cout << "Monster �Ҹ���" << endl;
	system("pause");
}

void Monster::Init(void) // ��� ������ �������� �� �ʱ�ȭ
{
	
}

void Monster::showStatus(void)
{
	cout << "��  ��: " << level << endl;
	cout << "Ŭ����: " << className << endl;
	cout << "ü  ��: " << hp << " / " << maxHp << endl;
	cout << "���ݷ�: " << attackDamage << endl;
	cout << "###############################" << endl;
}

void Monster::getDamaged(int att)
{
	hp -= att;
}

int Monster::getHp(void)
{
	return hp;
}

void Monster::setHp(int hp)
{
	this->hp = hp; // ���� �ִ� ���� ���Ŀ� ���� ó���� ��...
}

int Monster::getAttackDamage(void)
{
	return attackDamage;
}

void Monster::setAttackDamage(int attackDamage)
{
	this->attackDamage = attackDamage;
}

int Monster::getExp(void)
{
	return exp;
}

int Monster::getGold(void)
{
	return gold;
}
