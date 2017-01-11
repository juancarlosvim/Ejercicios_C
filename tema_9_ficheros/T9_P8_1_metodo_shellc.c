#include <stdio.h>
#include <conio.h>
#include <string.h>

typedef struct{
    char nombre[20];
    char direccion[30];
    char tlfn[10];
    int edad;
}Agenda;
typedef struct{
    long int num;
    char blancos[60];
}Primer;

static Agenda agenda;
static Primer primer;
FILE *puntero;
int i;

void altas(void);
void listado(void);
void consultas(void);
void bajas(void);
void modificaciones(void);
void ordenar();

int main(){
    //printf("%d %d\n",sizeof(Agenda),sizeof(Primer));getch();
    int seleccion=1;
    long int n=0,desplazamiento;

    puntero = fopen("AGENDA.RE","rb");
    if(puntero==NULL){
        printf("El fichero esta vacio\n");
        getch();
        clrscr();
        puntero= fopen("AGENDA.RE","a+b");
        fseek(puntero,0L,0);
        primer.num=0L;
        for(i=0;i<60;i++)
            primer.blancos[i]=' ';
        }
        fwrite(&primer,sizeof(primer),1,puntero);
        fclose(puntero);
    while(seleccion!=0){
        clrscr();
        printf("--Agenda--\n");
        printf("1.Altas\n");
        printf("2.Listado\n");
        printf("3.Consultas\n");
        printf("4.Bajas\n");
        printf("5.Modificaciones\n");
        printf("6.Ordenar metodo shell\n");
        printf("0.Salir\n");
        scanf("%d",&seleccion);
        switch(seleccion){
            case 1: altas();
            break;
            case 2: listado();
            break;
            case 3: consultas();
            break;
            case 4: bajas();
            break;
            case 5: modificaciones();
            break;
            case 6: ordenar();
            break;
            case 0: printf("Salir\n");
            break;
            default: printf("Opcion incorrecta\n");
        }
    }
return 0;
}
void altas(void){
    long int n=0,desplazamiento;

    puntero=fopen("AGENDA.RE","r+b");
    fseek(puntero,0L,0);
	fread(&primer, sizeof(primer), 1, puntero);
	n = primer.num;
	do
	{
		n=n+1;
		clrscr();
		printf("\nFicha numero: %ld",n);
		fflush(stdin);
		printf("\nNombre\n");
		gets(agenda.nombre);
		fflush(stdin);
		printf("Direccion\n");
		gets(agenda.direccion);
		fflush(stdin);
		printf("Telefono\n");
		gets(agenda.tlfn);
		fflush(stdin);
		printf("Edad\n");
		scanf("%d", &agenda.edad);
		fflush(stdin);

		desplazamiento=n*sizeof(agenda);
		fseek(puntero,desplazamiento,0);
		fwrite(&agenda, sizeof(agenda), 1, puntero);

		printf("Quiere introducir mas contactos (s/n)? => ");
		fflush(stdin);
	} while (getchar() == 's');

		desplazamiento=0L*sizeof(primer);
		fseek(puntero,desplazamiento,0);
			primer.num = n;
			for (i=0;i<60;i++)
				primer.blancos[i]=' ';
		fwrite(&primer, sizeof(primer), 1, puntero);

		fflush(puntero);
		fclose(puntero);
		ordenar();
}
void listado(void){
    long int n=0,desplazamiento;

    puntero = fopen("AGENDA.RE","rb");
    fseek(puntero,0L,0);
    fread(&primer,sizeof(primer),1,puntero);
    n=primer.num;
    printf("Nº de registros: %d",n);getch();
    for(i=1;i<=n;i++){
        clrscr();
        desplazamiento=i*sizeof(agenda);
		fseek(puntero,desplazamiento,0);
        fread(&agenda,sizeof(agenda),1,puntero);
        printf("%s %s %s %d\n",agenda.nombre,agenda.direccion,agenda.tlfn,agenda.edad);
        getch();
    }
    fflush(puntero);
    fclose(puntero);
    ordenar();
}
void consultas(void){
    long int n=0,desplazamiento;
    int seleccion=1,sw=0,lon;
    char busca[20];
    long busca1;

    puntero = fopen("AGENDA.RE","rb");
    fseek(puntero,0L,0);
    fread(&primer,sizeof(primer),1,puntero);
    n=primer.num;

    while(seleccion!=0){
        clrscr();
        printf("1.Busqueda por nombre\n");
        printf("2.Busqueda por numero de registro\n");
        printf("0.Salir\n");
        scanf("%d",&seleccion);
        switch(seleccion){
            case 1:
                fflush(stdin);
                printf("Introduce el nombre a buscar\n");
                gets(busca);
                lon = strlen(busca);
                for(i=1;i<=n;i++){
                    clrscr();
                    desplazamiento=i*sizeof(agenda);
                    fseek(puntero,desplazamiento,0);
                    fread(&agenda,sizeof(agenda),1,puntero);
                    if(strncmp(agenda.nombre,busca,lon)==0){
                        printf("%s %s %s %d\n",agenda.nombre,agenda.direccion,agenda.tlfn,agenda.edad);
                        getch();
                        sw=1;
                    }
                }
                if(sw==0)
                    printf("No encontrado\n");
                sw=0;
                break;

            case 2:
                fflush(stdin);
                printf("Introduce el numero de registro a buscar\n");
                scanf("%ld",&busca1);
                if (busca1 > n){
                    printf("Tenemos solo %d registros",n);
                    getch();
                }
                else{
                    desplazamiento=busca1*sizeof(agenda);
                    fseek(puntero,desplazamiento,0);
                    fread(&agenda,sizeof(agenda),1,puntero);
                    printf("%s %s %s %d\n",agenda.nombre,agenda.direccion,agenda.tlfn,agenda.edad);
                    getch();

                }
                break;

            case 0:
                printf("Adios\n");
                fclose(puntero);
                break;

        }
    }
}

void bajas(void){
    long int n=0,desplazamiento,j;
    char busca[20],respuesta;
    int lon,sw=0;
    do{
        clrscr();
        puntero = fopen("AGENDA.RE","r+b");
        fseek(puntero,0L,0);
        fread(&primer,sizeof(primer),1,puntero);
        n=primer.num;
        fflush(stdin);
        printf("Introduce el nombre del registro que deseas borrar(FIN para salir)\n");
        gets(busca);
        lon=strlen(busca);
        if(strcmp(busca,"FIN")==0)
            break;
        for(i=1;i<=n;i++){
            fread(&agenda,sizeof(agenda),1,puntero);
            if(strncmp(agenda.nombre,busca,lon)==0){
                printf("%s %s %s %d\n",agenda.nombre,agenda.direccion,agenda.tlfn,agenda.edad);
                getch();
                printf("Deseas eliminar este registro?\n");
                fflush(stdin);
                scanf("%c", &respuesta);
                if(respuesta=='s'){
                    while(i<n){
                        j=i+1;
                        desplazamiento=j*sizeof(agenda);
                        fseek(puntero,desplazamiento,0);
                        fread(&agenda,sizeof(agenda),1,puntero);
                        j=i;
                        desplazamiento=j*sizeof(agenda);
                        fseek(puntero,desplazamiento,0);
                        fwrite(&agenda,sizeof(agenda),1,puntero);
                        i++;
                    }
                    n=n-1;
                    desplazamiento=0L*sizeof(primer);
                    fseek(puntero,desplazamiento,0);
                    primer.num = n;
                    for (i=0;i<60;i++)
                        primer.blancos[i]=' ';
                    fwrite(&primer, sizeof(primer), 1, puntero);
                    sw=1;
                    printf("Registro borrado\n");
                    printf("Nº de registros: %d",n);
                    getch();
                    fflush(puntero);
                    fclose(puntero);
                    break;
                }
            }
        }
        if(sw==0){
            printf("No encontrado\n");
            getch();
        }
        sw=0;
    }while(1);
    fflush(puntero);
    fclose(puntero);
}

void modificaciones(void){
    long int n=0,desplazamiento,j;
    char busca[20],respuesta;
    int lon,sw=0;
    do{
        clrscr();
        puntero = fopen("AGENDA.RE","r+b");
        fseek(puntero,0L,0);
        fread(&primer,sizeof(primer),1,puntero);
        n=primer.num;
        fflush(stdin);
        printf("Introduce el nombre del registro que deseas modificar(FIN para salir)\n");
        gets(busca);
        lon=strlen(busca);
        if(strcmp(busca,"FIN")==0)
            break;
        for(i=1;i<=n;i++){
            desplazamiento=i*sizeof(agenda);
            fseek(puntero,desplazamiento,0);
            fread(&agenda,sizeof(agenda),1,puntero);
            if(strncmp(agenda.nombre,busca,lon)==0){
                printf("%s %s %s %d\n",agenda.nombre,agenda.direccion,agenda.tlfn,agenda.edad);
                getch();
                printf("Deseas modificar este registro?\n");
                fflush(stdin);
                scanf("%c", &respuesta);
                if(respuesta=='s'){
                    clrscr();
                    printf("\nFicha numero: %d",i);
                    fflush(stdin);
                    printf("\nNombre\n");
                    gets(agenda.nombre);
                    fflush(stdin);
                    printf("Direccion\n");
                    gets(agenda.direccion);
                    fflush(stdin);
                    printf("Telefono\n");
                    gets(agenda.tlfn);
                    fflush(stdin);
                    printf("Edad\n");
                    scanf("%d", &agenda.edad);
                    fflush(stdin);

                    desplazamiento=i*sizeof(agenda);
                    fseek(puntero,desplazamiento,0);
                    fwrite(&agenda, sizeof(agenda), 1, puntero);

                    printf("Registro modificado\n");
                    sw=1;
                    getch();
                    fflush(puntero);
                    fclose(puntero);
                    break;
                }
            }
        }
        if(sw==0){
            printf("No encontrado\n");
            getch();
        }
        sw=0;
    }while(1);
    fflush(puntero);
    fclose(puntero);
    ordenar();
}

void ordenar(void)
{
    long int n=0,desplazamiento;
    Agenda registro1, registro2;
    Primer registro0;
    long int i, d;
    int sw;
    FILE *puntero;


    puntero =fopen("AGENDA.RE", "r+b");
    fseek(puntero, 0L, 0);
    fread(&registro0, sizeof(registro0), 1, puntero);
    n= registro0.num;
    d =n;

//metodo shell
    while(d>=1)
    {
        d = d/2;
        do{
            sw =0;
            for(i=1;i<=n-d;i++)
            {
            desplazamiento = i * sizeof(registro1);
            fseek(puntero, desplazamiento, 0);
            fread(&registro1, sizeof(registro1), 1, puntero);

            desplazamiento= (i+d)*sizeof(registro2);
            fseek(puntero, desplazamiento, 0);
            fread(&registro2, sizeof(registro2), 1, puntero);

                if(strcmp(registro1.nombre, registro2.nombre)>0)
                {
                    desplazamiento=i*sizeof(registro2);
                    fseek(puntero, desplazamiento, 0);
                    fwrite(&registro2, sizeof(registro2), 1, puntero);

                    desplazamiento=(i+d)*sizeof(registro1);
                    fseek(puntero, desplazamiento, 0);
                    fwrite(&registro1, sizeof(registro1), 1, puntero);

                    sw =1;
                }
            }
        }while(sw);
    }
    fclose(puntero);
}
