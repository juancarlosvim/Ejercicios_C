#include <stdio.h>


int main()
{
    char nombre[25];
    char telefono[10];
    int edad;
    int i =1;

    FILE *registros_agenda;

    registros_agenda =fopen("AGENDA.SEC", "w");


    printf("Registro  (FINALIZAR = 'FIN') ");
    printf("\n");

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



        fprintf(registros_agenda,"%s %s %d\n", nombre, telefono, edad);
    }while(1);



    fclose(registros_agenda);

    return 0;
}
