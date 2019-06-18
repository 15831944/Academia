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
	// Key ���� �ڷ������� (char *) �ڷ����� ����,
	// ���ڿ� �񱳰� �ƴ� �ּ� �񱳰� �ǹǷ�, ���ϴ� ����� ���� ����.
	// Functor�� ���� ó���ϰų�, string ��ü�� ����ϴ� ���� �� �����.

	cout << "######################################################" << endl;
	map<char *, ITEM> mapItem1;
	typedef pair<char *, ITEM> ITEMPAIR;

	ITEM item1 = ITEM("������1", 10);
	ITEM item2 = ITEM("������2", 20);
	ITEM item3 = ITEM("������3", 30);

	mapItem1.insert(map<char *, ITEM>::value_type(item1.name, item1));
	mapItem1.insert(ITEMPAIR(item2.name, item2));
	mapItem1.emplace(item3.name, item3);

	cout << "### �ʱ� ����" << endl;
	map<char *, ITEM>::iterator iter1 = mapItem1.begin();
	for (; iter1 != mapItem1.end(); ++iter1)
	{
		cout << "(" << iter1->second.name << ") - " << iter1->second.price << endl;
	}
	cout << endl;

	cout << "### find() �˻�" << endl;
	iter1 = mapItem1.find("������1");
	// Key ���� �ڷ������� (char *) �ڷ����� ������� �� ��Ÿ���� ������ !!!!
	if (iter1 != mapItem1.end())
	{
		cout << "(" << iter1->second.name << ") - " << iter1->second.price << endl;
	}
	else
	{
		cout << "(������1)�� �����ϴ�." << endl;
	}
	cout << endl;


	cout << "######################################################" << endl;
	cout << "�ذ� ��� 1. �ڷ��� ���� - string" << endl;
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

	cout << "### find() �˻�" << endl;
	iter2 = mapItem2.find("������1");
	// Key ���� �ڷ������� (char *) �ڷ����� ������� �� ��Ÿ���� ������ !!!!
	if (iter2 != mapItem2.end())
	{
		cout << "(" << iter2->second.name << ") - " << iter2->second.price << endl;
	}
	else
	{
		cout << "(������1)�� �����ϴ�." << endl;
	}
	cout << endl;

	cout << "######################################################" << endl;
	cout << "�ذ� ��� 2. find_if �˰��� �Լ�, Functor ���" << endl;
	
	iter1 = find_if(mapItem1.begin(), mapItem1.end(), CharStrCmp("������1"));

	if (iter1 != mapItem1.end())
	{
		cout << "(" << iter1->second.name << ") - " << iter1->second.price << endl;
	}
	else
	{
		cout << "(������1)�� �����ϴ�." << endl;
	}
	cout << endl;
	

	cout << "######################################################" << endl;

	return 0;
}

