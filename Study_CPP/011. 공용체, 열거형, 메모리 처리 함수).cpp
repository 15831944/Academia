/*



###############################
        공용체 (union)
###############################

- 구조체와 함께 사용자 정의 자료형의 일종이다.
- 데이터의 집합.

- 공용체는 연속된 메모리 공간을 사용하지 않는다.
because, 멤버들은 하나의 메모리 공간을 공유하기 때문이다.
(그렇기 때문에.... 멤버 변수들의 주소가 같음.)

- 멤버 변수 중 가장 크기가 큰 자료형을 기준으로 공용체의 메모리 공간이 할당된다.

ex.

union 공용체 이름
{

};


########################
 공용체 선언과 초기화
########################

struct taxBox // 구조체
{
	short a;
	int b;
};

union uniBox // 공용체
{
	short a;
	int b;
};

tabBox tBox = {};
uniBox uBox = {};

tabBox tBox = { 10, 20 };
uniBox uBox = { 10, 20 }; // 오류 발생 !!!!.
						  // 한 개의 메모리 공간을 공유하기 때문에 값은 "1"개만 입력해야 함.


#######################################################################################################################


#####################################
      열거형 - "enumerated type"
#####################################

- "enumeration"의 약자.

- 사용자 정의 자료형의 일종.
- 상태 변수를 정의하는 데 사용 된다.

- 열거형의 데이터는 상수다 !!!!!
(switch 문에 사용 가능)

- 열거형의 크기는 "4 Bytes"로 고정되어있다.
(내부의 데이터 개수와는 상관이 없다 !!!!!)


ex. 열거형 데이터의 값 설정

enum PlayerStance { IDLE, WALK, ATTACK, END };
					  0    1      2      3

enum PlayerStance { IDLE = 1, WALK, ATTACK, END };
						       2      3      4

enum PlayerStance { IDLE = 2, WALK = 1, ATTACK, END }; // 중복해서 값을 가질 수가 있구나...
										  2      3

enum PlayerStance { IDLE = 1, WALK, ATTACK = 7, END };
				               2                 8	


###########################
   열거형 변수의 초기화
###########################

만약, 일반적인 함수 내에서 지역 변수의 일종으로 선언해서 사용한다면...

PlayerStance stance = WALK; // 이런 식으로 대입해서 쓴다.


- 열거형 변수는 나열된 상수 데이터만 가질 수 있다.
- 일반 상수를 대입할 경우 오류가 발생한다 !!!!


#######################################################################################################################


##############################
       메모리 처리 함수
##############################

- 메모리 공간 사이에 데이터를 초기화, 복사를 수행하는 함수


####################
   메모리 초기화
####################

case 1. memset()

- 메모리 초기화 하는데 사용 됨.
- 각 Byte의 LSB에 초기화 시킬 값을 전달.
- 배열이든, 구조체든 연속된 메모리를 가지는 객체에 대한 메모리 "0"으로 초기화.

void* memset(void *_Dst, int _Val, size_t _Size);

매개변수 void *_Dst : 메모리를 초기화 시킬 변수의 시작 주소를 전달
매개변수 int _Val : 각 Byte의 LSB에 초기화 시킬 값을 전달
매개변수 size_t _Size : 초기화될 공간의 크기 전달.
반환값 void* : _Det 즉, 초기화 된 메모리가 반환 된다.


####################
    메모리 복사
####################

case 2. memcpy()

- 메모리 복사 함수의 일종.
- _Src의 시작 주소부터 _Size만큼 _Dst 시작 주소에 복사하는 함수.
- 인자로 넘겨받는 크기는 Src와 Dst의 사이즈 크기보다 커서는 안 된다.

void* memcpy(void *_Dst, const void *_Src, size_t _Size);

매개변수 void *_Dst : 메모리 복사 받을 메모리 공간의 시작 주소
매개변수 const void *_Src : 메모리 복사를 해줄 메모리 공간의 시작 주소
매개변수 size_t _Size : 복사할 크기
반환값 void* : _Dst 즉, 초기화 된 메모리가 반환 된다.


int arrDst[5] = {};
int arrSrc[5] = { 1, 2, 3, 4, 5 };

// 기존에는 for 문을 이용해서 복사했음.

but, 한 줄에 가능. memcpy(arrDst, arrSrc, sizeof(arrDst));



case 3. memmove()

- 메모리 이동 함수의 일종. (넘겨주는 것을 의미 함.)
but, 실제로 수행하는 것은 memcpy와 동일하게 복사가 이루어진다.
(Source에도 값이 그대로 남아있다는 것을 의미 함.)

- memmove()는 임시 버퍼에 데이터가 잠시 등록된 후에 복사가 이루어진다 !!!!!

void* memmove(void *_Dst, const void *_Src, size_t _Size);

매개변수 void *_Dst : 
매개변수 const void *_Src : 
매개변수 size_t _Size : 
반환값 void* : _Dst 즉, 초기화 된 메모리가 반환 된다.


############################################
    차이점 예제를 확실히 확인할 것 !!!!
############################################

memcpy()는 복사하는 대상을 1개씩 잡기 때문에, 한 개의 값으로 들어갔는데...
but, 개선 되고 나서는 우리가 생각하는 일반적인 방법으로 데이터가 들어감.
(임시 버퍼를 거치지 않고 복사가 이루어진다. 그래서 웬만하면 쓰자?!)
- Linux에서 사용이 불가능할 수도 있다.


memmove()는 임시 메모리를 잡기 때문에, 그냥 데이터가 확실하게 들어감.
but, 오버헤드가 걸리겠지...
- 운영체제에 상관 없이 사용이 가능한 표준 함수이다.

#######################################################################################################################

errno_t memcpy_s(void *const _Destination, const rsize_t _DestinationSize, const void *const _Source, const rsize_t _SourceSize);
errno_t memmove_s(void *const _Destination, const rsize_t _DestinationSize, const void *const _Source, const rsize_t _SourceSize);


#######################################################################################################################



*/

#include <iostream>

using std::cout;
using std::endl;
using std::cin;

enum BATTLE { RUN = 1, AGAIN, HUNT = 7, DIE };

int main(void)
{
	cout << "##################################################################################" << endl;
	cout << "### 공용체 union " << endl << endl;

	struct taxBox
	{
		short a;
		int b;
	};

	union uniBox
	{
		short a;
		int b;
	};

	uniBox uBox = {};


	cout << "##################################################################################" << endl;
	cout << "### 공용체 union 멤버의 주소 확인" << endl << endl;


	cout << "&uBox: " << &uBox << endl;
	cout << "&(uBox.a): " << &(uBox.a) << endl;
	cout << "&(uBox.b): " << &(uBox.b) << endl << endl;

	cout << "##################################################################################" << endl;
	cout << "### 공용체 멤버의 메모리 공유" << endl << endl;

	uBox.a = 10;
	cout << "uBox.a: " << uBox.a << endl;

	uBox.b = 50; // 다른 멤버의 값을 바꾸었는데, 실질적으로 메모리를 공유하기 때문에...
	cout << "uBox.a: " << uBox.a << endl << endl;

	cout << "##################################################################################" << endl;
	cout << "### 공용체를 이용한 float형 자료 찍어보기" << endl << endl;

	union uniTest
	{
		int a;
		float b;
	};

	uniTest uTest = {};
	uTest.b = 3.14;

	// 10진수로 읽은 실수형....
	cout << "uTest.a: " << uTest.a << endl;

	cout << "##################################################################################" << endl;
	cout << "### 열거형 enum 선언과 사용" << endl << endl;

	enum PlayerStance { IDLE, WALK, ATTACK, END };

	PlayerStance stance = WALK; // 이런 식으로 사용 하는 건가...

	switch (stance)
	{
	case IDLE:
		cout << "대기 상태" << endl;
		break;
	case WALK:
		cout << "걷기 상태" << endl;
		break;
	case ATTACK:
		cout << "공격 상태" << endl;
		break;
	}
	cout << endl;

	cout << "BATTLE::RUN - " << BATTLE::RUN << endl;
	cout << "BATTLE::AGAIN - " << BATTLE::AGAIN << endl;
	cout << "BATTLE::HUNT - " << BATTLE::HUNT << endl;
	cout << "BATTLE::DIE - " << BATTLE::DIE << endl << endl;

	cout << "sizeof(BATTLE): " << sizeof(BATTLE) << endl << endl;

	cout << "##################################################################################" << endl;
	cout << "### 메모리 처리 함수 - memset " << endl << endl;

	int a;

	memset(&a, 0, sizeof(int));

	cout << "a: " << a << endl << endl;

	int *ptr = new int[10]; // 동적 배열은 선언과 동시에 초기화 불가능.

	for (int i = 0; i < 10; i++)
	{
		ptr[i] = i;
	}

	for (int i = 0; i < 10; i++)
	{
		cout << ptr[i] << " ";
	}
	cout << endl;

	memset(ptr, 0, sizeof(int) * 10); 

	for (int i = 0; i < 10; i++)
	{
		cout << ptr[i] << " ";
	}
	cout << endl << endl;


	cout << "##################################################################################" << endl;
	cout << "### 메모리 처리 함수 - memcpy, memmove " << endl << endl;

	int arrDst[5] = {};
	int arrSrc[5] = { 1, 2, 3, 4, 5 };

	// 기존에는 for 문을 이용해서 복사했음.

	memcpy(arrDst, arrSrc, sizeof(arrDst));

	for (int i = 0; i < 5; i++)
	{
		cout << arrDst[i] << " ";
	}
	cout << endl << endl;

	int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };

	
	// 두 번째 원소부터 int 형 1개 빼서 9개 복사해라...
	memcpy(arr + 1, arr, sizeof(arr) - 4);
	// 개선 전: 1 1 1 1 1 1 1 1 1 1 - 한 칸씩 복사를 진행하기 때문에 숫자가 밀려서....
	// 개선 후: 1 1 2 3 4 5 6 7 8 9 - 그렇지만, 수정 했기 때문에 원하는 결과 !!!!
	
	for (int i = 0; i < 10; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl << endl;

	int arr2[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	memmove(arr2 + 1, arr2, sizeof(arr2) - 4);
	// 1 1 2 3 4 5 6 7 8 9

	for (int i = 0; i < 10; i++)
	{
		cout << arr2[i] << " ";
	}
	cout << endl << endl;

	cout << "##################################################################################" << endl;
	
		
	return 0;
}
