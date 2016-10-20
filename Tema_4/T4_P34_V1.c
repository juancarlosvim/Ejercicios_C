#include <stdio.h>
//T4_P34_V1. Algoritmo que obtenga e imprima la lista de los divisores de un número N
//entero positivo.

int main()
{
    int numero, i;

    printf("Introduzca un numero: ");
    scanf("%d", &numero);
    printf("Los divisores de %d son\n", numero);

    for(i=1;i<=numero;i++)
    {
        if(numero%i == 0){
            printf("%d\t",i);
        }
    }
return 0;
}
