#include <stdio.h>
#include <conio.h>
#include <string.h>

typedef struct
{
    char cVendedor[5];
    char cif[12];
    char nVendedor[25];
    char dVendedor[25];
    char cPostal[6];
    char ciudad[15];
}Vendedores;

typedef struct
{
    long int nRegistros; //mide 4
    char blancos[83];
}primer_registro;

//FUNCIONES
void altas();
void listados();
void consultas();
void bajas();
void modificaciones();
void ordenar();
void ordenar_nombre();
int main()
{
    // printf("El tamanio de vendedores es %d\n", sizeof(Vendedores)); //87
    //printf("El tamanio de primer_registro es %d", sizeof(primer_registro)); //88
    int seleccion;
    int k;
    Vendedores vendedores1;
    primer_registro registro0;
    FILE *p1;
    p1 = fopen("VENDEDORES.DAT", "rb");
    if(p1==NULL)
    {
        printf("No hay ningun archivo\n");
        getch();
        system("cls");
        p1=fopen("VENDEDORES.DAT", "w+b");
        printf("Archivo creado\n");
        fseek(p1, 0L,0);
        registro0.nRegistros=0L;
        for(k=0;k<=83;k++)
        {
            registro0.blancos[k]=' ';
        }
        fwrite(&registro0, sizeof(registro0), 1, p1);
        getch();
    }
    fclose(p1);

    do
    {
        system("cls");
        printf("----MANTENIMIENTO----\n");
        printf("1) Altas\n");
        printf("2) Listados\n");
        printf("3) Consultas\n");
        printf("4) Bajas\n");
        printf("5) Modificaciones\n");
        printf("0) Salir\n");

        scanf("%d", &seleccion);
        if(seleccion==0)
        {
            printf("Bye!!!!\n");
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
                    ordenar();
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
                    bajas();
                    break;
                }
            case 5:
                {
                    modificaciones();
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
    int k;

    Vendedores vendedor1;
    primer_registro registro0;
    FILE *p1;

    p1=fopen("VENDEDORES.DAT","r+b");
    fseek(p1, 0L, 0);
    fread(&registro0, sizeof(registro0), 1, p1);
    n = registro0.nRegistros;
    do
    {
        n= n+1;
        system("cls");
        printf("Introduce el codigo del vendedor => ");
        fflush(stdin);
        gets(vendedor1.cVendedor);
        printf("Introduce el CIF => ");
        fflush(stdin);
        gets(vendedor1.cif);
        printf("Introduce el nombre del vendedor => ");
        fflush(stdin);
        gets(vendedor1.nVendedor);
        printf("Introduce la direccion del vendedor => ");
        fflush(stdin);
        gets(vendedor1.dVendedor);
        printf("Introduce el codigo postal => ");
        fflush(stdin);
        gets(vendedor1.cPostal);
        printf("Introduce la ciudad => ");
        fflush(stdin);
        gets(vendedor1.ciudad);

        desplazamiento =n *sizeof(vendedor1);
        fseek(p1, desplazamiento, 0);
        fwrite(&vendedor1, sizeof(vendedor1), 1, p1);

        printf("Vendedor registrado\n");

        printf("Desea aniadir mas vendedores?(s/n)=> ");
        fflush(stdin);
    }while(getchar()=='s'|| getchar()=='S');

    fseek(p1,0L,0);
    registro0.nRegistros = n;
    for(k=0;k<83;k++)
    {
        registro0.blancos[k]=' ';
    }
    fwrite(&registro0, sizeof(registro0), 1, p1);
    fclose(p1);

}

void listados(void)
{
    long int n, desplazamiento;
    int i;

    Vendedores vendedor1;
    primer_registro registro0;
    FILE *p1;
    p1 =fopen("VENDEDORES.DAT", "r+b");
    fseek(p1, 0L, 0);
    fread(&registro0, sizeof(registro0), 1,p1);

    n = registro0.nRegistros;
    for(i=1; i<=n;i++)
    {
        desplazamiento = i*sizeof(vendedor1);
        fseek(p1, desplazamiento, 0);
        fread(&vendedor1, sizeof(vendedor1), 1, p1);

        system("cls");
        printf("Codigo vendendor => %s\n", vendedor1.cVendedor);
        printf("CIF => %s\n", vendedor1.cif);
        printf("Nombre del vendedor => %s\n", vendedor1.nVendedor);
        printf("Direccion del vendedor => %s\n",vendedor1.dVendedor);
        printf("Codigo postal => %s\n", vendedor1.cPostal);
        printf("Ciudad => %s\n", vendedor1.ciudad);
        getch();
    }

    fclose(p1);

}

void consultas(void)
{
    long int n=0, desplazamiento;
    long int longitud, cen, izq, der, seleccion, sw, i;
    char buscar[20];

    Vendedores vendedor1;
    primer_registro registro0;
    FILE *p1;
    p1 =fopen("VENDEDORES.DAT", "r+b");
    fseek(p1,0L,0);
    fread(&registro0, sizeof(registro0), 1, p1);
    n = registro0.nRegistros;

    while(seleccion!=0)
    {
        system("cls");
        printf("1) Codigo del vendedor\n");
        printf("2) Nombre del vendedor\n");
        printf("0) Salir\n");
        scanf("%ld", &seleccion);
        if(seleccion==0)
        {
            break;
        }
        switch(seleccion)
        {
            case 1:
                {
                    ordenar();
                    do{
                        system("cls");
                        fflush(stdin);
                        printf("Introduce el codigo del vendedor (FIN para salir) => ");
                        scanf("%s", &buscar);
                        longitud = strlen(buscar);
                        /*for(i=0;i<longitud;i++)
                        {
                            buscar[i]=toupper(buscar[i]);
                        }*/
                        if(strncmp(buscar, "FIN",1)==0)
                        {
                            break;
                        }
                        sw =0;
                        izq =1;
                        der =n;
                        do{
                            cen=(izq+der)/2;

                            desplazamiento = cen*sizeof(vendedor1);
                            fseek(p1, desplazamiento, 0);
                            fread(&vendedor1, sizeof(vendedor1), 1, p1);
                            if(strncmp(buscar,vendedor1.cVendedor,longitud)==0||(izq>=der))
                            {
                                sw =1;
                                if(strncmp(buscar,vendedor1.cVendedor, longitud)==0)
                                {
                                    printf("Codigo vendendor => %s\n", vendedor1.cVendedor);
                                    printf("CIF => %s\n", vendedor1.cif);
                                    printf("Nombre del vendedor => %s\n", vendedor1.nVendedor);
                                    printf("Direccion del vendedor => %s\n",vendedor1.dVendedor);
                                    printf("Codigo postal => %s\n", vendedor1.cPostal);
                                    printf("Ciudad => %s\n", vendedor1.ciudad);
                                    getch();
                                }
                                else
                                {
                                    printf("No encontrado\n");
                                }

                            }
                            else
                            {
                                if(strncmp(buscar,vendedor1.cVendedor,longitud)<0)
                                {
                                    der = cen-1;
                                }
                                else
                                {
                                    izq = cen +1;
                                }
                            }
                            if(sw==1)
                            {
                                break;
                            }
                        }while(1);

                    }while(1);
                    break;

                }
            case 2:
                {
                    ordenar_nombre();
                    do{
                        system("cls");
                        fflush(stdin);
                        printf("Introduce el nombre del vendedor (FIN para salir) => ");
                        scanf("%s", &buscar);
                        longitud = strlen(buscar);
                        /*for(i=0;i<longitud;i++)
                        {
                            buscar[i]=toupper(buscar[i]);
                        }*/
                        if(strncmp(buscar, "FIN",1)==0)
                        {
                            break;
                        }
                        sw =0;
                        izq =1;
                        der =n;
                        do{
                            cen=(izq+der)/2;

                            desplazamiento = cen*sizeof(vendedor1);
                            fseek(p1, desplazamiento, 0);
                            fread(&vendedor1, sizeof(vendedor1), 1, p1);
                            if(strncmp(buscar,vendedor1.nVendedor,longitud)==0||(izq>=der))
                            {
                                sw =1;
                                if(strncmp(buscar,vendedor1.nVendedor, longitud)==0)
                                {
                                    printf("Codigo vendendor => %s\n", vendedor1.cVendedor);
                                    printf("CIF => %s\n", vendedor1.cif);
                                    printf("Nombre del vendedor => %s\n", vendedor1.nVendedor);
                                    printf("Direccion del vendedor => %s\n",vendedor1.dVendedor);
                                    printf("Codigo postal => %s\n", vendedor1.cPostal);
                                    printf("Ciudad => %s\n", vendedor1.ciudad);
                                    getch();
                                }
                                else
                                {
                                    printf("No encontrado\n");
                                }

                            }
                            else
                            {
                                if(strncmp(buscar,vendedor1.nVendedor,longitud)<0)
                                {
                                    der = cen-1;
                                }
                                else
                                {
                                    izq = cen +1;
                                }
                            }
                            if(sw==1)
                            {
                                break;
                            }
                        }while(1);

                    }while(1);
                    break;
                }
            default:
                {
                    printf("Opcion incorrecta\n");
                }
        }
    }

}

void bajas(void)
{
    int k;
    long int n=0, desplazamiento;
    long int longitud, cen, izq, der, seleccion, sw, i;
    char buscar[20];
    char respuesta;

    Vendedores vendedor1;
    primer_registro registro0;
    FILE *p1;
    p1 =fopen("VENDEDORES.DAT", "r+b");
    fseek(p1,0L,0);
    fread(&registro0, sizeof(registro0), 1, p1);
    n = registro0.nRegistros;

    ordenar_nombre();
    do{
        system("cls");
        fflush(stdin);
        printf("Introduce el nombre del vendedor que deseas eliminar (FIN para salir) => ");
        scanf("%s", &buscar);
        longitud = strlen(buscar);
        /*for(i=0;i<longitud;i++)
        {
            buscar[i]=toupper(buscar[i]);
        }*/
        if(strncmp(buscar, "FIN",1)==0)
        {
            break;
        }
        sw =0;
        izq =1;
        der =n;
            do{
                cen=(izq+der)/2;

                desplazamiento = cen*sizeof(vendedor1);
                fseek(p1, desplazamiento, 0);
                fread(&vendedor1, sizeof(vendedor1), 1, p1);
                if(strncmp(buscar,vendedor1.nVendedor,longitud)==0||(izq>=der))
                {
                    sw =1;
                    if(strncmp(buscar,vendedor1.nVendedor, longitud)==0)
                    {
                        printf("Registro => %ld\n", cen);
                        printf("Codigo vendendor => %s\n", vendedor1.cVendedor);
                        printf("CIF => %s\n", vendedor1.cif);
                        printf("Nombre del vendedor => %s\n", vendedor1.nVendedor);
                        printf("Direccion del vendedor => %s\n",vendedor1.dVendedor);
                        printf("Codigo postal => %s\n", vendedor1.cPostal);
                        printf("Ciudad => %s\n", vendedor1.ciudad);
                        getch();

                        printf("Deseas eliminar este vendedor? (s/n) => ");
                        fflush(stdin);
                        scanf("%c", &respuesta);
                        if(respuesta=='n'|| respuesta=='N')
                        {
                            break;
                        }
                        if(respuesta=='s'|| respuesta =='S')
                        {
                            desplazamiento = n*sizeof(vendedor1);
                            fseek(p1, desplazamiento, 0);
                            fread(&vendedor1, sizeof(vendedor1), 1, p1);

                            desplazamiento = cen*sizeof(vendedor1);
                            fseek(p1, desplazamiento, 0);
                            fwrite(&vendedor1, sizeof(vendedor1), 1, p1);

                            n = n -1;

                            fseek(p1, 0L, 0);
                            registro0.nRegistros= n;
                            for(k=0;k<83;k++)
                            {
                                registro0.blancos[k]=' ';
                            }
                            fwrite(&registro0, sizeof(registro0), 1, p1);
                        }
                        printf("Vendedor eliminado\n");
                        getch();
                    }
                    else
                    {
                        printf("No encontrado\n");
                    }

                }
                else
                {
                    if(strncmp(buscar,vendedor1.nVendedor,longitud)<0)
                    {
                        der = cen-1;
                    }
                    else
                    {
                        izq = cen +1;
                    }
                }
                if(sw==1)
                {
                    break;
                }
            }while(1);
    }while(1);
    fclose(p1);
    ordenar();
}
void modificaciones(void)
{
    int k;
    long int n=0, desplazamiento;
    long int longitud, cen, izq, der, seleccion, sw, i;
    char buscar[20];
    char respuesta;

    Vendedores vendedor1;
    primer_registro registro0;
    FILE *p1;
    p1 =fopen("VENDEDORES.DAT", "r+b");
    fseek(p1,0L,0);
    fread(&registro0, sizeof(registro0), 1, p1);
    n = registro0.nRegistros;

    ordenar_nombre();
    do{
        system("cls");
        fflush(stdin);
        printf("Introduce el nombre del vendedor que deseas modificar (FIN para salir) => ");
        scanf("%s", &buscar);
        longitud = strlen(buscar);
        /*for(i=0;i<longitud;i++)
        {
            buscar[i]=toupper(buscar[i]);
        }*/
        if(strncmp(buscar, "FIN",1)==0)
        {
            break;
        }
        sw =0;
        izq =1;
        der =n;
            do{
                cen=(izq+der)/2;

                desplazamiento = cen*sizeof(vendedor1);
                fseek(p1, desplazamiento, 0);
                fread(&vendedor1, sizeof(vendedor1), 1, p1);
                if(strncmp(buscar,vendedor1.nVendedor,longitud)==0||(izq>=der))
                {
                    sw =1;
                    if(strncmp(buscar,vendedor1.nVendedor, longitud)==0)
                    {
                        printf("Registro => %ld\n", cen);
                        printf("Codigo vendendor => %s\n", vendedor1.cVendedor);
                        printf("CIF => %s\n", vendedor1.cif);
                        printf("Nombre del vendedor => %s\n", vendedor1.nVendedor);
                        printf("Direccion del vendedor => %s\n",vendedor1.dVendedor);
                        printf("Codigo postal => %s\n", vendedor1.cPostal);
                        printf("Ciudad => %s\n", vendedor1.ciudad);
                        getch();

                        printf("Deseas modificar este vendedor? (s/n) => ");
                        fflush(stdin);
                        scanf("%c", &respuesta);
                        if(respuesta=='n'|| respuesta=='N')
                        {
                            break;
                        }
                        if(respuesta=='s'|| respuesta =='S')
                        {
                            do{
                                system("cls");
                                printf("Registro => %ld\n", cen);
                                printf("Codigo vendendor => %s\n", vendedor1.cVendedor);
                                printf("CIF => %s\n", vendedor1.cif);
                                printf("Nombre del vendedor => %s\n", vendedor1.nVendedor);
                                printf("Direccion del vendedor => %s\n",vendedor1.dVendedor);
                                printf("Codigo postal => %s\n", vendedor1.cPostal);
                                printf("Ciudad => %s\n", vendedor1.ciudad);
                                printf("\n");
                                printf("1) Codigo vendedor\n");
                                printf("2) CIF\n");
                                printf("3) Nombre del vendedor\n");
                                printf("4) Direccion del vendedor\n");
                                printf("5) Codigo postal\n");
                                printf("6) Ciudad\n");
                                printf("0) Salir\n");
                                printf("Elige una opcion =>");
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
                                           printf("Introduce el nuevo codigo del vendedor => ");
                                           fflush(stdin);
                                           gets(vendedor1.cVendedor);
                                           break;
                                        }
                                    case 2:
                                        {
                                            printf("Introduce el nuevo CIF => ");
                                            fflush(stdin);
                                            gets(vendedor1.cif);
                                            break;
                                        }
                                    case 3:
                                        {
                                            printf("Introduce el nuevo Nombre del vendedor => ");
                                            fflush(stdin);
                                            gets(vendedor1.nVendedor);
                                            break;
                                        }
                                    case 4:
                                        {
                                            printf("Introduce la nueva direccion del vendedor => ");
                                            fflush(stdin);
                                            gets(vendedor1.dVendedor);
                                            break;
                                        }
                                    case 5:
                                        {
                                            printf("Introduce el nuevo codigo postal => ");
                                            fflush(stdin);
                                            gets(vendedor1.cPostal);
                                            break;
                                        }
                                    case 6:
                                        {
                                            printf("Introduce la nueva ciudad del vendedor => ");
                                            fflush(stdin);
                                            gets(vendedor1.ciudad);
                                            break;
                                        }
                                    default:
                                        printf("Opcion incorrecta\n");
                                        break;
                                }

                            }while(1);

                            desplazamiento = cen*sizeof(vendedor1);
                            fseek(p1, desplazamiento, 0);
                            fwrite(&vendedor1, sizeof(vendedor1), 1, p1);


                            printf("Vendedor modificado\n");
                            getch();
                    }
                        }

                    else
                    {
                        printf("No encontrado\n");
                    }

                }
                else
                {
                    if(strncmp(buscar,vendedor1.nVendedor,longitud)<0)
                    {
                        der = cen-1;
                    }
                    else
                    {
                        izq = cen +1;
                    }
                }
                if(sw==1)
                {
                    break;
                }
            }while(1);
    }while(1);
    fclose(p1);
    ordenar();
}

void ordenar(void)
{
    long int n=0, desplazamiento;
    Vendedores registro1, registro2;
    primer_registro registro0;
    long int i, d;
    int sw;
    FILE *p1;

    p1 = fopen("VENDEDORES.DAT", "r+b");
    fseek(p1,0L,0);
    fread(&registro0, sizeof(registro0), 1, p1);
    n = registro0.nRegistros;
    d = n;

    while(d>=1)
    {
        d = d/2;
        do{
            sw =0;
            for(i=1;i<=n-d;i++)
            {
                desplazamiento=i*sizeof(registro1);
                fseek(p1, desplazamiento, 0);
                fread(&registro1, sizeof(registro1), 1, p1);

                desplazamiento=(i+d)*sizeof(registro2);
                fseek(p1, desplazamiento, 0);
                fread(&registro2, sizeof(registro2), 1, p1);

                if(strcmp(registro1.cVendedor, registro2.cVendedor)>0)
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

void ordenar_nombre()
{
    long int n=0, desplazamiento;
    Vendedores registro1, registro2;
    primer_registro registro0;
    long int i, d;
    int sw;
    FILE *p1;

    p1 = fopen("VENDEDORES.DAT", "r+b");
    fseek(p1,0L,0);
    fread(&registro0, sizeof(registro0), 1, p1);
    n = registro0.nRegistros;
    d = n;

    while(d>=1)
    {
        d = d/2;
        do{
            sw =0;
            for(i=1;i<=n-d;i++)
            {
                desplazamiento=i*sizeof(registro1);
                fseek(p1, desplazamiento, 0);
                fread(&registro1, sizeof(registro1), 1, p1);

                desplazamiento=(i+d)*sizeof(registro2);
                fseek(p1, desplazamiento, 0);
                fread(&registro2, sizeof(registro2), 1, p1);

                if(strcmp(registro1.nVendedor, registro2.nVendedor)>0)
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
