#include <stdio.h>

int main()
{
    char numero = 6;

    char *puntero;

    puntero = &numero;

    printf("EL contenido puntero %d\n", numero);
    printf("Direccion de memoria de puntero %p\n", &puntero);

    printf("Direccion de contenido de puntero %p\n", puntero);

    printf("Direccion de memoria numero %p\n", &numero);

    printf("Direccion que apunta puntero a numero %p\n", &*puntero);

    printf("El puntero donde apunta a nombre su contenido es %d\n", *puntero);



    *puntero = 8;

    printf("El contenido de puntero es %d\n", numero);
}
