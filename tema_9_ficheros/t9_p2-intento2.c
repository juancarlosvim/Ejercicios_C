#include <stdio.h>
#include <conio.h>
#include <string.h>

typedef struct
{
    char autor[30];
    char titulo[30];
    char editorial[15];
    int anEdicion;
    int nPaginas;
    float precio;
}biblioteca;


typedef struct
{
    long int num_registros; // mide 4
    char blancos[84];
}primer_registro;

int main()
{
    printf("El tamanio de la estructura de biblioteca es %d\n", sizeof(biblioteca)); //88
    printf("El tamanio de la estructura de primer_registro es %ld\n", sizeof(primer_registro)); //88 tienen que tener el mismo tamanio

}
