#include "stdafx.h"
#include "Player.h"
#include "Dungeon.h"
#include "MainGame.h"

MainGame::MainGame()
{
	cout << "MainGame 생성자" << endl;
	system("pause");
}

MainGame::~MainGame()
{
	cout << "MainGame 소멸자" << endl;
	system("pause");
	Release();
}

bool MainGame::Init(void)
{
	bool isNew = showTitleMenu();
	bool isLoaded = FALSE;
	
	while (TRUE)
	{
		if (isNew == TRUE)
		{
			pPlayer = selectClass();
			break;
		}
		else
		{
			isLoaded = loadData();
			if (isLoaded == TRUE) // 로드 실패하면 다시하기.
			{
				break;
			}
		}
	}

	pDungeon = new Dungeon(pPlayer); // 애초에 위에서 Player 메모리 동적 할당 예외처리 함.
	if (pDungeon == nullptr)
	{
		cout << "오류, 메모리 동적 할당 MainGame::Init()" << endl;
		system("pause");
		return FALSE;
	}

	pDungeon->setPPlayer(pPlayer);

	return TRUE;
}

void MainGame::Progress(void)
{
	int sel = 0;
	bool isExit = FALSE;

	while (TRUE)
	{
		system("cls");
		pPlayer->showStatus();
		cout << "1. 던전, 2. 저장, 3. 나가기" << endl;
		cin >> sel;

		switch (sel) {
		case 1:
			isExit = pDungeon->Progress();
			if (isExit == TRUE)
			{
				return; // 던전에서 게임 종료.
			}
			break;
		case 2:
			saveData();
			continue;
		case 3:
			cout << "게임을 종료합니다." << endl << endl;
			return;

		default:
			cout << "잘못된 선택입니다." << endl << endl;
			system("pause");
			continue;
		}
	}
}

void MainGame::Release(void)
{
	SAFE_DELETE(pPlayer);
	SAFE_DELETE(pDungeon);
}

bool MainGame::showTitleMenu(void)
{
	int sel = 0;

	while (TRUE)
	{
		system("cls");
		cout << "1. 새로하기, 2. 불러오기" << endl;
		cout << "입력: ";
		cin >> sel;

		switch (sel)
		{
		case TITLE_MENU::NEW:
			return TRUE;
		case TITLE_MENU::LOAD:
			return FALSE;

		default:
			cout << "잘못된 선택입니다." << endl;
			system("pause");
			continue;
		}
	}
}

Player * MainGame::selectClass(void) // 사실 멤버로 pPlayer를 갖고 있기 때문에...
{
	Player *pReturn = nullptr;
	int sel = 0;

	while (TRUE)
	{
		system("cls");
		
		cout << "1. 전사, 2. 마법사, 3. 도적" << endl;
		cout << "입력: ";
		cin >> sel;

		switch (sel)
		{
		case CLASS::WARRIOR:
			pReturn = new Player("전사", 200, 10);
			break;
		case CLASS::WIZARD:
			pReturn = new Player("마법사", 100, 30);
			break;
		case CLASS::THIEF:
			pReturn = new Player("도적", 150, 20);
			break;

		default:
			cout << "잘못된 입력입니다." << endl << endl;
			system("pause");
			continue;
		}

		if (pReturn == nullptr) // 이후에는 어떤 처리를 해야할 지...
		{
			cout << "오류, 메모리 동적 할당 MainGame::selectClass()" << endl;
			system("pause");
		}
		else 
		{
			break;
		}
	}

	return pReturn;
}

void MainGame::saveData(void)
{
	FILE *fp = nullptr;
	errno_t err = fopen_s(&fp, "./hello.txt", "wb");

	if (err == 0)
	{
		cout << "데이터를 저장 합니다." << endl << endl;

		fwrite(pPlayer, sizeof(Player), 1, fp);

		fclose(fp);
		system("pause");
	}
	else
	{

		cout << "데이터 저장에 실패했습니다." << endl << endl;

		system("pause");
	}
}

bool MainGame::loadData(void)
{
	FILE *fp = nullptr;
	errno_t err = fopen_s(&fp, "./hello.txt", "rb");

	if (err == 0)
	{
		cout << "데이터를 불러옵니다." << endl << endl;

		SAFE_DELETE(pPlayer);

		pPlayer = new Player(); // 쓰레기 값
		if (pPlayer == nullptr)
		{
			cout << "오류, 메모리 동적 할당 MainGame::loadData()" << endl << endl;

			cout << "게임을 새로 시작합니다." << endl << endl;

			system("pause");
			return FALSE;
		}

		fread(pPlayer, sizeof(Player), 1, fp); // Player 객체에 값 넣어줌.

		fclose(fp);
		system("pause");

		return TRUE;
	}
	else
	{

		cout << "데이터 불러오기가 실패했습니다." << endl << endl;
		system("pause");

		return FALSE;
	}
}
