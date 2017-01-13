#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>

typedef struct
{
    char nombre[25];
    int edad;
    char estudios[20];
}curriculum;

typedef struct
{
    long int nRegistros;
    char blancos[sizeof(curriculum)-4]; //48
}primer_registro;

void altas();
void listados();

int main()
{
    //printf("%d\n",sizeof(curriculum));
    //printf("%d\n",sizeof(primer_registro));
    long int n=0, desplazamiento;
    int k;
    int i;
    int seleccion;
    curriculum curriculum1;
    primer_registro registro0;

    FILE *puntero;

    puntero = fopen("CURRICULUM.DAT", "rb");
    if(puntero ==NULL)
    {
        printf("Archivo vacio\n");
        getch();
        system("cls");
        printf("Archivo creado\n");
        getch();
        puntero = fopen("CURRICULUM.DAT", "w+b");

        registro0.nRegistros =76;
        for(k=0;k<48;k++)
        {
            registro0.blancos[k]=' ';
        }
        fseek(puntero, 0L, 0);
        fwrite(&registro0, sizeof(registro0), 1, puntero);
        curriculum1.nombre[0]='*';
        for(i=1;i<=76;i++)
        {
            desplazamiento = i*sizeof(curriculum1);
            fseek(puntero, desplazamiento, 0);
            fwrite(&curriculum1, sizeof(curriculum1), 1, puntero);
        }
    }
    fclose(puntero);
    do{
        system("cls");

        printf("----MANTENIMIENTO----\n");
        printf("1) Altas \n");
        printf("2) Listados \n");
        printf("0) Salir \n");

        printf("Elige alguna opcion => ");
        scanf("%d", &seleccion);
        if(seleccion==0)
        {
            printf("Bye!!!\n");
            break;
        }
        switch(seleccion)
        {
        case 1:
            {
                altas();
                break;
            }
        case 2:
            {
                listados();
                break;
            }
        default:
            {
                printf("Opcion incorrecta\n");
                break;
            }
        }

    }while(1);
}

void altas(void)
{
    long int n=0, desplazamiento;
    char nombreaux[25];
    char estudiosaux[20];
    int edadaux;
    int direccion;
    int longitud;
    int i, k;
    int d1, d2, d3;
    int respuesta;

    curriculum curriculum1;
    primer_registro registro0;

    FILE *puntero;

    puntero = fopen("CURRICULUM.DAT", "r+b");



    do{
        fseek(puntero, 0L, 0);
        fread(&registro0, sizeof(registro0), 1, puntero);
        n = registro0.nRegistros;

        system("cls");
        printf("Introduce el nombre (FIN para salir) => ");
        fflush(stdin);
        gets(nombreaux);
        longitud = strlen(nombreaux);
        for(i=0;i<=longitud;i++)
        {
            nombreaux[i] = toupper(nombreaux[i]);
        }
        if(strcmp(nombreaux, "FIN")==0)
        {
            continue;
        }


        printf("Edad => ");
        fflush(stdin);
        scanf("%d", &edadaux);

        printf("Estudios => ");
        fflush(stdin);
        gets(estudiosaux);
        for(i=0;i<=longitud;i++)
        {
            estudiosaux[i] = toupper(estudiosaux[i]);
        }
        d1 =nombreaux[0];
        d2 = nombreaux[1];
        d3 = nombreaux[2];
        direccion = d1+d2+d3-194;
        //printf("Direccion => %d\n", direccion);
        do{

            desplazamiento = direccion *sizeof(curriculum1);
            fseek(puntero, desplazamiento, 0);
            fread(&curriculum1, sizeof(curriculum1), 1, puntero);

            if(curriculum1.nombre[0]=='*' || curriculum1.nombre[0]=='$')
            {
                strcpy(curriculum1.nombre, nombreaux);
                curriculum1.edad = edadaux;
                strcpy(curriculum1.estudios, estudiosaux);

                fseek(puntero, desplazamiento, 0);
                fwrite(&curriculum1, sizeof(curriculum1), 1, puntero);
                break;
            }
            else
            {
                direccion = direccion +1;
            }
        }while(direccion <=n);

        if(direccion>n)
        {
            registro0.nRegistros = direccion;
            for(k=0;k<48;k++)
            {
                registro0.blancos[k]=' ';
            }
            fseek(puntero, 0L, 0);
            fwrite(&registro0, sizeof(registro0), 1, puntero);

            strcpy(curriculum1.nombre, nombreaux);
            curriculum1.edad = edadaux;
            strcpy(curriculum1.estudios, estudiosaux);

            desplazamiento= direccion* sizeof(curriculum1);
            fseek(puntero, desplazamiento, 0);
            fwrite(&curriculum1, sizeof(curriculum1), 1, puntero);
        }

        printf("Desea insertar mas registros? (s/n) => ");

    }while(getchar()=='s'|| getchar()=='S');

    fclose(puntero);


}

void listados(void)
{
    long int n=0, desplazamiento;
    int i;

    curriculum curriculum1;
    primer_registro registro0;

    FILE *puntero;

    puntero = fopen("CURRICULUM.DAT", "r+b");

    system("cls");
    fseek(puntero, 0L, 0);
    fread(&registro0, sizeof(registro0), 1, puntero);
    n = registro0.nRegistros;
    for(i=1;i<=n;i++)
    {
        desplazamiento = i*sizeof(curriculum1);
        fseek(puntero, desplazamiento, 0);
        fread(&curriculum1, sizeof(curriculum1), 1, puntero);
        if(curriculum1.nombre[0] !='*' && curriculum1.nombre[0] !='$')
        {
            printf("Numero de registro => %d\n", i);
            printf("Nombre => %s\n", curriculum1.nombre);
            printf("Edad => %d\n", curriculum1.edad);
            printf("Estudios => %s\n", curriculum1.estudios);
            getch();
        }

    }
    fclose(puntero);



}
