#include <stdio.h>
#include "doublylinkedlist.h"

int main(void) {
	DoublyList *pList = NULL;
	DoublyListNode node;

	pList = createDoublyList();
	if (pList != NULL) {

		node.data = 1;
		addDLElement(pList, 0, node);

		node.data = 3;
		addDLElement(pList, 1, node);

		node.data = 5;
		addDLElement(pList, 2, node);

		displayDoublyList(pList);
		printf("#############################################\n");

		removeDLElement(pList, 0);
		displayDoublyList(pList);

		printf("#############################################\n");
		clearDoublyList(pList);
		displayDoublyList(pList);

		printf("#############################################\n");
		printf("%d \n", pList);
		printf("%d \n", &pList);

		deleteDoublyList(&pList); // delete 하고 난 뒤에 pList가 NULL이 아니니까 생기는 문제임.
		printf("%d \n", pList);
		printf("%d \n", &pList);
		printf("#############################################\n");

		displayDoublyList(pList);

	}

	return 0;
}