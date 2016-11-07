#include <stdio.h>
#include <stdlib.h>
#define N 20
// Busqueda dicotómica
int main ()
{
        int V[N+1];
        int i,j,sw,aux,x,izq,der,cen;

        srand(time(NULL));
        for (i=1; i<=N; i++)
        {
            V[i] = rand()%10+1;
        }
        for (i=1; i<=N; i++)
        {
            printf("%3d\t",V[i]);
        }
        printf("\n");

        for (i=1; i<=N-1; i++)
        {
            sw=0;
            for (j=N; j>= i+1; j--)
            {
                if (V[j-1]> V[j])
                {
                    sw=1;
                    aux = V[j -1];
                    V[j-1] = V[j];
                    V[j]= aux;
                }
            }
            if (sw==0)
                break;
        }

        printf("Vector ordenado de menor a mayor\n");
        for (i=1; i<=N; i++)
            {
                printf("%3d\t",V[i]);
            }
            printf("\n");
        do{
            printf("Introduce el número a buscar: ");
            scanf("%d",&x);
            if (x==0)
                break;
            izq = 1;
            der = N;
            do{
                cen = (izq+der)/2;
                if ((x==V[cen])||(izq>=der)){
                    if (x==V[cen])
                        printf("Encontrado en la posición %d\n",cen);
                    else
                        printf("No encontrado\n");
                    break;
                }
                else{
                    if (x>V[cen])
                        izq = cen + 1;
                    else
                        der = cen - 1;
                }
            }while(1);
        }while(x!=0);

    return 0;
}
