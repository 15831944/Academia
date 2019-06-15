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
//// ########################################################
//// "Deque Container"로 LIFO, FIFO 둘 다 가능한 Stack 만들기
////
//// 그리고, Undo, Redo 기능 구현하기 !!!!
//// Undo: 마지막 수행한 연산(Push, Pop)을 되돌리기
//// Redo: 마지막 수행한 연산을 한 번 더 수행하기
//// ########################################################
//
//
//template <typename T>
//class Stack
//{
//public:
//	Stack()
//		: meCurOperation(OPERATION::END),
//		mIsLIFO(TRUE)
//	{
//		Clear();
//	}
//
//private:
//	enum OPERATION
//	{
//		PUSH,
//		POP,
//		END
//	};
//
//public:
//	void Clear() { if (mStack.empty() != TRUE) mStack.clear(); }
//	bool IsStackEmpty() const { return mStack.empty(); }
//
//public:
//	void Push(T data)
//	{
//		meCurOperation = OPERATION::PUSH;
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
//		meCurOperation = OPERATION::POP;
//
//		// 애초에 들어있는 것은 "LIFO"로 들어있지만...
//		// "Trigger"를 줘서 front(), back()에서 Pop할 지 결정이 되네 !!!!
//		if (mIsLIFO)
//		{
//			memcpy(data, &mStack.back(), sizeof(T));
//			mTempDataStack.push_back(mStack.back());
//			mStack.pop_back();
//		}
//		else
//		{
//			memcpy(data, &mStack.at(0), sizeof(T));
//			mTempDataStack.push_back(mStack.front());
//			mStack.erase(mStack.begin());
//		}
//
//		return TRUE;
//	}
//
//	// Undo: 마지막 수행한 연산(Push, Pop)을 되돌리기
//	bool Undo()
//	{
//		if (meCurOperation == OPERATION::PUSH)
//		{
//			meCurOperation = OPERATION::POP;
//
//			if (mIsLIFO)
//			{
//				mTempDataStack.push_back(mStack.back());
//				mStack.pop_back();
//			}
//			else
//			{
//				mTempDataStack.push_back(mStack.front());
//				mStack.pop_front();
//			}
//
//			return TRUE;
//		}
//		else if (meCurOperation == OPERATION::POP)
//		{
//			if (IsStackEmpty() != TRUE)
//			{
//				meCurOperation = OPERATION::PUSH;
//
//				if (mIsLIFO)
//				{
//					mStack.push_back(mTempDataStack.front());
//				}
//				else
//				{
//					mStack.push_front(mTempDataStack.front());
//				}
//
//				mTempDataStack.pop_front();
//
//				return TRUE;
//			}
//		}
//
//		return FALSE;
//	}
//
//	// Redo: 마지막 수행한 연산을 한 번 더 수행하기
//	bool Redo()
//	{
//		if (meCurOperation == OPERATION::PUSH)
//		{
//			if (mIsLIFO)
//			{
//				mStack.push_back(mStack.back());
//			}
//			else
//			{
//				mStack.push_front(mStack.front());
//			}
//
//			return TRUE;
//		}
//		else if (meCurOperation == OPERATION::POP)
//		{
//			if (mTempDataStack.empty() != TRUE)
//			{
//				if (mIsLIFO)
//				{
//					mTempDataStack.push_back(mStack.back());
//					mStack.pop_back();
//				}
//				else
//				{
//					mTempDataStack.push_back(mStack.front());
//					mStack.pop_front();
//				}
//
//				return TRUE;
//			}
//		}
//
//		return FALSE;
//	}
//
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
//	deque<T> mStack;
//	deque<T> mTempDataStack;
//
//	OPERATION meCurOperation;
//	bool mIsLIFO; // FALSE면, FIFO
//};
//
//
//
//
//
//int main(void)
//{
//	cout << "####################################################" << endl;
//	cout << "### case 1. LIFO Stack" << endl;
//	Stack<int> stack1;
//	stack1.setIsLIFO(TRUE);
//
//	stack1.Push(1);
//	stack1.Push(2);
//	stack1.Push(3);
//
//	cout << "### 초기 상태 " << endl;
//	stack1.ShowData();
//
//	cout << "### Undo(LIFO - PUSH)" << endl;
//	stack1.Undo();
//	stack1.ShowData();
//
//	cout << "### Undo()" << endl;
//	stack1.Undo();
//	stack1.ShowData();
//	cout << endl;
//
//	cout << "####################" << endl;
//	int popData = 0;
//	stack1.Pop(&popData);
//
//	cout << "### Pop(LIFO) : " << popData << endl;
//	stack1.ShowData();
//
//	cout << "### Undo(LIFO - POP)" << endl;
//	stack1.Undo();
//	stack1.ShowData();
//
//	cout << "### Undo()" << endl;
//	stack1.Undo();
//	stack1.ShowData();
//	cout << endl;
//
//	cout << "####################################################" << endl;
//	cout << "### case 2. FIFO Stack" << endl;
//	Stack<int> stack2;
//	stack2.setIsLIFO(FALSE);
//
//	stack2.Push(1);
//	stack2.Push(2);
//	stack2.Push(3);
//	stack2.Push(4);
//
//	cout << "### 초기 상태 " << endl;
//	stack2.ShowData();
//
//	cout << "### Undo(FIFO - PUSH)" << endl;
//	stack2.Undo();
//	stack2.ShowData();
//
//	cout << "### Undo()" << endl;
//	stack2.Undo();
//	stack2.ShowData();
//	cout << endl;
//
//	cout << "####################" << endl;
//	popData = 0;
//	stack2.Pop(&popData);
//
//	cout << "### Pop(FIFO) : " << popData << endl;
//	stack2.ShowData();
//
//	cout << "### Undo(FIFO - POP)" << endl;
//	stack2.Undo();
//	stack2.ShowData();
//
//	cout << "### Undo()" << endl;
//	stack2.Undo();
//	stack2.ShowData();
//	cout << endl;
//
//
//	return 0;
//}