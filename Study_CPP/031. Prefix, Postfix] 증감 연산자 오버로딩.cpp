/*

####################################################################
   [Prefix/ Postfix] [Increment/ Decrement] Operator Overloading
####################################################################

##############
case 1. Prefix
##############

ex. Point& operator++();

#######################################
"Prefix"�� ��ȯ Ÿ���� �� "Reference"?!
#######################################

- �������� ���� ������ �����ϱ� ���ؼ� !!!!

ex. ++(++point);
 
- ��ȯ���� "Reference"�� �ƴϰ� �Ϲ����� �ڷ����̶��,
���� �����ڰ� ȣ��Ǿ� Parentheses ���� "++point" ���� ���Ŀ� �ӽ� ��ü�� ��ȯ�Ǵϱ�,
���� ����Ǵ� ���꿡�� ������ ������ ���� �ʽ��ϴ�.



###############
case 2. Postfix
###############

ex. Point operator++ (int); // ���ڸ� �ްڴٴ� �ǹ̰� �ƴմϴ�.
							// ����, "Prefix"���� ������ ���� ����Դϴ�.


########################################
"Postfix"�� ��ȯ Ÿ���� �� Normal Type?! - "Reference"�� �ƴ� ����.
########################################

ex. (point++)++;

- "Postfix Operator Overloading"�� ������ �κп���...
Point Ŭ������ ��ü�� temp�� operator �Լ� �ȿ� ����� ���������Դϴ�.
�ش� �Լ��� ����� ��, �Լ��� ���� stack ������ �����Ǹ鼭, �Ҵ� ���� �޸𸮵��� �Ҹ�˴ϴ�.

So, ���� ���� ������ �Ҵ���� ���� ������ ���� ������ �����ϰ� �ǹǷ�...
=> ���������� �޸� ����.


Primitive �ڷ����̸� ������ ������ ���ٵ�...
Ŭ���� ������� ������ "Operator Overloading"�� �Ұ����� �ɱ�?!

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
	Point& operator++() // ���� ���� Operator Overloading
	{
		cout << "Point& operator++()" << endl;
		xPos += 1;
		yPos += 1;

		return *this;
	}

	Point operator++ (int) // ���� ���� Operator Overloading, ���ڸ� �ްڴٴ� �ǹ̰� �ƴϰ�,
	{					   // ������ ���� ���� Operator Overloading�� �����ϱ� ���� ���
		cout << "Point operator++ (int)" << endl;
		Point temp(*this); // ���� ������ Default �����ڸ� ���� �߻���.
						   // �ش� ��ü�� �����ϴϱ�, ������ ���� �� ���� ��.
		xPos += 1;
		yPos += 1;

		return temp;
	}

	friend ostream& operator<< (ostream &out, Point &ref) // "<< Operator Overloading"
	{													  // ostream Ŭ���� ���ο� private ���...
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
	// case 1. ���� ���� Operator Overloading
	Point point11(1, 10);
	cout << "point11" << point11 << endl;

	++point11;
	cout << "point11" << point11 << endl << endl;


	// ######################################
	// case 2. ���� ���� Operator Overloading
	Point point12(1, 10);
	cout << "point12" << point12 << endl;

	(point12++)++; // �̰� ���� �Ǿ������???
				   // �����Ϸ� ������ ���� ����� ����?!?!?!?!
				   // ���� ���������� ����.

	cout << "point12" << point12 << endl;

	return 0;
}