#include <stdio.h>
#include "arraystack.h"

int main(void) {

	ArrayStack *pStack = NULL;
	ArrayStackNode node;
	ArrayStackNode *pNode = NULL;

	pStack = createArrayStack(5);
	if (pStack != NULL) {
		node.data = 'A';
		pushAS(pStack, node);

		node.data = 'B';
		pushAS(pStack, node);

		node.data = 'C';
		pushAS(pStack, node);

		displayArrayStack(pStack);
		printf("############################################\n");
		pNode = peekAS(pStack); // 노드의 주소를 반환하기 때문에 다른 함수에서 노드에 대한 처리를 대신 해줘야 함.
		if (pNode != NULL) {
			printf("peekAS: %c \n\n", pNode->data); // 원소의 값을 참조만 함.
		}

		displayArrayStack(pStack);
		printf("############################################\n");
		pNode = popAS(pStack);
		if (pNode != NULL) {
			printf("popAS: %c \n\n", pNode->data); // 원소 한 개가 사라짐
			free(pNode);
			pNode = NULL;
		}

		displayArrayStack(pStack);
		printf("############################################\n");
		clearArrayStack(pStack);

		displayArrayStack(pStack);
		printf("############################################\n");
		printf("%d \n",deleteArrayStack(&pStack)); // 주소 값을 넘겨줘야 pStack을 NULL로 만들 수 있음.

		displayArrayStack(pStack);

	}



	return 0;
}