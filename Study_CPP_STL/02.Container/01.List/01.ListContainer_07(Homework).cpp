//#include <iostream>
//#include <list>
//
//#define TRUE true
//#define FALSE false
//
//using std::cout;
//using std::endl;
//
//using std::list;
//
//typedef struct tagPoint
//{
//	tagPoint(int xPos, int yPos)
//		: xPos(xPos), yPos(yPos)
//	{
//
//	}
//
//	int xPos;
//	int yPos;
//
//} POINT;
//
//int main(void)
//{
//	// #############################################################################
//	list<POINT> pointList;
//
//	POINT p1 = { 50, 300 };
//	POINT p2 = { 20, 80 };
//	POINT p3 = { 75, 10 };
//	POINT p4 = { 130, 80 };
//	POINT p5 = { 100, 200 };
//
//	// p1(A) p2(B) p3(C) p4(D) p5(E)
//	pointList.push_back(p1);
//	pointList.push_back(p2);
//	pointList.push_back(p3);
//	pointList.push_back(p4);
//	pointList.push_back(p5);
//
//	cout << "##### �ʱ� ����" << endl;
//	list<POINT>::iterator iter = pointList.begin();
//	for (; iter != pointList.end(); ++iter)
//	{
//		cout << "[ " << iter->xPos << ", " << iter->yPos << " ]" << endl;
//	}
//	cout << endl;
//
//	// #############################################################################
//	// p4�� p5 ���̿� p6 { 180, 150 } �߰�
//	POINT p6 = { 180, 150 };
//
//	iter = pointList.begin(); // �� ���� ����� ����?!
//	++iter;
//	++iter;
//	++iter;
//	++iter;
//
//	// p1(A) p2(B) p3(C) p4(D) p6(F) p5(E)
//	pointList.insert(iter, p6);
//
//	cout << "##### 5�� ��ġ�� �� p6(F) (180, 150) �߰�" << endl;
//	iter = pointList.begin();
//	for (; iter != pointList.end(); ++iter)
//	{
//		cout << "[ " << iter->xPos << ", " << iter->yPos << " ]" << endl;
//	}
//	cout << endl;
//
//	// #############################################################################
//	// �� p4(D)�� ���� (200, 100)���� ����
//	iter = pointList.begin(); // �� ���� ����� ����?!
//	++iter;
//	++iter;
//	++iter;
//
//	iter->xPos = 200;
//	iter->yPos = 100;
//
//	cout << "##### p4 (130, 80) -> (200, 100) ����" << endl;
//	iter = pointList.begin();
//	for (; iter != pointList.end(); ++iter)
//	{
//		cout << "[ " << iter->xPos << ", " << iter->yPos << " ]" << endl;
//	}
//	cout << endl;
//
//	// #############################################################################
//	// �� p3(C)����
//
//	iter = pointList.begin();
//	++iter;
//	++iter;
//
//	pointList.erase(iter);
//
//	cout << "##### �� p3(C) (75, 10) ����" << endl;
//	iter = pointList.begin();
//	for (; iter != pointList.end(); ++iter)
//	{
//		cout << "[ " << iter->xPos << ", " << iter->yPos << " ]" << endl;
//	}
//	cout << endl;
//
//
//	return 0;
//}