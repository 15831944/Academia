#pragma once
#ifndef _DEFINE_H_
#define _DEFINE_H_

#define NAME_LEN 16

#define TRUE 1
#define FALSE 0

#define SAFE_DELETE(p) if(p) { delete p; p = nullptr; }
#define SAFE_DELETE_ARR(p) if(p) { delete[] p; p = nullptr; }


#endif