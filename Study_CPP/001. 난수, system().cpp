/*

2019.03.20.01 수

##########
   난수
##########

- 순서나 규칙이 없는 무작위의 수(random)

- rand();
- 0 ~ 32767(0x7fff) 사이의 값을 무작위로 추출해준다.
- 0x7fff = 0111 1111 1111 1111 signed short의 양수 최대 범위.
(but, 실제로는 순서가 정해져 있음.)

- 난수가 발생할 때 seed라는 값을 참고하여 난수표에서 값을 추출한다.
그래서, 아무 설정을 하지 않아서 default로 1의 값을 가진다.
(seed 값에 따른 고정된 난수표가 순차적으로 추출되기 때문에 난수가 바뀌지 않는다.)


- srand()
- seed 값 변경하는 함수
- 소괄호 안에 seed 값을 넣어 난수 Table을 바꿔준다.


- time()
- 현재 시간을 초 단위로 불러오는 함수
- 1970년 01월 01일을 기준으로...
- #include <time.h> 헤더파일을 포함해야한다.


srand(unsigned(time(NULL)));


#########################################################################################

#############
   system()
#############

- 인자 값에 따라 콘솔 창을 컨트롤할 수 있는 함수

case 1. "cls"
system("cls"); // 이전까지 출력된 내용을 지워주는 기능

case 2. "pause"
system("pause"); // 코드의 흐름을 일시정지 시켜준다.


#########################################################################################

*/

#include <iostream>
#include <time.h>

using std::cout;
using std::endl;
using std::cin;

int main(void) {

	cout << "###########################################################" << endl;
	cout << "### 난수 생성과 실습." << endl;

	int num2 = rand();
	int num3 = rand();
	int num4 = rand();

	cout << num2 << endl;
	cout << num3 << endl;
	cout << num4 << endl;
	cout << "#################" << endl;

	srand(1); // 자동으로 1이 들어가는 거였네. 출력이 같음.
	num2 = rand();
	num3 = rand();
	num4 = rand();

	cout << num2 << endl;
	cout << num3 << endl;
	cout << num4 << endl;
	cout << "#################" << endl;

  // seed 값을 주어 변경되는 난수를 출력.
	srand(unsigned(time(NULL))); // time() 함수의 반환 값을 unsigned로 표기하라.
	num2 = rand();
	num3 = rand();
	num4 = rand();

	cout << num2 << endl;
	cout << num3 << endl;
	cout << num4 << endl;
	cout << "###########################################################" << endl;

	return 0;
}
