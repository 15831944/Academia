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
//// ###########################################################################
//// 원래 "Stack"은 LIFO 구조.
//// but, Queue처럼 FIFO 구조도 가능하며, 저장 공간의 크기가 가변적이게 바꿔볼 것임.
//// ###########################################################################
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
//			memcpy(data, &mStack.front(), sizeof(T));
//			mStack.pop_front();
//		}
//
//		return TRUE;
//	}
//
//public:
//	int getSize() const { return static_cast<int>(mStack.size()); }
//	void setIsLIFO(bool isLIFO) { mIsLIFO = isLIFO; }
//
//
//private:
//	list<T> mStack;
//	bool mIsLIFO; // FALSE면, FIFO
//};
//
//
//int main(void)
//{
//	Stack<int> intStack;
//	intStack.setIsLIFO(TRUE);
//
//	intStack.Push(10);
//	intStack.Push(20);
//	intStack.Push(30);
//
//	int value = 0;
//	intStack.Pop(&value);
//
//	cout << "LIFO Pop: " << value << endl << endl;
//
//	intStack.Clear();
//
//	cout << "#########################################" << endl;
//
//	intStack.setIsLIFO(FALSE);
//
//	intStack.Push(10);
//	intStack.Push(20);
//	intStack.Push(30);
//
//	intStack.Pop(&value);
//
//	cout << "FIFO Pop: " << value << endl << endl;
//
//
//	return 0;
//}
//
//// assign();
//// get_allocator();
//// max_size();
//// merge();
//// resize();
//// reverse();
//// splice();
//// swap();
//// unique();
