//#include <iostream>
//#include <list>
//
//#include <functional>
//
//using std::cout;
//using std::endl;
//
//using std::list;
//
//// �̹� ���ǵ� "Predicate"�� "functional" ������Ͽ� !!!!
//using std::less;	// ��������
//using std::greater;	// ��������
//
//
//typedef struct tagItemInfo
//{
//	tagItemInfo(int itemCode, int price)
//		: itemCode(itemCode), price(price)
//	{
//
//	}
//
//	int itemCode;
//	int price;
//} ITEM;
//
//
//// Functor(�Լ� ��ü)
//template <typename T>
//class CompareItem : public std::binary_function <T, T, bool>
//{
//public:
//	bool operator() (const T lhs, const T rhs) const
//	{
//		// �ε�ȣ "<" - ��������
//		// �ε�ȣ ">" - ��������
//
//		// TRUE��, ���� ���� !!!!
//		return lhs.itemCode < rhs.itemCode;
//
//		// "greater< >()"�� ���� �������� ũ�� ���� ���� !!!!
//		// "less< >()"�� ���� �������� ������ ���� ���� !!!!
//	}
//
//
//};
//
//
//int main(void)
//{
//	list<int> listInt;
//
//	listInt.push_back(30);
//	listInt.push_back(20);
//	listInt.push_back(10);
//	listInt.push_back(40);
//	listInt.push_back(50);
//
//	cout << "##### ���� ���� sort() #####" << endl;
//	listInt.sort(); // �ڵ������� "less<int>()"�� �������.
//
//	list<int>::iterator iter = listInt.begin();
//	for (; iter != listInt.end(); ++iter)
//	{
//		cout << "list1: " << (*iter) << endl;
//	}
//	cout << endl;
//
//	cout << "##### ���� ���� sort() #####" << endl;
//	listInt.sort(greater<int>());	// �������� ũ�� �ٲ۴� !!!!
//									// �׷��� ������ ū ����, �������� ���� ����
//
//	iter = listInt.begin();
//	for (; iter != listInt.end(); ++iter)
//	{
//		cout << "list1: " << (*iter) << endl;
//	}
//	cout << endl;
//
//	// ##########################################################################
//	cout << "###################################################" << endl << endl;
//
//	cout << "##### (Functor)�� �̿��� sort()" << endl;
//	
//	list<ITEM> listItem;
//
//	ITEM item2(20, 3000);  listItem.push_back(item2);
//	ITEM item1(10, 4000);  listItem.push_back(item1);
//	ITEM item3(30, 2000);  listItem.push_back(item3);
//	ITEM item4(40, 1000);  listItem.push_back(item4);
//
//
//	list<ITEM>::iterator iterItem = listItem.begin();
//	for (; iterItem != listItem.end(); ++iterItem)
//	{
//		cout << "Item: " << iterItem->itemCode << endl;
//	}
//
//	cout << "##############################################" << endl;
//	listItem.sort(CompareItem<ITEM>());
//
//	iterItem = listItem.begin();
//	for (; iterItem != listItem.end(); ++iterItem)
//	{
//		cout << "Item: " << iterItem->itemCode << endl;
//	}
//
//	return 0;
//}