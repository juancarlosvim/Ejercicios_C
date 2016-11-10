#include <stdio.h>
#include <stdlib.h>
#define n 20

int main()
{
    int v[n+1];
    int i, izq, der, aux, sw;


    srand(time(NULL));

    for(i=1;i<=n;i++)
    {
        v[i]=rand()%90+1;
        printf("%4d\t", v[i]);
    }
    puts("");
    //metodo de la sacudida
    izq=1;
    der=n;
    while(izq!=der)
    {
        sw=0;
        for(i=izq;i<=der-1;i++)
        {
            if(v[i]>v[i+1]){
                aux=v[i];
                v[i]=v[i+1];
                v[i+1]=aux;
                sw = 1;
            }
        }
        if(sw==0){
            break;
        }
        der=der-1;
        if(izq==der){
            break;
        }
        sw =0;
        for(i=der;i>=izq+1;i--)
        {
            if(v[i-1]>v[i]){
                aux=v[i];
                v[i]=v[i-1];
                v[i-1]=aux;
                sw =1;
            }
        }
        if(sw==0){
            break;
        }
        izq=izq+1;

    };
    puts("");
    printf("Nuestro vector ordenador por el metodo de la sacudida de menor a mayor\n");
    for(i=1;i<=n;i++)
    {
        printf("%4d\t", v[i]);
    }

    puts("");

    //metodo de la sacudida de mayor a menor

    printf("Nuestro vector ordenador por el metodo de la sacudida de mayor a menor\n");
    for(i=n;i>=1;i--)
    {
        printf("%4d\t", v[i]);
    }

    puts("");
    //busqueda dicotomica
return 0;
}
