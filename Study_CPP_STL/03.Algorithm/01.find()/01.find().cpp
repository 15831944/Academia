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
//	// map, set ���� ���� �����̳ʴ� ����� find() �Լ��� ������ �ִ� !!!!
//
//	cout << "####################################################" << endl;
//	cout << "### find() �˰��� �Լ� - int �˻�" << endl;
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
//		cout << "�׸��� �����ϴ�." << endl;
//	}
//	cout << endl;
//
//	cout << "####################################################" << endl;
//	cout << "### find() �˰��� �Լ� - (char *) Hello �˻�" << endl;
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
//	cout << "### �Է����δ� ã�� ���� ����..." << endl;
//	vector<char *>::iterator iterFind2 = find(charStrVec1.begin(), charStrVec1.end(), str);
//	if (iterFind2 != charStrVec1.end())
//	{
//		cout << (*iterFind2) << endl;
//	}
//	else
//	{
//		cout << "�׸��� �����ϴ�." << endl;
//	}
//	cout << endl;
//
//	cout << "### literal ����� �ּҰ��� ���� ã�� ����..." << endl;
//	iterFind2 = find(charStrVec1.begin(), charStrVec1.end(), "Hello");
//	if (iterFind2 != charStrVec1.end())
//	{
//		cout << (*iterFind2) << endl;
//	}
//	else
//	{
//		cout << "�׸��� �����ϴ�." << endl;
//	}
//	cout << endl;
//
//	return 0;
//}