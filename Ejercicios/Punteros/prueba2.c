#include <stdio.h>

int main()
{
    char nombre[]= "pepe";

    char *puntero;

    puntero = nombre;

    printf("El nombre es => %s\n", puntero);

    printf("La direccion de puntero %p\n", &puntero);

    printf("Contenido de valor de puntero %p\n",  puntero);

    printf("La direccion de memoria de nombre => %p\n", &nombre);

    printf("La direccion de memoria del puntero que apunta a nombre %p\n", &*puntero);
    printf("La direccion de memoria de nombre => %p", &nombre);


}
