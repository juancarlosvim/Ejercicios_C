#include <stdio.h>
#include <ctype.h>

int main()
{
    char cadena[80];
    int i=0;

    printf("Introduzca una cadena de texto \n");
    gets(cadena);
    while(cadena[i] != '\0')
    {
        if( (0 !=islower(cadena[i])) ){
            cadena [i] = cadena[i] -32;
            printf("%c", cadena[i]);
        }
        i++;
    }
return 0;
}
