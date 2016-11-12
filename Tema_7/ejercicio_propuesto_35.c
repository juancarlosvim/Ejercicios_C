#include <stdio.h>
#define n 10

int oredanicion_shell(int [], int );

int main()
{

    int v[n+1]; //vector
    int i;
    for(i=1;i<=n;i++)
    {
        scanf("%d", &v[i]);
    }
    ordenacion_shell(v,n);

    printf("Vector ordenado\n");
    for(i=1;i<=n;i++)
    {
        printf("%d\t", v[i]);
    }
return 0;
}

int ordenacion_shell( int v[], int nn)
{
    int d, sw, aux, i;

    d=nn;
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

}
