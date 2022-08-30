#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    FILE* f1 = fopen(argv[1], "r");
    double rows, cols;
    double** arr2d;
    
    int nRead;
    
    int i, j;

    if(f1 == NULL)
    {
        perror("Error opening f1");
    }
    else
    {
        nRead = fscanf(f1, "%lf %lf", &rows, &cols);
        printf("%f %f", rows, cols);
        if(ferror(f1))
        {
            perror("Error reading from f1");
        }
        if(nRead != EOF)
        {
            arr2d = (double**)malloc(sizeof(double) * rows);
        }

        for(i = 0; i < rows ; i ++)
        {
            arr2d[i] = (double*)malloc(sizeof(double) * cols);
            for(j = 0; j < cols ; j ++)
            {
                fscanf(f1, "%lf", &(arr2d[i][j]));
                printf("%10.2f", arr2d[i][j]);
            }

            
        }
        
    }

    
    
    
    fclose(f1);

    return 0;
}