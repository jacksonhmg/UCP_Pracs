#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[])
{
    FILE* f1 = fopen(argv[1], "r");
    int day, hour, minute, seconds;
    char zMonth[4], processName[51];
    int nRead;
    char zDescription[500];
    char* pDesc = NULL;

    if(f1 == NULL)
    {
        perror("Error opening f1");
    }
    
    do{
        nRead = fscanf(f1, "%3s %d %d:%d:%d %50s", zMonth, &day, &hour, &minute, &seconds, processName);
        if(ferror(f1))
        {
            perror("Error reading from f1");
        }
        if(nRead != EOF && nRead != 6)
        {
            pDesc = fgets(zDescription, 500, f1);
            
            if(pDesc != NULL)
            {
                if(strstr(zDescription, "fail") != NULL)
                {
                    printf("sec: %d, message: %s", hour * 3600 + minute * 60 + seconds, zDescription);
                }
            }
        }
        
    }while (nRead != EOF);
    
    
    fclose(f1);

    return 0;
}