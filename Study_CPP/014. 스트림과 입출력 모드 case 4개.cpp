#include <iostream>

using std::cout;
using std::endl;

int main(void) {

	cout << "#######################################################" << endl;
	cout << "case 1. 바이너리 스트림, 바이너리 입출력" << endl;

	FILE *fp = nullptr;
	errno_t err = fopen_s(&fp, "./Hello.txt", "wb");

	if (err == 0) {

		char str[] = "\n";
		cout << "size: " << sizeof(str) << endl;

		fwrite(str, sizeof(str) / sizeof(char), 1, fp);

		cout << "파일 open 성공" << endl;

		fclose(fp);
	}
	else {

		cout << "파일 open 실패" << endl;
	}


	err = fopen_s(&fp, "./Hello.txt", "rb");

	if (err == 0) {

		int ch = 0;

		while (true) {

			fread(&ch, sizeof(char), 1, fp); // '\n' 읽고, NULL 읽음, EOF 없고 계속 NULL값
			fputc(ch, stdout); // NULL 문자도 출력 함.
			cout << "####" << endl;
			if (ch == EOF) { // EOF는 못 읽는 건가???

				cout << "EOF" << endl;
				break;
			}

			if (ch == '\0') {

				cout << "NULL" << endl;
				break;
			}
		}
		fclose(fp);

		cout << "파일 open 성공" << endl;
	}
	else {

		cout << "파일 open 실패" << endl;
	}

	cout << "#######################################################" << endl;
	cout << "case 2. 바이너리 스트림, 텍스트 입출력" << endl;
	err = fopen_s(&fp, "./Hello2.txt", "wb");

	if (err == 0) {

		cout << "파일 open 성공" << endl;

		char str[] = "\n";
		cout << "size: " << sizeof(str) << endl;

		cout << "fputs: " << fputs(str, fp) << endl;
		fclose(fp);


	}
	else {

		cout << "파일 open 실패" << endl;
	}



	err = fopen_s(&fp, "./Hello2.txt", "rb");

	if (err == 0) {

		cout << "파일 open 성공" << endl;

		char ch = 0;

		while (true) {

			ch = fgetc(fp);
			fputc(ch, stdout); // "\n" 읽고, 문자열의 끝인 '\0'은 그냥 무시해버리고 EOF네...
								// 콘솔 입출력 함수는 문자열 끝나면 바로 EOF

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

		cout << "파일 open 실패" << endl;
	}

	cout << "#######################################################" << endl;
	cout << "case 3. 텍스트 스트림, 텍스트 입출력" << endl;

	FILE *fp3 = nullptr;
	errno_t err3 = fopen_s(&fp3, "./Hello3.txt", "wt");

	if (err3 == 0) {

		char str[] = "\n";

		fputs(str, fp3);

		cout << "파일 open 성공" << endl;

		fclose(fp3);
	}
	else {

		cout << "파일 open 실패" << endl;

	}

	err3 = fopen_s(&fp3, "./Hello3.txt", "rt");

	if (err3 == 0) {

		char ch = 0;

		while (true) {

			ch = fgetc(fp3); // '\n'문자 다음에 바로 EOF
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

		cout << "파일 open 성공" << endl;

		fclose(fp3);
	}
	else {

		cout << "파일 open 실패" << endl;

	}
	cout << "#######################################################" << endl;
	cout << "case 4. 텍스트 스트림, 바이너리 입출력" << endl;

	FILE *fp4 = nullptr;
	errno_t err4 = fopen_s(&fp4, "./Hello4.txt", "wt");

	if (err4 == 0) {

		char str[] = "\n";

		fwrite(str, sizeof(str) / sizeof(char), 1, fp4);

		cout << "파일 open 성공" << endl;

		fclose(fp4);
	}
	else {

		cout << "파일 open 실패" << endl;
	}



	err4 = fopen_s(&fp4, "./Hello4.txt", "rt");

	if (err4 == 0) {

		char ch = 0;

		while (1) {

			fread(&ch, sizeof(char), 1, fp4); // '\n' 다음에 NULL 문자 읽었다. EOF 없다.
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

		cout << "파일 open 성공" << endl;

		fclose(fp4);
	}
	else {

		cout << "파일 open 실패" << endl;
	}

	return 0;
}