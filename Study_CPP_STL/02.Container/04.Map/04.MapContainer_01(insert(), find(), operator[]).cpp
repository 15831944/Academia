//#include <iostream>
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
//int main(void)
//{
//	// map 자료구조는 "Red-Black Tree"로 구현되어 있다.
//	map<int, int> intMap;
//
//	// "map<>::value_type()" & "pair<>()"
//	// 10 20
//	intMap.insert(map<int, int>::value_type(1, 10));
//	intMap.insert(pair<int, int>(2, 20));
//
//	// 특정 위치 추가.
//	map<int, int>::iterator iter = intMap.begin();
//	++iter;
//	++iter;
//	// 10 20 40 50
//	intMap.insert(iter, map<int, int>::value_type(4, 40));
//	intMap.insert(iter, pair<int, int>(5, 50));
//
//	// 다른 map 컨테이너의 원소 추가
//	map<int, int> intMap2;
//	
//	intMap2.emplace(2, 200);
//	intMap2.emplace(3, 300);
//	intMap2.emplace(4, 400); // 이미 있는 키라서, insert() 연산 수행 시, 무시됨.
//	intMap2.emplace(5, 500);
//	intMap2.emplace(6, 600);
//
//	map<int, int>::iterator iter2 = intMap2.begin();
//	++iter2;
//	map<int, int>::iterator iter2Find = intMap2.find(5);
//
//	// 10 20 300 40 50
//	intMap.insert(iter2, iter2Find);
//
//	// index 연산자를 이용한 추가.
//	// 10 20 300 40 50 60
//	intMap[6] = 60;
//
//	cout << "###################################################" << endl;
//	cout << "### 정상 출력" << endl;
//	iter = intMap.begin();
//	for (; iter != intMap.end(); ++iter)
//	{
//		cout << iter->second << " ";
//	}
//	cout << endl << endl;
//
//	cout << "### 역순 출력" << endl;
//	map<int, int>::reverse_iterator iterReverse = intMap.rbegin();
//	for (; iterReverse != intMap.rend(); ++iterReverse)
//	{
//		cout << iterReverse->second << " ";
//	}
//	cout << endl << endl;
//
//	return 0;
//}