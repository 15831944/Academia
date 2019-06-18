//#include <iostream>
//#include <unordered_map>
//
//#define TRUE true
//#define FALSE false
//
//using std::cout;
//using std::endl;
//
//using std::unordered_map;
//
//typedef struct tagCharacterInfo
//{
//	tagCharacterInfo() {}
//
//	tagCharacterInfo(int charCode, int level)
//		: charCode(charCode), level(level)
//	{
//
//	}
//
//	int charCode;
//	int level;
//
//} CHARACTERINFO;
//
//int main(void)
//{
//	unordered_map<int, CHARACTERINFO> charUMap;
//
//	CHARACTERINFO char1(10, 1);
//	charUMap.insert(unordered_map<int, CHARACTERINFO>::value_type(10, char1));
//
//	CHARACTERINFO char2(20, 2);
//	unordered_map<int, CHARACTERINFO>::iterator iter = charUMap.begin();
//	++iter;
//	charUMap.insert(iter, unordered_map<int, CHARACTERINFO>::value_type(20, char2));
//
//	cout << "###########################################################" << endl;
//	cout << "### �ʱ� ���� - charUMap" << endl;
//	iter = charUMap.begin();
//	for (; iter != charUMap.end(); ++iter)
//	{
//		cout << "ĳ���� �ڵ�: " << iter->second.charCode << " / ����: " << iter->second.level << endl;
//	}
//	cout << endl;
//
//	//
//	unordered_map<int, CHARACTERINFO> tempCharUMap;
//	tempCharUMap.insert(unordered_map<int, CHARACTERINFO>::value_type(30, CHARACTERINFO(30, 3)));
//	tempCharUMap.insert(unordered_map<int, CHARACTERINFO>::value_type(40, CHARACTERINFO(40, 4)));
//	tempCharUMap.insert(unordered_map<int, CHARACTERINFO>::value_type(50, CHARACTERINFO(50, 5)));
//	tempCharUMap.insert(unordered_map<int, CHARACTERINFO>::value_type(60, CHARACTERINFO(60, 6)));
//	tempCharUMap.insert(unordered_map<int, CHARACTERINFO>::value_type(70, CHARACTERINFO(70, 7)));
//	//
//
//	cout << "### �ʱ� ���� - tempCharUMap" << endl;
//	unordered_map<int, CHARACTERINFO>::iterator iter2 = tempCharUMap.begin();
//	for (; iter2 != tempCharUMap.end(); ++iter2)
//	{
//		cout << "ĳ���� �ڵ�: " << iter2->second.charCode << " / ����: " << iter2->second.level << endl;
//	}
//	cout << endl;
//
//	iter2 = tempCharUMap.find(60);
//	++iter2; // ����������� ���Խ�ų ��...
//	charUMap.insert(tempCharUMap.begin(), iter2); // ������ �̻�, �̸� !!!!
//
//	cout << "###########################################################" << endl;
//	cout << "### insert() - �ٸ� unordered_map�� ���� ���� ���� �߰��ϱ�" << endl;
//	cout << "### ���� ������ ���� ���� ������ �����ؾ��� ?!" << endl;
//	iter = charUMap.begin();
//	for (; iter != charUMap.end(); ++iter)
//	{
//		cout << "ĳ���� �ڵ�: " << iter->second.charCode << " / ����: " << iter->second.level << endl;
//	}
//	cout << endl;
//
//	cout << "###########################################################" << endl;
//	cout << "### reverse_iterator ��� rbegin(), rend() X" << endl << endl;
//
//
//	cout << "###########################################################" << endl;
//	cout << "### find() - Ű������ �˻��ϱ�" << endl;
//	unordered_map<int, CHARACTERINFO>::iterator iterFind = charUMap.find(70);
//	if (iterFind == charUMap.end())
//	{
//		cout << "ĳ���� �ڵ尡 70�� ĳ���ʹ� �����ϴ�." << endl;
//	}
//	else
//	{
//		cout << "ĳ���� �ڵ�: " << iterFind->second.charCode << " / ����: " << iterFind->second.level << endl;
//	}
//
//	unordered_map<int, CHARACTERINFO>::iterator iterFind2 = charUMap.find(80);
//	if (iterFind2 == charUMap.end())
//	{
//		cout << "ĳ���� �ڵ尡 80�� ĳ���ʹ� �����ϴ�." << endl;
//	}
//	else
//	{
//		cout << "ĳ���� �ڵ�: " << iterFind2->second.charCode << " / ����: " << iterFind2->second.level << endl;
//	}
//	cout << endl;
//
//	cout << "###########################################################" << endl;
//	cout << "### erase() - Ű��(70)���� �˻��ؼ� �����" << endl;
//	charUMap.erase(70);
//	iter = charUMap.begin();
//	for (; iter != charUMap.end(); ++iter)
//	{
//		cout << "ĳ���� �ڵ�: " << iter->second.charCode << " / ����: " << iter->second.level << endl;
//	}
//	cout << endl;
//
//	cout << "### erase() - iterator�� �̿��ؼ� 3��° ���� �����" << endl;
//	iter = charUMap.begin();
//	++iter;
//	++iter;
//	charUMap.erase(iter);
//
//	iter = charUMap.begin();
//	for (; iter != charUMap.end(); ++iter)
//	{
//		cout << "ĳ���� �ڵ�: " << iter->second.charCode << " / ����: " << iter->second.level << endl;
//	}
//	cout << endl;
//
//	cout << "### erase() - iterator�� �̿��� ���� ���� ���� �����" << endl;
//
//	iter = charUMap.begin();
//	++iter;
//	unordered_map<int, CHARACTERINFO>::iterator iterEnd = iter;
//	++iterEnd;
//	++iterEnd;
//	++iterEnd;
//
//	charUMap.erase(iter, iterEnd);
//	iter = charUMap.begin();
//	for (; iter != charUMap.end(); ++iter)
//	{
//		cout << "ĳ���� �ڵ�: " << iter->second.charCode << " / ����: " << iter->second.level << endl;
//	}
//	cout << endl;
//
//	cout << "###########################################################" << endl;
//	cout << "### clear(), empty()" << endl;
//
//	if (charUMap.empty() != TRUE)
//	{
//		cout << "unordered_map: " << charUMap.size() << endl;
//	}
//	else
//	{
//		cout << "unordered_map�� ����ֽ��ϴ�." << endl;
//	}
//	cout << endl;
//
//	charUMap.clear();
//
//	if (charUMap.empty() != TRUE)
//	{
//		cout << "unordered_map: " << charUMap.size() << endl;
//	}
//	else
//	{
//		cout << "unordered_map�� ����ֽ��ϴ�." << endl;
//	}
//	cout << endl;
//
//	return 0;
//}