/*

case 1.

textRPG 만들기

- 플레이어는 직업과 체력, 공격력 등의 데이터를 갖는다.
- 게임을 시작하면 플레이어의 직업 선택함.(전사, 마법사, 도적 등)
- 캐릭터를 생성하면 캐릭터의 정보는 상시 보여줌. (메뉴, 사냥터 등)
- 메뉴에서는 던전을 고를 수 있다.(초급, 중급, 고급 등)
- 던전 내 등장하는 몬스터는 이름과 공격력, 체력을 갖는다.
- 각 던전 별 등장하는 몬스터의 종류와 능력치는 다르다.
- 던전 입장 후 공격/도망 등의 선택지가 주어진다.
- 공격 선택 시 플레이어의 공격력만큼 몬스터의 체력이 낮아짐.
(그 반대의 경우도 해당 됨)
- 몬스터의 체력이 "0"이 되면 사냥 성공! 이후, 메뉴로 돌아온다.
- 플레이어의 체력이 "0"이 되면 사냥 실패!
- 플레이어 사망 시 메뉴 선택창으로 돌아오게 되며, 체력은 초기값으로 재설정된다.


 결국엔 하나의 구조체로 플레이어와 몬스터를 하나로...
 동적 할당을 통한 객체 생성
 몬스터는 함수 내에서 객체 생성,
 더블 포인터 사용해서 스테이터스도 설정

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

void printTRPGTitle(void); // 초기 타이틀 화면

void printClassMenu(void);
Character* selectClass(void); // 클래스 선택

void initCharacter(Character **dpPlayer, char *name, int maxHp, int damage);

void printStatus(const Character player, const Character monster); // 플레이어 + 몬스터 UI
void printCharacterStatus(const Character character); // 캐릭터 UI

enum BATTLE { RUN, AGAIN, HUNT, DIE };
enum CLASS { WARRIOR, WIZARD, THIEF };

int dungeonExploration(Character *pPlayer, Character *pMonster); // 던전 탐험

void beginnerDungeon(Character **dpMonster); // 해당 등급에 맞는 몬스터 생성, 규모 커지면 랜덤 풀.
void intermediateDungeon(Character **dpMonster);
void advancedDungeon(Character **dpMonster);

int attackMonster(Character *pPlayer, Character *pMonster, bool counterAttack = FALSE); // 공격 or 카운터 맞음

int runAwayFromDungeon(const Character player, const Character monster); // 도망

//void printWinResult(const Character monster); // 의미 없지만 그냥 나눕시다.
//void printLoseResult(const Character monster);

int main(void) {
	srand(unsigned(time(NULL)));

	playTextRPG();

	return 0;
}

void playTextRPG(void) {

	system("mode con cols=110 lines=25"); // 창 크기 조절.

	Character *pPlayer = nullptr, *pMonster = nullptr;

	int sel = 0;
	int battleLoop = BATTLE::AGAIN;

	//printTRPGTitle();
	pPlayer = selectClass(); // 플레이어 생성
	if (pPlayer == nullptr) {

		return;
	}

	while (TRUE) {

		printCharacterStatus(*pPlayer);

		cout << "1.초급, 2.중급, 3.고급, 4.종료" << endl;
		cout << "입력: "; cin >> sel;

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
			cout << "게임을 종료합니다." << endl << endl;

			if (pPlayer != nullptr) {

				delete pPlayer;
				pPlayer = nullptr;
			}
			return;
		default:
			cout << "잘못된 입력입니다." << endl << endl;
			system("pause");
			continue;
			//break;
		}

		battleLoop = BATTLE::AGAIN;
		while (battleLoop == AGAIN) { // 도망, 진행, 사냥 성공, 죽음

			battleLoop = dungeonExploration(pPlayer, pMonster);
		}

		if (pMonster != NULL) { // 전투가 종료 되었으므로 몬스터 해제 시켜줘야 함.

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

		BLOCK,   /*  0 : 까망 */
		DARK_BLUE,  /*  1 : 어두운 파랑 */
		DARK_GREEN,  /*  2 : 어두운 초록 */
		DARK_SKY_BLUE, /*  3 : 어두운 하늘 */
		DARK_RED,  /*  4 : 어두운 빨강 */
		DARK_VOILET, /*  5 : 어두운 보라 */
		DARK_YELLOW, /*  6 : 어두운 노랑 */
		GRAY,   /*  7 : 회색 */
		DARK_GRAY,  /*  8 : 어두운 회색 */
		BLUE,   /*  9 : 파랑 */
		GREEN,   /* 10 : 초록 */
		SKY_BLUE,  /* 11 : 하늘 */
		RED,   /* 12 : 빨강 */
		VOILET,   /* 13 : 보라 */
		YELLOW,   /* 14 : 노랑 */
		WHITE,   /* 15 : 하양 */
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
	cout << "전사";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	cout << ", ";

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	cout << "2. ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
	cout << "마법사";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	cout << ", ";

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	cout << "3. ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
	cout << "도적 ";
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
		cout << "입력: "; cin >> sel;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

		switch (sel) {

		case CLASS::WARRIOR:
			initCharacter(&pReturn, "전사", 200, 10);
			break;

		case CLASS::WIZARD:
			initCharacter(&pReturn, "마법사", 100, 30);
			break;

		case CLASS::THIEF:
			initCharacter(&pReturn, "도적", 150, 20);
			break;

		default:
			cout << "\n잘못된 입력입니다." << endl << endl;
			system("pause");
			continue;
		}

	}

	return pReturn;
}

void initCharacter(Character **dpPlayer, char *name, int maxHp, int damage) {

	(*dpPlayer) = new Character; // C++ 방식의 메모리 동적 할당 !!!!
								// 함수에서 메모리 동적 할당을 한 뒤, 반환해주려고 더블 포인터 사용 !!!!
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

	cout << "#   클래스: [" << character.className << "]"; // 14
	cout.width(30 - (14 + strlen(character.className)));
	cout << "#" << endl;

	cout << "#     체력: ["; // 13
	cout.width(3); // 3
	cout << character.currentHp << "/"; // 1
	cout.width(3); // 3
	cout << character.maxHp << "]"; // 1
	cout.width(30 - 21);
	cout << "#" << endl;

	cout << "#   공격력: "; // 12
	cout.width(3);
	cout << character.damage; // 3
	cout.width(30 - 15);
	cout << "#" << endl;

	cout << "##############################" << endl;
}

// 초급, 중급, 고급 던전을 함수별로 나눌 필요성이 있나 싶음.
// 나중에 몬스터의 차별화라든지 더 필요할 것 같음.
void beginnerDungeon(Character **dpMonster) {

	initCharacter(dpMonster, "슬라임", 30, 5);
}
void intermediateDungeon(Character **dpMonster) {

	initCharacter(dpMonster, "골렘", 120, 35);
}
void advancedDungeon(Character **dpMonster) {

	initCharacter(dpMonster, "엘드리치", 300, 70);
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

		cout << "1. 공격, 2. 도망" << endl;
		cout << "입력: "; cin >> sel;

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
			cout << "잘못된 입력입니다." << endl << endl;
			system("pause");
			continue;
			//break;
		}


		// 전투 진행에 따른 이벤트 발생
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

	if (!counterAttack) { // 도망 실패 시, 플레이어는 반격 당함.

		pMonster->currentHp -= pPlayer->damage;
	}

	if (pPlayer->currentHp <= 0) { // 플레이어 DIE

		pPlayer->currentHp = 0;
		if (pMonster->currentHp <= 0) {

			pMonster->currentHp = 0;
		}

		printStatus(*pPlayer, *pMonster); // 플레이어와 몬스터의 체력을 갱신.

		if (pMonster->currentHp <= 0) { // 플레이어 죽음 && 몬스터도 죽음

			cout << "아깝게도..." << endl;
		}
		cout << "[" << pMonster->className << "] 사냥 실패 ㅠㅠ." << endl << endl;
		system("pause");
		//printLoseResult(*pMonster);

		pPlayer->currentHp = pPlayer->maxHp;
		result = BATTLE::DIE;
	}
	else if (pMonster->currentHp <= 0) { // 몬스터 DIE
		pMonster->currentHp = 0;
		printStatus(*pPlayer, *pMonster);
		cout << "[" << pMonster->className << "] 사냥 성공 !!!" << endl << endl;
		system("pause");
		//printWinResult(*pMonster);
		result = BATTLE::HUNT;
	}

	return result;
}

int runAwayFromDungeon(const Character player, const Character monster) {

	int coin = rand() % 3;
	if (coin == 0) {
		// 나갈래 !!!
		system("cls");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
		cout << "[" << player.className << "] 은/는 도망 치는데 성공했습니다." << endl << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		system("pause");

		system("cls");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "[" << monster.className << "]: 안돼! 돌아와 !!!!" << endl << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		system("pause");

		return BATTLE::RUN;
	}
	else {
		// 어딜 나가?!
		system("cls");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
		cout << "[" << player.className << "] 은/는 도망 치는데 실패 했습니다." << endl << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
		cout << "[" << player.className << "] : 아니 왜?!" << endl << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		system("pause");

		system("cls");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "[" << monster.className << "]: ㅋㅋㅋㅋㅋㅋㅋ !!!!" << endl << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		system("pause");

		return BATTLE::AGAIN;
	}
}

//void printWinResult(const Character monster) { // 의미 없지만 그냥 나눕시다.
//	cout << "[" << monster.className << "] 사냥 성공 !!!" << endl << endl;
//	system("pause");
//}
//void printLoseResult(const Character monster) {
//	cout << "[" << monster.className << "] 사냥 실패 ㅠㅠ." << endl << endl;
//	system("pause");
//}
