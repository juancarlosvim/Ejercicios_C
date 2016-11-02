#include <stdio.h>

int main()
{
    int vector[3][3] ={0};
    int i; //filas
    int j; //columnas

    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
           scanf("%d", &vector[i][j]);

        }

    }

    for(i=0;i<3;i++) //matriz ordenada
    {
        for(j=0;j<3;j++)
        {
            printf("%d", vector[i][j]);
        }
        printf("\n");
    }

return 0;

}
