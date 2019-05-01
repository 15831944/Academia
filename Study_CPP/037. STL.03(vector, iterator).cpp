/*

###########################
      vector container
###########################

- <vector> header 파일 포함 시켜야 합니다.
(namespace도 넣어줘야 함.)

- 템플릿 클래스이므로, <> "angle bracket"안에 저장 및 관리하고 하는 자료형을 명시해준다.

vector<int> intVec;


#################
   데이터 추가
#################

- "back" 위치에서만 데이터의 추가가 이루어집니다.
("front"는 막혀있습니다.)
So, push_back() 함수 이용.

#################
   데이터 출력
#################

- for 문을 이용합니다.
동적 배열 기반으로 구현된 vector 컨테이너는 인덱스 연산으로 출력이 가능합니다 !!!!
(물론, 인덱스 연산자가 오버로딩이 되어있고, Random Access가 가능하니까 !!!!)

- vector 컨테이너의 멤버인 size() 함수를 사용하면 됩니다 !!!!

#################
   데이터 삭제
#################

- "back" 위치에서만 데이터의 제거가 이루어집니다.
("front"는 막혀있습니다.)
So, pop_back() 함수 이용.


####################################################################################################################

###############################
  vector 컨테이너의 멤버 함수
###############################


##############################
   컨테이너의 원소 개수 확인 - size()
##############################

size_t size() const;

- 현재 vector 컨테이너의 원소 개수를 반환합니다.
(반환형이 size_t "unsigned int"형으로 반환하기 때문에...)


##############################
   컨테이너의 동적 배열 크기 - capacity()
##############################

- vector 컨테이너의 현재 동적 할당된 메모리의 개수를 반환합니다.
- vector 컨테이너에 데이터를 추가 시, 동적 배열의 크기를 넘어가게 되면 재할당 및 복사가 일어난다.
(벡터 컨테이너의 초기 선언 상태에서는 "0")
- 할당된 메모리는 줄어들지 않습니다 !!!!


#############################
  컨테이너의 멤버 전체 삭제 - claer()
#############################

- vector 컨테이너에 추가되어 있는 모든 원소를 비웁니다.
but, 할당된 메모리는 그대로 남습니다.


###############################
  컨테이너가 비어있는 지 여부 - empty()
###############################

- bool 자료형을 반환하기 때문에...
비어있으면 "true", 원소가 존재한다면 "false"


########################
  컨테이너 자체를 교환 - swap()
########################

- swap 함수를 호출하는 vector 컨테이너와 인자로 전달하는 vector 컨테이너의 정보를 바꿉니다.

########################################################################
- 임시 객체를 이용한다면, vector 컨테이너의 메모리를 없앨 수 있다고 ?!?! - 초기 상태로...
왜냐하면 임시 객체는 바로 소멸자를 호출할 수 있으니까 !!!!
########################################################################


############################
  컨테이너의 원소 알아보기 - front(), back()
############################

- front() : 첫 원소 Reference (= intVec[0])
- back() : 마지막 원소 Reference (= intVec[intVec.size() - 1])

원소의 데이터에 접근해서 값을 바꿀 수도 있다 ?!?!?!



####################################################################################################################

#####################
   iterator(반복자) - 객체
#####################

- 반복자는 포인터와 비슷한 개념이고, 하나의 "객체"입니다 !!!!
- "operater*"를 통해 원소에 접근할 수 있습니다.

- 컨테이너마다 데이터의 저장 방식 및 내부 구조가 달라서, 컨테이너를 순회하는 방법도 다릅니다.

but, 일반화하여 공통적으로 사용할 수 있도록 "iterator"를 구현했습니다.
(즉, 컨테이너마다 반복자 객체를 템플릿화하여 만들어놓았습니다.)

ex. vector<int>::iterator iter_begin = intVec.begin();


############################################
   컨테이너의 반복자를 반환하는 멤버 함수 - begin(), end()
############################################

- begin() : "첫번째 원소의 위치"를 가리키는 반복자를 반환
- end() : "마지막 원소의 다음 위치"를 가리키는 반복자를 반환 (순회 조건을 쉽게...)

So, 반복자를 이용한 컨테이너 순회 방법

ex.
vector<int>::iterator iter_begin = intVec.begin();
vector<int>::iterator iter_end = intVec.end();

for (; iter_begin != iter_end; ++iter_begin)
{
	cout << *iter_begin << endl; // 물론 Reference를 반환하기 때문에 접근하여 값 변경도 가능합니다.
}



##############################
   iterator & const 키워드
##############################

- 읽기만 허용합니다.
- 애초에 컨테이너 자체에 const_iterator가 존재합니다 !!!!

ex.
vector<int>::const_iterator const_iter_begin = intVec.begin();
vector<int>::const_iterator const_iter_end = intVec.end();

####################################################################################################################

#####################
   iterator 의 종류 - 5가지
#####################

case 1. 임의 접근 반복자(Random Access Iterator)
case 2. 양방향 반복자(Bidirectional Iterator)
case 3. 순방향 반복자(Forward Iterator)
case 4. 입력 반복자(Input Iterator)
case 5. 출력 반복자(Output Iterator)


################################################
case 1. 임의 접근 반복자(Random Access Iterator)
################################################
- 연속된(contiguous) 메모리를 사용하는 배열 기반 컨테이너들이 갖는 반복자입니다.
- "[], +=, -=, ++, --" 등의 연산자들이 오버로딩 되어 있습니다.
(마치 포인터 연산을 하거나, 원소의 데이터에 접근하여 값을 변경할 수 있습니다.)


#############################################
case 2. 양방향 반복자(Bidirectional Iterator)
#############################################
- 노드 기반 컨테이들이 갖는 반복자입니다.
- "++, --"의 연산자로 양방향에서만 접근만 가능합니다.

#############################################


####################################################################################################################

########################################################
   임의 접근 반복자를 통한 중간 위치에 원소 추가, 삭제 - insert(), erase()
########################################################

- insert() : 매개변수로 "iterator"와 데이터를 받습니다.

- erase() : 매개변수로 "iterator"를 받고, 다음의 원소를 가리키는 iterator를 반환합니다.
			(물론, 실제 메모리 주소는 같음)

####################################################################################################################


*/


#include <iostream>
#include <vector>

using std::cout;
using std::endl;

using std::vector;


int main(void)
{
	cout << "############################################################################" << endl;
	cout << "### vector 컨테이너.01(선언, 데이터 추가, 삭제, 출력)" << endl << endl;

	// vector 컨테이너 선언
	vector<int> intVec1;

	// 데이터 추가  - pop_push() 함수, vector 컨테이너는 "back" 위치에서만 데이터의 추가, 삭제가 가능합니다.
	intVec1.push_back(1);
	intVec1.push_back(2);
	intVec1.push_back(3);
	intVec1.push_back(4);

	// 데이터 출력
	// vector 컨테이너는 동적 배열을 기반으로 구현되어 있기 때문에
	// 인덱스 연산을 통한 접근이 가능하며, 값의 변경도 가능합니다.
	for (int i = 0; i < 4; ++i) // 원소의 개수를 반환하는 멤버 함수 size()를 사용합니다.
	{
		cout << intVec1[i] << ' ';
	}
	cout << endl;

	for (int i = 0; i < 4; ++i)
	{
		intVec1[i] += 5;
		cout << intVec1[i] << ' ';
	}
	cout << endl << endl;

	// 데이터 삭제 - pop_back() 함수, vector 컨테이너는 "back" 위치에서만 데이터의 추가, 삭제가 가능합니다.
	intVec1.pop_back();
	intVec1.pop_back();

	for (int i = 0; i < 2; ++i)
	{
		cout << intVec1[i] << ' ';
	}
	cout << endl;

	cout << "############################################################################" << endl;
	cout << "### vector 컨테이너.02(size(), capacity(), empty(), swap()" << endl << endl;

	vector<int> intVec2;

	intVec2.push_back(1);
	intVec2.push_back(2);
	intVec2.push_back(3);
	intVec2.push_back(4);

	// vector 컨테이너의 멤버 함수 : size(), size_t(unsigned int)를 반환합니다.
	for (size_t i = 0; i < intVec2.size(); ++i)
	{
		cout << intVec2[i] << ' ';
	}
	cout << endl << endl;

	cout << "intVec2 size: " << intVec2.size() << endl;
	cout << "intVec2 capacity: " << intVec2.capacity() << endl << endl; // 추가 되지 않는 한 늘어나지 않고,
																		// 줄어들지는 않음.
	// 원소 전체 삭제
	cout << "vector 컨테이너의 원소 전체 삭제" << endl;
	intVec2.clear(); // 물론, 범위를 넘어간 배열 접근시 Runtime Error !!!!
	cout << "intVec2 size: " << intVec2.size() << endl;
	cout << "intVec2 capacity: " << intVec2.capacity() << endl << endl;

	// 비어있는 지 여부 확인
	cout << "empty() 함수를 이용한 vector 컨테이너의 원소 존재 여부" << endl;
	cout << '[';
	for (size_t i = 0; i < intVec1.size(); ++i)
	{
		cout << intVec1[i] << ' ';
	}
	cout << ']' << endl;

	if (intVec1.empty())
	{
		cout << "intVec1: 비어있습니다." << endl;
	}
	else
	{
		cout << "intVec1: 원소가 있습니다." << endl;
	}

	cout << '[';
	for (size_t i = 0; i < intVec2.size(); ++i)
	{
		cout << intVec2[i] << ' ';
	}
	cout << ']' << endl;

	if (intVec2.empty())
	{
		cout << "intVec2: 비어있습니다." << endl;
	}
	else
	{
		cout << "intVec2: 원소가 있습니다." << endl;
	}
	cout << endl;


	cout << "벡터 정보 교환 - swap()" << endl;
	vector<int> tempVec;
	tempVec.push_back(10);
	tempVec.push_back(20);
	
	cout << "#### 초기 상태 ####" << endl;
	cout << "intVec2 size: " << intVec2.size() << endl;
	cout << "intVec2 capacity: " << intVec2.capacity() << endl << endl;

	cout << "tempVec size: " << tempVec.size() << endl;
	cout << "tempVec capacity: " << tempVec.capacity() << endl << endl;

	cout << "#### swap() 멤버 호출 ####" << endl;

	intVec2.swap(tempVec);

	cout << "intVec2 size: " << intVec2.size() << endl;
	cout << "intVec2 capacity: " << intVec2.capacity() << endl << endl;

	cout << "tempVec size: " << tempVec.size() << endl;
	cout << "tempVec capacity: " << tempVec.capacity() << endl << endl;

	cout << "#### 임시 객체를 이용한 swap() 함수로 동적 배열 없애기 ####" << endl;

	cout << "intVec2 size: " << intVec2.size() << endl;
	cout << "intVec2 capacity: " << intVec2.capacity() << endl << endl;

	// ###########################
	// 임시 객체를 이용한 vector 컨테이너 초기화
	vector<int>().swap(intVec2);
	//intVec2.swap(vector<int>());
	// ###########################

	cout << "intVec2 size: " << intVec2.size() << endl;
	cout << "intVec2 capacity: " << intVec2.capacity() << endl << endl;

	cout << "############################################################################" << endl;
	cout << "### iterator 선언과 초기화, begin(), end()" << endl << endl;

	vector<int> intVec3;

	intVec3.push_back(1);
	intVec3.push_back(2);
	intVec3.push_back(3);
	intVec3.push_back(4);

	// 반복자의 선언과 초기화
	vector<int>::iterator iter_begin3 = intVec3.begin(); // 첫 번째 원소의 위치
	vector<int>::iterator iter_end3 = intVec3.end(); // 마지막 원소 위치의 다음 위치

	// ++, * operator가 오버로딩 되어있어 포인터 연산하는 것처럼 사용할 수 있습니다.
	for (; iter_begin3 != iter_end3; ++iter_begin3)
	{
		cout << *iter_begin3 << ' ';
	}
	cout << endl;

	// iter_begin3의 값 변동이 있어서 "iterator 무효화"가 발생했습니다.
	// So, 사용하기 전에 처음 값으로 다시 지정해야 합니다.
	iter_begin3 = intVec3.begin();
	for (; iter_begin3 != iter_end3; ++iter_begin3) // "iterator"를 이용한 멤버 접근으로 값 변경이 가능합니다.
	{
		*iter_begin3 += 10;
		cout << *iter_begin3 << ' ';
	}
	cout << endl << endl;


	cout << "비어있는 컨테이너의 begin()과 end()" << endl;
	intVec3.clear(); // vector 컨테이너의 원소 전체 제거
	iter_begin3 = intVec3.begin();
	iter_end3 = intVec3.end();

	if (iter_begin3 == iter_end3)
	{
		cout << "begin(), end() 같다" << endl; // 비어있는 컨테이너라서 같습니다 !!!!
	}
	else
	{
		cout << "다르다" << endl;
	}
	cout << endl;

	cout << "############################################################################" << endl;
	cout << "### vector container의 iterator - Random Access Iterator " << endl << endl;

	vector<int> intVec4;
	// vector 컨테이너는 연속된 메모리를 사용하는 동적 배열로 구현되어 있기 때문에,
	// "Random Access Iterator"를 사용합니다.

	intVec4.push_back(1);
	intVec4.push_back(2);
	intVec4.push_back(3);
	intVec4.push_back(4);

	cout << "임의 접근 반복자로 중간 위치 삽입, 삭제 - insert(), erase()" << endl << endl;

	vector<int>::iterator iter_begin4 = intVec4.begin();
	vector<int>::iterator iter_end4 = intVec4.end();

	cout << "초기 상태" << endl;
	for (size_t i = 0; i< intVec4.size(); ++i)
	{
		cout << intVec4[i] << ' ';
	}
	cout << endl << endl;


	// 반복자를 통한 insert() 함수 연산 수행하면... 또는 반복자를 통한 순회연산 시...
	// 반복자의 위치가 변동될 수 있으므로, 반복자의 무효화가 발생합니다.
	// So, 다시 값을 넣어주고 사용해야 합니다.
	iter_begin4 += 2; // "iter_begin[3]"과 같은 의미입니다.
	intVec4.insert(iter_begin4, 0);

	cout << "추가" << endl;
	for (size_t i = 0; i< intVec4.size() ; ++i)
	{
		cout << intVec4[i] << ' ';
	}
	cout << endl << endl;


	iter_begin4 = intVec4.begin() + 3;
	intVec4.erase(iter_begin4); // erase() 함수는 지운 원소의 다음 원소를 가리킵니다.
								// So, 이것을 이용한 초기화...

	// 반복자의 무효화가 발생할 수 있으므로... 초기화 시키고 하거나 아니면 size() 함수를 이용하여...
	cout << "삭제" << endl;
	for (size_t i = 0; i< intVec4.size(); ++i)
	{
		cout << intVec4[i] << ' ';
	}
	cout << endl;

	cout << "############################################################################" << endl;
	cout << "### iterator가 무효화 되는 경우..." << endl << endl;

	vector<int> intVec5;

	intVec5.push_back(1);
	intVec5.push_back(2);
	intVec5.push_back(3);
	intVec5.push_back(4);

	for (size_t i = 0; i< intVec5.size(); ++i)
	{
		cout << intVec5[i] << ' ';
	}
	cout << endl << endl;


	cout << "홀수번째 원소만 지우는 경우" << endl;
	vector<int>::iterator iter = intVec5.begin();
	for (; iter != intVec5.end();)
	{
		if ((*iter) % 2 == 1)
		{
			iter = intVec5.erase(iter); // out of range Runtime Error 생각하면서...
		}								// 오류가 발생하면 인덱스를 기준으로 디버깅할 것 !!!!
		else
		{
			++iter;
		}
	}

	for (size_t i = 0; i< intVec5.size(); ++i)
	{
		cout << intVec5[i] << ' ';
	}
	cout << endl;


	//////////////////////////////////////////////////////
	vector<int> intVec6;

	intVec6.push_back(1);
	intVec6.push_back(2);
	intVec6.push_back(3);
	intVec6.push_back(4);

	cout << "짝수번째 원소만 지우는 경우" << endl;
	iter = intVec6.begin();
	for (; iter != intVec6.end(); ++iter)
	{
		if ((*iter) % 2 == 1)
		{
			iter = intVec6.erase(iter); // 애초에 원소를 앞으로 당겨옴...
			iter--; // 홀수번째 지울때는 out of range Runtime Error
					// 왜냐하면, 첫 번째 원소를 가리키고 있는 iterator에서
					// 영역을 넘어서까지 감소 연산을 수행할 수 없기 때문에 !!!!
		}			// (vector iterator not decrementable)
	}

	for (size_t i = 0; i< intVec6.size(); ++i)
	{
		cout << intVec6[i] << ' ';
	}
	cout << endl;

	cout << "############################################################################" << endl;


	return 0;
}