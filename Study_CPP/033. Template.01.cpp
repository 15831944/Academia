/*

###############################
	   템플릿(template)
###############################

- 함수나 클래스가 각기 다른 자료형에서 동작할 수 있도록 하는 문법입니다.
(템플릿은 거푸집에 빗대어 표현할 수 있습니다.)


- "정의 해놓은 하나의 틀"에서 계속해서 찍어낼 수 있는 문법입니다.

######################################################################################################


###################################
case 1. 템플릿을 사용하지 않은 경우
###################################
- Function Overloading을 통해 각기 다른 자료형을 사용할 수 있지만, 비효율적이다 !!!!


#######################################
case 2. Function Template (함수 템플릿)
#######################################

- 모양은 함수지만 "template"으로 정의했기 때문에, "함수 템플릿"이라고 합니다.

"template <typename T>"의 형태로 선언합니다.
- T 자리에 오는 자료형을 모두 호환하는 템플릿으로 정의하는 것을 말합니다.



###################################
So, Template Function (템플릿 함수)
###################################

- 템플릿 함수 호출 시, 함수 명 뒤에 오는 <> 안에 자료형을 적어줍니다.
적어준 자료형은 "template"의 "T"자리에 매칭됩니다.

- 명시하지 않는다면, 인자의 자료형에 따라 매칭됩니다.

#########################################################################
- "Template Function"은 컴파일러에 의해 생성되는 함수입니다.
그래서, 컴파일 과정 중에 해당 함수가 어떤 자료형으로 호출될지 결정 될 때,
실제 함수 코드가 생성이 됩니다.
#########################################################################



############################
	함수 템플릿의 주의점
############################

- 해당 함수의 연산을 수행할 수 없는 자료형이 오는 경우, 문제가 발생합니다 !!!!

ex. 정수 및 실수의 덧셈 연산인 Add 함수 기반으로 Function Template을 정의했는데,
typename으로 받은 자료형이 (char *) 자료형일 경우 문제가 발생합니다.

- (char *) 자료형의 문자열에 대해서는 일반적인 의미의 덧셈이 불가능 합니다.

그래서, 예외 상황을 처리하기 위해서 Template Specialization(템플릿 특수화)가 필요합니다.

######################################################################################################

################################
    Template Specialization
################################

template<> angle brakets 안에 자료형을 적지 않는다 !!!!
- 애초에 자료형을 명시해서 템플릿을 만듭니다.

ex.

template<> // <> angle brakets 안에 자료형을 적지 않는다 !!!!
char* Add(char * a, char *b)
{
	cout << "char* Add(char * a, char *b)" << endl;
	int len = strlen(a) + strlen(b);
	char *pName = new char[len + 1];

	strcpy_s(pName, len + 1, a);
	strcat_s(pName, len + 1, b);

	return pName;
}



#######################################
  2 개 이상의 자료형을 받는 Template
#######################################

ex. template <typename T1, typename T2, typename T3>

","를 사용하여 typename의 개수만큼 구분지어주면 됩니다.

지정한 typename의 순서대로 명시한 자료형을 매칭시켜준다.

######################################################################################################


*/


#include <iostream>

using std::cout;
using std::endl;
using std::cin;

////////////////////////////////////////////////////////////////////////////////////
// Function Template(함수 템플릿)
template <typename T>
T Add(T a, T b)
{
	return a + b;
}

////////////////////////////////////////////////////////////////////////////////////
// Template Specialization(템플릿 특수화)
template<> // <> angle brakets 안에 자료형을 적지 않는다 !!!!
char* Add(char * a, char *b)
{
	cout << "char* Add(char * a, char *b)" << endl;
	int len = strlen(a) + strlen(b);
	char *pName = new char[len + 1];

	strcpy_s(pName, len + 1, a);
	strcat_s(pName, len + 1, b);

	return pName;
}

template<>
const char* Add(const char *a, const char *b) // Function Template 오버로딩
{											  // 템플릿 함수 사용 시, 특수화 시키는 자료형에 따라서 호출..
	cout << "const char* Add(const char *a, const char *b)" << endl;
	int len = strlen(a) + strlen(b);
	char *pName = new char[len + 1];

	strcpy_s(pName, len + 1, a);
	strcat_s(pName, len + 1, b);

	return pName;
}

////////////////////////////////////////////////////////////////////////////////////
// 2 개 이상의 자료형을 받는 Function Template
template <typename T1, typename T2, typename T3>
T3 Add(T1 a, T2 b)
{
	return a + b;
}

////////////////////////////////////////////////////////////////////////////////////

int main(void)
{
	cout << "##############################################################################" << endl;
	cout << "### Template Function" << endl << endl;

	// "함수 템플릿"을 이용한 "템플릿 함수" !!!!
	cout << Add<int>(10, 20) << endl;
	cout << Add<float>(3.14f, 3.14f) << endl;
	cout << Add<double>(3.1415, 3.1415) << endl;

	cout << "##############################################################################" << endl;
	cout << "### Template Specialization" << endl << endl;

	char *pStr1 = Add<char *>("Hello", "World");
	cout << pStr1 << endl << endl;
	delete[] pStr1;


	// 템플릿 함수를 지정해줄 때, 넣는 자료형에 따라서 결정되는 것 !!!!
	//const char *pStr2 = Add<char *>("Hello", "World"); // (char *) 자료형
	const char *pStr2 = Add<const char *>("Hello", "World"); // (const char *) 자료형
	cout << pStr2 << endl;
	delete[] pStr2;


	cout << "##############################################################################" << endl;
	cout << "### 2개 이상의 자료형을 사용하는 Template" << endl << endl;

	double dNum = Add<int, float, double>(10, 1.1f);

	cout << "dNum: " << dNum << endl;

	cout << "##############################################################################" << endl;

	return 0;
}
