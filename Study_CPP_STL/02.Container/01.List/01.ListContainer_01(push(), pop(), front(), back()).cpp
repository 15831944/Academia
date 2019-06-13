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
//	// "list containter"에 담긴 순서
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
//	cout << "######## 정상 출력 #######" << endl;
//	list<ITEM>::iterator iter = itemList.begin();
//	for (; iter != itemList.end(); ++iter)
//	{
//		cout << "아이템 코드: " << iter->itemCode << endl;
//	}
//	cout << endl;
//
//	cout << "######## 역순 출력 #######" << endl;
//	list<ITEM>::reverse_iterator reverseIter = itemList.rbegin();
//	for (; reverseIter != itemList.rend(); ++reverseIter) // 역순으로 사용해도 더해줘야 합니다 !!!!
//	{
//		cout << "아이템 코드: " << reverseIter->itemCode << endl;
//	}
//	cout << endl;
//
//	cout << "######## pop_front() 연산 후, front() 출력 #######" << endl;
//	itemList.pop_front();
//
//	// 1 3 4
//	ITEM frontItem = itemList.front();
//	cout << "아이템 코드: " << frontItem.itemCode << endl << endl;
//	
//	cout << "######## pop_back() 연산 후, back() 출력 #######" << endl;
//	itemList.pop_back();
//
//	// 1 3
//	ITEM backItem = itemList.back();
//	cout << "아이템 코드: " << backItem.itemCode << endl << endl;
//
//	cout << "######## 원소 개수 size_type 멤버 (size_t 자료형) #######" << endl;
//	if (itemList.empty() != TRUE)
//	{
//		list<ITEM>::size_type count = itemList.size(); // (size_t) 자료형
//		cout << "원소 개수: " << count << endl << endl;
//	}
//
//	cout << "######## clear() 멤버 함수 #######" << endl;
//	itemList.clear();
//	// 만약 "container"의 원소가 메모리 동적 할당한 멤버라면, 메모리 해제를 하고 clear() 해야 !!!!
//	// clear() 멤버 함수는 단순히 size()를 줄이는 역할만 수행한다 !!!!
//	list<ITEM>::size_type count = itemList.size();
//
//	cout << "원소 개수: " << count << endl << endl;
//
//
//	return 0;
//}