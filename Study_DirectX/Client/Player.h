#pragma once
#ifndef _PLAYER_H_
#define _PLAYER_H_

class SingleTexture;

class Player
{
private:
	explicit Player();

public:
	virtual ~Player();

public:
	void Update();
	void LateUpdate();
	void Render();

private:
	void Init();
	void Release();
	void InputKeyboard();

public:
	INFO getInfo() const { return m_tInfo; }

public:
	static Player* Create();

private:
	INFO m_tInfo;
	float m_RotAngle;
	float m_RevAngle;

	D3DXVECTOR3 m_vCenterOrigin;
	D3DXVECTOR3 m_vCenterConvert;
	D3DXVECTOR3 m_vOrigin[4];	// �� P(ó�� ��ġ)
	D3DXVECTOR3 m_vConvert[4];	// �� Q(��ȯ�� ��ġ)

	SingleTexture *m_pSingleTexture;

	bool m_IsInit;
};

#endif