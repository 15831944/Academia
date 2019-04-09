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

			printf("����, �޸� �Ҵ� 1 createArrayList() \n");
			return NULL;
		}

		// ����Ʈ�� ���Ҹ� ������ �迭�� �����Ҵ�.
		pReturn->pElement = (ArrayListNode *)malloc(sizeof(ArrayListNode) * maxElementCount);
		if (pReturn->pElement != NULL) {

			memset(pReturn->pElement, 0, sizeof(ArrayListNode) * maxElementCount); // �迭 �ʱ�ȭ.
		}
		else {

			printf("����, �޸� �Ҵ� 2 createArrayList() \n");
			free(pReturn); // �ݵ�� �޸� ���� �ؾ� ��.
			return NULL;
		}

	}
	else {

		printf("����, ����Ʈ�� ũ��� 1 �̻��̾�� �մϴ�. createArrayList() \n");
		return NULL;
	}

	return pReturn;
}

int addALElement(ArrayList *pList, int position, ArrayListNode element) {

	int ret = FALSE;

	if (pList != NULL) {
		if (isArrayListFull(pList) != TRUE) {
			if (position >= 0 && position <= getArrayListLength(pList)) {

				// �迭�� ����ִ� ������ ���Һ��� �� ĭ�� �ڷ� �̷��.
				for (int i = getArrayListLength(pList) - 1; i >= position; i--) {
					pList->pElement[i + 1] = pList->pElement[i];
				}

				pList->pElement[position] = element; // �ش� ��ġ�� ���ο� ���� �߰�.
				pList->currentElementCount++;

				ret = TRUE;
			}
			else {

				printf("����, �ε��� ���� �ʰ� -[%d] addALElement() \n", position);
			}

		}
		else {
			
			printf("����, ����Ʈ�� �� á���ϴ�. addALElement() \n");
		}
	}
	else {

		printf("����, ����Ʈ�� �����ϴ�. addALElement() \n");
	}

	return ret;
}

int removeALElement(ArrayList *pList, int position) {

	int ret = FALSE;

	if (pList != NULL) {
		if (isArrayListEmpty(pList) != TRUE) {
			if (position >= 0 && position < getArrayListLength(pList)) {

				// �迭�� �ش� ������ ��ġ���� ������ �� ĭ�� ��ܿ´�.
				for (int i = position; i < getArrayListLength(pList) - 1; i++) {
					pList->pElement[i] = pList->pElement[i + 1];
				}

				pList->currentElementCount--; // ���� ������ ������ "1" ���� ���Ѽ� ���� ȿ��.
				
				ret = TRUE;
			}
			else {

				printf("����, �ε��� ���� �ʰ� -[%d] removeALElement() \n", position);
			}

		}
		else {

			printf("����, ����Ʈ�� �����ϴ�. removeALElement() \n");
		}
	}
	else {

		printf("����, ����Ʈ�� �����ϴ�. removeALElement() \n");
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

				printf("����, �ε��� ���� �ʰ� -[%d] removeALElement() \n", position);
			}
		}
		else {

			printf("����, ����Ʈ�� ����ֽ��ϴ�. getALElement() \n");
		}
	}
	else {

		printf("����, ����Ʈ�� �����ϴ�. getALElement() \n");
	}

	return pReturn;
}

void displayArrayList(ArrayList *pList) {

	if (pList != NULL) {

		printf("���� ���� ����: %d \n", getArrayListLength(pList));
		printf("�ִ� ���� ����: %d \n\n", pList->maxElementCount); // �Լ��� ���� �ʿ伺

		for (int i = 0; i < getArrayListLength(pList); i++) {
			// ����, ����Ʈ�� NULL üũ�� ������,
			// for ���� �ε��� ������ �Ѿ�� Runtime ���� �߻� ���� ��ġ.
			printf("[%d] - %d \n", i, getALElement(pList, i)->data);
		}
		printf("\n");
	}
	else {

		printf("����, ����Ʈ�� �����ϴ�. displayArrayList() \n");
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

		printf("����, ����Ʈ�� �����ϴ�. clearArrayList() \n");
	}

	return ret;
}

int deleteArrayList(ArrayList **dpList) {

	int ret = FALSE;

	if (*dpList != NULL) {

		clearArrayList(*dpList);
		free(*dpList);
		(*dpList) = NULL; // ������Ų ����Ʈ�� �����͸� "NULL"�� �ٲٱ� ���ؼ� ���� ������ ���.

		ret = TRUE;
	}
	else {

		printf("����, ����Ʈ�� �����ϴ�. deleteArrayList() \n");
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

		printf("����, ����Ʈ�� �����ϴ�. isArrayListEmpty() \n");
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

		printf("����, ����Ʈ�� �����ϴ�. isArrayListFull() \n");
	}

	return ret;
}

int getArrayListLength(ArrayList *pList) {

	int ret = 0;

	if (pList != NULL) {
		
		ret = pList->currentElementCount;
	}
	else {

		printf("����, ����Ʈ�� �����ϴ�. getArrayListLength() \n");
	}

	return ret;
}
