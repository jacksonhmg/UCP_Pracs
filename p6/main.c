#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

void printData(void* pData)
{
	printf("APP:PDATA: %d\n", *((int*)pData));
}

void freeData(void* pData)
{
	free(pData);
}

/*int main()
{
	LinkedList* pList = createLinkedList();
	int iData1 = 10, iData2 = 20;
	
	insertFirst(pList, &iData1);
	insertLast(pList, &iData2);
   insertFirst(pList, &iData1);
   insertLast(pList, &iData2);

	printLinkedList(pList, &printData);

   removeFirst(pList);
   printLinkedList(pList, &printData);
    
   removeLast(pList);
   insertFirst(pList, &iData1);
	freeLinkedList(pList, &freeData);

    
	
	return 0;
}
/*int main(int argc, char const *argv[])
{
   LIST* list = NULL;
   char* color = RED;
   int ii;
   int passiSize = 0;
   int success = TRUE;

   testFunc currentTest = NULL;

   testFunc tests[TEST_COUNT] = {
      &testInsertStart1(list),
      &testInsertLast1(list),
      &testInsertStart2(list),
      &testInsertLast2(list),
      &testRemoveStart(list),
      &testRemoveLast(list),
      &testInsertStart3(list),
      &testFreeList(list),
   };

   list = testCreation();

   if(list != NULL)
   {  
      printf(GREEN "PASSED\n" RESET );
      ii = 0;
      passiSize++;
      while(ii < TEST_COUNT && success == TRUE)
      {  
         currentTest = tests[ii];
         success = (*currentTest)(list);

         if(success)
         {
            printf(GREEN "PASSED\n" RESET );
            passiSize++;
         }
         else
         {
            printf("Here is what your list looked like at time of fail\n");
            testPrintList(list);
         }
         ii++;
         
      }
   }
   
   if (passiSize == TEST_COUNT+1)
   {
      color = GREEN;
   }

   printf("\nTest passed: %s %d/%d\n\n" RESET ,color, passiSize, TEST_COUNT+1);

   return 0;
}*/