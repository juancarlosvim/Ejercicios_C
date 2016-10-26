//n) Calcular la suma de 1^2+2^2+3^2+ ... + 19^2
#include <stdio.h>
//#include <math.h> probado con pow pero no lo calcula bien la respuesta sale con pow 2465 y sin pow 2470;

int main()
{
    int i=0, n = 0, cuadrado;
    for(i=0;i<=19;i++)
    {
       cuadrado = i * i;
       n = n + cuadrado;

    }
    printf("%d", n);

}
