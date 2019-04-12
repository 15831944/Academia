/*

####################
    오답 풀이
####################


int *ptr = (int *)malloc(sizeof(int)); // int 형 변수를 메모리 동적 할당하고 포인터 변수로 받았다.
*ptr = 442;

cout << ptr << endl; // 해당 메모리 공간의 주소.
cout << *ptr << endl; // 442 출력

free(ptr); // 메모리 해제.
		   // 그러나, free()도 함수이므로 포인터 변수 ptr이 가지고 있는 주소값이 바뀌길 원했다면,
		   // double pointer(더블 포인터)를 사용 했어야 !!!

cout << ptr << endl; // 결국 가지고 있던 주소를 그대로 출력, Dangling pointer...
cout << *ptr << endl; // 가리키고 있던 메모리 공간의 데이터가 날아감.(쓰레기값)


###################################################################################################

*/


#include <iostream>

using std::cout;
using std::endl;
using std::cin;

int main(void) {

	cout << "###########################################################################" << endl;
	cout << "### 메모리 동적 할당받은 메모리 공간을 가리키는 포인터" << endl << endl;

	int *ptr = (int*)malloc(sizeof(int));
	*ptr = 442;
	cout << ptr << endl;
	cout << *ptr << endl;

	free(ptr);
	cout << ptr << endl; // 그대로 주소값이 나오네... Dangling pointer.
	cout << *ptr << endl; // 포인터가 가리키고 있는 메모리 공간이 날아감.
						  // 주소가 바뀐 것이 아님 !!!!

	cout << "###########################################################################" << endl;


	return 0;
}




