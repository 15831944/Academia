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
//typedef struct tagUser
//{
//	int charCode;
//
//} USER;
//
//int main(void)
//{
//	vector<USER> userVec;
//
//
//	USER user1;
//	user1.charCode = 1;
//
//	USER user2;
//	user2.charCode = 2;
//
//	USER user3;
//	user3.charCode = 3;
//
//	userVec.push_back(user1);
//	userVec.push_back(user2);
//	userVec.push_back(user3);
//
//	cout << "############################################################" << endl;
//	cout << "##### 정상 출력" << endl;
//	// 1 2 3
//	vector<USER>::iterator iter = userVec.begin();
//	for (; iter != userVec.end(); ++iter)
//	{
//		cout << "유저 코드: " << iter->charCode << endl;
//	}
//	cout << endl;
//
//	cout << "##### 역순 출력" << endl;
//	// 1 2 3 <- 들어있는 순서. "순회 순서만 역순" !!!!
//	vector<USER>::reverse_iterator iterReverse = userVec.rbegin();
//	for (; iterReverse != userVec.rend(); ++iterReverse) // 역방향 "iterator"를 이용해도 값을 증가 시켜줘야 합니다 !!!!
//	{
//		cout << "유저 코드: " << iterReverse->charCode << endl;
//	}
//	cout << endl;
//
//	cout << "############################################################" << endl;
//	cout << "##### 배열 방식 접근으로 출력" << endl;
//	// 인덱스 접근을 통해서 참조값을 반환하기 때문에, 수정이 가능한 것인가 ?!
//	int userCount = static_cast<int>(userVec.size());
//	for (int i = 0; i < userCount; ++i)
//	{
//		cout << "유저 코드: " << userVec[i].charCode << endl; // 실제 값이 변동 된다 !!!
//		//cout << "유저 코드: " << ++userVec[i].charCode << endl; // 실제 값이 변동 된다 !!!
//	}
//	cout << endl;
//
//	cout << "############################################################" << endl;
//	cout << "##### front(), back(), at() 멤버 함수 이용" << endl;
//	USER& frontUser = userVec.front();
//	cout << "첫 번째: " << frontUser.charCode << endl;
//
//	USER& secondUser = userVec.at(1);
//	cout << "두 번째: " << secondUser.charCode << endl;
//
//	USER& backUser = userVec.back();
//	cout << "마지막: " << backUser.charCode << endl << endl;
//
//	cout << "############################################################" << endl;
//	cout << "### clear() 함수, 메모리 동적 할당한 것은 지우지 않으니 조심 !!!!" << endl;
//
//	userCount = userVec.size();
//	cout << "현재 방에 있는 유저 수: " << userCount << endl << endl;
//
//	cout << "pop_back() 연산 수행" << endl;
//	userVec.pop_back();
//
//	userCount = userVec.size();
//	cout << "현재 방에 있는 유저 수: " << userCount << endl << endl;
//
//	cout << "clear() 연산 수행" << endl;
//
//	if (userVec.empty() != TRUE)
//	{
//		userVec.clear();
//	}
//
//	userCount = userVec.size();
//	cout << "현재 방에 있는 유저 수: " << userCount << endl << endl;
//
//	return 0;
//}