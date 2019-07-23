#include "stdafx.h"

#include "SingleTexture.h"

#include "Mouse.h"

#include "Player.h"


Player::Player()
	: m_pDeviceManager(DeviceManager::getInstance()),
	m_pSingleTexture(nullptr),
	m_IsInit(false)
{
}


Player::~Player()
{
	Release();
}

void Player::Update()
{
	InputKeyboard();

	// ####################################################################################################################
	// 2019.07.19 D3DXMATRIX

	// ũ�� ���
	D3DXMatrixScaling(&(m_tInfo.matScale), m_tInfo.vSize.x, m_tInfo.vSize.y, 0.0f); // D2D�ϱ� Z ������ 0.0f !!!!

	// ȸ�� ���(Rotation, ����)
	D3DXMatrixRotationZ(&(m_tInfo.matRotZ), D3DXToRadian(-(m_RotAngle))); // "Negative ��ȣ" ?!?!

	// �̵� ���
	D3DXMatrixTranslation(&(m_tInfo.matTrans), m_tInfo.vPos.x, m_tInfo.vPos.y, 0.0f); // D2D�ϱ� Z ������ 0.0f !!!!

	// ���� ��� = Scaling * Rotation * Translation * Revolution * Parent
	// (��ȯ��Ģ_"Commutative Law"�� �������� �ʱ� ������, ������ ���Ѿ� !!!!)
	m_tInfo.matWorld = m_tInfo.matScale * m_tInfo.matRotZ * m_tInfo.matTrans;

	for (int i = 0; i < 4; ++i)
	{
		// ���Ϳ� ��� ���� ���� ���� - ������ "w" ������ ���� "1"�̱� ������, ����� "��ġ ����"�Դϴ�.
		D3DXVec3TransformCoord(&(m_vConvert[i]), &(m_vOrigin[i]), &(m_tInfo.matWorld));
	}
	D3DXVec3TransformCoord(&m_vCenterConvert, &m_vCenterOrigin, &(m_tInfo.matWorld));

	// ���Ϳ� ��� ���� ���� ���� - ������ "w" ������ ���� "0"�̱� ������, ����� "���� ����"�Դϴ�.
	D3DXVec3TransformNormal(&(m_tInfo.vDir), &(m_tInfo.vDirOrigin), &(m_tInfo.matWorld));

	// ���� ������ ����ȭ !!!!
	D3DXVec3Normalize(&(m_tInfo.vDir), &(m_tInfo.vDir));
}

void Player::LateUpdate()
{
	if (m_RotAngle <= -360.0f || m_RotAngle >= 360.0f)
	{
		m_RotAngle = 0.0f;
	}

	if (m_RevAngle <= -360.0f || m_RevAngle >= 360.0f)
	{
		m_RevAngle = 0.0f;
	}
}

void Player::Render()
{
	D3DXMatrixScaling(&(m_tInfo.matScale),
		m_tInfo.vSize.x,
		m_tInfo.vSize.y,
		m_tInfo.vSize.z
	);
	D3DXMatrixRotationZ(&(m_tInfo.matRotZ), D3DXToRadian(-(m_RotAngle)));
	D3DXMatrixTranslation(&(m_tInfo.matTrans),
		m_tInfo.vPos.x,
		m_tInfo.vPos.y,
		m_tInfo.vPos.z
	);
	D3DXMatrixRotationZ(&(m_tInfo.matRevZ), D3DXToRadian(-(m_RevAngle)));

	m_tInfo.matWorld = m_tInfo.matScale * m_tInfo.matRotZ * m_tInfo.matTrans * m_tInfo.matRevZ;

	const TEXTURE_INFO *pTextureInfo = m_pSingleTexture->getTextureInfo();
	NULL_CHECK(pTextureInfo);

	float centerX = pTextureInfo->tImageInfo.Width * 0.5f;
	float centerY = pTextureInfo->tImageInfo.Height * 0.5f;

	m_pDeviceManager->getSprite()->SetTransform(&(m_tInfo.matWorld));
	m_pDeviceManager->getSprite()->Draw(
		pTextureInfo->pTexture,
		nullptr,
		&D3DXVECTOR3(centerX, centerY, 0.0f),
		nullptr,
		D3DCOLOR_ARGB(255, 255, 255, 255)
	);


	//RenderLine();
	DrawLine(D3DXVECTOR3(400.0f, 300.0f, 0.0f), D3DXVECTOR3(700.0f, 300.0f, 0.0f));
	DrawRect(
		m_vOrigin[0],
		m_vOrigin[2]
		//D3DXVECTOR3(- 50.0f, - 50.0f, 0.0f),
		//D3DXVECTOR3(50.0f, 50.0f, 0.0f)
	);
}

void Player::Init()
{
	m_tInfo.vPos = {
		WINSIZE_X / 2.0f,
		WINSIZE_Y / 2.0f,
		0.0f
	};
	m_tInfo.vDirOrigin = { 0.0f, -1.0f, 0.0f };	// vDirOrigin - ���� ���� ����
												// vDir - ��ȯ�� ���� ����
	m_tInfo.vSize = { 1.0f, 1.0f, 0.0f }; // ���� ��¥ �ǹ��� ���� !!!!

	m_RotAngle = 0.0f; // Degree Unit(Measure)
	m_RevAngle = 0.0f;

	// ����(Vertex) �ʱ� ��ġ
	// 0 1
	// 3 2

	m_vCenterOrigin = { 0.0f, 0.0f, 0.0f };
	m_vOrigin[0] = { -50.0f, -50.0f, 0.0f };
	m_vOrigin[1] = { 50.0f, -50.0f, 0.0f };
	m_vOrigin[2] = { 50.0f,  50.0f, 0.0f };
	m_vOrigin[3] = { -50.0f,  50.0f, 0.0f };

	if (m_IsInit == false)
	{
		m_pSingleTexture = new SingleTexture;
		m_pSingleTexture->LoadTexture(L"../Texture/Player.png");
		m_IsInit = true;
	}
}

void Player::Release()
{
	SafeDelete(m_pSingleTexture);
}

void Player::InputKeyboard()
{
	if (GetAsyncKeyState('1') & 0x8000)
	{
		cout << "######################################################" << endl;
		cout << "Player" << endl;
		cout << "ASDW - Pos" << endl;
		cout << "RT - Rotation" << endl;
		cout << "FG - Revolution" << endl;
		cout << "VB - Scaling" << endl;
	}

	if (GetAsyncKeyState('2') & 0x8000)
	{
		Init();
	}


	if (GetAsyncKeyState(VK_LBUTTON) & 0x8000)
	{
		cout << "#########################################################" << endl;
		cout << "Size : " << m_tInfo.vSize.x << " / " << m_tInfo.vSize.y << endl;
		cout << "Pos: " << m_tInfo.vPos.x << " / " << m_tInfo.vPos.y << endl;
		cout << "Rot : " << m_RotAngle << endl;
		cout << "Rev : " << m_RevAngle << endl;
	}

	if (GetAsyncKeyState('A') & 0x8000)
	{
		cout << "Pos: " << m_tInfo.vPos.x << " / " << m_tInfo.vPos.y << endl;
		m_tInfo.vPos.x += (-10.0f);
	}

	if (GetAsyncKeyState('D') & 0x8000)
	{
		m_tInfo.vPos.x += 10.0f;
		cout << "Pos: " << m_tInfo.vPos.x << " / " << m_tInfo.vPos.y << endl;
	}

	if (GetAsyncKeyState('W') & 0x8000)
	{
		m_tInfo.vPos.y += (-10.0f);
		cout << "Pos: " << m_tInfo.vPos.x << " / " << m_tInfo.vPos.y << endl;
	}
	if (GetAsyncKeyState('S') & 0x8000)
	{
		m_tInfo.vPos.y += 10.0f;
		cout << "Pos: " << m_tInfo.vPos.x << " / " << m_tInfo.vPos.y << endl;
	}

	if (GetAsyncKeyState('R') & 0x8000)
	{
		m_RotAngle += 1.0f;
		cout << "Rot : " << m_RotAngle << endl;
	}
	if (GetAsyncKeyState('T') & 0x8000)
	{
		m_RotAngle += (-1.0f);
		cout << "Rot : " << m_RotAngle << endl;
	}

	if (GetAsyncKeyState('F') & 0x8000)
	{
		m_RevAngle += 1.0f;
		cout << "Rev : " << m_RevAngle << endl;
	}
	if (GetAsyncKeyState('G') & 0x8000)
	{
		m_RevAngle += (-1.0f);
		cout << "Rev : " << m_RevAngle << endl;
	}

	if (GetAsyncKeyState('V') & 0x8000)
	{
		m_tInfo.vSize = { 1.0f, 1.0f, 0.0f };
		cout << "Size : " << m_tInfo.vSize.x << " / " << m_tInfo.vSize.y << endl;
	}
	if (GetAsyncKeyState('B') & 0x8000)
	{
		m_tInfo.vSize = { 2.0f, 2.0f, 0.0f };
		cout << "Size : " << m_tInfo.vSize.x << " / " << m_tInfo.vSize.y << endl;
	}

	if (GetAsyncKeyState('Z') & 0x8000)
	{
		cout << "####################################################################" << endl;
		cout << "Cen: " << m_vCenterConvert.x << " / " << m_vCenterConvert.y << endl;
		cout << "Dir: " << m_tInfo.vDir.x << " / " << m_tInfo.vDir.y << endl;
		cout << "Con[0]: " << m_vConvert[0].x << " / " << m_vConvert[0].y << endl;
		cout << "Con[1]: " << m_vConvert[1].x << " / " << m_vConvert[1].y << endl;
		cout << "Con[2]: " << m_vConvert[2].x << " / " << m_vConvert[2].y << endl;
		cout << "Con[3]: " << m_vConvert[3].x << " / " << m_vConvert[3].y << endl;
	}
}

void Player::RenderLine()
{
#ifdef _DEBUG
#endif

	m_pDeviceManager->getSprite()->End();

	D3DXVECTOR2 vPoint[5] =
	{
		{ -50.0f, -50.0f },
		{ 50.0f, -50.0f },
		{ 50.0f, 50.0f },
		{  -50.0f, 50.0f },
		{ -50.0f, -50.0f }
	};

	D3DXVECTOR3 vTempPoint[5] = {};

	// m_vOrigin
	D3DXVECTOR3 vTempPoint2[5] = {
		{ vPoint[0].x, vPoint[0].y, 0.0f },
		{ vPoint[1].x, vPoint[1].y, 0.0f },
		{ vPoint[2].x, vPoint[2].y, 0.0f },
		{ vPoint[3].x, vPoint[3].y, 0.0f },
		{ vPoint[0].x, vPoint[0].y, 0.0f }
	};

	// m_vConvert
	for (int i = 0; i < 5; ++i)
	{
		D3DXVec3TransformCoord(&vTempPoint[i], &vTempPoint2[i], &m_tInfo.matWorld);
	}

	for (int i = 0; i < 5; ++i)
	{
		vPoint[i].x = vTempPoint[i].x;
		vPoint[i].y = vTempPoint[i].y;
	}

	m_pDeviceManager->getLine()->SetWidth(5.0f);
	m_pDeviceManager->getLine()->Draw(vPoint, 5, D3DCOLOR_ARGB(255, 0, 255, 0));

	m_pDeviceManager->getSprite()->Begin(D3DXSPRITE_ALPHABLEND);
}

void Player::DrawLine(const D3DXVECTOR3 &start, const D3DXVECTOR3 &dest)
{
	m_pDeviceManager->getSprite()->End();

	D3DXVECTOR2 vPoint[2] =
	{
		{ start.x, start.y },
		{ dest.x, dest.y },
	};

	m_pDeviceManager->getLine()->SetWidth(5.0f);
	m_pDeviceManager->getLine()->Draw(vPoint, 2, D3DCOLOR_ARGB(255, 0, 255, 0));

	m_pDeviceManager->getSprite()->Begin(D3DXSPRITE_ALPHABLEND);
}

void Player::DrawRect(const D3DXVECTOR3 &leftTopPos, const D3DXVECTOR3 &rightBottomPos)
{
	m_pDeviceManager->getSprite()->End();

	D3DXVECTOR2 vPoint[5] =
	{
		{ leftTopPos.x, leftTopPos.y},
		{ rightBottomPos.x, leftTopPos.y},
		{ rightBottomPos.x, rightBottomPos.y},
		{ leftTopPos.x, rightBottomPos.y},
		{ leftTopPos.x, leftTopPos.y}
	};

	D3DXVECTOR3 vTempPoint[5] = {};
	D3DXVECTOR3 vTempPoint2[5] = {
		{ vPoint[0].x, vPoint[0].y, 0.0f },
		{ vPoint[1].x, vPoint[1].y, 0.0f },
		{ vPoint[2].x, vPoint[2].y, 0.0f },
		{ vPoint[3].x, vPoint[3].y, 0.0f },
		{ vPoint[0].x, vPoint[0].y, 0.0f }
	};

	for (int i = 0; i < 5; ++i)
	{
		D3DXVec3TransformCoord(&vTempPoint[i], &vTempPoint2[i], &m_tInfo.matWorld);
	}

	for (int i = 0; i < 5; ++i)
	{
		vPoint[i].x = vTempPoint[i].x;
		vPoint[i].y = vTempPoint[i].y;
	}

	m_pDeviceManager->getLine()->SetWidth(5.0f);
	m_pDeviceManager->getLine()->Draw(vPoint, 5, D3DCOLOR_ARGB(255, 0, 255, 0));

	m_pDeviceManager->getSprite()->Begin(D3DXSPRITE_ALPHABLEND);
}

Player * Player::Create()
{
	Player *pInstance = new Player; // Encapsulation (Singleton ������ �ƴ�.)
	if (pInstance)
	{
		pInstance->Init();
	}

	return pInstance;
}
