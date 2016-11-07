#include <stdio.h>
#include <stdlib.h>
//VECTOR ORDENADOS CON ELEMENTOS NO REPETIDOS BÚSQUEDA DICOTÓMICA
int main(){
    int i,j,sw,aux,x,izq,der,cent,n;

    srand(time(NULL));
    printf("Introduce la dimension del vector\n");
    scanf("%d", &n);
    int v[n];

    for(i=0;i<n;i++){
        v[i]= rand()%1000+1;
    }

    for(j=0;j<n-1;j++){
        sw=0;
        for(i=0;i<(n-1)-j;i++){
            if (v[i]>v[i+1]){
                aux=v[i];
                v[i]=v[i+1];
                v[i+1]=aux;
                sw=1;
            }
        }
        if(sw==0)
        break;
    }

    for(i=0;i<n;i++){
        printf("%d\t", v[i]);
    }

    puts("");
    do{
        scanf("%d", &x);
        if(x==0){
            break;
        }
        else if(x!=0){
            izq=0;
            der=n-1;
            do{
                cent=(izq+der)/2;
                if(x==v[cent] || izq>=der){
                    if(x==v[cent]){
                        printf("La posicion del numero es %d\n",cent);
                        break;
                    }else{
                         printf("No encontrado\n");
                         break;
                    }
                }else
                    if(x>v[cent]){
                        izq=cent+1;
                    }
                    else
                        der=cent-1;
            }while(1);
        }
    }while (x!=0);

return 0;
}


