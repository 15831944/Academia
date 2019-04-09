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

		printf("����, �޸� �Ҵ� createDoublyList() \n");
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

				printf("����, �޸� �Ҵ� addDLElement() \n");
			}
		}
		else {

			printf("����, �ε��� ���� �ʰ� -[%d] addDLElement() \n", position);
		}
	}
	else {

		printf("����, ����Ʈ�� �����ϴ�. addDLElement() \n");
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

				printf("����, �ε��� ���� �ʰ� -[%d] removeDLElement() \n", position);
			}
		}
		else {

			printf("����, ����Ʈ�� ����ֽ��ϴ�. removeDLElement() \n");
		}
	}
	else {

		printf("����, ����Ʈ�� �����ϴ�. removeDLElement() \n");
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

		printf("����, ����Ʈ�� �����ϴ�. clearDoublyList() \n");
	}

	return ret;
}

int deleteDoublyList(DoublyList **dpList) {

	int ret = FALSE;

	if ((*dpList) != NULL) {
		clearDoublyList(*dpList);
		free(*dpList);
		*dpList = NULL; // ����Ʈ�� ����Ű�� �����͸� "NULL"�� ����� ���ؼ� ���� ������

		ret = TRUE;
	}
	else {

		printf("����, ����Ʈ�� �����ϴ�. deleteDoublyList() \n");
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

			printf("����, �ε��� ���� �ʰ� -[%d] getDLElement() \n", position);
		}
	}
	else {

		printf("����, ����Ʈ�� �����ϴ�. getDLElement() \n");
	}

	return pReturn;
}

void displayDoublyList(DoublyList *pList) {

	if (pList != NULL) {

		printf("���� ���� ����: %d \n", pList->currentElementCount);

		for (int i = 0; i < pList->currentElementCount; i++) {
			printf("[%d] - %d \n", i, getDLElement(pList, i)->data);
		}
		
		// CircularList�� �ƴϹǷ�, while������ �����ϸ� ��.
		// ������ -> �߰��Ǵ� ��� -> NULL ������� �ϸ�...
		// ������ pNode->pRLink != NULL
	}
	else {

		printf("����, ����Ʈ�� �����ϴ�. displayDoublyList() \n");
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

		printf("����, ����Ʈ�� �����ϴ�. isDoublyListEmpty() \n");
	}

	return ret;
}

int getDoublyListLength(DoublyList *pList) {

	int ret = 0;

	if (pList != NULL) {

		ret = pList->currentElementCount;
	}
	else {

		printf("����, ����Ʈ�� �����ϴ�. displayDoublyList() \n");
	}

	return ret;
}
