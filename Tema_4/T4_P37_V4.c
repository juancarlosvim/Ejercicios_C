#include <stdio.h>
//T4_P37_V4. Algoritmo que obtenga el producto de dos números enteros positivos mediante el denominado
//“algoritmo ruso del producto”.
int main()
{
    int valor1, valor2, acumulador = 0, numero1, numero2;
    printf("Introduce dos numeros enteros positivos: ");
    scanf("%d%d", &valor1, &valor2);
    numero1 = valor1;
    numero2 = valor2;
    do{
         if(valor2%2==1){
            acumulador += valor1;
         }
         valor1= valor1 *2;
         valor2 = valor2 / 2;
         printf("primer factor %d segundo factor %d acumulador %d\n", valor1, valor2, acumulador);
    }
    while(valor2!=0);
    printf("%d x %d = %d\n", numero1, numero2, acumulador);

return 0;
}
