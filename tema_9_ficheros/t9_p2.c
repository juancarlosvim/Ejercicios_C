#include <stdio.h>
#include <string.h>
#include <conio.h>

typedef struct
{
    char autor[30];
    char titulo[30];
    char editorial[15];
    int anedicion;
    int npaginas;
    float precio;

}biblioteca;

void altas();
void listado();

int main()
{
    biblioteca biblioteca1;
    int seleccion;
    //tamaño de la estructura
    //printf("%d",sizeof(biblioteca1)); //88

    while(seleccion!=0)
    {
        system("cls");
        printf("----MENU----\n");
        printf("[1] Altas \n");
        printf("[2] Listado \n");
        printf("[0] Salir \n");

        printf("Eliga alguna opcion => ");

        scanf("%d", &seleccion);
        switch(seleccion)
        {
            case 1: altas();
            break;
            case 2: listado();
            break;
            case 0: printf("Bye!");
            break;
            default: printf("Opcion incorrecta \n");
        }
    }

    return 0;
}

void altas(void)
{
     biblioteca rg;
     FILE *p1;

    p1 = fopen("BIBLIOTECA.DAT", "ab");
    system("cls");

    do{
        printf("Introduce un autor (fin para salir) => ");
        fflush(stdin);
        gets(rg.autor);
        if(strcmp(rg.autor, "fin")==0)
        {
            break;
        }

        printf("Introduce el titulo => ");
        fflush(stdin);
        gets(rg.titulo);

        printf("Introduce la editorial => ");
        fflush(stdin);
        gets(rg.editorial);

        printf("Introduce el anno de edicion => ");
        fflush(stdin);
        scanf("%d", &rg.anedicion);

        printf("Introduce el numero de paginas => ");
        fflush(stdin);
        scanf("%d", &rg.npaginas);

        printf("Introduce el precio => ");
        fflush(stdin);
        scanf("%f", &rg.precio);

        fwrite(&rg,sizeof(rg),1,p1);


    }while(1);

    fclose(p1);

}


void listado(void)
{
    biblioteca rg;
    FILE *p1;

    p1 = fopen("BIBLIOTECA.DAT","rb");

    while(fread(&rg, sizeof(rg),1,p1)==1)
    {
        system("cls");
        printf("Autor => %s\n", rg.autor);
        printf("Titulo => %s\n", rg.titulo);
        printf("Editorial => %s\n", rg.editorial);
        printf("Anno de edicion => %d\n", rg.anedicion);
        printf("Numero de paginas => %d\n", rg.npaginas);
        printf("Precio => %.2f\n", rg.precio);
        getch();
    }

    fclose(p1);
}
