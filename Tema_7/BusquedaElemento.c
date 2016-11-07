/*Programa que genere 20 números enteros sobre un vector, comprendidos entre 1 y 90.*/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// Vector no ordenado. Valores (supuestamente) no repetidos
int main(){

    int V[20],i,j,sw,x;

    srand(time(NULL));

    for(i=0;i<20;i++)       //RELLENAR EL VECTOR
    {
        V[i]=rand()%90+1;
        printf("%d\t",V[i]);
    }
    do{
        sw=0;
        scanf("%d",&x);
        if(x==0)
            break;

        for(i=0;i<20;i++){
            if(x==V[i])
            {
                printf("%d en posicion %d\n",x,i);
                sw=1;
                break;
            }
        }

        if(sw==0)
            printf("No encontrado\n");
    }while(1);
return 0;
}
