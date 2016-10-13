#include <stdio.h>


int main()
{
     int sp = 0, si =0, i; //sp suma de pares, si suma de impares

    for(i=1;i<=100; i+=2)
    {
        si += i;
    }
    printf("La suma de los impares es: %d\n", si);

    for(i=2;i<=100;i+=2)
    {
        sp += i;
    }
    printf("La suma de los pares es: %d", sp);

return 0;
}
