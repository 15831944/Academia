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
//
//int main(void)
//{
//	vector<int> intVec1;
//
//	intVec1.push_back(10);
//	intVec1.push_back(20);
//	intVec1.push_back(30);
//
//
//	cout << "### 초기 상태" << endl;
//	// 10 20 30
//	vector<int>::iterator iter = intVec1.begin();
//	for (; iter != intVec1.end(); ++iter)
//	{
//		cout << *iter << " ";
//	}
//	cout << endl << endl;
//
//	// ############################################################################
//	cout << "### insert() - 지정 위치 데이터 추가 ###" << endl;
//	vector<int>::iterator iterInsertPos = intVec1.begin();
//	intVec1.insert(iterInsertPos, 40);
//
//	// 40 10 20 30
//	iter = intVec1.begin();
//	for (; iter != intVec1.end(); ++iter)
//	{
//		cout << *iter << " ";
//	}
//	cout << endl << endl;
//
//	// ############################################################################
//	cout << "### insert() - 지정 위치 데이터 (여러 번) 추가 ###" << endl;
//	iterInsertPos = intVec1.begin();
//	iterInsertPos += 3;
//
//	intVec1.insert(iterInsertPos, 2, 50);
//	// 40 10 20 50 50 30
//	iter = intVec1.begin();
//	for (; iter != intVec1.end(); ++iter)
//	{
//		cout << *iter << " ";
//	}
//	cout << endl << endl;
//
//	// ############################################################################
//	cout << "### insert() - 지정 위치 (다른 리스트의 데이터 여러 개) 추가 ###" << endl;
//	vector<int> intVec2;
//
//	intVec2.push_back(60);
//	intVec2.push_back(70);
//	intVec2.push_back(80);
//	intVec2.push_back(90);
//
//	iter = intVec1.begin();
//	iter += 1;
//	intVec1.insert(iter, ++intVec2.begin(), --intVec2.end());
//
//	// 40 70 80 10 20 50 50 30
//	iter = intVec1.begin();
//	for (; iter != intVec1.end(); ++iter)
//	{
//		cout << *iter << " ";
//	}
//	cout << endl << endl;
//
//	return 0;
//}