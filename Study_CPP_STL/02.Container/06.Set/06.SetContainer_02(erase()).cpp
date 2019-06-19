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
//	setInt1.insert(40);
//	setInt1.insert(35);
//
//	cout << "################################################" << endl;
//	cout << "### �ʱ� ����" << endl;
//
//	// 10 15 20 25 30 35 40
//	set<int>::iterator iter = setInt1.begin();
//	for (; iter != setInt1.end(); ++iter)
//	{
//		cout << (*iter) << " ";
//	}
//	cout << endl << endl;
//
//	cout << "################################################" << endl;
//	cout << "### erase() - ���� �� �� ����(�ݺ���) 15" << endl;
//	
//	iter = setInt1.begin();
//	++iter;
//
//	setInt1.erase(iter);
//
//	// 10 20 25 30 35 40
//	iter = setInt1.begin();
//	for (; iter != setInt1.end(); ++iter)
//	{
//		cout << (*iter) << " ";
//	}
//	cout << endl << endl;
//
//
//	cout << "################################################" << endl;
//	cout << "### erase() - ���� ���� �� ����(�ݺ���) 20 25" << endl;
//
//	iter = setInt1.begin();
//	++iter;
//
//	set<int>::iterator iterEnd = iter;
//	++iterEnd;
//	++iterEnd;
//
//	setInt1.erase(iter, iterEnd);
//
//	// 10 30 35 40
//	iter = setInt1.begin();
//	for (; iter != setInt1.end(); ++iter)
//	{
//		cout << (*iter) << " ";
//	}
//	cout << endl << endl;
//
//	cout << "################################################" << endl;
//	cout << "### erase() - Ű���� ���� ���� ���� 35" << endl;
//
//	setInt1.erase(35);
//
//	// 10 30 40
//	iter = setInt1.begin();
//	for (; iter != setInt1.end(); ++iter)
//	{
//		cout << (*iter) << " ";
//	}
//	cout << endl << endl;
//
//	cout << "################################################" << endl;
//
//	return 0;
//}