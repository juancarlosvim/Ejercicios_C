#include <stdio.h>


int main()
{
    char nombre[25];
    char telefono[10];
    int edad;

    FILE *agenda;
    FILE *nuevo;

    agenda =fopen("AGENDA.SEC", "r");
    nuevo = fopen("NUEVO.SEC", "w");
    //LEER USUARIOS
    while(fscanf(agenda,"%s %s %d", nombre, telefono, &edad) != EOF)
    {
        printf("%s %s %d\n", nombre, telefono, edad);
    }
    fclose(agenda);



    printf("Registro  (FINALIZAR = 'FIN') ");
    printf("\n");
    //NUEVOS USUARIOS
    do{

        printf("Nombre => ");
        fflush(stdin);
        scanf("%s", &nombre);
        if(strcmp(nombre, "FIN")==0){
            break;
        }
        printf("Telefono => ");
        fflush(stdin);
        scanf("%s", &telefono);
        printf("Edad => ");
        fflush(stdin);
        scanf("%d", &edad);



        fprintf(nuevo,"%s %s %d\n", nombre, telefono, edad);
    }while(1);

    fclose(nuevo);

    remove("AGENDA.SEC");
    rename("NUEVO.SEC", "AGENDA.SEC");

    return 0;
}
