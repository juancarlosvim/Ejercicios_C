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

typedef struct
{
    long nreg;
    char blancos[60];
}cero;

int i;

void altas();
void listado();

int main()
{
    biblioteca biblioteca1;
    cero c;
    FILE *p1;
    int seleccion;
    int i;
    //tamaño de la estructura
    //printf("%d",sizeof(biblioteca1)); //88

    p1 = fopen("BIBLIOTECA.DAT", "rb");
    if(p1 == NULL)
    {
        printf("El archivo esta vacio\n");
        getch();
        system("cls");
        p1 = fopen("BIBLIOTECA.DAT", "a+b");
        printf("Archivo creado \n");
        getch();

        fseek(p1, 0L, 0);
        c.nreg=0L;
        for(i=0;i<=60;i++)
        {
            c.blancos[i] = ' ';
        }
    }
    fwrite(&c, sizeof(c),1, p1);
    fflush(p1);
    fclose(p1);

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
    long int n = 0; // numero de registros
    long int desplazamiento;
    system("cls");
    biblioteca rg;
    cero c;
    FILE *p1;

    p1 = fopen("BIBLIOTECA.DAT", "r+b");
    fseek(p1, 0L, 0);
    fread(&c, sizeof(c), 1, p1);
    n= c.nreg;
    do{

        n = n+1;
        system("cls");
        printf("Registro numero %ld:\n", n);
        fflush(stdin);
        printf("Introduce un autor => ");
        fflush(stdin);
        gets(rg.autor);
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
        fflush(stdin);

        desplazamiento = n*sizeof(rg); //calcular desplazamiento
        fseek(p1, desplazamiento, 0); //colocarse
        fwrite(&rg,sizeof(rg),1,p1);
        fflush(stdin);
        printf("Desea introducir otro registro? (s/n) ");
    }while(getchar()== 's');

    desplazamiento = 0L*sizeof(c);
    fseek(p1, desplazamiento, 0);
    c.nreg = n;
    for(i=0;i<60;i++)
    {
        c.blancos[i]=' ';
    }
    fwrite(&c, sizeof(c), 1, p1);

    fflush(p1);
    fclose(p1);

}


void listado(void)
{
    long int n=0, desplazamiento;

    biblioteca rg;
    cero c;
    FILE *p1;

    p1 = fopen("BIBLIOTECA.DAT","rb");
    fseek(p1, 0L, 0);
    fread(&c, sizeof(c), 1, p1);
    n = c.nreg;
    printf("Numero de registros: %d", n);
    getch();

    for(i=1;i<=n;i++)
    {
        system("cls");
        desplazamiento=i*sizeof(rg);
        fseek(p1, desplazamiento, 0);
        fread(&rg, sizeof(rg),1,p1);
        printf("Autor => %s\n", rg.autor);
        printf("Titulo => %s\n", rg.titulo);
        printf("Editorial => %s\n", rg.editorial);
        printf("Anno de edicion => %d\n", rg.anedicion);
        printf("Numero de paginas => %d\n", rg.npaginas);
        printf("Precio => %.2f\n", rg.precio);
        getch();
    }
    fflush(p1);
    fclose(p1);
}
