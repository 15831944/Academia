#pragma once
#ifndef _STACK_H_
#define _STACK_H_

// 템플릿 클래스의 선언과 구현부를 나누기 위해서,
// 편법으로 "inline"을 의미하는 ".inl" 파일 만들어서...

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