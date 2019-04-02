///*
//
//2019.04.01.home 월
//
//
//과제.
//
//
//case 1.
//
//textRPG 만들기
//
//- 플레이어는 직업과 체력, 공격력 등의 데이터를 갖는다.
//- 게임을 시작하면 플레이어의 직업 선택함.(전사, 마법사, 도적 등)
//- 캐릭터를 생성하면 캐릭터의 정보는 상시 보여줌. (메뉴, 사냥터 등)
//- 메뉴에서는 던전을 고를 수 있다.(초급, 중급, 고급 등)
//- 던전 내 등장하는 몬스터는 이름과 공격력, 체력을 갖는다.
//- 각 던전 별 등장하는 몬스터의 종류와 능력치는 다르다.
//- 던전 입장 후 공격/도망 등의 선택지가 주어진다.
//- 공격 선택 시 플레이어의 공격력만큼 몬스터의 체력이 낮아짐.
//(그 반대의 경우도 해당 됨)
//- 몬스터의 체력이 "0"이 되면 사냥 성공! 이후, 메뉴로 돌아온다.
//- 플레이어의 체력이 "0"이 되면 사냥 실패!
//- 플레이어 사망 시 메뉴 선택창으로 돌아오게 되며, 체력은 초기값으로 재설정된다.
//
//
// 결국엔 하나의 구조체로 플레이어와 몬스터를 하나로...
// 동적 할당을 통한 객체 생성
// 몬스터는 함수 내에서 객체 생성, 
// 더블 포인터 사용해서 스테이터스도 설정
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
//void printTRPGTitle(void); // 초기 타이틀 화면
//
//void printClassMenu(void);
//void selectClass(Player *player); // 클래스 선택
//
//void printPlayerStatus(const Player player);
//void printHomeMenu(void);
//
//void goIntoTheDungeon(Player *player, Monster *monster, const int dungeon); // 던전 선택
//void beginnerDungeon(Player *player, Monster *monster); // 해당 등급에 맞는 몬스터
//void intermediateDungeon(Player *player, Monster *monster);
//void advancedDungeon(Player *player, Monster *monster);
//bool dungeonExploration(Player *player, Monster *monster); // 던전 탐험
//
//void printDungeonMenu(Player *player, Monster *monster);
//void printStatus(const Player player, const Monster monster); // 플레이어 + 몬스터 UI
//void printMonsterStatus(const Monster monster);
//
//bool attackMonster(Player *player, Monster *monster, bool counterAttack = FALSE); // 공격 or 카운터 맞음
//bool runAwayFromDungeon(const Player player, const Monster monster); // 도망
//
//void printWinResult(const Monster monster); // 의미 없지만 그냥 나눕시다.
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
//	// 0. 필요한 것들
//	/*
//	캐릭터 구조체
//	- 직업 정보 // 직업에 따른 체력과 공격력이 변경이라 초기화를 어떤 방식으로 해줘야하는지...
//	- 현재, 최대 체력
//	- 공격력
//
//	몬스터 구조체
//	- 이름 // 몬스터와 같은 경우도 여러 마리를 만드는 것은 좀 무리가 있지 않나...
//	- 현재, 최대 체력
//	- 공격력
//	*/
//
//	// 1. class 결정
//
//	// 2.1 캐릭터 Status 출력
//
//	//Player player = { "마법사", 150, 150, 20 };
//	//Monster monster = { "슬라임", 150, 150, 90 };
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
//		// 2.2 Menu 출력 및 선택
//		printHomeMenu();
//		cout << "입력: "; cin >> sel;
//
//		if (sel < 1 || sel>4) {
//			cout << "다시 입력하세요." << endl;
//			system("pause");
//			//contitnue;
//		}
//		else if (sel == 4) {
//
//			cout << "게임을 종료합니다." << endl << endl;
//			return;
//		}
//
//
//		// 2.2.1 초급 던전에 따른 몬스터
//		// 2.2.2 중급 던전에 따른 몬스터
//		// 2.2.3 고급 던전에 따른 몬스터
//		// 2.2.4 textRPG 종료
//
//		// 3.1 캐릭터 Status, 몬스터 Status 출력
//		// 3.2 공격 or 도망 선택.
//		// 3.3 전투 상황 판단
//		// 3.4.1 전투 결과 호출_ 사냥 성공!
//		// 3.4.2 전투 결과 호출_ 사냥 실패!
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
//		BLOCK,   /*  0 : 까망 */
//		DARK_BLUE,  /*  1 : 어두운 파랑 */
//		DARK_GREEN,  /*  2 : 어두운 초록 */
//		DARK_SKY_BLUE, /*  3 : 어두운 하늘 */
//		DARK_RED,  /*  4 : 어두운 빨강 */
//		DARK_VOILET, /*  5 : 어두운 보라 */
//		DARK_YELLOW, /*  6 : 어두운 노랑 */
//		GRAY,   /*  7 : 회색 */
//		DARK_GRAY,  /*  8 : 어두운 회색 */
//		BLUE,   /*  9 : 파랑 */
//		GREEN,   /* 10 : 초록 */
//		SKY_BLUE,  /* 11 : 하늘 */
//		RED,   /* 12 : 빨강 */
//		VOILET,   /* 13 : 보라 */
//		YELLOW,   /* 14 : 노랑 */
//		WHITE,   /* 15 : 하양 */
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
//	cout << "전사";
//	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
//	cout << ", ";
//
//	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
//	cout << "2. ";
//	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
//	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
//	cout << "마법사";
//	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
//	cout << ", ";
//
//	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
//	cout << "3. ";
//	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
//	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
//	cout << "도적 ";
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
//		cout << "입력: "; cin >> sel;
//		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
//
//		if (sel == 1) {
//			strcpy_s(player->className, sizeof(player->className), "전사");
//			player->currentHp = player->maxHp = 300;
//			player->damage = 50;
//			break;
//
//		}
//		else if (sel == 2) {
//			strcpy_s(player->className, sizeof(player->className), "마법사");
//			player->currentHp = player->maxHp = 80;
//			player->damage = 100;
//			break;
//
//		}
//		else if (sel == 3) {
//			strcpy_s(player->className, sizeof(player->className), "도적");
//			player->currentHp = player->maxHp = 120;
//			player->damage = 70;
//			break;
//		}
//		else {
//
//			cout << "\n잘못된 입력입니다." << endl << endl;
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
//	cout << "#   클래스: [" << player.className << "]"; // 14
//	cout.width(30 - (14 + strlen(player.className)));
//	cout << "#" << endl;
//
//	cout << "#     체력: ["; // 13
//	cout.width(3); // 3
//	cout << player.currentHp << "/"; // 1
//	cout.width(3); // 3
//	cout << player.maxHp << "]"; // 1
//	cout.width(30 - 21);
//	cout << "#" << endl;
//
//	cout << "#   공격력: "; // 12
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
//	cout << "1.초급, 2.중급, 3.고급, 4.종료" << endl;
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
//		cout << "다시 입력하세요." << endl << endl;
//		break;
//	}
//}
//
//// 초급, 중급, 고급 던전을 함수별로 나눌 필요성이 있나 싶음.
//// 어차피 안에서 수행하는 로직은 비슷한데...
//void beginnerDungeon(Player *player, Monster *monster) {
//
//	bool battleLoop = FALSE;
//
//	strcpy_s(monster->name, sizeof(monster->name), "슬라임");
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
//	strcpy_s(monster->name, sizeof(monster->name), "골렘");
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
//	strcpy_s(monster->name, sizeof(monster->name), "엘드리치");
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
//		cout << "입력: "; cin >> sel;
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
//	cout << "1. 공격, 2. 도망" << endl;
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
//	cout << "#   클래스: [" << monster.name << "]"; // 14
//	cout.width(30 - (14 + strlen(monster.name)));
//	cout << "#" << endl;
//
//	cout << "#     체력: ["; // 13
//	cout.width(3); // 3
//	cout << monster.currentHp << "/"; // 1
//	cout.width(3); // 3
//	cout << monster.maxHp << "]"; // 1
//	cout.width(30 - 21);
//	cout << "#" << endl;
//
//	cout << "#   공격력: "; // 12
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
//			cout << "아깝게도..." << endl;
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
//		// 나갈래 !!!
//		system("cls");
//		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
//		cout << "[" << player.className << "] 은/는 도망 치는데 성공했습니다." << endl << endl;
//		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
//		system("pause");
//
//		system("cls");
//		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
//		cout << "[" << monster.name << "]: 안돼! 돌아와 !!!!" << endl << endl;
//		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
//		system("pause");
//
//		return TRUE;
//	}
//	else {
//		// 어딜 나가?!
//		system("cls");
//		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
//		cout << "[" << player.className << "] 은/는 도망 치는데 실패 했습니다." << endl << endl;
//		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
//		cout << "[" << player.className << "] : 아니 왜?!" << endl << endl;
//		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
//		system("pause");
//
//		system("cls");
//		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
//		cout << "[" << monster.name << "]: ㅋㅋㅋㅋㅋㅋㅋ !!!!" << endl << endl;
//		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
//		system("pause");
//
//		return FALSE;
//	}
//
//	system("pause");
//}
//
//void printWinResult(const Monster monster) { // 의미 없지만 그냥 나눕시다.
//	cout << "[" << monster.name << "] 사냥 성공 !!!" << endl << endl;
//	system("pause");
//}
//void printLoseResult(const Monster monster) {
//	cout << "[" << monster.name << "] 사냥 실패 ㅠㅠ." << endl << endl;
//	system("pause");
//}