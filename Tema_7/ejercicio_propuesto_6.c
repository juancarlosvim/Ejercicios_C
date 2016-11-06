#include <stdio.h>

int main()
{
    int fil, col;
    int i; //filas
    int j; // columnas

    printf("Introduzca las filas de la matriz: \n");
    scanf("%d", &fil);
    printf("Introduzca las columnas de la matriz: \n");
    scanf("%d", &col);
    int matriz[fil][col]; //tamaño de la matriz


    for(i=0;i<=fil;i++)
    {

        for(j=0;j<=col;j++)
        {
            if(i == j){
                matriz[i][j]=1;
            }
            else{
                matriz[i][j]=0;
            }
            printf("%d", matriz[i][j]);
        }
    puts("");
    }
return 0;
}
