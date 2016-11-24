#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main()
{
    char palabra[11][30], mayorN[30], menorN[30];
    int i, longitud, mayor = 0, menor =30;

    for(i=0;i<=9;i++)
    {
        printf("Introduce %d nombre => ", i+1);
        fflush(stdin);
        gets(palabra[i]);
        longitud= strlen(palabra[i]);
        if(longitud>=mayor){
            mayor = longitud;
            strcpy(mayorN, palabra[i]);
        }
        if(longitud<=menor)
        {
            menor = longitud;
            strcpy(menorN, palabra[i]);
        }

    }
    printf("La palabra con mas caracteres es %s con %d caracteres\n", mayorN, mayor);
    printf("La palabra con menos caracteres es %s con %d caracteres\n", menorN, menor);

return 0;
}
