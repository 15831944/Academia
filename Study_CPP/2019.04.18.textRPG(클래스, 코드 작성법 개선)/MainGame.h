#pragma once
#ifndef _MAIN_GAME_H_
#define _MAIN_GAME_H_

class Player;
class Dungeon;

class MainGame {

public:

	MainGame();
	~MainGame();

public:

	bool Init(void);
	void Progress(void);
	void Release(void);

public:

	bool showTitleMenu(void);

	Player* selectClass(void);

	void saveData(void);
	bool loadData(void);

private:

	Player *pPlayer;
	Dungeon *pDungeon;

};

#endif