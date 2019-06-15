//#include <iostream>
//#include <deque>
//
//#define TRUE true
//#define FALSE false
//
//using std::cout;
//using std::endl;
//
//using std::deque;
//
//typedef struct tagPacket
//{
//	unsigned short index;
//} PACKET;
//
//int main(void)
//{
//	// Deque: Double Ended Queue
//
//	PACKET packet1;
//	packet1.index = 1;
//
//	PACKET packet2;
//	packet2.index = 2;
//
//	PACKET packet3;
//	packet3.index = 3;
//
//	PACKET packet4;
//	packet4.index = 4;
//
//	deque<PACKET> receivePacketDeque;
//
//	cout << "### �ʱ� ����" << endl;
//	deque<PACKET>::iterator iter = receivePacketDeque.begin();
//	for (; iter != receivePacketDeque.end(); ++iter)
//	{
//		cout << "��Ŷ �ε���: " << iter->index << endl;
//	}
//	cout << endl;
//
//	cout << "##########################################################" << endl;
//	cout << "### ������ �߰� - push_front(), push_back()" << endl;
//	receivePacketDeque.push_back(packet2);
//	receivePacketDeque.push_back(packet3);
//	receivePacketDeque.push_back(packet4);
//
//	receivePacketDeque.push_front(packet1);
//
//	cout << "### ���� ��� - iterator" << endl;
//	iter = receivePacketDeque.begin();
//	for (; iter != receivePacketDeque.end(); ++iter)
//	{
//		cout << "��Ŷ �ε���: " << iter->index << endl;
//	}
//	cout << endl;
//
//	cout << "### ������ ��� - reverse_iterator" << endl;
//	deque<PACKET>::reverse_iterator reverseIter = receivePacketDeque.rbegin();
//	for (; reverseIter != receivePacketDeque.rend(); ++reverseIter)
//	{
//		cout << "��Ŷ �ε���: " << reverseIter->index << endl;
//	}
//	cout << endl;
//
//	cout << "##########################################################" << endl;
//	cout << "Deque Container - �ε��� �����ϱ� []" << endl;
//
//	int packetCount = static_cast<int>(receivePacketDeque.size());
//	cout << "�� ��Ŷ ��: " << packetCount << endl;
//	for (int i = 0; i < packetCount; ++i)
//	{
//		cout << "��Ŷ �ε���: " << receivePacketDeque[i].index << endl;
//	}
//	cout << endl;
//
//	cout << "##########################################################" << endl;
//	cout << "### front(), at(), back()" << endl;
//	PACKET &firstPacket = receivePacketDeque.front();
//	cout << "ù ��° ��Ŷ �ε���: " << firstPacket.index << endl;
//
//	PACKET &packetAt = receivePacketDeque.at(1);
//	cout << "�� ��° ��Ŷ �ε���: " << packetAt.index << endl;
//
//	PACKET &lastPacket = receivePacketDeque.back();
//	cout << "������  ��Ŷ �ε���: " << lastPacket.index << endl;
//
//	cout << "##########################################################" << endl;
//	cout << "### ��Ŷ ���� �� ����" << endl;
//	packetCount = static_cast<int>(receivePacketDeque.size());
//	cout << "�� ��Ŷ ��: " << packetCount << endl;
//	for (int i = 0; i < packetCount; ++i)
//	{
//		cout << "��Ŷ �ε���: " << receivePacketDeque[i].index << endl;
//	}
//	cout << endl;
//
//	cout << "### ù ��° ��Ŷ ���� - pop_front()" << endl;
//	receivePacketDeque.pop_front();
//	cout << "ù ��° ��Ŷ �ε���: " << receivePacketDeque[0].index << endl << endl;
//
//	cout << "### ������ ��Ŷ ���� - pop_back()" << endl;
//	receivePacketDeque.pop_back();
//	cout << "������ ��Ŷ �ε���: " << receivePacketDeque.back().index << endl << endl;
//
//	cout << "##########################################################" << endl;
//	cout << "### ��� ��Ŷ ���� - clear()" << endl;
//
//	if (receivePacketDeque.empty() != TRUE)
//	{
//		cout << "��� ��Ŷ�� �����մϴ�." << endl;
//		receivePacketDeque.clear();
//	}
//
//	cout << "�� ��Ŷ ��: " << receivePacketDeque.size() << endl << endl;
//
//	return 0;
//}