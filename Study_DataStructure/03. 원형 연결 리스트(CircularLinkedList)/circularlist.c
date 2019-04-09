#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "circularlist.h"


CircularList* createCircularList() {

	CircularList *pReturn = NULL;
	pReturn = (CircularList *)malloc(sizeof(CircularList));
	if (pReturn != NULL) {

		memset(pReturn, 0, sizeof(CircularList));
	}
	else {

		printf("����, �޸� �Ҵ� createCircularList() \n");
	}

	return pReturn;
}

int addCLElement(CircularList *pList, int position, CircularListNode element) {

	int ret = FALSE;
	CircularListNode *pPreNode = NULL, *pNewNode = NULL, *pLastNode = NULL;

	if (pList != NULL) {
		if (position >= 0 && position <= getCircularListLength(pList)) {

			pNewNode = (CircularListNode *)malloc(sizeof(CircularListNode));
			if (pNewNode != NULL) {

				*pNewNode = element;
				pNewNode->pLink = NULL;

			}
			else {

				printf("����, �޸� �Ҵ� addCLElement() \n");
				return FALSE;
			}


			if (position == 0) { // �� ó�� ��忡 �߰��ϴ� ������.
				if (isCircularListEmpty(pList) == TRUE) { // ����Ʈ�� ����ִ� ���¿��� ó�� �߰��ϴ���.

					pList->pHead = pNewNode;
					pNewNode->pLink = pNewNode;
				}
				else {

					pLastNode = pList->pHead; // ������ ��尡 ����Ű�� ��带 �ٲ����.
					while (pLastNode->pLink != pList->pHead) {
						pLastNode = pLastNode->pLink;
					}

					pNewNode->pLink = pLastNode->pLink;
					pLastNode->pLink = pNewNode;
					pList->pHead = pNewNode;
				}
			}
			else { // ����Ʈ �߰��� �߰��ϴ� ���.

				pPreNode = pList->pHead;
				for (int i = 0; i < position - 1; i++) {
					pPreNode = pPreNode->pLink;
				}

				pNewNode->pLink = pPreNode->pLink;
				pPreNode->pLink = pNewNode;
			}

			pList->currentElementCount++;

			ret = TRUE;
		}
		else {

			printf("����, �ε��� ���� �ʰ� -[%d] addCLElement() \n", position);
		}
	}
	else {

		printf("����, ����Ʈ�� �����ϴ�. addCLElement() \n");
	}

	return ret;
}
int removeCLElement(CircularList *pList, int position) {

	int ret = FALSE;
	CircularListNode *pPreNode = NULL, *pDelNode = NULL, *pLastNode = NULL;

	if (pList != NULL) {
		if (isCircularListEmpty(pList) != TRUE) {
			if (position >= 0 && position < getCircularListLength(pList)) {

				if (position == 0) {

					pDelNode = pList->pHead;

					if (getCircularListLength(pList) == 1) {

						pList->pHead = NULL;
					}
					else {

						pLastNode = pList->pHead;
						while (pLastNode->pLink != pList->pHead) {
							pLastNode = pLastNode->pLink;
						}

						pList->pHead = pDelNode->pLink;
						pLastNode->pLink = pDelNode->pLink;
					}
				}
				else {

					pPreNode = pList->pHead;
					for (int i = 0; i < position - 1; i++) {
						pPreNode = pPreNode->pLink;
					}

					pDelNode = pPreNode->pLink;
					pPreNode->pLink = pDelNode->pLink;
				}

				pList->currentElementCount--;

				ret = TRUE;
			}
			else {

				printf("����, �ε��� ���� �ʰ� -[%d] removeCLElement() \n", position);
			}
		}
		else {

			printf("����, ����Ʈ�� ����ֽ��ϴ�. removeCLElement() \n");
		}
	}
	else {

		printf("����, ����Ʈ�� �����ϴ�. removeCLElement() \n");
	}

	return ret;
}

CircularListNode* getCLElement(CircularList *pList, int position) {

	CircularListNode *pReturn = NULL;

	if (pList != NULL) {
		if (isCircularListEmpty(pList) != TRUE) {
			if (position >= 0 && position < getCircularListLength(pList)) {

				pReturn = pList->pHead;
				for (int i = 0; i < position; i++) {
					pReturn = pReturn->pLink;
				}
			}
			else {

				printf("����, �ε��� ���� �ʰ� -[%d] getCLElement() \n", position);
			}
		}
		else {

			printf("����, ����Ʈ�� ����ֽ��ϴ�. getCLElement() \n");
		}
	}
	else {

		printf("����, ����Ʈ�� �����ϴ�. getCLElement() \n");
	}

	return pReturn;
}

void displayCircularList(CircularList *pList) {

	int i = 0;
	CircularListNode *pNode = NULL;

	if (pList != NULL) {

		printf("���� ���� ����: %d \n\n", getCircularListLength(pList));

		// case 1. for ���� �̿��� ��ȸ
		for (i = 0; i < getCircularListLength(pList); i++) {
			// �ε��� ���� �Ѿ������ Runtime ���� �߻� ���ɼ�.
			printf("[%d] - %d \n", i, getCLElement(pList, i)->data);
		}
		printf("\n");

		//// case 2. ���� ����Ʈ�� ������ �̿��� ��ȸ
		//i = 0;
		//pNode = pList->pHead;
		//
		//// �������� 3.
		//
		// 1 3 5 1
		// ����Ʈ�� �������� �������� ��� �� �� ������.
		// ������ ����� pLink�� pHead�� ����Ŵ.
		// pNode->pLink != pList->pHead �� ������ ������ ��� -1 ��° ����..
		// pNode->pLink != pList->pHead->pLink �̰� ��ȸ�ϴ� pNode�� pHead�� �Ǹ� ���߰�..
		// - �׷��� ó���� pHead���� �����ϱ� ������ ����.
		// while �����δ� "���� ���� 2."ó�� �ϴ� ����ۿ� ���� �� ����.


		//// �������� 2.
		//
		//if (pNode != NULL) {
		//
		//	while (1) { // ���ǿ� ��ȸ�ϴ� �ڵ尡 �־����� ������.
		//		printf("[%d] - %d \n", i, pNode->data);
		//
		//		pNode = pNode->pLink;
		//		i++;
		//
		//		if (pNode == pList->pHead)
		//			break;
		//	}
		//	printf("\n");
		//}


		//// ���� ���� 1.
		//
		// pHead�� NULL�̸� pLink�� ��� ���� ������ �ȵ�.
		//if (pList->pHead != NULL) {
		//
		//	do { // while ������ �ϴ� ����� ����?
		//
		//		printf("[%d] - %d \n", i, pNode->data);
		//
		//		pNode = pNode->pLink;
		//		i++;
		//	} while (pNode->pLink != pList->pHead->pLink);
		//	printf("\n");
		//}

	}
	else {

		printf("����, ����Ʈ�� �����ϴ�. displayCircularList() \n");
	}

}

int clearCircularList(CircularList *pList) {

	int ret = FALSE;

	if (pList != NULL) {

		while (isCircularListEmpty(pList) != TRUE) {

			removeCLElement(pList, 0);
		}

		ret = TRUE;
	}
	else {

		printf("����, ����Ʈ�� �����ϴ�. clearCircularList() \n");
	}

	return ret;
}

int deleteCircularList(CircularList **dpList) {

	int ret = FALSE;

	if ((*dpList) != NULL) {

		clearCircularList(*dpList);
		free(*dpList);
		(*dpList) = NULL; // ����Ʈ�� ����Ű�� �����͸� "NULL"�� �ʱ�ȭ ��Ű���� ���� ������

		ret = TRUE;
	}
	else {

		printf("����, ����Ʈ�� �����ϴ�. deleteCircularList() \n");
	}

	return ret;
}

int isCircularListEmpty(CircularList *pList) {

	int ret = FALSE;

	if (pList != NULL) {
		if (pList->currentElementCount == 0) {

			ret = TRUE;
		}
	}
	else {

		printf("����, ����Ʈ�� �����ϴ�. isCircularListEmpty() \n");
	}

	return ret;
}

int getCircularListLength(CircularList *pList) {

	int ret = FALSE;

	if (pList != NULL) {

		ret = pList->currentElementCount;
	}
	else {

		printf("����, ����Ʈ�� �����ϴ�. getCircularListLength() \n");
	}

	return ret;
}