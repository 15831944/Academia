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
//	cout << "### 초기 상태 - charUMap" << endl;
//	iter = charUMap.begin();
//	for (; iter != charUMap.end(); ++iter)
//	{
//		cout << "캐릭터 코드: " << iter->second.charCode << " / 레벨: " << iter->second.level << endl;
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
//	cout << "### 초기 상태 - tempCharUMap" << endl;
//	unordered_map<int, CHARACTERINFO>::iterator iter2 = tempCharUMap.begin();
//	for (; iter2 != tempCharUMap.end(); ++iter2)
//	{
//		cout << "캐릭터 코드: " << iter2->second.charCode << " / 레벨: " << iter2->second.level << endl;
//	}
//	cout << endl;
//
//	iter2 = tempCharUMap.find(60);
//	++iter2; // 증가시켜줘야 포함시킬 수...
//	charUMap.insert(tempCharUMap.begin(), iter2); // 범위가 이상, 미만 !!!!
//
//	cout << "###########################################################" << endl;
//	cout << "### insert() - 다른 unordered_map의 일정 범위 원소 추가하기" << endl;
//	cout << "### 저장 순서가 섞일 수도 있으니 조심해야함 ?!" << endl;
//	iter = charUMap.begin();
//	for (; iter != charUMap.end(); ++iter)
//	{
//		cout << "캐릭터 코드: " << iter->second.charCode << " / 레벨: " << iter->second.level << endl;
//	}
//	cout << endl;
//
//	cout << "###########################################################" << endl;
//	cout << "### reverse_iterator 없어서 rbegin(), rend() X" << endl << endl;
//
//
//	cout << "###########################################################" << endl;
//	cout << "### find() - 키값으로 검색하기" << endl;
//	unordered_map<int, CHARACTERINFO>::iterator iterFind = charUMap.find(70);
//	if (iterFind == charUMap.end())
//	{
//		cout << "캐릭터 코드가 70인 캐릭터는 없습니다." << endl;
//	}
//	else
//	{
//		cout << "캐릭터 코드: " << iterFind->second.charCode << " / 레벨: " << iterFind->second.level << endl;
//	}
//
//	unordered_map<int, CHARACTERINFO>::iterator iterFind2 = charUMap.find(80);
//	if (iterFind2 == charUMap.end())
//	{
//		cout << "캐릭터 코드가 80인 캐릭터는 없습니다." << endl;
//	}
//	else
//	{
//		cout << "캐릭터 코드: " << iterFind2->second.charCode << " / 레벨: " << iterFind2->second.level << endl;
//	}
//	cout << endl;
//
//	cout << "###########################################################" << endl;
//	cout << "### erase() - 키값(70)으로 검색해서 지우기" << endl;
//	charUMap.erase(70);
//	iter = charUMap.begin();
//	for (; iter != charUMap.end(); ++iter)
//	{
//		cout << "캐릭터 코드: " << iter->second.charCode << " / 레벨: " << iter->second.level << endl;
//	}
//	cout << endl;
//
//	cout << "### erase() - iterator를 이용해서 3번째 원소 지우기" << endl;
//	iter = charUMap.begin();
//	++iter;
//	++iter;
//	charUMap.erase(iter);
//
//	iter = charUMap.begin();
//	for (; iter != charUMap.end(); ++iter)
//	{
//		cout << "캐릭터 코드: " << iter->second.charCode << " / 레벨: " << iter->second.level << endl;
//	}
//	cout << endl;
//
//	cout << "### erase() - iterator를 이용해 일정 범위 원소 지우기" << endl;
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
//		cout << "캐릭터 코드: " << iter->second.charCode << " / 레벨: " << iter->second.level << endl;
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
//		cout << "unordered_map이 비어있습니다." << endl;
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
//		cout << "unordered_map이 비어있습니다." << endl;
//	}
//	cout << endl;
//
//	return 0;
//}