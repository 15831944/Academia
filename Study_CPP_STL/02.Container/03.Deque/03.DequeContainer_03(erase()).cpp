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
//
//int main(void)
//{
//	deque<int> intDeque;
//
//	intDeque.push_back(3);
//	intDeque.push_back(4);
//	intDeque.push_back(5);
//
//	intDeque.push_front(2);
//	intDeque.push_front(1);
//
//	cout << "#############################################################" << endl;
//	cout << "### �ʱ� ����" << endl;
//
//	// 1 2 3 4 5
//	deque<int>::iterator iter = intDeque.begin();
//	for (; iter != intDeque.end(); ++iter)
//	{
//		cout << (*iter) << " ";
//	}
//	cout << endl << endl;
//
//	cout << "#############################################################" << endl;
//	cout << "### erase() - ������ (��ġ)�� ���� ���� ###" << endl;
//
//	iter = intDeque.begin();
//	iter += 2;
//	intDeque.erase(iter);
//
//	// 1 2 4 5
//	iter = intDeque.begin();
//	for (; iter != intDeque.end(); ++iter)
//	{
//		cout << (*iter) << " ";
//	}
//	cout << endl << endl;
//
//	cout << "#############################################################" << endl;
//	cout << "### erase() - ������ (����)�� ���� ���� ###" << endl;
//
//	intDeque.erase(intDeque.begin() + 1, intDeque.end() - 1);
//
//	// 1 5
//	for (size_t i = 0; i < intDeque.size(); ++i)
//	{
//		cout << intDeque[i] << " ";
//	}
//	cout << endl << endl;
//
//	cout << "#############################################################" << endl;
//	cout << "### erase() - ���� ���� ��, iterator ��ȿȭ ���� ###" << endl;
//
//	deque<int> intDeque2;
//
//	// 1 2 3 4 5
//	intDeque2.push_back(1);
//	intDeque2.push_back(2);
//	intDeque2.push_back(3);
//	intDeque2.push_back(4);
//	intDeque2.push_back(5);
//
//	deque<int>::iterator iter2 = intDeque2.begin();
//	for (; iter2 != intDeque2.end();)
//	{
//		if ((*iter2) % 2 == 0)
//		{
//			iter2 = intDeque2.erase(iter2);
//		}
//		else
//		{
//			++iter2;
//		}
//	}
//
//	// 1 3 5
//	iter2 = intDeque2.begin();
//	for (; iter2 != intDeque2.end(); ++iter2)
//	{
//		cout << (*iter2) << " ";
//	}
//	cout << endl << endl;
//
//
//
//	return 0;
//}