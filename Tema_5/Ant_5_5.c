#include <stdio.h>

int main()
{
    char valor; // Una posicion de memoria para guardar un carácter.
    char *puntero; // un puntero

    valor = 97;
    printf("%p => | %d | <= direccion y datos de valor\n", &valor, valor);
    puntero = &valor; //puntero vale la posicion de valor
    printf("%p => | %p | <= direccion y datos de puntero\n", &puntero, puntero);
    printf("Valor almacenado en puntero = %p\n", puntero);
    printf("Direccion de puntero: &puntero = %p\n", &puntero);
    printf("Valor referenciado por puntero: *puntero = %d\n", *puntero);
}
