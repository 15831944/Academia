/*

2019.05.02.01 ��

#####################################################
   vector �����̳��� �޸� ��å(�޸� Ȯ�� ��Ģ)
#####################################################

- �Ҵ�� �޸𸮸� �ʰ��ϴ� ������ �õ��� ���� ���, �޸��� ���Ҵ� �� ���簡 �Ͼ�ϴ�.
- ���Ҵ��� ���� �޸��� �ݸ�ŭ �����Ͽ� �Ҵ�˴ϴ�.
����, ���� �޸𸮿� �ִ� ���ҵ��� ���� �Ҵ��� �޸𸮷� ���縦 �����մϴ�.
So, �������� �߰�,���� �� ��ȿ�����Դϴ�.

- vector �����̳ʴ� �������� ������ �߰� ��, ���Ҵ� �� ���縦 �ּ�ȭ �ϰ���
�̸� ����� ũ�⸸ŭ�� �޸𸮸� Ȯ���ϰų� �޸� ������ �����Ͽ� Ȱ���մϴ�.


###############################
ex.
vector<int> temp;

	temp.size()  capacity()
	ó��   0      0
	�߰�   1      1 (0/2_ �ּ� 1 ����)
	�߰�   2      2 (1/2_ �ּ� 1 ����)
	�߰�   3      3 (2/2_ 1 ����)
	�߰�   4      4 (3/2_ 1 ����)
	�߰�   5      6 (4/2_ 2 ����)
	�߰�   6      6
	�߰�   7      9 (6/2_ 3 ����)
###############################

########################################################################################################

###########################################
	vector �����̳� ���� ��, �޸� Ȯ��
###########################################

- ��ü ����� ���ÿ� operator() �����ڸ� �̿��Ͽ� �Ҵ��ϰ��� �ϴ� ũ�⸦ �������ָ� �˴ϴ�.

�̶�, Ȯ���� �޸� ������ �����ʹ� "0"���� �ʱ�ȭ �Ǿ��ֽ��ϴ� !!!!

########################################################################################################

#####################
  �޸� ���� ���� - resize() ��� �Լ�
######################

#############################################
case 1. vector �����̳��� ũ�⸦ ���̴� ���.
#############################################

- ���ڷ� �ѱ� ũ�⸸ŭ ����� ��� �����͸� �����մϴ�.
but, �̹� Ȯ���� �޸� ���� "capacity()"�� �پ���� �ʽ��ϴ� !!!!
(�̶�, vector �����̳ʿ� ������ �����ʹ� ���������� ������ �� �ִ� index ������ �پ��ϴ�.)

#############################################
case 2. vector �����̳��� ũ�⸦ �ø��� ���.
#############################################

- ������ �޸� ������ �����ʹ� �ڵ������� "0"�� ä�����ϴ�.




#####################
   �޸� ���� ���� - reserve() ��� �Լ�
#####################

- ���ڷ� �ѱ� ũ�⸸ŭ �޸𸮸� ���Ҵ����ݴϴ�.
(�̶�, �޸� Ȯ�� ��Ģ�� ���� capacity() ������ �ƴմϴ�.
���ڷ� ���� ũ�⸸ŭ ���Ҵ� �Ǵ� ��.)

#########################################################
- �޸𸮸� �Ҵ��� ��, �����ʹ� �߰����� �ʽ��ϴ�.
(So, size() : ��ȭ ����, capacity() : ���ڷ� ���޵� ũ��)
#########################################################

- �����̳��� ũ�⸦ ����ϴ� �������δ� ������ �������� �ʽ��ϴ� !!!!


########################################################################################################

##########################
	������(Predicate)
##########################

- bool �ڷ����� ���� ��ȯ�ϴ� �Լ��� "�Լ� ������" �Ǵ� "�Լ� ��ü(Functor)"

- STL(Standard Template Library)���� �����ϴ� �˰��� ���ڷ� ���˴ϴ�.
(����, �˻��� ������ �����ϱ� ����...)


case 1. ���� ������(�����̳��� �����Ϳ� ���� ������ �Ǻ�)
case 2. ���� ������(�����̳��� ������ 2���� ���� ���踦 �Ǻ�)


#######################################################
- �Լ� �����͵� ������(Predicate)�� ���� �� �ֽ��ϴ�.
#######################################################

########################################################################################################

###############################
   STL�� sort() ���ø� �Լ� - <algorithm> header ���Ͽ� ����, namespace �߰������...
###############################

- Bubble Sort�� �����Ǿ� �ֽ��ϴ�.

- STL���� �����ϸ�, �����̳��� �����͸� ������ �� �ִ� "���ø� �Լ�"�Դϴ�.
("���� ���� �ݺ��ڸ� �̿��ϴ� ���"���� �����մϴ� !!!!
���� �迭 ����� �����̳ʴ� Random Access Iterator !!!!)


- ���� ������ "Predicate"�� �������� ������ default�� "Ascending Order" (�������� ����)

- �Ű������� (�����̳��� ó�� ��ġ �ݺ���,
			������ ��ġ�� ���� �ݺ���,
			���� ����_"���� Predicate" �Լ� ������ or Functor)

###################################################
("Predicate"�� "��"�̸� ����(swap)�� �������� ����.
"����"�̾�� ����(swap)�� �����մϴ�.)
###################################################




##############################
   STL�� �����ϴ� Predicate
##############################

- <functional> header�� ����ֽ��ϴ�.
����, namespace�� �߰������...

- �������� �� �������� �� ������(Predicate)�� �Լ� ��ü(Functor)�� ���ǵǾ� �ֽ��ϴ� !!!!

ex. less, greater

########################################################################################################


#################################
   STL�� count_if() ���ø� �Լ� - <algorithm> header ���Ͽ� ����, namespace �߰������...
#################################

�����̳��� �����͸� ��ȸ�ϸ鼭, ���ڷ� ���޹���

- ���� Predicate�� ����.



###############################
   STL�� for_each ���ø� �Լ� - <algorithm> header ���Ͽ� ����, namespace �߰������...
###############################

- ù ��°�� ���� �ݺ��ں��� �� ��°�� ���� �ݺ��ڱ��� ��ȸ�ϸ鼭,
�� ��°�� ���� Predicate(������_ �Լ� ������, �Լ� ��ü)�� ������ �ݺ��ϴ� ���ø� �Լ��Դϴ�.


#################################################################
- �������� ������ �׳� ���ุ �մϴ�, (bool ��ȯ�� �ƴմϴ� !!!!)
#################################################################

########################################################################################################

*/


#include <iostream>
#include <vector>
#include <algorithm> // STL�� �˰����� ����ϱ� ���ؼ� ���� !!!!
#include <functional> //

#define TRUE 1
#define FALSE 0

using std::cout;
using std::endl;
using std::cin;

using std::vector;
using std::sort;
using std::count_if;
using std::for_each;

using std::greater;
using std::less;

///////////////////////////////////////////////////////////////////////////////////
// ������(Predicate) ���� - sort() ���ø� �Լ�

template <typename T>
bool Ascend(T a, T b) // �������� ����
{					  // ���� Predicate

	return a < b; // "TRUE"�� swap�� ���� ����.
}

template <typename T>
bool Descend(T a, T b) // �������� ����
{					   // ���� Predicate

	return a > b; // "TRUE"�� swap�� ���� ����.
}
///////////////////////////////////////////////////////////////////////////////////
// ������(Predicate) ���� - count_if() ���ø� �Լ�

template <typename T>
bool CheckNum(T num) // ���� Predicate
{
	if (num % 2 == 1) // Ȧ��...
	{
		return TRUE; // "TRUE_ Ȧ��"�� count�� ���ϴ�.
	}
	else
	{
		return FALSE;
	}
}
///////////////////////////////////////////////////////////////////////////////////
// ������(Predicate) ���� - for_each() ���ø� �Լ�

template <typename T>
void SafeDelete(T obj) // for_each() ���ø� �Լ��� "Predicate"���� �Ѿ�� �Լ��� �ݺ� ����.
{
	if (obj != nullptr)
	{
		delete obj;
		obj = nullptr;
	}
}


int main(void)
{
	cout << "################################################################" << endl;
	cout << "### vector �����̳��� �޸� ��å" << endl << endl;

	vector<int> intVec11;
	vector<int> intVec12(10); // �޸� ������ �����ְ�, �����͵� "0"���� ���ִ� ���� !!!!

	intVec11.push_back(1);
	intVec11.push_back(2);
	intVec11.push_back(3);
	intVec11.push_back(4);
	intVec11.push_back(5);

	for (size_t i = 0; i < intVec11.size(); ++i)
	{
		cout << intVec11[i] << ' ';
	}
	cout << endl;

	cout << "intVec11 size : " << intVec11.size() << endl;
	cout << "intVec11 capacity : " << intVec11.capacity() << endl << endl;


	for (size_t i = 0; i < intVec12.size(); ++i)
	{
		cout << intVec12[i] << ' ';
	}
	cout << endl;

	cout << "intVec12 size : " << intVec12.size() << endl;
	cout << "intVec12 capacity : " << intVec12.capacity() << endl << endl;

	cout << "################################################################" << endl;
	cout << "### vector �����̳��� capacity() ũ�� ����" << endl << endl;

	// vector �����̳��� �Ҵ�� �޸� ������ �Ѿ ������ �߰� ��, capacity() �� �����մϴ�.
	// �̶�, ������ �߰��ϱ� ���� capacity() ���� ������ŭ capacity() ���� �����մϴ�.
	// (but, �Ҽ����� ������, �ּ� 1��ŭ ũ�Ⱑ ���� �մϴ�.)

	vector<int> temp;

	cout << "##### �ʱ� ����   ####" << endl;
	cout << "size: " << temp.size() << ", ";				 // size(), capacity()
	cout << "capacity: " << temp.capacity() << endl << endl; // 0, 0

	cout << "##### ������ �߰� ####" << endl;
	temp.push_back(42);
	cout << "size: " << temp.size() << ", ";
	cout << "capacity: " << temp.capacity() << endl; // 1, 1 (0/2 = 0, �ּ� 1 ����)

	temp.push_back(42);
	cout << "size: " << temp.size() << ", ";
	cout << "capacity: " << temp.capacity() << endl; // 2, 2 (1/2 = 0, �ּ� 1 ����)

	temp.push_back(42);
	cout << "size: " << temp.size() << ", ";
	cout << "capacity: " << temp.capacity() << endl; // 3, 3 (2/2 = 1 ����)

	temp.push_back(42);
	cout << "size: " << temp.size() << ", ";
	cout << "capacity: " << temp.capacity() << endl; // 4, 4 (3/2 = 1 ����)

	temp.push_back(42);
	cout << "size: " << temp.size() << ", ";
	cout << "capacity: " << temp.capacity() << endl; // 5, 6 (4/2 = 2 ����)

	temp.push_back(42);
	cout << "size: " << temp.size() << ", ";
	cout << "capacity: " << temp.capacity() << endl; // 6, 6

	temp.push_back(42);
	cout << "size: " << temp.size() << ", ";
	cout << "capacity: " << temp.capacity() << endl; // 7, 9 (6/2 = 3 ����)

	temp.push_back(42);
	cout << "size: " << temp.size() << ", ";
	cout << "capacity: " << temp.capacity() << endl; // 8, 9

	temp.push_back(42);
	cout << "size: " << temp.size() << ", ";
	cout << "capacity: " << temp.capacity() << endl; // 9, 9

	temp.push_back(42);
	cout << "size: " << temp.size() << ", ";
	cout << "capacity: " << temp.capacity() << endl; // 10, 13 (9/2 = 4 ����)


	cout << "################################################################" << endl;
	cout << "### resize() ��� �Լ� - vector �����̳��� ���� �迭 ũ�� ���Ҵ�" << endl << endl;

	vector<int> intVec21;

	intVec21.push_back(1);
	intVec21.push_back(2);
	intVec21.push_back(3);
	intVec21.push_back(4);

	cout << "intVec11 size : " << intVec11.size() << endl;
	cout << "intVec11 capacity : " << intVec11.capacity() << endl;

	for (size_t i = 0; i < intVec11.size(); ++i)
	{
		cout << intVec11[i] << ' ';
	}
	cout << endl << endl;

	intVec11.resize(7); // vector �����̳��� �ε��� ������ �����ϴ� ����.
						// ũ�⸦ �ٿ��� ��, �����ʹ� ���������� ������ ���ϴ� ���� !!!!
						// ũ�⸦ �÷ȴٸ�, �޸� ������ ���Ҵ��� �̷�����鼭 ������ ���簡 �̷�����ϴ�.
						// �׸���, �ڵ����� ������ �κп��� "0" ���� ä�����ϴ�.

	// 0 1 2 3 4 6 6 9 ������ capacity() ���� �����մϴ�.

	cout << "intVec11 size : " << intVec11.size() << endl;
	cout << "intVec11 capacity : " << intVec11.capacity() << endl;

	for (size_t i = 0; i < intVec11.size(); ++i)
	{
		cout << intVec11[i] << ' ';
	}
	cout << endl << endl;

	cout << "################################################################" << endl;
	cout << "### reserve() ��� �Լ� - �޸� ���� ����" << endl << endl;

	vector<int> intVec22(3);

	for (size_t i = 0; i < intVec22.size(); ++i)
	{
		cout << intVec22[i] << ' ';
	}
	cout << endl;

	cout << "intVec22 size : " << intVec22.size() << endl;
	cout << "intVec22 capacity : " << intVec22.capacity() << endl << endl;


	intVec22.reserve(7); // �޸� ������ �����ϴ� ���.
						 // �޸� Ȯ�� ��Ģ�� ������ ���� �����մϴ�.
						 // �׸���, ������ �߰� ���� capacity() ���� �÷� �޸� ���Ҵ��� �մϴ�.
						 // but, �޸� ������ �����ϴ� �����̶� �Ը� ����ϴ� ���� �Ұ����մϴ�.

	// ������....
	// 0 1 2 3 4 6 6 9 ������ capacity() ���� �����մϴ�.

	intVec22.push_back(4);
	intVec22.push_back(5);
	intVec22.push_back(6);
	intVec22.push_back(7); // 7��° ������ �߰�������, capacity() ���� "7"�� �Ǿ������Ƿ� �׳� �Ҵ��.
						   // ������ ������ �߰� ��, capacity() ������...
						   // �迭�� ũ�Ⱑ �� �������Ƿ� ���Ҵ� �޾ƾ� �մϴ�.
						   // So, ���� ��Ģ��� capacity() ���� ���� ���� ������ŭ �����ϹǷ�... (7/2 = 3 ����)
	for (size_t i = 0; i < intVec22.size(); ++i)
	{
		cout << intVec22[i] << ' ';
	}
	cout << endl;

	cout << "intVec22 size : " << intVec22.size() << endl;
	cout << "intVec22 capacity : " << intVec22.capacity() << endl << endl;



	intVec22.push_back(8); // vector �����̳ʿ� �����͸� 1�� �߰��ϸ� capacity()�� "3"������ "10"�� �˴ϴ�.

	for (size_t i = 0; i < intVec22.size(); ++i)
	{
		cout << intVec22[i] << ' ';
	}
	cout << endl;

	cout << "intVec22 size : " << intVec22.size() << endl;
	cout << "intVec22 capacity : " << intVec22.capacity() << endl << endl;


	cout << "################################################################" << endl;
	cout << "### case 1. sort() ���ø� �Լ�" << endl << endl;

	vector<int> intVec31;
	intVec31.reserve(5);

	intVec31.push_back(3);
	intVec31.push_back(5);
	intVec31.push_back(1);
	intVec31.push_back(4);
	intVec31.push_back(2);

	for (size_t i = 0; i < intVec31.size(); ++i)
	{
		cout << intVec31[i] << ' ';
	}
	cout << endl << endl;


	///////////////////////////////////////////////////////////////////////////////////
	// <algorithm> header ���Ͽ� �ִ� sort() ���ø� �Լ� ����ϱ�
	// �Ű� ���� - ó�� ��ġ, ������ ��ġ + 1, Predicate(�Լ� ������, �Լ� ��ü)
	///////////////////////////////////////////////////////////////////////////////////

	sort(intVec31.begin(), intVec31.end(), Ascend<int>);
	// "Predicate"�� ������ "TRUE"(��)�̸� swap�Ͽ� �������� ����.
	// "FALSE"(����)�̾�� swap�� �����մϴ�.

	for (size_t i = 0; i < intVec31.size(); ++i)
	{
		cout << intVec31[i] << ' ';
	}
	cout << endl;


	sort(intVec31.begin(), intVec31.end(), Descend<int>);
	// "Predicate"�� ������ "TRUE"(��)�̸� swap�Ͽ� �������� ����.
	// "FALSE"(����)�̾�� swap�� �����մϴ�.

	for (size_t i = 0; i < intVec31.size(); ++i)
	{
		cout << intVec31[i] << ' ';
	}
	cout << endl << endl;


	///////////////////////////////////////////////////////////////////////////////////
	// <functional> header ���Ͽ� �ִ� Predicate(������) ����ϱ�
	// #### less, greater <= Functor ####
	///////////////////////////////////////////////////////////////////////////////////

	sort(intVec31.begin(), intVec31.end(), less<int>());
	// <functional> header ���Ͽ� Functor�� Predicate�� �����Ǿ� ����.
	// �׷��� ȣ�� ��, Function Call Operator() ����߽��ϴ�.

	for (size_t i = 0; i < intVec31.size(); ++i)
	{
		cout << intVec31[i] << ' ';
	}
	cout << endl;

	sort(intVec31.begin(), intVec31.end(), greater<int>());

	for (size_t i = 0; i < intVec31.size(); ++i)
	{
		cout << intVec31[i] << ' ';
	}
	cout << endl << endl;



	cout << "################################################################" << endl;
	cout << "### case 2. count_if() ���ø� �Լ�" << endl << endl;

	vector<int> intVec41;

	intVec41.push_back(1);
	intVec41.push_back(2);
	intVec41.push_back(3);
	intVec41.push_back(4);
	intVec41.push_back(5);

	int count41 = count_if(intVec41.begin(), intVec41.end(), CheckNum<int>);

	cout << "Ȧ�� ����(count3): " << count41 << endl << endl;


	cout << "count_if() ���ø� �Լ��� �Ϲ� �迭������ ����� �����մϴ�." << endl;
	int arr42[5] = { 1, 2, 3, 4, 5 };

	int count42 = count_if(arr42, arr42 + (sizeof(arr42) / sizeof(int)), CheckNum<int>);
	int count43 = count_if(arr42, arr42 + 5, CheckNum<int>);
	// ������ �����ϰ��� �ϴ� �迭�� �ּ�(���� ��ġ),
	// ������ �����ϰ��� �ϴ� �迭�� �ּ�(������ ��ġ) + 1,
	// ������ ���� "Predicate" - �Լ� ������, �Լ� ��ü(Functor)

	cout << "Ȧ��(count42): " << count42 << endl;
	cout << "Ȧ��(count43): " << count43 << endl << endl;


	cout << "################################################################" << endl;
	cout << "### case 3. for_each() ���ø� �Լ�" << endl << endl;

	cout << "���� ����� ���� �޸� ����" << endl;
	vector<int *> intPtrVec11;

	for (int i = 0; i < 5; ++i)
	{
		int *ptr = new int(i + 1);
		intPtrVec11.push_back(ptr);
	}

	for (size_t i = 0; i < intPtrVec11.size(); ++i)
	{
		cout << *intPtrVec11[i] << ' ';
	}
	cout << endl;

	cout << "intPtrVec11 size : " << intPtrVec11.size() << endl;
	cout << "intPtrVec11 capacity : " << intPtrVec11.capacity() << endl << endl;

	// ���� ����� ���� �޸� ����
	for (size_t i = 0; i < intPtrVec11.size(); ++i)
	{
		delete intPtrVec11[i]; // vector �����̳��� �����Ϳ� �����Ͽ�, ���� �Ҵ� ���� �޸𸮸� ���� ����.
		intPtrVec11[i] = nullptr; // vector �����̳ʸ� ���� ������ �ƴ� !!!!
								  //
								  // So, size()�� ���� ����.
								  // �׸��� "nullptr"�� ���������� ���� ���� �Ұ����մϴ� !!!!
								  // ���� �߻� ������ �ڵ� !!!!
	}

						 // ######################################################################
	intPtrVec11.clear(); // �ٽ� ����Ϸ��� clear() ��� �Լ��� �����͸� �����ϰ� ����ؾ� �մϴ�.
						 // ######################################################################
	for (size_t i = 0; i < intPtrVec11.size(); ++i)
	{
		cout << *intPtrVec11[i] << ' ';
	}
	cout << endl;
	cout << "intPtrVec11 size : " << intPtrVec11.size() << endl;
	cout << "intPtrVec11 capacity : " << intPtrVec11.capacity() << endl << endl;


	intPtrVec11.push_back(new int(42));
	for (size_t i = 0; i < intPtrVec11.size(); ++i)
	{
		cout << *intPtrVec11[i] << ' ';
	}
	cout << endl;
	cout << "intPtrVec11 size : " << intPtrVec11.size() << endl;
	cout << "intPtrVec11 capacity : " << intPtrVec11.capacity() << endl << endl;


	///////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////
	// <algorithm> header ���Ͽ� �ִ� for_each() ���ø� �Լ� ����ϱ�
	// �Ű� ���� - ������ ������ �迭�� ó�� �ε��� �ּ�,
	//			   ������ ������ �迭�� ������ �ε��� + 1, 
	//			   Predicate(�Լ� ������, �Լ� ��ü)
	//
	// for_each() ���ø� �Լ��� "Predicate"�� ������ �ݺ������� �����մϴ�.
	// bool �ڷ����� ���� ��ȯ���� �ʽ��ϴ� !!!!
	///////////////////////////////////////////////////////////////////////////////////
	cout << "################################################" << endl;

	vector<int *> intPtrVec12;

	for (int i = 0; i < 5; ++i)
	{
		int *ptr = new int(i + 1);
		intPtrVec12.push_back(ptr);
	}

	for (size_t i = 0; i < intPtrVec12.size(); ++i)
	{
		cout << *intPtrVec12[i] << ' ';
	}
	cout << endl;

	cout << "intPtrVec12 size : " << intPtrVec12.size() << endl;
	cout << "intPtrVec12 capacity : " << intPtrVec12.capacity() << endl << endl;


	for_each(intPtrVec12.begin(), intPtrVec12.end(), SafeDelete<int *>);
	// �Ϲ� �迭������ ����� �����մϴ�.
	// ����, �Ű������� "ó�� �ε��� �ּ�", "������ �ε��� �ּ� + 1", "������ ����"

	// #######################################################################################
	// "Predicate"�� ���� "SafeDelete" �Լ� �����Ͱ� �Ű������� �Ϲ� �ڷ����� ������...
	// �Ű������� ���������̹Ƿ�, "nullptr"�� ���ϴ� ���� ����� ��.
	// ���� �ּҵ��� ������ �ʰ�, delete ���� �� �޸� �����ǰ� ���� ������ ���� ����Ű�� ��.
	// ����, �̷� ������ �Ű������� Reference �ڷ������� �����ϸ� �˴ϴ� !!!!
	// #######################################################################################

	for (size_t i = 0; i < intPtrVec12.size(); ++i)
	{
		cout << *intPtrVec12[i] << ' ';
	}
	cout << endl;

	cout << "intPtrVec12 size : " << intPtrVec12.size() << endl;
	cout << "intPtrVec12 capacity : " << intPtrVec12.capacity() << endl << endl;


	intPtrVec12.clear();
	for (size_t i = 0; i < intPtrVec12.size(); ++i)
	{
		cout << *intPtrVec12[i] << ' ';
	}
	cout << endl;

	cout << "intPtrVec12 size : " << intPtrVec12.size() << endl;
	cout << "intPtrVec12 capacity : " << intPtrVec12.capacity() << endl << endl;

	intPtrVec12.push_back(new int(42));

	for (size_t i = 0; i < intPtrVec12.size(); ++i)
	{
		cout << *intPtrVec12[i] << ' ';
	}
	cout << endl;

	cout << "intPtrVec12 size : " << intPtrVec12.size() << endl;
	cout << "intPtrVec12 capacity : " << intPtrVec12.capacity() << endl << endl;


	cout << "for_each() ���ø� �Լ��� �Ϲ� �迭������ ����� �����մϴ�." << endl;
	int *arr12[5];

	for (int i = 0; i < sizeof(arr12) / sizeof(int*); ++i)
	{
		arr12[i] = new int(i + 1);
		cout << *arr12[i] << ' ';
	}
	cout << endl;

	for_each(arr12 + 1, arr12 + 3, SafeDelete<int *>);
	// ������ �����ϰ��� �ϴ� �迭�� �ּ�(���� ��ġ),
	// ������ �����ϰ��� �ϴ� �迭�� �ּ�(������ ��ġ) + 1,
	// �ݺ��� ������ ���� "Predicate" - �Լ� ������, �Լ� ��ü(Functor)

	for (int i = 0; i < sizeof(arr12) / sizeof(int*); ++i)
	{
		cout << *arr12[i] << ' ';
	}
	cout << endl;

	cout << "################################################################" << endl << endl;

	return 0;
}