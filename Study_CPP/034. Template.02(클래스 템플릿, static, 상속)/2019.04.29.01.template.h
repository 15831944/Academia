#pragma once
#ifndef _TEMPLATE_H_
#define _TEMPLATE_H_

template <typename T>
class Example
{
public:
	Example();
	Example(T num);
	~Example();

public:
	T Add(T a);

private:
	T mNum;
};

#endif
