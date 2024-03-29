/*

처음 프로젝트 만들 때, 바로 마침 눌러서 만들기.
- stdafx.cpp 등도 만들어지게..

stdafx.h : 수정이 잘 이루어지지 않은 헤더파일을 가지고 있어서, 컴파일(빌드) 속도 높이기 위해서 !!!!

#####################################################################################################

그 전에... 

###################
  프로그래밍 방식
###################

A. 절차 지향 프로그래밍
- 동사를 의미하는 "~하다"에 중점을 둔 프로그래밍 방법이다.
- 함수들이 가진 기능을 절차대로 호출하여 프로그램 흐름을 진행시킨다.


B. 객체 지향 프로그래밍(Object Oriented Programming, OOP)

객체(object) - 실세계를 구성하는 하나의 실체?!
ex. 사람, 칠판, 컴퓨터 등

- 객체(주어)에 중점을 둔 프로그래밍 방법이다.
- 프로그램을 구성하는 객체간 의사소통을 통해 프로그램 흐름이 진행된다.
(객체간 의사소통 = Message Passing)


####################################
  OOP(객체 지향 프로그래밍)의 특징
####################################
- 실세계를 구현하는 프로그램에 그대로 반영할 수 있다.
- 상속을 통한 코드의 재사용성을 보장한다.
- 유지보수 및 관리가 용이하다.
(오류가 있는 해당 부분만 고치면 되기 때문에, 대규모 프로젝트에 적합하다.)


#####################
   Message Passing
#####################

- 프로그램을 구성하는 객체들간 의사소통 방식
- 실질적으로는 객체들이 가지고 있는 함수를 통해서 이루어진다.


#####################################################################################################

####################
   클래스 - class
####################

- C++부터 등장하는 사용자 정의 자료형.
- 데이터(Data)와 해당 데이터를 처리하는 기능(Function)을 하나로 묶어 놓은 것.


#############################
 프로그래밍에서 객체의 의미
#############################
- 클래스는 사용자 정의 자료형의 일종이다.
- 클래스에 대한 변수를 선언하면, 당연히 메모리에 할당이 된다.
- 그래서, 그 할당 받은 메모리 공간을 "객체", 인스턴스(Instance)라고도 한다.



#######################
  Abstraction(추상화)
#######################

- 공통된 요소들을 추출하는 작업.

ex. 객체 : 사자, 호랑이, 곰
공통점 : 동물(포유류)


#####################################################################################################

####################################################################
     멤버 접근 지정자(제한자, 한정자, 지시자) - Access Modifier
####################################################################

- 멤버에 접근하는 권한을 지정한다.

case 1. private:

- 멤버 접근을 오로지 클래스 내부에서만 허용한다.
- 클래스 외부로부터의 접근은 불가능하다 !!!!
- 클래스의 default 접근 조건

case 2. public:

- 클래스 내부/외부 모두에서 멤버 접근이 가능하다.
- 구조체의 default 접근 조건

case 3. protected:

- 클래스 내부 또는 상속 관계의 클래스 내부에서만 멤버에 접근 가능하다.


So,

########################
   구조체 vs. 클래스
########################

case 1. "Access Modifier"
- 멤버 접근에 대한 범위가 다를 뿐 !!!!

클래스는 "private"
구조체는 "public"

나머지는 둘 다 똑같음.

C++ 이후 클래스와 구조체의 경계선이 모호해졌음.

그래서, 구조체에서는 멤버 함수를 사용하지 않기로 함.
(데이터의 집합을 표현하는 용도로만 구조체를 사용하기로 했다.)


#####################################################################################################

##########################
     클래스의 4대 속성
##########################

case 1. 정보 은닉(Information Hiding)

- 정보를 은닉하겠다[숨기겠다]
- 데이터 보호.

- 멤버 접근 권한을 기본적으로 "private"으로 하여,
 클래스 외부로부터의 원치않은 접근을 막는다.


case 2. 캡슐화(Encapsulation) 

- 데이터와 해당 데이터를 다루는 기능을 하나로 묶어,
 클래스 외부로부터 구성 요소를 숨기겠다.

 - 객체가 가진 구성 요소보다는 기능이 중요하다.
(기능의 세부사항은 중요하지가 않고, 구현된 상태가 중요함.
왜냐하면, 구현된 것을 가져다 쓰기만 하면 되니까 !!!!)


case 3. 상속성(Inheritance)

- 클래스끼리 공통된 데이터를 사용한다면,
상속을 통해서 상위 클래스의 데이터를 하위 클래스에게 물려줄 수 있다.

- 부모 클래스는 곧 자식 클래스들의 공통된 요소를 추출한 추상적인 존재가 된다.

- 하위에서 상위로 올라갈수록 일반화(Generalization) 및 추상화(Abstraction)가 발생한다.
- 상위에서 하위로 내려갈수록 구체화(Concretization), 세분화(refinement) 및 특수화(Specialization)가 발생한다.

##############
Genralization: An existing desciprtion of a set of obejects can be further generalizaed 
              by adding new objects to the set and modifying the description to take these new objects into account.

Specialization: The inverse operation to generalization is specialization.
               sepcializing the description of a set of objects involves the reduction of the set to a subset.

Abstraction: An existing description of a set of objects can be further abstracted
            using a new focus and filtering away all parts of the description that are not relevant with respect to the new focus.

Concretization: The inverse operation to absraction is concretion(also called refinement).
               Concretization results in the increase of detail per obejct.
##############


case 4. 다형성(Polymorphism)

- 각기 다른 형태(클래스)의 객체가 동일한 Message를 통해서 각자의 기능을 수행한다.
- 다형성은 상속과 밀접한 관련이 있다.
(상위 클래스의 변수로 하위 클래스의 객체를 가리킬 경우, 동적 바인딩을 통해...)


#####################################################################################################

#####################################
case 1. 정보 은닉(Information Hiding)
#####################################

- 정보은닉을 하지 않으면 클래스 외부의 접근을 통해 원하지 않는 데이터로 변경될 수 있다 !!!!
- so, 멤버 변수에 대한 접근 권한을 "private"과 "protected"으로 사용한다.

ex.

class CIphone
{
public:
	char m_OS[16];

	void OS()
	{
		cout << "OS는 " << m_OS << endl;
	}
}; // 세미콜론 반드시 적어줘야 함 !!!!


int main(void)
{
	CIphone iphone;

	// 정보은닉을 하지 않으면 원하지 않는 데이터로 변경될 수 있다 !!!!
	strcpy_s(iphone.m_OS, 16, "Android");
	iphone.OS(); // OS는 Android 출력된다.
}


######################################
  정보 은닉된 데이터에 접근하는 방법
######################################

- Data는 "private" 키워드로 정보은닉을 하지만,
 해당 Data를 처리하는 Function은 "public" 키워드로 클래스 외부에서도 접근할 수 있도록 한다.


- 정보은닉된 데이터는 클래스 내부에서만 제어하기 위해서 get(), set() 함수를 사용한다.

get() : 데이터 값을 불러오는 용도(읽기)
set() : 데이터 값을 변경하는 용도(쓰기)

class CIphone
{
public:
	void OS()
	{
		cout << "OS는 " << m_OS << endl;
	}

	void setOS(char *os) // set() 함수 정의
	{
		if(!strcmp(os, "IOS"))
		{
			strcpy_s(m_OS, 16, os);
		}
		else
		{
			strcpy_s(m_OS, 16, "IOS");
		}
	}

	const char* getOS() const // get() 함수 정의, const 함수는 멤버 함수를 대상으로 적용이 가능하다 !!!!
	{
		return m_OS;
	}
	
private:
	char m_OS[16];
}


int main(void)
{
	CIphone iphone;
	iphone.setOS("Android");
	iphone.OS(); // OS는 IOS 출력된다.

	cout << "iphone의 OS: " << iphone.getOS() << endl;

}

#####################################################################################################

#########################################
case 2. 캡슐화(Capsulation) Encapsulation
#########################################

- 관련 있는 모든 것(Data, Function)을 하나의 클래스 안에 한번에 묶어 두는 것이 캡슐화.
- 함수의 실제 구현부를 클래스 외부로부터 숨긴다. (+ 정보은닉이 포함되어 있는 개념)


A. 캡슐화의 개념을 사용하지 않는 경우.
- 구현된 로직의 순서에 맞게 해당 클래스의 함수들을 호출해줘야 함.
(그런데 직접 클래스의 변수를 통해서라면, 함수 호출 순서가 틀릴 수도 있을 가능성이 있다.)


B. 캡슐화의 개념을 적용한 경우

class Alyak
{
public:
	void Take()
	{
		c1.take(); // 함수 호출 순서를 틀릴 이유가 없음.
		c2.take(); // 만약 오류가 있다면, 함수 구현의 문제가 될 것임.
		c3.take(); // 그 부분만 수정하면 됨.
	}
	
private:
	클래스1 c1;
	클래스2 c2;
	클래스3 c3;

}

#####################################################################################################

###########################
case 3. 상속성(Inheritance)
###########################

- 이후 추가



#####################################################################################################

############################
case 4. 다형성(Polymorphism)
############################

- 이후 추가

#####################################################################################################

######################
  클래스의 파일 분할
######################

############################
Contac600 header 파일의 내용
############################

- 클래스를 정의하고, 멤버 변수와 멤버 함수의 prototype을 정의한다.
- #pragma once와 조건부 컴파일(#ifndef)를 사용하여 중복 포함을 막는다.

#pragma once
#ifndef _CONTACT600_H_
#define _CONTACK600_H_

#include "다른 파일.cpp" ?!

class CContac600
{
public:
	void Take();
	
private:
	클래스1 c1;
	클래스2 c2;
	클래스3 c3;
}

#endif


#########################
Contac600.cpp 파일의 내용
#########################

- #include로 header를 추가해주고 함수 원형의 body를 정의해준다.

################################################################################
- 해당 클래스의 멤버 함수라는 것을 표시해주기 위해 scope 연산자 "::"를 사용한다.
################################################################################

#include "stdafx.h"
#include "Contac600.h"

void CContac600::Take() // 영역 지정을 해줘야 함수를 따로 정의할 수 있다.
{
	c1.take();
	c2.take();
	c3.take();
}


####################
test.cpp 파일의 내용
####################

#include "stdafx.h"
#include "Contac600.h"

int main(void)
{
	CContac600 contac600;
	contac600.Take();

}

#########################################################################################################


*/

#include "stdafx.h" // 이제 stdafx header 파일을 포함시킨다. !!!!


// case 1. 클래스의 선언과 정의

class CCar // 클래스를 의미하는 헝가리안 표기법 : 앞에 C 붙이기.
{

// 클래스는 기본적으로 멤버 변수[함수]는 private 설정
//private: // default !!!!

public:
	// 멤버 변수(의미있는 값을 가지고 있는 데이터)
	// m_ : 헝가리안 표기법의 멤버 변수
	char m_name[16];
	int m_speed;

	// 멤버 함수(데이터를 처리하는 기능)
	void move() {
		cout << m_name << "의 speed : " << m_speed << endl;
	}

};

// case 2. 동일한 기능을 수행하는 구조체의 선언과 정의

struct Car
{
//public: // default !!!!

	char m_name[16];
	int m_speed;

	// C++에서는 구조체도 멤버 함수를 가질 수 있다 !!!!
	void move() {
		cout << m_name << "의 speed : " << m_speed << endl;
	}
};


int main()
{
	// 클래스를 통한 변수 선언
	CCar tico;

	strcpy_s(tico.m_name, 16, "티코"); // 클래스는 기본적으로 Access Modifier가 private
	tico.m_speed = 200; // scope 연산 통해 접근을 할 수가 없음
	tico.move(); // so, 클래스 외부에서의 멤버 접근을 위해 "public"으로 접근 권한을 변경해주면 됨.

	// 구조체를 통한 변수 선언
	Car matiz;
	strcpy_s(matiz.m_name, 16, "마티즈");
	matiz.m_speed = 100;
	matiz.move();

    return 0;
}
