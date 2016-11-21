#include <stdio.h>
#include <string.h>
#include <ctype.h>


int main()
{
    char nombre[11][15];
    int i, j, aux[15], sw;

    for(i=1;i<=10;i++)
    {
        printf("Introduce el %d nombre => ", i);
        gets(nombre[i]);
    }
    for(i=1;i<=10;i++)
    {
        printf("el %d nombre es = %s \n", i, nombre[i]);
    }
    //ordenar metodo de la burbuja
    for(i=0;i<=9;i++)
    {
        sw =0;
        for(j=0;j<=9-i;j++)
        {
            if(strcmp(nombre[i], nombre[j+1])>0){
                sw =1;
                strcpy(aux, nombre[j-1]);
                strcpy(nombre[j-1], nombre[j]);
                strcpy(nombre[j], aux);
            }
        }
        if(sw==0){
            break;
        }
    }
    puts("");
    for(i=0;i<=9;i++)
    {
        printf("el %d nombre es = %s \n", i, nombre[i]);
    }
return 0;
}
