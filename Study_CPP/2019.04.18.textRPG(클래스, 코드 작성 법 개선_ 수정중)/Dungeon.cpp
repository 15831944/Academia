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

void Dungeon::Progress(void)
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

			cout << "����" << endl;
			system("pause");
			continue;
		case 5:

			cout << "�ҷ�����" << endl;
			system("pause");
			continue;

		case 6:

			cout << "����" << endl;
			system("pause");
			continue;
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

	if (isMonsterAtt == TRUE)
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

}

void Dungeon::setPPlayer(Player *pPlayer)
{
	this->pPlayer = pPlayer;
}
