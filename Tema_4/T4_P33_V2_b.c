#include <stdio.h>
#include <math.h>
//T4_P33_V1. Algoritmo que indique si un número introducido por teclado es primo o
//no
int main()
{
    int i, numero, sw, m = 0, p=0; //p es el contador

    printf("Introduce cuantos numeros primos quieres: ");
    scanf("%d", &numero);
    do{
        m += 1;
        sw = 0;
        for(i=2;i<=sqrt(m);i++)
        {
            if(m%i==0)
            {
                sw = 1;
            }
        }
        if(sw==0)
        {
            p++;
            printf("%d es el %d primo\n", m, p);
        }

    }
    while(p<numero);
return 0;
}
