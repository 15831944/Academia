/*

#####################################
   정적 배열의 선언 시, 상수 크기
#####################################

ex.

void print(const int sizeNum) {

	const int size = 5;
	int arr[size];
}

- 이런식으로 함수를 만들었다고 가정하면,

우선, 정적 배열 arr은 크기가 컴파일 시에 결정이 된다.
(크기로 설정된 size는 const 상수로서 컴파일 시에 상수라고 고정이 됨.
그래서 배열의 크기로 사용될 수 있는 것임.)

- sizeNum은 const 상수이긴 하나, 아직 값이 정해지지 않은 것.
("배열 크기로 사용해서 쓰레기 값이 들어갈 수 있지 않느냐"라고 할 수 있는데, 의미 없는 말임.)

물론, 정적 배열은 Data 영역의 데이터이므로 프로그램 시작 시 할당이 되고
size와 sizeNum은 지역변수이므로 Stack 영역에 함수 호출 시 할당이 된다.


결과적으로는 배열 크기는 컴파일 시점에 상수 크기로 결정되는 것임.
변수에 접근하고 말고는 그 이후의 프로그램 시작할 때의 문제 !!!!

*/

#include <iostream>

using std::cout;
using std::endl;

void print(const int sizeNum) {

  const int size = 5;
  
  //int arr[sizeNum];
  int arr[size];
}


