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
void consultas();
void modificaciones();
void bajas();

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
        printf("[3] Consultas \n");
        printf("[4] Modificaciones \n");
        printf("[5] Bajas\n");
        printf("[0] Salir \n");

        printf("Eliga alguna opcion => ");

        scanf("%d", &seleccion);
        switch(seleccion)
        {
            case 1: altas();
            break;
            case 2: listado();
            break;
            case 3: consultas();
            break;
            case 4: modificaciones();
            break;
            case 5: bajas();
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
        printf("Introduce un autor (fin por siquieres salir)=> ");
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
        printf("Introduce el anio de edicion => ");
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
    }while(getchar()== 's' || getchar()=='S');

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
        if(rg.autor[0] !='#')
        {
            printf("Autor => %s\n", rg.autor);
            printf("Titulo => %s\n", rg.titulo);
            printf("Editorial => %s\n", rg.editorial);
            printf("Anio de edicion => %d\n", rg.anedicion);
            printf("Numero de paginas => %d\n", rg.npaginas);
            printf("Precio => %.2f\n", rg.precio);
            getch();
        }

    }
    fflush(p1);
    fclose(p1);
}


void consultas(void)
{
    long int n=0, desplazamiento;
    int  seleccion, sw=0, lon;
    int selec;
    char buscar[20];
    long busca1;
    biblioteca rg;
    cero c;

    FILE *p1;

    p1 = fopen("BIBLIOTECA.DAT", "r+b");
    fseek(p1, 0L, 0);
    fread(&c, sizeof(c),1, p1);
    n = c.nreg;

    while(seleccion != 0)
    {
        system("cls");
        printf("[1] Nombre del autor\n");
        printf("[2] Nombre del titulo \n");
        printf("[3] Nombre de la editorial \n");
        printf("[4] Por anio de edicion\n");
        printf("[5] Por numero de paginas\n");
        printf("[0] Salir \n");
        printf("Eliga alguna opcion => ");
        scanf("%d", &seleccion);
        switch(seleccion)
        {
            case 1:
                {
                    do
                    {
                        fflush(stdin);
                        system("cls");
                        printf("Introduce el nombre del autor  => ");
                        fflush(stdin);
                        gets(buscar);
                        lon = strlen(buscar);
                        sw =0;
                        for(i=1;i<=n;i++)
                        {
                            desplazamiento=i*sizeof(rg);
                            fseek(p1, desplazamiento, 0);
                            fread(&rg, sizeof(rg),1, p1);
                            if(strncmp(rg.autor,buscar,lon)==0)
                            {
                                sw =1;
                                printf("Autor => %s\n", rg.autor);
                                printf("Titulo => %s\n", rg.titulo);
                                printf("Editorial => %s\n", rg.editorial);
                                printf("Anio de edicion => %d\n", rg.anedicion);
                                printf("Numero de paginas => %d\n", rg.npaginas);
                                printf("Precio => %.2f\n", rg.precio);
                                getch();

                            }
                        }
                        if(sw==0)
                        {
                            printf("No encontrado\n");
                        }
                        fflush(stdin);
                        printf("Desea consultar mas autores? (s/n) =>  ");

                    }while(getchar()== 's' || getchar()=='S');

                    break;

                }
            case 2:
                {

                    do
                    {
                        fflush(stdin);
                        system("cls");
                        printf("Introduce el nombre del titulo  => ");
                        fflush(stdin);
                        gets(buscar);
                        lon = strlen(buscar);
                        sw =0;
                        for(i=1;i<=n;i++)
                        {
                            desplazamiento=i*sizeof(rg);
                            fseek(p1, desplazamiento, 0);
                            fread(&rg, sizeof(rg),1, p1);
                            if(strncmp(rg.titulo,buscar,lon)==0)
                            {
                                sw =1;
                                printf("Autor => %s\n", rg.autor);
                                printf("Titulo => %s\n", rg.titulo);
                                printf("Editorial => %s\n", rg.editorial);
                                printf("Anio de edicion => %d\n", rg.anedicion);
                                printf("Numero de paginas => %d\n", rg.npaginas);
                                printf("Precio => %.2f\n", rg.precio);
                                getch();

                            }
                        }
                        if(sw==0)
                        {
                            printf("No encontrado\n");
                        }
                        fflush(stdin);
                        printf("Desea consultar mas titulos? (s/n) =>  ");

                    }while(getchar()== 's' || getchar()=='S');

                    break;


                }

            case 3:
                {

                    do
                    {
                        fflush(stdin);
                        system("cls");
                        printf("Introduce el nombre de la editorial  => ");
                        fflush(stdin);
                        gets(buscar);
                        lon = strlen(buscar);
                        sw =0;
                        for(i=1;i<=n;i++)
                        {
                            desplazamiento=i*sizeof(rg);
                            fseek(p1, desplazamiento, 0);
                            fread(&rg, sizeof(rg),1, p1);
                            if(strncmp(rg.editorial,buscar,lon)==0)
                            {
                                sw =1;
                                printf("Autor => %s\n", rg.autor);
                                printf("Titulo => %s\n", rg.titulo);
                                printf("Editorial => %s\n", rg.editorial);
                                printf("Anio de edicion => %d\n", rg.anedicion);
                                printf("Numero de paginas => %d\n", rg.npaginas);
                                printf("Precio => %.2f\n", rg.precio);
                                getch();

                            }
                        }
                        if(sw==0)
                        {
                            printf("No encontrado\n");
                        }
                        fflush(stdin);
                        printf("Desea consultar mas editoriales? (s/n) =>  ");

                    }while(getchar()== 's' || getchar()=='S');

                    break;


                }
            case 4:
                {
                       do
                   {
                       fflush(stdin);
                       system("cls");
                       printf("Introduce el anno  => ");
                       fflush(stdin);
                       scanf("%d", &busca1);
                       sw =0;
                       for(i=1;i<=n;i++)
                       {
                           desplazamiento=i*sizeof(rg);
                           fseek(p1, desplazamiento, 0);
                           fread(&rg, sizeof(rg),1, p1);
                           if(busca1 == rg.anedicion)
                           {
                               sw =1;
                               printf("Autor => %s\n", rg.autor);
                               printf("Titulo => %s\n", rg.titulo);
                               printf("Editorial => %s\n", rg.editorial);
                               printf("Anio de edicion => %d\n", rg.anedicion);
                               printf("Numero de paginas => %d\n", rg.npaginas);
                               printf("Precio => %.2f\n", rg.precio);
                               getch();

                           }
                       }
                       if(sw==0)
                       {
                           printf("No encontrado\n");
                           getch();
                       }
                       fflush(stdin);
                       printf("Desea consultar mas editoriales? (s/n) =>  ");

                   }while(getchar()== 's' || getchar()=='S');

                   break;



                }

            case 5:
                {
                       do
                   {
                       fflush(stdin);
                       system("cls");
                       printf("Introduce el numero de paginas  => ");
                       fflush(stdin);
                       scanf("%d", &busca1);
                       sw =0;
                       for(i=1;i<=n;i++)
                       {
                           desplazamiento=i*sizeof(rg);
                           fseek(p1, desplazamiento, 0);
                           fread(&rg, sizeof(rg),1, p1);
                           if(busca1 == rg.npaginas)
                           {
                               sw =1;
                               printf("Autor => %s\n", rg.autor);
                               printf("Titulo => %s\n", rg.titulo);
                               printf("Editorial => %s\n", rg.editorial);
                               printf("Anio de edicion => %d\n", rg.anedicion);
                               printf("Numero de paginas => %d\n", rg.npaginas);
                               printf("Precio => %.2f\n", rg.precio);
                               getch();

                           }
                       }
                       if(sw==0)
                       {
                           printf("No encontrado\n");
                           getch();
                       }
                       fflush(stdin);
                       printf("Desea consultar mas libros por paginas? (s/n) =>  ");

                   }while(getchar()== 's' || getchar()=='S');

                   break;
                }

            case 0:
                fclose(p1);
                break;
        }
    }
}

void modificaciones(void)
{
    long int n=0, desplazamiento;
    int  seleccion, sw=0, lon;
    int selec;
    char buscar[20];
    long busca1;
    char respuesta;
    biblioteca rg;
    cero c;

    FILE *p1;

        do{
            system("cls");
            p1 =fopen("BIBLIOTECA.DAT", "r+b");
            fseek(p1, 0L, 0);
            fread(&c, sizeof(c), 1, p1);
            n =c.nreg;
            fflush(stdin);
            printf("Introduce el nombre del registro que quieres modificar (fin para salir) => ");
            gets(buscar);
            lon = strlen(buscar);
            if(strcmp(buscar, "fin")==0)
            {
                break;
            }
            sw =0;

            for(i=1;i<=n;i++)
            {
                desplazamiento = i*sizeof(rg);
                fseek(p1, desplazamiento, 0);
                fread(&rg, sizeof(rg), 1, p1);

                if(strncmp(rg.autor, buscar, lon)==0)
                {
                    sw =1;
                    printf("Autor => %s\n", rg.autor);
                    printf("Titulo => %s\n", rg.titulo);
                    printf("Editorial => %s\n", rg.editorial);
                    printf("Anio de edicion => %d\n", rg.anedicion);
                    printf("Numero de paginas => %d\n", rg.npaginas);
                    printf("Precio => %.2f\n", rg.precio);
                    fflush(stdin);
                    printf("Desea modificar este registro? (s/n) => ");
                    scanf("%s", &respuesta);
                    fflush(stdin);
                    if(respuesta == 's' || respuesta =='S')
                    {
                        do{
                            system("cls");
                            printf("Autor => %s\n", rg.autor);
                            printf("Titulo => %s\n", rg.titulo);
                            printf("Editorial => %s\n", rg.editorial);
                            printf("Anio de edicion => %d\n", rg.anedicion);
                            printf("Numero de paginas => %d\n", rg.npaginas);
                            printf("Precio => %.2f\n", rg.precio);
                            printf("\n");
                            printf("\n");

                            printf("Elige un campo que quieras modificar \n");
                            printf("[1] Autor \n");
                            printf("[2] Titulo \n");
                            printf("[3] Editorial \n");
                            printf("[4] Anio de edicion \n");
                            printf("[5] Numero de paginas \n");
                            printf("[6] Precio \n");
                            printf("[0] Salir \n");
                            printf("Seleccione alguna de las siguientes opciones [0-6] => ");
                            scanf("%d", &selec);

                            if(selec ==0)
                            {
                                break;
                            }

                            switch(selec)
                            {
                                case 1:
                                    {
                                        fflush(stdin);
                                        printf("Introduce un autor => ");
                                        fflush(stdin);
                                        gets(rg.autor);
                                        break;
                                    }

                                case 2:
                                    {
                                        fflush(stdin);
                                        printf("Introduce el titulo => ");
                                        fflush(stdin);
                                        gets(rg.titulo);
                                        break;
                                    }

                                case 3:
                                    {
                                        printf("Introduce la editorial => ");
                                        fflush(stdin);
                                        gets(rg.editorial);
                                        break;
                                    }
                                case 4:
                                    {
                                        printf("Introduce el anio de edicion => ");
                                        fflush(stdin);
                                        scanf("%d", &rg.anedicion);
                                        break;
                                    }
                                case 5:
                                    {
                                        printf("Introduce el numero de paginas => ");
                                        fflush(stdin);
                                        scanf("%d", &rg.npaginas);
                                        break;
                                    }
                                case 6:
                                    {
                                        printf("Introduce el precio => ");
                                        fflush(stdin);
                                        scanf("%f", &rg.precio);
                                        break;
                                    }

                                default:
                                    {
                                        printf("Opcion incorrecta \n");
                                    }
                            }
                            fflush(stdin);
                            printf("Desea guardar este registro modificado? (s/n) => \n");

                        }while(getchar() == 's' || getchar()== 'S');
                        fflush(stdin);

                        desplazamiento = i*sizeof(rg);
                        fseek(p1, desplazamiento, 0);
                        fwrite(&rg, sizeof(rg), 1, p1);
                        printf("Registro modificado\n");
                        getch();

                    }
                }
            }
            if(sw ==0)
            {
                printf("No se ha encontrado ningun autor con ese nombre\n");
                getch();
            }
            fflush(stdin);
          printf("Desea modificar mas registros? (s/n) =>  ");
        }while(getchar()== 's' || getchar()=='S');

        fflush(p1);
        fclose(p1);
}

void bajas(void)
{
    long int n=0, desplazamiento;
    int  seleccion, sw=0, lon;
    int selec, k;
    char buscar[20];
    long busca1;
    char respuesta;
    biblioteca rg;
    cero c;

    FILE *p1;
    do
    {
        system("cls");
        p1 =fopen("BIBLIOTECA.DAT", "r+b");
        fseek(p1, 0L, 0);
        fread(&c, sizeof(c), 1, p1);
        n =c.nreg;
        fflush(stdin);
        printf("Introduce el nombre del registro que quieres eliminar (fin para salir) => ");
        fflush(stdin);
        gets(buscar);
        if(strcmp(buscar, "fin")==0)
        {
            break;
        }
        lon = strlen(buscar);
        if(strcmp(buscar, "FIN")==0)
        {
            break;
        }


        for(i=1;i<=n;i++)
        {
            desplazamiento = i*sizeof(rg);
            fseek(p1, desplazamiento, 0);
            fread(&rg, sizeof(rg), 1, p1);

            if(strncmp(rg.autor, buscar, lon)==0)
            {
                sw =1;
                printf("Autor => %s\n", rg.autor);
                printf("Titulo => %s\n", rg.titulo);
                printf("Editorial => %s\n", rg.editorial);
                printf("Anio de edicion => %d\n", rg.anedicion);
                printf("Numero de paginas => %d\n", rg.npaginas);
                printf("Precio => %.2f\n", rg.precio);
                fflush(stdin);
                printf("Desea eliminar este registro? (s/n) => ");
                scanf("%s", &respuesta);

                if(respuesta == 's')
                {
                    rg.autor[0]= '#';
                    rg.autor[0] = '#';
                    rg.titulo[0] = '#';
                    rg.editorial[0] = '#';
                    rg.anedicion = 0;
                    rg.npaginas = 0;
                    rg.precio = 0.0;

                    desplazamiento= n*sizeof(rg);
                    fseek(p1, desplazamiento, 0);
                    fread(&rg, sizeof(rg), 1, p1);

                    desplazamiento = i*sizeof(rg);
                    fseek(p1, desplazamiento, 0);
                    fwrite(&rg, sizeof(rg), 1, p1);
                    n = n-1;
                    fseek(p1, 0L, 0);
                    c.nreg = n;
                    for(k=0;k<=60;k++)
                    {
                        c.blancos[k]=' ';
                    }
                    fwrite(&c, sizeof(c), 1, p1);
                    printf("Registro eliminado\n");
                    getch();
                }

            }
        }
        if(sw == 0)
        {
            printf("No se ha encontrado ningun autor con ese nombre\n");
            getch();
        }
        fflush(stdin);
         printf("Desea eliminar mas registros? (s/n) =>  ");
    }while(getchar()== 's' || getchar()=='S');

    fflush(p1);
    fclose(p1);
}


