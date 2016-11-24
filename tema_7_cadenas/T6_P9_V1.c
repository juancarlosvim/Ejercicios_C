#include<stdio.h>
#include<string.h>

int main()
{
    char cadena[11][15];
    char aux[15],nombre[15];
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
    //Busqueda Dicotomica
    while(1){
        printf("\nIntroduce un nombre.\n");
        fflush(stdin);
        gets(nombre);
        if(strncmp(nombre,"fin",3)==0)
            break;
        izq=1;
        der=10;
        while(strncmp(nombre,"fin",3)!=0){
            cen=(izq+der)/2;
            if((strcmp(cadena[cen],nombre)==0)||(izq>=der)){
                if(strcmp(nombre,cadena[cen])==0){
                    printf("El nombre %s se ha encontrado en la posicion %d",cadena[cen],cen);
                    break;
                }
                else{
                    printf("Nombre no encontrado.\n");
                    break;
                }
            }
            else{
                if(strcmp(nombre,cadena[cen])>0)
                    izq=cen+1;
                else
                    der=cen-1;

            }
        }
    }
return 0;
}
