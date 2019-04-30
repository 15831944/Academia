#include <iostream>

using std::cout;
using std::endl;

#include "2019.04.29.01.template.h"


template <typename T>
Example<T>::Example()
	: mNum(0)
{

}

template <typename T>
Example<T>::Example(T num)
	: mNum(num)
{

}

template <typename T>
Example<T>::~Example()
{

}


template <typename T>
T Example<T>::Add(T a)
{
	mNum += a;
	return mNum;
}