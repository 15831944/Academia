//#include <iostream>
//#include <set>
//
//#define SAFE_DELETE(p) if(p) { delete p; p = nullptr; }
//
//using std::cout;
//using std::endl;
//
//using std::set;
//
//class Player
//{
//public:
//	Player(int level)
//		: mLevel(level)
//	{}
//	~Player() {}
//
//	int mLevel;
//};
//
//template <typename T>
//class LevelCmp
//{
//public:
//	bool operator() (const T &pPlayer1, const T &pPlayer2) const
//	{
//		return pPlayer1->mLevel > pPlayer2->mLevel;
//	}
//};
//
//int main(void)
//{
//	set<Player *, LevelCmp<Player *>> setPlayer1;
//
//	Player *pPlayer1 = new Player(10);
//	setPlayer1.insert(pPlayer1);
//	Player *pPlayer2 = new Player(20);
//	setPlayer1.insert(pPlayer2);
//	Player *pPlayer3 = new Player(30);
//	setPlayer1.insert(pPlayer3);
//	Player *pPlayer4 = new Player(40);
//	setPlayer1.insert(pPlayer4);
//
//	cout << "###############################################" << endl;
//	cout << "### 초기 상태" << endl;
//	set<Player *>::iterator iter = setPlayer1.begin();
//	for (; iter != setPlayer1.end(); ++iter)
//	{
//		cout << (*iter)->mLevel << " ";
//	}
//	cout << endl << endl;
//
//	cout << "###############################################" << endl;
//	cout << "### find() - 검색 후, 객체 삭제 해보기" << endl << endl;
//
//	set<Player *>::iterator iterFind = setPlayer1.find(pPlayer3);
//	if (iterFind != setPlayer1.end())
//	{
//		cout << "pPlayer3를 찾았습니다." << endl;
//		cout << "--- pPlayer3 삭제" << endl;
//
//		// #######################################################
//		// set에서 객체를 받은 다음 지울 수는 없나?!
//		// iterator를 dereferencing 해서 지울 수가 없어서...
//		SAFE_DELETE(pPlayer3);
//		setPlayer1.erase(iterFind);
//		// #######################################################
//	}
//	else
//	{
//		cout << "pPlayer3를 못 찾았습니다." << endl;
//	}
//	cout << endl;
//
//	cout << "### 삭제 후, 출력" << endl;
//	iter = setPlayer1.begin();
//	for (; iter != setPlayer1.end(); ++iter)
//	{
//		cout << (*iter)->mLevel << " ";
//	}
//	cout << endl << endl;
//
//	SAFE_DELETE(pPlayer1);
//	SAFE_DELETE(pPlayer2);
//	SAFE_DELETE(pPlayer3);
//	SAFE_DELETE(pPlayer4);
//
//	return 0;
//}