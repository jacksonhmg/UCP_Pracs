#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "header.h"

int main(int argc, char* argv[])
{
    Entry* eArray = NULL;

    int nLine, nRead,day,month,year,counter,nElement;
    char str[100];
    FILE* f1 = fopen("journalinfo.txt","r");
    if(f1 == NULL)
    {
        perror("Error opening f1");
    }
    nRead = fscanf(f1,"%d ",&nLine);
    
    eArray = (Entry*)malloc(nLine * sizeof(Entry));

    counter = 0;

    do
    {
        nRead = fscanf(f1,"%d/%d/%d ",&day,&month,&year);        
        if(nRead != EOF)
        {
            eArray[counter].day = day;
            // printf("|%d/",eArray[counter].day);
            eArray[counter].month = month;
            // printf("%d/",eArray[counter].month);
            eArray[counter].year = year;
            // printf("%d\n",eArray[counter].year);          
            eArray[counter].text = malloc(sizeof(char) * 500);
            fgets(eArray[counter].text, 500, f1);
            // printf("%s\n",eArray[counter].text);
            counter++;
            /*printf("\n");
            printf("%ld\n",ftell(f1));*/
        }
        
    } while(nRead != EOF);

    if(ferror(f1))
    {
        perror("Error reading from f1");
    }

    nElement = atoi(argv[1]);

    printf("%d, %d/", nElement, eArray[nElement].day);
    printf("%d/",eArray[nElement].month);
    printf("%d\n",eArray[nElement].year);
    printf("%s\n",eArray[nElement].text);

    return 0;
}