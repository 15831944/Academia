//#include <iostream>
//#include <set>
//#include <functional>
//
//using std::cout;
//using std::endl;
//
//using std::set;
//
//using std::greater; // Descending order
//using std::less;	// Ascending order
//
//
//int main(void)
//{
//	set<int> setInt1;
//	setInt1.insert(10);
//	setInt1.insert(20);
//	setInt1.insert(15);
//	setInt1.insert(30);
//	setInt1.insert(25);
//
//	cout << "###########################################################" << endl;
//	cout << "### �ʱ� ���� - Key ������ �ڵ� ����" << endl;
//
//	// 10 15 20 25 30
//	set<int>::iterator iter = setInt1.begin();
//	for (; iter != setInt1.end(); ++iter)
//	{
//		cout << (*iter) << " ";
//	}
//	cout << endl << endl;
//
//	cout << "### ���� ���" << endl;
//	// 30 25 20 15 10
//	set<int>::reverse_iterator iterReverse = setInt1.rbegin();
//	for (; iterReverse != setInt1.rend(); ++iterReverse)
//	{
//		cout << (*iterReverse) << " ";
//	}
//	cout << endl << endl;
//
//	cout << "###########################################################" << endl;
//	cout << "### insert() - �߰� ��ġ�� Key �� (35) �߰�" << endl;
//	iter = setInt1.begin();
//	++iter;
//	++iter;
//
//	setInt1.insert(iter, 35);
//
//	// 10 15 20 25 30 35
//	iter = setInt1.begin();
//	for (; iter != setInt1.end(); ++iter)
//	{
//		cout << (*iter) << " ";
//	}
//	cout << endl << endl;
//
//	cout << "###########################################################" << endl;
//	cout << "### find() - Key ������ �˻�" << endl << endl;
//
//	//set<int, greater<int>> setInt2;
//	set<int> setInt2;
//
//	setInt2.insert(10);
//	setInt2.insert(20);
//	setInt2.insert(30);
//
//	cout << "### �ʱ� ����" << endl;
//
//	// 30 20 10
//	set<int>::iterator iter2 = setInt2.begin();
//	for (; iter2 != setInt2.end(); ++iter2)
//	{
//		cout << (*iter2) << " ";
//	}
//	cout << endl << endl;
//
//	set<int>::iterator iterFind = setInt2.find(20);
//	if (iterFind != setInt2.end())
//	{
//		cout << "���� �ȵǴµ�?!" << endl;
//		cout << (*iterFind) << endl;
//	}
//	cout << endl;
//
//	cout << "###########################################################" << endl;
//
//	return 0;
//}