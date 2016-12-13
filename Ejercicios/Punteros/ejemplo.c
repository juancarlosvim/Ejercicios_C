#include <stdio.h>

int main()
{
    char *puntero;
    char variable;
    variable = 5;
    puntero = &variable;
    printf("Variable contiene %d\n", variable);
    printf("La direccion de variable es %p\n", &variable);
    printf("El valor que contiene puntero es %d\n", puntero);
    printf("La direccion de puntero es %p \n", puntero);

    *puntero = 2;

}
