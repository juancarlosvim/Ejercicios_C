#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char v[10][15], nombre[15], aux[15];
    int i, j, sw;

    for(i=0;i<10;i++)
    {
        printf("Introduce el %d nombre => ", i+1);
        gets(nombre);
        strcpy(v[i], nombre);
    }
    for(i=0;i<10;i++)
    {
        //printf("el %d nombre es = %s \n", i, nombre[i]);
    }
    //ordenar metodo de la burbuja
    for(i=0;i<9;i++)
    {
        sw =0;
        for(j=0;j<9-i;j++)
        {
            if(strcmp(v[j], v[j+1])>0){

                strcpy(aux, v[j]);
                strcpy(v[j], v[j+1]);
                strcpy(v[j+1], aux);
                sw =1;
            }
        }
        if(sw==0){
            break;
        }
    }
    puts("");
    for(i=0;i<10;i++)
    {
        printf("%d - %s\n", i, v[i]);
    }
return 1;
}

