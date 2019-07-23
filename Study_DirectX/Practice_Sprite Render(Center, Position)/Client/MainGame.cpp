#include "stdafx.h"

#include "Player.h"

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
}

void MainGame::Update()
{
	m_pPlayer->Update();
}

void MainGame::LateUpdate()
{
	m_pPlayer->LateUpdate();
}

void MainGame::Render()
{
	m_pDeviceManager->RenderBegin();

	m_pPlayer->Render();

	m_pDeviceManager->RenderEnd();
}

void MainGame::Release()
{
	SafeDelete(m_pPlayer);

	m_pDeviceManager->DestroyInstance();
}

