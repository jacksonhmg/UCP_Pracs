#include <stdio.h>

int main(int argc, char* argv[])
{
    FILE* f1 = fopen(argv[1], "r");
    
    FILE* f2 = fopen(argv[2], "w");
    char ch;
    if(f1 == NULL)
    {
        perror("Error opening f1");
    }
    if(f2 == NULL)
    {
        perror("Error opening f2");
    }   
    
    do{
        ch = fgetc(f1);
        if(ferror(f1))
        {
            perror("Error reading from f1");
        }
        if(ch != EOF)
        {
            fputc(ch,f2);
            if(ferror(f2))
            {
                perror("Error writing to f2");
            }
        }
    }while (ch != EOF);
    
    
    fclose(f1);
    fclose(f2);

    return 0;
}