#ifndef _ARRAY_LIST_
#define _ARRAY_LIST_

typedef struct ArrayListNodeType {
	int data;
} ArrayListNode;

typedef struct ArrayListType {
	int currentElementCount;
	int maxElementCount;
	ArrayListNode *pElement;
} ArrayList;


ArrayList* createArrayList(int maxElementCount); // 배열 리스트 생성

int addALElement(ArrayList *pList, int position, ArrayListNode element); // 배열 원소 추가
int removeALElement(ArrayList *pList, int position); // 배열 원소 삭제

ArrayListNode* getALElement(ArrayList *pList, int position); // 해당 위치 배열 원소 주소값 반환

void displayArrayList(ArrayList *pList);

int clearArrayList(ArrayList *pList); // 배열 리스트 비우기, 전체 크기 그대로 but, 원소만 비우기
int deleteArrayList(ArrayList **dpList); // 배열 리스트 삭제

int isArrayListEmpty(ArrayList *pList);
int isArrayListFull(ArrayList *pList);

int getArrayListLength(ArrayList *pList);


#endif


#ifndef _COMMON_LIST_DEF_
#define _COMMON_LIST_DEF_

#define TRUE 1
#define FALSE 0

#endif
