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
//	multiMapItem.insert(multimap<int, ITEM>::value_type(10, ITEM("������1", 10)));
//	multiMapItem.emplace(20, ITEM("������2", 20));
//	multiMapItem.emplace(30, ITEM("������3", 30));
//	multiMapItem.emplace(40, ITEM("������4", 40));
//	multiMapItem.emplace(40, ITEM("������5", 40));
//	// Ű���� �ߺ��Ǿ� ������, ���� ������� ������ �ȴ� !!!!
//
//	multimap<int, ITEM>::iterator iter = multiMapItem.begin();
//	for (; iter != multiMapItem.end(); ++iter)
//	{
//		cout << "�̸�: " << iter->second.name << " / ";
//		cout << "����: " << iter->second.price << endl;
//	}
//	cout << endl;
//	return 0;
//}