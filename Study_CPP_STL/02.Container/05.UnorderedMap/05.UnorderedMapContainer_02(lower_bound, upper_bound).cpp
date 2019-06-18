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
//	cout << "### 초기 상태 - 저장 순서 unordered !!!!" << endl;
//
//	// 50 10 20 30 40
//	unordered_map<int, CHARACTERINFO>::iterator iter = charUMap.begin();
//	for (; iter != charUMap.end(); ++iter)
//	{
//		cout << "캐릭터 코드: " << iter->second.charCode << " / 레벨: " << iter->second.level << endl;
//	}
//	cout << endl;
//
//	cout << "#####################################################" << endl;
//	cout << "### lower_bound() - 해당 키값(20)의 반복자. " << endl;
//	iter = charUMap.lower_bound(20);
//	cout << "캐릭터 코드: " << iter->second.charCode << " / 레벨: " << iter->second.level << endl;
//	cout << endl;
//
//	cout << "#####################################################" << endl;
//	cout << "### upper_bound() - 해당 키값(20)의 다음값(30)의 반복자. " << endl;
//	iter = charUMap.upper_bound(20);
//	cout << "캐릭터 코드: " << iter->second.charCode << " / 레벨: " << iter->second.level << endl;
//	cout << endl;
//
//	return 0;
//}