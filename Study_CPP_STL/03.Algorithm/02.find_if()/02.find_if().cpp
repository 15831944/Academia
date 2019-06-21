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
//	cout << "### find_if() �˰��� �Լ� - Predicate�� ����Ͽ� (Good) �˻�" << endl;
//	vector<const char *> charStrVec;
//
//	charStrVec.push_back("Hello");
//	charStrVec.push_back("World");
//	charStrVec.push_back("Good");
//	charStrVec.push_back("Day");
//
//	cout << "### case 1. ���ڿ��� �Է��ؼ� �˻�" << endl;
//	char str[16];
//	cout << "�Է�: ";
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
//		cout << "�׸��� �����ϴ�." << endl;
//	}
//	cout << endl;
//
//	cout << "### case 2. ���ڿ� ����� �־ �˻�" << endl;
//	iter = find_if(charStrVec.begin(), charStrVec.end(), CharStrCmp("Good"));
//	if (iter != charStrVec.end())
//	{
//		cout << "@@@@@@@@@@@" << endl;
//		cout << (*iter) << endl;
//		cout << "@@@@@@@@@@@" << endl;
//	}
//	else
//	{
//		cout << "�׸��� �����ϴ�." << endl;
//	}
//	cout << endl;
//
//	cout << "###########################################################" << endl;
//	map<char *, int> mapItem;
//
//	mapItem.insert(pair<char *, int>("������2", 2));
//	mapItem.insert(map<char *, int>::value_type("������1", 1));
//
//	cout << "### �ʱ� ����" << endl;
//	map<char *, int>::iterator iter2 = mapItem.begin();
//	for (; iter2 != mapItem.end(); ++iter2)
//	{
//		cout << iter2->first << " / " << iter2->second << endl;
//	}
//	cout << endl;
//
//	cout << "### map �����̳��� find() ��� �Լ� (������1) �˻�" << endl;
//
//	cout << "�Է�: ";
//	cin >> str;
//
//	iter2 = mapItem.find(str);
//	if (iter2 != mapItem.end())
//	{
//		cout << iter2->first << " / " << iter2->second << endl;
//	}
//	else
//	{
//		cout << "�׸��� �����ϴ�." << endl;
//	}
//	cout << endl;
//
//	iter2 = mapItem.find("������2");
//	if (iter2 != mapItem.end())
//	{
//		cout << iter2->first << " / " << iter2->second << endl;
//	}
//	else
//	{
//		cout << "�׸��� �����ϴ�." << endl;
//	}
//	cout << endl;
//
//	cout << "�ּҰ��� ���ϱ� ������ �˻��� �Ұ���..." << endl;
//	cout << "So, find_if() �˰��� �Լ� ����ؾ� ��." << endl;
//
//	iter2 = find_if(mapItem.begin(), mapItem.end(), CharStrCmp(str));
//	if (iter2 != mapItem.end())
//	{
//		cout << iter2->first << " / " << iter2->second << endl;
//	}
//	else
//	{
//		cout << "�׸��� �����ϴ�." << endl;
//	}
//	cout << endl;
//
//	
//	return 0;
//}