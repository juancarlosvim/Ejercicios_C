#include <stdio.h>
#include <stdlib.h>
#define f 20
#define c 7

int main()
{
    int m[f+1][c+1];
    int i, j, d, sw, aux;
    int izq, der, cen, x;

    srand(time(NULL));

    for(i=1;i<=f;i++)
    {
        for(j=1;j<=c;j++)
        {
            m[i][j] = rand()%100+1;
            printf("%3d\t", m[i][j]);
        }
        printf("\n");
    }
    d=f;
    puts("");
    puts("metodo shell");
    while(d!=1)
    {
        d = (d/2);
        sw = 1;
        while(sw==1){
            sw =0;
            for(i=1;i<=f-d;i++)
            {
                if(m[i][1] < m[i+d][1]){
                    for(j=1; j<=c; j++)
                    {
                        aux = m[i+d][j];
                        m[i+d][j] = m[i][j];
                        m[i][j]= aux;
                    }
                    sw=1;
                }
            }
        }
    }
    puts("matriz ordenada por el metodo shell");
    for(i=1;i<=f;i++)
    {
        for(j=1;j<=c;j++)
        {
            printf("%4d\t", m[i][j]);
        }
        puts("");
    }
 //busqueda dicotomica

    do{
        printf("Introdue el valor que quieres buscar (FIN=0): ");
        scanf("%d", &x);
        if(x==0){
            break;
        }
        //busqueda binaria o dicotomica
        izq=1;
        der=f; //tamaño del vector
        do{
            cen = (izq+der)/2;
            if( (x==m[cen][1]) || (izq>=der) ){
                break;
            }
            if(x>m[cen][1]){
                der = cen -1;
            }
            else{

                izq = cen +1;
            }
        }while(1);
        if(x==m[cen][1]){
            printf("El valor %d esta en la fila %d\n", x, cen);
        }
        else{
            printf("No encontrado\n");
        }
    }while(x!=0);
return 0;
}



