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
//	cout << "### �ʱ� ����" << endl;
//	vector<int>::iterator iter = intVec1.begin();
//	for (; iter != intVec1.end(); ++iter)
//	{
//		cout << (*iter) << " ";
//	}
//	cout << endl << endl;
//
//	cout << "#######################################################" << endl;
//	cout << "### assign() - ���� ������ Vector Container ä���" << endl;
//	intVec1.assign(3, 5); // 3���� 5�� ä�� ����.
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
//	cout << "### assign() - �ٸ� Vector Container ������ ��ü�ϱ�" << endl;
//
//	vector<int> intVec2;
//	intVec2.push_back(3);
//	intVec2.push_back(4);
//	intVec2.push_back(5);
//	intVec2.push_back(6);
//
//	// ������ �����ߴ� �ֵ��� �� ���������, ���� ä������.
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