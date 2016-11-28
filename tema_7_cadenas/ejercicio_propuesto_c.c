#include <stdio.h>
#include <string.h>
#include <conio.h>

int main()
{
    char cadena[16][16];
    char aux[16];
    char nombre[16];
    int i, j, d, sw;

    for(i=1;i<=15;i++)
    {
        printf("Introduce el nombre %d => ", i);
        gets(cadena[i]);
    }

    //metodo shell
    d=15;

    while(d!=1)
    {
        d=d/2;
        sw =1;
        while(sw==1){
            sw =0;
            for(j=1;j<=15-d;j++)
            {
                if((strcmp(cadena[j], cadena[j+d]))>0){
                    strcpy(aux, cadena[j+d]);
                    strcpy(cadena[j+d], cadena[j]);
                    strcpy(cadena[j], aux);
                    sw =1;
                }
            }
        }
    }
    printf("\n");


    printf("La lista de nombres ordenana\n");
    for(i=1;i<=15;i++)
    {
        printf("%5s\t",cadena[i]);
    }
    printf("\n");
    printf("Los tres primeros => \n");
    for(i=1; i<=3;i++)
    {
        printf("%5s\t", cadena[i]);
    }
    printf("\n");
    printf("Los tres ultimos=> \n");
    for(i=13; i<=15;i++)
    {
        printf("%5s\t", cadena[i]);
    }
    printf("\n");
    printf("Los tres en la mitad de la lista => \n");
    for(i=7; i<=9;i++)
    {
        printf("%5s\t", cadena[i]);
    }
    printf("\n");

return 0;
}
