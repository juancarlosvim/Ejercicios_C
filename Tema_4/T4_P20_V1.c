#include <stdio.h>
//T4_P20_V1. Algoritmo que calcule e imprima la suma y el producto de los números
//pares comprendidos entre el 10 y el 20 (ambos inclusive).
//Nota: Se utilizan dos acumuladores SUMA y PRODUCTO que totalizan los dos resultados pedidos.

int main()
{
    int suma = 0, producto = 1, i;
    for(i=10;i<=20;i+=2)
    {


            suma += i;
            producto = producto*i;


    }

    printf("la suma %d\n y el producto %d\n", suma, producto);


return 0;
}
