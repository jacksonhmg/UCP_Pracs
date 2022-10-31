/*
 * File: LinkedListTest.c
 * File Created: Thursday, 2nd April 2020 5:54:10 pm
 * Author: Jonathon Winter
 * -----
 * Last Modified: Friday, 3rd April 2020 2:14:40 am
 * Modified By: Jonathon Winter
 * -----
 * Purpose: A Test harness for a Linked List in 'C'. You are not needed to understand how it all works. 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

#include "LinkedList.h"

static char* createString(char* input);
static void printTest(char* input);
static void printFailure(char* format, ...);

int checkHead(LIST* list, char* input)
{  
   int success = FALSE;
   if(list->HEAD == NULL)
   {
      printFailure("Head is still NULL");
   }
   else if(!STR_MATCH((char*)(list->HEAD->DATA), input))
   {
      printFailure("Head data %s != %s", (char*)(list->HEAD->DATA), input);
   }
   else
   {
      success = TRUE;
      #ifdef DOUBLE_LINKED
         success = success && (list->HEAD->prev == NULL);
         if(!success)
         {
            printFailure("head->prev is not NULL");
         }
      #endif

   }
   
   return success;
}

int checkTail(LIST* list, char* input)
{
   int success = FALSE;

   #ifdef DOUBLE_ENDED
      if(list->TAIL == NULL)
      {
         printFailure("Tail is still NULL");
      }
      else if(!STR_MATCH((char*)(list->TAIL->DATA), input))
      {
         printFailure("Tail data %s != %s", (char*)(list->TAIL->DATA), input);
      }
      else
      {
         success = TRUE;
         #ifdef DOUBLE_LINKED
            success = success && (list->TAIL->next == NULL);
            if(!success)
            {
               printFailure("tail->next is not NULL");
            }
         #endif
      }
   #else
      NODE* current = list->HEAD;
      while(current->pNext != NULL)
      {
         current = current->pNext;
      }
      
      if(!STR_MATCH((char*)(current->DATA), input))
      {
         printFailure("Tail data %s != %s", (char*)(current->DATA), input);
      }
      else if(current->pNext != NULL)
      {
         printFailure("tail->next is not NULL");
      }
      else
      {
         success = TRUE;
      }
   #endif


   return success;
}

int checkiSize(LIST* list, int iSize)
{
   int success = TRUE;

   if(list->iSize != iSize)
   {
      success = FALSE;
      printFailure("List Couint (%d) != %d", list->iSize, iSize);
   }

   return success;
}

LIST* testCreation()
{
   LIST* list = NULL;

   printTest("Creating List");
   list = createLinkedList();

   if(list == NULL)
   {
      printFailure("List == NULL");
      list = NULL;
   }
   else if (list->HEAD != NULL)
   {
      printFailure("List head != NULL");
      list = NULL;
   }
   #ifdef DOUBLE_ENDED
   else if (list->TAIL != NULL)
   {
      printFailure("List tail != NULL");
      list = NULL;
   }
   #endif
   else if (list->iSize != 0)
   {
      printFailure("List iSize (%d) != %d", list->iSize, 0);
      list = NULL;
   }

   return list;
}

int testinsertFirst1(LIST* list)
{
   int success = FALSE;
   char* str = createString(STR2);

   printTest("Insert First #1");
   insertFirst(list, str);

   success = checkHead(list, str) && 
               checkTail(list, str) &&
               checkiSize(list,1);
   
   return success;
}

int testinsertFirst2(LIST* list)
{
   int success = FALSE;
   char* str = createString(STR1);

   printTest("Insert First #2");
   insertFirst(list, str);

   success = checkHead(list, str) && 
               checkTail(list, STR3) &&
               checkiSize(list, 3);

   return success;
}

int testinsertFirst3(LIST* list)
{
   int success = FALSE;
   char* str = createString(STR5);

   printTest("Insert First #3");
   insertFirst(list, str);

   success = checkHead(list, str) && 
               checkTail(list, STR3) &&
               checkiSize(list, 3);

   return success;
}

int testInsertLast1(LIST* list)
{
   int success = FALSE;
   char* str = createString(STR3);

   printTest("Insert Last #1");

   insertLast(list, str);

   success = checkTail(list, str) && 
               checkiSize(list, 2);

   return success;
}

int testInsertLast2(LIST* list)
{
   int success = FALSE;
   char* str = createString(STR4);

   printTest("Insert Last #2");

   insertLast(list, str);

   success = checkTail(list, str) && 
               checkiSize(list, 4);

   return success;
}

int testremoveFirst(LIST* list)
{
   int success;
   char* removed;
   
   printTest("Remove First");

   removed = removeFirst(list);

   success = (strncmp(removed, STR1, strlen(STR1)+1) == 0) && 
               checkHead(list, STR2) && 
               checkiSize(list, 3);

   /* Only success if both checks are passed */
   free(removed);

   return success ;
}

int testRemoveLast(LIST* list)
{
   int success;

   char* removed;
   printTest("Remove Last");

   removed = (char*)removeLast(list);

   success = (strncmp(removed, STR4, strlen(STR4)+1) == 0) && 
               checkTail(list, STR3) && 
               checkiSize(list, 2);

   free(removed);

   return success ;
}

void testPrintList(LIST* list)
{
   printf(" iSize: %d\n", list->iSize);
   printLinkedList(list, &printString);
}

int testFreeList(LIST* list)
{
   printTest("Free List");

   freeLinkedList(list, &freeString);
   /* There isnt really a way to test if it properly freed (Use valgrind) */
   return TRUE;
}

static void printTest(char* input)
{
   printf("%-16s: ", input);
}

static void printFailure(char* format, ...)
{
   va_list args;
   va_start(args, format);

   printf(RED);
   vprintf(format, args);
   printf("\n"RESET);

   va_end(args);
}

void printString(void* data)
{
   char* str = (char*)data;
   printf("  %s\n", str);
}

void freeString(void* data)
{
   free(data);
}

static char* createString(char* input)
{
   int length = strlen(input) + 1;

   char* str = (char*)malloc(sizeof(char) * length);
   strncpy(str,input, length);

   return str;
}

int main(int argc, char const *argv[])
{
   LIST* list = NULL;
   char* color = RED;
   int ii;
   int passiSize = 0;
   int success = TRUE;

   testFunc currentTest = NULL;

   testFunc tests[TEST_COUNT] = {
      &testinsertFirst1,
      &testInsertLast1,
      &testinsertFirst2,
      &testInsertLast2,
      &testremoveFirst,
      &testRemoveLast,
      &testinsertFirst3,
      &testFreeList,
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
}