#include <stdio.h>
//T4_P20_V1. Algoritmo que calcule e imprima la suma y el producto de los números
//pares comprendidos entre el 10 y el 20 (ambos inclusive).
//Nota: Se utilizan dos acumuladores SUMA y PRODUCTO que totalizan los dos resultados pedidos.

void miFuncion(int, int);

main()
{
    int inicio =10, fin = 20;

    miFuncion(inicio,fin);
}

void miFuncion(int inicio, int fin)
{
    int suma = 0, producto = 1;
    int c = 0; //c es el contador y lo igualamos a 0
    if(inicio%2!=0)
    {
        inicio +=1;
    }
    for(c=inicio;c<=fin;c+=2)
    {
        suma +=c;
        producto *= c;


    }
    printf("la suma %d\n y el producto %d\n", suma, producto);


}
