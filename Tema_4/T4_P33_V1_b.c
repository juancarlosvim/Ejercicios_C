#include <stdio.h>
#include <math.h>
//T4_P33_V1. Algoritmo que indique si un número introducido por teclado es primo o
//no
int main()
{
    int n, i, sw = 0;
    printf("Introduce un numero entero positivos: ");
    scanf("%d", &n);
    for(i=2;i<=(int)sqrt(n);i++)
    {
        if(n%i==0){
            sw = 1;
        }
    }
    if(sw == 0){
        printf("%d es primo", n);
    }
    else{
        printf("%d no es primo", n);

    }
return 0;
}
