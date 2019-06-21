//#include <iostream>
//#include <vector>
//#include <map>
//#include <algorithm>
//
//#include "CharStrCmp.h"
//
//using std::cout;
//using std::endl;
//using std::cin;
//
//using std::vector;
//using std::map;
//
//using std::pair;
//using std::make_pair;
//
//using std::find_if;
//
//
//int main(void)
//{
//	cout << "#####################################################################" << endl;
//	cout << "### find_if() 알고리즘 함수 - Predicate을 사용하여 (Good) 검색" << endl;
//	vector<const char *> charStrVec;
//
//	charStrVec.push_back("Hello");
//	charStrVec.push_back("World");
//	charStrVec.push_back("Good");
//	charStrVec.push_back("Day");
//
//	cout << "### case 1. 문자열을 입력해서 검색" << endl;
//	char str[16];
//	cout << "입력: ";
//	cin >> str;
//
//	vector<const char *>::iterator iter = find_if(charStrVec.begin(), charStrVec.end(), CharStrCmp(str));
//	if (iter != charStrVec.end())
//	{
//		cout << "###########" << endl;
//		cout << (*iter) << endl;
//		cout << "###########" << endl;
//	}
//	else
//	{
//		cout << "항목이 없습니다." << endl;
//	}
//	cout << endl;
//
//	cout << "### case 2. 문자열 상수를 넣어서 검색" << endl;
//	iter = find_if(charStrVec.begin(), charStrVec.end(), CharStrCmp("Good"));
//	if (iter != charStrVec.end())
//	{
//		cout << "@@@@@@@@@@@" << endl;
//		cout << (*iter) << endl;
//		cout << "@@@@@@@@@@@" << endl;
//	}
//	else
//	{
//		cout << "항목이 없습니다." << endl;
//	}
//	cout << endl;
//
//	cout << "###########################################################" << endl;
//	map<char *, int> mapItem;
//
//	mapItem.insert(pair<char *, int>("아이템2", 2));
//	mapItem.insert(map<char *, int>::value_type("아이템1", 1));
//
//	cout << "### 초기 상태" << endl;
//	map<char *, int>::iterator iter2 = mapItem.begin();
//	for (; iter2 != mapItem.end(); ++iter2)
//	{
//		cout << iter2->first << " / " << iter2->second << endl;
//	}
//	cout << endl;
//
//	cout << "### map 컨테이너의 find() 멤버 함수 (아이템1) 검색" << endl;
//
//	cout << "입력: ";
//	cin >> str;
//
//	iter2 = mapItem.find(str);
//	if (iter2 != mapItem.end())
//	{
//		cout << iter2->first << " / " << iter2->second << endl;
//	}
//	else
//	{
//		cout << "항목이 없습니다." << endl;
//	}
//	cout << endl;
//
//	iter2 = mapItem.find("아이템2");
//	if (iter2 != mapItem.end())
//	{
//		cout << iter2->first << " / " << iter2->second << endl;
//	}
//	else
//	{
//		cout << "항목이 없습니다." << endl;
//	}
//	cout << endl;
//
//	cout << "주소값을 비교하기 때문에 검색이 불가능..." << endl;
//	cout << "So, find_if() 알고리즘 함수 사용해야 함." << endl;
//
//	iter2 = find_if(mapItem.begin(), mapItem.end(), CharStrCmp(str));
//	if (iter2 != mapItem.end())
//	{
//		cout << iter2->first << " / " << iter2->second << endl;
//	}
//	else
//	{
//		cout << "항목이 없습니다." << endl;
//	}
//	cout << endl;
//
//	
//	return 0;
//}