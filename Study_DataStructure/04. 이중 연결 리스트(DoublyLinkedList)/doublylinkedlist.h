#ifndef _DOUBLY_LINKED_LIST_
#define _DOUBLY_LINKED_LIST_

typedef struct DoublyLinkedListNodeType {
	int data;
	struct DoublyLinkedListNodeType *pLLink;
	struct DoublyLinkedListNodeType *pRLink;
} DoublyListNode;

typedef struct DoublyLinkedListType {
	int currentElementCount;
	DoublyListNode headerNode; // ��� ���� �߰�/���� ������ ������ ���� �ϱ� ���� Dummy ��� !!!!
} DoublyList;


DoublyList* createDoublyList();

int addDLElement(DoublyList *pList, int position, DoublyListNode element);
int removeDLElement(DoublyList *pList, int position);

int clearDoublyList(DoublyList *pList);
int deleteDoublyList(DoublyList **dpList);

DoublyListNode* getDLElement(DoublyList *pList, int position);

void displayDoublyList(DoublyList *pList);

int isDoublyListEmpty(DoublyList *pList);

int getDoublyListLength(DoublyList *pList);

#endif

#ifndef _COMMON_LIST_DEF_
#define _COMMON_LIST_DEF_

#define TRUE 1
#define FALSE 0

#endif