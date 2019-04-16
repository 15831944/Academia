#include "stdafx.h"
#include "GradeManagement.h"

int main(void) {

	ManageSystem sys;
	int sel = 0;

	while (TRUE) { // ManageSystem ��ü�� ���� ó�� ����

		system("cls");
		cout << "1. �л� �߰�, 2. ��ü ���, 3. �˻� ���, 4. ����" << endl;
		cout << "#################################################" << endl;
		cout << "�Է�: ";
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
			cout << "����ǥ �ý����� �����մϴ�." << endl;
			sys.deleteStdArr();
			return 0;

		default:
			cout << "�߸��� �Է��Դϴ�." << endl;
			system("pause");
			continue;
		}
	}

	return 0;
}