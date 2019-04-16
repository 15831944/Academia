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
		cout << "(�߰�) �л� ��: ";
		cin >> num;

		if (num <= 0) {
			cout << "�߸��� �Է��Դϴ�." << endl;
			system("pause");
			continue;
		}

		count = stdCount + num;
		Student *tempArr = new Student[count];
		if (tempArr == nullptr) {

			cout << "����, �޸� ���� �Ҵ� ManageSystem::inputStudent()" << endl;
			system("pause");
			break;
		}

		// ������ �غ��ô�.
		// ó�� ���α׷��� �����ϸ� �л��� ������ ���� ���¿��� ������.
		// but, �Է��� ������ �л� �� ī��Ʈ�� ��.
		// ������ �ִ� �����͸� �����ϴ� ������ �Է� �޴� ������ �����ؾ� ��.

		// case 1. ������ �����Ͱ� �ִ� ��� - ������ ����
		for (int i = 0; i < stdCount; i++) { // but, ó���� �Է��� �޾ƾ�...

		}

		// case 2. ������ �����Ͱ� ���� ��� - ���� �Է� ����.

		for (int i = stdCount; i < count; i++) {

			cout << "�̸�: "; cin >> name; tempArr[i].setName(name);
			cout << "����: "; cin >> kor; tempArr[i].setKor(kor);
			cout << "����: "; cin >> eng; tempArr[i].setEng(eng);
			cout << "����: "; cin >> math; tempArr[i].setMath(math);
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
		break; // ������ ���� �����ϸ� �ڵ������� �ݺ��� ���.
	}
}

void ManageSystem::printStdInfo(int index) {

	cout << "�̸�: " << pStdArr[index].getName() << endl;
	cout << "-------------------" << endl;
	cout << "����: " << pStdArr[index].getKor() << endl;
	cout << "����: " << pStdArr[index].getEng() << endl;
	cout << "����: " << pStdArr[index].getMath() << endl;
	cout << "-------------------" << endl;
	cout << "����: " << pStdArr[index].getTotal() << endl;
	streamsize prec = cout.precision();
	cout.precision(4); // ���߿� �ڸ��� ������ �ؼ� ���� ��.
	cout << "���: " << pStdArr[index].getAverage() << endl;
	cout.precision(prec);
	cout << "###################" << endl << endl;
}


void ManageSystem::printAllStdInfo()
{
	system("cls");

	cout << "#### ��ü ��� ####" << endl << endl;
	if (stdCount != 0) {

		for (int i = 0; i < stdCount; i++) {

			printStdInfo(i);
		}
		cout << endl;
	}
	else {

		cout << "�Էµ� �л��� �����ϴ�." << endl << endl;
	}
	system("pause");
}

void ManageSystem::searchStdInfo()
{
	char name[NAME_LEN] = {};

	system("cls");

	cout << "ã�� ��� �̸�: ";
	cin >> name;

	cout << "#### �˻� ��� ####" << endl << endl;
	for (int i = 0; i < stdCount; i++) {

		if (!strcmp(name, pStdArr[i].getName())) {

			printStdInfo(i);
			system("pause");
			return;
		}
	}

	cout << "�ش� ����� ã�� ���Ͽ����ϴ�." << endl << endl;
	system("pause");
}



void ManageSystem::deleteStdArr(void) {

	if (pStdArr != nullptr) {

		delete[] pStdArr;
		pStdArr = nullptr; // Dangling pointer �ʱ�ȭ
	}

}



const int ManageSystem::getStdCount() {

	return stdCount;
}

void ManageSystem::setStdCount(int val) {

	if (val > 0) {

		stdCount = val; // ��Ȯ�� �������� ���� ó�� �ؾ���.
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

		cout << "�ùٸ��� ���� �Է��̹Ƿ� \"0\"�� �Էµ˴ϴ�." << endl;
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

		cout << "�ùٸ��� ���� �Է��̹Ƿ� \"0\"�� �Էµ˴ϴ�." << endl;
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

		cout << "�ùٸ��� ���� �Է��̹Ƿ� \"0\"�� �Էµ˴ϴ�." << endl;
		math = 0;
	}
}
const int Student::getMath(void) {

	return math;
}

void Student::setTotal(void) {

	int total = kor + eng + math;
	this->total = total; // �� ��������?!
}
const int Student::getTotal(void) {

	return total;
}
void Student::setAverage(void) {

	float aver = total / 3.f;
	this->average = aver; // �� ��������?!
}
const float Student::getAverage(void) {

	return average;
}



