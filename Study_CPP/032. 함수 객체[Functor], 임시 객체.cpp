/*

################################
   �Լ� ��ü(Function Objects)    = Functor !!!!
################################

- "Function Call Operator -  ()"�� "Operator Overloading"�� �Ͽ�, ��ü�� �Լ�ó�� ���� ���� ���մϴ�.

- "Function Objects"�� "Functor"��� �Ҹ��ϴ� !!!!



################################
  �Լ� ��ü, "Functor"�� ����
################################

- �Լ� ��ü�� ���� ȣ�� �����̶� ���� � ��ü�Ŀ� ����,
���� �ٸ� ���¸� ���ϰ� ���ִ� ������ �ֽ��ϴ�.

- header ������ Ŭ���� ����ο� ��� �Լ��� ��ü���� ���ǵǾ� �ִٸ�...
�ش� ��� �Լ��� �ڵ� inlineȭ �Ǿ� �Ϲ� �Լ��� ���� �ӵ��� ������.
(����, �����Ϸ��� �Ǵ� �ϰ���...)


################################################################################################

##################################
   �ӽ� ��ü(Temporary Objects)
##################################

- �̸� ���� �ӽ� �޸� ������ �Ҵ� �޴� ��ü�� ���մϴ�.


####################################
    �Ϲ� ��ü�� �ӽ� ��ü�� ����
####################################

case 1. �Ϲ� ��ü(���� �� ��� ����� ��/ ex. ���� ���� ��...)
- �Լ��� ����Ǳ� ������ �޸𸮿� �����ִ´�.

case 2. �ӽ� ��ü
- �ش� �ڵ������ ����ڸ��� �Ҹ�ȴ�!



################################
   �ӽ� ��ü�� ����ϴ� ����
################################

- �ڵ������ ����ȭ ��ų �� �ִ�.

- �ӽ� ��ü�� �Ϲ� ��ü�� �޸� �޸𸮿� ��� �����ϴ� ���� �ƴϱ� ������,
�޸� ���� ���鿡�� ȿ�����Դϴ�.


#####################################################################################
Ư��, ��ȯ���� "Reference"�� �ƴϰ� �Ϲ� �ڷ����� ��...
�ӽ� ��ü�� ��ȯ������, �״�� �ٷ� �־��ִ� ������ �����Ϸ��� ����ȭ�� �����Ѵ� !!!!
#####################################################################################


Assignment �������� Point Ŭ������ ����� operator+() �κп� �ٷ� �ӽð�ü ��ȯ !!!!


################################################################################################


*/


#include <iostream>

#define TRUE 1
#define FALSE 0

using std::cout;
using std::endl;
using std::cin;

/////////////////////////////////////////////////////////////////////////////
// Functor(Function Objects) //
///////////////////////////////
class Plus // �갡 �Լ� ��ü(Function Objects)
{		   // ��, "Functor"
public:
	int operator() (int a, int b)
	{
		return a + b;
	}
};

class SortRule
{
public:
	virtual bool operator() (int a, int b) = 0;
};

class Ascending : public SortRule  // �굵 Functor !!!!
{
public:
	virtual bool operator() (int a, int b)
	{
		if (a > b)
		{
			return TRUE;
		}
		else
		{
			return FALSE;
		}
	}
};

class Descending : public SortRule  // �굵 Functor !!!!
{
public:
	virtual bool operator() (int a, int b)
	{
		if (a < b)
		{
			return TRUE;
		}
		else
		{
			return FALSE;
		}
	}
};


void BubbleSort(int arr[], const int size, SortRule &functor)
{
	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < (size - 1) - i; ++j)
		{
			if (functor(arr[j], arr[j + 1]))
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}


////////////////////////////////////////////////////////////////
// Temporary Object //
//////////////////////
class Obj
{
public:
	Obj() {}
	Obj(char *pName)
	{
		strcpy_s(name, 16, pName);
		cout << name << "�� ������ ȣ��" << endl;
	}

	~Obj()
	{
		cout << name << "�� �Ҹ��� ȣ��" << endl;
	}

private:
	char name[16];
};


int main(void)
{
	cout << "###############################################################" << endl;
	cout << "### Functor = Functon Objects" << endl << endl;
	Plus functor; // ��ü�� �Լ�ó�� ����ϰ� �ִ� !!!!
	cout << functor(10, 20) << endl << endl;

	// "operator()"�� ���� ��ü�� �Լ�ó�� �ٷ�� �ֽ��ϴ�.
	// �̸� �Լ� ��ü��� �ϸ�, Functor��� �θ��ϴ�.


	// ###################################################################

	cout << "�Լ� ��ü(Functor) Ȱ�� - ���� ����" << endl;

	Ascending ascend; // Functor
	Descending descend;
	
	int arr1[5] = { 5, 3, 1, 4, 2 };

	BubbleSort(arr1, sizeof(arr1) / sizeof(int), ascend);

	for (int i = 0; i < 5; i++)
	{
		cout << arr1[i] << " ";
	}
	cout << endl;

	int arr2[5] = { 5, 3, 1, 4, 2 };
	
	BubbleSort(arr2, sizeof(arr2) / sizeof(int), descend);

	for (int i = 0; i < 5; i++)
	{
		cout << arr2[i] << " ";
	}
	cout << endl;


	cout << "###############################################################" << endl;
	cout << "### Temporary Objects" << endl << endl;

						  // �Ϲ� ��ü�� �̸��� �����ϴ�.
	Obj obj("�Ϲ� ��ü"); // �Ϲ� ��ü�� �Լ��� ����Ǳ� ������ �޸𸮿� �����ִ� !!!!!
	cout << endl;		  // main() �Լ��� ����Ǽ� �Ҹ��� ȣ��.

	cout << "========================================" << endl;
	Obj("�ӽ� ��ü"); // �ӽ� ��ü�� �̸��� �����ϴ�.
					  // �ӽ� ��ü�� �ش� �ڵ������ ����� �Ҹ�ȴ� !!!!
	cout << "###############################################################" << endl;

	return 0;
}