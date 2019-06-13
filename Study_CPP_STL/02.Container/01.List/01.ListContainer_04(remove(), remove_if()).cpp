//#include <iostream>
//#include <list>
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
//
//// "Predicate"에 쓰일 함수 객체(Functor)
//template <typename T>
//class Is_AndOver20_Under30 : public std::unary_function <T, bool> // 단항 연산자의 역할 !!!!
//{
//public:
//	bool operator() (T &val)
//	{
//		return (val >= 20 && val < 30);
//	}
//};
//
//int main(void)
//{
//	// remove() 멤버 함수는 "값"을 통해서 일치한 모든 원소를 삭제합니다.
//
//	list<int> listInt;
//
//	// 10 20 20 30 40
//	listInt.push_back(10);
//	listInt.push_back(20);
//	listInt.push_back(20);
//	listInt.push_back(30);
//	listInt.push_back(40);
//
//	cout << "### remove() - (값)에 따른 해당 원소 모두 삭제" << endl;
//	listInt.remove(20);
//
//	list<int>::iterator iter = listInt.begin();
//	for (; iter != listInt.end(); ++iter)
//	{
//		cout << "list: " << (*iter) << endl;
//	}
//	cout << endl;
//
//	// ##########################################################################
//	cout << "###################################################" << endl << endl;
//
//	list<ITEM *> listItem;
//
//	ITEM *pItem1 = new ITEM(1); listItem.push_back(pItem1);
//	ITEM *pItem2 = new ITEM(2); listItem.push_back(pItem2); listItem.push_back(pItem2);
//	ITEM *pItem3 = new ITEM(3); listItem.push_back(pItem3);
//
//
//	// pItem1 pItem2 pItem2 pItem3
//	cout << "########## 초기 상태 ##########" << endl;
//	list<ITEM *>::iterator iterListItem = listItem.begin();
//	for (; iterListItem != listItem.end(); ++iterListItem)
//	{
//		cout << "아이템 코드: " << (*iterListItem)->itemCode << endl;
//	}
//	cout << endl;
//
//	cout << "### remove() - (포인터 값)에 따른 해당 원소 모두 삭제" << endl;
//	listItem.remove(pItem2);
//
//	iterListItem = listItem.begin();
//	for (; iterListItem != listItem.end(); ++iterListItem)
//	{
//		cout << "아이템 코드: " << (*iterListItem)->itemCode << endl;
//	}
//	cout << endl;
//
//	delete pItem1;
//	delete pItem2;
//	delete pItem3;
//
//	// ##########################################################################
//	cout << "###################################################" << endl << endl;
//
//
//	list<int> listInt2;
//	
//	// 15 20 25 30 35
//	listInt2.push_back(15);
//	listInt2.push_back(20);
//	listInt2.push_back(25);
//	listInt2.push_back(30);
//	listInt2.push_back(35);
//
//	cout << "########## 초기 상태 ##########" << endl;
//	list<int>::iterator iter2 = listInt2.begin();
//	for (; iter2 != listInt2.end(); ++iter2)
//	{
//		cout << "list2: " << (*iter2) << endl;
//	}
//	cout << endl;
//
//	cout << "### remove_if() - Predicate(조건자)을 만족하는 모든 원소 삭제" << endl;
//	listInt2.remove_if(Is_AndOver20_Under30<int>());
//
//	iter2 = listInt2.begin();
//	for (; iter2 != listInt2.end(); ++iter2)
//	{
//		cout << "list2: " << (*iter2) << endl;
//	}
//	cout << endl;
//
//	return 0;
//}