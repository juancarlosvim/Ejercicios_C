#include <stdio.h>
#include <stdlib.h>
//contando la posicion cero
int main()
{
    int matriz[5][10]; // tamaño de la matriz
    int i; //filas
    int j; //columnas
    int minimo =100, maximo =0;
    int posicioni, posicionj;
    int posmi, posmj;


    srand(time(NULL));

    for(i=0;i<5;i++) //imprimir matriz
    {
        for(j=0;j<10;j++)
        {

            matriz[i][j] = rand()%90+1;
            printf("%4d", matriz[i][j]);
        }
        printf("\n");
    }
    for(i=1;i<=4;i++)
    {
        for(j=0;j<=9;j++)
        {
            if(maximo<matriz[i][j])
            {
                posicioni = i;
                posicionj = j;
                maximo = matriz[i][j];
            }
        }
    }
    for(i=0;i<=4;i++)
    {
        for(j=0;j<=9;j++)
        {
            if(minimo>matriz[i][j])
            {
                posmi = i;
                posmj = j;
                minimo = matriz[i][j];
            }
        }
    }
    printf("Mayor %d posicion %d,%d\n", maximo, posicioni, posicionj);
    printf("Menor %d posicion %d,%d\n", minimo, posmi, posmj);
return 0;
}
