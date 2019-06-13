//#include <iostream>
//#include <list>
//
//using std::cout;
//using std::endl;
//
//using std::list;
//
//
//int main(void)
//{
//	list<int> listint;
//
//	// 10 20 30 40 50
//	listint.push_back(10);
//	listint.push_back(20);
//	listint.push_back(30);
//	listint.push_back(40);
//	listint.push_back(50);
//
//	// #########################################################################
//	cout << "### erase() - 지정된 (위치)의 원소 삭제 ###" << endl;
//	listint.erase(listint.begin());
//
//	// 20 30 40 50
//	list<int>::iterator iter = listint.begin();
//	for (; iter != listint.end(); ++iter)
//	{
//		cout << "list: " << (*iter) << endl;
//	}
//	cout << endl;
//
//	// #########################################################################
//	cout << "### erase() - 지정된 (범위)의 원소 삭제 ###" << endl;
//
//	iter = listint.begin();
//	++iter; // 두 번째 위치에서 부터 모든 원소 삭제하기...
//	listint.erase(iter, listint.end());
//
//	// 20
//	iter = listint.begin();
//	for (; iter != listint.end(); ++iter)
//	{
//		cout << "list: " << (*iter) << endl;
//	}
//	cout << endl;
//
//
//	// #########################################################################
//	cout << "### erase() - 원소 삭제 시, iterator 무효화 문제 ###" << endl;
//	list<int> listint2;
//
//	// 1 2 3 4 5
//	listint2.push_back(1);
//	listint2.push_back(2);
//	listint2.push_back(3);
//	listint2.push_back(4);
//	listint2.push_back(5);
//
//	list<int>::iterator iter2 = listint2.begin();
//	for (; iter2 != listint2.end(); )
//	{
//		if ((*iter2) % 2 == 0)
//		{
//			iter2 = listint2.erase(iter2);
//			// ##########################################
//			// erase() 멤버 함수는 삭제한 다음 위치의 원소를 가리킨다 !!!!
//		}
//		else
//		{
//			++iter2;
//		}
//	}
//
//	// 1 3 5
//	iter2 = listint2.begin();
//	for (; iter2 != listint2.end(); ++iter2)
//	{
//		cout << "list2: " << (*iter2) << endl;
//	}
//	cout << endl;
//
//	return 0;
//}