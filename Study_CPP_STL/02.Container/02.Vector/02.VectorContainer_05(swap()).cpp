//#include <iostream>
//#include <vector>
//
//#define TRUE true
//#define FALSE false
//
//using std::cout;
//using std::endl;
//
//using std::vector;
//
//int main(void)
//{
//	vector<int> intVec1;
//
//	intVec1.push_back(1);
//	intVec1.push_back(2);
//	intVec1.push_back(3);
//
//	vector<int> intVec2;
//
//	intVec2.push_back(5);
//	intVec2.push_back(6);
//	intVec2.push_back(7);
//	intVec2.push_back(8);
//	intVec2.push_back(9);
//
//	cout << "### 초기 상태" << endl;
//	cout << "intVec1: ";
//	for (size_t i = 0; i < intVec1.size(); ++i)
//	{
//		cout << intVec1[i] << " ";
//	}
//	cout << endl;
//
//	cout << "intVec2: ";
//	for (size_t i = 0; i < intVec2.size(); ++i)
//	{
//		cout << intVec2[i] << " ";
//	}
//	cout << endl << endl;
//
//	cout << "### swap() 멤버 함수 수행 후" << endl;
//
//	intVec1.swap(intVec2);
//	//intVec2.swap(intVec1);
//
//	cout << "intVec1: ";
//	for (size_t i = 0; i < intVec1.size(); ++i)
//	{
//		cout << intVec1[i] << " ";
//	}
//	cout << endl;
//
//	cout << "intVec2: ";
//	for (size_t i = 0; i < intVec2.size(); ++i)
//	{
//		cout << intVec2[i] << " ";
//	}
//	cout << endl << endl;
//
//	return 0;
//}