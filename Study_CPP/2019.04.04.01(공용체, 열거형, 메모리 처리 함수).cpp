/*

2019.04.04.01 ��


###############################
        ����ü (union)
###############################

- ����ü�� �Բ� ����� ���� �ڷ����� �����̴�.
- �������� ����.

- ����ü�� ���ӵ� �޸� ������ ������� �ʴ´�.
because, ������� �ϳ��� �޸� ������ �����ϱ� �����̴�.
(�׷��� ������.... ��� �������� �ּҰ� ����.)

- ��� ���� �� ���� ũ�Ⱑ ū �ڷ����� �������� ����ü�� �޸� ������ �Ҵ�ȴ�.

ex.

union ����ü �̸� {

};


########################
 ����ü ����� �ʱ�ȭ
########################

struct taxBox { // ����ü

	short a;
	int b;
};

union uniBox { // ����ü

	short a;
	int b;
};

tabBox tBox = {};
uniBox uBox = {};

tabBox tBox = { 10, 20 };
uniBox uBox = { 10, 20 }; // ���� �߻� !!!!.
						  // �� ���� �޸� ������ �����ϱ� ������ ���� "1"���� �Է��ؾ� ��.


#######################################################################################################################


#####################################
      ������ - "enumerated type"
#####################################

- "enumeration"�� ����.

- ����� ���� �ڷ����� ����.
- ���� ������ �����ϴ� �� ��� �ȴ�.

- �������� �����ʹ� ����� !!!!!
(switch ���� ��� ����)

- �������� ũ��� "4 Bytes"�� �����Ǿ��ִ�.
(������ ������ �����ʹ� ����� ���� !!!!!)


ex. ������ �������� �� ����

enum PlayerStance { IDLE, WALK, ATTACK, END };
					  0    1      2      3

enum PlayerStance { IDLE = 1, WALK, ATTACK, END };
						       2      3      4

enum PlayerStance { IDLE = 2, WALK = 1, ATTACK, END }; // �ߺ��ؼ� ���� ���� ���� �ֱ���...
										  2      3

enum PlayerStance { IDLE = 1, WALK, ATTACK = 7, END };
				               2                 8	


###########################
   ������ ������ �ʱ�ȭ
###########################

����, �Ϲ����� �Լ� ������ ���� ������ �������� �����ؼ� ����Ѵٸ�...

PlayerStance stance = WALK; // �̷� ������ �����ؼ� ����.


- ������ ������ ������ ��� �����͸� ���� �� �ִ�.
- �Ϲ� ����� ������ ��� ������ �߻��Ѵ� !!!!


#######################################################################################################################


##############################
       �޸� ó�� �Լ�
##############################

- �޸� ���� ���̿� �����͸� �ʱ�ȭ, ���縦 �����ϴ� �Լ�


case 1. memset

- �޸� �ʱ�ȭ �ϴµ� ��� ��.
- �� Byte�� LSB�� �ʱ�ȭ ��ų ���� ����.
- �迭�̵�, ����ü�� ���ӵ� �޸𸮸� ������ ��ü�� ���� �޸� "0"���� �ʱ�ȭ.

void* memset(void *_Dst, int _Val, size_t _Size);

�Ű����� void *_Dst : �޸𸮸� �ʱ�ȭ ��ų ������ ���� �ּҸ� ����
�Ű����� int _Val : �� Byte�� LSB�� �ʱ�ȭ ��ų ���� ����
�Ű����� size_t _Size : �ʱ�ȭ�� ������ ũ�� ����.
��ȯ�� void* : _Det ��, �ʱ�ȭ �� �޸𸮰� ��ȯ �ȴ�.


case 2. memcpy

errno_t memcpy_s(void *const _Destination, const rsize_t _DestinationSize, const void *const _Source, const rsize_t _SourceSize);

void* memcpy(void *_Dst, const void *_Src, size_t _Size);

�Ű����� void *_Dst : 
�Ű����� const void *_Src :
�Ű����� size_t _Size :
��ȯ�� void* : _Dst ��, �ʱ�ȭ �� �޸𸮰� ��ȯ �ȴ�.


case 3. memmove

errno_t memmove_s(void *const _Destination, const rsize_t _DestinationSize, const void *const _Source, const rsize_t _SourceSize);

void* memmove(void *_Dst, const void *_Src, size_t _Size);

�Ű����� 
�Ű����� 
�Ű����� 
��ȯ�� void* : _Dst ��, �ʱ�ȭ �� �޸𸮰� ��ȯ �ȴ�.


#######################################################################################################################





#######################################################################################################################





#######################################################################################################################




#######################################################################################################################





#######################################################################################################################





*/

#include <iostream>

using std::cout;
using std::endl;
using std::cin;

enum BATTLE { RUN = 1, AGAIN, HUNT = 7, DIE };

int main(void) {

	cout << "##################################################################################" << endl;
	cout << "### ����ü union " << endl << endl;

	struct taxBox {

		short a;
		int b;
	};

	union uniBox {

		short a;
		int b;
	};

	uniBox uBox = {};


	cout << "##################################################################################" << endl;
	cout << "### ����ü union ����� �ּ� Ȯ��" << endl << endl;


	cout << "&uBox: " << &uBox << endl;
	cout << "&(uBox.a): " << &(uBox.a) << endl;
	cout << "&(uBox.b): " << &(uBox.b) << endl << endl;

	cout << "##################################################################################" << endl;
	cout << "### ����ü ����� �޸� ����" << endl << endl;

	uBox.a = 10;
	cout << "uBox.a: " << uBox.a << endl;

	uBox.b = 50; // �ٸ� ����� ���� �ٲپ��µ�, ���������� �޸𸮸� �����ϱ� ������...
	cout << "uBox.a: " << uBox.a << endl << endl;


	cout << "##################################################################################" << endl;
	cout << "### ����ü�� �̿��� float�� �ڷ� ����" << endl << endl;

	union uniTest {

		int a;
		float b;
	};

	uniTest uTest = {};
	uTest.b = 3.14;

	// 10������ ���� �Ǽ���....
	cout << "uTest.a: " << uTest.a << endl;

	cout << "##################################################################################" << endl;
	cout << "### ������ enum ����� ���" << endl << endl;

	enum PlayerStance { IDLE, WALK, ATTACK, END };

	PlayerStance stance = WALK;

	switch (stance) {

	case IDLE:
		cout << "��� ����" << endl;
		break;
	case WALK:
		cout << "�ȱ� ����" << endl;
		break;
	case ATTACK:
		cout << "���� ����" << endl;
		break;
	}
	cout << endl;

	cout << "BATTLE::RUN - " << BATTLE::RUN << endl;
	cout << "BATTLE::AGAIN - " << BATTLE::AGAIN << endl;
	cout << "BATTLE::HUNT - " << BATTLE::HUNT << endl;
	cout << "BATTLE::DIE - " << BATTLE::DIE << endl << endl;

	cout << "sizeof(BATTLE): " << sizeof(BATTLE) << endl << endl;

	cout << "##################################################################################" << endl;
	cout << "### �޸� ó�� �Լ� - memset " << endl << endl;

	int a;

	memset(&a, 0, sizeof(int));

	cout << "a: " << a << endl << endl;

	int *ptr = new int[10]; // ���� �迭�� ����� ���ÿ� �ʱ�ȭ �Ұ���.

	for (int i = 0; i < 10; i++) {
		cout << ptr[i] << " ";
	}
	cout << endl;

	memset(ptr, 0, sizeof(int) * 10); 

	for (int i = 0; i < 10; i++) {
		cout << ptr[i] << " ";
	}
	cout << endl << endl;


	cout << "##################################################################################" << endl;
	cout << "### �޸� ó�� �Լ� - memcpy, memmove " << endl << endl;




	cout << "##################################################################################" << endl;
	
		
	return 0;
}