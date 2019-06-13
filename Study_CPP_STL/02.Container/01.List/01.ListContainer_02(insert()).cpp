//#include <iostream>
//#include <list>
//
//using std::cout;
//using std::endl;
//
//using std::list;
//
//int main(void)
//{
//	list<int> listInt;
//
//	// 20
//	listInt.push_back(20);
//	// 20 30
//	listInt.push_back(30);
//
//
//	// ############################################################################
//	cout << "### insert() - 지정 위치 데이터 추가 ###" << endl;
//	list<int>::iterator iterInsertPos = listInt.begin();
//	listInt.insert(iterInsertPos, 10);
//	// ###############################################
//	// insert() 함수는 추가한 위치의 다음 위치 반환 !!!!
//
//	// 10 20 30
//	iterInsertPos = listInt.begin();
//	for (; iterInsertPos != listInt.end(); ++iterInsertPos)
//	{
//		cout << "listInt: " << (*iterInsertPos) << endl; // Derefrencing을 해줘야 들어있는 데이터 확인 가능.
//	}
//	cout << endl;
//
//
//	// ############################################################################
//	cout << "### insert() - 지정 위치 데이터 (여러 번) 추가 ###" << endl;
//	iterInsertPos = listInt.begin();
//	++iterInsertPos;
//
//	// 10 40 40 20 30
//	listInt.insert(iterInsertPos, 2, 40);
//	// ###############################################
//	// insert() 함수는 추가한 위치의 다음 위치 반환 !!!!
//
//	iterInsertPos = listInt.begin();
//	for (; iterInsertPos != listInt.end(); ++iterInsertPos)
//	{
//		cout << "listInt: " << (*iterInsertPos) << endl; // Derefrencing을 해줘야 들어있는 데이터 확인 가능.
//	}
//	cout << endl;
//
//
//	// ############################################################################
//	cout << "### insert() - 지정 위치 (다른 리스트의 데이터 여러 개) 추가 ###" << endl;
//
//	list<int> listInt2;
//	listInt2.push_back(40);
//	listInt2.push_back(50);
//	listInt2.push_back(60);
//	listInt2.push_back(70);
//
//	iterInsertPos = listInt.begin(); // "10" 위치
//	++iterInsertPos; // "40' 위치
//	++iterInsertPos; // "40" 위치
//	++iterInsertPos; // "20" 위치 (그 자리에 넣어야 "20"이 뒤로 밀림)
//
//	// 10 40 40 50 60 20 30
//	listInt.insert(iterInsertPos, ++listInt2.begin(), --listInt2.end());
//	// ###############################################
//	// insert() 함수는 추가한 위치의 다음 위치 반환 !!!!
//
//	iterInsertPos = listInt.begin();
//	for (; iterInsertPos != listInt.end(); ++iterInsertPos)
//	{
//		cout << "listInt: " << (*iterInsertPos) << endl; // Derefrencing을 해줘야 들어있는 데이터 확인 가능.
//	}
//	cout << endl;
//
//	return 0;
//}