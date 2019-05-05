/*

2019.05.02.01 목

#####################################################
   vector 컨테이너의 메모리 정책(메모리 확보 규칙)
#####################################################

- 할당된 메모리를 초과하는 삽입의 시도가 있을 경우, 메모리의 재할당 및 복사가 일어납니다.
- 재할당은 기존 메모리의 반만큼 증가하여 할당됩니다.
이후, 기존 메모리에 있던 원소들을 새로 할당한 메모리로 복사를 진행합니다.
So, 데이터의 추가,제거 시 비효율적입니다.

- vector 컨테이너는 유동적인 데이터 추가 시, 재할당 및 복사를 최소화 하고자
미리 사용할 크기만큼의 메모리를 확보하거나 메모리 공간을 예약하여 활용합니다.


###############################
ex.
vector<int> temp;

	temp.size()  capacity()
	처음   0      0
	추가   1      1 (0/2_ 최소 1 증가)
	추가   2      2 (1/2_ 최소 1 증가)
	추가   3      3 (2/2_ 1 증가)
	추가   4      4 (3/2_ 1 증가)
	추가   5      6 (4/2_ 2 증가)
	추가   6      6
	추가   7      9 (6/2_ 3 증가)
###############################

########################################################################################################

###########################################
	vector 컨테이너 선언 시, 메모리 확보
###########################################

- 객체 선언과 동시에 operator() 연산자를 이용하여 할당하고자 하는 크기를 전달해주면 됩니다.

이때, 확보된 메모리 공간의 데이터는 "0"으로 초기화 되어있습니다 !!!!

########################################################################################################

#####################
  메모리 공간 조절 - resize() 멤버 함수
######################

#############################################
case 1. vector 컨테이너의 크기를 줄이는 경우.
#############################################

- 인자로 넘긴 크기만큼 남기고 모든 데이터를 제거합니다.
but, 이미 확보된 메모리 공간 "capacity()"은 줄어들지 않습니다 !!!!
(이때, vector 컨테이너에 실제로 데이터는 남아있지만 접근할 수 있는 index 범위가 줄어듭니다.)

#############################################
case 2. vector 컨테이너의 크기를 늘리는 경우.
#############################################

- 넓혀진 메모리 공간의 데이터는 자동적으로 "0"이 채워집니다.




#####################
   메모리 공간 예약 - reserve() 멤버 함수
#####################

- 인자로 넘긴 크기만큼 메모리를 재할당해줍니다.
(이때, 메모리 확보 규칙에 따른 capacity() 증가가 아닙니다.
인자로 받은 크기만큼 재할당 되는 것.)

#########################################################
- 메모리만 할당할 뿐, 데이터는 추가하지 않습니다.
(So, size() : 변화 없음, capacity() : 인자로 전달된 크기)
#########################################################

- 컨테이너의 크기를 축소하는 방향으로는 연산을 수행하지 않습니다 !!!!


########################################################################################################

##########################
	조건자(Predicate)
##########################

- bool 자료형의 값을 반환하는 함수의 "함수 포인터" 또는 "함수 객체(Functor)"

- STL(Standard Template Library)에서 제공하는 알고리즘에 인자로 사용됩니다.
(정렬, 검색의 조건을 제공하기 위해...)


case 1. 단항 조건자(컨테이너의 데이터에 대한 조건을 판별)
case 2. 이항 조건자(컨테이너의 데이터 2개에 대한 관계를 판별)


#######################################################
- 함수 포인터도 조건자(Predicate)로 사용될 수 있습니다.
#######################################################

########################################################################################################

###############################
   STL의 sort() 템플릿 함수 - <algorithm> header 파일에 존재, namespace 추가해줘야...
###############################

- Bubble Sort로 구현되어 있습니다.

- STL에서 제공하며, 컨테이너의 데이터를 정렬할 수 있는 "템플릿 함수"입니다.
("임의 접근 반복자를 이용하는 경우"에만 동작합니다 !!!!
동적 배열 기반의 컨테이너는 Random Access Iterator !!!!)


- 정렬 기준인 "Predicate"을 전달하지 않으면 default로 "Ascending Order" (오름차순 정렬)

- 매개변수는 (컨테이너의 처음 위치 반복자,
			마지막 위치의 다음 반복자,
			정렬 기준_"이항 Predicate" 함수 포인터 or Functor)

###################################################
("Predicate"이 "참"이면 정렬(swap)을 수행하지 않음.
"거짓"이어야 정렬(swap)을 수행합니다.)
###################################################




##############################
   STL이 제공하는 Predicate
##############################

- <functional> header에 들어있습니다.
물론, namespace도 추가해줘야...

- 오름차순 및 내림차순 등 조건자(Predicate)가 함수 객체(Functor)로 정의되어 있습니다 !!!!

ex. less, greater

########################################################################################################


#################################
   STL의 count_if() 템플릿 함수 - <algorithm> header 파일에 존재, namespace 추가해줘야...
#################################

컨테이너의 데이터를 순회하면서, 인자로 전달받은

- 단항 Predicate을 받음.



###############################
   STL의 for_each 템플릿 함수 - <algorithm> header 파일에 존재, namespace 추가해줘야...
###############################

- 첫 번째로 받은 반복자부터 두 번째로 받은 반복자까지 순회하면서,
세 번째로 받은 Predicate(조건자_ 함수 포인터, 함수 객체)의 연산을 반복하는 템플릿 함수입니다.


#################################################################
- 조건자의 연산을 그냥 수행만 합니다, (bool 반환이 아닙니다 !!!!)
#################################################################

########################################################################################################

*/


#include <iostream>
#include <vector>
#include <algorithm> // STL의 알고리즘을 사용하기 위해서 포함 !!!!
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
// 조건자(Predicate) 정의 - sort() 템플릿 함수

template <typename T>
bool Ascend(T a, T b) // 오름차순 정렬
{					  // 이항 Predicate

	return a < b; // "TRUE"면 swap을 하지 않음.
}

template <typename T>
bool Descend(T a, T b) // 내림차순 정렬
{					   // 이항 Predicate

	return a > b; // "TRUE"면 swap을 하지 않음.
}
///////////////////////////////////////////////////////////////////////////////////
// 조건자(Predicate) 정의 - count_if() 템플릿 함수

template <typename T>
bool CheckNum(T num) // 단항 Predicate
{
	if (num % 2 == 1) // 홀수...
	{
		return TRUE; // "TRUE_ 홀수"면 count를 셉니다.
	}
	else
	{
		return FALSE;
	}
}
///////////////////////////////////////////////////////////////////////////////////
// 조건자(Predicate) 정의 - for_each() 템플릿 함수

template <typename T>
void SafeDelete(T obj) // for_each() 템플릿 함수는 "Predicate"으로 넘어온 함수를 반복 수행.
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
	cout << "### vector 컨테이너의 메모리 정책" << endl << endl;

	vector<int> intVec11;
	vector<int> intVec12(10); // 메모리 공간이 잡혀있고, 데이터도 "0"으로 들어가있는 상태 !!!!

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
	cout << "### vector 컨테이너의 capacity() 크기 변동" << endl << endl;

	// vector 컨테이너의 할당된 메모리 공간을 넘어서 데이터 추가 시, capacity() 가 증가합니다.
	// 이때, 데이터 추가하기 전의 capacity() 값의 반절만큼 capacity() 값이 증가합니다.
	// (but, 소수점은 버리고, 최소 1만큼 크기가 증가 합니다.)

	vector<int> temp;

	cout << "##### 초기 상태   ####" << endl;
	cout << "size: " << temp.size() << ", ";				 // size(), capacity()
	cout << "capacity: " << temp.capacity() << endl << endl; // 0, 0

	cout << "##### 데이터 추가 ####" << endl;
	temp.push_back(42);
	cout << "size: " << temp.size() << ", ";
	cout << "capacity: " << temp.capacity() << endl; // 1, 1 (0/2 = 0, 최소 1 증가)

	temp.push_back(42);
	cout << "size: " << temp.size() << ", ";
	cout << "capacity: " << temp.capacity() << endl; // 2, 2 (1/2 = 0, 최소 1 증가)

	temp.push_back(42);
	cout << "size: " << temp.size() << ", ";
	cout << "capacity: " << temp.capacity() << endl; // 3, 3 (2/2 = 1 증가)

	temp.push_back(42);
	cout << "size: " << temp.size() << ", ";
	cout << "capacity: " << temp.capacity() << endl; // 4, 4 (3/2 = 1 증가)

	temp.push_back(42);
	cout << "size: " << temp.size() << ", ";
	cout << "capacity: " << temp.capacity() << endl; // 5, 6 (4/2 = 2 증가)

	temp.push_back(42);
	cout << "size: " << temp.size() << ", ";
	cout << "capacity: " << temp.capacity() << endl; // 6, 6

	temp.push_back(42);
	cout << "size: " << temp.size() << ", ";
	cout << "capacity: " << temp.capacity() << endl; // 7, 9 (6/2 = 3 증가)

	temp.push_back(42);
	cout << "size: " << temp.size() << ", ";
	cout << "capacity: " << temp.capacity() << endl; // 8, 9

	temp.push_back(42);
	cout << "size: " << temp.size() << ", ";
	cout << "capacity: " << temp.capacity() << endl; // 9, 9

	temp.push_back(42);
	cout << "size: " << temp.size() << ", ";
	cout << "capacity: " << temp.capacity() << endl; // 10, 13 (9/2 = 4 증가)


	cout << "################################################################" << endl;
	cout << "### resize() 멤버 함수 - vector 컨테이너의 동적 배열 크기 재할당" << endl << endl;

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

	intVec11.resize(7); // vector 컨테이너의 인덱스 범위를 조정하는 것임.
						// 크기를 줄였을 때, 데이터는 남아있지만 접근을 못하는 것임 !!!!
						// 크기를 늘렸다면, 메모리 공간의 재할당이 이루어지면서 데이터 복사가 이루어집니다.
						// 그리고, 자동으로 나머지 부분에는 "0" 값이 채워집니다.

	// 0 1 2 3 4 6 6 9 순으로 capacity() 값이 증가합니다.

	cout << "intVec11 size : " << intVec11.size() << endl;
	cout << "intVec11 capacity : " << intVec11.capacity() << endl;

	for (size_t i = 0; i < intVec11.size(); ++i)
	{
		cout << intVec11[i] << ' ';
	}
	cout << endl << endl;

	cout << "################################################################" << endl;
	cout << "### reserve() 멤버 함수 - 메모리 공간 예약" << endl << endl;

	vector<int> intVec22(3);

	for (size_t i = 0; i < intVec22.size(); ++i)
	{
		cout << intVec22[i] << ' ';
	}
	cout << endl;

	cout << "intVec22 size : " << intVec22.size() << endl;
	cout << "intVec22 capacity : " << intVec22.capacity() << endl << endl;


	intVec22.reserve(7); // 메모리 공간을 예약하는 방법.
						 // 메모리 확보 규칙과 관련이 없이 증가합니다.
						 // 그리고, 데이터 추가 없이 capacity() 값만 늘려 메모리 재할당을 합니다.
						 // but, 메모리 공간을 예약하는 개념이라서 규모를 축소하는 것은 불가능합니다.

	// 원래는....
	// 0 1 2 3 4 6 6 9 순으로 capacity() 값이 증가합니다.

	intVec22.push_back(4);
	intVec22.push_back(5);
	intVec22.push_back(6);
	intVec22.push_back(7); // 7번째 데이터 추가이지만, capacity() 값이 "7"로 되어있으므로 그냥 할당됨.
						   // 이후의 데이터 추가 시, capacity() 변동은...
						   // 배열의 크기가 꽉 차있으므로 재할당 받아야 합니다.
						   // So, 원래 규칙대로 capacity() 값이 이전 값의 반절만큼 증가하므로... (7/2 = 3 증가)
	for (size_t i = 0; i < intVec22.size(); ++i)
	{
		cout << intVec22[i] << ' ';
	}
	cout << endl;

	cout << "intVec22 size : " << intVec22.size() << endl;
	cout << "intVec22 capacity : " << intVec22.capacity() << endl << endl;



	intVec22.push_back(8); // vector 컨테이너에 데이터를 1개 추가하면 capacity()가 "3"증가된 "10"이 됩니다.

	for (size_t i = 0; i < intVec22.size(); ++i)
	{
		cout << intVec22[i] << ' ';
	}
	cout << endl;

	cout << "intVec22 size : " << intVec22.size() << endl;
	cout << "intVec22 capacity : " << intVec22.capacity() << endl << endl;


	cout << "################################################################" << endl;
	cout << "### case 1. sort() 템플릿 함수" << endl << endl;

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
	// <algorithm> header 파일에 있는 sort() 템플릿 함수 사용하기
	// 매개 변수 - 처음 위치, 마지막 위치 + 1, Predicate(함수 포인터, 함수 객체)
	///////////////////////////////////////////////////////////////////////////////////

	sort(intVec31.begin(), intVec31.end(), Ascend<int>);
	// "Predicate"의 조건이 "TRUE"(참)이면 swap하여 정렬하지 않음.
	// "FALSE"(거짓)이어야 swap을 수행합니다.

	for (size_t i = 0; i < intVec31.size(); ++i)
	{
		cout << intVec31[i] << ' ';
	}
	cout << endl;


	sort(intVec31.begin(), intVec31.end(), Descend<int>);
	// "Predicate"의 조건이 "TRUE"(참)이면 swap하여 정렬하지 않음.
	// "FALSE"(거짓)이어야 swap을 수행합니다.

	for (size_t i = 0; i < intVec31.size(); ++i)
	{
		cout << intVec31[i] << ' ';
	}
	cout << endl << endl;


	///////////////////////////////////////////////////////////////////////////////////
	// <functional> header 파일에 있는 Predicate(조건자) 사용하기
	// #### less, greater <= Functor ####
	///////////////////////////////////////////////////////////////////////////////////

	sort(intVec31.begin(), intVec31.end(), less<int>());
	// <functional> header 파일에 Functor로 Predicate가 구현되어 있음.
	// 그래서 호출 시, Function Call Operator() 사용했습니다.

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
	cout << "### case 2. count_if() 템플릿 함수" << endl << endl;

	vector<int> intVec41;

	intVec41.push_back(1);
	intVec41.push_back(2);
	intVec41.push_back(3);
	intVec41.push_back(4);
	intVec41.push_back(5);

	int count41 = count_if(intVec41.begin(), intVec41.end(), CheckNum<int>);

	cout << "홀수 갯수(count3): " << count41 << endl << endl;


	cout << "count_if() 템플릿 함수는 일반 배열에서도 사용이 가능합니다." << endl;
	int arr42[5] = { 1, 2, 3, 4, 5 };

	int count42 = count_if(arr42, arr42 + (sizeof(arr42) / sizeof(int)), CheckNum<int>);
	int count43 = count_if(arr42, arr42 + 5, CheckNum<int>);
	// 연산을 수행하고자 하는 배열의 주소(시작 위치),
	// 연산을 수행하고자 하는 배열의 주소(마지막 위치) + 1,
	// 연산의 조건 "Predicate" - 함수 포인터, 함수 객체(Functor)

	cout << "홀수(count42): " << count42 << endl;
	cout << "홀수(count43): " << count43 << endl << endl;


	cout << "################################################################" << endl;
	cout << "### case 3. for_each() 템플릿 함수" << endl << endl;

	cout << "기존 방식의 동적 메모리 해제" << endl;
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

	// 기존 방식의 동적 메모리 해제
	for (size_t i = 0; i < intPtrVec11.size(); ++i)
	{
		delete intPtrVec11[i]; // vector 컨테이너의 데이터에 접근하여, 동적 할당 받은 메모리를 해제 했음.
		intPtrVec11[i] = nullptr; // vector 컨테이너를 비우는 연산이 아님 !!!!
								  //
								  // So, size()는 변함 없음.
								  // 그리고 "nullptr"로 만들어버려서 접근 또한 불가능합니다 !!!!
								  // 문제 발생 가능한 코드 !!!!
	}

						 // ######################################################################
	intPtrVec11.clear(); // 다시 사용하려면 clear() 멤버 함수로 데이터를 제거하고 사용해야 합니다.
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
	// <algorithm> header 파일에 있는 for_each() 템플릿 함수 사용하기
	// 매개 변수 - 연산을 수행할 배열의 처음 인덱스 주소,
	//			   연산을 수행할 배열의 마지막 인덱스 + 1, 
	//			   Predicate(함수 포인터, 함수 객체)
	//
	// for_each() 템플릿 함수는 "Predicate"의 연산을 반복적으로 수행합니다.
	// bool 자료형의 값을 반환하지 않습니다 !!!!
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
	// 일반 배열에서도 사용이 가능합니다.
	// 물론, 매개변수가 "처음 인덱스 주소", "마지막 인덱스 주소 + 1", "수행할 연산"

	// #######################################################################################
	// "Predicate"로 들어온 "SafeDelete" 함수 포인터가 매개변수로 일반 자료형을 받으면...
	// 매개변수도 지역변수이므로, "nullptr"로 변하는 것은 복사된 값.
	// 실제 주소들은 변하지 않고, delete 연산 시 메모리 해제되고 남은 쓰레기 값을 가리키게 됨.
	// 물론, 이런 문제는 매개변수를 Reference 자료형으로 수정하면 됩니다 !!!!
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


	cout << "for_each() 템플릿 함수는 일반 배열에서도 사용이 가능합니다." << endl;
	int *arr12[5];

	for (int i = 0; i < sizeof(arr12) / sizeof(int*); ++i)
	{
		arr12[i] = new int(i + 1);
		cout << *arr12[i] << ' ';
	}
	cout << endl;

	for_each(arr12 + 1, arr12 + 3, SafeDelete<int *>);
	// 연산을 수행하고자 하는 배열의 주소(시작 위치),
	// 연산을 수행하고자 하는 배열의 주소(마지막 위치) + 1,
	// 반복할 연산의 조건 "Predicate" - 함수 포인터, 함수 객체(Functor)

	for (int i = 0; i < sizeof(arr12) / sizeof(int*); ++i)
	{
		cout << *arr12[i] << ' ';
	}
	cout << endl;

	cout << "################################################################" << endl << endl;

	return 0;
}