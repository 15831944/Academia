#include <iostream>

using std::cout;
using std::endl;

int main(void) {

	cout << "#######################################################" << endl;
	cout << "case 1. ���̳ʸ� ��Ʈ��, ���̳ʸ� �����" << endl;

	FILE *fp = nullptr;
	errno_t err = fopen_s(&fp, "./Hello.txt", "wb");

	if (err == 0) {

		char str[] = "\n";
		cout << "size: " << sizeof(str) << endl;

		fwrite(str, sizeof(str) / sizeof(char), 1, fp);

		cout << "���� open ����" << endl;

		fclose(fp);
	}
	else {

		cout << "���� open ����" << endl;
	}


	err = fopen_s(&fp, "./Hello.txt", "rb");

	if (err == 0) {

		int ch = 0;

		while (true) {

			fread(&ch, sizeof(char), 1, fp); // '\n' �а�, NULL ����, EOF ���� ��� NULL��
			fputc(ch, stdout); // NULL ���ڵ� ��� ��.
			cout << "####" << endl;
			if (ch == EOF) { // EOF�� �� �д� �ǰ�???

				cout << "EOF" << endl;
				break;
			}

			if (ch == '\0') {

				cout << "NULL" << endl;
				break;
			}
		}
		fclose(fp);

		cout << "���� open ����" << endl;
	}
	else {

		cout << "���� open ����" << endl;
	}

	cout << "#######################################################" << endl;
	cout << "case 2. ���̳ʸ� ��Ʈ��, �ؽ�Ʈ �����" << endl;
	err = fopen_s(&fp, "./Hello2.txt", "wb");

	if (err == 0) {

		cout << "���� open ����" << endl;

		char str[] = "\n";
		cout << "size: " << sizeof(str) << endl;

		cout << "fputs: " << fputs(str, fp) << endl;
		fclose(fp);


	}
	else {

		cout << "���� open ����" << endl;
	}



	err = fopen_s(&fp, "./Hello2.txt", "rb");

	if (err == 0) {

		cout << "���� open ����" << endl;

		char ch = 0;

		while (true) {

			ch = fgetc(fp);
			fputc(ch, stdout); // "\n" �а�, ���ڿ��� ���� '\0'�� �׳� �����ع����� EOF��...
								// �ܼ� ����� �Լ��� ���ڿ� ������ �ٷ� EOF

			if (ch == EOF) {

				cout << "EOF" << endl;
				break;
			}

			if (ch == '\0') {

				cout << "NULL" << endl;
				break;

			}
		}
		fclose(fp);

	}
	else {

		cout << "���� open ����" << endl;
	}

	cout << "#######################################################" << endl;
	cout << "case 3. �ؽ�Ʈ ��Ʈ��, �ؽ�Ʈ �����" << endl;

	FILE *fp3 = nullptr;
	errno_t err3 = fopen_s(&fp3, "./Hello3.txt", "wt");

	if (err3 == 0) {

		char str[] = "\n";

		fputs(str, fp3);

		cout << "���� open ����" << endl;

		fclose(fp3);
	}
	else {

		cout << "���� open ����" << endl;

	}

	err3 = fopen_s(&fp3, "./Hello3.txt", "rt");

	if (err3 == 0) {

		char ch = 0;

		while (true) {

			ch = fgetc(fp3); // '\n'���� ������ �ٷ� EOF
			cout << ch << "#########" << endl;

			if (ch == EOF) {

				cout << "EOF" << endl;
				break;
			}

			if (ch == '\0') {

				cout << "NULL" << endl;
				break;
			}
		}

		cout << "���� open ����" << endl;

		fclose(fp3);
	}
	else {

		cout << "���� open ����" << endl;

	}
	cout << "#######################################################" << endl;
	cout << "case 4. �ؽ�Ʈ ��Ʈ��, ���̳ʸ� �����" << endl;

	FILE *fp4 = nullptr;
	errno_t err4 = fopen_s(&fp4, "./Hello4.txt", "wt");

	if (err4 == 0) {

		char str[] = "\n";

		fwrite(str, sizeof(str) / sizeof(char), 1, fp4);

		cout << "���� open ����" << endl;

		fclose(fp4);
	}
	else {

		cout << "���� open ����" << endl;
	}



	err4 = fopen_s(&fp4, "./Hello4.txt", "rt");

	if (err4 == 0) {

		char ch = 0;

		while (1) {

			fread(&ch, sizeof(char), 1, fp4); // '\n' ������ NULL ���� �о���. EOF ����.
			fputc(ch, stdout);
			cout << "###########" << endl;

			if (ch == EOF) {

				cout << "EOF" << endl;
				break;
			}

			if (ch == '\0') {

				cout << "NULL" << endl;
				break;
			}

		}

		cout << "���� open ����" << endl;

		fclose(fp4);
	}
	else {

		cout << "���� open ����" << endl;
	}

	return 0;
}