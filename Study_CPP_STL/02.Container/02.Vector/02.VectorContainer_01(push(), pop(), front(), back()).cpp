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
//	cout << "##### ���� ���" << endl;
//	// 1 2 3
//	vector<USER>::iterator iter = userVec.begin();
//	for (; iter != userVec.end(); ++iter)
//	{
//		cout << "���� �ڵ�: " << iter->charCode << endl;
//	}
//	cout << endl;
//
//	cout << "##### ���� ���" << endl;
//	// 1 2 3 <- ����ִ� ����. "��ȸ ������ ����" !!!!
//	vector<USER>::reverse_iterator iterReverse = userVec.rbegin();
//	for (; iterReverse != userVec.rend(); ++iterReverse) // ������ "iterator"�� �̿��ص� ���� ���� ������� �մϴ� !!!!
//	{
//		cout << "���� �ڵ�: " << iterReverse->charCode << endl;
//	}
//	cout << endl;
//
//	cout << "############################################################" << endl;
//	cout << "##### �迭 ��� �������� ���" << endl;
//	// �ε��� ������ ���ؼ� �������� ��ȯ�ϱ� ������, ������ ������ ���ΰ� ?!
//	int userCount = static_cast<int>(userVec.size());
//	for (int i = 0; i < userCount; ++i)
//	{
//		cout << "���� �ڵ�: " << userVec[i].charCode << endl; // ���� ���� ���� �ȴ� !!!
//		//cout << "���� �ڵ�: " << ++userVec[i].charCode << endl; // ���� ���� ���� �ȴ� !!!
//	}
//	cout << endl;
//
//	cout << "############################################################" << endl;
//	cout << "##### front(), back(), at() ��� �Լ� �̿�" << endl;
//	USER& frontUser = userVec.front();
//	cout << "ù ��°: " << frontUser.charCode << endl;
//
//	USER& secondUser = userVec.at(1);
//	cout << "�� ��°: " << secondUser.charCode << endl;
//
//	USER& backUser = userVec.back();
//	cout << "������: " << backUser.charCode << endl << endl;
//
//	cout << "############################################################" << endl;
//	cout << "### clear() �Լ�, �޸� ���� �Ҵ��� ���� ������ ������ ���� !!!!" << endl;
//
//	userCount = userVec.size();
//	cout << "���� �濡 �ִ� ���� ��: " << userCount << endl << endl;
//
//	cout << "pop_back() ���� ����" << endl;
//	userVec.pop_back();
//
//	userCount = userVec.size();
//	cout << "���� �濡 �ִ� ���� ��: " << userCount << endl << endl;
//
//	cout << "clear() ���� ����" << endl;
//
//	if (userVec.empty() != TRUE)
//	{
//		userVec.clear();
//	}
//
//	userCount = userVec.size();
//	cout << "���� �濡 �ִ� ���� ��: " << userCount << endl << endl;
//
//	return 0;
//}