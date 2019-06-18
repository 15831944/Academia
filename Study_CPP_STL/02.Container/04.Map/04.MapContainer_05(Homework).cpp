//#include <iostream>
//#include <map>
//#include <functional>
//
//using std::cout;
//using std::endl;
//
//using std::multimap;
//
//using std::greater;
//using std::less;
//
//typedef struct tagItem
//{
//	tagItem(char *name, int price)
//		: price(price)
//	{
//		strcpy_s(this->name, sizeof(this->name), name);
//	}
//
//	char name[32];
//	int price;
//
//} ITEM;
//
//int main(void)
//{
//	multimap<int, ITEM, greater<int>> multiMapItem;
//
//	multiMapItem.insert(multimap<int, ITEM>::value_type(10, ITEM("아이템1", 10)));
//	multiMapItem.emplace(20, ITEM("아이템2", 20));
//	multiMapItem.emplace(30, ITEM("아이템3", 30));
//	multiMapItem.emplace(40, ITEM("아이템4", 40));
//	multiMapItem.emplace(40, ITEM("아이템5", 40));
//	// 키값이 중복되어 있지만, 저장 순서대로 정렬이 된다 !!!!
//
//	multimap<int, ITEM>::iterator iter = multiMapItem.begin();
//	for (; iter != multiMapItem.end(); ++iter)
//	{
//		cout << "이름: " << iter->second.name << " / ";
//		cout << "가격: " << iter->second.price << endl;
//	}
//	cout << endl;
//	return 0;
//}