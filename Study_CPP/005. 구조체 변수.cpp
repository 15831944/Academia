/*

##########################
    구조체_ structure
##########################

- 사용자 자료형의 일종.
- 기본 자료형을 모아서 새로운 자료형을 만드는 것과 동일함.
- 데이터의 집합을 의미함.

- 구조체의 선언은 원래 전역 변수처럼 함수 밖에다가 선언한다.

ex.
struct 구조체 이름 {
	구조체의 변수들 선언.
}; <= 세미콜론 ";", 꼭 있어야 함 !!!!

"struct" 키워드를 통해 구조체를 정의한다는 것을 알려준다.
- 사용자 정의 자료형이므로 사용자가 구조체의 이름을 정해준다.
- {} 중괄호 안에 자료형을 나열하고, 멤버 변수라고 칭한다.
- 구조체의 크기는 멤버 변수의 자료형과 개수에 따라 다르다.

struct StudentInfo {

	char name[20]; // 20 + (4_ Byte Padding)

	int kor;
	int eng; // 4 + 4
	int math;

	int total; // 4 + 4
	double average; // 8
};

##########################
  구조체 변수의 초기화
##########################

struct StudentInfo std1 = {}; // 모든 멤버 변수가 "0"으로 초기화 됨.

struct StudentInfo std2 = { "ABC", 10, 20, 30 }; // 멤버 변수의 선언 순서에 따라 데이터가 초기화 된다.
												// 초기화를 하지 않은 멤버 변수는 "0"으로 초기화 된다.

##########################
	멤버 변수 접근 방식
##########################

case 1. 멤버 접근 연산자 "." Dot 연산자를 통한 직접 접근.

struct StudentInfo std1;

std1.iTotal = std1.kor + std1.eng + std1.math;

if( 구조체 변수의 멤버 변수 중에 문자열을 포함한다면)
- strcpy_s 를 사용하여...

case 2. 간접 참조(접근) 연산자 "->" Arrow 연산자, 포인터 멤버 연산자를 통한 간접 접근.

struct StudentInfo std1;
struct StudentInfo *std2;

std2->iTotal = std2->kor + std2->eng + std2->math;

################################################################################################

########################
    typedef 키워드
########################

- type + define의 약자.
- 긴 자료형의 이름이나 자료형의 이름에 새로운 의미를 부여할 때, 명칭을 바꿔줄 수 있는 키워드

ex.

typedef LinkedListNodeType ListNode; - 긴 자료형의 이름을 간단하게 줄일 때...

typedef int PlayerHp; - 자료형의 이름에 새로운 의미 부여


C++에서는 struct 키워드 내부에 typedef 키워드가 포함된 형태라서 바로 구조체 변수 선언이 가능함.
but, C에서는 struct 키워드를 포함해서 해야 선언이 가능했음 !!!!


################################################################################################

############################
    구조체 변수와 포인터
############################

- 구조체 변수도 일종의 변수니까 메모리 영역의 주소를 할당 받는다.
- 배열처럼 각 멤버가 연속된 메모리에 할당이 됩니다.
- 구조체 변수의 주소와 첫 멤버 변수의 주소가 동일함.

but, 구조체 변수의 이름은 주소가 아니다 !!!!


그런데, 이 때 변수의 순서에 따라 구조체 변수의 크기가 달라짐.
왜냐하면, 메모리 공간을 할당 하는 크기가 달라지기 때문
(멤버 변수 중에 가장 큰 자료형을 기준으로...)


###########################
   구조체의 포인터 선언
###########################

= 포인터 변수의 자료형과 참고하는 변수의 자료형이 일치해야 함.
- 구조체도 자료형의 일종이므로 선언된 구조체의 자료형과 포인터 변수의 자료형은 일치해야함.

Student std1;
Student pStd = &std1;

##################################
	구조체 포인터의 멤버 접근
##################################

- (*std1).x; // Dereferencing을 해도 되지만,
- std1->x; // Arrow 연산자를 통해서 할 수도 있음 !!!!!

################################################################################################

########################
   구조체의 크기 차이
########################

- 멤버 변수의 순서에 따라서도 크기가 달라질 수 있음.

- 멤버 변수 중에 가장 큰 자료형을 가진 멤버의 자료형의 크기로 할당한다.
그리고, 선언된 순서대로 채워 넣는다.
(도중에 메모리가 부족하면 다음번 Byte 크기로 넘어간다.
그리고 Padding Bytes가 발생하니까 생각을 한 번 더 해볼 것 !!!!)

ex.

typedef struct Size1 {

	char a;
	int b;
	double c;
	float d;
};

cout << sizeof(Size1) << endl; // 24

우선, double 형의 크기인 8 Bytes를 기준으로 메모리 공간을 잡는다.

1 + 4 + (3_ Byte Padding)
8
4 + (4_ Byte Padding)

###################################

구조체 안에 다른 구조체의 변수가 멤버로 있으면???

typedef struct Size2 {

	char a;
	int b; // 1 + 4 + (3_ Byte Padding)
	double c; // 8
	struct Size1 size; // 24
};

- 구조체의 모든 기본 자료형들을 모두 모으고,
가장 큰 변수의 자료형에 대한 Bytes를 기준으로 메모리 공간으로 잡는다.


cout << sizeof(Size2) << endl; // 40

// Size2의 멤버를 지우면 몇??
// char a;
// double c; 지우면... // 32

######################
꼭 바꿔서 해볼 것 !!!!
######################

if. 구조체 변수의 멤버 변수에 배열이 있다면 ????

struct A {

	char ch; 
	int num[10]; // 1 + (3_ Byte Padding) + 4(배열의 첫 번째 원소), (4 * 2) * 4 개, 나머지 원소 1개 4 + (4_ Byte Padding)
	double d; // 8
};

- 우선, 8 Bytes 자료형인 double 형이 제일 크기가 크기 때문에, 8 Bytes 단위로 메모리가 할당된다.
- 배열은 연속적으로 할당이 되어야 하므로, "Byte Padding"이 중간에 발생.
- 결국, 8 + 32 + 8 + 8 = 56 !!!!

################################################################################################

#####################################
  자신을 멤버 변수로 가지는 구조체
#####################################

- 자기 자신을 멤버 변수로 가질 때 typedef 키워드로 정의된 이름을 사용하면 안됨.
- 자기 자신의 크기를 구하기 위해서는 계속 타고 들어가야되는 현상이 발생하기 때문에 컴파일 오류 발생
- 그래서, 자기 자신을 멤버로 가지기 위해서는 반드시 구조체 포인터로 정의해야 한다.
- 포인터 크기는 32 bits 기반의 운영체제에서 4 Bytes 크기로 고정되어 있기 때문에, 구조체의 크기를 구하기 위한 무한 루프를 방지할 수 있다.


ex.

typedef struct tagSize {

	char a;
	int b;
	double c;
	float d;
	//tagSize size; // 컴파일 시점에 구조체의 크기를 구할 수가 없어서.
	tagSize *pSize; // 그래서, 크기가 고정되어 있는 값인 주소값.
					// 즉, 포인터로 선언을 한다.

} SIZE;

################################################################################################


*/

#include <iostream>

using std::cout;
using std::endl;


int main(void) {

	cout << "#################################################################" << endl;
	cout << "### 구조체 선언과 정의" << endl << endl;


	struct StudentInfo {

		char name[20];

		int kor;
		int eng;
		int math;

		int total;
		double average;
	};

	// 구조체 변수 선언
	struct StudentInfo student;

	// 구조체 변수 초기화
	struct StudentInfo std1;

	struct StudentInfo std2 = { "ABC", 10, 20, 30 };

	// 구조체 멤버 변수 접근 연산자, Dot 연산자, 직접 접근



	cout << "#################################################################" << endl;
	cout << "### typedef 키워드" << endl << endl;

	typedef int _int;

	int a = 10;
	_int b = 20; // 둘 다 똑같은 자료형인데 명칭만 다르게...



	typedef struct StudentInfo2 {

		char name[20];

		int kor;
		int eng;
		int math;

		int total;
		double average;
	} Student;

	typedef struct StudentInfo2 Student;

	StudentInfo2 std3; // C++에서는 C와는 다르게 구조체 선언에서 typedef 키워드가 포함 되어있으니까
						// struct 키워드를 붙이지 않고도 구조체 변수 선언 가능.

	Student std4; // typedef 키워드로 자료형의 이름을 바꿈.


	cout << "#################################################################" << endl;
	cout << "### 구조체 변수와 포인터" << endl << endl;

	typedef struct Point {

		int x;
		int y;
	} Pos;

	Pos pos1;

	cout << "&pos1: " << &pos1 << endl;
	cout << "&(pos1.x): " << &(pos1.x) << endl;
	cout << "&(pos1.y): " << &(pos1.y) << endl << endl;

	cout << "#################################################################" << endl;
	cout << "### 구조체 변수의 크기 차이 1" << endl << endl;

	struct A { // 구조체 변수 중에 가장 크기가 큰 double 형 8 Bytes 규모의 공간이 잡힌다.

		char a;
		int b; // 1 + 4 + (3_ Byte Padding)
		float c; // 4 + (4_ Byte Padding)
		double d; // 8
	};

	struct B {

		float c; // 4 + (4_ Byte Padding)
		double d; // 8
		int b;
		char a; // 4 + 1 + (3_ Btye Padding)
	};

	cout << "sizeof(A): " << sizeof(A) << endl; // 24 Bytes
	cout << "sizeof(B): " << sizeof(B) << endl << endl; // 24 Btyes

	// 비교해볼 것.

	cout << "#################################################################" << endl;
	cout << "### 구조체 변수의 크기 차이 2" << endl << endl;

	struct C {

		char ch;
		int b; // 1 + 4 + (3_ Byte Padding)

		struct A a;

		/*
		우선, 구조체 A의 변수들 까지 모아놓고 가장 큰 자료형의 크기를 구해야 함.

		char a;
		int b; // 1 + 4 + (3_ Byte Padding)
		float c; // 4 + (4_ Byte Padding)
		double d; // 8

		double 형이 8 Bytes로 제일 크기 때문에, 메모리 공간이 8 Bytes 단위로 잡힐 것임.

		이제, 구조체 C 멤버 변수를 할당하고, 그 다음에 메모리 공간을 새로 확보해서 A 구조체의 멤버를 채워나갈 것임.
		*/
	};

	cout << "sizeof(C): " << sizeof(C) << endl << endl; // 32

	cout << "#################################################################" << endl;
	cout << "### 구조체 변수의 크기 차이 3" << endl << endl;

	struct D {

		char a;
		int b; // 1 + 4 + (3_ Byte Padding)
		char c; // 1 + (7_ Byte Padding)
		double e; // 8
		float f;
		struct D *d; // 4 + 4

		//struct D d; // 구조체의 크기를 결정할 수 없음.
					// 자기 참조를 위해서는 포인터 변수를 이용해야 함.
	};

	cout << "sizeof(D): " << sizeof(D) << endl << endl; // 32

	cout << "#################################################################" << endl;
	cout << "### 구조체 변수의 크기 차이 4" << endl << endl;

	struct StudentInfo3 {

		char name[20]; // 20 + (4_ Byte Padding)
						// 해당 배열은 char 형이 모인 것이니까 1 Byte 씩 계산

		int kor;
		int eng; // 4 + 4
		int math;

		int total; // 4 + 4
		double average; // 8
	};

	cout << "sizeof(StudentInfo3): " << sizeof(StudentInfo3) << endl << endl; // 48

	cout << "#################################################################" << endl;



	return 0;
}
