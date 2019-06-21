#pragma once
#ifndef _CHAR_STR_CMP_H_
#define _CHAR_STR_CMP_H_

#include <iostream>
// 아래에서 어떤 함수 사용하는지 체크하려고 임시로 넣어 놓음.

using std::cout;
using std::endl;

class CharStrCmp
{
public:
	CharStrCmp(const char *pString)
		: mpString(pString)
	{

	}
	~CharStrCmp() {}

public:
	template <typename T>
	bool operator() (const T& iterMap)
	{
		cout << "### template operator()" << endl;
		return !(strcmp(mpString, iterMap.first));
	}

	bool operator() (const char *pString)
	{
		cout << "### operator(const char *pString)" << endl;
		return !(strcmp(mpString, pString));
	}

private:
	const char *mpString;
};

#endif