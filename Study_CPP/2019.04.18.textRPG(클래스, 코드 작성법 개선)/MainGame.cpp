#include "stdafx.h"
#include "Player.h"
#include "Dungeon.h"
#include "MainGame.h"

MainGame::MainGame()
{
	cout << "MainGame ������" << endl;
	system("pause");
}

MainGame::~MainGame()
{
	cout << "MainGame �Ҹ���" << endl;
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
			if (isLoaded == TRUE) // �ε� �����ϸ� �ٽ��ϱ�.
			{
				break;
			}
		}
	}

	pDungeon = new Dungeon(pPlayer); // ���ʿ� ������ Player �޸� ���� �Ҵ� ����ó�� ��.
	if (pDungeon == nullptr)
	{
		cout << "����, �޸� ���� �Ҵ� MainGame::Init()" << endl;
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
		cout << "1. ����, 2. ����, 3. ������" << endl;
		cin >> sel;

		switch (sel) {
		case 1:
			isExit = pDungeon->Progress();
			if (isExit == TRUE)
			{
				return; // �������� ���� ����.
			}
			break;
		case 2:
			saveData();
			continue;
		case 3:
			cout << "������ �����մϴ�." << endl << endl;
			return;

		default:
			cout << "�߸��� �����Դϴ�." << endl << endl;
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
		cout << "1. �����ϱ�, 2. �ҷ�����" << endl;
		cout << "�Է�: ";
		cin >> sel;

		switch (sel)
		{
		case TITLE_MENU::NEW:
			return TRUE;
		case TITLE_MENU::LOAD:
			return FALSE;

		default:
			cout << "�߸��� �����Դϴ�." << endl;
			system("pause");
			continue;
		}
	}
}

Player * MainGame::selectClass(void) // ��� ����� pPlayer�� ���� �ֱ� ������...
{
	Player *pReturn = nullptr;
	int sel = 0;

	while (TRUE)
	{
		system("cls");
		
		cout << "1. ����, 2. ������, 3. ����" << endl;
		cout << "�Է�: ";
		cin >> sel;

		switch (sel)
		{
		case CLASS::WARRIOR:
			pReturn = new Player("����", 200, 10);
			break;
		case CLASS::WIZARD:
			pReturn = new Player("������", 100, 30);
			break;
		case CLASS::THIEF:
			pReturn = new Player("����", 150, 20);
			break;

		default:
			cout << "�߸��� �Է��Դϴ�." << endl << endl;
			system("pause");
			continue;
		}

		if (pReturn == nullptr) // ���Ŀ��� � ó���� �ؾ��� ��...
		{
			cout << "����, �޸� ���� �Ҵ� MainGame::selectClass()" << endl;
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
		cout << "�����͸� ���� �մϴ�." << endl << endl;

		fwrite(pPlayer, sizeof(Player), 1, fp);

		fclose(fp);
		system("pause");
	}
	else
	{

		cout << "������ ���忡 �����߽��ϴ�." << endl << endl;

		system("pause");
	}
}

bool MainGame::loadData(void)
{
	FILE *fp = nullptr;
	errno_t err = fopen_s(&fp, "./hello.txt", "rb");

	if (err == 0)
	{
		cout << "�����͸� �ҷ��ɴϴ�." << endl << endl;

		SAFE_DELETE(pPlayer);

		pPlayer = new Player(); // ������ ��
		if (pPlayer == nullptr)
		{
			cout << "����, �޸� ���� �Ҵ� MainGame::loadData()" << endl << endl;

			cout << "������ ���� �����մϴ�." << endl << endl;

			system("pause");
			return FALSE;
		}

		fread(pPlayer, sizeof(Player), 1, fp); // Player ��ü�� �� �־���.

		fclose(fp);
		system("pause");

		return TRUE;
	}
	else
	{

		cout << "������ �ҷ����Ⱑ �����߽��ϴ�." << endl << endl;
		system("pause");

		return FALSE;
	}
}
