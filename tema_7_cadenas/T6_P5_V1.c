#include <stdio.h>
#include <string.h>

int main()
{
    char cadena[80], cadena2[80];

    printf("Introduce un nombre => ");
    gets(cadena);
    printf("Introduce otro nombre => ");
    gets(cadena2);
    if(strcmp(cadena, cadena2)> 0)
    {
        printf("%s | es mayor que | %s", cadena, cadena2);

    }
    else{
        printf("%s | es mayor que | %s", cadena, cadena2);
    }
return 0;
}
