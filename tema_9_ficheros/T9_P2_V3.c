#include <stdio.h>
#include <conio.h>


int main()
{
    char nombre[25];
    char telefono[10];
    int edad;


    FILE *registros_agenda;
    registros_agenda =fopen("AGENDA.SEC", "r");

    while(fscanf(registros_agenda,"%s %s %d", nombre, telefono, &edad) != EOF)
    {
        printf("%s %s %d\n", nombre, telefono, edad);
    }


    fclose(registros_agenda);

    return 0;
}
