#include "stdafx.h"
#include "Monster.h"

Monster::Monster(char *name, int level, int maxHp, int attackDamage)
{
	cout << "Monster(매개변수) 생성자" << endl;
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
	cout << "Monster 소멸자" << endl;
	system("pause");
}

void Monster::Init(void) // 멤버 변수에 고정적인 값 초기화
{
	
}

void Monster::showStatus(void)
{
	cout << "레  벨: " << level << endl;
	cout << "클래스: " << className << endl;
	cout << "체  력: " << hp << " / " << maxHp << endl;
	cout << "공격력: " << attackDamage << endl;
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
	this->hp = hp; // 집어 넣는 값은 이후에 예외 처리할 것...
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
