//#include <iostream>
//#include <list>
//
//using std::cout;
//using std::endl;
//
//using std::list;
//
//int main(void)
//{
//	list<int> listInt;
//
//	// 20
//	listInt.push_back(20);
//	// 20 30
//	listInt.push_back(30);
//
//
//	// ############################################################################
//	cout << "### insert() - ���� ��ġ ������ �߰� ###" << endl;
//	list<int>::iterator iterInsertPos = listInt.begin();
//	listInt.insert(iterInsertPos, 10);
//	// ###############################################
//	// insert() �Լ��� �߰��� ��ġ�� ���� ��ġ ��ȯ !!!!
//
//	// 10 20 30
//	iterInsertPos = listInt.begin();
//	for (; iterInsertPos != listInt.end(); ++iterInsertPos)
//	{
//		cout << "listInt: " << (*iterInsertPos) << endl; // Derefrencing�� ����� ����ִ� ������ Ȯ�� ����.
//	}
//	cout << endl;
//
//
//	// ############################################################################
//	cout << "### insert() - ���� ��ġ ������ (���� ��) �߰� ###" << endl;
//	iterInsertPos = listInt.begin();
//	++iterInsertPos;
//
//	// 10 40 40 20 30
//	listInt.insert(iterInsertPos, 2, 40);
//	// ###############################################
//	// insert() �Լ��� �߰��� ��ġ�� ���� ��ġ ��ȯ !!!!
//
//	iterInsertPos = listInt.begin();
//	for (; iterInsertPos != listInt.end(); ++iterInsertPos)
//	{
//		cout << "listInt: " << (*iterInsertPos) << endl; // Derefrencing�� ����� ����ִ� ������ Ȯ�� ����.
//	}
//	cout << endl;
//
//
//	// ############################################################################
//	cout << "### insert() - ���� ��ġ (�ٸ� ����Ʈ�� ������ ���� ��) �߰� ###" << endl;
//
//	list<int> listInt2;
//	listInt2.push_back(40);
//	listInt2.push_back(50);
//	listInt2.push_back(60);
//	listInt2.push_back(70);
//
//	iterInsertPos = listInt.begin(); // "10" ��ġ
//	++iterInsertPos; // "40' ��ġ
//	++iterInsertPos; // "40" ��ġ
//	++iterInsertPos; // "20" ��ġ (�� �ڸ��� �־�� "20"�� �ڷ� �и�)
//
//	// 10 40 40 50 60 20 30
//	listInt.insert(iterInsertPos, ++listInt2.begin(), --listInt2.end());
//	// ###############################################
//	// insert() �Լ��� �߰��� ��ġ�� ���� ��ġ ��ȯ !!!!
//
//	iterInsertPos = listInt.begin();
//	for (; iterInsertPos != listInt.end(); ++iterInsertPos)
//	{
//		cout << "listInt: " << (*iterInsertPos) << endl; // Derefrencing�� ����� ����ִ� ������ Ȯ�� ����.
//	}
//	cout << endl;
//
//	return 0;
//}