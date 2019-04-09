#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedlist.h"

LinkedList* createLinkedList() {

	LinkedList *pReturn = NULL;
	pReturn = (LinkedList *)malloc(sizeof(LinkedList));
	if (pReturn != NULL) {

		memset(pReturn, 0, sizeof(LinkedList)); // �ش� �޸��� ��� ��Ʈ�� "0"���� �ʱ�ȭ.
	}
	else {

		printf("����, �޸� �Ҵ� createLinkedList() \n");
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

				printf("����, �޸� �Ҵ� addLLElement() \n");
				return FALSE;
			}

			pPreNode = &(pList->headerNode);
			for (int i = 0; i < position; i++) {

				pPreNode = pPreNode->pLink;
			}

			pNewNode->pLink = pPreNode->pLink; // ��� ���� ����(�ش� ��ġ�� ��,�� ���)
			pPreNode->pLink = pNewNode;

			pList->currentElementCount++;

			ret = TRUE;
		}
		else {

			printf("����, �ε��� ���� �ʰ� -[%d] addLLElement()\n", position);
		}
	}
	else {

		printf("����, ����Ʈ�� �����ϴ�. addLLElement() \n");
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
			pPreNode->pLink = pDelNode->pLink; // ���� ��� �� ��带 ���� ��Ŵ.

			free(pDelNode);

			pList->currentElementCount--;

			ret = TRUE;
		}
		else {

			printf("����, �ε��� ���� �ʰ� -[%d] removeLLElement()\n", position);
		}
	}
	else {

		printf("����, ����Ʈ�� �����ϴ�. removeLLElement() \n");
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

			printf("����, �ε��� ���� �ʰ� -[%d] getLLElement()\n", position);
		}
	}
	else {

		printf("����, ����Ʈ�� �����ϴ�. getLLElement() \n");
	}

	return pReturn;
}

void displayLinkedList(LinkedList *pList) {

	LinkedListNode *pNode = NULL;
	int i = 0;

	if (pList != NULL) {
		
		printf("���� ���� ����: %d \n\n", getLinkedListLength(pList));

		//// case 1. ���� �Լ� �̿��Ͽ� for ������ ��ȸ
		//for (i = 0; i < getLinkedListLength(pList); i++) {
		//	// �ε��� ������ �Ѿ�� ���� �Ѱ��� ��� Runtime ���� �߻�.
		//	printf("[%d] - %d \n", i, getLLElement(pList, i)->data);
		//}
		//printf("\n");

		// case 2. LinkedList�� ������ �̿��� ��ȸ
		i = 0;
		pNode = &(pList->headerNode);
		while (pNode->pLink != NULL) {
			pNode = pNode->pLink; // ��ȸ�ϴ� �κ��� �ڷ� �ű� ����� ����?
			
			printf("[%d] - %d \n", i, pNode->data);
			i++;
		}
		printf("\n");

	}
	else {

		printf("����, ����Ʈ�� �����ϴ�. displayLinkedList() \n");
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

		printf("����, ����Ʈ�� �����ϴ�. clearLinkedList() \n");
	}

	return ret;
}

int deleteLinkedList(LinkedList **dpList) {

	int ret = FALSE;

	if ((*dpList) != NULL) {
		
		clearLinkedList(*dpList);
		free(*dpList);
		(*dpList) = NULL; // ���� ����Ʈ�� ��� �ִ� �����͸� "NULL"�� ����� ���� ���� ������

		ret = TRUE;
	}
	else {

		printf("����, ����Ʈ�� �����ϴ�. deleteLinkedList() \n");
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

		printf("����, ����Ʈ�� �����ϴ�. isLinkedListEmpty() \n");
	}

	return ret;
}

int getLinkedListLength(LinkedList *pList) {

	int ret = 0;

	if (pList != NULL) {

		ret = pList->currentElementCount;
	}
	else {

		printf("����, ����Ʈ�� �����ϴ�. getLinkedListLength() \n");
	}

	return ret;
}
