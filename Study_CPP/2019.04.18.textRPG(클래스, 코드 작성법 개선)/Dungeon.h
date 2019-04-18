#pragma once
#ifndef _DUNGEON_H_
#define _DUNGEON_H_

class Player;
class Monster;

class Dungeon {


public:
	explicit Dungeon(Player *pPlayer); // 차라리 생성자를 통해서...
	~Dungeon();

private:
	Dungeon() {}

public:
	void Init(void);
	bool Progress(void);
	void Release(void);

public:
	void goIntoTheDungeon(void);
	
	BATTLE_STATE attackMonster(bool isMonsterAtt);
	BATTLE_STATE tryRunAway(void);

	void getDungeonReward(void);

	void saveData(void);
	bool loadData(void);

public:

	void setPPlayer(Player *pPlayer); // 흠... 그닥...
									  // 그렇지만, 가능성을 열어둡시다.


private:

	Player *pPlayer; // 굳이 정보를 받아와서...
					// 사용되는 객체만 포인터로 받아와서 하자면서...
					// 생성자를 통해 정의하면 안되나?!
	Monster *pMonster;

	BATTLE_STATE battleLoop;
};

#endif