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
//	cout << "#######################################################" << endl;
//	cout << "### �ʱ� ����" << endl;
//
//	for (size_t i = 0; i < intDeque1.size(); ++i)
//	{
//		cout << intDeque1[i] << " ";
//	}
//	cout << endl << endl;
//
//	cout << "#######################################################" << endl;
//	cout << "### assign() - ���� ������ Vector Container ä���" << endl;
//
//	intDeque1.assign(3, 5); // ������ 3�� ���� �ǵ�, ���� 5...
//
//	// 5 5 5
//	for (size_t i = 0; i < intDeque1.size(); ++i)
//	{
//		cout << intDeque1[i] << " ";
//	}
//	cout << endl << endl;
//
//	cout << "#######################################################" << endl;
//	cout << "### assign() - �ٸ� Vector Container ������ ��ü�ϱ�" << endl;
//
//	deque<int> intDeque2;
//
//	intDeque2.push_back(10);
//	intDeque2.push_back(20);
//	intDeque2.push_back(30);
//	intDeque2.push_back(40);
//	intDeque2.push_back(50);
//	intDeque2.push_back(60);
//
//	intDeque1.assign(intDeque2.begin() + 1, intDeque2.end() - 1);
//
//	deque<int>::iterator iter = intDeque1.begin();
//	for (; iter != intDeque1.end(); ++iter)
//	{
//		cout << (*iter) << " ";
//	}
//	cout << endl << endl;
//
//	return 0;
//}