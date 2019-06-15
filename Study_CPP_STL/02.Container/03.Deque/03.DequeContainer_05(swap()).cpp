//#include <iostream>
//#include <deque>
//
//#define TRUE true
//#define FALSE false
//
//using std::cout;
//using std::endl;
//
//using std::deque;
//
//int main(void)
//{
//	deque<int> intDeque1;
//
//	intDeque1.push_back(1);
//	intDeque1.push_back(2);
//	intDeque1.push_back(3);
//
//
//	deque<int> intDeque2;
//
//	intDeque2.push_back(5);
//	intDeque2.push_back(6);
//	intDeque2.push_back(7);
//	intDeque2.push_back(8);
//	intDeque2.push_back(9);
//
//	cout << "### 초기 상태" << endl;
//	cout << "intDeque1: ";
//	for (size_t i = 0; i < intDeque1.size(); ++i)
//	{
//		cout << intDeque1[i] << " ";
//	}
//	cout << endl;
//
//	cout << "intDeque2: ";
//	deque<int>::iterator iter2 = intDeque2.begin();
//	for (; iter2 != intDeque2.end(); ++iter2)
//	{
//		cout << (*iter2) << " ";
//	}
//	cout << endl << endl;
//
//
//	cout << "### swap() 멤버 함수 수행 후" << endl;
//
//	//intDeque1.swap(intDeque2);
//	intDeque2.swap(intDeque1);
//
//	cout << "intDeque1: ";
//	for (size_t i = 0; i < intDeque1.size(); ++i)
//	{
//		cout << intDeque1[i] << " ";
//	}
//	cout << endl;
//
//	cout << "intDeque2: ";
//	iter2 = intDeque2.begin();
//	for (; iter2 != intDeque2.end(); ++iter2)
//	{
//		cout << (*iter2) << " ";
//	}
//	cout << endl << endl;
//
//	return 0;
//}