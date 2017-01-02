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
    long int nRegistros; //long int mude 4
    char blancos[84];
}primer_registro;

//********* FUNCIONES *********
void altas();
void listados();
void consultas();
void modificaciones();
void bajas();
void ordenar();

int main()
{
    int k;
    int seleccion;
    biblioteca biblioteca1;
    primer_registro registro0;
    FILE *p1;
    p1 = fopen("BIBLIOTECA.JC", "rb");
    if(p1==NULL)
    {
        printf("Archivo vacio\n");
        getch();
        system("cls");
        p1 = fopen("BIBLIOTECA.JC", "a+b");
        printf("Archivo creado\n");
        fseek(p1, 0L, 0);
        registro0.nRegistros =0L;
        for(k=0;k<84;k++)
        {
            registro0.blancos[k]=' ';
        }
        fwrite(&registro0, sizeof(registro0), 1, p1);
        printf("Numero de registro n vale %d\n", registro0.nRegistros);
        getch();
    }
    fclose(p1);

    /*long int d;
    printf("\nEl tamanio de biblioteca es %d", sizeof(biblioteca)); //88
    printf("\nEl tamanio de primer registro es %d", sizeof(primer_registro)); //88
    printf("\nel tamanio de long int es %d", sizeof(d)); //4 */

    do{
        system("cls");
        printf("----MANTENIMIENTO----\n");
        printf("1) ALTAS\n");
        printf("2) LISTADOS\n");
        printf("3) CONSULTAS\n");
        printf("4) MODIFICACIONES\n");
        printf("5) BAJAS\n");
        printf("0) SALIR\n");
        printf("Elige una opcion => ");
        scanf("%d", &seleccion);

        if(seleccion==0)
        {
            printf("Bye!!!!!!\n");
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
            case 3:
                {
                    consultas();
                    break;
                }
            case 4:
                {
                    modificaciones();
                    break;
                }
            case 5:
                {
                    bajas();
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
    long int n =0;
    long int desplazamiento;
    int k;

    biblioteca biblioteca1;
    primer_registro registro0;
    FILE *p1;

    p1 = fopen("BIBLIOTECA.JC", "r+b");
    fseek(p1, 0L, 0);
    fread(&registro0, sizeof(registro0), 1, p1);
    n = registro0.nRegistros;

    do{
        n = n+1;
        system("cls");
        printf("Introduce el autor => ");
        fflush(stdin);
        gets(biblioteca1.autor);
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

        printf("Libro registrado\n");
        fflush(stdin);
        printf("Quiere introducir mas libros? (s/n)=> ");
    }while(getchar()=='s' || getchar() == 'S');

    fseek(p1, 0L, 0);
    registro0.nRegistros = n;
    for(k=0;k<84;k++)
    {
        registro0.blancos[k]=' ';
    }
    fwrite(&registro0, sizeof(registro0), 1, p1);
    fclose(p1);
    ordenar();
}


void listados(void)
{
    long int n;
    long int desplazamiento;
    int i, k;
    biblioteca biblioteca1;
    primer_registro registro0;
    FILE *p1;
    system("cls");
    p1 = fopen("BIBLIOTECA.JC", "r+b");
    fseek(p1, 0L, 0);
    fread(&registro0.nRegistros, sizeof(registro0.nRegistros), 1, p1);
    n = registro0.nRegistros;

    printf("Numero de registros es %ld\n", n);
    getch();
    for(i=1;i<=n;i++)
    {
        desplazamiento = i*sizeof(biblioteca1);
        fseek(p1, desplazamiento, 0);
        fread(&biblioteca1, sizeof(biblioteca1),1, p1);
        if(strcmp(biblioteca1.autor, "#")==0)
        {
            continue;

        }
        else
        {
            system("cls");
            printf("Numero de registro %d \n", i);
            printf("Autor => %s\n", biblioteca1.autor);
            printf("Titulo => %s\n", biblioteca1.titulo);
            printf("Editorial => %s\n", biblioteca1.editorial);
            printf("Anio de edicion => %d\n", biblioteca1.anEdicion);
            printf("Numero de paginas => %d\n", biblioteca1.nPaginas);
            printf("Precio => %.2f\n", biblioteca1.precio);
            getch();
        }
        //printf("Autor => %s\n", biblioteca1.autor);
    }
    fclose(p1);
}

void consultas(void)
{
    long int n=0;
    long int desplazamiento;
    int seleccion;
    int i;
    int sw=0;
    int longitud;
    char buscar[20];
    long busca1;

    biblioteca biblioteca1;
    primer_registro registro0;
    FILE *p1;

    p1 =fopen("BIBLIOTECA.JC", "r+b");
    fseek(p1, 0L, 0);
    fread(&registro0, sizeof(registro0), 1, p1);

    n = registro0.nRegistros;

    while(seleccion !=0)
    {
        system("cls");
        printf("1) Nombre del autor\n");
        printf("2) Nombre del titulo\n");
        printf("3) Nombre de la editorial\n");
        printf("4) Anio de edicion\n");
        printf("5) Numero de paginas\n");
        printf("0) Salir\n");

        printf("Elige una opcion => ");
        scanf("%d", &seleccion);

        switch(seleccion)
        {
            case 1:
                {
                    do
                    {

                        system("cls");
                        printf("Introduce el autor que quieres consultar => ");
                        fflush(stdin);
                        gets(buscar);
                        longitud = strlen(buscar);
                        sw =0;
                        for(i=1;i<=n;i++)
                        {
                            desplazamiento = i* sizeof(biblioteca1);
                            fseek(p1, desplazamiento, 0);
                            fread(&biblioteca1, sizeof(biblioteca1), 1, p1);
                            if(strncmp(biblioteca1.autor, buscar, longitud)==0)
                            {
                                sw =1;
                                printf("Autor => %s\n", biblioteca1.autor);
                                printf("Titulo => %s\n", biblioteca1.titulo);
                                printf("Editorial => %s\n", biblioteca1.editorial);
                                printf("Anio de edicion => %d\n", biblioteca1.anEdicion);
                                printf("Numero de paginas => %d\n", biblioteca1.nPaginas);
                                printf("Precio => %.2f\n", biblioteca1.precio);
                                getch();

                            }
                        }
                        if(sw ==0)
                        {
                            printf("No se ha encontrado con ningun autor con este nombre => %s\n", buscar);
                        }

                        printf("Desea buscar mas autores?(s/n)=> ");
                        fflush(stdin);
                    }while(getchar()=='s'|| getchar()=='S');
                    break;
                }
            case 2:
                {

                    do
                    {

                        system("cls");
                        printf("Introduce el titulo del libro que quieres consultar => ");
                        fflush(stdin);
                        gets(buscar);
                        longitud = strlen(buscar);
                        sw =0;
                        for(i=1;i<=n;i++)
                        {
                            desplazamiento = i* sizeof(biblioteca1);
                            fseek(p1, desplazamiento, 0);
                            fread(&biblioteca1, sizeof(biblioteca1), 1, p1);
                            if(strncmp(biblioteca1.titulo, buscar, longitud)==0)
                            {
                                sw =1;
                                printf("Autor => %s\n", biblioteca1.autor);
                                printf("Titulo => %s\n", biblioteca1.titulo);
                                printf("Editorial => %s\n", biblioteca1.editorial);
                                printf("Anio de edicion => %d\n", biblioteca1.anEdicion);
                                printf("Numero de paginas => %d\n", biblioteca1.nPaginas);
                                printf("Precio => %.2f\n", biblioteca1.precio);
                                getch();

                            }
                        }
                        if(sw ==0)
                        {
                            printf("No se ha encontrado con ningun libro con ese titulo => %s\n", buscar);
                        }

                        printf("Desea buscar mas libros por sus titulos?(s/n)=> ");
                        fflush(stdin);
                    }while(getchar()=='s'|| getchar()=='S');
                    break;
                }
            case 3:
                {
                    do
                    {

                        system("cls");
                        printf("Introduce la editorial que quieres consultar => ");
                        fflush(stdin);
                        gets(buscar);
                        longitud = strlen(buscar);
                        sw =0;
                        for(i=1;i<=n;i++)
                        {
                            desplazamiento = i* sizeof(biblioteca1);
                            fseek(p1, desplazamiento, 0);
                            fread(&biblioteca1, sizeof(biblioteca1), 1, p1);
                            if(strncmp(biblioteca1.editorial, buscar, longitud)==0)
                            {
                                sw =1;
                                printf("Autor => %s\n", biblioteca1.autor);
                                printf("Titulo => %s\n", biblioteca1.titulo);
                                printf("Editorial => %s\n", biblioteca1.editorial);
                                printf("Anio de edicion => %d\n", biblioteca1.anEdicion);
                                printf("Numero de paginas => %d\n", biblioteca1.nPaginas);
                                printf("Precio => %.2f\n", biblioteca1.precio);
                                getch();

                            }
                        }
                        if(sw ==0)
                        {
                            printf("No se ha encontrado con ninguna editorial con ese nombre => %s\n", buscar);
                        }

                        printf("Desea buscar mas editoriales?(s/n)=> ");
                        fflush(stdin);
                    }while(getchar()=='s'|| getchar()=='S');
                    break;
                }
            case 4:
                {
                    do{
                        system("cls");
                        printf("Introduce el anio del libro que quieres consultar => ");
                        fflush(stdin);
                        scanf("%ld", &busca1);
                        sw =0;
                        for(i=1;i<=n;i++)
                        {
                            desplazamiento = i*sizeof(biblioteca1);
                            fseek(p1, desplazamiento, 0);
                            fread(&biblioteca1, sizeof(biblioteca1), 1, p1);
                            if(busca1 == biblioteca1.anEdicion)
                            {
                                sw =1;
                                printf("Autor => %s\n", biblioteca1.autor);
                                printf("Titulo => %s\n", biblioteca1.titulo);
                                printf("Editorial => %s\n", biblioteca1.editorial);
                                printf("Anio de edicion => %d\n", biblioteca1.anEdicion);
                                printf("Numero de paginas => %d\n", biblioteca1.nPaginas);
                                printf("Precio => %.2f\n", biblioteca1.precio);
                                getch();
                            }
                        }
                        if(sw==0)
                        {
                            printf("No se ha encontrado ningun libro con ese anio => %ld\n", busca1);
                        }
                        printf("Desea seguir buscando mas libros por anio de edicion? (s/n) => ");
                        fflush(stdin);
                    }while(getchar()=='s' || getchar()=='S');
                    break;
                }
            case 5:
                {
                    do{
                        system("cls");
                        printf("Introduce el numero de paginas del libro que quieres consultar => ");
                        fflush(stdin);
                        scanf("%ld", &busca1);
                        sw =0;
                        for(i=1;i<=n;i++)
                        {
                            desplazamiento = i*sizeof(biblioteca1);
                            fseek(p1, desplazamiento, 0);
                            fread(&biblioteca1, sizeof(biblioteca1), 1, p1);
                            if(busca1 == biblioteca1.nPaginas)
                            {
                                sw =1;
                                printf("Autor => %s\n", biblioteca1.autor);
                                printf("Titulo => %s\n", biblioteca1.titulo);
                                printf("Editorial => %s\n", biblioteca1.editorial);
                                printf("Anio de edicion => %d\n", biblioteca1.anEdicion);
                                printf("Numero de paginas => %d\n", biblioteca1.nPaginas);
                                printf("Precio => %.2f\n", biblioteca1.precio);
                                getch();
                            }
                        }
                        if(sw==0)
                        {
                            printf("No se ha encontrado ningun libro con ese numero de paginas => %ld\n", busca1);
                        }
                        printf("Desea seguir buscando mas libros por numero de paginas? (s/n) => ");
                        fflush(stdin);
                    }while(getchar()=='s' || getchar()=='S');
                    break;
                }

        }
    }
}

void modificaciones(void)
{
    long int n;
    long int desplazamiento;
    int i;
    int sw =0;
    int longitud;
    int seleccion;
    char buscar[20];
    char respuesta;
    biblioteca biblioteca1;
    primer_registro registro0;
    FILE *p1;
    system("cls");
    p1 = fopen("BIBLIOTECA.JC", "r+b");
    fseek(p1, 0L, 0);
    fread(&registro0.nRegistros, sizeof(registro0.nRegistros), 1, p1);
    n = registro0.nRegistros;

    do
    {
        system("cls");
        printf("Introduce el autor que quieres modificar (fin para salir) => \n");
        fflush(stdin);
        gets(buscar);
        if(strcmp(buscar, "fin")==0)
        {
            break;
        }
        longitud = strlen(buscar);

        sw=0;

        for(i=1;i<=n;i++)
        {
            desplazamiento = i* sizeof(biblioteca1);
            fseek(p1, desplazamiento, 0);
            fread(&biblioteca1, sizeof(biblioteca1), 1, p1);
            if(strncmp(biblioteca1.autor, buscar, longitud)==0)
            {
                sw =1;
                printf("Autor => %s\n", biblioteca1.autor);
                printf("Titulo => %s\n", biblioteca1.titulo);
                printf("Editorial => %s\n", biblioteca1.editorial);
                printf("Anio de edicion => %d\n", biblioteca1.anEdicion);
                printf("Numero de paginas => %d\n", biblioteca1.nPaginas);
                printf("Precio => %.2f\n", biblioteca1.precio);
                getch();

                printf("Quieres modificar el registro? (s/n) => ");
                scanf("%c", &respuesta);
                if(respuesta =='s' || respuesta == 'S')
                {
                    do{
                        system("cls");
                        printf("Numero de registro => %d\n", i);
                        printf("Autor => %s\n", biblioteca1.autor);
                        printf("Titulo => %s\n", biblioteca1.titulo);
                        printf("Editorial => %s\n", biblioteca1.editorial);
                        printf("Anio de edicion => %d\n", biblioteca1.anEdicion);
                        printf("Numero de paginas => %d\n", biblioteca1.nPaginas);
                        printf("Precio => %.2f\n", biblioteca1.precio);
                        printf("\n");
                        printf("1) Autor \n");
                        printf("2) Titulo \n");
                        printf("3) Editorial \n");
                        printf("4) Anio de edicion \n");
                        printf("5) Numero de paginas \n");
                        printf("6) Precio \n");
                        printf("0) Salir \n");
                        printf("Seleccione una opcion que desea modificar => ");
                        fflush(stdin);
                        scanf("%d", &seleccion);
                        if(seleccion==0)
                        {
                            break;
                        }
                        switch(seleccion)
                        {
                            case 1:
                                {
                                    printf("Introduce el nuevo autor => ");
                                    fflush(stdin);
                                    gets(biblioteca1.autor);
                                    break;
                                }
                            case 2:
                                {
                                    printf("Introduce el nuevo titulo => ");
                                    fflush(stdin);
                                    gets(biblioteca1.titulo);
                                    break;
                                }
                            case 3:
                                {
                                    printf("Introduce la nueva editorial => ");
                                    fflush(stdin);
                                    gets(biblioteca1.editorial);
                                    break;
                                }
                            case 4:
                                {
                                    printf("Introduce el nuevo anio de edicion => ");
                                    fflush(stdin);
                                    scanf("%d", &biblioteca1.anEdicion);
                                    break;
                                }
                            case 5:
                                {
                                    printf("Introdue el nuevo numero de paginas => ");
                                    fflush(stdin);
                                    scanf("%d", &biblioteca1.nPaginas);
                                    break;
                                }
                            case 6:
                                {
                                    printf("Introduce el nuevo precio => ");
                                    fflush(stdin);
                                    scanf("%f", &biblioteca1.precio);
                                    break;
                                }
                            default:
                                {
                                    printf("Opcion incorrecta \n");
                                    break;
                                }
                        }



                    }while(1);



                    desplazamiento = i*sizeof(biblioteca1);
                    fseek(p1, desplazamiento, 0);
                    fwrite(&biblioteca1, sizeof(biblioteca1), 1, p1);
                    printf("Registro modificado\n");
                    getch();
                }
            }

        }
        if(sw ==0)
        {
            printf("No se ha encontrado con ningun autor con este nombre => %s\n", buscar);
            getch();
        }

    }while(1);
    fclose(p1);
    ordenar();

}

void bajas(void)
{
    long int n;
    long int desplazamiento;
    int i, j, k;
    int sw =0;
    int longitud;
    int seleccion;
    char buscar[20];
    char respuesta;
    biblioteca biblioteca1;
    primer_registro registro0;
    FILE *p1;
    system("cls");
    p1 = fopen("BIBLIOTECA.JC", "r+b");
    fseek(p1, 0L, 0);
    fread(&registro0.nRegistros, sizeof(registro0.nRegistros), 1, p1);
    n = registro0.nRegistros;

    do
    {
        system("cls");
        printf("Introduce el autor que deseas eliminar (fin para salir)=> ");
        fflush(stdin);
        gets(buscar);
        if(strcmp(buscar, "fin")==0)
        {
            break;
        }
        longitud = strlen(buscar);
        sw = 0;
        for(i=1;i<=n;i++)
        {
            desplazamiento = i*sizeof(biblioteca1);
            fseek(p1, desplazamiento, 0);
            fread(&biblioteca1, sizeof(biblioteca1), 1, p1);
            if(strncmp(buscar, biblioteca1.autor, longitud)==0)
            {
                sw =1;
                printf("Autor => %s\n", biblioteca1.autor);
                printf("Titulo => %s\n", biblioteca1.titulo);
                printf("Editorial => %s\n", biblioteca1.editorial);
                printf("Anio de edicion => %d\n", biblioteca1.anEdicion);
                printf("Numero de paginas => %d\n", biblioteca1.nPaginas);
                printf("Precio => %.2f\n", biblioteca1.precio);
                getch();

                printf("Quieres eliminar el libro? (s/n) => ");
                fflush(stdin);
                scanf("%c", &respuesta);
                if(respuesta =='n' || respuesta == 'N')
                {
                    continue;
                }
                if(respuesta=='s' || respuesta =='S')
                {
                    biblioteca1.autor[0]='#';
                    biblioteca1.titulo[0]='#';
                    biblioteca1.editorial[0]='#';
                    biblioteca1.anEdicion =0;
                    biblioteca1.nPaginas =0;
                    biblioteca1.precio=0;

                    desplazamiento=(i+1)*sizeof(biblioteca1);
                    fseek(p1, desplazamiento, 0);
                    fread(&biblioteca1, sizeof(biblioteca1), 1, p1);

                    desplazamiento =i *sizeof(biblioteca1);
                    fseek(p1, desplazamiento, 0);
                    fwrite(&biblioteca1, sizeof(biblioteca1), 1, p1);

                    n = n -1;
                    fseek(p1, 0L, 0);
                    registro0.nRegistros = n;
                    for(k=0;k<84;k++)
                    {
                        registro0.blancos[k]=' ';
                    }
                    fwrite(&registro0, sizeof(registro0), 1, p1);
                }
                printf("Libro eliminado\n");
                getch();
            }
        }
        if(sw==0)
        {
            printf("No se ha encontrado ningun libro con ese nombre => %s",buscar);
            getch();
        }

    }while(1);

    fclose(p1);
    ordenar();
}

void ordenar(void)
{
    long int n=0;
    long int desplazamiento;
    long int i, d;
    int sw;

    biblioteca registro1, registro2;
    primer_registro registro0;
    FILE *p1;

    p1 =fopen("BIBLIOTECA.JC", "r+b");
    fseek(p1, 0L, 0);
    fread(&registro0, sizeof(registro0), 1, p1);
    n= registro0.nRegistros;

    d= n;

    while(d>=1)
    {
        d = d/2;
        do{
            sw =0;
        for(i=1;i<=n-d;i++)
        {
            desplazamiento = i * sizeof(registro1);
            fseek(p1, desplazamiento, 0);
            fread(&registro1, sizeof(registro1), 1, p1);

            desplazamiento= (i+d)*sizeof(registro2);
            fseek(p1, desplazamiento, 0);
            fread(&registro2, sizeof(registro2), 1, p1);

            if(strcmp(registro1.autor, registro2.autor)>0)
            {
                desplazamiento=i*sizeof(registro2);
                fseek(p1, desplazamiento, 0);
                fwrite(&registro2, sizeof(registro2), 1, p1);

                desplazamiento=(i+d)*sizeof(registro1);
                fseek(p1, desplazamiento, 0);
                fwrite(&registro1, sizeof(registro1), 1, p1);

                sw =1;
            }
        }

        }while(sw);
    }
    fclose(p1);

}
