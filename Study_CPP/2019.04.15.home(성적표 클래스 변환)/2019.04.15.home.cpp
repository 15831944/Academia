#include "stdafx.h"
#include "GradeManagement.h"

int main(void) {

	ManageSystem sys;
	int sel = 0;

	while (TRUE) { // ManageSystem 객체에 대한 처리 로직

		system("cls");
		cout << "1. 학생 추가, 2. 전체 출력, 3. 검색 출력, 4. 종료" << endl;
		cout << "#################################################" << endl;
		cout << "입력: ";
		cin >> sel;

		switch (sel) {

		case MENU::INSERT:
			sys.inputStudent();
			break;
		case MENU::ALLINFO:
			sys.printAllStdInfo();
			break;
		case MENU::SEARCH:
			sys.searchStdInfo();
			break;
		case MENU::EXIT:
			cout << "성적표 시스템을 종료합니다." << endl;
			sys.deleteStdArr();
			return 0;

		default:
			cout << "잘못된 입력입니다." << endl;
			system("pause");
			continue;
		}
	}

	return 0;
}