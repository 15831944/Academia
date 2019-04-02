///*
//
//2019.04.01.home 杉
//
//
//引薦.
//
//
//case 1.
//
//textRPG 幻級奄
//
//- 巴傾戚嬢澗 送穣引 端径, 因維径 去税 汽戚斗研 握澗陥.
//- 惟績聖 獣拙馬檎 巴傾戚嬢税 送穣 識澱敗.(穿紫, 原狛紫, 亀旋 去)
//- 蝶遣斗研 持失馬檎 蝶遣斗税 舛左澗 雌獣 左食捜. (五敢, 紫撹斗 去)
//- 五敢拭辞澗 揮穿聖 壱研 呪 赤陥.(段厭, 掻厭, 壱厭 去)
//- 揮穿 鎧 去舌馬澗 佼什斗澗 戚硯引 因維径, 端径聖 握澗陥.
//- 唖 揮穿 紺 去舌馬澗 佼什斗税 曽嫌人 管径帖澗 陥牽陥.
//- 揮穿 脊舌 板 因維/亀諺 去税 識澱走亜 爽嬢遭陥.
//- 因維 識澱 獣 巴傾戚嬢税 因維径幻鏑 佼什斗税 端径戚 碍焼像.
//(益 鋼企税 井酔亀 背雁 喫)
//- 佼什斗税 端径戚 "0"戚 鞠檎 紫撹 失因! 戚板, 五敢稽 宜焼紳陥.
//- 巴傾戚嬢税 端径戚 "0"戚 鞠檎 紫撹 叔鳶!
//- 巴傾戚嬢 紫諺 獣 五敢 識澱但生稽 宜焼神惟 鞠悟, 端径精 段奄葵生稽 仙竺舛吉陥.
//
//
// 衣厩殖 馬蟹税 姥繕端稽 巴傾戚嬢人 佼什斗研 馬蟹稽...
// 疑旋 拝雁聖 搭廃 梓端 持失
// 佼什斗澗 敗呪 鎧拭辞 梓端 持失, 
// 希鷺 匂昔斗 紫遂背辞 什砺戚斗什亀 竺舛
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
//void printTRPGTitle(void); // 段奄 展戚堂 鉢檎
//
//void printClassMenu(void);
//void selectClass(Player *player); // 適掘什 識澱
//
//void printPlayerStatus(const Player player);
//void printHomeMenu(void);
//
//void goIntoTheDungeon(Player *player, Monster *monster, const int dungeon); // 揮穿 識澱
//void beginnerDungeon(Player *player, Monster *monster); // 背雁 去厭拭 限澗 佼什斗
//void intermediateDungeon(Player *player, Monster *monster);
//void advancedDungeon(Player *player, Monster *monster);
//bool dungeonExploration(Player *player, Monster *monster); // 揮穿 貼蝿
//
//void printDungeonMenu(Player *player, Monster *monster);
//void printStatus(const Player player, const Monster monster); // 巴傾戚嬢 + 佼什斗 UI
//void printMonsterStatus(const Monster monster);
//
//bool attackMonster(Player *player, Monster *monster, bool counterAttack = FALSE); // 因維 or 朝錘斗 限製
//bool runAwayFromDungeon(const Player player, const Monster monster); // 亀諺
//
//void printWinResult(const Monster monster); // 税耕 蒸走幻 益撹 蟹姦獣陥.
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
//	// 0. 琶推廃 依級
//	/*
//	蝶遣斗 姥繕端
//	- 送穣 舛左 // 送穣拭 魚献 端径引 因維径戚 痕井戚虞 段奄鉢研 嬢恐 号縦生稽 背操醤馬澗走...
//	- 薄仙, 置企 端径
//	- 因維径
//
//	佼什斗 姥繕端
//	- 戚硯 // 佼什斗人 旭精 井酔亀 食君 原軒研 幻球澗 依精 岨 巷軒亜 赤走 省蟹...
//	- 薄仙, 置企 端径
//	- 因維径
//	*/
//
//	// 1. class 衣舛
//
//	// 2.1 蝶遣斗 Status 窒径
//
//	//Player player = { "原狛紫", 150, 150, 20 };
//	//Monster monster = { "十虞績", 150, 150, 90 };
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
//		// 2.2 Menu 窒径 貢 識澱
//		printHomeMenu();
//		cout << "脊径: "; cin >> sel;
//
//		if (sel < 1 || sel>4) {
//			cout << "陥獣 脊径馬室推." << endl;
//			system("pause");
//			//contitnue;
//		}
//		else if (sel == 4) {
//
//			cout << "惟績聖 曽戟杯艦陥." << endl << endl;
//			return;
//		}
//
//
//		// 2.2.1 段厭 揮穿拭 魚献 佼什斗
//		// 2.2.2 掻厭 揮穿拭 魚献 佼什斗
//		// 2.2.3 壱厭 揮穿拭 魚献 佼什斗
//		// 2.2.4 textRPG 曽戟
//
//		// 3.1 蝶遣斗 Status, 佼什斗 Status 窒径
//		// 3.2 因維 or 亀諺 識澱.
//		// 3.3 穿燈 雌伐 毒舘
//		// 3.4.1 穿燈 衣引 硲窒_ 紫撹 失因!
//		// 3.4.2 穿燈 衣引 硲窒_ 紫撹 叔鳶!
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
//		BLOCK,   /*  0 : 猿諺 */
//		DARK_BLUE,  /*  1 : 嬢砧錘 督櫛 */
//		DARK_GREEN,  /*  2 : 嬢砧錘 段系 */
//		DARK_SKY_BLUE, /*  3 : 嬢砧錘 馬潅 */
//		DARK_RED,  /*  4 : 嬢砧錘 察悪 */
//		DARK_VOILET, /*  5 : 嬢砧錘 左虞 */
//		DARK_YELLOW, /*  6 : 嬢砧錘 葛櫛 */
//		GRAY,   /*  7 : 噺事 */
//		DARK_GRAY,  /*  8 : 嬢砧錘 噺事 */
//		BLUE,   /*  9 : 督櫛 */
//		GREEN,   /* 10 : 段系 */
//		SKY_BLUE,  /* 11 : 馬潅 */
//		RED,   /* 12 : 察悪 */
//		VOILET,   /* 13 : 左虞 */
//		YELLOW,   /* 14 : 葛櫛 */
//		WHITE,   /* 15 : 馬丞 */
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
//	cout << "穿紫";
//	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
//	cout << ", ";
//
//	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
//	cout << "2. ";
//	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
//	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
//	cout << "原狛紫";
//	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
//	cout << ", ";
//
//	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
//	cout << "3. ";
//	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
//	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
//	cout << "亀旋 ";
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
//		cout << "脊径: "; cin >> sel;
//		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
//
//		if (sel == 1) {
//			strcpy_s(player->className, sizeof(player->className), "穿紫");
//			player->currentHp = player->maxHp = 300;
//			player->damage = 50;
//			break;
//
//		}
//		else if (sel == 2) {
//			strcpy_s(player->className, sizeof(player->className), "原狛紫");
//			player->currentHp = player->maxHp = 80;
//			player->damage = 100;
//			break;
//
//		}
//		else if (sel == 3) {
//			strcpy_s(player->className, sizeof(player->className), "亀旋");
//			player->currentHp = player->maxHp = 120;
//			player->damage = 70;
//			break;
//		}
//		else {
//
//			cout << "\n設公吉 脊径脊艦陥." << endl << endl;
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
//	cout << "#   適掘什: [" << player.className << "]"; // 14
//	cout.width(30 - (14 + strlen(player.className)));
//	cout << "#" << endl;
//
//	cout << "#     端径: ["; // 13
//	cout.width(3); // 3
//	cout << player.currentHp << "/"; // 1
//	cout.width(3); // 3
//	cout << player.maxHp << "]"; // 1
//	cout.width(30 - 21);
//	cout << "#" << endl;
//
//	cout << "#   因維径: "; // 12
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
//	cout << "1.段厭, 2.掻厭, 3.壱厭, 4.曽戟" << endl;
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
//		cout << "陥獣 脊径馬室推." << endl << endl;
//		break;
//	}
//}
//
//// 段厭, 掻厭, 壱厭 揮穿聖 敗呪紺稽 蟹喚 琶推失戚 赤蟹 粛製.
//// 嬢託杷 照拭辞 呪楳馬澗 稽送精 搾汁廃汽...
//void beginnerDungeon(Player *player, Monster *monster) {
//
//	bool battleLoop = FALSE;
//
//	strcpy_s(monster->name, sizeof(monster->name), "十虞績");
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
//	strcpy_s(monster->name, sizeof(monster->name), "茨圭");
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
//	strcpy_s(monster->name, sizeof(monster->name), "燭球軒帖");
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
//		cout << "脊径: "; cin >> sel;
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
//	cout << "1. 因維, 2. 亀諺" << endl;
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
//	cout << "#   適掘什: [" << monster.name << "]"; // 14
//	cout.width(30 - (14 + strlen(monster.name)));
//	cout << "#" << endl;
//
//	cout << "#     端径: ["; // 13
//	cout.width(3); // 3
//	cout << monster.currentHp << "/"; // 1
//	cout.width(3); // 3
//	cout << monster.maxHp << "]"; // 1
//	cout.width(30 - 21);
//	cout << "#" << endl;
//
//	cout << "#   因維径: "; // 12
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
//			cout << "焼鴛惟亀..." << endl;
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
//		// 蟹哀掘 !!!
//		system("cls");
//		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
//		cout << "[" << player.className << "] 精/澗 亀諺 帖澗汽 失因梅柔艦陥." << endl << endl;
//		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
//		system("pause");
//
//		system("cls");
//		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
//		cout << "[" << monster.name << "]: 照掬! 宜焼人 !!!!" << endl << endl;
//		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
//		system("pause");
//
//		return TRUE;
//	}
//	else {
//		// 嬢渠 蟹亜?!
//		system("cls");
//		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
//		cout << "[" << player.className << "] 精/澗 亀諺 帖澗汽 叔鳶 梅柔艦陥." << endl << endl;
//		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
//		cout << "[" << player.className << "] : 焼艦 訊?!" << endl << endl;
//		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
//		system("pause");
//
//		system("cls");
//		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
//		cout << "[" << monster.name << "]: せせせせせせせ !!!!" << endl << endl;
//		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
//		system("pause");
//
//		return FALSE;
//	}
//
//	system("pause");
//}
//
//void printWinResult(const Monster monster) { // 税耕 蒸走幻 益撹 蟹姦獣陥.
//	cout << "[" << monster.name << "] 紫撹 失因 !!!" << endl << endl;
//	system("pause");
//}
//void printLoseResult(const Monster monster) {
//	cout << "[" << monster.name << "] 紫撹 叔鳶 ばば." << endl << endl;
//	system("pause");
//}