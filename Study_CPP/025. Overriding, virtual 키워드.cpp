/*

##############################
    Overriding(�������̵�)
##############################

- ��� ���迡�� ���� Ŭ������ ��� �Լ��� �̸��� �Ű�������, ��ȯ Ÿ���� ��� ���� �Լ���
 ����Ŭ�������� �����ϴ� ������ �ǹ��Ѵ�.

ex.

class Obj;
class Player : public Obj;

�� Ŭ���� ��� void Render(void); �Լ��� ������ ����.

��� ���谡 �̷���, Function Overriding�� �ߴٸ�...

################################
case 1. Obj *pObj1 = new Player;
################################

pObj1->Render(); // ���� Ŭ������ Obj Ŭ������ Render() �Լ��� ȣ��ȴ�.

���������δ� Player ��ü�� Obj::Render(), Player::Render()�� ������,
������ ������ ���� Ŭ������ Obj��, �ش� ������ ������ Ŭ������ �������� �Լ� ȣ���� �Ǵ��ϱ� �����̴� !!!!


###################################
case 2. Player *pObj2 = new Player;
###################################

pObj2->Render(); //���� Ŭ������ Player�� Render() �Լ��� ȣ�� ��.

Obj Ŭ������ Obj::Render() �Լ��� Player Ŭ������ ��� �Լ� Player::Render()�� ���� "Overriding" �Ǿ��ٰ� �Ѵ�.
And, Player Ŭ������ Render() �Լ��� ���� �������� ������ "����ȭ �Ǿ���"�� �Ѵ�. (Hiding)


����, ���� Ŭ������ ��� �Լ��� �ִٸ� ���� Ŭ�������� �翬�� ȣ���� �� ����.
������, ���� Ŭ�������� �� �Լ��� Overriding �Ѵٸ�, 
���� Ŭ������ ��� �Լ��� Hiding �Ǿ� �ڽ��� ȣ����� ��ȸ�� �纸�ؾ� ��.



cf) Overloading ����� �򰥸��� �� ��.
- ��ȯ���� �ƴ� �Ű������� ���̷� �Լ����� ���� �Լ����� ������ �� �ִ� ������ �ǹ��մϴ�.


####################################################################################################

##########################################
   virtual Ű����� Ŭ������ ��� �Լ�
##########################################

- virtual : "������", �������� �ʴ� ���� �����ϴ� ��ó�� ������ �ϴ� ���� �ǹ���.


���� �����ϸ�, virtual Ű����� ��ü ������ ���� �ڷ����� Ŭ������ ������ �ִ� ����Լ��� ���� ��ó�� �ൿ�϶�� �ǹ� ?!
- ��ü ������ ������ ����Ű�� �ִ� ���� ��� ��ü�� ��� ���� �Լ��� ȣ���ϰ� �ȴ� !!!!
- ����, ���� Ŭ������ ���� �Լ��� Overriding �Ǿ� ���� �ʾҴٸ�, �� �ش� �Լ� ȣ�� ������.


- �ֻ��� Ŭ�������� ��� �Լ��� virtual Ű���带 �ٿ��� �Լ��� �����,
 ���� Ŭ�������� "virtual Ű���尡 ����� �Ǿ�" �Ȱ��� ����ȴ� !!!!
(�׷���, ��������  ���Ͽ�...
���� Ŭ������ virtual function�� Overriding�� ���� Ŭ������ ��� �Լ����� virtual Ű���带 �ٿ��� ��.)


(���� ���ε��� ����)

������(polymorphism)�� ���� �߰�.

��ü ������ + Overriding + virtual Ű����


####################################################################################################

*/


#include <iostream>

#define SAVE_DELETE(p) if(p) { delete p; p = nullptr; }

using std::cout;
using std::endl;
using std::cin;


//////////////////////////////////////////////////////////////////////////////////////////////
// ���� Ŭ����
class Obj
{
public:
	Obj() {}
	~Obj() {}

public:
	void Render1(void) // ���� Ŭ�������� �ִ� �Ϲ� ��� �Լ�
	{
		cout << "Obj::Render1()" << endl;
	}

	void Render2(void) // ���� Ŭ�������� Overriding�� �Ϲ� ��� �Լ�
	{
		cout << "Obj::Render2()" << endl;
	}

	virtual void Render3(void) { // virtual Ű���带 ����Ͽ� ���� Ŭ�������� Overriding�� ���� ��� �Լ�
		cout << "Obj::Render3()" << endl;
	}
};

//////////////////////////////////////////////////////////////////////////////////////////////
// ���� Ŭ����
class Player : public Obj
{
public:
	Player() {}
	~Player() {}

public:
	void Render2(void) // ���� Ŭ������ �ִ� �Լ��� Overriding�� ��� �Լ�.
	{
		cout << "Player::Render2()" << endl;
	}

	virtual void Render3(void) { // virtual Ű���带 ����Ͽ� ���� Ŭ������ �ִ� �Լ��� Overriding�� ���� ��� �Լ�
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
	void Render2(void) // ���� Ŭ������ �ִ� �Լ��� Overriding�� ��� �Լ�.
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
	cout << "### \"Function Overriding\"�� ����� \"virtual\" Ű����" << endl << endl;

	cout << "case 1. ���� Ŭ�������� �ִ� ��� �Լ�" << endl;
	Obj *pObj1 = new Obj;
	Obj *pObj2 = new Player;

	cout << "### pObj1->Render1() ###" << endl;
	pObj1->Render1();
	cout << "### pObj2->Render1() ###" << endl;
	pObj2->Render1(); // ���� Ŭ�������� �ִ� ��� �Լ��� ��� �޾Ƽ� �׳� ����ϴ� �����.
	cout << endl << endl;

	cout << "case 2. ���� Ŭ�������� Function Overriding" << endl;
	
	cout << "### pObj1->Render2() ###" << endl;
	pObj1->Render2();
	cout << "### pObj2->Render2() ###" << endl;
	pObj2->Render2(); // ���� Ŭ�������� Overriding���� �����Ͽ�����, ������ ������ ���� Ŭ������ Obj�̹Ƿ�,
	cout << endl;	  // Obj Ŭ������ �ش� ��� �Լ��� ȣ��ȴ�.

	Player *pObj3 = new Player;
	cout << "### pObj3->Render2() ###" << endl;
	pObj3->Render2(); // ������ ������ ���� Ŭ������ Player�̹Ƿ�, Player Ŭ������ Overriding�� �Լ� ȣ��.
	cout << "### pObj3->Render2() ###" << endl;
	pObj3->Render2();
	SAVE_DELETE(pObj3);
	cout << endl;

	cout << "�ǹ���... Down-Casting" << endl;
	Player *pObj4 = (Player *)(new Obj); // ���� ����Ű�� �ִ� ����� ���� Ŭ����... (Down-Casting)
	pObj4->Render2();					 // �ƹ��� ������ ������ �ڷ����� �������� �Ǵ��Ѵٰ� �ص�...
	SAVE_DELETE(pObj4);					 // ��� �Լ��� Code �������� ���ϱ� ����� ���� ����.
	cout << endl << endl;				 // �׸���, ���� Ŭ������ �ٸ� ����� �����ϴ� ��ɵ� ��� ����Ǵ� �� ����..

	cout << "case 3. Virtual Function Overriding" << endl;

	cout << "### pObj1->Render3() ###" << endl;
	pObj1->Render3(); // ����Ű�� �ִ� ���� ��ü�� Obj Ŭ������ Render3() ��� �Լ� ȣ��.
	cout << "### pObj2->Render3() ###" << endl;
	pObj2->Render3(); // ����Ű�� �ִ� ���� ��ü�� Player Ŭ������ Render3() ��� �Լ� ȣ�� !!!!
	cout << endl;	  // virtual function�� �̿��Ͽ����Ƿ�, ������ ������ Ŭ������ �������� �Լ� ȣ���ϴ� ���� �ƴ� !!!!

	SAVE_DELETE(pObj1);
	SAVE_DELETE(pObj2);
	

	cout << "###########################################################" << endl;
	cout << "### � �Լ��� ȣ�� �ɱ�?! - Up-Casting" << endl << endl;

	SubPlayer subPlayer;
	SubPlayer *pSub = &subPlayer;
	Player *pPlayer = &subPlayer;
	Obj *pObj = &subPlayer;

	// case 1. virtual Ű���尡 ���� ���
	// Up-casting
	// �� ��ü�� ������ Ÿ������ Render()�Լ��� ȣ��ȴ�.
	subPlayer.Render2();	// sub
	pSub->Render2();		// sub
	pPlayer->Render2();		// player
	pObj->Render2();		// obj
	cout << endl << endl;

	// case 2. virtual Ű���尡 ���� ���
	// Up-casting
	// �� �����Ͱ� ����Ű�� �ִ� ���� ��ü�� Render()�Լ��� ȣ��ȴ�.
	subPlayer.Render3();	// sub
	pSub->Render3();		// sub
	pPlayer->Render3();		// sub
	pObj->Render3();		// sub
	cout << endl << endl;


	cout << "###########################################################" << endl;
	cout << "### � �Լ��� ȣ�� �ɱ�?! - Down-Casting" << endl << endl;


	cout << "���� �ۼ�" << endl;


	cout << "###########################################################" << endl;


	return 0;
}