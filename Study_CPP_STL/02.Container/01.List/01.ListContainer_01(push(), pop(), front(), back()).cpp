//#include <iostream>
//#include <list>
//
//#define TRUE true
//#define FALSE false
//
//using std::cout;
//using std::endl;
//
//using std::list;
//
//typedef struct tagItemInfo
//{
//	tagItemInfo(int itemCode)
//		: itemCode(itemCode)
//	{
//
//	}
//
//	int itemCode;
//} ITEM;
//
//int main(void)
//{
//	list<ITEM> itemList;
//
//	// "list containter"�� ��� ����
//	// 1
//	ITEM item1(1);
//	itemList.push_front(item1);
//
//	// 2 1
//	ITEM item2(2);
//	itemList.push_front(item2);
//
//	// 2 1 3
//	ITEM item3(3);
//	itemList.push_back(item3);
//
//	// 2 1 3 4
//	ITEM item4(4);
//	itemList.push_back(item4);
//
//	cout << "######## ���� ��� #######" << endl;
//	list<ITEM>::iterator iter = itemList.begin();
//	for (; iter != itemList.end(); ++iter)
//	{
//		cout << "������ �ڵ�: " << iter->itemCode << endl;
//	}
//	cout << endl;
//
//	cout << "######## ���� ��� #######" << endl;
//	list<ITEM>::reverse_iterator reverseIter = itemList.rbegin();
//	for (; reverseIter != itemList.rend(); ++reverseIter) // �������� ����ص� ������� �մϴ� !!!!
//	{
//		cout << "������ �ڵ�: " << reverseIter->itemCode << endl;
//	}
//	cout << endl;
//
//	cout << "######## pop_front() ���� ��, front() ��� #######" << endl;
//	itemList.pop_front();
//
//	// 1 3 4
//	ITEM frontItem = itemList.front();
//	cout << "������ �ڵ�: " << frontItem.itemCode << endl << endl;
//	
//	cout << "######## pop_back() ���� ��, back() ��� #######" << endl;
//	itemList.pop_back();
//
//	// 1 3
//	ITEM backItem = itemList.back();
//	cout << "������ �ڵ�: " << backItem.itemCode << endl << endl;
//
//	cout << "######## ���� ���� size_type ��� (size_t �ڷ���) #######" << endl;
//	if (itemList.empty() != TRUE)
//	{
//		list<ITEM>::size_type count = itemList.size(); // (size_t) �ڷ���
//		cout << "���� ����: " << count << endl << endl;
//	}
//
//	cout << "######## clear() ��� �Լ� #######" << endl;
//	itemList.clear();
//	// ���� "container"�� ���Ұ� �޸� ���� �Ҵ��� ������, �޸� ������ �ϰ� clear() �ؾ� !!!!
//	// clear() ��� �Լ��� �ܼ��� size()�� ���̴� ���Ҹ� �����Ѵ� !!!!
//	list<ITEM>::size_type count = itemList.size();
//
//	cout << "���� ����: " << count << endl << endl;
//
//
//	return 0;
//}