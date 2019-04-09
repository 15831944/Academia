#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arraylist.h"


ArrayList* createArrayList(int maxElementCount) {

	ArrayList *pReturn = NULL;

	if (maxElementCount > 0) {

		pReturn = (ArrayList *)malloc(sizeof(ArrayList));
		if (pReturn != NULL) {

			pReturn->currentElementCount = 0;
			pReturn->maxElementCount = maxElementCount;
			pReturn->pElement = NULL;
		}
		else {

			printf("오류, 메모리 할당 1 createArrayList() \n");
			return NULL;
		}

		// 리스트의 원소를 저장할 배열을 동적할당.
		pReturn->pElement = (ArrayListNode *)malloc(sizeof(ArrayListNode) * maxElementCount);
		if (pReturn->pElement != NULL) {

			memset(pReturn->pElement, 0, sizeof(ArrayListNode) * maxElementCount); // 배열 초기화.
		}
		else {

			printf("오류, 메모리 할당 2 createArrayList() \n");
			free(pReturn); // 반드시 메모리 해제 해야 함.
			return NULL;
		}

	}
	else {

		printf("오류, 리스트의 크기는 1 이상이어야 합니다. createArrayList() \n");
		return NULL;
	}

	return pReturn;
}

int addALElement(ArrayList *pList, int position, ArrayListNode element) {

	int ret = FALSE;

	if (pList != NULL) {
		if (isArrayListFull(pList) != TRUE) {
			if (position >= 0 && position <= getArrayListLength(pList)) {

				// 배열에 들어있는 마지막 원소부터 한 칸씩 뒤로 미룬다.
				for (int i = getArrayListLength(pList) - 1; i >= position; i--) {
					pList->pElement[i + 1] = pList->pElement[i];
				}

				pList->pElement[position] = element; // 해당 위치에 새로운 원소 추가.
				pList->currentElementCount++;

				ret = TRUE;
			}
			else {

				printf("오류, 인덱스 범위 초과 -[%d] addALElement() \n", position);
			}

		}
		else {
			
			printf("오류, 리스트가 꽉 찼습니다. addALElement() \n");
		}
	}
	else {

		printf("오류, 리스트가 없습니다. addALElement() \n");
	}

	return ret;
}

int removeALElement(ArrayList *pList, int position) {

	int ret = FALSE;

	if (pList != NULL) {
		if (isArrayListEmpty(pList) != TRUE) {
			if (position >= 0 && position < getArrayListLength(pList)) {

				// 배열의 해당 원소의 위치부터 앞으로 한 칸씩 당겨온다.
				for (int i = position; i < getArrayListLength(pList) - 1; i++) {
					pList->pElement[i] = pList->pElement[i + 1];
				}

				pList->currentElementCount--; // 현재 원소의 개수를 "1" 감소 시켜서 지운 효과.
				
				ret = TRUE;
			}
			else {

				printf("오류, 인덱스 범위 초과 -[%d] removeALElement() \n", position);
			}

		}
		else {

			printf("오류, 리스트가 비어습니다. removeALElement() \n");
		}
	}
	else {

		printf("오류, 리스트가 없습니다. removeALElement() \n");
	}

	return ret;
}

ArrayListNode* getALElement(ArrayList *pList, int position) {

	ArrayListNode *pReturn = NULL;

	if (pList != NULL) {
		if (isArrayListEmpty != TRUE) {
			if (position >= 0 && position < getArrayListLength(pList)) {
				
				pReturn = &(pList->pElement[position]);
			}
			else {

				printf("오류, 인덱스 범위 초과 -[%d] removeALElement() \n", position);
			}
		}
		else {

			printf("오류, 리스트가 비어있습니다. getALElement() \n");
		}
	}
	else {

		printf("오류, 리스트가 없습니다. getALElement() \n");
	}

	return pReturn;
}

void displayArrayList(ArrayList *pList) {

	if (pList != NULL) {

		printf("현재 원소 개수: %d \n", getArrayListLength(pList));
		printf("최대 원소 개수: %d \n\n", pList->maxElementCount); // 함수를 만들 필요성

		for (int i = 0; i < getArrayListLength(pList); i++) {
			// 물론, 리스트의 NULL 체크를 하지만,
			// for 문이 인덱스 범위가 넘어가면 Runtime 오류 발생 가능 위치.
			printf("[%d] - %d \n", i, getALElement(pList, i)->data);
		}
		printf("\n");
	}
	else {

		printf("오류, 리스트가 없습니다. displayArrayList() \n");
	}
}

int clearArrayList(ArrayList *pList) {

	int ret = FALSE;

	if (pList != NULL) {

		while (isArrayListEmpty(pList) != TRUE) {

			removeALElement(pList, 0);
		}

		ret = TRUE;
	}
	else {

		printf("오류, 리스트가 없습니다. clearArrayList() \n");
	}

	return ret;
}

int deleteArrayList(ArrayList **dpList) {

	int ret = FALSE;

	if (*dpList != NULL) {

		clearArrayList(*dpList);
		free(*dpList);
		(*dpList) = NULL; // 삭제시킨 리스트의 포인터를 "NULL"로 바꾸기 위해서 더블 포인터 사용.

		ret = TRUE;
	}
	else {

		printf("오류, 리스트가 없습니다. deleteArrayList() \n");
	}

	return ret;
}

int isArrayListEmpty(ArrayList *pList) {

	int ret = FALSE;

	if (pList != NULL) {
		if (pList->currentElementCount == 0) {

			ret = TRUE;
		}
	}
	else {

		printf("오류, 리스트가 없습니다. isArrayListEmpty() \n");
	}

	return ret;
}

int isArrayListFull(ArrayList *pList) {

	int ret = FALSE;

	if (pList != NULL) {
		if (pList->currentElementCount == pList->maxElementCount) {

			ret = TRUE;
		}
	}
	else {

		printf("오류, 리스트가 없습니다. isArrayListFull() \n");
	}

	return ret;
}

int getArrayListLength(ArrayList *pList) {

	int ret = 0;

	if (pList != NULL) {
		
		ret = pList->currentElementCount;
	}
	else {

		printf("오류, 리스트가 없습니다. getArrayListLength() \n");
	}

	return ret;
}
