#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
int main()
{
    int vectorA[20][20];
    int numero, fila, columna;
    int i, j;
    int suma;

    do{
        printf("Introduce el numero del cuadrado: ");
        scanf("%d", &numero);
    }
    while(numero%2==0);
    for(i=1;i<=numero;i++)
    {
        for(j=1;j<=numero;j++)
        {
            vectorA[i][j]=0;

        }
    }
    fila = numero /2;
    columna = (numero/2) +1;
    vectorA[fila][columna] = 1;
    gotoxy(4*columna,4+fila);
    printf("%3d", vectorA[fila][columna]);
    getch();
    for(i=2;i<=numero * numero; i++)
    {
        if(fila==1){
            fila = numero + 1;

        }
        fila = fila -1;

        if(columna == numero)
        {
            columna = 0;

        }
        columna = columna + 1;

        if(vectorA[fila][columna]==0){
            vectorA[fila][columna]= i;
            gotoxy(4*columna,4+fila);
            printf("%3d", vectorA[fila][columna]);
            getch();
        }
        else{
            fila =  fila -1;
            columna = columna -1;

            if(fila ==0)
            {
                fila = numero;
            }
            if(columna==0)
            {
                columna = numero;
            }
            vectorA[fila][columna] = i;
            gotoxy(4*columna, 4+fila);
            printf("%3d", vectorA[fila][columna]);
            getch();
        }
    }
    puts("");
    puts("");
    suma = (numero*(numero*numero+1)/2);
    printf("La suma de cada fila, columna y diagonal es de:  %d \n", suma);
return 1;
}
