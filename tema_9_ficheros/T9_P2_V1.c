#include <stdio.h>


int main()
{
    char nombre[25];
    char telefono[10];
    int edad;
    int i =1;

    FILE *registros_agenda;

    registros_agenda =fopen("AGENDA.SEC", "w");

    printf("Introduce 5 registros agenda\n");

    for(i=1;i<=5;i++)
    {
        printf("Registro %d\n", i);
        printf("Nombre => ");
        fflush(stdin);
        scanf("%s", &nombre);

        printf("Telefono => ");
        fflush(stdin);
        scanf("%s", &telefono);

        printf("Edad => ");
        fflush(stdin);
        scanf("%d", &edad);

        fprintf(registros_agenda,"%s %s %d\n", nombre, telefono, edad);
    }

    fclose(registros_agenda);

    return 0;
}
