#include <stdio.h>
#include <stdlib.h>
#include "arraylist.h"

int main(int argc, char *argv[]) {
	int i = 0;
	int arrayCount = 0;
	ArrayList *pList = NULL;
	ArrayListNode *pNode = NULL;

	pList = createArrayList(6);

	if (pList != NULL) {
		ArrayListNode node;

		// 리스트 초기화: 1, 3, 5 추가.
		node.data = 1;
		addALElement(pList, 0, node);

		node.data = 3;
		addALElement(pList, 1, node);

		node.data = 5;
		addALElement(pList, 2, node);

		displayArrayList(pList);

		printf("#########################\n");
		// 첫번째 원소 제거.
		removeALElement(pList, 0);
		displayArrayList(pList);

		printf("#########################\n");
		arrayCount = getArrayListLength(pList);
		for (i = 0; i < arrayCount; i++) {
			pNode = getALElement(pList, i);
			printf("위치[%d] - %d\n", i, pNode->data);
		}

		deleteArrayList(&pList);

	}

	return 0;
}