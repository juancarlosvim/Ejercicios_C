//T4_P19_V1. Algoritmo que lea 10 números y cuente cuántos de ellos son positivos.

#include <stdio.h>
int teclado(); // Funcion que lee por teclado la cantidad de numeros que se le pase.
int main(void)
{
   int num = 10;
   int pos = 0; /*Consideramos el 0 como numero positivo*/


   pos = teclado(num);
   printf("Hay %d numeros positivos", pos);
   printf("Hat %d numeros negativos", num - pos);
return 0;
}

int teclado( int contador){
    int k = 0;
    int pos = 0;
    int numero = 0; //Ahora mismo perdemos el numero cada vez que introducimos otro por teclado. Lo ideal es utilizar un vector de enteros para almacenar numeros.
    for(k = 1; k <= contador; k++){
        printf("%d.Introduce un numero: ",k);
        scanf("%d",&numero);

            /*Cuando esten implementados los vectores  podremos
              sacar la llamada a esta funcion y hacerla mas independiente*/

        pos += numPositivo(numero);

    }
    return pos;
}

int numPositivo(int num){
    int sw = 0;
    if(num <= 0){
        sw = 1;
    }
    return sw;
}
