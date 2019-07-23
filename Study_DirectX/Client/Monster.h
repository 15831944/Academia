#pragma once
#ifndef _MONSTER_H_
#define _MONSTER_H_

class SingleTexture;

class Player;

class Monster
{
private:
	explicit Monster();

public:
	virtual ~Monster();

public:
	void Update();
	void LateUpdate();
	void Render();

private:
	void Init();
	void Release();
	void InputKeyboard();

public:
	void setPlayer(Player *pPlayer) { m_pPlayer = pPlayer; }

public:
	static Monster* Create(Player *pPlayer);

private:
	INFO m_tInfo;
	float m_RotAngle;
	float m_RevAngle;

	D3DXVECTOR3 m_vCenterOrigin;
	D3DXVECTOR3 m_vCenterConvert;
	D3DXVECTOR3 m_vOrigin[4];	// 점 P(처음 위치)
	D3DXVECTOR3 m_vConvert[4];	// 점 Q(변환된 위치)

	SingleTexture *m_pSingleTexture;

	Player *m_pPlayer;

	bool m_IsInit;
};

#endif