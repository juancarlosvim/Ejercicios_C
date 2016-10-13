//R3_T_V1. Algoritmo que imprima los resultados posibles que se obtienen al considerar la
//suma de los valores del lanzamiento de dos dados, imprimiéndolos en forma de tabla.
#include <stdio.h>
#include <conio.h>

int main()
{
    int i, j;

    for(i=1;i<=6;i++)
    {
        gotoxy(3+4*i,1);
        printf("%d", i);
        gotoxy(1,2+i);
        printf("%d",i);

        for(j=1;j<=6;j++)
        {
            gotoxy(3+4*i,2+j);
            printf("%d", i+j);
        }
    }

return 0;
}
