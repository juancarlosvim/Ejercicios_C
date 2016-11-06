#include <stdio.h>
#include <stdlib.h>

int main()
{
    int matriz[6][11]; // tamaño de la matriz
    int i; //filas
    int j; //columnas
    int minimo =100, maximo =0;
    int posicioni, posicionj;
    int posmi, posmj;


    srand(time(NULL));

    for(i=1;i<=5;i++) //imprimir matriz
    {
        for(j=1;j<=10;j++)
        {

            matriz[i][j] = rand()%90+1;
            printf("%4d", matriz[i][j]);
        }
        printf("\n");
    }
    for(i=1;i<=5;i++)
    {
        for(j=1;j<=10;j++)
        {
            if(maximo<matriz[i][j])
            {
                posicioni = i;
                posicionj = j;
                maximo = matriz[i][j];
            }
        }
    }
    for(i=1;i<=5;i++)
    {
        for(j=1;j<=10;j++)
        {
            if(minimo>matriz[i][j])
            {
                posmi = i;
                posmj = j;
                minimo = matriz[i][j];
            }
        }
    }
    printf("Mayor %d posicion (%d,%d)\n", maximo, posicioni, posicionj);
    printf("Menor %d posicion (%d,%d)\n", minimo, posmi, posmj);
return 0;
}
