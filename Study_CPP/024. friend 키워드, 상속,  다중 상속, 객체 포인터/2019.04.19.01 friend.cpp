#include "stdafx.h"
#include "2019.04.19.01 friend.h"

void Boy2::Func(Girl girl) // Boy2 Ŭ������ Member Function
{
	cout << "Boy2::Func(Girl girl)" << endl;
	ShowGirlMoney(girl);
}

void Girl::ShowBoy1Money(Boy1 boy1) // Girl Ŭ������ Member Function, Boy1 Ŭ�������� friend Ŭ���� ����
{
	cout << "Member Functon - Girl::ShowBoy1Money()" << endl;
	cout << "boy1.money: " << boy1.money << endl;
}

void Boy2::ShowGirlMoney(Girl girl) // Boy2 Ŭ������ Member Function, Girl Ŭ�������� friend �Լ� ����
{
	cout << "Member Function - Boy2::ShowGirlMoney(Girl girl), Girl Ŭ�������� friend" << endl;
	cout << "girl.money: " << girl.money << endl;
}


void ShowGirlMoney(Girl girl) // �ش� ����� cpp ���Ͽ� ���õ� �Ϲ� Global Function
{							  // Girl Ŭ������ #include (����)���� �ʴ� �ٸ� source �ڵ忴�ٸ�,
							  // extern Ű���带 ���ؼ�...
	cout << "Global Function - ShowGirlMoney(Girl girl)" << endl;
	cout << "girl.money: " << girl.money << endl;
}
