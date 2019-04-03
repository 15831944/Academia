/*

2019.04.01.home ��


����.


case 1.

textRPG �����

- �÷��̾�� ������ ü��, ���ݷ� ���� �����͸� ���´�.
- ������ �����ϸ� �÷��̾��� ���� ������.(����, ������, ���� ��)
- ĳ���͸� �����ϸ� ĳ������ ������ ��� ������. (�޴�, ����� ��)
- �޴������� ������ �� �� �ִ�.(�ʱ�, �߱�, ��� ��)
- ���� �� �����ϴ� ���ʹ� �̸��� ���ݷ�, ü���� ���´�.
- �� ���� �� �����ϴ� ������ ������ �ɷ�ġ�� �ٸ���.
- ���� ���� �� ����/���� ���� �������� �־�����.
- ���� ���� �� �÷��̾��� ���ݷ¸�ŭ ������ ü���� ������.
(�� �ݴ��� ��쵵 �ش� ��)
- ������ ü���� "0"�� �Ǹ� ��� ����! ����, �޴��� ���ƿ´�.
- �÷��̾��� ü���� "0"�� �Ǹ� ��� ����!
- �÷��̾� ��� �� �޴� ����â���� ���ƿ��� �Ǹ�, ü���� �ʱⰪ���� �缳���ȴ�.


 �ᱹ�� �ϳ��� ����ü�� �÷��̾�� ���͸� �ϳ���...
 ���� �Ҵ��� ���� ��ü ����
 ���ʹ� �Լ� ������ ��ü ����,
 ���� ������ ����ؼ� �������ͽ��� ����

*/

#include <iostream>
#include <cstdio>
#include <ctime>
#include <Windows.h>
#include <conio.h>

#define TRUE 1
#define FALSE 0

using std::cout;
using std::endl;
using std::cin;

typedef struct CharacterType {

	char className[16];
	int currentHp;
	int maxHp;
	int damage;

} Character;


void playTextRPG(void);

void printTRPGTitle(void); // �ʱ� Ÿ��Ʋ ȭ��

void printClassMenu(void);
Character* selectClass(void); // Ŭ���� ����

void initCharacter(Character **dpPlayer, char *name, int maxHp, int damage);

void printStatus(const Character player, const Character monster); // �÷��̾� + ���� UI
void printCharacterStatus(const Character character); // ĳ���� UI

enum BATTLE { RUN, AGAIN, HUNT, DIE };
enum CLASS { WARRIOR, WIZARD, THIEF };

int dungeonExploration(Character *pPlayer, Character *pMonster); // ���� Ž��

void beginnerDungeon(Character **dpMonster); // �ش� ��޿� �´� ���� ����, �Ը� Ŀ���� ���� Ǯ.
void intermediateDungeon(Character **dpMonster);
void advancedDungeon(Character **dpMonster);

int attackMonster(Character *pPlayer, Character *pMonster, bool counterAttack = FALSE); // ���� or ī���� ����

int runAwayFromDungeon(const Character player, const Character monster); // ����

//void printWinResult(const Character monster); // �ǹ� ������ �׳� �����ô�.
//void printLoseResult(const Character monster);

int main(void) {
	srand(unsigned(time(NULL)));

	playTextRPG();

	return 0;
}

void playTextRPG(void) {

	system("mode con cols=110 lines=25"); // â ũ�� ����.

	Character *pPlayer = nullptr, *pMonster = nullptr;

	int sel = 0;
	int battleLoop = BATTLE::AGAIN;

	//printTRPGTitle();
	pPlayer = selectClass(); // �÷��̾� ����
	if (pPlayer == nullptr) {

		return;
	}

	while (TRUE) {

		printCharacterStatus(*pPlayer);

		cout << "1.�ʱ�, 2.�߱�, 3.���, 4.����" << endl;
		cout << "�Է�: "; cin >> sel;

		switch (sel) {
		case 1:
			beginnerDungeon(&pMonster);
			break;

		case 2:
			intermediateDungeon(&pMonster);
			break;

		case 3:
			advancedDungeon(&pMonster);
			break;
		case 4:
			cout << "������ �����մϴ�." << endl << endl;

			if (pPlayer != nullptr) {

				delete pPlayer;
				pPlayer = nullptr;
			}
			return;
		default:
			cout << "�߸��� �Է��Դϴ�." << endl << endl;
			system("pause");
			continue;
			//break;
		}

		battleLoop = BATTLE::AGAIN;
		while (battleLoop == AGAIN) { // ����, ����, ��� ����, ����

			battleLoop = dungeonExploration(pPlayer, pMonster);
		}

		if (pMonster != NULL) { // ������ ���� �Ǿ����Ƿ� ���� ���� ������� ��.

			delete pMonster;
			pMonster = NULL;
		}
	}

}

void printTRPGTitle(void) {

	int index = 0;
	int color2[12] = { 7, 8, 7, 0, 15, 7, 8, 7, 0, 15, 8 };
	const int colorSize = 12;

	enum {

		BLOCK,   /*  0 : ��� */
		DARK_BLUE,  /*  1 : ��ο� �Ķ� */
		DARK_GREEN,  /*  2 : ��ο� �ʷ� */
		DARK_SKY_BLUE, /*  3 : ��ο� �ϴ� */
		DARK_RED,  /*  4 : ��ο� ���� */
		DARK_VOILET, /*  5 : ��ο� ���� */
		DARK_YELLOW, /*  6 : ��ο� ��� */
		GRAY,   /*  7 : ȸ�� */
		DARK_GRAY,  /*  8 : ��ο� ȸ�� */
		BLUE,   /*  9 : �Ķ� */
		GREEN,   /* 10 : �ʷ� */
		SKY_BLUE,  /* 11 : �ϴ� */
		RED,   /* 12 : ���� */
		VOILET,   /* 13 : ���� */
		YELLOW,   /* 14 : ��� */
		WHITE,   /* 15 : �Ͼ� */
	};

	while (index < 15) {

		system("cls");
		cout << "\n\n\n\n\n";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color2[(index) % colorSize]);
		cout << "##############################################################################################################" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color2[(index) % colorSize]);
		cout << "    ######                                              ######                                            " << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color2[(index) % colorSize]);
		cout << "    #     #   ##   #####  #    # ######  ####  #####    #     # #    # #    #  ####  ######  ####  #    # " << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color2[(index) % colorSize]);
		cout << "    #     #  #  #  #    # #   #  #      #        #      #     # #    # ##   # #    # #      #    # ##   # " << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color2[(index) % colorSize]);
		cout << "    #     # #    # #    # ####   #####   ####    #      #     # #    # # #  # #      #####  #    # # #  # " << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color2[(index) % colorSize]);
		cout << "    #     # ###### #####  #  #   #           #   #      #     # #    # #  # # #  ### #      #    # #  # # " << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color2[(index) % colorSize]);
		cout << "    #     # #    # #   #  #   #  #      #    #   #      #     # #    # #   ## #    # #      #    # #   ## " << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color2[(index) % colorSize]);
		cout << "    ######  #    # #    # #    # ######  ####    #      ######   ####  #    #  ####  ######  ####  #    # " << endl << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color2[(index) % colorSize]);
		cout << "##############################################################################################################" << endl;
		cout << "\n\n\n\n\n";

		cout.width(100);
		cout << "Copyright by Vaida _ version 0.1" << endl;

		Sleep(100);
		index++;
	}
}

void printClassMenu(void) {

	system("cls");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	cout << "####### Select Class ##########" << endl;
	cout << "#";
	cout.width(31 - 1);
	cout << "#" << endl;
	cout << "# ";

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	cout << "1. ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
	cout << "����";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	cout << ", ";

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	cout << "2. ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
	cout << "������";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	cout << ", ";

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	cout << "3. ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
	cout << "���� ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	cout << "#" << endl;

	cout << "#";
	cout.width(31 - 1);
	cout << "#" << endl;
	cout << "###############################" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
}

Character* selectClass() {

	int sel = 0;
	Character *pReturn = nullptr;

	while (1) {

		printClassMenu();

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		cout << "�Է�: "; cin >> sel;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

		switch (sel) {

		case CLASS::WARRIOR:
			initCharacter(&pReturn, "����", 200, 10);
			break;

		case CLASS::WIZARD:
			initCharacter(&pReturn, "������", 100, 30);
			break;

		case CLASS::THIEF:
			initCharacter(&pReturn, "����", 150, 20);
			break;

		default:
			cout << "\n�߸��� �Է��Դϴ�." << endl << endl;
			system("pause");
			continue;
		}

	}

	return pReturn;
}

void initCharacter(Character **dpPlayer, char *name, int maxHp, int damage) {

	(*dpPlayer) = new Character; // C++ ����� �޸� ���� �Ҵ� !!!!
								// �Լ����� �޸� ���� �Ҵ��� �� ��, ��ȯ���ַ��� ���� ������ ��� !!!!
	strcpy_s((*dpPlayer)->className, sizeof((*dpPlayer)->className), name);
	(*dpPlayer)->currentHp = (*dpPlayer)->maxHp = maxHp;
	(*dpPlayer)->damage = damage;
}

void printCharacterStatus(const Character character) {

	system("cls");
	cout << "######  Player Status  #######" << endl;

	cout << "#"; // 1
	cout.width(30 - 1);
	cout << "#" << endl;

	cout << "#   Ŭ����: [" << character.className << "]"; // 14
	cout.width(30 - (14 + strlen(character.className)));
	cout << "#" << endl;

	cout << "#     ü��: ["; // 13
	cout.width(3); // 3
	cout << character.currentHp << "/"; // 1
	cout.width(3); // 3
	cout << character.maxHp << "]"; // 1
	cout.width(30 - 21);
	cout << "#" << endl;

	cout << "#   ���ݷ�: "; // 12
	cout.width(3);
	cout << character.damage; // 3
	cout.width(30 - 15);
	cout << "#" << endl;

	cout << "##############################" << endl;
}

// �ʱ�, �߱�, ��� ������ �Լ����� ���� �ʿ伺�� �ֳ� ����.
// ���߿� ������ ����ȭ����� �� �ʿ��� �� ����.
void beginnerDungeon(Character **dpMonster) {

	initCharacter(dpMonster, "������", 30, 5);
}
void intermediateDungeon(Character **dpMonster) {

	initCharacter(dpMonster, "��", 120, 35);
}
void advancedDungeon(Character **dpMonster) {

	initCharacter(dpMonster, "���帮ġ", 300, 70);
}

void printStatus(const Character player, const Character monster) {

	printCharacterStatus(player);
	printCharacterStatus(monster);
}

int dungeonExploration(Character *pPlayer, Character *pMonster) {

	int sel = 0;
	int battleLoop = BATTLE::AGAIN;

	while (battleLoop == BATTLE::AGAIN) {

		printStatus(*pPlayer, *pMonster);

		cout << "1. ����, 2. ����" << endl;
		cout << "�Է�: "; cin >> sel;

		switch (sel) {
		case 1:
			battleLoop = attackMonster(pPlayer, pMonster);
			break;
		case 2:
			cout << "Hello" << endl;
			system("pause");
			battleLoop = runAwayFromDungeon(*pPlayer, *pMonster);
			if (battleLoop == BATTLE::AGAIN) {
				battleLoop = attackMonster(pPlayer, pMonster, TRUE);
			}
			break;

		default:
			cout << "�߸��� �Է��Դϴ�." << endl << endl;
			system("pause");
			continue;
			//break;
		}


		// ���� ���࿡ ���� �̺�Ʈ �߻�
		switch (battleLoop) {
		case BATTLE::RUN:
			//cout << "RUN" << endl;
			break;
		case BATTLE::AGAIN:
			//cout << "AGAIN" << endl;
			break;
		case BATTLE::HUNT:
			//cout << "HUNT" << endl;
			break;

		case BATTLE::DIE:
			//cout << "DIE" << endl;
			break;

		default:
			break;
		}

	}

	return battleLoop;
}


int attackMonster(Character *pPlayer, Character *pMonster, bool counterAttack) {

	int result = AGAIN;

	pPlayer->currentHp -= pMonster->damage;

	if (!counterAttack) { // ���� ���� ��, �÷��̾�� �ݰ� ����.

		pMonster->currentHp -= pPlayer->damage;
	}

	if (pPlayer->currentHp <= 0) { // �÷��̾� DIE

		pPlayer->currentHp = 0;
		if (pMonster->currentHp <= 0) {

			pMonster->currentHp = 0;
		}

		printStatus(*pPlayer, *pMonster); // �÷��̾�� ������ ü���� ����.

		if (pMonster->currentHp <= 0) { // �÷��̾� ���� && ���͵� ����

			cout << "�Ʊ��Ե�..." << endl;
		}
		cout << "[" << pMonster->className << "] ��� ���� �Ф�." << endl << endl;
		system("pause");
		//printLoseResult(*pMonster);

		pPlayer->currentHp = pPlayer->maxHp;
		result = BATTLE::DIE;
	}
	else if (pMonster->currentHp <= 0) { // ���� DIE
		pMonster->currentHp = 0;
		printStatus(*pPlayer, *pMonster);
		cout << "[" << pMonster->className << "] ��� ���� !!!" << endl << endl;
		system("pause");
		//printWinResult(*pMonster);
		result = BATTLE::HUNT;
	}

	return result;
}

int runAwayFromDungeon(const Character player, const Character monster) {

	int coin = rand() % 3;
	if (coin == 0) {
		// ������ !!!
		system("cls");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
		cout << "[" << player.className << "] ��/�� ���� ġ�µ� �����߽��ϴ�." << endl << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		system("pause");

		system("cls");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "[" << monster.className << "]: �ȵ�! ���ƿ� !!!!" << endl << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		system("pause");

		return BATTLE::RUN;
	}
	else {
		// ��� ����?!
		system("cls");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
		cout << "[" << player.className << "] ��/�� ���� ġ�µ� ���� �߽��ϴ�." << endl << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
		cout << "[" << player.className << "] : �ƴ� ��?!" << endl << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		system("pause");

		system("cls");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "[" << monster.className << "]: �������������� !!!!" << endl << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		system("pause");

		return BATTLE::AGAIN;
	}
}

//void printWinResult(const Character monster) { // �ǹ� ������ �׳� �����ô�.
//	cout << "[" << monster.className << "] ��� ���� !!!" << endl << endl;
//	system("pause");
//}
//void printLoseResult(const Character monster) {
//	cout << "[" << monster.className << "] ��� ���� �Ф�." << endl << endl;
//	system("pause");
//}