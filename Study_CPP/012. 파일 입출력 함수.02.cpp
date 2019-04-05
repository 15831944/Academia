/*

2019.04.05.01 금


###########################
    파일 입출력 함수.02
###########################

case 1. fseek()

- 파일 지시자의 위치를 변경할 수 있는 함수
(다음 번에 읽을 문자의 앞에 위치하고 있다 !!!!!)

int fseek(FILE *_Stream, long _Offset, int _Origin);

매개변수 FILE *_Stream : 대상 파일의 스트림
매개변수 long _Offset : 파일 지시자를 이동 시킬 byte 수 (양수면 뒤쪽_오른쪽, 음수면 앞쪽_왼쪽)
매개변수 int _Origin : 상대적인 파일 지시자의 위치
                      (SEEK_SET 파일의 시작, SEEK_CUR 파일 지시자의 현재 위치, SEEK_END 파일의 끝)
반환값 int : 파일 지시자의 위치를 옮기는데 성공하면 "0", 실패하면 "0"이 아닌 값.


case 2. ftell()

- 파일 지시자의 현재 위치를 알려주는 함수
- 첫 시작 위치는 "0"부터 시작함.

long ftell(FILE *_Stream);

매개변수 FILE *_Stream : 작업을 수행할 스트림의 FILE 구조체의 포인터
반환값 long : 파일 지시자의 현재 위치를 반환. (파일의 시작은 "0"을 의미한다.)


case 3. feof()

- 파일 지시자가 EOF(End Of File)에 도달 했는지 검사하는 함수.
- 도달 했으면 "0"이 아닌 값을 반환
  "0"이면 파일을 읽고 있는 도중 !!!!

int feof(FILE *_Stream);

FILE *_Stream : 작업을 수행할 스트림의 FILE 구조체의 포인터
반환값 int : 파일의 끝에 도달 했으면 "0"이 아닌 값을 반환, "0"이면 파일을 읽고 있는 중 !!!!

while (feof(fp3) == 0) {
	int ch = fgetc(fp3);
	fputc(ch, stdout); // 단일 문자 출력이라 아스키 코드 값에 따른 문자 !!!!
}
// 출력 "1234567890 " 빈칸이 출력 되었네???
// 진짜 끝인지 한 번 더 확인하는 과정에서 출력하는 것임.
// 그리고, Windows에서는 개행을 "\r\n"으로 사용하니까 문자 2개로 읽힘.

- 한 번 더 EOF가 맞는지 확인한다 !!!!
(오류를 만나서 파일 입출력이 끝나는 것인지, 정상적으로 끝나는 것인지 확인하기 위해서...)

because, EOF를 만나도 "0"을 반환하기 때문에... 넘어서야 다른 값 반환해서 끝남 !!!!


#########################################################################################################


*/

#include <iostream>

using std::cout;
using std::endl;

int main(void) {

	cout << "###############################################################################" << endl;
	cout << "### 파일 입출력 함수.02 " << endl << endl;

	FILE *fp = nullptr;
	errno_t err = fopen_s(&fp, "test.txt", "rb"); // 1234567890 입력해서 Source 텍스트 만들 것 !!!!

	if (err == 0) { // 파일 개방 성공

		cout << "Hello test.txt" << endl << endl;

		int ch = 0;

		// ㅁ1234567890

		// 파일 지시자가 시작 위치에서 뒤로(양수_오른쪽) 2 bytes 이동
		// 12 ㅁ 34567890
		fseek(fp, 2, SEEK_SET);
		ch = fgetc(fp);
		fputc(ch, stdout); // "3" 출력이 되니까 파일 지시자의 위치가 "2"와 "3" 사이 !!!!
		fseek(fp, -1, SEEK_CUR);

		cout << endl;

		// 파일 지시자가 현재 위치에서 뒤로(양수_오른쪽) 2 bytes 이동
		// 1234 ㅁ 567890
		fseek(fp, 2, SEEK_CUR);
		ch = fgetc(fp);
		fputc(ch, stdout); // "5" 출력이 되니까 파일 지시자의 위치가 "4"와 "5" 사이 !!!!
		fseek(fp, -1, SEEK_CUR);

		cout << endl;
		
		// 파일 지시자가 파일의 끝 위치에서 앞으로(음수_왼쪽) 2 bytes 이동
		// 12345678 ㅁ 90
		fseek(fp, -2, SEEK_END);
		ch = fgetc(fp);
		fputc(ch, stdout); // "9" 출력이 되니까 파일 지시자의 위치가 "8"과 "9" 사이 !!!!
		fseek(fp, -1, SEEK_CUR);

		cout << endl;

		fclose(fp);

	}
	else {

		cout << "파일 개방 실패" << endl;
	}

	cout << "###############################################################################" << endl;
	cout << "### 파일 지시자의 현재 위치 - ftell()" << endl << endl;

	FILE *fp2 = nullptr;
	errno_t err2 = fopen_s(&fp2, "test.txt", "rb");

	if (err2 == 0) { // 파일 개방 성공

		// 12 ㅁ 34567890
		fseek(fp2, 2, SEEK_SET);

		// 123 4567890
		int ch = fgetc(fp2);

		// So, 처음 "0"부터 시작해서, 2 bytes 이동하고, 한개의 문자를 출력했으니 - 3 출력.
		cout << "파일 지시자의 위치: " << ftell(fp2) << endl;

		fclose(fp2);
	}
	else {

		cout << "파일 개방 실패" << endl;
	}

	cout << "###############################################################################" << endl;
	cout << "### 파일의 끝에 도달했는지 확인 - feof()" << endl << endl;

	FILE *fp3 = nullptr;
	errno_t err3 = fopen_s(&fp3, "test.txt", "rb");
	int count = 0;

	if (err3 == 0) { // 파일 개방 성공

		while (feof(fp3) == 0) { // 파일을 읽고 있는 중이면...

			int ch = fgetc(fp3);
			fputc(ch, stdout);

			count++; // "Enter"는 Windows라서 그런지 \r\n으로 인식하는 것 같음.

		}
		
		// 출력 "1234567890 " 빈칸이 1개 출력 되었네???
		// 진짜 끝인지 한 번 더 확인하는 과정에서 출력하는 것임.
		cout << "count1 : " << count << endl;


		fseek(fp3, 0, SEEK_SET);
		count = 0;

		while (1) {

			int ch = fgetc(fp3);

			if (feof(fp3) != 0) { // 입력을 받고 바로 검사를 해서 반복문을 빠져나가야 원하는 결과를 얻음.

				break;
			}

			fputc(ch, stdout);
			if (ch == '6') { // 단일 문자로 넣어줘야 하네...
				fputs("Hello", stdout);
			}
			if (ch == EOF) {
				fputs("World", stdout);
			}

			count++; // "Enter"는 Windows라서 그런지 \r\n으로 인식하는 것 같음.
		}

		cout << "count2 : " << count << endl;

		fclose(fp3);
	}
	else {

		cout << "파일 개방 실패" << endl;
	}

	cout << "###############################################################################" << endl;
	cout << "### 이미지 파일 바이너리 복사" << endl << endl;

	FILE *fInput = nullptr;
	FILE *fOutput = nullptr;

	errno_t errInput = fopen_s(&fInput, "./devcat.png", "rb");
	
	if (errInput == 0) {

		errno_t errOutput = fopen_s(&fOutput, "./copy.png", "wb");
		if (errOutput == 0) {

			// case 1. 동적 배열을 만들어서.... fseek()을 이용한 방법
			// - 파일의 끝을 ftell()로 찍어서 Bytes 읽어오고, 메모리 동적 할당을 한 뒤에 복사 받음.

		/*	fseek(fInput, 0, SEEK_END);
			int size = ftell(fInput);

			fseek(fInput, 0, SEEK_SET);

			char *ptr = new char[size];
			fread(ptr, sizeof(char) * size, 1, fInput);
			fwrite(ptr, sizeof(char) * size, 1, fOutput);*/


			// case 2. feof()를 이용하는 방법
			while (feof(fInput) == 0) { // 아까 feof()는 바이트 더 읽을 수 있다는 것 !!!!
				char ch = 0;
				fread(&ch, sizeof(char), 1, fInput);
				fwrite(&ch, sizeof(char), 1, fOutput);
			}


			cout << "파일 복사 성공" << endl;

			fclose(fOutput);

		}
		else {

		}

		fclose(fInput);
	}

	cout << "###############################################################################" << endl;

	return 0;
}