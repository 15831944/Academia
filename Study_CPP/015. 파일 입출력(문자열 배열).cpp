#include <iostream>

using std::cout;
using std::endl;

int main(void) {

	cout << "################################################################" << endl;
	cout << "### case 1. 텍스트 작성(fputs 문자열), 출력모드, 입력모드 변경" << endl;

	FILE *fp = nullptr;
	errno_t err = fopen_s(&fp, "./Hello1.txt", "wt"); // binary 모드로 저장 이상한 문자 + 쓴 문자들, NULL 문자 없음.
													  // text 모드로 저장 개행 되고 + 쓴 문자들, NULL 문자 없음.

	if (err == 0) {

		cout << "파일 open 성공" << endl;

		char str[] = "\nbc"; // '\n' + 'b' + 'c' + '\0' 4개
		fputs(str, fp); // 이상한 문자('\n') + b + c, 그런데 NULL 문자는 출력 안되서 텍스트 파일에 없음 !!!!
						// binary 모드에서는 NULL 문자는 출력 안 하나봐 !!!!

		fclose(fp);
	}
	else {

		cout << "파일 open 실패" << endl;
	}



	//err = fopen_s(&fp, "./Hello1.txt", "rt");
	//
	//if (err == 0) {
	//
	//	cout << "파일 open 성공" << endl;
	//
	//	char ch = 0;
	//
	//	while (1) {
	//
	//		ch = fgetc(fp); // binary 모드 저장, binary 읽기 : '\n' + 'b' + 'c' + EOF
	//						// text 모드 저장, binary 읽기 : '\r' + '\n' + 'b' + 'c' + EOF
	//						// binary 모드 저장, text 읽기 : '\n' +  'b' + 'c' + EOF
	//						// text 모드 저장, text 읽기 : '\n' +  'b' + 'c' + EOF
	//		if (ch == EOF) {
	//
	//			cout << "EOF" << endl;
	//			break;
	//		}
	//
	//		if (ch == '\0') {
	//
	//			cout << "NULL" << endl;
	//			break;
	//		}
	//	}
	//
	//	fclose(fp);
	//}
	//else {
	//
	//	cout << "파일 open 실패" << endl;
	//}



	//err = fopen_s(&fp, "./Hello1.txt", "rt");
	//
	//if (err == 0) {
	//
	//	cout << "파일 open 성공" << endl;
	//
	//	char ch = 0;
	//
	//	while (1) {
	//
	//		fread(&ch, sizeof(char), 1, fp); // binary 모드 저장, binary 읽기 : '\n' + 'b' + 'c'(계속)
	//										// text 모드 저장, binary 읽기 : '\r' + '\n' + 'b' + 'c'(계속)
	//										// binary 모드 저장, text 읽기 : '\n' + 'b' + 'c'(계속)
	//										// text 모드 저장, text 읽기 : '\n' + 'b' + 'c'(계속)
	//
	//		if (ch == EOF) {
	//
	//			cout << "EOF" << endl;
	//			//break;
	//		}
	//
	//		if (ch == '\0') {
	//
	//			cout << "NULL" << endl;
	//			break;
	//		}
	//
	//	}
	//
	//	fclose(fp);
	//}
	//else {
	//
	//	cout << "파일 open 실패" << endl;
	//}



	//err = fopen_s(&fp, "./Hello1.txt", "rt");
	//
	//if (err == 0) {
	//
	//	cout << "파일 open 성공" << endl;
	//
	//	char str[10];
	//
	//	fgets(str, sizeof(str), fp); // binary 모드 저장, binary 읽기 : '\n' + '\0' 개행이 나오면 문자열이 끝난 걸로 생각해서 NULL 문자 붙여주고 읽어 오나봄...
	//								// text 모드 저장, binary 읽기 : '\r' + '\n' + '\0' 개행으로 문자열의 끝을 판단해서 NULL 문자 넣어줌.
	//								// binary 모드 저장, text 읽기 : '\n' + '\0'
	//								// text 모드 저장, text 읽기 : '\n' + '\0'
	//
	//	fgets(str, sizeof(str), fp); // binary 모드 저장, binary 읽기 : 'b' + 'c' + '\0'
	//								// text 모드 저장, binary 읽기 : 'b' + 'c' + '\0'
	//								// binary 모드 저장, text 읽기 : 'b' + 'c' + '\0'
	//								// text 모드 저장, text 읽기 : 'b' + 'c' + '\0'
	//
	//	fclose(fp);
	//}
	//else {
	//
	//	cout << "파일 open 실패" << endl;
	//}



	//err = fopen_s(&fp, "./Hello1.txt", "rt");
	//
	//if (err == 0) {
	//
	//	cout << "파일 open 성공" << endl;
	//
	//	char str[10];
	//
	//	fread(str, sizeof(char), 10, fp); // binary 모드 저장, binary 읽기 : '\n' + 'b' + 'c'
	//									  // 텍스트 파일에 NULL 문자가 없어서 데이터를 못 읽어오니까
	//									  // 문자열 끝에 NULL 문자가 없어서 메모리 누수 생김 !!!!
	//
	//									  // text 모드 저장, binary 읽기 :  '\r' + '\n' + 'b' + 'c'
	//									  // 마찬가지로 NULL 문자가 없어서 메모리 누수가 생김 !!!!
	//
	//									  // binary 모드 저장, text 읽기 : '\n' + 'b' + 'c'
	//									  // NULL 문자 없어서 메모리 누수 !!!!
	//
	//									  // text 모드 저장, text 읽기 : '\n' + 'b' + 'c'
	//									  // NULL 문자 없어서 메모리 누수 !!!!
	//
	//	fclose(fp);
	//}
	//else {
	//
	//	cout << "파일 open 실패" << endl;
	//}


	cout << "################################################################" << endl;
	cout << "### case 2. 텍스트 작성(fwrite 문자열), 출력모드, 입력모드 변경" << endl;

	err = fopen_s(&fp, "./Hello2.txt", "wt");

	if (err == 0) {

		cout << "파일 open 성공" << endl;

		char str[] = "\nbc";
		fwrite(str, sizeof(str) / sizeof(char), 1, fp); // binary 모드 저장 : 이상한 문자('\n') + 쓴 문자들 + 빈 공간 1개 NULL ('\0') !!!!
														// text 모드 저장 : 개행되고 + 쓴 문자들 + 빈 공간 1개 null ('\0') !!!!
		fclose(fp);
	}
	else {

		cout << "파일 open 성공" << endl;
	}




	//err = fopen_s(&fp, "./Hello2.txt", "rt");
	//
	//if (err == 0) {
	//
	//	cout << "파일 open 성공" << endl;
	//
	//	char ch = 0;
	//
	//	while (1) {
	//
	//		ch = fgetc(fp); // binary 모드 저장, binary 읽기 : '\n' + 'b' + 'c' + '\0' + EOF
	//						// text 모드 저장, binary 읽기 : '\r' + '\n' + 'b' + 'c' + '\0' + EOF
	//						// binary 모드 저장, text 읽기 : '\n' + 'b' + 'c' + '\0' + EOF
	//						// text 모드 저장, text 읽기 : '\n' + 'b' + 'c' + '\0' + EOF
	//		if (ch == EOF) {
	//
	//			cout << "EOF" << endl;
	//			break;
	//		}
	//
	//		if (ch == '\0') {
	//
	//			cout << "NULL" << endl;
	//			//break;
	//		}
	//	}
	//
	//	fclose(fp);
	//
	//	cout << "파일 open 실패" << endl;
	//}



	//err = fopen_s(&fp, "./Hello2.txt", "rt");
	//
	//if (err == 0) {
	//
	//	cout << "파일 open 성공" << endl;
	//
	//	char ch = 0;
	//
	//	while (1) {
	//
	//		fread(&ch, sizeof(char), 1, fp); // binary 모드 저장, binary 읽기 : '\n' + 'b' + 'c' + '\0'(계속)
	//										 // text 모드 저장, binary 읽기 : '\r' + '\n' + 'b' + 'c' + '\0'(계속)
	//										 // binary 모드 저장, text 읽기 : '\n' + 'b' + 'c' + '\0'(계속)
	//										 // text 모드 저장, text 읽기 : '\n' + 'b' + 'c' + '\0'(계속)
	//
	//		if (ch == EOF) {
	//
	//			cout << "EOF" << endl;
	//			break;
	//		}
	//
	//		if (ch == '\0') {
	//
	//			cout << "NULL" << endl;
	//			//break;
	//		}
	//
	//	}
	//
	//	fclose(fp);
	//}
	//else {
	//
	//	cout << "파일 open 실패" << endl;
	//}



	//err = fopen_s(&fp, "./Hello2.txt", "rt");
	//
	//if (err == 0) {
	//
	//	cout << "파일 open 성공" << endl;
	//
	//	char str[10];
	//
	//	fgets(str, sizeof(str), fp); // binary 모드 저장, binary 읽기 : '\n' + '\0' 개행으로 문자열의 끝을 판단해서 NULL 문자 넣어줌.
	//								 // text 모드 저장, binary 읽기 : '\r' + '\n' + '\0' 
	//								 // binary 모드 저장, text 읽기 : '\n' + '\0'
	//								 // text 모드 저장, text 읽기 : '\n' + '\0'
	//
	//	fgets(str, sizeof(str), fp); // binary 모드 저장, binary 읽기 : 'b' + 'c' + '\0' + '\0'
	//								 // text 모드 저장, binary 읽기 : 'b' + 'c' + '\0' + '\0'
	//								 // binary 모드 저장, text 읽기 : 'b' + 'c' + '\0' + '\0'
	//								 // text 모드 저장, text 읽기 : 'b' + 'c' + '\0' + '\0'
	//
	//	fclose(fp);
	//}
	//else {
	//
	//	cout << "파일 open 실패" << endl;
	//}



	//err = fopen_s(&fp, "./Hello2.txt", "rt");
	//
	//if (err == 0) {
	//
	//	cout << "파일 open 성공" << endl;
	//
	//	char str[10];
	//
	//	fread(str, sizeof(char), 10, fp); // binary 모드 저장, binary 읽기 : '\n' + 'b' + 'c' + '\0'
	//									  // fwrite로 binary 모드 저장 했더니 텍스트 파일에 NULL 문자가 들어가있음.
	//
	//									  // text 모드 저장, binary 읽기 :  '\r' + '\n' + 'b' + 'c' + '\0'
	//
	//									  // binary 모드 저장, text 읽기 : '\n' + 'b' + 'c' + '\0'
	//
	//									  // text 모드 저장, text 읽기 : '\n' + 'b' + 'c' + '\0'
	//
	//	fclose(fp);
	//}
	//else {
	//
	//	cout << "파일 open 실패" << endl;
	//}



	cout << "################################################################" << endl;
	cout << "### case 3. 텍스트 작성(fputc 문자 단위), 출력모드, 입력모드 변경" << endl;

	err = fopen_s(&fp, "./Hello3.txt", "wt");

	if (err == 0) {

		cout << "파일 open 성공" << endl;

		char str[] = "\nbc"; // '\n' + 'b' + 'c' + '\0' 4개

		for (int i = 0; i < sizeof(str) / sizeof(char); i++) {

			char ch = str[i];
			fputc(ch, fp); // binary 모드 저장 : 이상한 문자('\n') + b + c + 빈 공간 1개 NULL ('\0') 문자 !!!!
						   // text 모드 저장 : 개행되고, b + c + 빈 공간 1개 NULL ('\0') 문자 !!!!
		}


		fclose(fp);
	}
	else {

		cout << "파일 open 실패" << endl;
	}



	//err = fopen_s(&fp, "./Hello3.txt", "rt");
	//
	//if (err == 0) {
	//
	//	cout << "파일 open 성공" << endl;
	//
	//	char ch = 0;
	//
	//	while (1) {
	//
	//		ch = fgetc(fp); // binary 모드 저장, binary 읽기 : '\n' + 'b' + 'c' + '\0' + EOF
	//						// text 모드 저장, binary 읽기 : '\r' + '\n' + 'b' + 'c' + '\0' + EOF
	//						// binary 모드 저장, text 읽기 : '\n' + 'b' + 'c' + '\0' + EOF
	//						// text 모드 저장, text 읽기 : '\n' + 'b' + 'c' + '\0' + EOF
	//		if (ch == EOF) {
	//
	//			cout << "EOF" << endl;
	//			break;
	//		}
	//
	//		if (ch == '\0') {
	//
	//			cout << "NULL" << endl;
	//			//break;
	//		}
	//	}
	//
	//	fclose(fp);
	//
	//	cout << "파일 open 실패" << endl;
	//}



	//err = fopen_s(&fp, "./Hello3.txt", "rt");
	//
	//if (err == 0) {
	//
	//	cout << "파일 open 성공" << endl;
	//
	//	char ch = 0;
	//
	//	while (1) {
	//
	//		fread(&ch, sizeof(char), 1, fp); // binary 모드 저장, binary 읽기 : '\n' + 'b' + 'c' + '\0'(계속)
	//										 // text 모드 저장, binary 읽기 : '\r' + '\n' + 'b' + 'c' + '\0'(계속)
	//										 // binary 모드 저장, text 읽기 : '\n' + 'b' + 'c' + '\0'(계속)
	//										 // text 모드 저장, text 읽기 : '\n' + 'b' + 'c' + '\0'(계속)
	//
	//		if (ch == EOF) {
	//
	//			cout << "EOF" << endl;
	//			break;
	//		}
	//
	//		if (ch == '\0') {
	//
	//			cout << "NULL" << endl;
	//			//break;
	//		}
	//
	//	}
	//
	//	fclose(fp);
	//}
	//else {
	//
	//	cout << "파일 open 실패" << endl;
	//}



	//err = fopen_s(&fp, "./Hello3.txt", "rt");
	//
	//if (err == 0) {
	//
	//	cout << "파일 open 성공" << endl;
	//
	//	char str[10];
	//
	//	fgets(str, sizeof(str), fp); // binary 모드 저장, binary 읽기 : '\n' + '\0' 개행으로 문자열의 끝을 판단해서 NULL 문자 넣어줌.
	//								 // text 모드 저장, binary 읽기 : '\r' + '\n' + '\0' 
	//								 // binary 모드 저장, text 읽기 : '\n' + '\0'
	//								 // text 모드 저장, text 읽기 : '\n' + '\0'
	//
	//	fgets(str, sizeof(str), fp); // binary 모드 저장, binary 읽기 : 'b' + 'c' + '\0' + '\0'
	//								 // text 모드 저장, binary 읽기 : 'b' + 'c' + '\0' + '\0'
	//								 // binary 모드 저장, text 읽기 : 'b' + 'c' + '\0' + '\0'
	//								 // text 모드 저장, text 읽기 : 'b' + 'c' + '\0' + '\0'
	//
	//	fclose(fp);
	//}
	//else {
	//
	//	cout << "파일 open 실패" << endl;
	//}



	//err = fopen_s(&fp, "./Hello3.txt", "rt");
	//
	//if (err == 0) {
	//
	//	cout << "파일 open 성공" << endl;
	//
	//	char str[10];
	//
	//	fread(str, sizeof(char), 10, fp); // binary 모드 저장, binary 읽기 : '\n' + 'b' + 'c' + '\0'
	//									  // fputc도 binary 모드 저장 했더니 텍스트 파일에 NULL 문자가 들어가있음.
	//
	//									  // text 모드 저장, binary 읽기 :  '\r' + '\n' + 'b' + 'c' + '\0'
	//
	//									  // binary 모드 저장, text 읽기 : '\n' + 'b' + 'c' + '\0'
	//
	//									  // text 모드 저장, text 읽기 : '\n' + 'b' + 'c' + '\0'
	//
	//	fclose(fp);
	//}
	//else {
	//
	//	cout << "파일 open 실패" << endl;
	//}


	cout << "################################################################" << endl;
	cout << "### case 4. 텍스트 작성(fwrite 문자 단위), 출력모드, 입력모드 변경" << endl;

	//err = fopen_s(&fp, "./Hello4.txt", "wt");

	//if (err == 0) {

	//	cout << "파일 open 성공" << endl;

	//	char str[] = "\nbc";
	//	for (int i = 0; i < sizeof(str) / sizeof(char); i++) {

	//		fwrite(&(str[i]), sizeof(char), 1, fp); // binary 모드 저장 : 이상한 문자('\n') + 쓴 문자들 + 빈 공간 1개 NULL ('\0') !!!!
	//												// text 모드 저장 : 개행되고 + 쓴 문자들 + 빈 공간 1개 NULL ('\0') !!!!
	//	}
	//	fclose(fp);
	//}
	//else {

	//	cout << "파일 open 성공" << endl;
	//}





	//err = fopen_s(&fp, "./Hello4.txt", "rt");
	//
	//if (err == 0) {
	//
	//	cout << "파일 open 성공" << endl;
	//
	//	char ch = 0;
	//
	//	while (1) {
	//
	//		ch = fgetc(fp); // binary 모드 저장, binary 읽기 : '\n' + 'b' + 'c' + '\0' + EOF
	//						// text 모드 저장, binary 읽기 : '\r' + '\n' + 'b' + 'c' + '\0' + EOF
	//						// binary 모드 저장, text 읽기 : '\n' + 'b' + 'c' + '\0' + EOF
	//						// text 모드 저장, text 읽기 : '\n' + 'b' + 'c' + '\0' + EOF
	//		if (ch == EOF) {
	//
	//			cout << "EOF" << endl;
	//			break;
	//		}
	//
	//		if (ch == '\0') {
	//
	//			cout << "NULL" << endl;
	//			//break;
	//		}
	//	}
	//
	//	fclose(fp);
	//
	//	cout << "파일 open 실패" << endl;
	//}



	//err = fopen_s(&fp, "./Hello4.txt", "rt");
	//
	//if (err == 0) {
	//
	//	cout << "파일 open 성공" << endl;
	//
	//	char ch = 0;
	//
	//	while (1) {
	//
	//		fread(&ch, sizeof(char), 1, fp); // binary 모드 저장, binary 읽기 : '\n' + 'b' + 'c' + '\0'(계속)
	//										 // text 모드 저장, binary 읽기 : '\r' + '\n' + 'b' + 'c' + '\0'(계속)
	//										 // binary 모드 저장, text 읽기 : '\n' + 'b' + 'c' + '\0'(계속)
	//										 // text 모드 저장, text 읽기 : '\n' + 'b' + 'c' + '\0'(계속)
	//
	//		if (ch == EOF) {
	//
	//			cout << "EOF" << endl;
	//			break;
	//		}
	//
	//		if (ch == '\0') {
	//
	//			cout << "NULL" << endl;
	//			//break;
	//		}
	//
	//	}
	//
	//	fclose(fp);
	//}
	//else {
	//
	//	cout << "파일 open 실패" << endl;
	//}



	//err = fopen_s(&fp, "./Hello4.txt", "rt");
	//
	//if (err == 0) {
	//
	//	cout << "파일 open 성공" << endl;
	//
	//	char str[10];
	//
	//	fgets(str, sizeof(str), fp); // binary 모드 저장, binary 읽기 : '\n' + '\0' 개행으로 문자열의 끝을 판단해서 NULL 문자 넣어줌.
	//								 // text 모드 저장, binary 읽기 : '\r' + '\n' + '\0' 
	//								 // binary 모드 저장, text 읽기 : '\n' + '\0'
	//								 // text 모드 저장, text 읽기 : '\n' + '\0'
	//
	//	fgets(str, sizeof(str), fp); // binary 모드 저장, binary 읽기 : 'b' + 'c' + '\0' + '\0'
	//								 // text 모드 저장, binary 읽기 : 'b' + 'c' + '\0' + '\0'
	//								 // binary 모드 저장, text 읽기 : 'b' + 'c' + '\0' + '\0'
	//								 // text 모드 저장, text 읽기 : 'b' + 'c' + '\0' + '\0'
	//
	//	fclose(fp);
	//}
	//else {
	//
	//	cout << "파일 open 실패" << endl;
	//}



	//err = fopen_s(&fp, "./Hello4.txt", "rt");
	//
	//if (err == 0) {
	//
	//	cout << "파일 open 성공" << endl;
	//
	//	char str[10];
	//
	//	fread(str, sizeof(char), 10, fp); // binary 모드 저장, binary 읽기 : '\n' + 'b' + 'c' + '\0'
	//									  // fwrite로 binary 모드 저장 했더니 텍스트 파일에 NULL 문자가 들어가있음.
	//
	//									  // text 모드 저장, binary 읽기 :  '\r' + '\n' + 'b' + 'c' + '\0'
	//
	//									  // binary 모드 저장, text 읽기 : '\n' + 'b' + 'c' + '\0'
	//
	//									  // text 모드 저장, text 읽기 : '\n' + 'b' + 'c' + '\0'
	//
	//	fclose(fp);
	//}
	//else {
	//
	//	cout << "파일 open 실패" << endl;
	//}

	cout << "################################################################" << endl;
	cout << "### case 5. 텍스트 작성(메모장), 출력모드, 입력모드 변경" << endl;

	// Enter(개행 한뒤), b + c 입력, NULL 문자 같은건 입력할 수 없었음.

	//err = fopen_s(&fp, "./Hello5.txt", "rb");

	//if (err == 0) {

	//	cout << "파일 open 성공" << endl;

	//	char ch = 0;

	//	while (1) {

	//		ch = fgetc(fp); // 메모장 작성, binary 읽기 : '\r' + '\n' + 'b' + 'c' + EOF
	//						// 메모장 작성, text 읽기 : '\n' + 'b' + 'c' + EOF

	//		if (ch == EOF) {

	//			cout << "EOF" << endl;
	//			break;
	//		}

	//		if (ch == '\0') {

	//			cout << "NULL" << endl;
	//			//break;
	//		}
	//	}

	//	fclose(fp);

	//	cout << "파일 open 실패" << endl;
	//}



	//err = fopen_s(&fp, "./Hello5.txt", "rb");

	//if (err == 0) {

	//	cout << "파일 open 성공" << endl;

	//	char ch = 0;

	//	while (1) {

	//		fread(&ch, sizeof(char), 1, fp); // 메모장 작성, binary 읽기 : '\r' + '\n' + 'b' + 'c'(계속)
	//										 // 메모장 작성, text 읽기 : '\n' + 'b' + 'c'(계속)

	//		if (ch == EOF) {

	//			cout << "EOF" << endl;
	//			break;
	//		}

	//		if (ch == '\0') {

	//			cout << "NULL" << endl;
	//			//break;
	//		}

	//	}

	//	fclose(fp);
	//}
	//else {

	//	cout << "파일 open 실패" << endl;
	//}



	//err = fopen_s(&fp, "./Hello5.txt", "rb");

	//if (err == 0) {

	//	cout << "파일 open 성공" << endl;

	//	char str[10];

	//	fgets(str, sizeof(str), fp); // 메모장 작성, binary 읽기 : '\r' + '\n' + '\0' 개행으로 문자열의 끝을 판단해서 NULL 문자 넣어줌.
	//								 // 메모장 작성, text 읽기 : '\n' + '\0'

	//	fgets(str, sizeof(str), fp); // 메모장 작성, binary 읽기 : 'b' + 'c' + '\0'
	//								 // 메모장 작성, text 읽기 : 'b' + 'c' + '\0'

	//	fclose(fp);
	//}
	//else {

	//	cout << "파일 open 실패" << endl;
	//}



	//err = fopen_s(&fp, "./Hello5.txt", "rb");

	//if (err == 0) {

	//	cout << "파일 open 성공" << endl;

	//	char str[10];

	//	fread(str, sizeof(char), 10, fp); // 메모장 작성, binary 읽기 : '\r' + '\n' + 'b' + 'c'
	//									  // 메모장에서 (Enter + b + c) 저장 했더니 NULL 문자는 입력해준 것이 아니라서 없음.
	//									  // So, 메모리 누수 발생 !!!!

	//									  // 메모장 작성, text 읽기 : '\n' + 'b' + 'c'
	//									  // 입력 해주지도 않은 NULL 문자가 나타날리가 없으니까, 메모리 누수 발생 !!!!

	//	fclose(fp);
	//}
	//else {

	//	cout << "파일 open 실패" << endl;
	//}


	cout << "################################################################" << endl;


	return 0;
}