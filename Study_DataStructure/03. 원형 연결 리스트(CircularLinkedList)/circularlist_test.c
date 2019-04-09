#include <stdio.h>
#include <stdlib.h>
#include "circularlist.h"

int main(void) {
	CircularList *pList = NULL;
	CircularListNode node;

	pList = createCircularList();
	if (pList != NULL) {

		node.data = 1;
		addCLElement(pList, 0, node);

		node.data = 3;
		addCLElement(pList, 1, node);

		node.data = 5;
		addCLElement(pList, 2, node);

		displayCircularList(pList);
		printf("#############################################\n");

		removeCLElement(pList, 0);
		displayCircularList(pList);

		printf("#############################################\n");
		clearCircularList(pList);
		displayCircularList(pList);

		printf("#############################################\n");
		printf("%d \n", pList);
		printf("%d \n", &pList);

		deleteCircularList(&pList); // delete 하고 난 뒤에 pList가 NULL이 아니니까 생기는 문제임.
		printf("%d \n", pList);
		printf("%d \n", &pList);
		printf("#############################################\n");

		displayCircularList(pList);

	}

	return 0;
}