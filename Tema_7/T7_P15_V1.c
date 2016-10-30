#include <stdio.h>

int main()
{
    int vector[16], i, aux;

    for(i=1;i<=15;i++)
    {
        printf("Introduce la componente %d: ", i);
        scanf("%d", &vector[i]);
    }

    for(i=1;i<=14;i++)
    {
        if(vector[i+1]<vector[1]){
            aux = vector[i];
            vector[i] = vector[i+1];
            vector[i+1] = aux;
        }
    }
    printf("La componente ultima del vector es: %d \n", vector[15]);
return 0;
}
