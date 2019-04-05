/*

#################
	 자료형
#################

 1. 자료형의 종류

- 기본 자료형: 프로그램 언어에서 기본적으로 제공하는 타입

- 사용자 정의 자료형: 사용자 필요에 맞게 디자인하는 타입


 2. 기본 자료형.

- 정수 자료형
 short, int, long, long long

- 실수 자료형
 float, double, long double

- 단일 문자 자료형
 char

- 논리 자료형 (C++부터 등장한, 참 또는 거짓을 표현하는 자료형)
 bool

 3. 기본 자료형의 크기.

프로그램 자료 크기의 최소 단위 = bit (비트)

1byte(1 바이트) = 8bits

byte는 기본적으로 2의 n승으로 증가한다.

- 1byte의 크기의 자료형 (8bits)
 char, bool

- 2bytes의 크기의 자료형 (16bits)
 short

- 4bytes의 크기의 자료형 (32bits)
 int, long, float
 (int, long은 둘 다 정수 자료형인데 왜 바이트 수가 같은가?
 운영체제(OS)나 시스템 환경에 따라 길이가 다를 수도 있다!!!

 16bits 환경에서 int는 2bytes의 크기를 가졌다.
 32bits 환경에서 int는 4bytes의 크기를 가진다.)



- 8bytes의 크기의 자료형 (64bits)
 long long, double, long double


 4. 정수 표현 방식
 unsigned / signed

 unsigned char : 1byte(8bits)
 - 문자 자료형이지만 아스키코드 값을 문자로 표현할 뿐, 실제로 저장되는 건 정수형 데이터.

 unsigned short : 2bytes(16bits)

 unsigned int, long : 4bytes(32bits)

 unsigned long long : 8bytes(64bits)


 5. 음의 정수 표현법

 맨 앞의 비트 (MSB)가 부호 비트
 (0은 양수, 1은 음수)

 2의 보수를 사용하여 음수 표현 함.
 (1의 보수 + 1)


 6. 실수 자료형의 표현 방식

 (1) 고정 소수점 방식
 - 정수부와 소수부로 비트를 나눔.
 - but, 표현 범위가 작다 !!!!

 ex. 32bits

  1     15     16
 부호 정수부 소수부

 (2) 부동 소수점 방식
- 가수부(m)와 지수부(e)로 나누어 표현
- 가수는 유효숫자 / 지수는 소수점의 위치
- +/- (1.m)^(e-127)
- but, 오차가 존재한다 !!!!

ex. 32 bits

 1      8     23
부호 가수부 지수부

ex. 64 bits

 1     11     52
부호 가수부 지수부


7. escape sequence 이스케이프 문자열?
- 형태는 문자열인데 단일 문자로 취급된다.
ex.
\n(개행), \t(탭), \0(NULL문자) 등...

8. char 자료형
- 단일 문자를 갖는다, 1byte의 크기
- 단일 문자는 아스키 코드를 통해 정수 값을 문자로 출력할 뿐이다.

아스키 코드는 128개
- 맨 앞의 1bit는 Parity Bit(패리티 비트)라고 하여, 통신 에러 검출을 위해 사용한다.
- Parity bit를 제외한 7bits로는 영문 키보드로 입력할 수 있는 모든 키를 포함한다.

- 다른 언어를 표현하기에는 부족하다.
- 그래서 8bits의 아스키 코드가 나왔는데, ANSI코드라고 불렸다.

- So, 다른 나라(비 유럽 국가, 한국 중국 등)의 언어의 문자를 포함시키기 위해 유니코드라는 국제 표준 코드가 등장함.

9. bool 자료형
- 저장되어 있는 값이 0(거짓) or 0이 아닌 숫자(참)

10. 상수
- 변하지 않고 고정되어 있는 수
- const 키워드를 자료형 앞에 붙이면 된다.
- const 키워드는 값을 변경할 수 없도록 하는 키워드.


- 그래서, 반드시 const 변수는 선언과 동시에 초기화를 해야한다 !!!!


11. 리터럴 상수
- 이미 정해져 있는 값.
- 리터럴 상수는 임시 메모리에 저장되며,
 정수형이라면 기본적으로 int형으로 간주된다.
 실수형이라면 기본적으로 double형으로 간주된다.
 (float이라면 float형 + f 키워드
  리터럴 상수의 default가 double형이므로 8bytes의 크기를 가진다.
  8bytes에서 4bytes로 변경될 때 데이터 손실이 발생한다 !!!!
  그래서, 임시 메모리의 크기를 float형의 크기인 4bytes로 맞춰주기 위해서 f 키워드를 붙여준다.)

- 임시 메모리는 코드 라인을 벗어나면 즉시 소멸된다 !!!

- 연산 수행 시 메모리가 필요하며, 연산 결과도 임시 메모리에 저장된다.

CPU와 RAM과의 연산 과정에서
CPU는 RAM에 있는 데이터를 가지고 연산을 수행함.
그래서, 선언된 변수는 메모리에 있지만 리터럴 상수는 그렇지 못함.
임시 메모리를 두어 그곳에 값에 따른 자료형만큼을 임시로 할당.


12. cin (Console Input)
- 데이터 출력 : cout을 사용했음 (cout <<)
- 데이터 입력 : cin을 사용함. (cin >>)


*/

#include <iostream>

using namespace std;

int main(void) {

	cout << "############################################################################" << endl;

	short a1 = 10;
	int b1 = 20;
	long c1 = 30;
	long long d1 = 40;

	float a2 = 3.14f;
	double b2 = 3.1415;
	long double c2 = 3.141592;

	char a3 = 'A';

	bool a4 = true;
	bool b4 = false;

	cout << "sizeof(short): " << sizeof(short) << endl; // 2
	cout << "sizeof(int): " << sizeof(int) << endl; // 4
	cout << "sizeof(long): " << sizeof(long) << endl; // 4
	cout << "sizeof(long long): " << sizeof(long long) << endl << endl; // 8

	cout << "sizeof(float): " << sizeof(float) << endl; // 4
	cout << "sizeof(double): " << sizeof(double) << endl; // 8
	cout << "sizeof(long double): " << sizeof(long double) << endl << endl; // 8

	cout << "sizeof(char): " << sizeof(char) << endl; // 1
	cout << "sizeof(bool): " << sizeof(bool) << endl << endl; // 1

	cout << "############################################################################" << endl;

	float a = 0.f; // 0을 의미함.

	for (int i = 0; i < 100; ++i)
		a += 0.1;

	printf("%f\n", a); // 10.000002 오차 존재 !!!!

	cout << "############################################################################" << endl;

	char a8 = 'A';
	char b8 = 65;

	cout << a8 << ", " << b8 << endl << endl;
	// char형에는 단일 문자로 입력 받아도 정수형 데이터로 변환되서 저장되고,
	// 출력시에는 char형이라면 아스키 코드 표에서 해당 값의 문자를 출력한다 !!!!

	////////////////////////////////////////////////////
	// 문제) 아스키코드표를 참고하여 Hello를 출력하자.

	char s1 = 72, s2 = 101, s3 = 108, s4 = 111, s5 = 119, s6 = 114, s7 = 100;
	cout << s1 << s2 << s3 << s3 << s4 << ' ' << s5 << s4 << s6 << s3 << s7 << '!' << endl << endl;
	//      H     e      l     l     o            w     o     r     l     d

	cout << "############################################################################" << endl;

	bool a9 = 2.f;
	bool b9 = 'a';
	bool c9 = true;
	bool d9 = false;
	// bool 형 변수는 "0"이 아니면 모드 "1"로 취급한다 !!!!

	cout << "bool 2.f: " << a9 << endl; // 1
	cout << "bool 'a': " << b9 << endl; // 1
	cout << "bool true: " << c9 << endl; // 1
	cout << "bool false: " << d9 << endl << endl; // 0

	cout << "############################################################################" << endl;

	int a11 = 10 + 20;

	float f11 = 3.14f;
	//float d11 = 3.14; // 리터럴 상수의 default는 double형이라서 데이터 손실이 있음.

	cout << "############################################################################" << endl << endl;

	return 0;
}
