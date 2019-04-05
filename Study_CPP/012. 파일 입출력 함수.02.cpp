/*

2019.04.05.01 ��


###########################
    ���� ����� �Լ�.02
###########################

case 1. fseek()

- ���� �������� ��ġ�� ������ �� �ִ� �Լ�
(���� ���� ���� ������ �տ� ��ġ�ϰ� �ִ� !!!!!)

int fseek(FILE *_Stream, long _Offset, int _Origin);

�Ű����� FILE *_Stream : ��� ������ ��Ʈ��
�Ű����� long _Offset : ���� �����ڸ� �̵� ��ų byte �� (����� ����_������, ������ ����_����)
�Ű����� int _Origin : ������� ���� �������� ��ġ
                      (SEEK_SET ������ ����, SEEK_CUR ���� �������� ���� ��ġ, SEEK_END ������ ��)
��ȯ�� int : ���� �������� ��ġ�� �ű�µ� �����ϸ� "0", �����ϸ� "0"�� �ƴ� ��.


case 2. ftell()

- ���� �������� ���� ��ġ�� �˷��ִ� �Լ�
- ù ���� ��ġ�� "0"���� ������.

long ftell(FILE *_Stream);

�Ű����� FILE *_Stream : �۾��� ������ ��Ʈ���� FILE ����ü�� ������
��ȯ�� long : ���� �������� ���� ��ġ�� ��ȯ. (������ ������ "0"�� �ǹ��Ѵ�.)


case 3. feof()

- ���� �����ڰ� EOF(End Of File)�� ���� �ߴ��� �˻��ϴ� �Լ�.
- ���� ������ "0"�� �ƴ� ���� ��ȯ
  "0"�̸� ������ �а� �ִ� ���� !!!!

int feof(FILE *_Stream);

FILE *_Stream : �۾��� ������ ��Ʈ���� FILE ����ü�� ������
��ȯ�� int : ������ ���� ���� ������ "0"�� �ƴ� ���� ��ȯ, "0"�̸� ������ �а� �ִ� �� !!!!

while (feof(fp3) == 0) {
	int ch = fgetc(fp3);
	fputc(ch, stdout); // ���� ���� ����̶� �ƽ�Ű �ڵ� ���� ���� ���� !!!!
}
// ��� "1234567890 " ��ĭ�� ��� �Ǿ���???
// ��¥ ������ �� �� �� Ȯ���ϴ� �������� ����ϴ� ����.
// �׸���, Windows������ ������ "\r\n"���� ����ϴϱ� ���� 2���� ����.

- �� �� �� EOF�� �´��� Ȯ���Ѵ� !!!!
(������ ������ ���� ������� ������ ������, ���������� ������ ������ Ȯ���ϱ� ���ؼ�...)

because, EOF�� ������ "0"�� ��ȯ�ϱ� ������... �Ѿ�� �ٸ� �� ��ȯ�ؼ� ���� !!!!


#########################################################################################################


*/

#include <iostream>

using std::cout;
using std::endl;

int main(void) {

	cout << "###############################################################################" << endl;
	cout << "### ���� ����� �Լ�.02 " << endl << endl;

	FILE *fp = nullptr;
	errno_t err = fopen_s(&fp, "test.txt", "rb"); // 1234567890 �Է��ؼ� Source �ؽ�Ʈ ���� �� !!!!

	if (err == 0) { // ���� ���� ����

		cout << "Hello test.txt" << endl << endl;

		int ch = 0;

		// ��1234567890

		// ���� �����ڰ� ���� ��ġ���� �ڷ�(���_������) 2 bytes �̵�
		// 12 �� 34567890
		fseek(fp, 2, SEEK_SET);
		ch = fgetc(fp);
		fputc(ch, stdout); // "3" ����� �Ǵϱ� ���� �������� ��ġ�� "2"�� "3" ���� !!!!
		fseek(fp, -1, SEEK_CUR);

		cout << endl;

		// ���� �����ڰ� ���� ��ġ���� �ڷ�(���_������) 2 bytes �̵�
		// 1234 �� 567890
		fseek(fp, 2, SEEK_CUR);
		ch = fgetc(fp);
		fputc(ch, stdout); // "5" ����� �Ǵϱ� ���� �������� ��ġ�� "4"�� "5" ���� !!!!
		fseek(fp, -1, SEEK_CUR);

		cout << endl;
		
		// ���� �����ڰ� ������ �� ��ġ���� ������(����_����) 2 bytes �̵�
		// 12345678 �� 90
		fseek(fp, -2, SEEK_END);
		ch = fgetc(fp);
		fputc(ch, stdout); // "9" ����� �Ǵϱ� ���� �������� ��ġ�� "8"�� "9" ���� !!!!
		fseek(fp, -1, SEEK_CUR);

		cout << endl;

		fclose(fp);

	}
	else {

		cout << "���� ���� ����" << endl;
	}

	cout << "###############################################################################" << endl;
	cout << "### ���� �������� ���� ��ġ - ftell()" << endl << endl;

	FILE *fp2 = nullptr;
	errno_t err2 = fopen_s(&fp2, "test.txt", "rb");

	if (err2 == 0) { // ���� ���� ����

		// 12 �� 34567890
		fseek(fp2, 2, SEEK_SET);

		// 123 4567890
		int ch = fgetc(fp2);

		// So, ó�� "0"���� �����ؼ�, 2 bytes �̵��ϰ�, �Ѱ��� ���ڸ� ��������� - 3 ���.
		cout << "���� �������� ��ġ: " << ftell(fp2) << endl;

		fclose(fp2);
	}
	else {

		cout << "���� ���� ����" << endl;
	}

	cout << "###############################################################################" << endl;
	cout << "### ������ ���� �����ߴ��� Ȯ�� - feof()" << endl << endl;

	FILE *fp3 = nullptr;
	errno_t err3 = fopen_s(&fp3, "test.txt", "rb");
	int count = 0;

	if (err3 == 0) { // ���� ���� ����

		while (feof(fp3) == 0) { // ������ �а� �ִ� ���̸�...

			int ch = fgetc(fp3);
			fputc(ch, stdout);

			count++; // "Enter"�� Windows�� �׷��� \r\n���� �ν��ϴ� �� ����.

		}
		
		// ��� "1234567890 " ��ĭ�� 1�� ��� �Ǿ���???
		// ��¥ ������ �� �� �� Ȯ���ϴ� �������� ����ϴ� ����.
		cout << "count1 : " << count << endl;


		fseek(fp3, 0, SEEK_SET);
		count = 0;

		while (1) {

			int ch = fgetc(fp3);

			if (feof(fp3) != 0) { // �Է��� �ް� �ٷ� �˻縦 �ؼ� �ݺ����� ���������� ���ϴ� ����� ����.

				break;
			}

			fputc(ch, stdout);
			if (ch == '6') { // ���� ���ڷ� �־���� �ϳ�...
				fputs("Hello", stdout);
			}
			if (ch == EOF) {
				fputs("World", stdout);
			}

			count++; // "Enter"�� Windows�� �׷��� \r\n���� �ν��ϴ� �� ����.
		}

		cout << "count2 : " << count << endl;

		fclose(fp3);
	}
	else {

		cout << "���� ���� ����" << endl;
	}

	cout << "###############################################################################" << endl;
	cout << "### �̹��� ���� ���̳ʸ� ����" << endl << endl;

	FILE *fInput = nullptr;
	FILE *fOutput = nullptr;

	errno_t errInput = fopen_s(&fInput, "./devcat.png", "rb");
	
	if (errInput == 0) {

		errno_t errOutput = fopen_s(&fOutput, "./copy.png", "wb");
		if (errOutput == 0) {

			// case 1. ���� �迭�� ����.... fseek()�� �̿��� ���
			// - ������ ���� ftell()�� �� Bytes �о����, �޸� ���� �Ҵ��� �� �ڿ� ���� ����.

		/*	fseek(fInput, 0, SEEK_END);
			int size = ftell(fInput);

			fseek(fInput, 0, SEEK_SET);

			char *ptr = new char[size];
			fread(ptr, sizeof(char) * size, 1, fInput);
			fwrite(ptr, sizeof(char) * size, 1, fOutput);*/


			// case 2. feof()�� �̿��ϴ� ���
			while (feof(fInput) == 0) { // �Ʊ� feof()�� ����Ʈ �� ���� �� �ִٴ� �� !!!!
				char ch = 0;
				fread(&ch, sizeof(char), 1, fInput);
				fwrite(&ch, sizeof(char), 1, fOutput);
			}


			cout << "���� ���� ����" << endl;

			fclose(fOutput);

		}
		else {

		}

		fclose(fInput);
	}

	cout << "###############################################################################" << endl;

	return 0;
}