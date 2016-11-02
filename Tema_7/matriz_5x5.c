#include <stdio.h>

int main()
{
    int vector [5][5] ={0}; //tamaño de la matriz 5x5
    int i; //filas
    int j; // columnas

    for(i=0;i<=4;i++)
    {
        vector[i][i]=1;
    }
    for(i=0;i<=4;i++)
    {

        for(j=0;j<=4;j++)
        {
            printf("%d", vector[i][j]);
        }
        puts("");
    }
return 0;
}
