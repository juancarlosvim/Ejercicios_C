#include <stdio.h>
//R3_U_V1. En la asignatura de programación, los N alumnos de una clase, tienen C notas a lo largo del
//primer trimestre, tras introducir las notas de cada alumno queremos que nos de la nota media de este.

int main()
{
    int i, j, n, c;
    float s, nota;

    printf("Introduce el numero de alumnos: ");
    scanf("%d", &n);
    printf("Introduce el numero de notas: ");
    scanf("%d", &c);

    for(i=1;i<=n;i++)
    {
        s = 0;
        for(j=1;j<=c;j++)
        {
            printf("Del alumno %d, introduce la nota %d: ", i,j);
            scanf("%f", &nota);
            s += nota;
        }
        printf("\n La nota media del alumno %d, es: %.2f\n", i, s/c);
    }
return 0;
}
