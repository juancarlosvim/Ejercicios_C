#include <stdio.h>
#include <stdlib.h>

int main()
{
    char cadena[10], cadena2[10];
    float numero;

    printf("Introduce un entero con signo => ");
    gets(cadena);
    printf("Introduce un entero con signo => ");
    gets(cadena2);
    numero = atof(cadena)+ atof(cadena2);
    printf("La suma de los dos numeros es: %.2f", numero);
return 0;
}
