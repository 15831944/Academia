/*


##################################
  템플릿 클래스(Template Class)
##################################

- 클래스 템플릿을 이용하여 클래스를 만든 것.
- 클래스의 멤버 중 "T"로 정의한 것을 "<>" (angle bracket)에 명시한 자료형으로 매칭시킵니다.
- 컴파일 시점에 클래스가 어떤 자료형을 토대로 정해질 지 결정될 때
 해당 클래스의 코드가 생성 되므로, "Template Class"라고 합니다.

 ex.
 Point<int> intPoint(10, 20);
 Point<float> floatPoint(3.14f, 10.06f);

#######################################################################################################

################################
	  템플릿의 파일 분할
################################

- 템플릿을 파일 분할하여 사용할 때,
사용하는 소스 코드에서는 템플릿의 정의부에 대한 정보도 필요합니다.
So, "Template"의 구현부도 포함시켜야 합니다 !!!!



###############################################
	템플릿의 정의부(구현부)가 필요한 이유
###############################################

- 템플릿 함수, 템플릿 클래스는 컴파일러에 의해 사용될 자료형의 결정 및 코드를 생성합니다.
but, header 파일과 source 파일의 연결 작업은 Linker(링커)가 하는 역할입니다 !!!!
So, 사용하는 소스 코드에서 header 파일만 포함해서는 컴파일러가 정의부(구현부)의 내용을 모릅니다.

#######################################################################################################

##############################################
  [함수, 클래스] 템플릿과 static(정적) 변수
##############################################

#########################
case 1. Function Template
#########################

- 함수 템플릿의 static 변수는 각 자료형들의 템플릿에 대하여 독립적으로 존재합니다.
"<>" (angle bracket)으로 넘긴 같은 자료형의 템플릿 함수끼리 해당 자료형의 static 변수를 공유합니다.

######################
case 2. Class Template
######################

- 클래스 템플릿의 경우에도 각 자료형에 대한 템플릿 클래스들은 동일 static 변수를 공유합니다.


#######################################################################################################

#############################
		템플릿의 상속
#############################

- 기존 상속과 동일하며,
클래스 선언 윗 부분에 "template <typename T>"와 상위 클래스에 "<T>"를 추가하면 됩니다.

#######################################################################################################

#########################
	  템플릿의 특징
#########################

- 모든 자료형과 호환이 가능합니다
- 컴파일 시점에 템플릿에 대한 소스 코드가 생성되므로,
오류가 발생하기 전에 컴파일러에 의해 검사할 수 있어 안전합니다.
- 컴파일 차원에서 소스 코드를 생성하므로 속도의 측면에서 뛰어납니다.

but, 자료형에 따라 실행 코드가 일일이 생성되므로 실행파일의 크기가 커질 수 있습니다.
(코드의 비대화?!)

#######################################################################################################

*/

#include <iostream>
using std::cout;
using std::endl;

#include "2019.04.29.01.template.h"
#include "2019.04.29.01.template.cpp" // 템플릿을 파일분할 했을 때,
// 컴파일러가 템플릿의 구현부를 알아야 컴파일이 가능합니다.
// So, 템플릿의 구현부도 포함시켜야 합니다 !!!!

///////////////////////////////////////////////////////////////////////////////////////////////////////////
//// Class Template(클래스 템플릿)
template <typename T>
class Point
{
public:
	Point() {}
	Point(T x, T y) : mXPos(x), mYPos(y) {}
	~Point() {}

public:
	T mXPos;
	T mYPos;
};


template <typename T>
class Plus
{
public:
	T Add(T a, T b) { return a + b; }
};

template <> // Class Template Specialization
class Plus<char *> // (클래스 템플릿의 특수화)
{
public:
	char* Add(char *a, char *b) // 문자열 concatenation
	{							// 동일한 함수 명이라고 해도 자료형에 따른 다른 의미를 부여 가능.
		int len = strlen(a) + strlen(b);
		char *pStr = new char[len + 1];

		strcpy_s(pStr, len + 1, a);
		strcat_s(pStr, len + 1, b);

		return pStr;
	}
};
///////////////////////////////////////////////////////////////////////////////////////////////////////////
// static 변수와 템플릿

// case 1. Function Template
template <typename T>
T FuncSum(T num)
{
	static T sum = 0;
	sum += num;

	return sum;
}

// case 2. Class Template
template <typename T>
class Test
{
public:
	Test() {}
	~Test() {}

public:
	T FuncSum(T num)
	{
		mSum += num;
		return mSum;
	}

private:
	static T mSum;
};

template <typename T>
T Test<T>::mSum = 0; // static 멤버 변수는 클래스 외부의 header 파일에서 초기화를 해야 함.

///////////////////////////////////////////////////////////////////////////////////////////////////////////
// 템플릿의 상속

template <typename T>
class Obj
{
private:
	T mNum1;
};

template <typename T>
class Player : public Obj<T>
{
private:
	T mNum2;
};

///////////////////////////////////////////////////////////////////////////////////////////////////////////

int main(void)
{
	cout << "#############################################################" << endl;
	cout << "### 클래스 템플릿과 템플릿 클래스" << endl << endl;

	// 클래스 템플릿은 템플릿
	// 템플릿 클래스는 클래스 템플릿을 이용하여 클래스를 만든 것 !!!!

	Point<int> intPoint(10, 20);
	Point<float> floatPoint(3.14f, 10.06f);

	cout << "#############################################################" << endl;
	cout << "### 템플릿의 파일 분할" << endl << endl;

	// "Template"을 파일 분할하여 사용할 경우...
	// header 파일만 포함해서는 컴파일러가 템플릿의 정의부(구현부)의 내용을 모릅니다.
	// So, 컴파일 오류 발생 !!!!

	Example<int> example(10);
	cout << "템플릿 파일 분할: " << example.Add(5) << endl << endl;

	cout << "#############################################################" << endl;
	cout << "### 템플릿과 static 변수" << endl << endl;

	//cout << "case 1. Function Template" << endl;
	// 각 자료형에 따른 "Template Function"은 static 변수를 공유합니다.
	cout << FuncSum<int>(42) << endl;
	cout << FuncSum<int>(424) << endl;

	cout << FuncSum<float>(3.14f) << endl;
	cout << FuncSum<float>(13.14f) << endl << endl << endl;

	//cout << "case 2. Class Template" << endl;
	// 각 자료형에 따른 "Template Class"는 static 변수를 공유합니다.
	Test<int> intTest;
	Test<float> floatTest;

	cout << intTest.FuncSum(42) << endl;
	cout << intTest.FuncSum(424) << endl;

	cout << floatTest.FuncSum(3.14f) << endl;
	cout << floatTest.FuncSum(13.14f) << endl << endl;


	cout << "#############################################################" << endl;


	return 0;
}