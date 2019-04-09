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

		printf("오류, 메모리 할당 createCircularList() \n");
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

				printf("오류, 메모리 할당 addCLElement() \n");
				return FALSE;
			}


			if (position == 0) { // 맨 처음 노드에 추가하는 것인지.
				if (isCircularListEmpty(pList) == TRUE) { // 리스트가 비어있는 상태에서 처음 추가하는지.

					pList->pHead = pNewNode;
					pNewNode->pLink = pNewNode;
				}
				else {

					pLastNode = pList->pHead; // 마지막 노드가 가리키는 노드를 바꿔야함.
					while (pLastNode->pLink != pList->pHead) {
						pLastNode = pLastNode->pLink;
					}

					pNewNode->pLink = pLastNode->pLink;
					pLastNode->pLink = pNewNode;
					pList->pHead = pNewNode;
				}
			}
			else { // 리스트 중간에 추가하는 경우.

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

			printf("오류, 인덱스 범위 초과 -[%d] addCLElement() \n", position);
		}
	}
	else {

		printf("오류, 리스트가 없습니다. addCLElement() \n");
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

				printf("오류, 인덱스 범위 초과 -[%d] removeCLElement() \n", position);
			}
		}
		else {

			printf("오류, 리스트가 비어있습니다. removeCLElement() \n");
		}
	}
	else {

		printf("오류, 리스트가 없습니다. removeCLElement() \n");
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

				printf("오류, 인덱스 범위 초과 -[%d] getCLElement() \n", position);
			}
		}
		else {

			printf("오류, 리스트가 비어있습니다. getCLElement() \n");
		}
	}
	else {

		printf("오류, 리스트가 없습니다. getCLElement() \n");
	}

	return pReturn;
}

void displayCircularList(CircularList *pList) {

	int i = 0;
	CircularListNode *pNode = NULL;

	if (pList != NULL) {

		printf("현재 원소 개수: %d \n\n", getCircularListLength(pList));

		// case 1. for 문을 이용한 순회
		for (i = 0; i < getCircularListLength(pList); i++) {
			// 인덱스 범위 넘어버리면 Runtime 오류 발생 가능성.
			printf("[%d] - %d \n", i, getCLElement(pList, i)->data);
		}
		printf("\n");

		//// case 2. 연결 리스트의 성질을 이용한 순회
		//i = 0;
		//pNode = pList->pHead;
		//
		//// 시행착오 3.
		//
		// 1 3 5 1
		// 리스트의 마지막을 조건으로 어떻게 알 수 있을까.
		// 마지막 노드의 pLink는 pHead를 가리킴.
		// pNode->pLink != pList->pHead 이 조건은 마지막 노드 -1 번째 까지..
		// pNode->pLink != pList->pHead->pLink 이건 순회하다 pNode가 pHead가 되면 멈추게..
		// - 그런데 처음은 pHead부터 시작하기 때문에 실패.
		// while 문으로는 "시행 착오 2."처럼 하는 방법밖에 없을 것 같음.


		//// 시행착오 2.
		//
		//if (pNode != NULL) {
		//
		//	while (1) { // 조건에 순회하는 코드가 있었으면 좋겠음.
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


		//// 시행 착오 1.
		//
		// pHead가 NULL이면 pLink가 없어서 연산 수행이 안됨.
		//if (pList->pHead != NULL) {
		//
		//	do { // while 문으로 하는 방법은 없나?
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

		printf("오류, 리스트가 없습니다. displayCircularList() \n");
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

		printf("오류, 리스트가 없습니다. clearCircularList() \n");
	}

	return ret;
}

int deleteCircularList(CircularList **dpList) {

	int ret = FALSE;

	if ((*dpList) != NULL) {

		clearCircularList(*dpList);
		free(*dpList);
		(*dpList) = NULL; // 리스트를 가리키는 포인터를 "NULL"로 초기화 시키려고 더블 포인터

		ret = TRUE;
	}
	else {

		printf("오류, 리스트가 없습니다. deleteCircularList() \n");
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

		printf("오류, 리스트가 없습니다. isCircularListEmpty() \n");
	}

	return ret;
}

int getCircularListLength(CircularList *pList) {

	int ret = FALSE;

	if (pList != NULL) {

		ret = pList->currentElementCount;
	}
	else {

		printf("오류, 리스트가 없습니다. getCircularListLength() \n");
	}

	return ret;
}