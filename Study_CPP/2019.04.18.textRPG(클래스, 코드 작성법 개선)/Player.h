#pragma once
#ifndef _PLAYER_H_
#define _PLAYER_H_

class Player {

public:

	explicit Player(char *name, int maxHp, int attackDamage);
	explicit Player();
	~Player();

private:


public:

	void Init(void); // 멤버 변수 고정값 초기화
	void Progress(void);
	void Release(void);

public:

	void showStatus(void);

	void getDamaged(int att);

	void resetHp(void);
	void getReward(int exp, int gold);

public:

	const char* getClassName(void);
	void setClassName(const char *name);
	int getLevel(void);
	void setLevel(int level);
	int getHp(void);
	void setHp(int hp);
	int getMaxHp(void);
	void setMaxHp(int maxHp);
	int getAttackDamage(void);
	void setAttackDamage(int attackDamage);
	int getExp(void);
	void setExp(int exp);
	int getMaxExp(void);
	void setMaxExp(int maxExp);
	int getGold(void);
	void setGold(int gold);

private:

	char className[NAME_LEN];
	int level;
	int hp;
	int maxHp;
	int attackDamage;
	int exp;
	int maxExp;
	int gold;
};

#endif