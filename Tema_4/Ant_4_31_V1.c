#include <stdio.h>

int resdiv(int, int);
int main()
{
    int numero1, numero2;
    printf("Introduzca el dividendo y el divisor ");
    scanf("%d%d", &numero1, &numero2);
    resdiv(numero1, numero2);
    printf("%d /%d = %d  ", numero1, numero2, resdiv(numero1,numero2));
return 0;
}

int resdiv(int a, int b)
{
     int resultado;
    if(a>=b){

        resultado = a-= b;
        resdiv(numero1, numero2);


    }
    else
        return
}
