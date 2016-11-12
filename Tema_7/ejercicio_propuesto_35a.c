#include <stdio.h>
#define n 10

int busqueda_dicotomica(int [], int, int);

int main()
{
    int v[n+1]={0,1,7, 8, 12, 15, 38, 45, 46, 52, 79};
    int x, pos;

    do{
        printf("Dato (FIN = 0): \n");
        scanf("%d", &x);
        if(x==0){
            break;
        }
        pos=busqueda_dicotomica(v, n, x);

        if(pos== -1){
            printf("%d, no esta en el vector\n", x);
        }
        else{
            printf("%d, esta en la posicion %d\n", x, pos);
        }
    }while(x!=0);
return 0;
}

int busqueda_dicotomica(int v[],int nn, int x)
{
    int izq, der, cen;

    izq = 1;
    der = nn;
    do{
        cen =(izq + der) /2;
        if( (x==v[cen]) || (izq>=der) ){
            if(v[cen] == x){
                return cen;
            }
            else{
                return -1;
                break;
            }
        }
        if(x>v[cen]){
            izq = cen +1;
        }
        else{
            der = cen -1;
        }
    }while(1);
}
