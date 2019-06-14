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
//
//	cout << "#######################################################" << endl;
//	cout << "### 초기 상태" << endl;
//	vector<int>::iterator iter = intVec1.begin();
//	for (; iter != intVec1.end(); ++iter)
//	{
//		cout << (*iter) << " ";
//	}
//	cout << endl << endl;
//
//	cout << "#######################################################" << endl;
//	cout << "### assign() - 동일 값으로 Vector Container 채우기" << endl;
//	intVec1.assign(3, 5); // 3개를 5로 채울 것임.
//
//	// 5 5 5
//	/*iter = intVec1.begin();
//	for (; iter != intVec1.end(); ++iter)
//	{
//		cout << (*iter) << " ";
//	}
//	cout << endl << endl; */
//
//	for (size_t i = 0; i < intVec1.size(); ++i)
//	{
//		cout << intVec1[i] << " ";
//	}
//	cout << endl << endl;
//
//	cout << "#######################################################" << endl;
//	cout << "### assign() - 다른 Vector Container 값으로 교체하기" << endl;
//
//	vector<int> intVec2;
//	intVec2.push_back(3);
//	intVec2.push_back(4);
//	intVec2.push_back(5);
//	intVec2.push_back(6);
//
//	// 기존에 존재했던 애들을 다 비워버리고, 새로 채워넣음.
//	// 4 5
//	intVec1.assign(intVec2.begin() + 1, --intVec2.end());
//	for (size_t i = 0; i < intVec1.size(); ++i)
//	{
//		cout << intVec1[i] << " ";
//	}
//	cout << endl << endl;
//
//
//	return 0;
//}