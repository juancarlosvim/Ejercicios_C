#include <stdio.h>
#include <ctype.h>

int main()
{
    char cadena[10], cadena2[10];
    long numero;

    printf("Introduce un entero con signo => ");
    gets(cadena);
    printf("Introduce un entero con signo => ");
    gets(cadena2);
    numero = atol(cadena)+ atol(cadena2);
    printf("La suma de los dos numeros es: %ld", numero);
return 0;
}
