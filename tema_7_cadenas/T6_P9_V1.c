#include<stdio.h>
#include<string.h>

int main()
{
    char cadena[11][15];
    char aux[15],buscar[15];
    int d,i,j,sw,izq,der,cen;

    for(i=1;i<=10;i++){
            printf("Introduce el nombre %d:\n", i);
            scanf("%s",cadena[i]);
    }
    puts("");
    printf("\nListado de nombres:\n");
    for(i=1;i<=10;i++){
            printf("%s\n",cadena[i]);
    }
    //Metodo Shell.
    d=10;
    while(d!=1)
    {
        d=d/2;
        sw=1;
        while(sw==1)
        {
            sw=0;
            for(i=1;i<=10-d;i++)
            {
               if(strcmp(cadena[i],cadena[i+d])>0)
               {
                   strcpy(aux,cadena[i+d]);
                   strcpy(cadena[i+d],cadena[i]);
                   strcpy(cadena[i],aux);
                   sw=1;
               }
            }
        }
    }
    puts("");
    printf("\nListado de nombres ordenado:\n");
    for(i=1;i<=10;i++){
            printf("%s",cadena[i]);
            printf("\n");
    }

    //busqueda dicotomica
    do{
            izq= 1;
            der = 10;
            printf("Introduce un nombre a buscar => ");
            fflush(stdin);
            gets(buscar);
            if(strcmp(buscar, "fin")==0){
                break;
            }
            while(1)
            {
                cen =(izq +der ) /2;
                if(izq > der){
                    printf("El nombre %s no se ha encontrado", buscar);
                    break;
                }
                if(strcmp(buscar, cadena[cen])==0)
                {
                    printf("SE HA ENCONTRADO el nombre %s  EN LA POSCION %d\n", buscar, cen);
                    break;
                }
                if(strcmp(buscar, cadena[cen])>0){
                    izq = cen +1;
                    continue;
                }
                else{
                    der = cen -1;
                    continue;
                }
            }


    }while (1);

return 0;

}
