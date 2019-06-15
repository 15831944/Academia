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
//	cout << "### 초기 상태" << endl;
//	deque<PACKET>::iterator iter = receivePacketDeque.begin();
//	for (; iter != receivePacketDeque.end(); ++iter)
//	{
//		cout << "패킷 인덱스: " << iter->index << endl;
//	}
//	cout << endl;
//
//	cout << "##########################################################" << endl;
//	cout << "### 데이터 추가 - push_front(), push_back()" << endl;
//	receivePacketDeque.push_back(packet2);
//	receivePacketDeque.push_back(packet3);
//	receivePacketDeque.push_back(packet4);
//
//	receivePacketDeque.push_front(packet1);
//
//	cout << "### 정상 출력 - iterator" << endl;
//	iter = receivePacketDeque.begin();
//	for (; iter != receivePacketDeque.end(); ++iter)
//	{
//		cout << "패킷 인덱스: " << iter->index << endl;
//	}
//	cout << endl;
//
//	cout << "### 역방향 출력 - reverse_iterator" << endl;
//	deque<PACKET>::reverse_iterator reverseIter = receivePacketDeque.rbegin();
//	for (; reverseIter != receivePacketDeque.rend(); ++reverseIter)
//	{
//		cout << "패킷 인덱스: " << reverseIter->index << endl;
//	}
//	cout << endl;
//
//	cout << "##########################################################" << endl;
//	cout << "Deque Container - 인덱스 접근하기 []" << endl;
//
//	int packetCount = static_cast<int>(receivePacketDeque.size());
//	cout << "총 패킷 수: " << packetCount << endl;
//	for (int i = 0; i < packetCount; ++i)
//	{
//		cout << "패킷 인덱스: " << receivePacketDeque[i].index << endl;
//	}
//	cout << endl;
//
//	cout << "##########################################################" << endl;
//	cout << "### front(), at(), back()" << endl;
//	PACKET &firstPacket = receivePacketDeque.front();
//	cout << "첫 번째 패킷 인덱스: " << firstPacket.index << endl;
//
//	PACKET &packetAt = receivePacketDeque.at(1);
//	cout << "두 번째 패킷 인덱스: " << packetAt.index << endl;
//
//	PACKET &lastPacket = receivePacketDeque.back();
//	cout << "마지막  패킷 인덱스: " << lastPacket.index << endl;
//
//	cout << "##########################################################" << endl;
//	cout << "### 패킷 삭제 전 상태" << endl;
//	packetCount = static_cast<int>(receivePacketDeque.size());
//	cout << "총 패킷 수: " << packetCount << endl;
//	for (int i = 0; i < packetCount; ++i)
//	{
//		cout << "패킷 인덱스: " << receivePacketDeque[i].index << endl;
//	}
//	cout << endl;
//
//	cout << "### 첫 번째 패킷 삭제 - pop_front()" << endl;
//	receivePacketDeque.pop_front();
//	cout << "첫 번째 패킷 인덱스: " << receivePacketDeque[0].index << endl << endl;
//
//	cout << "### 마지막 패킷 삭제 - pop_back()" << endl;
//	receivePacketDeque.pop_back();
//	cout << "마지막 패킷 인덱스: " << receivePacketDeque.back().index << endl << endl;
//
//	cout << "##########################################################" << endl;
//	cout << "### 모든 패킷 삭제 - clear()" << endl;
//
//	if (receivePacketDeque.empty() != TRUE)
//	{
//		cout << "모든 패킷을 삭제합니다." << endl;
//		receivePacketDeque.clear();
//	}
//
//	cout << "총 패킷 수: " << receivePacketDeque.size() << endl << endl;
//
//	return 0;
//}