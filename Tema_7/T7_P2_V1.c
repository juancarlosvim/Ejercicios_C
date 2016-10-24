#include <stdio.h>
//Algoritmo que lea las calificaciones de un alumno en 10 asignaturas, las almacena en un
//vector y calcula e imprime su media.

int main()
{
    int vector[11], i;
    float media;
    for(i=1;i<=10;i++)
    {
        printf("Introduce la nota %d: ", i);
        scanf("%d", &vector[i]);
    }

    for(i=1;i<=10;i++)
    {
    media += vector[i];
    }
    printf("la media es %.2f", media/10);

return 0;
}
