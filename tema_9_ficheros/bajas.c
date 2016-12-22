#include <stdio.h>
#include <conio.h>
#include <string.h>

#define FICHERO "PIEZAS.DAT"

typedef struct
{
    char nombre_pieza[15];
    int cantidad;
    float precio_unitario;
}tipo_pieza;

typedef struct
{
    long int nregistros;
    char blancos[60];

}primer_registro;

int main()
{
    tipo_pieza registro;
    primer_registro registro0;
    FILE *puntero;
    long int n=0, desplazamiento;
    int k, i, l, sw;
    char nombre[15], a;

    puntero = fopen("BIBLIOTECA.DAT", "rb");
    if(puntero == NULL)
    {
        printf("El fichero BIBLIOTECA.DAT esta vacio o no existe");
        getch();
        system("cls");
        puntero =fopen("BIBLIOTECA.DAT", a+b);
        fseek(puntero, 0L, 0);
        registro0.nregistros = 0L;
        for(k=0;k<17;k++)
        {
            registro0.blancos[k]=' ';
        }
        fwrite(&registro0, sizeof(registro0), 1, puntero);
        printf("Numero de registros n vale = %ld", registro0.nregistros);
        getch();
        return(-1);
    }
    fclose(puntero);

    puntero = fopen("BIBLIOTECA.DAT", "r+b");
    fseek(puntero, 0L, 0);
    fread(&registro0, sizeof(registro0), 1, puntero);
    n = registro0.nregistros;

    system("cls");
    do {
        fflush(stdin);
        printf("Introdice el nombre a borrar => ");
        gets(nombre);
        l = strlen(nombre);
        if(strncmp(nombre, "FIN", 1)==0)
        {
            break;
        }
        sw =0;
        for(i=1;i<=n;i++)
        {
            desplazamiento = i*sizeof(registro);
            fseek(puntero, desplazamiento, 0);
            fread(&registro, sizeof(registro), 1, puntero);
            if(strncmp(nombre, registro.nombre_pieza, 1)==0)
            {
                printf(""); //imprimo los registros
                sw =1;
                fflush(stdin);
                printf("Quieres borrar este registro? (s/n)=> \n");
                scanf("%c", &a);
                if(a=='s' || a =='S')
                {
                    desplazamiento = n *sizeof(registro);
                    fseek(puntero, desplazamiento, 0);
                    fread(&registro, sizeof(registro), 1, puntero);

                    desplazamiento = i *sizeof(registro);
                    fseek(puntero, desplazamiento, 0);
                    fwrite(&registro, sizeof(registro), 1, puntero);
                    n =n -1;
                    fseek(puntero, 0L, 0);
                    registro0.nregistros = n;
                    for(k=0;k<17;k++)
                    {
                        registro0.blancos[k]=' ';

                    }
                    fwrite(&registro0, sizeof(registro0), 1, puntero);
                    break;
                }
            }
        }
        if(sw==0)
        {
            printf("No encontrado\n");
            getch();
        }
    }while(1);
    fclose(puntero);
}
