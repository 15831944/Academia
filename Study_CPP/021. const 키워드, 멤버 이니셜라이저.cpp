/*


#######################################
   const 키워드와 클래스의 멤버 변수
#######################################

ex. 

class Obj
{
public:
	// case 1.
	Obj(int a)
	{
		num2 = a; // 객체 생성 시, 생성자 호출 이전에 객체를 위한 메모리가 할당된다.
				  // 이 때, const 상수 num2는 쓰레기 값으로 초기화가 된다.
				  // 그렇기 때문에 const 상수에 대입 연산을 진행할 수 없다.

				  // 그래서, 메모리 할당과 함께 초기화 하는 문법이 필요하다.
	}
	
private:
	int num1; // 값 변경이 가능 한 변수.
	const int num2; // 값 변경이 불가능한 상수형 변수.
};

그렇다면, 어떻게 const 상수를 초기화 해야하는가?!
- 선언과 동시에 초기화를 진행한다.

const int num2 = 100;

but, 그렇다면 변수를 객체를 초기화 하는 부분을 찾기가 어렵다.
그리고 해당 클래스의 모든 객체가 동일한 값을 지닌다.


#############################################################
  So, 생성자를 통한 const 변수 초기화(Member Initializer)
#############################################################

- 객체 생성 과정

1. 메모리 공간 할당
2. Member Initializer를 통한 멤버 변수 초기화.
3. 생성자 실행.

- Member Initializer를 통한 멤버의 초기화는 선언과 동시에 초기화를 한 것과 같다.


ex.

class Obj
{
public:
	// case 2.
	Obj(int a)
		: num2(a) // Member Initializer의 사용법.
	{

	}
	
private:
	const int num2;	
}



##########################################################
    생성자와 Member Initializer의 멤버 변수 초기화 차이
##########################################################

case 1. 생성자
int a;
a = 10; // 2번에 걸쳐서...

case 2. Member Initializer
int b = 10; // 한 번에...


#################################################################################################################

#######################################
   const 키워드와 클래스의 멤버 함수
#######################################

- 멤버 함수 내부에서 "멤버 변수의 값"을 변경할 수 없도록 만드는 const 키워드 !!!!
(그냥 지역 변수를 선언하고 값 변경하는 것은 상관이 없다 !!!!)

- 멤버 변수의 데이터를 읽기만 가능한 용도의 함수.
(그렇기 때문에, 값 변경이 가능한 일반적인 형태의 함수는 호출이 불가능하다.
무조건 const 멤버 함수는 const 멤버 함수만 호출이 가능하다 !!!!)


ex.

class Obj
{
public:
	void normalFunc(void) // 함수의 일반적인 형태.
	{
		cout << "normalFunc()" << endl;
	}

	void constFunc(void) const // const 멤버 함수
	{
		cout << "constFunc()" << endl;
	}
	
private:
	int num1;
}


#################################################################################################################

#######################################
      const 키워드와 클래스의 객체
#######################################

- const 키워드가 붙은 클래스는 멤버들의 변경을 허용하지 않는다.
(객체 생성 시, const 객체가 생성된다.)


ex.

class Obj
{
public:
	void normalFunc(void) { // 함수의 일반적인 형태.
		cout << "normalFunc()" << endl;
	}

	void constFunc(void) const { // const 멤버 함수
		cout << "constFunc()" << endl;
	}

	void Func() {
		normalFunc();
	}

	void Func() const {
		constFunc();
	}
	
private:
	int num;
}


int main(void)
{
	Obj obj1; // 일반적인 객체 생성
	const Obj obj2; // const 객체 생성
			// Member Initializer로 const 객체 생성 시, 멤버 변수의 초기화는 가능하다 !!!!

	obj1.normalFunc(); // 일반적인 객체는 둘 다 사용 가능함.
	obj2.constFunc();

	//obj2.normalFunc(); // const 객체는 일반 함수(값 변경의 가능성이 있는)의 호출이 불가능하다.
	obj2.constFunc(); // const 객체는 무조건 const 멤버 함수만 호출이 가능하다.

}


####################################
  const 키워드와 함수 Overloading
####################################

- const 키워드로 함수 Overloading이 가능하다.
(일반적인 객체인지 const 객체인지에 따라서 호출되는 대상이 다르다 !!!!)


#################################################################################################################


*/


#include "stdafx.h"

class Obj
{
public:
	Obj(int a) : num2(a) // Member Initializer를 이용하여 const 멤버 변수 초기화.
	{		     // 객체 생성 시, 메모리 할당 다음과 생성자 호출 전에 멤버 변수를 초기화를 해줌.
		num1 = a; // 일반적인 멤버 변수.
		//num2 = a; // const 멤버 변수이기 때문에, 불가능 하다.
	}
	
	void Func(void)
	{
		cout << "일반 함수 Func()" << endl;

		normalFunc();
		constFunc(); // 일반적인 함수는 const 함수 호출도 가능함.
	}

	void Func(void) const // const 객체가 Func() 함수를 호출하면, Overloading 때문에 const 함수가 호출된다 !!!!
	{
		cout << "const 함수 Func()" << endl;

		//normalFunc(); // 일반적인 함수는 멤버 변수의 값을 변경할 수 있는 가능성이 있으므로, 호출 불가 !!!!
		constFunc(); // const 함수 내에선 const 함수만 호출할 수 있다.
	}
	
	void normalFunc(void)
	{
		cout << "normalFunc()" << endl;
	}

	void constFunc(void) const
	{
		cout << "constFunc()" << endl;
	}
	
private:
	int num1;
	const int num2;
};

int main(void)
{
	cout << "######################################################################" << endl;
	cout << "### const 키워드와 멤버 함수" << endl << endl;

	Obj obj1(20);
	const Obj obj2(42);

	cout << "case 1." << endl;
	obj1.Func();

	cout << "case 2." << endl;
	obj2.Func();
	//obj2.normalFunc(); // const 객체는 일반적인 함수 호출이 불가능하다.

	cout << "######################################################################" << endl;

	return 0;
}
