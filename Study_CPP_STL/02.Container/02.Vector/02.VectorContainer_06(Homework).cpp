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
//// "Vector Container"�� LIFO, FIFO �� �� ������ Stack �����
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
//		// ���ʿ� ����ִ� ���� "LIFO"�� ���������...
//		// "Trigger"�� �༭ front(), back()���� Pop�� �� ������ �ǳ� !!!!
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
//	bool mIsLIFO; // FALSE��, FIFO
//};
//
//// ###############################################################
//// ### �κ񿡼� ���� �����ϱ�
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
//// �濡�� �ִ� 6����� �� �� �ְ�,
//// ���� ���� ��� �� ����� ������ �ȴ�.
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
//	// ���� �߰�
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
//	// �濡�� ���� ����
//	// ������ ������, ���ο� ���� ����
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
//	// ���� �ѾƳ���
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
//	// Ư�� ������ ����
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
//	// ������ ���� ����
//	USERINFO* GetMasterUser()
//	{
//		return GetUser(mMasterName);
//	}
//	// ���� �������� ���� ���� ����
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
//	cout << "### Vector Container�� �̿��� LIFO, FIFO �� �� �Ǵ� Stack" << endl;
//	Stack<int> intStack1;
//	intStack1.setIsLIFO(TRUE);
//
//	intStack1.Push(1);
//	intStack1.Push(2);
//	intStack1.Push(3);
//
//	cout << "### �ʱ� ����" << endl;
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
//	cout << "### �ʱ� ����" << endl;
//	intStack2.ShowData();
//
//	int value2 = 0;
//	intStack2.Pop(&value2);
//
//	cout << "FIFO Pop value: " << value2 << endl;
//
//	cout << "############################################################" << endl;
//	cout << "### �¶��� ������ �κ��� ���� �����ϱ�" << endl << endl;
//
//	GameLobby gameLobby;
//
//	cout << "### �ʱ� ����" << endl;
//	gameLobby.ShowLobbyAllUser();
//
//	cout << "### ���� �߰�" << endl;
//	gameLobby.AddUser(USERINFO("AAA", 1, 10));
//	gameLobby.AddUser(USERINFO("BBB", 2, 20));
//	gameLobby.AddUser(USERINFO("CCC", 3, 30));
//	gameLobby.AddUser(USERINFO("DDD", 4, 40));
//
//	gameLobby.ShowLobbyAllUser();
//
//	cout << "### ���� ����" << endl;
//	USERINFO *pUser = gameLobby.GetMasterUser();
//	if (pUser != nullptr)
//	{
//		cout << pUser->userName << ", " << pUser->level << endl;
//		pUser = nullptr;
//	}
//
//	cout << "### Ư�� ���� ���� - �̸�" << endl;
//	pUser = gameLobby.GetUser("CCC");
//	if (pUser != nullptr)
//	{
//		cout << pUser->userName << ", " << pUser->level << endl;
//		pUser = nullptr;
//	}
//
//	cout << "### ������ ���� ����" << endl;
//	pUser = gameLobby.GetLastUser();
//	if (pUser != nullptr)
//	{
//		cout << pUser->userName << ", " << pUser->level << endl;
//		pUser = nullptr;
//	}
//
//	cout << "### Ư�� ���� �ѾƳ��� - ����" << endl;
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