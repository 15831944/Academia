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
	void RenderLine();
	void DrawLine(const D3DXVECTOR3 &start, const D3DXVECTOR3 &dest);
	void DrawRect(const D3DXVECTOR3 &leftTopPos, const D3DXVECTOR3 &rightBottomPos);
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
	D3DXVECTOR3 m_vOrigin[4];	// 점 P(처음 위치)
	D3DXVECTOR3 m_vConvert[4];	// 점 Q(변환된 위치)

	DeviceManager *m_pDeviceManager;
	SingleTexture *m_pSingleTexture;

	bool m_IsInit;
};

#endif