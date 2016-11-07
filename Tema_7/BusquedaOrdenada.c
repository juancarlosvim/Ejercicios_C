#include <stdio.h>
#include <stdlib.h>
// Vector no ordenado. Valores  (supuestamente) no repetidos
int main ()
{
        int V[21];
        int i,j,sw,aux,x;

        srand(time(NULL));
        for (i=1; i<=20; i++)
        {
            V[i] = rand()%900+1;
        }
        for (i=1; i<=20; i++)
        {
            printf("%3d\t",V[i]);
        }
        printf("\n");

        for (i=1; i<=19; i++)
        {
            sw=0;
            for (j=20; j>= i+1; j--)
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
        for (i=1; i<=20; i++)
            {
                printf("%3d\t",V[i]);
            }
            printf("\n");
        do{
            sw=0;
            printf("Introduce el número a buscar: ");
            scanf("%d",&x);
            if (x==0)
                break;
            for(i=1;i<=20;i++){
                if (x<V[i])
                    break;
                if (x==V[i]){
                    printf("El número %d está en la posición %d\n",x,i);
                    sw=1;
                    break;
                }
                printf("Voy por %d\n",i);
            }
            if (sw==0)
                printf("\nNo encontrado");

        }while(x!=0);

    return 0;
}
