//m) Leemos un número N, y generamos los N primeros términos de la serie de Fibonacci.
#include <stdio.h>
int main()
{

   int  N, i = 0;
   int a = 0, b = 1, c;
   printf("Hasta cuantos numeros quieres que te muestre de la serie fibonacci: ");
   scanf("%d", &N);


   if(a==1){
        printf("%d", a);

   }
   if(a==2){
    printf("%d\n%d\n", a, b);
   }
   if(a<2){
    printf("%d\n", a);
    printf("%d\n", b);
    for(i=1;i<=N;i++)
        {
            c = a + b;
            a = b;
            b = c;


            printf("%d\n", c);
        }
   }
return 0;
}
