#ifndef _CIRCULAR_LINKED_LIST_
#define _CIRCULAR_LINKED_LIST_

typedef struct CircularLinkedListNodeType {

	int data;
	struct CircularLinkedListNodeType *pLink;
} CircularListNode;

typedef struct CircularLinkedListType {

	int currentElementCount;
	CircularListNode *pHead; // 이번엔 헤드 포인터로 구현.
} CircularList;


CircularList* createCircularList();

int addCLElement(CircularList *pList, int position, CircularListNode element);
int removeCLElement(CircularList *pList, int position);

CircularListNode* getCLElement(CircularList *pList, int position);

void displayCircularList(CircularList *pList);

int clearCircularList(CircularList *pList);
int deleteCircularList(CircularList **dpList);

int isCircularListEmpty(CircularList *pList);

int getCircularListLength(CircularList *pList);



#endif

#ifndef _COMMON_LIST_DEF_
#define _COMMON_LIST_DEF_

#define TRUE 1
#define FALSE 0

#endif