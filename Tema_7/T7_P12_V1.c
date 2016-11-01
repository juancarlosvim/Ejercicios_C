#include <stdio.h>
#include <stdlib.h>

int main()
{
     int vector[11];
     int i, aux;

     srand(time(NULL));

     for(i=1;i<=10;i++)
     {
         vector[i]=rand()%10+1;
     }
     printf("Vector normal: \n");

     for(i=1;i<=10;i++)
     {
         printf("%4d", vector[i]);
     }
     aux = vector[10];
     for(i=1;i<=9;i++)
     {
         vector[11-i] = vector[10-i];
     }
     vector[1]= aux;
     puts("");
     printf("Vector rotado: \n");

     for(i=1;i<=10;i++)
     {
         printf("%4d", vector[i]);
     }
return 0;
}
