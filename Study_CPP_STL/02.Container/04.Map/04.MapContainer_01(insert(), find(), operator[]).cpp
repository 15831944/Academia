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
//	// map �ڷᱸ���� "Red-Black Tree"�� �����Ǿ� �ִ�.
//	map<int, int> intMap;
//
//	// "map<>::value_type()" & "pair<>()"
//	// 10 20
//	intMap.insert(map<int, int>::value_type(1, 10));
//	intMap.insert(pair<int, int>(2, 20));
//
//	// Ư�� ��ġ �߰�.
//	map<int, int>::iterator iter = intMap.begin();
//	++iter;
//	++iter;
//	// 10 20 40 50
//	intMap.insert(iter, map<int, int>::value_type(4, 40));
//	intMap.insert(iter, pair<int, int>(5, 50));
//
//	// �ٸ� map �����̳��� ���� �߰�
//	map<int, int> intMap2;
//	
//	intMap2.emplace(2, 200);
//	intMap2.emplace(3, 300);
//	intMap2.emplace(4, 400); // �̹� �ִ� Ű��, insert() ���� ���� ��, ���õ�.
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
//	// index �����ڸ� �̿��� �߰�.
//	// 10 20 300 40 50 60
//	intMap[6] = 60;
//
//	cout << "###################################################" << endl;
//	cout << "### ���� ���" << endl;
//	iter = intMap.begin();
//	for (; iter != intMap.end(); ++iter)
//	{
//		cout << iter->second << " ";
//	}
//	cout << endl << endl;
//
//	cout << "### ���� ���" << endl;
//	map<int, int>::reverse_iterator iterReverse = intMap.rbegin();
//	for (; iterReverse != intMap.rend(); ++iterReverse)
//	{
//		cout << iterReverse->second << " ";
//	}
//	cout << endl << endl;
//
//	return 0;
//}