#pragma once
#ifndef _FRIEND_H_
#define _FRIEND_H_

class Boy1
{
public:
	Boy1()
		: money(42)
	{}

private:
	int money;

	friend class Girl; // 클래스를 friend 선언, Girl 클래스에서 Boy1 클래스의 "private 멤버"에 접근할 수 있다.
};

class Boy2
{
public:
	void Func(Girl girl); // Boy2 클래스의 일반적인 멤버 함수.
						  // Girl 클래스에서 friend 선언을 받은 ShowGirlMoney 멤버 함수를 호출함.

	void ShowGirlMoney(Girl girl); 
};

class Girl
{
public:
	Girl()
		: money(442)
	{}

	void ShowBoy1Money(Boy1 boy1);

	// friend 멤버 함수는 같은 header 파일에 있는 클래스의 멤버 대상으로 !!!!
	friend void Boy2::ShowGirlMoney(Girl girl);

	friend void ShowGirlMoney(Girl girl); // 전역함수를 friend 선언.

private:
	int money;
};

//class Boy2 // [컴파일 오류],friend 멤버 함수를 만들고자 하는 대상이 자신보다 아래에 있어서 !!!!
//{
//public:
//	void Func(Girl girl); 
//	void ShowGirlMoney(Girl girl); 
//};


// ##############################################################################################
// if) friend 멤버 함수를 만들고 싶은데, 그 함수가 있는 클래스가 자신보다 아래에 위치한다면???
// - 컴파일 오류난다 !!!!
// because, 해당 함수의 구현 내용을 모르기 때문에.
//
// case 1. header 파일의 입장. (X - 여기서 안 됨.)
// - Girl 클래스에서는 함수 구현 내용을 몰라서 컴파일 오류 !!!! 
//
// case 2. cpp 파일의 입장.
// - header 파일을 #include (포함)하면,
//  Girl 클래스의 내용이 함수의 정의부보다 위에 있으므로 정보는 알 수 있다.

// ##############################################################################################
// So, friend 멤버 함수를 만들고 싶다면, 그 함수가 있는 클래스가 자신보다 위에 위치해야 한다 !!!!
// case 1. header 파일의 입장.
// - cpp 파일의 함수 정의부가 header 파일에 위치한 함수 prototype에 옮겨져서,
//  Girl 클래스에서 함수 구현 내용을 알 수 있다.
//
// case 2. cpp 파일의 입장.
// - header 파일을 #include (포함)하면,
//  Girl 클래스의 내용이 함수의 정의부보다 위에 있으므로 정보는 알 수 있다.


#endif
