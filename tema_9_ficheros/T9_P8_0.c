#include <stdio.h>
#include <conio.h>
#include <string.h>

typedef struct
{
    char nCuenta[10];
    char nombre[25];
    char clave[8];
    float saldo;
    float retPermitida;
}banco;

void altas();
void listados();


int main()
{
    int opcion;

    do{
        printf("----Mantenimiento----\n");
        printf("1. Altas\n");
        printf("2. Listado\n");
        printf("0. Salir\n");

        printf("Elegir opcion => ");
        scanf("%d", &opcion);
        switch(opcion)
        {
            case 1: altas();
            break;
            case 2: listados();
            break;
            case 0: printf("Bye!\n");
            break;
            default: printf("Opcion incorrecta");
        }

    }while(1);
}

void altas(void)
{
    banco alt;
    FILE *P1_banco;

    P1_banco =fopen("CAJERO.DAT","ab");

    do{
        printf("Introduce numero de cuenta (fin para salir) => ");
        fflush(stdin);
        gets(alt.nCuenta);
        if(strcmp(alt.nCuenta, "fin")==0)
        {
            break;
        }

        printf("Introduce nombre => ");
        fflush(stdin);
        gets(alt.nombre);

        printf("Introduce la clave => ");
        fflush(stdin);
        gets(alt.clave);

        printf("Introduce el saldo => ");
        fflush(stdin);
        scanf("%f", &alt.saldo);

        printf("Introduce la cantidad que quiere retirar => ");
        fflush(stdin);
        scanf("%f", &alt.retPermitida);

    }while(1);
}


void listados(void)
{
    FILE *P1_banco;
    banco list;

    P1_banco =fopen("CAJERO.DAT", "rb");

    while(fread(&list, sizeof(list), 1, P1_banco)==1)
    {
        printf("Numero de cuenta => %s\n",list.nCuenta);
        printf("Nombre => %s\n",list.nombre);
        printf("Clave => %s\n",list.clave);
        printf("Saldo => %s\n",list.saldo);
        printf("Retirada permitida => %s\n",list.retPermitida);
    }
}
