//n) Calcular la suma de 1^2+2^2+3^2+ ... + 19^2
#include <stdio.h>

int main()
{
    int i = 0, n = 0, cuadrado;

    while(i<=19){

        cuadrado = i * i;
        n += cuadrado;
        i++;
    }

    printf("%d", n);

 return 0;
}
