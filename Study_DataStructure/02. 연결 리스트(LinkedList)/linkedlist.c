#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedlist.h"

LinkedList* createLinkedList() {

	LinkedList *pReturn = NULL;
	pReturn = (LinkedList *)malloc(sizeof(LinkedList));
	if (pReturn != NULL) {

		memset(pReturn, 0, sizeof(LinkedList)); // 해당 메모리의 모든 비트를 "0"으로 초기화.
	}
	else {

		printf("오류, 메모리 할당 createLinkedList() \n");
	}


	return pReturn;
}

int addLLElement(LinkedList *pList, int position, LinkedListNode element) {

	int ret = FALSE;
	LinkedListNode *pPreNode = NULL, *pNewNode = NULL;

	if (pList != NULL) {
		if (position >= 0 && position <= getLinkedListLength(pList)) {

			pNewNode = (LinkedListNode *)malloc(sizeof(LinkedListNode));
			if (pNewNode != NULL) {

				*pNewNode = element;
				pNewNode->pLink = NULL;

				
			}
			else {

				printf("오류, 메모리 할당 addLLElement() \n");
				return FALSE;
			}

			pPreNode = &(pList->headerNode);
			for (int i = 0; i < position; i++) {

				pPreNode = pPreNode->pLink;
			}

			pNewNode->pLink = pPreNode->pLink; // 노드 연결 과정(해당 위치의 앞,뒤 노드)
			pPreNode->pLink = pNewNode;

			pList->currentElementCount++;

			ret = TRUE;
		}
		else {

			printf("오류, 인덱스 범위 초과 -[%d] addLLElement()\n", position);
		}
	}
	else {

		printf("오류, 리스트가 없습니다. addLLElement() \n");
	}

	return ret;
}

int removeLLElement(LinkedList *pList, int position) {

	int ret = FALSE;
	LinkedListNode *pPreNode = NULL, *pDelNode = NULL;

	if (pList != NULL) {
		if (position >= 0 && position < getLinkedListLength(pList)) {

			pPreNode = &(pList->headerNode);
			for (int i = 0; i < position; i++) {

				pPreNode = pPreNode->pLink;
			}

			pDelNode = pPreNode->pLink;
			pPreNode->pLink = pDelNode->pLink; // 지울 노드 앞 노드를 연결 시킴.

			free(pDelNode);

			pList->currentElementCount--;

			ret = TRUE;
		}
		else {

			printf("오류, 인덱스 범위 초과 -[%d] removeLLElement()\n", position);
		}
	}
	else {

		printf("오류, 리스트가 없습니다. removeLLElement() \n");
	}

	return ret;
}

LinkedListNode* getLLElement(LinkedList *pList, int position) {

	LinkedListNode *pReturn = NULL;

	if (pList != NULL) {
		if (position >= 0 && position < getLinkedListLength(pList)) {

			pReturn = &(pList->headerNode);
			for (int i = 0; i < position; i++) {

				pReturn = pReturn->pLink;
			}
		}
		else {

			printf("오류, 인덱스 범위 초과 -[%d] getLLElement()\n", position);
		}
	}
	else {

		printf("오류, 리스트가 없습니다. getLLElement() \n");
	}

	return pReturn;
}

void displayLinkedList(LinkedList *pList) {

	LinkedListNode *pNode = NULL;
	int i = 0;

	if (pList != NULL) {
		
		printf("현재 원소 개수: %d \n\n", getLinkedListLength(pList));

		//// case 1. 기존 함수 이용하여 for 문으로 순회
		//for (i = 0; i < getLinkedListLength(pList); i++) {
		//	// 인덱스 범위를 넘어가는 값을 넘겨줄 경우 Runtime 오류 발생.
		//	printf("[%d] - %d \n", i, getLLElement(pList, i)->data);
		//}
		//printf("\n");

		// case 2. LinkedList의 성질을 이용한 순회
		i = 0;
		pNode = &(pList->headerNode);
		while (pNode->pLink != NULL) {
			pNode = pNode->pLink; // 순회하는 부분을 뒤로 옮길 방법은 없나?
			
			printf("[%d] - %d \n", i, pNode->data);
			i++;
		}
		printf("\n");

	}
	else {

		printf("오류, 리스트가 없습니다. displayLinkedList() \n");
	}

}

int clearLinkedList(LinkedList *pList) {

	int ret = FALSE;

	if (pList != NULL) {

		while (isLinkedListEmpty(pList) != TRUE) {

			removeLLElement(pList, 0);
		}

		ret = TRUE;
	}
	else {

		printf("오류, 리스트가 없습니다. clearLinkedList() \n");
	}

	return ret;
}

int deleteLinkedList(LinkedList **dpList) {

	int ret = FALSE;

	if ((*dpList) != NULL) {
		
		clearLinkedList(*dpList);
		free(*dpList);
		(*dpList) = NULL; // 연결 리스트를 담고 있는 포인터를 "NULL"로 만들기 위해 더블 포인터

		ret = TRUE;
	}
	else {

		printf("오류, 리스트가 없습니다. deleteLinkedList() \n");
	}

	return ret;
}

int isLinkedListEmpty(LinkedList * pList) {

	int ret = FALSE;

	if (pList != NULL) {
		if (pList->currentElementCount == 0) {

			ret = TRUE;
		}
	}
	else {

		printf("오류, 리스트가 없습니다. isLinkedListEmpty() \n");
	}

	return ret;
}

int getLinkedListLength(LinkedList *pList) {

	int ret = 0;

	if (pList != NULL) {

		ret = pList->currentElementCount;
	}
	else {

		printf("오류, 리스트가 없습니다. getLinkedListLength() \n");
	}

	return ret;
}
