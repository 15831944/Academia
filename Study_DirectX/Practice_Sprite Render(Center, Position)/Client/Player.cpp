#include "stdafx.h"

#include "SingleTexture.h"

#include "Player.h"


Player::Player()
	: m_pSingleTexture(nullptr),
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

	// 크기 행렬
	D3DXMatrixScaling(&(m_tInfo.matScale), m_tInfo.vSize.x, m_tInfo.vSize.y, 0.0f); // D2D니까 Z 성분은 0.0f !!!!

	// 회전 행렬(Rotation, 자전)
	D3DXMatrixRotationZ(&(m_tInfo.matRotZ), D3DXToRadian(-(m_RotAngle))); // "Negative 부호" ?!?!

	// 이동 행렬
	D3DXMatrixTranslation(&(m_tInfo.matTrans), m_tInfo.vPos.x, m_tInfo.vPos.y, 0.0f); // D2D니까 Z 성분은 0.0f !!!!

	// 월드 행렬 = Scaling * Rotation * Translation * Revolution * Parent
	// (교환법칙_"Commutative Law"이 성립하지 않기 때문에, 순서를 지켜야 !!!!)
	m_tInfo.matWorld = m_tInfo.matScale * m_tInfo.matRotZ * m_tInfo.matTrans;

	for (int i = 0; i < 4; ++i)
	{
		// 벡터와 행렬 간에 곱셈 연산 - 벡터의 "w" 성분의 값이 "1"이기 때문에, 결과는 "위치 벡터"입니다.
		D3DXVec3TransformCoord(&(m_vConvert[i]), &(m_vOrigin[i]), &(m_tInfo.matWorld));
	}
	D3DXVec3TransformCoord(&m_vCenterConvert, &m_vCenterOrigin, &(m_tInfo.matWorld));

	// 벡터와 행렬 간에 곱셈 연산 - 벡터의 "w" 성분의 값이 "0"이기 때문에, 결과는 "방향 벡터"입니다.
	D3DXVec3TransformNormal(&(m_tInfo.vDir), &(m_tInfo.vDirOrigin), &(m_tInfo.matWorld));

	// 방향 벡터의 정규화 !!!!
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

	int imageWidth = pTextureInfo->tImageInfo.Width;
	int imageHeight = pTextureInfo->tImageInfo.Height;

	// 원본 이미지로부터 계산한 중심.
	float centerX = pTextureInfo->tImageInfo.Width * 0.5f;
	float centerY = pTextureInfo->tImageInfo.Height * 0.5f;

	RECT rcRender = { imageWidth / 2, 0, imageWidth, imageHeight };

	DeviceManager::getInstance()->getSprite()->SetTransform(&(m_tInfo.matWorld));
	DeviceManager::getInstance()->getSprite()->Draw(
		pTextureInfo->pTexture,
		//nullptr,
		&rcRender,
		nullptr,
		//&D3DXVECTOR3(centerY, centerY, 0.0f),
		//&D3DXVECTOR3(50, 50, 0.0f),
		//nullptr,
		&D3DXVECTOR3(-100.0f, -200.0f, 0.0f),
		D3DCOLOR_ARGB(255, 255, 255, 255)
	);

	// ###########################################################################################################
	// 매개변수의 의미
	// SrcRect	: 이미지의 어느 부분부터 보여줄 것인지.
	// Center	: SrcRect의 정해진 부분에서 Texture 이미지가 그려지는 중심(+ 회전 중심) (NULL - 이미지의 (0, 0) 위치)
	// Position	: 어느정도 Offset을 줄 것인지
	// ###########################################################################################################
	// ex. 400X400 큐브 이미지.
	// X 축 반절 크기로 보여주고 - RECT rcRender = { imageWidth/2, 0, imageWidth, imageHeight };
	// Center를 원본 이미지 크기의 중앙으로 잡고 - &D3DXVECTOR3(centerX, centerY, 0.0f),
	// Position을 X 축 방향으로 100.0f 이동시켰을 때...- &D3DXVECTOR3(100.0f, 0.0f, 0.0f),
	// ###########################################################################################################
	// - 우선. vPos를 (0, 0)으로 하여 원본 이미지의 오른쪽의 반절인 (200, 0) ~ (400, 400) 부분. 즉, 크기가 200X400 이미지를 보여줍니다.
	// - centerX = 200, centerY = 200 => 그려진 이미지의 (200, 200) 부분이 vPos 위치에 오도록합니다.
	// (여기까지는 200X400 그림이 (200, 200)부분이 vPos에 있고 큐브의 반절이 왼쪽에 있습니다.
	// - Position이 X 축으로 100만큼 이동했으므로,
	// So, 200X400 이미지의 정중앙인 (100, 200) 부분이 vPos를 중심으로 그려지게 됩니다.
	// ###########################################################################################################
}

void Player::Init()
{
	m_tInfo.vPos = {
		WINSIZE_X / 2.0f,
		WINSIZE_Y / 2.0f,
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
		m_pSingleTexture->LoadTexture(L"../Texture/Cube.png");
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

Player * Player::Create()
{
	Player *pInstance = new Player; // Encapsulation (Singleton 패턴이 아님.)
	if (pInstance)
	{
		pInstance->Init();
	}

	return pInstance;
}
