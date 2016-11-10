#include <stdio.h>
#include <stdlib.h>
#define n 100
void posicion(int, int, int[]);  //funcion para la busqueda dicotomica
int main()
{
    int v[n+1];
    int i, izq, der, sw, aux, cen, x;

    srand(time(NULL));
    for(i=1;i<=n;i++) //imprimo vector de 100 numeros
    {
        v[i]=rand()%1001+1000;
        printf("%4d\t", v[i]);
    }
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
    printf("Nuestro vector ordenador por el metodo de la sacudida\n");
    for(i=1;i<=n;i++)
    {
        printf("%4d\t", v[i]);
    }

    puts("");
    //busqueda dicotomica

    do{
        printf("Introdue el valor que quieres buscar (FIN=0): ");
        scanf("%d", &x);
        if(x==0){
            break;
        }
        //busqueda binaria o dicotomica
        izq=1;
        der=n;
        do{
            cen = (izq+der)/2;
            if( (x==v[cen]) || (izq>=der) ){
                break;
            }
            if(x>v[cen]){
                izq = cen +1;
            }
            else{
                der = cen -1;
            }
        }while(1);
        if(x==v[cen]){
            posicion(x,cen,v);
        }
        else{
            printf("No encontrado\n");
        }
    }while(x!=0);
return 0;
}

void posicion(int x, int cen, int v[n+1])
{
    int i, inicio, fin;

    inicio = cen;
    fin =cen;
    do{
        inicio = inicio -1;
        if(inicio==0){
            break;
        }
    }while(v[inicio]==x);
    inicio = inicio +1;
    do{
        fin = fin +1;
        if(fin>n){
            break;
        }
    }while(v[fin]==x);
    fin = fin -1;
    for(i=inicio;i<=fin;i++)
    {
        printf("%d en la posicion %d\n", v[i], i);
    }
}
