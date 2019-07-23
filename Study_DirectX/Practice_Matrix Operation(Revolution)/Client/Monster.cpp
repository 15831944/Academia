#include "stdafx.h"

#include "SingleTexture.h"

#include "Player.h"

#include "Monster.h"


Monster::Monster()
	: m_pSingleTexture(nullptr),
	m_IsInit(false),
	m_IsMovingAlongDir(false)
{
}


Monster::~Monster()
{
	Release();
}

void Monster::Update()
{
	InputKeyboard();

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

	INFO tParentInfo = m_pPlayer->getInfo();
	D3DXMATRIX matParent = tParentInfo.matRotZ * tParentInfo.matTrans * tParentInfo.matRevZ;

	// Scaling을 하지 않은 World Matrix를 넘겨줘야 합니다 !!!!
	m_tInfo.matWorld = m_tInfo.matScale * m_tInfo.matRotZ * m_tInfo.matTrans * m_tInfo.matRevZ * matParent;

	for (int i = 0; i < 4; ++i)
	{
		D3DXVec3TransformCoord(&(m_vConvert[i]), &(m_vOrigin[i]), &(m_tInfo.matWorld));
	}
	D3DXVec3TransformCoord(&m_vCenterConvert, &m_vCenterOrigin, &(m_tInfo.matWorld));

	// 방향 벡터는 Revolution 값을 먹이면 안되네?!
	matParent = tParentInfo.matRotZ * tParentInfo.matTrans;
	m_tInfo.matWorld = m_tInfo.matScale * m_tInfo.matRotZ * m_tInfo.matTrans * matParent;
	D3DXVec3TransformNormal(&(m_tInfo.vDir), &(m_tInfo.vDirOrigin), &(m_tInfo.matWorld));
	D3DXVec3Normalize(&(m_tInfo.vDir), &(m_tInfo.vDir));
}

void Monster::LateUpdate()
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

void Monster::Render()
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

	INFO tParentInfo = m_pPlayer->getInfo();
	D3DXMATRIX matParent = tParentInfo.matRotZ * tParentInfo.matTrans * tParentInfo.matRevZ;

	// Scaling을 하지 않은 World Matrix를 넘겨줘야 합니다 !!!!
	m_tInfo.matWorld = m_tInfo.matScale * m_tInfo.matRotZ * m_tInfo.matTrans * m_tInfo.matRevZ * matParent;
	//m_tInfo.matWorld = m_tInfo.matScale * m_tInfo.matRotZ * m_tInfo.matTrans * m_tInfo.matRevZ * tParentInfo.matWorld;

	const TEXTURE_INFO *pTextureInfo = m_pSingleTexture->getTextureInfo();
	NULL_CHECK(pTextureInfo);

	float centerX = pTextureInfo->tImageInfo.Width * 0.5f;
	float centerY = pTextureInfo->tImageInfo.Height * 0.5f;

	DeviceManager::getInstance()->getSprite()->SetTransform(&(m_tInfo.matWorld));
	DeviceManager::getInstance()->getSprite()->Draw(
		pTextureInfo->pTexture,
		nullptr,
		&D3DXVECTOR3(centerX, centerY, 0.0f),
		nullptr,
		D3DCOLOR_ARGB(255, 255, 255, 255)
	);
}

void Monster::Init()
{
	m_tInfo.vPos = {
		100.0f,
		0.0f,
		0.0f
	};
	m_tInfo.vDirOrigin = { 0.0f, -1.0f, 0.0f };	// vDirOrigin - 기준 방향 벡터
												// vDir - 변환된 방향 벡터
	m_tInfo.vSize = { 1.0f, 1.0f, 0.0f }; // 이제 진짜 의미의 배율 !!!!

	m_RotAngle = 0.0f; // Degree Unit(Measure)
	m_RevAngle = 0.0f;

	// 정점(Vertex) 초기 배치
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
		m_pSingleTexture->LoadTexture(L"../Texture/Monster.png");
		m_IsInit = true;
	}

	m_IsMovingAlongDir = false;
}

void Monster::Release()
{
	SafeDelete(m_pSingleTexture);
}

void Monster::InputKeyboard()
{
	if (GetAsyncKeyState('1') & 0x8000)
	{
		cout << "Monster" << endl;
		cout << "화살표 - Pos" << endl;
		cout << "YU - Rotation" << endl;
		cout << "HJ - Revolution" << endl;
		cout << "BN - Scaling" << endl;
	}

	if (GetAsyncKeyState('2') & 0x8000)
	{
		Init();
	}

	if (GetAsyncKeyState('3') & 0x8000)
	{
		m_IsMovingAlongDir = true;
	}
	if (GetAsyncKeyState('4') & 0x8000)
	{
		m_IsMovingAlongDir = false;
	}

	if (GetAsyncKeyState(VK_LBUTTON) & 0x8000)
	{
		cout << "M-Size : " << m_tInfo.vSize.x << " / " << m_tInfo.vSize.y << endl;
		cout << "M-Pos: " << m_tInfo.vPos.x << " / " << m_tInfo.vPos.y << endl;
		cout << "M-Rot : " << m_RotAngle << endl;
		cout << "M-Rev : " << m_RevAngle << endl;
	}

	if (GetAsyncKeyState(VK_LEFT) & 0x8000)
	{
		m_tInfo.vPos.x += (-10.0f);
		cout << "M-Pos: " << m_tInfo.vPos.x << " / " << m_tInfo.vPos.y << endl;
	}

	if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
	{
		m_tInfo.vPos.x += 10.0f;
		cout << "M-Pos: " << m_tInfo.vPos.x << " / " << m_tInfo.vPos.y << endl;
	}

	if (GetAsyncKeyState(VK_UP) & 0x8000)
	{
		if (m_IsMovingAlongDir)
		{
			m_tInfo.vPos += m_tInfo.vDir * 1.0f;
			cout << "M-Pos: " << m_tInfo.vPos.x << " / " << m_tInfo.vPos.y << endl;
		}
		else
		{
			m_tInfo.vPos.y += (-10.0f);
			cout << "M-Pos: " << m_tInfo.vPos.x << " / " << m_tInfo.vPos.y << endl;
		}
	}
	if (GetAsyncKeyState(VK_DOWN) & 0x8000)
	{
		if (m_IsMovingAlongDir)
		{
			m_tInfo.vPos += (-m_tInfo.vDir) * 1.0f;
			cout << "M-Pos: " << m_tInfo.vPos.x << " / " << m_tInfo.vPos.y << endl;
		}
		else
		{
			m_tInfo.vPos.y += 10.0f;
			cout << "M-Pos: " << m_tInfo.vPos.x << " / " << m_tInfo.vPos.y << endl;
		}
	}

	if (GetAsyncKeyState('Y') & 0x8000)
	{
		m_RotAngle += 1.0f;
		cout << "M-Rot : " << m_RotAngle << endl;
	}
	if (GetAsyncKeyState('U') & 0x8000)
	{
		m_RotAngle += (-1.0f);
		cout << "M-Rot : " << m_RotAngle << endl;
	}

	if (GetAsyncKeyState('H') & 0x8000)
	{
		m_RevAngle += 1.0f;
		cout << "M-Rev : " << m_RevAngle << endl;
	}
	if (GetAsyncKeyState('J') & 0x8000)
	{
		m_RevAngle += (-1.0f);
		cout << "M-Rev : " << m_RevAngle << endl;
	}

	if (GetAsyncKeyState('N') & 0x8000)
	{
		m_tInfo.vSize = { 1.0f, 1.0f, 0.0f };
		cout << "M-Size : " << m_tInfo.vSize.x << " / " << m_tInfo.vSize.y << endl;
	}
	if (GetAsyncKeyState('M') & 0x8000)
	{
		m_tInfo.vSize = { 2.0f, 2.0f, 0.0f };
		cout << "M-Size : " << m_tInfo.vSize.x << " / " << m_tInfo.vSize.y << endl;
	}

	if (GetAsyncKeyState('Z') & 0x8000)
	{
		cout << "M-Cen: " << m_vCenterConvert.x << " / " << m_vCenterConvert.y << endl;
		cout << "M-Dir: " << m_tInfo.vDir.x << " / " << m_tInfo.vDir.y << endl;
		cout << "M-Con[0]: " << m_vConvert[0].x << " / " << m_vConvert[0].y << endl;
		cout << "M-Con[1]: " << m_vConvert[1].x << " / " << m_vConvert[1].y << endl;
		cout << "M-Con[2]: " << m_vConvert[2].x << " / " << m_vConvert[2].y << endl;
		cout << "M-Con[3]: " << m_vConvert[3].x << " / " << m_vConvert[3].y << endl;
	}
}

Monster* Monster::Create(Player *pPlayer)
{
	Monster *pInstance = new Monster; // Encapsulation (Singleton 패턴이 아님.)
	if (pInstance)
	{
		pInstance->Init();
	}

	pInstance->setPlayer(pPlayer);

	return pInstance;
}
