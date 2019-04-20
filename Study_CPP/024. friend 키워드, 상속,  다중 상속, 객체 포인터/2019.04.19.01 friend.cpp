#include "stdafx.h"
#include "2019.04.19.01 friend.h"

void Boy2::Func(Girl girl) // Boy2 클래스의 Member Function
{
	cout << "Boy2::Func(Girl girl)" << endl;
	ShowGirlMoney(girl);
}

void Girl::ShowBoy1Money(Boy1 boy1) // Girl 클래스의 Member Function, Boy1 클래스에서 friend 클래스 선언
{
	cout << "Member Functon - Girl::ShowBoy1Money()" << endl;
	cout << "boy1.money: " << boy1.money << endl;
}

void Boy2::ShowGirlMoney(Girl girl) // Boy2 클래스의 Member Function, Girl 클래스에서 friend 함수 선언
{
	cout << "Member Function - Boy2::ShowGirlMoney(Girl girl), Girl 클래스에서 friend" << endl;
	cout << "girl.money: " << girl.money << endl;
}


void ShowGirlMoney(Girl girl) // 해당 헤더와 cpp 파일에 관련된 일반 Global Function
{							  // Girl 클래스를 #include (포함)하지 않는 다른 source 코드였다면,
							  // extern 키워드를 통해서...
	cout << "Global Function - ShowGirlMoney(Girl girl)" << endl;
	cout << "girl.money: " << girl.money << endl;
}
