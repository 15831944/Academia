/*

2019.04.24.01 수

###############################################
   형 변환[캐스팅] 연산자(Casting Operator)
###############################################

###############
case 1. C style
###############

int num1 = 3.14; - implicit casting(묵시적 형 변환)
int num2 = (int)3.14; - explicit casting(명시적 형 변환)

- warning 뜨는 유무가 차이점 !!!

######################################################################

#################
case 2. C++ style
#################

A. static_cast
B. dynamic_cast
C. const_cast
D. reinterpret_cast


#######################################################################################################################

############################
A. static_cast (정적 캐스팅)
############################

- 논리적인 형 변환을 해주며, 우리가 늘 써오던 C style 형 변환과 같은 역할을 합니다.
- 형 변환 시점이 "Compile 시점"이기 때문에, "static_cast"

#############################################################

여기서 말하는 논리적인 형 변환은 클래스 간 상속 관계에서의 형 변환을 의미합니다 !!!!
- 객체 포인터는 자신의 클래스 타입 또는 직접[간접]적으로 상속을 하는 객체의 주소를 저장할 수 있습니다.

만약 C style 형 변환이라면, 모든 경우 형 변환을 지원하기 때문에 매우 위험한 상황이 발생할 수 있습니다.
- 반면에 static_cast는 형 변환 시키는 대상이 클래스의 경우, 상속 관계에서만 형 변환을 허용하기 때문에,
Compile 단계에서 오류를 검사 해줄 수 있으므로, C style 형 변환보다 안정적입니다.

- 상속 관계 유무를 따지기 때문에 "논리적인 캐스팅"이라고 합니다.

#############################################################

- "static_cast"는 클래스 대상일 때, 상속 관계일 경우 모든 종류의 형 변환을 허용하는 문제가 있습니다.

특히, 상위 클래스를 하위 클래스로 형 변환 하는 것을 "Down-Casting"이라고 합니다.


#############################################################################################
primitive 자료형이면, C style의 형 변환과 같은 역할.
만약, 클래스 대상이라면 상속 관계에서의 형 변환을 합니다.
(그러나, 상위 클래스 객체를 Down-Casting 할 수도 있으므로 "dynamic_cast"를 사용해야 합니다.
#############################################################################################


#######################################################################################################################

#############################
B. dynamic_cast (동적 캐스팅)
#############################

- 형 변환 가능 여부를 Runtime 시점에 체크하여, 안전하지 않은 Down-Casting일 경우 NULL을 반환합니다.
(상위 클래스 객체를 하위 클래스의 포인터 변수로 가리키려고 형 변환 하는 경우 !!!!)

- 그래서, 클래스 대상으로 형 변환은 "dynamic_cast"는 "static_cast"보다 안전합니다 !!!!



// 상위 클래스 포인터 변수가 가리키는 실제 대상 객체를 하위 클래스 객체로 할당할 때,
// 객체 포인터를 Down-Casting하는 것이 안전한 Down-Casting이라고 할 수 있다 !!!!

// 실제 대상 객체가 하위 클래스인 Player 객체.
// 가리키는 포인터 변수가 상위 클래스인 Obj 클래스.
// So, Player 클래스 포인터 변수로 안전하게 "Down-Casting"이 가능하다 !!!!


###################################
	 Up-Casting & Down-Casting
###################################

- primitive 자료형을 대상으로는 "Promotion & Demotion",
클래스를 대상으로는 "Up-Casting & Down-Casting"이라고 합니다.

- 하위 클래스를 상위 클래스로 형 변환하는 것을 "Up-Casting"이라고 한다.
- 상위 클래스를 하위 클래스로 형 변환하는 것을 "Down-Casting"이라고 합니다.



#####################################
#####################################
	  "dynamic_cast" 연산의 조건
#####################################
#####################################

- primitive 자료형을 대상으로는 사용되지 않습니다.

- "객체 포인터 간의 형 변환을 목적"으로 사용됩니다 !!!!
(클래스 간 형변환 용도)

- 또한, "가상 함수"를 포함하고 있는 상속 관계에서만 가능하다?!
(물론, Virtual Destructor도 포함됩니다.)

나머지 경우는 Compile 오류가 발생합니다 !!!!


#######################################################################################################################

#############
C. const_cast
#############

- "포인터" 및 "Reference"에 대한 const 키워드의 특징(데이터 변경 불가능)을 제거하는 연산자입니다.


#######################################################################################################################

###################
D. reinterpret_cast
###################


- const 포인터를 제외한 모든 포인터의 형 변환을 허용합니다.
(논리적으로 맞지 않는 형 변환을 허용한다는 의미라서 배우 불안정합니다 !!!!)

ex. 아무런 연관 없는(상속 관계가 아닌) 객체 포인터끼리의 형 변환도 허용하기 때문에, 매우 위험합니다 !!!!


#######################################################################################################################


*/


#include <iostream>

using std::cout;
using std::endl;
using std::cin;

class Obj
{
public:
	explicit Obj() {}
	virtual ~Obj() { cout << "Obj::소멸자" << endl; }

public:
	void Render_Obj() { }
};

class Player : public Obj
{
public:
	explicit Player() {}
	virtual ~Player() { }

public:
	void Render_Player() { cout << "Player::Render()" << endl; }
};

class Monster2 // Obj 클래스를 상속 받지 않았음.
{

};

class Monster : public Obj
{
public:
	explicit Monster() {}
	virtual ~Monster() {}

public:
	void Render_Monster() { cout << "Player::Monster()" << endl; }
};


void Render(Obj *pObj) // dynamic_cast 활용법
{
	// ############################################
	// 클래스 타입을 알 수 있는 방법 - dynamic_cast
	// - 허용하지 않는 casting이면 NULL 반환한다.
	// ############################################

	// case 1.
	/*if (dynamic_cast<Player *>(pObj) != nullptr)
	{
		dynamic_cast<Player *>(pObj)->Render_Player();
	}
	else if (dynamic_cast<Monster *>(pObj) != nullptr)
	{
		dynamic_cast<Monster *>(pObj)->Render_Monster();
	}*/

	// case 2.
	Player *pPlayer = dynamic_cast<Player *>(pObj);
	Monster *pMonster = dynamic_cast<Monster *>(pObj);

	if (pPlayer != nullptr)
	{
		pPlayer->Render_Player();
	}
	else if (pMonster != nullptr)
	{
		pMonster->Render_Monster();
	}
}

int main(void)
{
	cout << "######################################################################" << endl;
	cout << "### Casting Operator - C style" << endl << endl << endl;

	int num1 = 3.14;		// implicit casting(묵시적 형 변환)
	int num2 = (int)3.14;	// explicit casting(명시적 형 변환)

	cout << "######################################################################" << endl;
	cout << "### static_cast Operator - C++ style" << endl << endl;

	int num3 = static_cast<int>(3.14); // static_cast<형 변환 시킬 자료형>(바꿀 변수, 데이터)


	// ##########################################
	// case 1. 클래스 대상으로 static_cast 사용법
	// ##########################################
	Monster2 *pMonster11 = new Monster2;

	//Obj *pObj11 = pMonster2; // 상속 관계가 아니라서 안 됨, 컴파일 오류 !!!!

	Obj *pObj12 = (Obj *)pMonster11; // 컴파일이 됬음. C style 형 변환은 가능함.
									 // but, 상속 관계를 고려하지 않고 형 변환을 하기 때문에 위험한 문장입니다 !!!!
	delete pMonster11;

	//Obj *pObj13 = static_cast<Obj *>(pMonster11); // 논리적으로 불가능(상속 관계인 클래스들이 아님)
												  // static_cast는 상속 여부를 확인하여 형 변환을 하므로, 컴파일 오류를 띄워줌.



	// 객체 포인터는 자신의 클래스 타입 또는 직접[간접]적으로 상속을 하는 객체의 주소를 저장할 수 있습니다.
	// Monster2와 Obj 클래스는 상속 관계가 아니기 때문에, 아무런 연관이 없는 클래스입니다.
	//
	// C style 형 변환은 모든 경우 형 변환을 지원하기 때문에, 매우 위험한 상황이 발생할 수 있습니다 !!!!
	//
	// So, static_cast는 클래스의 경우, 상속 관계에서만 형 변환을 허용하기 때문에,
	// Compile 단계에서 오류를 나타내줄 수 있으므로, C style 형 변환보다 안정적.
	//
	// 상속 관계 유무를 따지기 때문에 논리적인 캐스팅이라고 한다.



	// ##########################################
	// case 2. 클래스 대상으로 static_cast 사용법
	// ##########################################

	Obj *pObj21 = new Obj;
	//Player *pPlayer21 = pObj21; // 컴파일 오류 !!!!
								// 원래, Down-Casting은 Implicit 형 변환이 불가능 함.
								// explicit 형 변환을 해야 함.

	Player *pPlayer22 = static_cast<Player *>(pObj21); // 컴파일 가능?! 위험한 코드 !!!!
													   // 하위 클래스 포인터 변수로 실제 들어있는 객체는 상위 클래스인 객체를 가리키는
													   // "Down-Casting"을 하고 있음.
	delete pObj21;

	// 객체 포인터의 특성에서 알 수 있듯이, 상위 클래스는 하위 클래스의 멤버를 알 수 없습니다.
	// 그래서, 상위 클래스 객체를 하위 클래스 포인터 변수에 대입 시, 컴파일 오류가 발생합니다 !!!!
	//
	// 단, static_cast를 통해 형 변환을 시도하면 컴파일은 가능합니다. 그래서 위험한 문장입니다 !!!!
	// "static_cast"는 상속 관계일 경우 모든 종류의 형 변환을 허용하는 문제가 있습니다.
	// 
	// 상위 클래스를 하위 클래스로 형 변환 하는 것을 "Down-Casting"이라고 한다.
	// 그래서, "Down-Casting" 연산 가능 여부를 판단할 수 있도록 "dynamic_cast" 연산을 사용해야 합니다.


	cout << "######################################################################" << endl;
	cout << "###  dynamic_cast Operator - C++ style" << endl << endl;

	// ##########################################
	// 논리적으로 올바른 Down-Casting이 아닌 경우
	// ##########################################

	Obj *pObj31 = new Obj;
	Player *pPlayer31 = dynamic_cast<Player *>(pObj31); // 컴파일은 가능하나, "Down-Casting"이 안전하지 않은 경우라서 NULL 값 반환.
														// 왜냐하면, 상위 클래스의 객체를 하위 클래스 포인터 변수로 Down-Casting 하려 했으므로 !!!!
	cout << pPlayer31 << endl;
	delete pObj31;
	cout << endl << endl;


	Player *pPlayer32 = new Player;
	pPlayer32->Render_Obj();	// 상위 클래스 멤버 함수
	pPlayer32->Render_Player();	// 하위 클래스 멤버 함수
	delete pPlayer32;
	cout << endl << endl;


	Obj *pObj33 = new Player;
	Player *pPlayer33 = dynamic_cast<Player *>(pObj33); // 상위 클래스 포인터 변수가 가리키는 하위 클래스의 객체를
														// 해당 하위 클래스의 포인터 변수로 Down-Casting 하는 경우이므로..
														// 논리적으로 맞는 상황이라서 올바른 형 변환이 이루어집니다.
	pPlayer33->Render_Obj();
	pPlayer33->Render_Player();
	cout << endl << endl;

	// 정리하자면...
	// 상위 클래스 포인터 변수가 가리키는 실제 대상인 하위 클래스 객체를
	// 해당 하위 클래스 포인터 변수로 할당할 때, 안전한 Down-Casting이라고 할 수 있습니다 !!!!
	//
	// 이 예제에서는 실제 대상 객체가 하위 클래스인 Player 객체.
	// 가리키는 포인터 변수가 상위 클래스인 Obj 클래스.
	// So, Obj 클래스 포인터 변수에서 Player 클래스 포인터 변수로 "Down-Casting"이 가능합니다 !!!!


	// #########################################
	// 일회용으로 형 변환해서 함수 호출하는 방법
	// 그렇지만, NULL 값 조심해야 합니다 !!!!
	dynamic_cast<Player *>(pObj33)->Render_Obj();
	dynamic_cast<Player *>(pObj33)->Render_Player();
	delete pObj33;
	cout << endl;


	// ########################################################
	// dynamic_cast 활용 방법
	// - 함수에 인자로 들어온 객체 판단하는 방법 - dynamic_cast
	// ########################################################

	cout << "함수에 인자로 들어온 객체 판단하는 방법 - dynamic_cast" << endl;
	Obj *pPlayer34 = new Player;
	Obj *pMonster34 = new Monster;

	Render(pPlayer34);
	Render(pMonster34);

	delete pPlayer34;
	delete pMonster34;


	cout << "######################################################################" << endl;
	cout << "### Up-Casting" << endl << endl;

	// 하위 클래스를 상위 클래스로 변환하는 것을 Up-Casting이라고 한다.

	Player *pPlayer41 = new Player;
	Obj *pObj41 = pPlayer41; // Implicit Up-Casting

	Obj *pObj42 = dynamic_cast<Obj *>(pPlayer41); // explicit Up-Casting
	Obj *pObj43 = static_cast<Obj *>(pPlayer41); // explicit Up-Casting
	delete pPlayer41;

	cout << "######################################################################" << endl;
	cout << "### const_cast Operator - C++ style" << endl << endl;

	// "포인터" 및 "Reference"의 const 특성만 제거할 수 있는 형 변환만 가능합니다 !!!!

	int num = 10;
	cout << "Before - const_cast" << endl;
	cout << "num: " << num << endl << endl;

	const int *ptr1 = &num; // "Dereferencing"을 통한 값 변경이 불가능한 const 포인터.

	//int *ptr2 = ptr1; // ptr1은 (const int *)형이기 때문에,
					  //값 변경이 가능한 (int *)형으로는 형 변환이 불가능합니다.

	int *ptr3 = const_cast<int*>(ptr1);
	(*ptr3) = 42;

	cout << "After - const_cast" << endl;
	cout << "num: " << num << endl << endl;



	cout << "######################################################################" << endl;
	cout << "### reinterpret_cast Operator - C++ style" << endl << endl;

	// "reinterpret_cast" 연산은 const 포인터를 제외한 모든 포인터의 형 변환을 허용합니다.
	// 논리적으로 맞지 않는 형 변환을 허용한다는 의미이므로, 매우 불안정...

	int num4 = 65;

	char *ptr = reinterpret_cast<char *>(&num4);

	cout << "cout 객체는 (char *)을 만나면 C style 문자열이라고 판단해서..." << endl;
	cout << "ptr: " << ptr << endl; // cout 객체가 오버로딩 된 것이...
									// (char *)을 만나면 C style 문자열이라고 판단해서
									// 주소가 아닌 문자을 찍어버리네 !!!!
	
	cout << "*ptr: " << *ptr << endl << endl;

	char num5 = 65;
	int *ptr2 = reinterpret_cast<int *>(&num5);

	cout << "다른 자료형인 int는 그대로..." << endl;
	cout << "ptr2: " << ptr2 << endl;
	cout << "*ptr2: " << *ptr2 << endl << endl;


	// 아무런 연관 없는 객체 포인터끼리의 형 변환을 허용해 버리기 때문에, 매우 위험합니다 !!!!
	Monster2 *pMonster51 = new Monster2;
	Obj *pObj51 = reinterpret_cast<Obj *>(pMonster51);
	delete pMonster51;

	cout << "######################################################################" << endl;


	return 0;
}