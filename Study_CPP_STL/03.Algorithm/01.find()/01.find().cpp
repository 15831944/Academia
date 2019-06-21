//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//using std::cout;
//using std::endl;
//using std::cin;
//
//using std::vector;
//
//using std::find;
//
//
//int main(void)
//{
//	// map, set 등의 연관 컨테이너는 멤버로 find() 함수를 가지고 있다 !!!!
//
//	cout << "####################################################" << endl;
//	cout << "### find() 알고리즘 함수 - int 검색" << endl;
//	vector<int> intVec1;
//
//	intVec1.push_back(30);
//	intVec1.push_back(20);
//	intVec1.push_back(10);
//
//	vector<int>::iterator iterFind = find(intVec1.begin(), intVec1.end(), 20);
//	if (iterFind != intVec1.end())
//	{
//		cout << (*iterFind) << endl;
//	}
//	else
//	{
//		cout << "항목이 없습니다." << endl;
//	}
//	cout << endl;
//
//	cout << "####################################################" << endl;
//	cout << "### find() 알고리즘 함수 - (char *) Hello 검색" << endl;
//
//	vector<char *> charStrVec1;
//
//	charStrVec1.push_back("Hello");
//	charStrVec1.push_back("World");
//	charStrVec1.push_back("Good");
//	charStrVec1.push_back("Day");
//
//	char str[16];
//	cin >> str;
//
//	cout << "### 입력으로는 찾을 수가 없음..." << endl;
//	vector<char *>::iterator iterFind2 = find(charStrVec1.begin(), charStrVec1.end(), str);
//	if (iterFind2 != charStrVec1.end())
//	{
//		cout << (*iterFind2) << endl;
//	}
//	else
//	{
//		cout << "항목이 없습니다." << endl;
//	}
//	cout << endl;
//
//	cout << "### literal 상수의 주소값을 통해 찾은 것임..." << endl;
//	iterFind2 = find(charStrVec1.begin(), charStrVec1.end(), "Hello");
//	if (iterFind2 != charStrVec1.end())
//	{
//		cout << (*iterFind2) << endl;
//	}
//	else
//	{
//		cout << "항목이 없습니다." << endl;
//	}
//	cout << endl;
//
//	return 0;
//}