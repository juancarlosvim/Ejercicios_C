#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char colores[4][4][10];
    int i, j;

    printf("Introduce colores => ");
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            fflush(stdin);
            gets(colores[i][j]);
        }
    }
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
            printf("%5s   \t", colores[i][j]);
        {
        }
        printf("\n");
    }
return 0;
}
