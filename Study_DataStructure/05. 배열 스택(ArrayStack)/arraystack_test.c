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
		pNode = peekAS(pStack); // ����� �ּҸ� ��ȯ�ϱ� ������ �ٸ� �Լ����� ��忡 ���� ó���� ��� ����� ��.
		if (pNode != NULL) {
			printf("peekAS: %c \n\n", pNode->data); // ������ ���� ������ ��.
		}

		displayArrayStack(pStack);
		printf("############################################\n");
		pNode = popAS(pStack);
		if (pNode != NULL) {
			printf("popAS: %c \n\n", pNode->data); // ���� �� ���� �����
			free(pNode);
			pNode = NULL;
		}

		displayArrayStack(pStack);
		printf("############################################\n");
		clearArrayStack(pStack);

		displayArrayStack(pStack);
		printf("############################################\n");
		printf("%d \n",deleteArrayStack(&pStack)); // �ּ� ���� �Ѱ���� pStack�� NULL�� ���� �� ����.

		displayArrayStack(pStack);

	}



	return 0;
}