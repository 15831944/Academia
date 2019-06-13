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
//// 이미 정의된 "Predicate"은 "functional" 헤더파일에 !!!!
//using std::less;	// 오름차순
//using std::greater;	// 내림차순
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
//// Functor(함수 객체)
//template <typename T>
//class CompareItem : public std::binary_function <T, T, bool>
//{
//public:
//	bool operator() (const T lhs, const T rhs) const
//	{
//		// 부등호 "<" - 오름차순
//		// 부등호 ">" - 내림차순
//
//		// TRUE면, 변경 안함 !!!!
//		return lhs.itemCode < rhs.itemCode;
//
//		// "greater< >()"도 왼쪽 기준으로 크면 변경 안함 !!!!
//		// "less< >()"도 왼쪽 기준으로 작으면 변경 안함 !!!!
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
//	cout << "##### 오름 차순 sort() #####" << endl;
//	listInt.sort(); // 자동적으로 "less<int>()"가 들어있음.
//
//	list<int>::iterator iter = listInt.begin();
//	for (; iter != listInt.end(); ++iter)
//	{
//		cout << "list1: " << (*iter) << endl;
//	}
//	cout << endl;
//
//	cout << "##### 내림 차순 sort() #####" << endl;
//	listInt.sort(greater<int>());	// 오른쪽이 크면 바꾼다 !!!!
//									// 그래서 왼쪽이 큰 숫자, 오른쪽이 작은 숫자
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
//	cout << "##### (Functor)를 이용한 sort()" << endl;
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