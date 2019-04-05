/*

2019.03.14.01 목

######################
소스 분석(키워드 위주)
######################

1. #include <iostream>
# : 전처리 지시자 -> 컴파일 전에 처리해라!
include : 포함하다

<iostream> : C++의 표준 입출력 라이브러리 - 우클릭 해서 문서 열기(해당 내용 볼 수 있음)
- i = Input / o = Output / stream = 통로의 의미

So, iostream 내부에 선언된 기능을 사용할 수 있도록 포함시키는 전처리기


2. using namespace std;

using : 지시자 -> 무엇을 사용하라는 지시자

namespace : 이름공간
- C++부터 중복된 이름의 충돌을 방지하기 위해 등장함.
- 각기 다른 소프트웨어 개발 업체들이 제공하는 라이브러리 안의 코드들을 사용가능하게 한다.

std : standard의 약자, 표준을 뜻하는 이름을 가진 이름공간이다.

ex.

namespace A {
	void Render() {
		cout << "AAAAA" << endl;
	}
}

namespace B {
	void Render() {
		cout << "BBBBB" << endl;
	}
}

main 함수에서 Render()를 호출하면 오류가 생김.
- 이름공간을 사용하라는 지시자의 명령이 필요함.

using namespace A;
using namespace B;

둘 중 하나만 써야함.
but, 둘 다 쓰면 둘 다 Render()니까 오류생기는 거임.

그래서 scope 연산자 <= ::
- 영역지정 연산자
- namespace 선언 없이 사용을 가능하게 한다.

So, 이름공간을 사용하지 않아도 함수 호출 가능
ex.
A::Render();
B::Render();


3. main 함수
- 프로그램 실행 시 처음 호출되는 함수
- 사용자가 임의로 이름을 변경할 수 없다.
- 2개 이상 존재 할 수 없다.


4. cout << "Hello World!" << endl;

cout : Console Output의 약자
- 출력의 기능을 담당하는 객체

endl : End Line의 약자
- 줄바꿈(개행)의 기능을 담당하는 객체

<< : cout과 만나면서 추출 연산자로 사용된다.
- 원래는 Shift 연산자. but!!!

"Hello World!" : 문자열
- 2개 이상의 문자를 사용하며 큰 따옴표로 감싼다.

'A' 단일문자: 1개의 문자를 사용하며 작은 따옴표로 감싼다.

(세미콜론) ; : 마침표와 같은 것으로, 문장의 종료를 의미함. 



*/

#include <iostream>

using namespace std;

void main(void) {
	cout << "Hello World!" << endl;
}
