#pragma once
#ifndef _MONSTER_H_
#define _MONSTER_H_

class Monster {

public:
	explicit Monster(char *name, int level, int maxHp, int attackDamage);
	~Monster();

private:
	Monster() {}


public:
	void Init(void);
	void Progress(void);
	void Release(void);

public:
	void showStatus(void);

	void getDamaged(int att);

public:

	int getHp(void);
	void setHp(int hp);

	int getAttackDamage(void);
	void setAttackDamage(int attackDamage);

private:
	char className[NAME_LEN];
	int level;
	int hp;
	int maxHp;
	int attackDamage;
	int exp;
	int gold;
};

#endif