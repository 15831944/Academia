#pragma once
#ifndef _STACK_H_
#define _STACK_H_

// ���ø� Ŭ������ ����� �����θ� ������ ���ؼ�,
// ������� "inline"�� �ǹ��ϴ� ".inl" ���� ����...

template <typename T> class Stack
{
public:
	explicit Stack(int size);
	~Stack();

public:
	bool Push(T data);
	T pop();
	void Clear();
	bool IsEmpty();

public:
	int getCount();
	int getStackSize();

private:
	T *mData;
	int mCount;

	int mSize;
};

#include "01.Stack.inl"

#endif