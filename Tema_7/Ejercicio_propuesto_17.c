#include <stdio.h>
#include <stdlib.h>

int main()
{
    int vector[20];
    int i, j, sw, aux;

    srand(time(NULL));

    for(i=0;i<20;i++) // imprime 20 numeros aleatorios entre 1 y 90
    {
        vector[i]=rand()%90+1;
        printf("%d\n", vector[i]);
    }
    for(i=0;i<=19;i++) //metodo de la burbuja para ordenar el vector
    {
        sw =0;
        for(j=20;j>=i+1;j--)
        {
            if(vector[j-1]>vector[j]){
                sw =1;
                aux = vector[j-1];
                vector[j-1]= vector[j];
                vector[j]=aux;
            }
        }
        if(sw==0){
            break;
        }
    }
    printf("Vector ordenado \n");
    for(i=0;i<=19;i++)
    {
        printf("%4d\t", vector[i]);
    }
    printf("\n");
    printf("menor a mayor \n");
    for(i=0;i<=19;i++)
    {
        printf("%4d\t", vector[i]);
    }
    printf("\n");
    printf("mayor a menor \n");
    for(i=20;i>=1;i--)
    {
        printf("%4d\t", vector[i]);
    }
return 0;
}
