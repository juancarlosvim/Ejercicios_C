//T4_P19_V1. Algoritmo que lea 10 números y cuente cuántos de ellos son positivos.

#include <stdio.h>

main()
{
    int p=0, i, n;
    printf("Introduce 10 numeros: ");
    for(i=1;i<=10;i++)
    {

        scanf("%d", &n);
        if(n>0)
        {
            p += 1;

        }

    }

    printf("Hay %d numeros positivos", p);
return 0;
}
