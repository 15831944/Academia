#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <functional>

using std::cout;
using std::endl;

using std::string;

using std::map;
using std::pair;

using std::find_if;

using std::greater;
using std::less;

typedef struct tagItem
{
	tagItem(char *name, int price)
		: price(price)
	{
		strcpy_s(this->name, sizeof(this->name), name);
	}

	char name[32];
	int price;

} ITEM;


class CharStrCmp
{
public:
	CharStrCmp(const char *strKey)
		: mStrKey(strKey)
	{

	}

public:
	template <typename T>
	bool operator() (T &dest)
	{
		return !(strcmp(dest.first, mStrKey));
	}

private:
	const char *mStrKey;
};

int main(void)
{
	// Key 값의 자료형으로 (char *) 자료형을 쓰면,
	// 문자열 비교가 아닌 주소 비교가 되므로, 원하는 결과를 얻지 못함.
	// Functor를 만들어서 처리하거나, string 객체를 사용하는 것이 한 방법임.

	cout << "######################################################" << endl;
	map<char *, ITEM> mapItem1;
	typedef pair<char *, ITEM> ITEMPAIR;

	ITEM item1 = ITEM("아이템1", 10);
	ITEM item2 = ITEM("아이템2", 20);
	ITEM item3 = ITEM("아이템3", 30);

	mapItem1.insert(map<char *, ITEM>::value_type(item1.name, item1));
	mapItem1.insert(ITEMPAIR(item2.name, item2));
	mapItem1.emplace(item3.name, item3);

	cout << "### 초기 상태" << endl;
	map<char *, ITEM>::iterator iter1 = mapItem1.begin();
	for (; iter1 != mapItem1.end(); ++iter1)
	{
		cout << "(" << iter1->second.name << ") - " << iter1->second.price << endl;
	}
	cout << endl;

	cout << "### find() 검색" << endl;
	iter1 = mapItem1.find("아이템1");
	// Key 값의 자료형으로 (char *) 자료형을 사용했을 때 나타나는 문제점 !!!!
	if (iter1 != mapItem1.end())
	{
		cout << "(" << iter1->second.name << ") - " << iter1->second.price << endl;
	}
	else
	{
		cout << "(아이템1)이 없습니다." << endl;
	}
	cout << endl;


	cout << "######################################################" << endl;
	cout << "해결 방법 1. 자료형 변경 - string" << endl;
	map<string, ITEM, less<string>> mapItem2;

	mapItem2.insert(map<string, ITEM>::value_type(item3.name, item3));
	mapItem2.insert(ITEMPAIR(item2.name, item2));
	mapItem2.emplace(item1.name, item1);

	map<string, ITEM>::iterator iter2 = mapItem2.begin();
	for (; iter2 != mapItem2.end(); ++iter2)
	{
		cout << "(" << iter2->second.name << ") - " << iter2->second.price << endl;
	}
	cout << endl;

	cout << "### find() 검색" << endl;
	iter2 = mapItem2.find("아이템1");
	// Key 값의 자료형으로 (char *) 자료형을 사용했을 때 나타나는 문제점 !!!!
	if (iter2 != mapItem2.end())
	{
		cout << "(" << iter2->second.name << ") - " << iter2->second.price << endl;
	}
	else
	{
		cout << "(아이템1)이 없습니다." << endl;
	}
	cout << endl;

	cout << "######################################################" << endl;
	cout << "해결 방법 2. find_if 알고리즘 함수, Functor 사용" << endl;
	
	iter1 = find_if(mapItem1.begin(), mapItem1.end(), CharStrCmp("아이템1"));

	if (iter1 != mapItem1.end())
	{
		cout << "(" << iter1->second.name << ") - " << iter1->second.price << endl;
	}
	else
	{
		cout << "(아이템1)이 없습니다." << endl;
	}
	cout << endl;
	

	cout << "######################################################" << endl;

	return 0;
}

