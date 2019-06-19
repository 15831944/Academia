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
//	cout << "### �ʱ� ����" << endl;
//	set<Player *>::iterator iter = setPlayer1.begin();
//	for (; iter != setPlayer1.end(); ++iter)
//	{
//		cout << (*iter)->mLevel << " ";
//	}
//	cout << endl << endl;
//
//	cout << "###############################################" << endl;
//	cout << "### find() - �˻� ��, ��ü ���� �غ���" << endl << endl;
//
//	set<Player *>::iterator iterFind = setPlayer1.find(pPlayer3);
//	if (iterFind != setPlayer1.end())
//	{
//		cout << "pPlayer3�� ã�ҽ��ϴ�." << endl;
//		cout << "--- pPlayer3 ����" << endl;
//
//		// #######################################################
//		// set���� ��ü�� ���� ���� ���� ���� ����?!
//		// iterator�� dereferencing �ؼ� ���� ���� ���...
//		SAFE_DELETE(pPlayer3);
//		setPlayer1.erase(iterFind);
//		// #######################################################
//	}
//	else
//	{
//		cout << "pPlayer3�� �� ã�ҽ��ϴ�." << endl;
//	}
//	cout << endl;
//
//	cout << "### ���� ��, ���" << endl;
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