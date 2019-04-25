/*

####################################################################
   [Prefix/ Postfix] [Increment/ Decrement] Operator Overloading
####################################################################

##############
case 1. Prefix
##############

ex. Point& operator++();

#######################################
"Prefix"의 반환 타입이 왜 "Reference"?!
#######################################

- 연속적인 증감 연산을 구현하기 위해서 !!!!

ex. ++(++point);
 
- 반환형이 "Reference"가 아니고 일반적인 자료형이라면,
복사 생성자가 호출되어 Parentheses 안의 "++point" 문장 이후에 임시 객체가 반환되니까,
이후 수행되는 연산에서 원본의 증감이 되질 않습니다.



###############
case 2. Postfix
###############

ex. Point operator++ (int); // 인자를 받겠다는 의미가 아닙니다.
							// 단지, "Prefix"와의 구분을 위한 약속입니다.


########################################
"Postfix"의 반환 타입이 왜 Normal Type?! - "Reference"가 아닌 이유.
########################################

ex. (point++)++;

- "Postfix Operator Overloading"을 구현한 부분에서...
Point 클래스의 객체는 temp는 operator 함수 안에 선언된 지역변수입니다.
해당 함수가 종료된 후, 함수를 위한 stack 영역이 해제되면서, 할당 받은 메모리들이 소멸됩니다.

So, 이후 연산 수행은 할당되지 않은 공간에 증감 연산을 진행하게 되므로...
=> 비정상적인 메모리 접근.


Primitive 자료형이면 컴파일 오류가 뜰텐데...
클래스 대상으로 구현한 "Operator Overloading"은 불가능한 걸까?!

#########################################################################################


*/

#include <iostream>

using std::cout;
using std::endl;
using std::cin;
using std::ostream;

class Point
{
public:
	explicit Point() {}
	explicit Point(int x, int y)
		: xPos(x), yPos(y)
	{

	}
	Point(const Point &ref)
		: xPos(ref.xPos), yPos(ref.yPos)
	{

	}

	~Point() {}

public:
	Point& operator++() // 전위 증감 Operator Overloading
	{
		cout << "Point& operator++()" << endl;
		xPos += 1;
		yPos += 1;

		return *this;
	}

	Point operator++ (int) // 후위 증감 Operator Overloading, 인자를 받겠다는 의미가 아니고,
	{					   // 전위와 후위 증감 Operator Overloading을 구분하기 위한 약속
		cout << "Point operator++ (int)" << endl;
		Point temp(*this); // 여기 문장이 Default 생성자면 오류 발생함.
						   // 해당 객체는 동일하니까, 증가된 것이 또 들어가게 됨.
		xPos += 1;
		yPos += 1;

		return temp;
	}

	friend ostream& operator<< (ostream &out, Point &ref) // "<< Operator Overloading"
	{													  // ostream 클래스 내부에 private 멤버...
		out << '(' << ref.xPos << ", " << ref.yPos << ')';
		return out;
	}

private:
	int xPos;
	int yPos;
};


int main(void)
{
	cout << "##################################################################" << endl;
	cout << "### [Prefix/ Postfix] [Increment/ Decrement]" << endl << endl;

	// ######################################
	// case 1. 전위 증감 Operator Overloading
	Point point11(1, 10);
	cout << "point11" << point11 << endl;

	++point11;
	cout << "point11" << point11 << endl << endl;


	// ######################################
	// case 2. 후위 증감 Operator Overloading
	Point point12(1, 10);
	cout << "point12" << point12 << endl;

	(point12++)++; // 이거 수행 되어버리네???
				   // 컴파일러 오류로 막는 방법은 없나?!?!?!?!
				   // 값은 정상적으로 나옴.

	cout << "point12" << point12 << endl;

	return 0;
}