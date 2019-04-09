#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arraystack.h"

ArrayStack* createArrayStack(int maxElementCount) {

	ArrayStack *pReturn = NULL;

	if (maxElementCount > 0) {

		pReturn = (ArrayStack *)malloc(sizeof(ArrayStack));
		if (pReturn != NULL) {

			pReturn->currentElementCount = 0;
			pReturn->maxElementCount = maxElementCount;
			pReturn->pElement = NULL;
		}
		else {

			printf("����, �޸� �Ҵ� 1 createArrayStack() \n");
			return NULL;
		}

		pReturn->pElement = (ArrayStackNode *)malloc(sizeof(ArrayStackNode) * maxElementCount);
		if (pReturn->pElement != NULL) {

			memset(pReturn->pElement, 0, sizeof(ArrayStackNode) * maxElementCount);
		}
		else {

			printf("����, �޸� �Ҵ� 2 createArrayStack() \n");
			free(pReturn);
			return NULL;
		}

	}
	else {

		printf("����, ������ ũ��� 1 �̻��̾�� �մϴ�. -[%d] createArrayStack() \n", maxElementCount);
	}

	return pReturn;
}

int pushAS(ArrayStack *pStack, ArrayStackNode element) {

	int ret = FALSE;

	if (pStack != NULL) {
		if (isArrayStackFull(pStack) != TRUE) {
			
			pStack->pElement[getArrayStackLength(pStack)] = element;
			pStack->currentElementCount++;

			ret = TRUE;
		}
		else {

			printf("����, ������ �� á���ϴ�. pushAS() \n");
		}
	}
	else {

		printf("����, ������ �����ϴ�. pushAS() \n");
	}

	return ret;
}
ArrayStackNode* popAS(ArrayStack *pStack) {

	ArrayStackNode *pReturn = NULL;

	if (pStack != NULL) {
		if (isArrayStackEmpty(pStack) != TRUE) {

			pReturn = (ArrayStackNode *)malloc(sizeof(ArrayStackNode));
			if (pReturn != NULL) {

				*pReturn = pStack->pElement[getArrayStackLength(pStack) - 1];
				
				pStack->currentElementCount--;
			}
			else {

				printf("����, �޸� �Ҵ� popAS() \n");
			}
			
		}
		else {

			printf("����, ������ ����ֽ��ϴ�. popAS() \n");
		}
	}
	else {

		printf("����, ������ �����ϴ�. popAS() \n");
	}

	return pReturn;
}
ArrayStackNode* peekAS(ArrayStack *pStack) {

	ArrayStackNode *pReturn = NULL;

	if (pStack != NULL) {
		if (isArrayStackEmpty(pStack) != TRUE) {

			pReturn = &(pStack->pElement[getArrayStackLength(pStack) - 1]);
		}
		else {

			printf("����, ������ ����ֽ��ϴ�. peekAS() \n");
		}
	}
	else {

		printf("����, ������ �����ϴ�. peekAS() \n");
	}

	return pReturn;
}

void displayArrayStack(ArrayStack *pStack) {

	if (pStack != NULL) {

		printf("���� ���� ����: %d \n\n", getArrayStackLength(pStack));

		// ����� ��, pop�ϰ� �ٸ� �����ٰ� �����ߴٰ�  
		// �ٽ� �������� �־��ִ� �׷� ����� ��...
		for (int i = getArrayStackLength(pStack) - 1; i >= 0; i--) {
			printf("[%d] - %c \n", i, pStack->pElement[i].data);
		}
		printf("\n");
	}
	else {

		printf("����, ������ �����ϴ�. displayArrayStack() \n");
	}
}

int clearArrayStack(ArrayStack *pStack) {

	int ret = FALSE;
	ArrayStackNode *pNode = NULL;

	if (pStack != NULL) {
		
		while (isArrayStackEmpty(pStack) != TRUE) {

			pNode = popAS(pStack);
			free(pNode);
		}

		ret = TRUE;
	}
	else {

		printf("����, ������ �����ϴ�. clearArrayStack() \n");
	}

	return ret;
}

int deleteArrayStack(ArrayStack **dpStack) {

	int ret = FALSE;

	if ((*dpStack) != NULL) {

		clearArrayStack(*dpStack);
		free(*dpStack);
		(*dpStack) = NULL; // ������ ����Ű�� �����͸� "NULL"�� ������ֱ� ���ؼ� ���� ������

		ret = TRUE;
	}
	else {

		printf("����, ������ �����ϴ�. deleteArrayStack() \n");
	}

	return ret;
}

int isArrayStackEmpty(ArrayStack *pStack) {

	int ret = FALSE;

	if (pStack != NULL) {
		if (pStack->currentElementCount == 0) {

			ret = TRUE;
		}
	}
	else {

		printf("����, ������ �����ϴ�. isArrayStackEmpty() \n");
	}

	return ret;
}

int isArrayStackFull(ArrayStack *pStack) {

	int ret = FALSE;

	if (pStack != NULL) {
		if (pStack->currentElementCount == pStack->maxElementCount) {

			ret = TRUE;
		}
	}
	else {

		printf("����, ������ �����ϴ�. isArrayStackFull() \n");
	}

	return ret;
}

int getArrayStackLength(ArrayStack *pStack) {

	int ret = 0;

	if (pStack != NULL) {

		ret = pStack->currentElementCount;
	}
	else {

		printf("����, ������ �����ϴ�. getArrayStackLength() \n");
	}

	return ret;
}