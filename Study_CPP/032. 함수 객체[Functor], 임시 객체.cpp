/*

################################
   함수 객체(Function Objects)    = Functor !!!!
################################

- "Function Call Operator -  ()"를 "Operator Overloading"을 하여, 객체를 함수처럼 쓰는 것을 말합니다.

- "Function Objects"는 "Functor"라고 불립니다 !!!!



################################
  함수 객체, "Functor"의 장점
################################

- 함수 객체는 같은 호출 문장이라도 실제 어떤 객체냐에 따라,
각기 다른 상태를 지니게 해주는 이점이 있습니다.

- header 파일의 클래스 선언부에 멤버 함수의 몸체까지 정의되어 있다면...
해당 멤버 함수는 자동 inline화 되어 일반 함수에 비해 속도가 빠르다.
(물론, 컴파일러가 판단 하겠지...)


################################################################################################

##################################
   임시 객체(Temporary Objects)
##################################

- 이름 없이 임시 메모리 공간을 할당 받는 객체를 말합니다.


####################################
    일반 객체와 임시 객체의 차이
####################################

case 1. 일반 객체(영역 내 모든 선언된 것/ ex. 지역 변수 등...)
- 함수가 종료되기 전까지 메모리에 남아있는다.

case 2. 임시 객체
- 해당 코드라인을 벗어나자마자 소멸된다!



################################
   임시 객체를 사용하는 이유
################################

- 코드라인을 간결화 시킬 수 있다.

- 임시 객체는 일반 객체와 달리 메모리에 계속 상주하는 것이 아니기 때문에,
메모리 관리 측면에서 효율적입니다.


#####################################################################################
특히, 반환형이 "Reference"가 아니고 일반 자료형일 때...
임시 객체를 반환하지만, 그대로 바로 넣어주는 것으로 컴파일러가 최적화를 진행한다 !!!!
#####################################################################################


Assignment 예제에서 Point 클래스의 멤버인 operator+() 부분에 바로 임시객체 반환 !!!!


################################################################################################


*/


#include <iostream>

#define TRUE 1
#define FALSE 0

using std::cout;
using std::endl;
using std::cin;

/////////////////////////////////////////////////////////////////////////////
// Functor(Function Objects) //
///////////////////////////////
class Plus // 얘가 함수 객체(Function Objects)
{		   // 즉, "Functor"
public:
	int operator() (int a, int b)
	{
		return a + b;
	}
};

class SortRule
{
public:
	virtual bool operator() (int a, int b) = 0;
};

class Ascending : public SortRule  // 얘도 Functor !!!!
{
public:
	virtual bool operator() (int a, int b)
	{
		if (a > b)
		{
			return TRUE;
		}
		else
		{
			return FALSE;
		}
	}
};

class Descending : public SortRule  // 얘도 Functor !!!!
{
public:
	virtual bool operator() (int a, int b)
	{
		if (a < b)
		{
			return TRUE;
		}
		else
		{
			return FALSE;
		}
	}
};


void BubbleSort(int arr[], const int size, SortRule &functor)
{
	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < (size - 1) - i; ++j)
		{
			if (functor(arr[j], arr[j + 1]))
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}


////////////////////////////////////////////////////////////////
// Temporary Object //
//////////////////////
class Obj
{
public:
	Obj() {}
	Obj(char *pName)
	{
		strcpy_s(name, 16, pName);
		cout << name << "의 생성자 호출" << endl;
	}

	~Obj()
	{
		cout << name << "의 소멸자 호출" << endl;
	}

private:
	char name[16];
};


int main(void)
{
	cout << "###############################################################" << endl;
	cout << "### Functor = Functon Objects" << endl << endl;
	Plus functor; // 객체를 함수처럼 사용하고 있다 !!!!
	cout << functor(10, 20) << endl << endl;

	// "operator()"를 통해 객체를 함수처럼 다루고 있습니다.
	// 이를 함수 객체라고 하며, Functor라고 부릅니다.


	// ###################################################################

	cout << "함수 객체(Functor) 활용 - 버블 정렬" << endl;

	Ascending ascend; // Functor
	Descending descend;
	
	int arr1[5] = { 5, 3, 1, 4, 2 };

	BubbleSort(arr1, sizeof(arr1) / sizeof(int), ascend);

	for (int i = 0; i < 5; i++)
	{
		cout << arr1[i] << " ";
	}
	cout << endl;

	int arr2[5] = { 5, 3, 1, 4, 2 };
	
	BubbleSort(arr2, sizeof(arr2) / sizeof(int), descend);

	for (int i = 0; i < 5; i++)
	{
		cout << arr2[i] << " ";
	}
	cout << endl;


	cout << "###############################################################" << endl;
	cout << "### Temporary Objects" << endl << endl;

						  // 일반 객체는 이름을 갖습니다.
	Obj obj("일반 객체"); // 일반 객체는 함수가 종료되기 전까지 메모리에 남아있다 !!!!!
	cout << endl;		  // main() 함수가 종료되서 소멸자 호출.

	cout << "========================================" << endl;
	Obj("임시 객체"); // 임시 객체는 이름이 없습니다.
					  // 임시 객체는 해당 코드라인을 벗어나면 소멸된다 !!!!
	cout << "###############################################################" << endl;

	return 0;
}