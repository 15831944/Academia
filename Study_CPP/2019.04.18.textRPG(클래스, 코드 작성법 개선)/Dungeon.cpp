#include "stdafx.h"
#include "Player.h"
#include "Monster.h"
#include "Dungeon.h"

Dungeon::Dungeon(Player *pPlayer)
{
	cout << "Dungeon ������" << endl;
	system("pause");

	Init();

	this->pPlayer = pPlayer;

	battleLoop = BATTLE_STATE::AGAIN; // �ʱ� state�� ���� ��� Ž��.
}

Dungeon::~Dungeon()
{
	cout << "Dungeon �Ҹ���" << endl;
	system("pause");

	Release();
}

void Dungeon::Init(void)
{
	pPlayer = nullptr;
	pMonster = nullptr;
}

bool Dungeon::Progress(void)
{
	int sel = 0;

	while (TRUE)
	{
		system("cls");
		pPlayer->showStatus();
		cout << "1. �ʱ�, 2. �߱�, 3. ���, 4. ����, 5. �ҷ�����, 6. ����" << endl;
		cout << "�Է�: ";
		cin >> sel;

		switch (sel)
		{
		case 1:
			pMonster = new Monster("������", 1, 30, 10);
			break;
		case 2:
			pMonster = new Monster("��", 3, 200, 70);
			break;
		case 3:
			pMonster = new Monster("���帮ġ", 5, 500, 120);
			break;

		case 4:
			saveData();
			continue;
		case 5:
			loadData();
			continue;
		case 6:
			cout << "������ �����մϴ�." << endl << endl;
			return TRUE;
		}

		if (pMonster == nullptr)
		{
			cout << "����, �޸� ���� �Ҵ� pMonster Dungeon::Progress()" << endl;
			system("pause");
			continue;
		}

		goIntoTheDungeon();

		switch (battleLoop) {
		case BATTLE_STATE::HUNT:
			getDungeonReward();
			break;
		case BATTLE_STATE::RUN:
			pPlayer->setGold(pPlayer->getGold() >> 1);
			break;
		case BATTLE_STATE::DIE:
			pPlayer->setExp(0);
			break;
		}

		SAFE_DELETE(pMonster); // ������ ������ ���� �޸� ����
							   // Release �Լ��� ���� �Ͱ� �뵵�� ��� ���ؾ��ұ...

		return FALSE; // �������� ���� ������ �� �ֵ���...
	}
}

void Dungeon::Release(void)
{
	SAFE_DELETE(pMonster);
}

void Dungeon::goIntoTheDungeon(void)
{
	int sel = 0;

	battleLoop = BATTLE_STATE::AGAIN;
	while (battleLoop == BATTLE_STATE::AGAIN)
	{
		system("cls");
		pPlayer->showStatus();
		pMonster->showStatus();
		cout << "1. ����, 2. ����" << endl;
		cout << "�Է�: ";
		cin >> sel;

		switch (sel)
		{
		case 1:
			battleLoop = attackMonster(FALSE); // ������ ��� ���� �����̶�...
										  // MainGame�� ����� �ʴ� ��, ������ �����ؾ��ϴ� ������.
			break;
		case 2:
			battleLoop = tryRunAway();
			if (battleLoop != BATTLE_STATE::RUN) {
				battleLoop = attackMonster(TRUE);
			}
			break;

		default:
			cout << "�߸��� �����Դϴ�." << endl << endl;
			system("pause");
			continue;
		}
	}
}

BATTLE_STATE Dungeon::attackMonster(bool isMonsterAtt)
{
	system("cls");

	if (isMonsterAtt != TRUE)
	{
		pMonster->getDamaged(pPlayer->getAttackDamage());
	}
	pPlayer->getDamaged(pMonster->getAttackDamage());

	if (pPlayer->getHp() <= 0)
	{
		pPlayer->setHp(0);

		if (pMonster->getHp() <= 0)
		{
			pMonster->setHp(0);
		}

		pPlayer->showStatus();
		pMonster->showStatus();

		if (pMonster->getHp() <= 0)
		{
			cout << "�Ʊ��Ե�..." << endl;
		}

		cout << "[��� ����] �÷��̾ �׾����ϴ�." << endl << endl;
		system("pause");

		return BATTLE_STATE::DIE;
	}
	else if (pMonster->getHp() <= 0)
	{
		pMonster->setHp(0);

		pPlayer->showStatus();
		pMonster->showStatus();

		cout << "[��� ����] ���Ͱ� �׾����ϴ�." << endl << endl;
		system("pause");

		return BATTLE_STATE::HUNT;
	}

	return BATTLE_STATE::AGAIN;
}

BATTLE_STATE Dungeon::tryRunAway(void)
{
	int probability = rand() % 4;

	if (probability == 0)
	{
		cout << "[���� ����] �׷���, �ణ�� ��带 �Ҿ���Ƚ��ϴ�." << endl << endl;
		system("pause");

		return BATTLE_STATE::RUN;
	}
	else
	{
		cout << "[���� ����] ���Ͱ� ��������, �ݰ��� �մϴ�." << endl << endl;
		pMonster->setAttackDamage(pMonster->getAttackDamage() + 5); // ������ �뷱��

		system("pause");

		return BATTLE_STATE::AGAIN;
	}
}

void Dungeon::getDungeonReward(void)
{
	// ����ġ�� ��� ȹ�� ����

	pPlayer->getReward(pMonster->getExp(), pMonster->getGold());

}

void Dungeon::saveData(void)
{
	FILE *fp = nullptr;
	errno_t err = fopen_s(&fp, "./hello.txt", "wb");

	if (pPlayer == nullptr) {

		cout << "����, �÷��̾ �����ϴ�. saveData()" << endl;
		system("pause");
		return;
	}

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

bool Dungeon::loadData(void)
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

void Dungeon::setPPlayer(Player *pPlayer)
{
	this->pPlayer = pPlayer;
}
