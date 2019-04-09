#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "doublylinkedlist.h"

DoublyList* createDoublyList() {

	DoublyList *pReturn = NULL;

	pReturn = (DoublyList *)malloc(sizeof(DoublyList));
	if (pReturn != NULL) {

		memset(pReturn, 0, sizeof(DoublyList));

		pReturn->headerNode.pLLink = &(pReturn->headerNode);
		pReturn->headerNode.pRLink = &(pReturn->headerNode);
	}
	else {

		printf("오류, 메모리 할당 createDoublyList() \n");
	}

	return pReturn;
}

int addDLElement(DoublyList *pList, int position, DoublyListNode element) {

	int ret = FALSE;
	int i;
	DoublyListNode *pPreNode = NULL, *pNewNode = NULL;

	if (pList != NULL) {
		if (position >= 0 && position <= pList->currentElementCount) {

			pNewNode = (DoublyListNode *)malloc(sizeof(DoublyListNode));
			if (pNewNode != NULL) {

				*pNewNode = element;
				pNewNode->pLLink = NULL;
				pNewNode->pRLink = NULL;

				pPreNode = &(pList->headerNode);
				for (i = 0; i < position; i++) {
					pPreNode = pPreNode->pRLink;
				}

				pNewNode->pLLink = pPreNode;
				pNewNode->pRLink = pPreNode->pRLink;
				pPreNode->pRLink->pLLink = pNewNode;
				pPreNode->pRLink = pNewNode;

				pList->currentElementCount++;

				ret = TRUE;
			}
			else {

				printf("오류, 메모리 할당 addDLElement() \n");
			}
		}
		else {

			printf("오류, 인덱스 범위 초과 -[%d] addDLElement() \n", position);
		}
	}
	else {

		printf("오류, 리스트가 없습니다. addDLElement() \n");
	}

	return ret;
}

int removeDLElement(DoublyList *pList, int position) {

	int ret = FALSE;
	int i;
	DoublyListNode *pPreNode = NULL, *pDelNode = NULL;

	if (pList != NULL) {
		if (isDoublyListEmpty(pList) != TRUE) {
			if (position >= 0 && position < pList->currentElementCount) {

				pPreNode = &(pList->headerNode);
				for (i = 0; i < position; i++) {
					pPreNode = pPreNode->pRLink;
				}

				pDelNode = pPreNode->pRLink;

				pDelNode->pRLink->pLLink = pPreNode;
				pPreNode->pRLink = pDelNode->pRLink;

				free(pDelNode);
				pList->currentElementCount--;

				ret = TRUE;
			}
			else {

				printf("오류, 인덱스 범위 초과 -[%d] removeDLElement() \n", position);
			}
		}
		else {

			printf("오류, 리스트가 비어있습니다. removeDLElement() \n");
		}
	}
	else {

		printf("오류, 리스트가 없습니다. removeDLElement() \n");
	}

	return ret;
}

int clearDoublyList(DoublyList *pList) {

	int ret = FALSE;

	if (pList != NULL) {

		while (pList->currentElementCount != 0) {

			removeDLElement(pList, 0);
		}

		ret = TRUE;
	}
	else {

		printf("오류, 리스트가 없습니다. clearDoublyList() \n");
	}

	return ret;
}

int deleteDoublyList(DoublyList **dpList) {

	int ret = FALSE;

	if ((*dpList) != NULL) {
		clearDoublyList(*dpList);
		free(*dpList);
		*dpList = NULL; // 리스트를 가리키는 포인터를 "NULL"로 만들기 위해서 더블 포인터

		ret = TRUE;
	}
	else {

		printf("오류, 리스트가 없습니다. deleteDoublyList() \n");
	}

	return ret;
}

DoublyListNode* getDLElement(DoublyList *pList, int position)
{
	DoublyListNode *pReturn = NULL;

	if (pList != NULL) {
		if (position >= 0 && position < pList->currentElementCount) {

			pReturn = &(pList->headerNode);
			for (int i = 0; i <= position; i++) {

				pReturn = pReturn->pRLink;
			}
		}
		else {

			printf("오류, 인덱스 범위 초과 -[%d] getDLElement() \n", position);
		}
	}
	else {

		printf("오류, 리스트가 없습니다. getDLElement() \n");
	}

	return pReturn;
}

void displayDoublyList(DoublyList *pList) {

	if (pList != NULL) {

		printf("현재 원소 개수: %d \n", pList->currentElementCount);

		for (int i = 0; i < pList->currentElementCount; i++) {
			printf("[%d] - %d \n", i, getDLElement(pList, i)->data);
		}
		
		// CircularList가 아니므로, while문으로 구현하면 됨.
		// 헤더노드 -> 추가되는 노드 -> NULL 순서라고 하면...
		// 조건은 pNode->pRLink != NULL
	}
	else {

		printf("오류, 리스트가 없습니다. displayDoublyList() \n");
	}
}

int isDoublyListEmpty(DoublyList *pList) {

	int ret = FALSE;

	if (pList != NULL) {
		if (pList->currentElementCount == 0) {

			ret = TRUE;
		}
	}
	else {

		printf("오류, 리스트가 없습니다. isDoublyListEmpty() \n");
	}

	return ret;
}

int getDoublyListLength(DoublyList *pList) {

	int ret = 0;

	if (pList != NULL) {

		ret = pList->currentElementCount;
	}
	else {

		printf("오류, 리스트가 없습니다. displayDoublyList() \n");
	}

	return ret;
}
