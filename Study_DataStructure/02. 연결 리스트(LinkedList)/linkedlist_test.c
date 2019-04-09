#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

int main(void) {
	LinkedList *pList = NULL;
	LinkedListNode node;

	pList = createLinkedList();
	if (pList != NULL) {

		node.data = 1;
		addLLElement(pList, 0, node);

		node.data = 3;
		addLLElement(pList, 1, node);

		node.data = 5;
		addLLElement(pList, 2, node);

		displayLinkedList(pList);
		printf("#############################################\n");

		removeLLElement(pList, 0);
		displayLinkedList(pList);

		printf("#############################################\n");
		clearLinkedList(pList);
		displayLinkedList(pList);

		printf("#############################################\n");
		printf("%d \n", pList);
		printf("%d \n", &pList);

		deleteLinkedList(&pList); // delete �ϰ� �� �ڿ� pList�� NULL�� �ƴϴϱ� ����� ������.
		printf("%d \n", pList);
		printf("%d \n", &pList);
		printf("#############################################\n");

		displayLinkedList(pList);



	}

	return 0;
}