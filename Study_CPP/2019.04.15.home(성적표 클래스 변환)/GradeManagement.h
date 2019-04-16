#pragma once
#ifndef _GRADE_MANAGEMENT_H_
#define _GRADE_MANAGEMENT_H_

#define NAME_LEN 16

enum MENU { INSERT = 1, ALLINFO, SEARCH, EXIT };

class Student;

class ManageSystem {

private:

	Student *pStdArr;
	int stdCount = 0; // 생성자 배우면 그때 고칩시다.

public:

	void inputStudent(void);
	void printStdInfo(int index);
	void printAllStdInfo(void);
	void searchStdInfo(void);

	void deleteStdArr(void);

	const int getStdCount(void);
	void setStdCount(int val);


};

class Student {

private:

	char name[NAME_LEN];
	int kor;
	int eng;
	int math;
	int total;
	float average;

public:

	void setName(char *name);
	const char* getName(void);

	void setKor(int grade);
	const int getKor(void);
	void setEng(int grade);
	const int getEng(void);
	void setMath(int grade);
	const int getMath(void);

	void setTotal(void);
	const int getTotal(void);
	void setAverage(void);
	const float getAverage(void);

};

#endif