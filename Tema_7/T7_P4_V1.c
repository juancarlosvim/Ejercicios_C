#include <stdio.h>

int main()
{
    int vectorT[10], vectorV[10], vectorX[10];
    int i;
    int menor, mayor = 0, posicion; //mayor lo igualo a cero para que siempre sea mayor el vectorX[i]

    printf("Introduce 10 numeros y se vera como se copia el vectorT al vectorV\n");
    for(i=0;i<10;i++) //a) Almacenar 10 valores en el vector T y a continuación copiarlos en el vector V.
    {
        scanf("%d", &vectorT[i]);
        vectorV[i] = vectorT[i]; //Copia de vectorT a vectorV
        printf("VectorT[%d]= %d y vectorV[%d] = %d\n", i, vectorT[i], i, vectorV[i]);
    }
    puts(""); //Salto de linea
    for(i=0;i<10;i++) //b) Copiar el vector V en X pero en orden inverso.
    {
        vectorX[i] = vectorV[9-i]; //Copia de vectorV a vectorX pero en orden inverso

        printf("VectorX[%d] = %d\n", i, vectorX[i]);
    }
    puts(""); //Salto de linea
    for(i=0;i<10;i++) //c) Encontrar el menor valor en el vector X e imprimirlo.
    {
        if(vectorX[i]<menor){
            menor = vectorX[i];
        }

    }
    printf("El menor es %d\n", menor);

    puts(""); //Salto de linea

    for(i=0;i<10;i++) //d) Hallar el mayor valor en el vector X, imprimir este valor e indica también su posición en el vector.
    {
        if(vectorX[i]>mayor){
            mayor = vectorX[i];
            posicion = i;
        }
    }
    printf("El mayor es %d y la posicion %d", mayor, posicion);

return 0;
}
