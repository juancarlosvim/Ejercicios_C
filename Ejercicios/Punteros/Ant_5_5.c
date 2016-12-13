#include <stdio.h>

int main()
{
    char valor;
    char *puntero;

    valor =97;

    //printf("tamanno de valor %d\n",sizeof(valor));
    //printf("tamanno de puntero %d\n",sizeof(puntero));

    printf("%p => %d  <= direccion y datos de valor\n", &valor, valor);
    puntero = &valor; //puntero toma la direccion de valor

    printf("%p => %d <= direccion y datos de puntero\n", &puntero, puntero);

    printf("Valor almacenado en puntero => %p\n", puntero);
    printf("Direccion del puntero => %p\n", &puntero);
    printf("Valor referenciado por pubtero => %d\n", *puntero);
}
