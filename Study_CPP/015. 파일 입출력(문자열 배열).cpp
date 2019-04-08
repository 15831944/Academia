#include <iostream>

using std::cout;
using std::endl;

int main(void) {

	cout << "################################################################" << endl;
	cout << "### case 1. �ؽ�Ʈ �ۼ�(fputs ���ڿ�), ��¸��, �Է¸�� ����" << endl;

	FILE *fp = nullptr;
	errno_t err = fopen_s(&fp, "./Hello1.txt", "wt"); // binary ���� ���� �̻��� ���� + �� ���ڵ�, NULL ���� ����.
													  // text ���� ���� ���� �ǰ� + �� ���ڵ�, NULL ���� ����.

	if (err == 0) {

		cout << "���� open ����" << endl;

		char str[] = "\nbc"; // '\n' + 'b' + 'c' + '\0' 4��
		fputs(str, fp); // �̻��� ����('\n') + b + c, �׷��� NULL ���ڴ� ��� �ȵǼ� �ؽ�Ʈ ���Ͽ� ���� !!!!
						// binary ��忡���� NULL ���ڴ� ��� �� �ϳ��� !!!!

		fclose(fp);
	}
	else {

		cout << "���� open ����" << endl;
	}



	//err = fopen_s(&fp, "./Hello1.txt", "rt");
	//
	//if (err == 0) {
	//
	//	cout << "���� open ����" << endl;
	//
	//	char ch = 0;
	//
	//	while (1) {
	//
	//		ch = fgetc(fp); // binary ��� ����, binary �б� : '\n' + 'b' + 'c' + EOF
	//						// text ��� ����, binary �б� : '\r' + '\n' + 'b' + 'c' + EOF
	//						// binary ��� ����, text �б� : '\n' +  'b' + 'c' + EOF
	//						// text ��� ����, text �б� : '\n' +  'b' + 'c' + EOF
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
	//	cout << "���� open ����" << endl;
	//}



	//err = fopen_s(&fp, "./Hello1.txt", "rt");
	//
	//if (err == 0) {
	//
	//	cout << "���� open ����" << endl;
	//
	//	char ch = 0;
	//
	//	while (1) {
	//
	//		fread(&ch, sizeof(char), 1, fp); // binary ��� ����, binary �б� : '\n' + 'b' + 'c'(���)
	//										// text ��� ����, binary �б� : '\r' + '\n' + 'b' + 'c'(���)
	//										// binary ��� ����, text �б� : '\n' + 'b' + 'c'(���)
	//										// text ��� ����, text �б� : '\n' + 'b' + 'c'(���)
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
	//	cout << "���� open ����" << endl;
	//}



	//err = fopen_s(&fp, "./Hello1.txt", "rt");
	//
	//if (err == 0) {
	//
	//	cout << "���� open ����" << endl;
	//
	//	char str[10];
	//
	//	fgets(str, sizeof(str), fp); // binary ��� ����, binary �б� : '\n' + '\0' ������ ������ ���ڿ��� ���� �ɷ� �����ؼ� NULL ���� �ٿ��ְ� �о� ������...
	//								// text ��� ����, binary �б� : '\r' + '\n' + '\0' �������� ���ڿ��� ���� �Ǵ��ؼ� NULL ���� �־���.
	//								// binary ��� ����, text �б� : '\n' + '\0'
	//								// text ��� ����, text �б� : '\n' + '\0'
	//
	//	fgets(str, sizeof(str), fp); // binary ��� ����, binary �б� : 'b' + 'c' + '\0'
	//								// text ��� ����, binary �б� : 'b' + 'c' + '\0'
	//								// binary ��� ����, text �б� : 'b' + 'c' + '\0'
	//								// text ��� ����, text �б� : 'b' + 'c' + '\0'
	//
	//	fclose(fp);
	//}
	//else {
	//
	//	cout << "���� open ����" << endl;
	//}



	//err = fopen_s(&fp, "./Hello1.txt", "rt");
	//
	//if (err == 0) {
	//
	//	cout << "���� open ����" << endl;
	//
	//	char str[10];
	//
	//	fread(str, sizeof(char), 10, fp); // binary ��� ����, binary �б� : '\n' + 'b' + 'c'
	//									  // �ؽ�Ʈ ���Ͽ� NULL ���ڰ� ��� �����͸� �� �о���ϱ�
	//									  // ���ڿ� ���� NULL ���ڰ� ��� �޸� ���� ���� !!!!
	//
	//									  // text ��� ����, binary �б� :  '\r' + '\n' + 'b' + 'c'
	//									  // ���������� NULL ���ڰ� ��� �޸� ������ ���� !!!!
	//
	//									  // binary ��� ����, text �б� : '\n' + 'b' + 'c'
	//									  // NULL ���� ��� �޸� ���� !!!!
	//
	//									  // text ��� ����, text �б� : '\n' + 'b' + 'c'
	//									  // NULL ���� ��� �޸� ���� !!!!
	//
	//	fclose(fp);
	//}
	//else {
	//
	//	cout << "���� open ����" << endl;
	//}


	cout << "################################################################" << endl;
	cout << "### case 2. �ؽ�Ʈ �ۼ�(fwrite ���ڿ�), ��¸��, �Է¸�� ����" << endl;

	err = fopen_s(&fp, "./Hello2.txt", "wt");

	if (err == 0) {

		cout << "���� open ����" << endl;

		char str[] = "\nbc";
		fwrite(str, sizeof(str) / sizeof(char), 1, fp); // binary ��� ���� : �̻��� ����('\n') + �� ���ڵ� + �� ���� 1�� NULL ('\0') !!!!
														// text ��� ���� : ����ǰ� + �� ���ڵ� + �� ���� 1�� null ('\0') !!!!
		fclose(fp);
	}
	else {

		cout << "���� open ����" << endl;
	}




	//err = fopen_s(&fp, "./Hello2.txt", "rt");
	//
	//if (err == 0) {
	//
	//	cout << "���� open ����" << endl;
	//
	//	char ch = 0;
	//
	//	while (1) {
	//
	//		ch = fgetc(fp); // binary ��� ����, binary �б� : '\n' + 'b' + 'c' + '\0' + EOF
	//						// text ��� ����, binary �б� : '\r' + '\n' + 'b' + 'c' + '\0' + EOF
	//						// binary ��� ����, text �б� : '\n' + 'b' + 'c' + '\0' + EOF
	//						// text ��� ����, text �б� : '\n' + 'b' + 'c' + '\0' + EOF
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
	//	cout << "���� open ����" << endl;
	//}



	//err = fopen_s(&fp, "./Hello2.txt", "rt");
	//
	//if (err == 0) {
	//
	//	cout << "���� open ����" << endl;
	//
	//	char ch = 0;
	//
	//	while (1) {
	//
	//		fread(&ch, sizeof(char), 1, fp); // binary ��� ����, binary �б� : '\n' + 'b' + 'c' + '\0'(���)
	//										 // text ��� ����, binary �б� : '\r' + '\n' + 'b' + 'c' + '\0'(���)
	//										 // binary ��� ����, text �б� : '\n' + 'b' + 'c' + '\0'(���)
	//										 // text ��� ����, text �б� : '\n' + 'b' + 'c' + '\0'(���)
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
	//	cout << "���� open ����" << endl;
	//}



	//err = fopen_s(&fp, "./Hello2.txt", "rt");
	//
	//if (err == 0) {
	//
	//	cout << "���� open ����" << endl;
	//
	//	char str[10];
	//
	//	fgets(str, sizeof(str), fp); // binary ��� ����, binary �б� : '\n' + '\0' �������� ���ڿ��� ���� �Ǵ��ؼ� NULL ���� �־���.
	//								 // text ��� ����, binary �б� : '\r' + '\n' + '\0' 
	//								 // binary ��� ����, text �б� : '\n' + '\0'
	//								 // text ��� ����, text �б� : '\n' + '\0'
	//
	//	fgets(str, sizeof(str), fp); // binary ��� ����, binary �б� : 'b' + 'c' + '\0' + '\0'
	//								 // text ��� ����, binary �б� : 'b' + 'c' + '\0' + '\0'
	//								 // binary ��� ����, text �б� : 'b' + 'c' + '\0' + '\0'
	//								 // text ��� ����, text �б� : 'b' + 'c' + '\0' + '\0'
	//
	//	fclose(fp);
	//}
	//else {
	//
	//	cout << "���� open ����" << endl;
	//}



	//err = fopen_s(&fp, "./Hello2.txt", "rt");
	//
	//if (err == 0) {
	//
	//	cout << "���� open ����" << endl;
	//
	//	char str[10];
	//
	//	fread(str, sizeof(char), 10, fp); // binary ��� ����, binary �б� : '\n' + 'b' + 'c' + '\0'
	//									  // fwrite�� binary ��� ���� �ߴ��� �ؽ�Ʈ ���Ͽ� NULL ���ڰ� ������.
	//
	//									  // text ��� ����, binary �б� :  '\r' + '\n' + 'b' + 'c' + '\0'
	//
	//									  // binary ��� ����, text �б� : '\n' + 'b' + 'c' + '\0'
	//
	//									  // text ��� ����, text �б� : '\n' + 'b' + 'c' + '\0'
	//
	//	fclose(fp);
	//}
	//else {
	//
	//	cout << "���� open ����" << endl;
	//}



	cout << "################################################################" << endl;
	cout << "### case 3. �ؽ�Ʈ �ۼ�(fputc ���� ����), ��¸��, �Է¸�� ����" << endl;

	err = fopen_s(&fp, "./Hello3.txt", "wt");

	if (err == 0) {

		cout << "���� open ����" << endl;

		char str[] = "\nbc"; // '\n' + 'b' + 'c' + '\0' 4��

		for (int i = 0; i < sizeof(str) / sizeof(char); i++) {

			char ch = str[i];
			fputc(ch, fp); // binary ��� ���� : �̻��� ����('\n') + b + c + �� ���� 1�� NULL ('\0') ���� !!!!
						   // text ��� ���� : ����ǰ�, b + c + �� ���� 1�� NULL ('\0') ���� !!!!
		}


		fclose(fp);
	}
	else {

		cout << "���� open ����" << endl;
	}



	//err = fopen_s(&fp, "./Hello3.txt", "rt");
	//
	//if (err == 0) {
	//
	//	cout << "���� open ����" << endl;
	//
	//	char ch = 0;
	//
	//	while (1) {
	//
	//		ch = fgetc(fp); // binary ��� ����, binary �б� : '\n' + 'b' + 'c' + '\0' + EOF
	//						// text ��� ����, binary �б� : '\r' + '\n' + 'b' + 'c' + '\0' + EOF
	//						// binary ��� ����, text �б� : '\n' + 'b' + 'c' + '\0' + EOF
	//						// text ��� ����, text �б� : '\n' + 'b' + 'c' + '\0' + EOF
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
	//	cout << "���� open ����" << endl;
	//}



	//err = fopen_s(&fp, "./Hello3.txt", "rt");
	//
	//if (err == 0) {
	//
	//	cout << "���� open ����" << endl;
	//
	//	char ch = 0;
	//
	//	while (1) {
	//
	//		fread(&ch, sizeof(char), 1, fp); // binary ��� ����, binary �б� : '\n' + 'b' + 'c' + '\0'(���)
	//										 // text ��� ����, binary �б� : '\r' + '\n' + 'b' + 'c' + '\0'(���)
	//										 // binary ��� ����, text �б� : '\n' + 'b' + 'c' + '\0'(���)
	//										 // text ��� ����, text �б� : '\n' + 'b' + 'c' + '\0'(���)
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
	//	cout << "���� open ����" << endl;
	//}



	//err = fopen_s(&fp, "./Hello3.txt", "rt");
	//
	//if (err == 0) {
	//
	//	cout << "���� open ����" << endl;
	//
	//	char str[10];
	//
	//	fgets(str, sizeof(str), fp); // binary ��� ����, binary �б� : '\n' + '\0' �������� ���ڿ��� ���� �Ǵ��ؼ� NULL ���� �־���.
	//								 // text ��� ����, binary �б� : '\r' + '\n' + '\0' 
	//								 // binary ��� ����, text �б� : '\n' + '\0'
	//								 // text ��� ����, text �б� : '\n' + '\0'
	//
	//	fgets(str, sizeof(str), fp); // binary ��� ����, binary �б� : 'b' + 'c' + '\0' + '\0'
	//								 // text ��� ����, binary �б� : 'b' + 'c' + '\0' + '\0'
	//								 // binary ��� ����, text �б� : 'b' + 'c' + '\0' + '\0'
	//								 // text ��� ����, text �б� : 'b' + 'c' + '\0' + '\0'
	//
	//	fclose(fp);
	//}
	//else {
	//
	//	cout << "���� open ����" << endl;
	//}



	//err = fopen_s(&fp, "./Hello3.txt", "rt");
	//
	//if (err == 0) {
	//
	//	cout << "���� open ����" << endl;
	//
	//	char str[10];
	//
	//	fread(str, sizeof(char), 10, fp); // binary ��� ����, binary �б� : '\n' + 'b' + 'c' + '\0'
	//									  // fputc�� binary ��� ���� �ߴ��� �ؽ�Ʈ ���Ͽ� NULL ���ڰ� ������.
	//
	//									  // text ��� ����, binary �б� :  '\r' + '\n' + 'b' + 'c' + '\0'
	//
	//									  // binary ��� ����, text �б� : '\n' + 'b' + 'c' + '\0'
	//
	//									  // text ��� ����, text �б� : '\n' + 'b' + 'c' + '\0'
	//
	//	fclose(fp);
	//}
	//else {
	//
	//	cout << "���� open ����" << endl;
	//}


	cout << "################################################################" << endl;
	cout << "### case 4. �ؽ�Ʈ �ۼ�(fwrite ���� ����), ��¸��, �Է¸�� ����" << endl;

	//err = fopen_s(&fp, "./Hello4.txt", "wt");

	//if (err == 0) {

	//	cout << "���� open ����" << endl;

	//	char str[] = "\nbc";
	//	for (int i = 0; i < sizeof(str) / sizeof(char); i++) {

	//		fwrite(&(str[i]), sizeof(char), 1, fp); // binary ��� ���� : �̻��� ����('\n') + �� ���ڵ� + �� ���� 1�� NULL ('\0') !!!!
	//												// text ��� ���� : ����ǰ� + �� ���ڵ� + �� ���� 1�� NULL ('\0') !!!!
	//	}
	//	fclose(fp);
	//}
	//else {

	//	cout << "���� open ����" << endl;
	//}





	//err = fopen_s(&fp, "./Hello4.txt", "rt");
	//
	//if (err == 0) {
	//
	//	cout << "���� open ����" << endl;
	//
	//	char ch = 0;
	//
	//	while (1) {
	//
	//		ch = fgetc(fp); // binary ��� ����, binary �б� : '\n' + 'b' + 'c' + '\0' + EOF
	//						// text ��� ����, binary �б� : '\r' + '\n' + 'b' + 'c' + '\0' + EOF
	//						// binary ��� ����, text �б� : '\n' + 'b' + 'c' + '\0' + EOF
	//						// text ��� ����, text �б� : '\n' + 'b' + 'c' + '\0' + EOF
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
	//	cout << "���� open ����" << endl;
	//}



	//err = fopen_s(&fp, "./Hello4.txt", "rt");
	//
	//if (err == 0) {
	//
	//	cout << "���� open ����" << endl;
	//
	//	char ch = 0;
	//
	//	while (1) {
	//
	//		fread(&ch, sizeof(char), 1, fp); // binary ��� ����, binary �б� : '\n' + 'b' + 'c' + '\0'(���)
	//										 // text ��� ����, binary �б� : '\r' + '\n' + 'b' + 'c' + '\0'(���)
	//										 // binary ��� ����, text �б� : '\n' + 'b' + 'c' + '\0'(���)
	//										 // text ��� ����, text �б� : '\n' + 'b' + 'c' + '\0'(���)
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
	//	cout << "���� open ����" << endl;
	//}



	//err = fopen_s(&fp, "./Hello4.txt", "rt");
	//
	//if (err == 0) {
	//
	//	cout << "���� open ����" << endl;
	//
	//	char str[10];
	//
	//	fgets(str, sizeof(str), fp); // binary ��� ����, binary �б� : '\n' + '\0' �������� ���ڿ��� ���� �Ǵ��ؼ� NULL ���� �־���.
	//								 // text ��� ����, binary �б� : '\r' + '\n' + '\0' 
	//								 // binary ��� ����, text �б� : '\n' + '\0'
	//								 // text ��� ����, text �б� : '\n' + '\0'
	//
	//	fgets(str, sizeof(str), fp); // binary ��� ����, binary �б� : 'b' + 'c' + '\0' + '\0'
	//								 // text ��� ����, binary �б� : 'b' + 'c' + '\0' + '\0'
	//								 // binary ��� ����, text �б� : 'b' + 'c' + '\0' + '\0'
	//								 // text ��� ����, text �б� : 'b' + 'c' + '\0' + '\0'
	//
	//	fclose(fp);
	//}
	//else {
	//
	//	cout << "���� open ����" << endl;
	//}



	//err = fopen_s(&fp, "./Hello4.txt", "rt");
	//
	//if (err == 0) {
	//
	//	cout << "���� open ����" << endl;
	//
	//	char str[10];
	//
	//	fread(str, sizeof(char), 10, fp); // binary ��� ����, binary �б� : '\n' + 'b' + 'c' + '\0'
	//									  // fwrite�� binary ��� ���� �ߴ��� �ؽ�Ʈ ���Ͽ� NULL ���ڰ� ������.
	//
	//									  // text ��� ����, binary �б� :  '\r' + '\n' + 'b' + 'c' + '\0'
	//
	//									  // binary ��� ����, text �б� : '\n' + 'b' + 'c' + '\0'
	//
	//									  // text ��� ����, text �б� : '\n' + 'b' + 'c' + '\0'
	//
	//	fclose(fp);
	//}
	//else {
	//
	//	cout << "���� open ����" << endl;
	//}

	cout << "################################################################" << endl;
	cout << "### case 5. �ؽ�Ʈ �ۼ�(�޸���), ��¸��, �Է¸�� ����" << endl;

	// Enter(���� �ѵ�), b + c �Է�, NULL ���� ������ �Է��� �� ������.

	//err = fopen_s(&fp, "./Hello5.txt", "rb");

	//if (err == 0) {

	//	cout << "���� open ����" << endl;

	//	char ch = 0;

	//	while (1) {

	//		ch = fgetc(fp); // �޸��� �ۼ�, binary �б� : '\r' + '\n' + 'b' + 'c' + EOF
	//						// �޸��� �ۼ�, text �б� : '\n' + 'b' + 'c' + EOF

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

	//	cout << "���� open ����" << endl;
	//}



	//err = fopen_s(&fp, "./Hello5.txt", "rb");

	//if (err == 0) {

	//	cout << "���� open ����" << endl;

	//	char ch = 0;

	//	while (1) {

	//		fread(&ch, sizeof(char), 1, fp); // �޸��� �ۼ�, binary �б� : '\r' + '\n' + 'b' + 'c'(���)
	//										 // �޸��� �ۼ�, text �б� : '\n' + 'b' + 'c'(���)

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

	//	cout << "���� open ����" << endl;
	//}



	//err = fopen_s(&fp, "./Hello5.txt", "rb");

	//if (err == 0) {

	//	cout << "���� open ����" << endl;

	//	char str[10];

	//	fgets(str, sizeof(str), fp); // �޸��� �ۼ�, binary �б� : '\r' + '\n' + '\0' �������� ���ڿ��� ���� �Ǵ��ؼ� NULL ���� �־���.
	//								 // �޸��� �ۼ�, text �б� : '\n' + '\0'

	//	fgets(str, sizeof(str), fp); // �޸��� �ۼ�, binary �б� : 'b' + 'c' + '\0'
	//								 // �޸��� �ۼ�, text �б� : 'b' + 'c' + '\0'

	//	fclose(fp);
	//}
	//else {

	//	cout << "���� open ����" << endl;
	//}



	//err = fopen_s(&fp, "./Hello5.txt", "rb");

	//if (err == 0) {

	//	cout << "���� open ����" << endl;

	//	char str[10];

	//	fread(str, sizeof(char), 10, fp); // �޸��� �ۼ�, binary �б� : '\r' + '\n' + 'b' + 'c'
	//									  // �޸��忡�� (Enter + b + c) ���� �ߴ��� NULL ���ڴ� �Է����� ���� �ƴ϶� ����.
	//									  // So, �޸� ���� �߻� !!!!

	//									  // �޸��� �ۼ�, text �б� : '\n' + 'b' + 'c'
	//									  // �Է� �������� ���� NULL ���ڰ� ��Ÿ������ �����ϱ�, �޸� ���� �߻� !!!!

	//	fclose(fp);
	//}
	//else {

	//	cout << "���� open ����" << endl;
	//}


	cout << "################################################################" << endl;


	return 0;
}