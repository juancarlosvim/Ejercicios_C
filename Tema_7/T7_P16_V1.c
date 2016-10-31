#include <stdio.h>

int main()
{
    int vectorA[13] = {0, 44, 24, 18, 56, 6, 78, 21, 27, 18, 34, 15, 31};
    int i, j, aux, sw;

    printf("Datos del vector: \n");
    for(i=1;i<=12;i++)
    {

        printf("%3d", vectorA[i]);
    }
    for(i=1;i<=12;i++)
    {
        sw = 0;
        for(j=12;j>=i+1;j--)
        {
            if(vectorA[j]<vectorA[j-1]){
                aux = vectorA[j-1];
                vectorA[j-1]= vectorA[j];
                vectorA[j] = aux;
                sw =1;
            }
        }
        if(sw==0){
            break;
        }
    }
    printf("Vector ordenado: \n");
    for(i=1;i<=12;i++)
    {
        printf("%3d", vectorA[i]);
    }
return 0;
}
