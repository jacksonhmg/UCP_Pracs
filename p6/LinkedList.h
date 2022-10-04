#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef void (*listFunc)(void* data);

typedef struct LinkedListNode
{
	void* pData;
	struct LinkedListNode* pNext;
} LinkedListNode;

typedef struct LinkedList
{
	LinkedListNode* pHead;
	LinkedListNode* pTail;
	int iSize;	
} LinkedList;

LinkedList* createLinkedList();
void insertLast(LinkedList* list, void* entry);
void insertFirst(LinkedList* pList, void* pEntry);
void* removeLast(LinkedList* list);
void* removeFirst(LinkedList* pList);
void printLinkedList(LinkedList* list, listFunc funcPtr);
void freeLinkedList(LinkedList* list, listFunc funcPtr);


/* DO NOT CHANGE ANY OF THESE DEFINES */
   #define FALSE 0
   #define TRUE !FALSE
   #define RED "\033[0;31m"
   #define GREEN "\033[0;32m"
   #define RESET "\033[0m"

   #define STR_MATCH(a,b) (strncmp((a),(b),strlen(b)+1) == 0)

   #define TEST_COUNT 8

   #define STR1 "Hello"
   #define STR2 "World"
   #define STR3 "Steve"
   #define STR4 "Bob"
   #define STR5 "Alice"
/* END OF THAT BLOCK */

/* Change these if you have named your Linked Lists structs something weird :P */
   #define LIST LinkedList
   #define NODE LinkedListNode
   #define HEAD pHead
   #define TAIL pTail
   #define DATA pData
   #define COUNT iSize
/* END OF THAT BLOCK*/

/* Uncomment this define if you did a double ended array and want to test that */
   /* #define DOUBLE_ENDED */
   /* #define DOUBLE_LINKED */
/* END OF THAT BLOCK*/


void printString(void* data);
void freeString(void* data);
int testFreeList(LIST* list);
void testPrintList(LIST* list);
int testRemoveLast(LIST* list);
int testRemoveStart(LIST* list);
int testInsertLast2(LIST* list);
int testInsertLast1(LIST* list);
int testInsertStart3(LIST* list);
int testInsertStart2(LIST* list);
int testInsertStart1(LIST* list);
LIST* testCreation();
int checkiSize(LIST* list, int iSize);
int checkTail(LIST* list, char* input);
int checkHead(LIST* list, char* input);

typedef int(*testFunc)(LIST* list);


#endif