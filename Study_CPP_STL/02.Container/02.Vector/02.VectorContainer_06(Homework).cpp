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
//// ########################################################
//// "Vector Container"로 LIFO, FIFO 둘 다 가능한 Stack 만들기
//// ########################################################
//
//template <typename T>
//class Stack
//{
//public:
//	Stack()
//	{
//		Clear();
//	}
//
//public:
//	void Clear() { if (mStack.empty() != TRUE) mStack.clear(); }
//	bool IsStackEmpty() const { return mStack.empty(); }
//
//public:
//	void Push(T data)
//	{
//		mStack.push_back(data);
//	}
//
//	bool Pop(T *data)
//	{
//		if (IsStackEmpty())
//		{
//			return FALSE;
//		}
//
//		// 애초에 들어있는 것은 "LIFO"로 들어있지만...
//		// "Trigger"를 줘서 front(), back()에서 Pop할 지 결정이 되네 !!!!
//		if (mIsLIFO)
//		{
//			memcpy(data, &mStack.back(), sizeof(T));
//			mStack.pop_back();
//		}
//		else
//		{
//			memcpy(data, &mStack.at(0), sizeof(T));
//			mStack.erase(mStack.begin());
//		}
//
//		return TRUE;
//	}
//
//	void ShowData()
//	{
//		if (IsStackEmpty())
//		{
//			return;
//		}
//
//		for (size_t i = 0; i < mStack.size(); ++i)
//		{
//			cout << mStack[i] << " ";
//		}
//		cout << endl;
//	}
//
//public:
//	int getSize() const { return static_cast<int>(mStack.size()); }
//	void setIsLIFO(bool isLIFO) { mIsLIFO = isLIFO; }
//
//
//private:
//	vector<T> mStack;
//	bool mIsLIFO; // FALSE면, FIFO
//};
//
//// ###############################################################
//// ### 로비에서 유저 관리하기
//
//typedef struct tagUserInfo
//{
//	tagUserInfo(const char *name, int level, int exp)
//		: level(level)
//	{
//		strcpy_s(userName, name);
//	}
//
//	char userName[16];
//	int level;
//
//} USERINFO;
//
//// 방에는 최대 6명까지 들어갈 수 있고,
//// 가장 먼저 들어 온 사람이 방장이 된다.
//
//class GameLobby
//{
//public:
//	GameLobby()
//	{
//		mUserVec.reserve(6);
//		memset(mMasterName, 0, sizeof(mMasterName));
//	}
//	~GameLobby() {}
//
//public:
//	// 유저 추가
//	bool AddUser(USERINFO &tUserInfo)
//	{
//		if (IsFull() != TRUE)
//		{
//			if (IsEmpty() == TRUE)
//			{
//				strcpy_s(mMasterName, sizeof(mMasterName), tUserInfo.userName);
//			}
//			mUserVec.push_back(tUserInfo);
//			return TRUE;
//		}
//		return FALSE;
//	}
//
//	// 방에서 유저 삭제
//	// 방장이 나가면, 새로운 방장 설정
//	bool DeleteUser(char *userName)
//	{
//		if (IsEmpty() == TRUE)
//		{
//			return FALSE;
//		}
//
//		vector<USERINFO>::iterator iter = mUserVec.begin();
//		for (; iter != mUserVec.end(); ++iter)
//		{
//			if (!(strcmp(userName, mMasterName)))
//			{
//				mUserVec.erase(iter);
//				if (IsEmpty() == TRUE)
//				{
//					memset(mMasterName, 0, sizeof(mMasterName));
//				}
//				else
//				{
//					strcpy_s(mMasterName, sizeof(mMasterName), mUserVec[0].userName);
//				}
//				return TRUE;
//			}
//			else if (!(strcmp(userName, iter->userName)))
//			{
//				mUserVec.erase(iter);
//			}
//		}
//
//		return FALSE;
//	}
//
//	// 유저 쫓아내기
//	bool BanUser(int orderNum)
//	{
//		if (orderNum < static_cast<int>(mUserVec.size()))
//		{
//			vector<USERINFO>::iterator iter = mUserVec.begin();
//			iter += (orderNum - 1);
//
//			mUserVec.erase(iter);
//
//			return TRUE;
//		}
//
//		return FALSE;
//	}
//
//	void ShowLobbyAllUser()
//	{
//		for (size_t i = 0; i < mUserVec.size(); ++i)
//		{
//			if (!(strcmp(mMasterName, mUserVec[i].userName)))
//			{
//				cout << "Master: ";
//			}
//			else
//			{
//				cout << "User: ";
//			}
//			cout << mUserVec[i].userName << endl;
//			cout << "level: " << mUserVec[i].level << endl;
//		}
//		cout << endl;
//	}
//
//	void Clear()
//	{
//		mUserVec.clear();
//	}
//
//	bool IsEmpty() { return mUserVec.empty(); }
//	bool IsFull() { return (mUserVec.size() >= 6) ? TRUE : FALSE; }
//
//public:
//	// 특정 유저의 정보
//	USERINFO* GetUser(char *userName)
//	{
//		if (IsEmpty() != TRUE)
//		{
//			for (size_t i = 0; i < mUserVec.size(); ++i)
//			{
//				if (!(strcmp(userName, mUserVec[i].userName)))
//				{
//					return &mUserVec[i];
//				}
//			}
//		}
//
//		return nullptr;
//	}
//	// 방장의 유저 정보
//	USERINFO* GetMasterUser()
//	{
//		return GetUser(mMasterName);
//	}
//	// 가장 마지막에 들어온 유저 정보
//	USERINFO* GetLastUser()
//	{
//		if (IsEmpty() != TRUE)
//		{
//			return &mUserVec[mUserVec.size() - 1];
//		}
//
//		return nullptr;
//	}
//
//
//private:
//	vector<USERINFO> mUserVec;
//	char mMasterName[16];
//};
//
//
//int main(void)
//{
//	cout << "############################################################" << endl;
//	cout << "### Vector Container를 이용한 LIFO, FIFO 둘 다 되는 Stack" << endl;
//	Stack<int> intStack1;
//	intStack1.setIsLIFO(TRUE);
//
//	intStack1.Push(1);
//	intStack1.Push(2);
//	intStack1.Push(3);
//
//	cout << "### 초기 상태" << endl;
//	intStack1.ShowData();
//
//	int value1 = 0;
//	intStack1.Pop(&value1);
//
//	cout << "LIFO Pop value: " << value1 << endl << endl;
//
//	Stack<int> intStack2;
//	intStack2.setIsLIFO(FALSE);
//
//	intStack2.Push(1);
//	intStack2.Push(2);
//	intStack2.Push(3);
//
//	cout << "### 초기 상태" << endl;
//	intStack2.ShowData();
//
//	int value2 = 0;
//	intStack2.Pop(&value2);
//
//	cout << "FIFO Pop value: " << value2 << endl;
//
//	cout << "############################################################" << endl;
//	cout << "### 온라인 게임의 로비의 유저 관리하기" << endl << endl;
//
//	GameLobby gameLobby;
//
//	cout << "### 초기 상태" << endl;
//	gameLobby.ShowLobbyAllUser();
//
//	cout << "### 유저 추가" << endl;
//	gameLobby.AddUser(USERINFO("AAA", 1, 10));
//	gameLobby.AddUser(USERINFO("BBB", 2, 20));
//	gameLobby.AddUser(USERINFO("CCC", 3, 30));
//	gameLobby.AddUser(USERINFO("DDD", 4, 40));
//
//	gameLobby.ShowLobbyAllUser();
//
//	cout << "### 방장 정보" << endl;
//	USERINFO *pUser = gameLobby.GetMasterUser();
//	if (pUser != nullptr)
//	{
//		cout << pUser->userName << ", " << pUser->level << endl;
//		pUser = nullptr;
//	}
//
//	cout << "### 특정 유저 정보 - 이름" << endl;
//	pUser = gameLobby.GetUser("CCC");
//	if (pUser != nullptr)
//	{
//		cout << pUser->userName << ", " << pUser->level << endl;
//		pUser = nullptr;
//	}
//
//	cout << "### 마지막 유저 정보" << endl;
//	pUser = gameLobby.GetLastUser();
//	if (pUser != nullptr)
//	{
//		cout << pUser->userName << ", " << pUser->level << endl;
//		pUser = nullptr;
//	}
//
//	cout << "### 특정 유저 쫓아내기 - 순서" << endl;
//	gameLobby.BanUser(3);
//
//	gameLobby.ShowLobbyAllUser();
//
//	cout << "### Clear()" << endl;
//	gameLobby.Clear();
//
//	gameLobby.ShowLobbyAllUser();
//
//	cout << "################################################" << endl << endl;
//
//	return 0;
//}