#pragma once
#ifndef _MAIN_GAME_H_
#define _MAIN_GAME_H_

class Player;
class Monster;

class MainGame
{
public:
	MainGame();
	~MainGame();

public:
	void Init();
	void Update();
	void LateUpdate();
	void Render();

private:
	void Release();

private:
	DeviceManager	*m_pDeviceManager;

	Player	*m_pPlayer;
	Monster	*m_pMonster;
};

#endif