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

	friend class Girl; // Ŭ������ friend ����, Girl Ŭ�������� Boy1 Ŭ������ "private ���"�� ������ �� �ִ�.
};

class Boy2
{
public:
	void Func(Girl girl); // Boy2 Ŭ������ �Ϲ����� ��� �Լ�.
						  // Girl Ŭ�������� friend ������ ���� ShowGirlMoney ��� �Լ��� ȣ����.

	void ShowGirlMoney(Girl girl); 
};

class Girl
{
public:
	Girl()
		: money(442)
	{}

	void ShowBoy1Money(Boy1 boy1);

	// friend ��� �Լ��� ���� header ���Ͽ� �ִ� Ŭ������ ��� ������� !!!!
	friend void Boy2::ShowGirlMoney(Girl girl);

	friend void ShowGirlMoney(Girl girl); // �����Լ��� friend ����.

private:
	int money;
};

//class Boy2 // [������ ����],friend ��� �Լ��� ������� �ϴ� ����� �ڽź��� �Ʒ��� �־ !!!!
//{
//public:
//	void Func(Girl girl); 
//	void ShowGirlMoney(Girl girl); 
//};


// ##############################################################################################
// if) friend ��� �Լ��� ����� ������, �� �Լ��� �ִ� Ŭ������ �ڽź��� �Ʒ��� ��ġ�Ѵٸ�???
// - ������ �������� !!!!
// because, �ش� �Լ��� ���� ������ �𸣱� ������.
//
// case 1. header ������ ����. (X - ���⼭ �� ��.)
// - Girl Ŭ���������� �Լ� ���� ������ ���� ������ ���� !!!! 
//
// case 2. cpp ������ ����.
// - header ������ #include (����)�ϸ�,
//  Girl Ŭ������ ������ �Լ��� ���Ǻκ��� ���� �����Ƿ� ������ �� �� �ִ�.

// ##############################################################################################
// So, friend ��� �Լ��� ����� �ʹٸ�, �� �Լ��� �ִ� Ŭ������ �ڽź��� ���� ��ġ�ؾ� �Ѵ� !!!!
// case 1. header ������ ����.
// - cpp ������ �Լ� ���Ǻΰ� header ���Ͽ� ��ġ�� �Լ� prototype�� �Ű�����,
//  Girl Ŭ�������� �Լ� ���� ������ �� �� �ִ�.
//
// case 2. cpp ������ ����.
// - header ������ #include (����)�ϸ�,
//  Girl Ŭ������ ������ �Լ��� ���Ǻκ��� ���� �����Ƿ� ������ �� �� �ִ�.


#endif
