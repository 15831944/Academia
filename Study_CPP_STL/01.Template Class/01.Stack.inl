#pragma once
#ifndef _STACK_INL_
#define _STACK_INL_

#include <iostream>

#define TRUE true
#define FALSE false

using std::cout;
using std::endl;
using std::cin;

template<typename T>
Stack<T>::Stack(int size)
{
	mSize = size;
	mData = new T[mSize];

	memset(mData, 0, sizeof(T) * mSize);

	Clear();
}

template<typename T>
Stack<T>::~Stack()
{
	delete[] mData;
}

template<typename T>
bool Stack<T>::Push(T data)
{
	if (mCount >= mSize)
	{
		return FALSE;
	}

	mData[mCount] = data;
	++mCount;
	true;
	return TRUE;
}

template<typename T>
T Stack<T>::pop()
{
	// 애매한데?!
	if (mCount <= 0)
	{
		return 0;
	}

	--mCount;

	return mData[mCount];
}

template<typename T>
void Stack<T>::Clear()
{
}

template<typename T>
bool Stack<T>::IsEmpty()
{
	return (mCount == 0) ? TRUE : FALSE;
}

template<typename T>
int Stack<T>::getCount()
{
	return mCount;
}

template<typename T>
int Stack<T>::getStackSize()
{
	return mSize;
}

#endif