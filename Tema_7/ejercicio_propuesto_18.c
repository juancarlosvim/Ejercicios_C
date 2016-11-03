#include <stdio.h>
#include <stdlib.h>

int main()
{
    int vector[100];
    int i, j, sw, aux;

    srand(time(NULL));
    for(i=0;i<100;i++)
    {
        vector[i]= rand()%401+100;
        printf("%d\n", vector[i]);
    }

    for(i=1;i<=100;i++)
    {
        sw = 0;
        for(j=100;j>=i+1;j--)
        {
            if(vector[j-1]>vector[j]){
                sw=1;
                aux = vector[j-1];
                vector[j-1]= vector[j];
                vector[j]=aux;
            }
        }
        if(sw==0){
            break;
        }
    }
    printf("vector ordenado\n");
    for(i=1;i<100;i++)
    {
        printf("%4d\t", vector[i]);
    }
    puts("");
    printf("Los menores son:\n");
    for(i=1;i<=10;i++)
    {

        printf("%4d\t", vector[i]);
    }
    puts("");
    printf("Los mayores son: \n");
    for(i=90;i<=99;i++)
    {

        printf("%4d\t", vector[i]);

    }
return 0;
}
