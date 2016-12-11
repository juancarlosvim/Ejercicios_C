#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>

typedef struct
{
    char nombre[25];
    char telefono[10];
    int edad;
}agenda;

FILE *P1;
FILE *P2;

void altas(void);
void listados(void);
void consultas(void);
void bajas(void);
void modificaciones(void);

int main()
{
    int seleccion;
    do{
       getch();
        system("cls");


        printf("----Mantenimiento----\n");
        printf("1 - Altas\n");
        printf("2 - Listados\n");
        printf("3 - Consultas\n");
        printf("4 - Bajas\n");
        printf("5 - Modificaciones\n");
        printf("0 - Salir\n");
        printf("Introduce una de las opciones => \n");
        scanf("%d", &seleccion);

        switch(seleccion)
        {
            case 1: altas();
            break;
            case 2: listados();
            break;
            case 3: consultas();
            break;
           /* case 4: bajas();
            break;*/
            case 0: printf("Adios\n");
            break;
            default:
                printf("Opcion incorrecta\n");

        }

    }while(seleccion != 0);
return 0;
}

void altas(void)
{
    char c;
    agenda agenda1;

    P1 = fopen("AGENDA.SEC", "ab");
    system("cls");
    do{
    printf("Introduce un nombre => \n");
    fflush(stdin);
    scanf("%s", agenda1.nombre);
    printf("Introduce un telefono => \n");
    fflush(stdin);
    scanf("%s", agenda1.telefono);
    printf("Introduce la edad => \n");
    fflush(stdin);
    scanf("%d", &agenda1.edad);

    fwrite(&agenda1, sizeof(agenda1), 1, P1);
    printf("Quieres seguir annadiendo nuevas altas? (s/n) => \n");
    }while(getchar() == 's');
    fclose(P1);
}

void listados(void)
{
    agenda agenda1;
    P1 = fopen("AGENDA.SEC", "rb");
    system("cls");
    if(P1 == NULL)
    {
        printf("No hay registros");
        fclose(P1);
        return;
    }
    printf("Listado:(pusle cualquier tecla para salir)\n");
    while(fread(&agenda1, sizeof(agenda1),1, P1)== 1)
        printf("Nombre => %s\n Telefono => %s\n Edad => %d \n", agenda1.nombre, agenda1.telefono, agenda1.edad);
    fclose(P1);
}

void consultas(void)
{
  char c;
  char buscar[30];
  int sw;

  agenda agenda1;
  system("cls");
  do{
    printf("Introduce el nombre a buscar (FIN para salir) => \n");
    fflush(stdin);
    scanf("%s", buscar);
    if(strcmp(buscar, "FIN"))
    {
        P1 = fopen("AGENDA.SEC", "rb");
        if(P1 == NULL)
        {
            printf("No hay registros");
            fclose(P1);
            return;
        }
        sw =0;
        while(fread(&agenda1, sizeof(agenda1), 1, P1)==1)
        {
            if(!strncmp(agenda1.nombre, buscar, strlen(buscar)))
            {
                printf("Nombre => %s\n Telefono => %s\n Edad => %d\n", agenda1.nombre, agenda1.telefono, agenda1.edad);
                sw =1;
            }
        }

        fclose(P1);
        if(sw==0){
            printf("No encontrado\n");
        }
    }

    printf("Continuar buscando? (s/n) => \n");


  }while(getchar() == 's');
}
