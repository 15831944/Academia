/*

##############################
    Overriding(오버라이딩)
##############################

- 상속 관계에서 상위 클래스의 멤버 함수의 이름과 매개변수와, 반환 타입이 모두 같은 함수를
 하위클래스에서 선언하는 문법을 의미한다.

ex.

class Obj;
class Player : public Obj;

두 클래스 모두 void Render(void); 함수를 가지고 있음.

상속 관계가 이렇고, Function Overriding을 했다면...

################################
case 1. Obj *pObj1 = new Player;
################################

pObj1->Render(); // 상위 클래스인 Obj 클래스의 Render() 함수가 호출된다.

실질적으로는 Player 객체에 Obj::Render(), Player::Render()가 있지만,
포인터 변수가 상위 클래스인 Obj라서, 해당 포인터 변수의 클래스를 기준으로 함수 호출을 판단하기 때문이다 !!!!


###################################
case 2. Player *pObj2 = new Player;
###################################

pObj2->Render(); //하위 클래스인 Player의 Render() 함수가 호출 됨.

Obj 클래스의 Obj::Render() 함수는 Player 클래스의 멤버 함수 Player::Render()에 의해 "Overriding" 되었다고 한다.
And, Player 클래스의 Render() 함수에 의해 가려지는 현상을 "은닉화 되었다"고 한다. (Hiding)


물론, 상위 클래스의 멤버 함수만 있다면 하위 클래스에서 당연히 호출할 수 있음.
하지만, 하위 클래스에서 그 함수를 Overriding 한다면, 
상위 클래스의 멤버 함수는 Hiding 되어 자신이 호출당할 기회를 양보해야 함.



cf) Overloading 개념과 헷갈리지 말 것.
- 반환형이 아닌 매개변수의 차이로 함수명이 같은 함수들을 구분할 수 있는 문법을 의미합니다.


####################################################################################################

##########################################
   virtual 키워드와 클래스의 멤버 함수
##########################################

- virtual : "가상의", 존재하지 않는 것을 존재하는 것처럼 느끼게 하는 것을 의미함.


쉽게 생각하면, virtual 키워드는 객체 포인터 변수 자료형인 클래스가 가지고 있는 멤버함수를 없는 것처럼 행동하라는 의미 ?!
- 객체 포인터 변수가 가리키고 있는 실제 대상 객체의 멤버 가상 함수를 호출하게 된다 !!!!
- 물론, 상위 클래스의 가상 함수가 Overriding 되어 있지 않았다면, 그 해당 함수 호출 ㅋㅋㅋ.


- 최상위 클래스에서 멤버 함수에 virtual 키워드를 붙여서 함수를 만들면,
 하위 클래스에도 "virtual 키워드가 상속이 되어" 똑같이 적용된다 !!!!
(그래도, 가독성을  위하여...
상위 클래스의 virtual function을 Overriding한 하위 클래스의 멤버 함수에도 virtual 키워드를 붙여줄 것.)


(동적 바인딩의 개념)

다형성(polymorphism)의 개념 추가.

객체 포인터 + Overriding + virtual 키워드


####################################################################################################

*/


#include <iostream>

#define SAVE_DELETE(p) if(p) { delete p; p = nullptr; }

using std::cout;
using std::endl;
using std::cin;


//////////////////////////////////////////////////////////////////////////////////////////////
// 상위 클래스
class Obj
{
public:
	Obj() {}
	~Obj() {}

public:
	void Render1(void) // 상위 클래스에만 있는 일반 멤버 함수
	{
		cout << "Obj::Render1()" << endl;
	}

	void Render2(void) // 하위 클래스에서 Overriding한 일반 멤버 함수
	{
		cout << "Obj::Render2()" << endl;
	}

	virtual void Render3(void) { // virtual 키워드를 사용하여 하위 클래스에서 Overriding한 가상 멤버 함수
		cout << "Obj::Render3()" << endl;
	}
};

//////////////////////////////////////////////////////////////////////////////////////////////
// 하위 클래스
class Player : public Obj
{
public:
	Player() {}
	~Player() {}

public:
	void Render2(void) // 상위 클래스에 있는 함수를 Overriding한 멤버 함수.
	{
		cout << "Player::Render2()" << endl;
	}

	virtual void Render3(void) { // virtual 키워드를 사용하여 상위 클래스에 있는 함수를 Overriding한 가상 멤버 함수
		cout << "Player::Render3()" << endl;
	}

private:
	int num;
};

class SubPlayer : public Player
{
public:
	SubPlayer() {}
	~SubPlayer() {}

public:
	void Render2(void) // 상위 클래스에 있는 함수를 Overriding한 멤버 함수.
	{
		cout << "SubPlayer::Render2()" << endl;
	}

	virtual void Render3()
	{
		cout << "SubPlayer::Render3()" << endl;
	}
};

//////////////////////////////////////////////////////////////////////////////////////////////

int main(void)
{
	cout << "################################################################" << endl;
	cout << "### \"Function Overriding\"의 개념과 \"virtual\" 키워드" << endl << endl;

	cout << "case 1. 상위 클래스에만 있는 멤버 함수" << endl;
	Obj *pObj1 = new Obj;
	Obj *pObj2 = new Player;

	cout << "### pObj1->Render1() ###" << endl;
	pObj1->Render1();
	cout << "### pObj2->Render1() ###" << endl;
	pObj2->Render1(); // 상위 클래스에만 있는 멤버 함수를 상속 받아서 그냥 사용하는 경우임.
	cout << endl << endl;

	cout << "case 2. 하위 클래스에서 Function Overriding" << endl;
	
	cout << "### pObj1->Render2() ###" << endl;
	pObj1->Render2();
	cout << "### pObj2->Render2() ###" << endl;
	pObj2->Render2(); // 하위 클래스에서 Overriding으로 구현하였지만, 포인터 변수가 상위 클래스인 Obj이므로,
	cout << endl;	  // Obj 클래스의 해당 멤버 함수가 호출된다.

	Player *pObj3 = new Player;
	cout << "### pObj3->Render2() ###" << endl;
	pObj3->Render2(); // 포인터 변수가 하위 클래스인 Player이므로, Player 클래스가 Overriding한 함수 호출.
	cout << "### pObj3->Render2() ###" << endl;
	pObj3->Render2();
	SAVE_DELETE(pObj3);
	cout << endl;

	cout << "의문점... Down-Casting" << endl;
	Player *pObj4 = (Player *)(new Obj); // 실제 가리키고 있는 대상은 상위 클래스... (Down-Casting)
	pObj4->Render2();					 // 아무리 포인터 변수의 자료형을 기준으로 판단한다고 해도...
	SAVE_DELETE(pObj4);					 // 멤버 함수가 Code 영역으로 들어가니까 생기는 문제 같음.
	cout << endl << endl;				 // 그리고, 하위 클래스의 다른 멤버에 접근하는 기능도 없어서 수행되는 것 같음..

	cout << "case 3. Virtual Function Overriding" << endl;

	cout << "### pObj1->Render3() ###" << endl;
	pObj1->Render3(); // 가리키고 있는 실제 객체인 Obj 클래스의 Render3() 멤버 함수 호출.
	cout << "### pObj2->Render3() ###" << endl;
	pObj2->Render3(); // 가리키고 있는 실제 객체인 Player 클래스의 Render3() 멤버 함수 호출 !!!!
	cout << endl;	  // virtual function을 이용하였으므로, 포인터 변수의 클래스를 기준으로 함수 호출하는 것이 아님 !!!!

	SAVE_DELETE(pObj1);
	SAVE_DELETE(pObj2);
	

	cout << "###########################################################" << endl;
	cout << "### 어떤 함수가 호출 될까?! - Up-Casting" << endl << endl;

	SubPlayer subPlayer;
	SubPlayer *pSub = &subPlayer;
	Player *pPlayer = &subPlayer;
	Obj *pObj = &subPlayer;

	// case 1. virtual 키워드가 없을 경우
	// Up-casting
	// 각 객체의 포인터 타입으로 Render()함수가 호출된다.
	subPlayer.Render2();	// sub
	pSub->Render2();		// sub
	pPlayer->Render2();		// player
	pObj->Render2();		// obj
	cout << endl << endl;

	// case 2. virtual 키워드가 있을 경우
	// Up-casting
	// 각 포인터가 가리키고 있는 실제 객체의 Render()함수가 호출된다.
	subPlayer.Render3();	// sub
	pSub->Render3();		// sub
	pPlayer->Render3();		// sub
	pObj->Render3();		// sub
	cout << endl << endl;


	cout << "###########################################################" << endl;
	cout << "### 어떤 함수가 호출 될까?! - Down-Casting" << endl << endl;


	cout << "추후 작성" << endl;


	cout << "###########################################################" << endl;


	return 0;
}