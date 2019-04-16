#include "stdafx.h"
#include "GradeManagement.h"

void ManageSystem::inputStudent()
{
	int num = 0;
	int count = 0;

	char name[16] = {};
	int kor = 0, eng = 0, math = 0;

	while (TRUE) {
		system("cls");
		cout << "(추가) 학생 수: ";
		cin >> num;

		if (num <= 0) {
			cout << "잘못된 입력입니다." << endl;
			system("pause");
			continue;
		}

		count = stdCount + num;
		Student *tempArr = new Student[count];
		if (tempArr == nullptr) {

			cout << "오류, 메모리 동적 할당 ManageSystem::inputStudent()" << endl;
			system("pause");
			break;
		}

		// 생각을 해봅시다.
		// 처음 프로그램을 시작하면 학생의 정보가 없는 상태에서 시작함.
		// but, 입력을 받으면 학생 수 카운트가 됨.
		// 이전에 있던 데이터를 복사하는 로직과 입력 받는 로직이 공존해야 함.

		// case 1. 이전에 데이터가 있는 경우 - 데이터 이전
		for (int i = 0; i < stdCount; i++) { // but, 처음에 입력을 받아야...

		}

		// case 2. 이전에 데이터가 없는 경우 - 새로 입력 받음.

		for (int i = stdCount; i < count; i++) {

			cout << "이름: "; cin >> name; tempArr[i].setName(name);
			cout << "국어: "; cin >> kor; tempArr[i].setKor(kor);
			cout << "영어: "; cin >> eng; tempArr[i].setEng(eng);
			cout << "수학: "; cin >> math; tempArr[i].setMath(math);
			cout << endl;

			tempArr[i].setTotal();
			tempArr[i].setAverage();

		}

		if (stdCount != 0) {

			memcpy_s(tempArr, sizeof(Student) * stdCount, pStdArr, sizeof(Student) * stdCount);
		}

		deleteStdArr();

		pStdArr = tempArr;
		tempArr = nullptr;
		stdCount = count;

		system("pause");
		break; // 로직의 끝에 도달하면 자동적으로 반복문 벗어남.
	}
}

void ManageSystem::printStdInfo(int index) {

	cout << "이름: " << pStdArr[index].getName() << endl;
	cout << "-------------------" << endl;
	cout << "국어: " << pStdArr[index].getKor() << endl;
	cout << "영어: " << pStdArr[index].getEng() << endl;
	cout << "수학: " << pStdArr[index].getMath() << endl;
	cout << "-------------------" << endl;
	cout << "총점: " << pStdArr[index].getTotal() << endl;
	streamsize prec = cout.precision();
	cout.precision(4); // 나중에 자리수 계산까지 해서 넣을 것.
	cout << "평균: " << pStdArr[index].getAverage() << endl;
	cout.precision(prec);
	cout << "###################" << endl << endl;
}


void ManageSystem::printAllStdInfo()
{
	system("cls");

	cout << "#### 전체 출력 ####" << endl << endl;
	if (stdCount != 0) {

		for (int i = 0; i < stdCount; i++) {

			printStdInfo(i);
		}
		cout << endl;
	}
	else {

		cout << "입력된 학생이 없습니다." << endl << endl;
	}
	system("pause");
}

void ManageSystem::searchStdInfo()
{
	char name[NAME_LEN] = {};

	system("cls");

	cout << "찾을 대상 이름: ";
	cin >> name;

	cout << "#### 검색 출력 ####" << endl << endl;
	for (int i = 0; i < stdCount; i++) {

		if (!strcmp(name, pStdArr[i].getName())) {

			printStdInfo(i);
			system("pause");
			return;
		}
	}

	cout << "해당 대상을 찾지 못하였습니다." << endl << endl;
	system("pause");
}



void ManageSystem::deleteStdArr(void) {

	if (pStdArr != nullptr) {

		delete[] pStdArr;
		pStdArr = nullptr; // Dangling pointer 초기화
	}

}



const int ManageSystem::getStdCount() {

	return stdCount;
}

void ManageSystem::setStdCount(int val) {

	if (val > 0) {

		stdCount = val; // 정확한 숫자인지 오류 처리 해야함.
	}
	else {
		

	}
}


/////////////////////////////////////////////////////////////////////////////////

void Student::setName(char *name) {

	if (name != nullptr) {
		strcpy_s(this->name, NAME_LEN, name);
	}
}
const char* Student::getName(void) {

	return name;
}

void Student::setKor(int grade) {

	if (grade >= 0 && grade <= 100) {

		kor = grade;
	}
	else {

		cout << "올바르지 못한 입력이므로 \"0\"이 입력됩니다." << endl;
		kor = 0;
	}
}
const int Student::getKor(void) {

	return kor;
}
void Student::setEng(int grade) {

	if (grade >= 0 && grade <= 100) {

		eng = grade;
	}
	else {

		cout << "올바르지 못한 입력이므로 \"0\"이 입력됩니다." << endl;
		eng = 0;
	}
}
const int Student::getEng(void) {

	return eng;
}
void Student::setMath(int grade) {

	if (grade >= 0 && grade <= 100) {

		math = grade;
	}
	else {

		cout << "올바르지 못한 입력이므로 \"0\"이 입력됩니다." << endl;
		math = 0;
	}
}
const int Student::getMath(void) {

	return math;
}

void Student::setTotal(void) {

	int total = kor + eng + math;
	this->total = total; // 한 문장으로?!
}
const int Student::getTotal(void) {

	return total;
}
void Student::setAverage(void) {

	float aver = total / 3.f;
	this->average = aver; // 한 문장으로?!
}
const float Student::getAverage(void) {

	return average;
}



