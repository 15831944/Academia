//#include <iostream>
//#include <unordered_map>
//
//#define TRUE true
//#define FALSE false
//
//using std::cout;
//using std::endl;
//
//using std::unordered_map;
//
//typedef struct tagCharacterInfo
//{
//	tagCharacterInfo() {}
//
//	tagCharacterInfo(int charCode, int level)
//		: charCode(charCode), level(level)
//	{
//
//	}
//
//	int charCode;
//	int level;
//
//} CHARACTERINFO;
//
//
//int main(void)
//{
//	unordered_map<int, CHARACTERINFO> charUMap;
//
//	CHARACTERINFO char1(10, 1);
//	CHARACTERINFO char2(20, 2);
//	CHARACTERINFO char3(30, 3);
//	CHARACTERINFO char4(40, 4);
//	CHARACTERINFO char5(50, 5);
//
//	charUMap.insert(unordered_map<int, CHARACTERINFO>::value_type(10, char1));
//	charUMap.insert(unordered_map<int, CHARACTERINFO>::value_type(20, char2));
//	charUMap.insert(unordered_map<int, CHARACTERINFO>::value_type(30, char3));
//	charUMap.insert(unordered_map<int, CHARACTERINFO>::value_type(40, char4));
//	charUMap.insert(unordered_map<int, CHARACTERINFO>::value_type(50, char5));
//
//	cout << "#####################################################" << endl;
//	cout << "### �ʱ� ���� - ���� ���� unordered !!!!" << endl;
//
//	// 50 10 20 30 40
//	unordered_map<int, CHARACTERINFO>::iterator iter = charUMap.begin();
//	for (; iter != charUMap.end(); ++iter)
//	{
//		cout << "ĳ���� �ڵ�: " << iter->second.charCode << " / ����: " << iter->second.level << endl;
//	}
//	cout << endl;
//
//	cout << "#####################################################" << endl;
//	cout << "### lower_bound() - �ش� Ű��(20)�� �ݺ���. " << endl;
//	iter = charUMap.lower_bound(20);
//	cout << "ĳ���� �ڵ�: " << iter->second.charCode << " / ����: " << iter->second.level << endl;
//	cout << endl;
//
//	cout << "#####################################################" << endl;
//	cout << "### upper_bound() - �ش� Ű��(20)�� ������(30)�� �ݺ���. " << endl;
//	iter = charUMap.upper_bound(20);
//	cout << "ĳ���� �ڵ�: " << iter->second.charCode << " / ����: " << iter->second.level << endl;
//	cout << endl;
//
//	return 0;
//}