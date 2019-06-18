//#include <iostream>
//#include <functional>
//#include <map>
//
//#define TRUE true
//#define FALSE false
//
//using std::cout;
//using std::endl;
//
//using std::map;
//using std::pair;
//
//using std::greater;
//using std::less;
//
//int main(void)
//{
//	map<int, int> intMap; // default 오름차순
//	intMap.insert(map<int, int>::value_type(2, 20));
//	intMap.insert(map<int, int>::value_type(3, 30));
//	intMap.insert(map<int, int>::value_type(1, 10));
//
//	map<int, int, less<int>> intMap2; // less : 오름차순
//	intMap2.insert(pair<int, int>(2, 20));
//	intMap2.insert(pair<int, int>(3, 30));
//	intMap2.insert(pair<int, int>(1, 10));
//
//	map<int, int, greater<int>> intMap3; // greater : 내림차순
//	intMap3.emplace(2, 20);
//	intMap3.emplace(3, 30);
//	intMap3.emplace(1, 10);
//
//	cout << "##################################################" << endl;
//	cout << "### default" << endl;
//	map<int, int>::iterator iter = intMap.begin();
//	for (; iter != intMap.end(); ++iter)
//	{
//		cout << iter->second << " ";
//	}
//	cout << endl << endl;
//
//	cout << "### less<> predicate" << endl;
//	map<int, int, less<int>>::iterator iterLess = intMap2.begin();
//	for (; iterLess != intMap2.end(); ++iterLess)
//	{
//		cout << iterLess->second << " ";
//	}
//	cout << endl << endl;
//
//	cout << "### greater<> predicate" << endl;
//	map<int, int, greater<int>>::iterator iterGreater = intMap3.begin();
//	for (; iterGreater != intMap3.end(); ++iterGreater)
//	{
//		cout << iterGreater->second << " ";
//	}
//	cout << endl << endl;
//
//	return 0;
//}