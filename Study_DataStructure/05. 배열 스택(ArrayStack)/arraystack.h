#ifndef _ARRAY_STACK_
#define _ARRAY_STACK_

typedef struct ArrayStackNodeType {

	char data;
} ArrayStackNode;

typedef struct ArrayStackType {

	int currentElementCount; // Top을 가리키는 index 역할도 할 것임.
	int maxElementCount;
	ArrayStackNode *pElement;
} ArrayStack;


ArrayStack* createArrayStack(int maxElementCount);

int pushAS(ArrayStack *pStack, ArrayStackNode element);
ArrayStackNode* popAS(ArrayStack *pStack);
ArrayStackNode* peekAS(ArrayStack *pStack);

void displayArrayStack(ArrayStack *pStack);

int clearArrayStack(ArrayStack *pStack);
int deleteArrayStack(ArrayStack **dpStack);

int isArrayStackEmpty(ArrayStack *pStack);
int isArrayStackFull(ArrayStack *pStack);

int getArrayStackLength(ArrayStack *pStack);

#endif


#ifndef _COMMON_STACK_DEF_
#define _COMMON_STACK_DEF_

#define TRUE 1
#define FALSE 0

#endif