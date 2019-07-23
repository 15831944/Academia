#include "stdafx.h"

#include "Player.h"
#include "Monster.h"

#include "MainGame.h"


MainGame::MainGame()
	: m_pDeviceManager(DeviceManager::getInstance()),
	m_pPlayer(nullptr)
{
}


MainGame::~MainGame()
{
	Release();
}

void MainGame::Init()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	//_CrtSetBreakAlloc(256);

	m_pDeviceManager->InitDevice(
		g_hWnd,
		WINSIZE_X, WINSIZE_Y,
		DeviceManager::SCREEN_MODE::WINDOWED
	);

	m_pPlayer = Player::Create();
	m_pMonster = Monster::Create(m_pPlayer);
}

void MainGame::Update()
{
	m_pPlayer->Update();
	m_pMonster->Update();
}

void MainGame::LateUpdate()
{
	m_pPlayer->LateUpdate();
	m_pMonster->LateUpdate();
}

void MainGame::Render()
{
	m_pDeviceManager->RenderBegin();

	m_pPlayer->Render();
	m_pMonster->Render();

	m_pDeviceManager->RenderEnd();
}

void MainGame::Release()
{
	SafeDelete(m_pMonster);
	SafeDelete(m_pPlayer);

	m_pDeviceManager->DestroyInstance();
}

