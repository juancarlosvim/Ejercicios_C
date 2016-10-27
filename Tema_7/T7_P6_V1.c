#include <stdio.h>
//T7_P6_V1.- Programa que recibe como dato un número entero positivo, correspondiente a una cantidad de dinero, y
//calcula e imprime el mejor desglose de moneda (mínimo número de unidades monetarias).
//Las unidades monetarias existentes son: 500, 200, 100, 50, 20, 10, 5, 2, 1.
//El programa almacenará estas cantidades ordenadas en un vector y desglosará la cantidad en orden decreciente de las
//componentes del vector.

int main()
{
    int vectorA[] ={0,500,200,100,50,20,10,5,2,1};
    int cantidad, i, division, resto;
    printf("Introduce una cantidad: ");
    scanf("%d", &cantidad);
    printf("Moneda\t Numero\n");
    for(i=1;i<=9;i++)
    {
        division = cantidad / vectorA[i];
        resto = cantidad % vectorA[i];

        if(division>0){
            printf("%d", vectorA[i]);
            printf("\t%d\n", division);
        }
        cantidad = resto;

    }

}
