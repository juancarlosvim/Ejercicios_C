#include <stdio.h>
#include <conio.h>
#include <string.h>

typedef struct
{
    char cod_vendendor[5];
    char cif[12];
    char nombre_vendedor[25];
    char direccion_vendedor[25];
    char cod_postal[5];
}Vendedores;

typedef struct
{
    long int nRegistros; //mide 4
}primer_registro;

int main()
{
    printf("El tamanio de vendedores es %d\n", sizeof(Vendedores)); //87
}
