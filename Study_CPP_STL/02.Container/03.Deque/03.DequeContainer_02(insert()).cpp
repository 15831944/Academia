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
//	PACKET packet1;
//	packet1.index = 1;
//	PACKET packet2;
//	packet2.index = 2;
//	PACKET packet3;
//	packet3.index = 3;
//
//	deque<PACKET> receivePacketDeque;
//	receivePacketDeque.push_back(packet1);
//	receivePacketDeque.push_back(packet2);
//	receivePacketDeque.push_back(packet3);
//
//	cout << "#######################################################" << endl;
//	cout << "### 초기 상태" << endl;
//
//	// 1 2 3
//	deque<PACKET>::iterator iter = receivePacketDeque.begin();
//	for (; iter != receivePacketDeque.end(); ++iter)
//	{
//		cout << "패킷 인덱스: " << iter->index << endl;
//	}
//	cout << endl;
//
//	// ############################################################################
//	cout << "### insert() - 지정 위치 데이터 추가 ###" << endl;
//	PACKET packet4;
//	packet4.index = 4;
//
//	iter = receivePacketDeque.begin();
//	iter += 1;
//	receivePacketDeque.insert(iter, packet4);
//
//	// 1 4 2 3
//	iter = receivePacketDeque.begin();
//	for (; iter != receivePacketDeque.end(); ++iter)
//	{
//		cout << "패킷 인덱스: " << iter->index << endl;
//	}
//	cout << endl;
//
//	// ############################################################################
//	cout << "### insert() - 지정 위치 데이터 (여러 번) 추가 ###" << endl;
//	PACKET packet5;
//	packet5.index = 5;
//
//	iter = receivePacketDeque.begin();
//	iter += 2;
//	receivePacketDeque.insert(iter, 2, packet5); // 2번 packet5 추가
//
//	// 1 4 5 5 2 3
//	iter = receivePacketDeque.begin();
//	for (; iter != receivePacketDeque.end(); ++iter)
//	{
//		cout << "패킷 인덱스: " << iter->index << endl;
//	}
//	cout << endl;
//	// ############################################################################
//	cout << "### insert() - 지정 위치 (다른 리스트의 데이터 여러 개) 추가 ###" << endl;
//
//	PACKET packet6;
//	packet6.index = 6;
//	PACKET packet7;
//	packet7.index = 7;
//	PACKET packet8;
//	packet8.index = 8;
//	PACKET packet9;
//	packet9.index = 9;
//
//	deque<PACKET> receivePacketDeque2;
//	receivePacketDeque2.push_back(packet6);
//	receivePacketDeque2.push_back(packet7);
//	receivePacketDeque2.push_back(packet8);
//	receivePacketDeque2.push_back(packet9);
//
//	iter = receivePacketDeque.begin();
//	iter += 5;
//	receivePacketDeque.insert(iter, receivePacketDeque2.begin() + 1, receivePacketDeque2.end() - 1);
//
//	// 1 4 5 5 2 7 8 3
//	iter = receivePacketDeque.begin();
//	for (; iter != receivePacketDeque.end(); ++iter)
//	{
//		cout << "패킷 인덱스: " << iter->index << endl;
//	}
//	cout << endl;
//
//	return 0;
//}