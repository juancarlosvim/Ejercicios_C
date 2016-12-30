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

// FUNCIONES //
void altas();
void listado();


int main()
{
    biblioteca biblioteca1;
    primer_registro registro0;
    FILE *p1;
    int seleccion;
    int k;
    //printf("El tamanio de la estructura de biblioteca es %d\n", sizeof(biblioteca)); //88
    //printf("El tamanio de la estructura de primer_registro es %ld\n", sizeof(primer_registro)); //88 tienen que tener el mismo tamanio

    p1 = fopen("BIBLIOTECA.DAT", "rb");
    if(p1 == NULL)
    {
        printf("Fichero biblioteca esta vacio\n");
        getch();
        system("cls");
        p1 = fopen("BIBLIOTECA.DAT", "a+b");
        printf("Fichero biblioteca creado\n");
        getch();

        fseek(p1, 0L, 0);
        registro0.num_registros = 0L;
        for(k=0;k<84;k++)
        {
            registro0.blancos[k]= ' ';
        }
        fwrite(&registro0, sizeof(registro0), 1, p1);
    }
    fclose(p1);


    do{
        system("cls");
        printf("----MANTENIMIENTO----\n");
        printf("[1] Altas \n");
        printf("[2] Listado \n");
        /*printf("[3] Consultas \n");
        printf("[4] Modificaciones \n");
        printf("[5] Bajas \n");*/
        printf("[0] Salir \n");
        printf("Elige una opcion => ");
        scanf("%d", &seleccion);

        if(seleccion == 0)
        {
            printf("Bye!! \n");
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
                    listado();
                    break;
                }
            default:
                {
                    printf("Opcion incorrecta \n");
                    break;
                }
        }
    }while(1);

}

void altas(void)
{
  long int n;
  long int desplazamiento;
  int k;

  biblioteca biblioteca1;
  primer_registro registro0;
  FILE *p1;

    p1 = fopen("BIBLIOTECA.DAT","r+b");
    fseek(p1, 0L, 0);
    fread(&registro0, sizeof(registro0), 1, p1);
    n = registro0.num_registros;


    do{
        n = n+1;
        system("cls");
        printf("Numero de registro => %ld\n", n);
        printf("Introduce el autor (fin para salir) => ");
        fflush(stdin);
        gets(biblioteca1.autor);
        if(strncmp(biblioteca1.autor, "fin", 3)==0)
        {
            break;
        }
        printf("Introduce el titulo => ");
        fflush(stdin);
        gets(biblioteca1.titulo);
        printf("Introduce la editorial => ");
        fflush(stdin);
        gets(biblioteca1.editorial);
        printf("Introduce el anio de edicion => ");
        fflush(stdin);
        scanf("%d", &biblioteca1.anEdicion);
        printf("Introduce el numero de paginas => ");
        fflush(stdin);
        scanf("%d", &biblioteca1.nPaginas);
        printf("Introduce el precio => ");
        fflush(stdin);
        scanf("%f", &biblioteca1.precio);

        desplazamiento = n*sizeof(biblioteca1);
        fseek(p1, desplazamiento, 0);
        fwrite(&biblioteca1, sizeof(biblioteca1), 1, p1);

        printf("Desea aniadir mas libros? (s/n) => ");
        fflush(stdin);

    }while(getchar() == 's' || getchar() == 'S');

    desplazamiento = 0L * sizeof(registro0);
    fseek(p1, desplazamiento, 0);
    registro0.num_registros = n;
    for(k=0;k<84;k++)
    {
        registro0.blancos[k] = ' ';
    }
    fwrite(&registro0, sizeof(registro0), 1, p1);
    fclose(p1);
}

void listado(void)
{
    long int n;
    long int desplazamiento;
    int i;

    biblioteca biblioteca1;
    primer_registro registro0;
    FILE *p1;

    p1 = fopen("BIBLIOTECA.DAT", "rb");

    fseek(p1, 0L, 0);
    fread(&registro0, sizeof(registro0), 1, p1);

    n = registro0.num_registros;

    system("cls");
    printf("Hay %ld registros \n", n);
    getch();
    for(i=1;i<=n;i++)
    {
        desplazamiento = i*sizeof(biblioteca1);
        fseek(p1, desplazamiento, 0);
        fread(&biblioteca1, sizeof(biblioteca1), 1, p1);

        printf("Numero de registro => %d\n", i);
        printf("Autor => %s \n", biblioteca1.autor);
        printf("Titulo => %s \n", biblioteca1.titulo);
        printf("Editorial => %s \n", biblioteca1.editorial);
        printf("Anio de edicion => %d \n", biblioteca1.anEdicion);
        printf("Numero de paginas => %d \n", biblioteca1.nPaginas);
        printf("Precio => %.2f\n", biblioteca1.precio);

        getch();
        fclose(p1);
    }

}
