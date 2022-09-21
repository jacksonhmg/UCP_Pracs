#include <stdio.h>
#include "LinkedList.h"

void printData(void* pData)
{
	printf("APP:PDATA: %d\n", *((int*)pData));
}

void freeData(void* pData)
{
	
}

int main()
{
	LinkedList* pList = createLinkedList();
	int iData1 = 10, iData2 = 20;
	
	insertLast(pList, &iData1);
	insertLast(pList, &iData2);
	
	printLinkedList(pList, &printData);

    removeLast(pList);
    printLinkedList(pList, &printData);
    
	freeLinkedList(pList, &freeData);

    removeLast(pList);
	
	return 0;
}