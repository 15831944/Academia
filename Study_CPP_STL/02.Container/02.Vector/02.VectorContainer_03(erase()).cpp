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
//
//int main(void)
//{
//	vector<int> intVec1;
//
//	intVec1.push_back(10);
//	intVec1.push_back(20);
//	intVec1.push_back(30);
//	intVec1.push_back(40);
//	intVec1.push_back(50);
//
//	cout << "### 초기 상태" << endl;
//	// 10 20 30 40 50
//	for (size_t i = 0; i < intVec1.size(); ++i)
//	{
//		cout << intVec1[i] << " ";
//	}
//	cout << endl << endl;
//
//	// #########################################################################
//	cout << "### erase() - 지정된 (위치)의 원소 삭제 ###" << endl;
//
//	intVec1.erase(intVec1.begin());
//
//	// 20 30 40 50
//	for (size_t i = 0; i < intVec1.size(); ++i)
//	{
//		cout << intVec1[i] << " ";
//	}
//	cout << endl << endl;
//
//	// #########################################################################
//	cout << "### erase() - 지정된 (범위)의 원소 삭제 ###" << endl;
//
//	vector<int>::iterator iterEnd = intVec1.begin() + 2;
//	intVec1.erase(intVec1.begin() + 1, iterEnd); // 앞의 "iterator" 이상, 뒤의 "iterator" 미만
//
//	for (size_t i = 0; i < intVec1.size(); ++i)
//	{
//		cout << intVec1[i] << " ";
//	}
//	cout << endl << endl;
//
//	// #########################################################################
//	cout << "### erase() - 원소 삭제 시, iterator 무효화 문제 ###" << endl;
//	vector<int> intVec2;
//
//	// 1 2 3 4 5
//	intVec2.push_back(1);
//	intVec2.push_back(2);
//	intVec2.push_back(3);
//	intVec2.push_back(4);
//	intVec2.push_back(5);
//
//	vector<int>::iterator iter2 = intVec2.begin();
//	for (; iter2 != intVec2.end(); )
//	{
//		if ((*iter2) % 2 == 0)
//		{
//			iter2 = intVec2.erase(iter2);
//			// ##########################################
//			// erase() 멤버 함수는 삭제한 다음 위치의 원소를 가리킨다 !!!!
//		}
//		else
//		{
//			++iter2;
//		}
//	}
//
//	// 1 3 5
//	iter2 = intVec2.begin();
//	for (; iter2 != intVec2.end(); ++iter2)
//	{
//		cout << (*iter2) << " ";
//	}
//	cout << endl << endl;
//
//
//	return 0;
//}