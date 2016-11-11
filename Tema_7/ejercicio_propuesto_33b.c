#include <stdio.h>
#include <stdlib.h>
#define n 20

int main()
{
    int v[n+1];
    int i, aux, sw ,d;


    srand(time(NULL));
    puts("Vector generado");
    for(i=1;i<=n;i++)
    {
        v[i]=rand()%90+1;
        printf("%4d\t", v[i]);
    }
    puts("");
    //metodo de Shell
   d=n;
    puts("");

    while(d!=1)
    {
        d = (d/2);
        sw = 1;
        while(sw==1){
            sw =0;
            for(i=1;i<=n-d;i++)
            {
                if(v[i]>v[i+d]){
                    aux = v[i+d];
                    v[i+d] = v[i];
                    v[i]= aux;
                    sw=1;
                }
            }
        }
    }
    puts("");
    puts("Vector ordenado por el metodo shell");
    for(i=1;i<=n;i++)
    {
        printf("%4d\t", v[i]);
    }

    //metodo de shell de mayor a menor
    puts("");
    printf("Nuestro vector ordenador por el metodo shell de mayor a menor\n");
    for(i=n;i>=1;i--)
    {
        printf("%4d\t", v[i]);
    }

    puts("");
return 0;
}
