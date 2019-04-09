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

			printf("오류, 메모리 할당 1 createArrayStack() \n");
			return NULL;
		}

		pReturn->pElement = (ArrayStackNode *)malloc(sizeof(ArrayStackNode) * maxElementCount);
		if (pReturn->pElement != NULL) {

			memset(pReturn->pElement, 0, sizeof(ArrayStackNode) * maxElementCount);
		}
		else {

			printf("오류, 메모리 할당 2 createArrayStack() \n");
			free(pReturn);
			return NULL;
		}

	}
	else {

		printf("오류, 스택의 크기는 1 이상이어야 합니다. -[%d] createArrayStack() \n", maxElementCount);
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

			printf("오류, 스택이 꽉 찼습니다. pushAS() \n");
		}
	}
	else {

		printf("오류, 스택이 없습니다. pushAS() \n");
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

				printf("오류, 메모리 할당 popAS() \n");
			}
			
		}
		else {

			printf("오류, 스택이 비어있습니다. popAS() \n");
		}
	}
	else {

		printf("오류, 스택이 없습니다. popAS() \n");
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

			printf("오류, 스택이 비어있습니다. peekAS() \n");
		}
	}
	else {

		printf("오류, 스택이 없습니다. peekAS() \n");
	}

	return pReturn;
}

void displayArrayStack(ArrayStack *pStack) {

	if (pStack != NULL) {

		printf("현재 원소 개수: %d \n\n", getArrayStackLength(pStack));

		// 출력할 때, pop하고 다른 곳에다가 보관했다가  
		// 다시 역순으로 넣어주는 그런 방법은 좀...
		for (int i = getArrayStackLength(pStack) - 1; i >= 0; i--) {
			printf("[%d] - %c \n", i, pStack->pElement[i].data);
		}
		printf("\n");
	}
	else {

		printf("오류, 스택이 없습니다. displayArrayStack() \n");
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

		printf("오류, 스택이 없습니다. clearArrayStack() \n");
	}

	return ret;
}

int deleteArrayStack(ArrayStack **dpStack) {

	int ret = FALSE;

	if ((*dpStack) != NULL) {

		clearArrayStack(*dpStack);
		free(*dpStack);
		(*dpStack) = NULL; // 스택을 가리키는 포인터를 "NULL"로 만들어주기 위해서 더블 포인터

		ret = TRUE;
	}
	else {

		printf("오류, 스택이 없습니다. deleteArrayStack() \n");
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

		printf("오류, 스택이 없습니다. isArrayStackEmpty() \n");
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

		printf("오류, 스택이 없습니다. isArrayStackFull() \n");
	}

	return ret;
}

int getArrayStackLength(ArrayStack *pStack) {

	int ret = 0;

	if (pStack != NULL) {

		ret = pStack->currentElementCount;
	}
	else {

		printf("오류, 스택이 없습니다. getArrayStackLength() \n");
	}

	return ret;
}