///*
//
//2019.04.01.home ��
//
//
//����.
//
//
//case 1.
//
//textRPG �����
//
//- �÷��̾�� ������ ü��, ���ݷ� ���� �����͸� ���´�.
//- ������ �����ϸ� �÷��̾��� ���� ������.(����, ������, ���� ��)
//- ĳ���͸� �����ϸ� ĳ������ ������ ��� ������. (�޴�, ����� ��)
//- �޴������� ������ �� �� �ִ�.(�ʱ�, �߱�, ��� ��)
//- ���� �� �����ϴ� ���ʹ� �̸��� ���ݷ�, ü���� ���´�.
//- �� ���� �� �����ϴ� ������ ������ �ɷ�ġ�� �ٸ���.
//- ���� ���� �� ����/���� ���� �������� �־�����.
//- ���� ���� �� �÷��̾��� ���ݷ¸�ŭ ������ ü���� ������.
//(�� �ݴ��� ��쵵 �ش� ��)
//- ������ ü���� "0"�� �Ǹ� ��� ����! ����, �޴��� ���ƿ´�.
//- �÷��̾��� ü���� "0"�� �Ǹ� ��� ����!
//- �÷��̾� ��� �� �޴� ����â���� ���ƿ��� �Ǹ�, ü���� �ʱⰪ���� �缳���ȴ�.
//
//
// �ᱹ�� �ϳ��� ����ü�� �÷��̾�� ���͸� �ϳ���...
// ���� �Ҵ��� ���� ��ü ����
// ���ʹ� �Լ� ������ ��ü ����, 
// ���� ������ ����ؼ� �������ͽ��� ����
//
//*/
//
//#include <iostream>
//#include <cstdio>
//#include <ctime>
//#include <Windows.h>
//#include <conio.h>
//
//#define TRUE 1
//#define FALSE 0
//
//using std::cout;
//using std::endl;
//using std::cin;
//
//typedef struct PlayerCharacterType {
//
//	char className[16];
//	int currentHp;
//	int maxHp;
//	int damage;
//
//} Player;
//
//typedef struct MonsterType {
//
//	char name[16];
//	int currentHp;
//	int maxHp;
//	int damage;
//
//} Monster;
//
//void playTextRPG(void);
//
//void printTRPGTitle(void); // �ʱ� Ÿ��Ʋ ȭ��
//
//void printClassMenu(void);
//void selectClass(Player *player); // Ŭ���� ����
//
//void printPlayerStatus(const Player player);
//void printHomeMenu(void);
//
//void goIntoTheDungeon(Player *player, Monster *monster, const int dungeon); // ���� ����
//void beginnerDungeon(Player *player, Monster *monster); // �ش� ��޿� �´� ����
//void intermediateDungeon(Player *player, Monster *monster);
//void advancedDungeon(Player *player, Monster *monster);
//bool dungeonExploration(Player *player, Monster *monster); // ���� Ž��
//
//void printDungeonMenu(Player *player, Monster *monster);
//void printStatus(const Player player, const Monster monster); // �÷��̾� + ���� UI
//void printMonsterStatus(const Monster monster);
//
//bool attackMonster(Player *player, Monster *monster, bool counterAttack = FALSE); // ���� or ī���� ����
//bool runAwayFromDungeon(const Player player, const Monster monster); // ����
//
//void printWinResult(const Monster monster); // �ǹ� ������ �׳� �����ô�.
//void printLoseResult(const Monster monster);
//
//int main(void) {
//	srand(unsigned(time(NULL)));
//
//	playTextRPG();
//
//	return 0;
//}
//
//void playTextRPG(void) {
//
//	// 0. �ʿ��� �͵�
//	/*
//	ĳ���� ����ü
//	- ���� ���� // ������ ���� ü�°� ���ݷ��� �����̶� �ʱ�ȭ�� � ������� ������ϴ���...
//	- ����, �ִ� ü��
//	- ���ݷ�
//
//	���� ����ü
//	- �̸� // ���Ϳ� ���� ��쵵 ���� ������ ����� ���� �� ������ ���� �ʳ�...
//	- ����, �ִ� ü��
//	- ���ݷ�
//	*/
//
//	// 1. class ����
//
//	// 2.1 ĳ���� Status ���
//
//	//Player player = { "������", 150, 150, 20 };
//	//Monster monster = { "������", 150, 150, 90 };
//
//	system("mode con cols=110 lines=25");
//
//	Player player = {};
//	Monster monster = {};
//
//	int sel = 0;
//
//	printTRPGTitle();
//	selectClass(&player);
//
//	while (1) {
//
//		printPlayerStatus(player);
//
//		// 2.2 Menu ��� �� ����
//		printHomeMenu();
//		cout << "�Է�: "; cin >> sel;
//
//		if (sel < 1 || sel>4) {
//			cout << "�ٽ� �Է��ϼ���." << endl;
//			system("pause");
//			//contitnue;
//		}
//		else if (sel == 4) {
//
//			cout << "������ �����մϴ�." << endl << endl;
//			return;
//		}
//
//
//		// 2.2.1 �ʱ� ������ ���� ����
//		// 2.2.2 �߱� ������ ���� ����
//		// 2.2.3 ��� ������ ���� ����
//		// 2.2.4 textRPG ����
//
//		// 3.1 ĳ���� Status, ���� Status ���
//		// 3.2 ���� or ���� ����.
//		// 3.3 ���� ��Ȳ �Ǵ�
//		// 3.4.1 ���� ��� ȣ��_ ��� ����!
//		// 3.4.2 ���� ��� ȣ��_ ��� ����!
//		goIntoTheDungeon(&player, &monster, sel);
//
//	}
//
//}
//
//void printTRPGTitle(void) {
//
//	int count = 0, index = 0;
//	int color[3] = { 4, 8, 12 };
//	int color2[12] = { 7, 8, 7, 0, 15, 7, 8, 7, 0, 15, 8 };
//	const int colorSize = 12;
//	enum {
//		BLOCK,   /*  0 : ��� */
//		DARK_BLUE,  /*  1 : ��ο� �Ķ� */
//		DARK_GREEN,  /*  2 : ��ο� �ʷ� */
//		DARK_SKY_BLUE, /*  3 : ��ο� �ϴ� */
//		DARK_RED,  /*  4 : ��ο� ���� */
//		DARK_VOILET, /*  5 : ��ο� ���� */
//		DARK_YELLOW, /*  6 : ��ο� ��� */
//		GRAY,   /*  7 : ȸ�� */
//		DARK_GRAY,  /*  8 : ��ο� ȸ�� */
//		BLUE,   /*  9 : �Ķ� */
//		GREEN,   /* 10 : �ʷ� */
//		SKY_BLUE,  /* 11 : �ϴ� */
//		RED,   /* 12 : ���� */
//		VOILET,   /* 13 : ���� */
//		YELLOW,   /* 14 : ��� */
//		WHITE,   /* 15 : �Ͼ� */
//	};
//
//	while (count < 15) {
//		system("cls");
//		/*cout << "\n\n\n\n\n";
//		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color[(index++) % 3]);
//		cout << "##############################################################################################################" << endl;
//		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color[(index++) % 3]);
//		cout << "    ######                                              ######                                            " << endl;
//		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color[(index++) % 3]);
//		cout << "    #     #   ##   #####  #    # ######  ####  #####    #     # #    # #    #  ####  ######  ####  #    # " << endl;
//		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color[(index++) % 3]);
//		cout << "    #     #  #  #  #    # #   #  #      #        #      #     # #    # ##   # #    # #      #    # ##   # " << endl;
//		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color[(index++) % 3]);
//		cout << "    #     # #    # #    # ####   #####   ####    #      #     # #    # # #  # #      #####  #    # # #  # " << endl;
//		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color[(index++) % 3]);
//		cout << "    #     # ###### #####  #  #   #           #   #      #     # #    # #  # # #  ### #      #    # #  # # " << endl;
//		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color[(index++) % 3]);
//		cout << "    #     # #    # #   #  #   #  #      #    #   #      #     # #    # #   ## #    # #      #    # #   ## " << endl;
//		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color[(index++) % 3]);
//		cout << "    ######  #    # #    # #    # ######  ####    #      ######   ####  #    #  ####  ######  ####  #    # " << endl << endl;
//		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color[(index++) % 3]);
//		cout << "##############################################################################################################" << endl;
//		cout << "\n\n\n\n\n";*/
//
//		cout << "\n\n\n\n\n";
//		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color2[(index) % colorSize]);
//		cout << "##############################################################################################################" << endl;
//		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color2[(index) % colorSize]);
//		cout << "    ######                                              ######                                            " << endl;
//		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color2[(index) % colorSize]);
//		cout << "    #     #   ##   #####  #    # ######  ####  #####    #     # #    # #    #  ####  ######  ####  #    # " << endl;
//		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color2[(index) % colorSize]);
//		cout << "    #     #  #  #  #    # #   #  #      #        #      #     # #    # ##   # #    # #      #    # ##   # " << endl;
//		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color2[(index) % colorSize]);
//		cout << "    #     # #    # #    # ####   #####   ####    #      #     # #    # # #  # #      #####  #    # # #  # " << endl;
//		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color2[(index) % colorSize]);
//		cout << "    #     # ###### #####  #  #   #           #   #      #     # #    # #  # # #  ### #      #    # #  # # " << endl;
//		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color2[(index) % colorSize]);
//		cout << "    #     # #    # #   #  #   #  #      #    #   #      #     # #    # #   ## #    # #      #    # #   ## " << endl;
//		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color2[(index) % colorSize]);
//		cout << "    ######  #    # #    # #    # ######  ####    #      ######   ####  #    #  ####  ######  ####  #    # " << endl << endl;
//		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color2[(index) % colorSize]);
//		cout << "##############################################################################################################" << endl;
//		cout << "\n\n\n\n\n";
//
//
//		cout.width(100);
//		cout << "Copyright by Vaida _ version 0.1" << endl;
//
//		Sleep(100);
//		count++;
//		index++;
//	}
//}
//
//void printClassMenu(void) {
//
//	system("cls");
//	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
//	cout << "####### Select Class ##########" << endl;
//	cout << "#";
//	cout.width(31 - 1);
//	cout << "#" << endl;
//	cout << "# ";
//
//	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
//	cout << "1. ";
//	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
//	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
//	cout << "����";
//	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
//	cout << ", ";
//
//	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
//	cout << "2. ";
//	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
//	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
//	cout << "������";
//	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
//	cout << ", ";
//
//	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
//	cout << "3. ";
//	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
//	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
//	cout << "���� ";
//	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
//	cout << "#" << endl;
//
//	cout << "#";
//	cout.width(31 - 1);
//	cout << "#" << endl;
//	cout << "###############################" << endl;
//	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
//}
//
//void selectClass(Player *player) {
//
//	int sel = 0;
//
//	while (1) {
//
//		printClassMenu();
//
//		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
//		cout << "�Է�: "; cin >> sel;
//		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
//
//		if (sel == 1) {
//			strcpy_s(player->className, sizeof(player->className), "����");
//			player->currentHp = player->maxHp = 300;
//			player->damage = 50;
//			break;
//
//		}
//		else if (sel == 2) {
//			strcpy_s(player->className, sizeof(player->className), "������");
//			player->currentHp = player->maxHp = 80;
//			player->damage = 100;
//			break;
//
//		}
//		else if (sel == 3) {
//			strcpy_s(player->className, sizeof(player->className), "����");
//			player->currentHp = player->maxHp = 120;
//			player->damage = 70;
//			break;
//		}
//		else {
//
//			cout << "\n�߸��� �Է��Դϴ�." << endl << endl;
//			system("pause");
//			continue;
//		}
//	}
//}
//
//void printPlayerStatus(const Player player) {
//
//	system("cls");
//	cout << "######  Player Status  #######" << endl;
//
//	cout << "#"; // 1
//	cout.width(30 - 1);
//	cout << "#" << endl;
//
//	cout << "#   Ŭ����: [" << player.className << "]"; // 14
//	cout.width(30 - (14 + strlen(player.className)));
//	cout << "#" << endl;
//
//	cout << "#     ü��: ["; // 13
//	cout.width(3); // 3
//	cout << player.currentHp << "/"; // 1
//	cout.width(3); // 3
//	cout << player.maxHp << "]"; // 1
//	cout.width(30 - 21);
//	cout << "#" << endl;
//
//	cout << "#   ���ݷ�: "; // 12
//	cout.width(3);
//	cout << player.damage; // 3
//	cout.width(30 - 15);
//	cout << "#" << endl;
//
//	cout << "##############################" << endl;
//}
//
//
//void printHomeMenu(void) {
//	cout << "1.�ʱ�, 2.�߱�, 3.���, 4.����" << endl;
//}
//
//void goIntoTheDungeon(Player *player, Monster *monster, const int dungeon) {
//
//	switch (dungeon) {
//	case 1:
//		beginnerDungeon(player, monster);
//		break;
//
//	case 2:
//		intermediateDungeon(player, monster);
//		break;
//
//	case 3:
//		advancedDungeon(player, monster);
//		break;
//
//	default:
//		cout << "�ٽ� �Է��ϼ���." << endl << endl;
//		break;
//	}
//}
//
//// �ʱ�, �߱�, ��� ������ �Լ����� ���� �ʿ伺�� �ֳ� ����.
//// ������ �ȿ��� �����ϴ� ������ ����ѵ�...
//void beginnerDungeon(Player *player, Monster *monster) {
//
//	bool battleLoop = FALSE;
//
//	strcpy_s(monster->name, sizeof(monster->name), "������");
//	monster->currentHp = monster->maxHp = 100;
//	monster->damage = 30;
//
//	while (!battleLoop) {
//
//		battleLoop = dungeonExploration(player, monster);
//	}
//
//}
//void intermediateDungeon(Player *player, Monster *monster) {
//
//	bool battleLoop = FALSE;
//
//	strcpy_s(monster->name, sizeof(monster->name), "��");
//	monster->currentHp = monster->maxHp = 150;
//	monster->damage = 45;
//
//	while (!battleLoop) {
//
//		battleLoop = dungeonExploration(player, monster);
//	}
//}
//void advancedDungeon(Player *player, Monster *monster) {
//
//	bool battleLoop = FALSE;
//
//	strcpy_s(monster->name, sizeof(monster->name), "���帮ġ");
//	monster->currentHp = monster->maxHp = 300;
//	monster->damage = 50;
//
//	while (!battleLoop) {
//
//		battleLoop = dungeonExploration(player, monster);
//	}
//}
//
//bool dungeonExploration(Player *player, Monster *monster) {
//
//	int sel = 0;
//	bool battleLoop = FALSE;
//
//	while (!battleLoop) {
//
//		printDungeonMenu(player, monster);
//		cout << "�Է�: "; cin >> sel;
//
//		switch (sel) {
//		case 1:
//			battleLoop = attackMonster(player, monster);
//			break;
//		case 2:
//			battleLoop = runAwayFromDungeon(*player, *monster);
//			if (!battleLoop) {
//				battleLoop = attackMonster(player, monster, TRUE);
//			}
//			break;
//
//		default:
//
//			break;
//		}
//
//	}
//
//	return battleLoop;
//}
//
//void printDungeonMenu(Player *player, Monster *monster) {
//	printStatus(*player, *monster);
//
//	cout << "1. ����, 2. ����" << endl;
//}
//
//void printStatus(const Player player, const Monster monster) {
//	printPlayerStatus(player);
//	printMonsterStatus(monster);
//}
//
//void printMonsterStatus(const Monster monster) {
//
//	cout << "######  Monster Status  ######" << endl;
//	cout << "#";
//	cout.width(30 - 1);
//	cout << "#" << endl;
//
//	cout << "#   Ŭ����: [" << monster.name << "]"; // 14
//	cout.width(30 - (14 + strlen(monster.name)));
//	cout << "#" << endl;
//
//	cout << "#     ü��: ["; // 13
//	cout.width(3); // 3
//	cout << monster.currentHp << "/"; // 1
//	cout.width(3); // 3
//	cout << monster.maxHp << "]"; // 1
//	cout.width(30 - 21);
//	cout << "#" << endl;
//
//	cout << "#   ���ݷ�: "; // 12
//	cout.width(3); // 3
//	cout << monster.damage;
//	cout.width(30 - 15);
//	cout << "#" << endl;
//	cout << "##############################" << endl;
//}
//
//bool attackMonster(Player *player, Monster *monster, bool counterAttack) {
//
//	bool battleLoop = FALSE;
//
//	player->currentHp -= monster->damage;
//	
//	if (!counterAttack) {
//		monster->currentHp -= player->damage;
//	}
//
//	if (player->currentHp <= 0) {
//
//		player->currentHp = 0;
//		printStatus(*player, *monster);
//
//		if (monster->currentHp <= 0) {
//			monster->currentHp = 0;
//			cout << "�Ʊ��Ե�..." << endl;
//		}
//
//		printLoseResult(*monster);
//
//		player->currentHp = player->maxHp;
//		battleLoop = TRUE;
//	}
//	else if (monster->currentHp <= 0) {
//		monster->currentHp = 0;
//		printStatus(*player, *monster);
//		printWinResult(*monster);
//		battleLoop = TRUE;
//	}
//
//	return battleLoop;
//}
//
//bool runAwayFromDungeon(const Player player, const Monster monster) {
//
//
//	int coin = rand() % 3;
//
//	if (coin == 0) {
//		// ������ !!!
//		system("cls");
//		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
//		cout << "[" << player.className << "] ��/�� ���� ġ�µ� �����߽��ϴ�." << endl << endl;
//		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
//		system("pause");
//
//		system("cls");
//		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
//		cout << "[" << monster.name << "]: �ȵ�! ���ƿ� !!!!" << endl << endl;
//		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
//		system("pause");
//
//		return TRUE;
//	}
//	else {
//		// ��� ����?!
//		system("cls");
//		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
//		cout << "[" << player.className << "] ��/�� ���� ġ�µ� ���� �߽��ϴ�." << endl << endl;
//		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
//		cout << "[" << player.className << "] : �ƴ� ��?!" << endl << endl;
//		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
//		system("pause");
//
//		system("cls");
//		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
//		cout << "[" << monster.name << "]: �������������� !!!!" << endl << endl;
//		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
//		system("pause");
//
//		return FALSE;
//	}
//
//	system("pause");
//}
//
//void printWinResult(const Monster monster) { // �ǹ� ������ �׳� �����ô�.
//	cout << "[" << monster.name << "] ��� ���� !!!" << endl << endl;
//	system("pause");
//}
//void printLoseResult(const Monster monster) {
//	cout << "[" << monster.name << "] ��� ���� �Ф�." << endl << endl;
//	system("pause");
//}