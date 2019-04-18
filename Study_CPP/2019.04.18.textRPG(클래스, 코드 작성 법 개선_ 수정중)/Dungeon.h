#pragma once
#ifndef _DUNGEON_H_
#define _DUNGEON_H_

class Player;
class Monster;

class Dungeon {


public:
	explicit Dungeon(Player *pPlayer); // ���� �����ڸ� ���ؼ�...
	~Dungeon();

private:
	Dungeon() {}

public:
	void Init(void);
	void Progress(void);
	void Release(void);

public:
	void goIntoTheDungeon(void);
	
	BATTLE_STATE attackMonster(bool isMonsterAtt);
	BATTLE_STATE tryRunAway(void);

	void getDungeonReward(void);



public:

	void setPPlayer(Player *pPlayer); // ��... �״�...
									  // �׷�����, ���ɼ��� ����ӽô�.


private:

	Player *pPlayer; // ���� ������ �޾ƿͼ�...
					// ���Ǵ� ��ü�� �����ͷ� �޾ƿͼ� ���ڸ鼭...
					// �����ڸ� ���� �����ϸ� �ȵǳ�?!
	Monster *pMonster;

	BATTLE_STATE battleLoop;
};

#endif