#ifndef _LINKED_LIST_
#define _LINKED_LIST_

typedef struct LinkedListNodeType {

	int data;
	struct LinkedListNodeType *pLink; // ���� ��ũ�� �ּҸ� ���� ������
} LinkedListNode;

typedef struct LinkedListType {
	
	int currentElementCount;
	LinkedListNode headerNode; // ��� �����Ͱ� �ƴ� ��� ���(���� ���)
} LinkedList;


LinkedList* createLinkedList();

int addLLElement(LinkedList *pList, int position, LinkedListNode element);
int removeLLElement(LinkedList *pList, int position);

LinkedListNode* getLLElement(LinkedList *pList, int position);

void displayLinkedList(LinkedList *pList);

int clearLinkedList(LinkedList *pList);
int deleteLinkedList(LinkedList **dpList);

int isLinkedListEmpty(LinkedList *pList);

int getLinkedListLength(LinkedList *pList);

#endif


#ifndef _COMMON_LIST_DEF_
#define _COMMON_LIST_DEF_

#define TRUE 1
#define FALSE 0

#endif