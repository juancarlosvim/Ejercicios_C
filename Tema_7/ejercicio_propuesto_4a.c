#include <stdio.h>
#include <stdlib.h>

int main()
{
    int matriz[5][10]; // tamaño de la matriz
    int i; //filas
    int j; //columnas
    int minimo =100, maximo =0;
    int filaMayor, columnaMayor;
    int filaMenor, columnaMenor;


    srand(time(NULL));

    for(i=0;i<5;i++) //imprimir matriz
    {
        for(j=0;j<10;j++)
        {
            matriz[i][j] = rand()%90+1;
            printf("%4d", matriz[i][j]);

	    if(matriz[i][j] > maximo)
            {
                filaMayor = i;
                columnaMayor = j;
                maximo = matriz[i][j];
            }

	    if(matriz[i][j] < minimo)
            {
                filaMenor = i;
                columnaMenor = j;
                minimo = matriz[i][j];
            }
        }
        printf("\n");
    }


    printf("Mayor %d posicion %d%d\n", maximo, filaMayor, columnaMayor);
    printf("Menor %d posicion %d%d\n", minimo, filaMenor, columnaMenor);
}
