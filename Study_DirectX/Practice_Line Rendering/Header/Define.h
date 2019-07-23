#pragma once
#ifndef _DEFINE_H_
#define _DEFINE_H_

// #################################################################################################################
// General

#define WINSIZE_X 800
#define WINSIZE_Y 600


// #################################################################################################################
// Client(Win32)




// #################################################################################################################
#define NO_COPY(ClassName)						\
private:										\
	ClassName(const ClassName &);				\
	ClassName& operator= (const ClassName &);

#define DECLARE_SINGLETON(ClassName)			\
	NO_COPY(ClassName);							\
public:											\
	static ClassName* getInstance();			\
	static void DestroyInstance();				\
private:										\
	static ClassName *mpInstance;

#define IMPLEMENT_SINGLETON(ClassName)			\
ClassName* ClassName::mpInstance = nullptr;		\
ClassName* ClassName::getInstance()				\
{												\
	if (mpInstance == nullptr)					\
	{											\
		mpInstance = new ClassName;				\
	}											\
	return mpInstance;							\
}												\
void ClassName::DestroyInstance()				\
{												\
	if (mpInstance)								\
	{											\
		delete mpInstance;						\
		mpInstance = nullptr;					\
	}											\
}

// #################################################################################################################
#ifdef CLIENT
#define ERR_MSG(msg)	\
MessageBox(nullptr, msg, L"System Error", MB_OK)
#else
#define ERR_MSG(msg)	\
AfxMessageBox(msg)
#endif

#define NULL_CHECK(ptr)	\
if(nullptr == (ptr))	\
	return;

#define NULL_CHECK_MSG(ptr, msg)	\
if(nullptr == (ptr))				\
{									\
	ERR_MSG(msg);					\
	return;							\
}

#define NULL_CHECK_RETURN(ptr, returnValue)	\
if(nullptr == (ptr))						\
	return returnValue;

#define NULL_CHECK_MSG_RETURN(ptr, msg, returnValue)	\
if(nullptr == (ptr))									\
{														\
	ERR_MSG(msg);										\
	return returnValue;									\
}

#define FAILED_CHECK(hr)	\
if(FAILED(hr))				\
	return;

#define FAILED_CHECK_MSG(hr, msg)	\
if(FAILED(hr))						\
{									\
	ERR_MSG(msg);					\
	return;							\
}

#define FAILED_CHECK_RETURN(hr, returnValue)	\
if(FAILED(hr))									\
	return returnValue;

#define FAILED_CHECK_MSG_RETURN(hr, msg, returnValue)	\
if(FAILED(hr))											\
{														\
	ERR_MSG(msg);										\
	return returnValue;									\
}

#endif