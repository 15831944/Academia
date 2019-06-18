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
//
//int main(void)
//{
//	map<int, int> intMap;
//
//	intMap.insert(map<int, int>::value_type(1, 10));
//	intMap.insert(map<int, int>::value_type(2, 20));
//	intMap.insert(map<int, int>::value_type(3, 30));
//	intMap.insert(pair<int, int>(4, 40));
//	intMap.insert(pair<int, int>(5, 50));
//	intMap.emplace(6, 60);
//	intMap.emplace(7, 70);
//
//	cout << "################################################" << endl;
//	cout << "### �ʱ� ����" << endl;
//	map<int, int>::iterator iter = intMap.begin();
//	for (; iter != intMap.end(); ++iter)
//	{
//		cout << iter->second << " ";
//	}
//	cout << endl << endl;
//
//	cout << "################################################" << endl;
//	cout << "### erase() - ���� �� �� ����(�ݺ���) 2(20)" << endl;
//	iter = intMap.begin();
//	++iter;
//
//	intMap.erase(iter);
//
//	iter = intMap.begin();
//	for (; iter != intMap.end(); ++iter)
//	{
//		cout << iter->second << " ";
//	}
//	cout << endl << endl;
//
//	cout << "################################################" << endl;
//	cout << "### erase() - ���� ���� �� ����(�ݺ���) 4(40) 5(50)" << endl;
//	iter = intMap.find(4); // Ű������ �˻� !!!!
//	iter = intMap.lower_bound(4); // ���� ���� !!!!
//
//	map<int, int>::iterator iterEnd = intMap.upper_bound(5);
//
//	intMap.erase(iter, iterEnd);
//	
//	iter = intMap.begin();
//	for (; iter != intMap.end(); ++iter)
//	{
//		cout << iter->second << " ";
//	}
//	cout << endl << endl;
//
//	cout << "################################################" << endl;
//	cout << "### erase() - Ű���� ���� ���� ���� 7(70)" << endl;
//	intMap.erase(7);
//
//	iter = intMap.begin();
//	for (; iter != intMap.end(); ++iter)
//	{
//		cout << iter->second << " ";
//	}
//	cout << endl << endl;
//
//	return 0;
//}