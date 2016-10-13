#include <stdio.h>
//R3_U_V1. En la asignatura de programación, los N alumnos de una clase, tienen C notas a lo largo del
//primer trimestre, tras introducir las notas de cada alumno queremos que nos de la nota media de este.
//R3_V_V1.1 Mejorar el programa anterior, introduciendo el nombre del alumno y el número de notas que
//tiene este, ya que seguramente no todos los alumnos tengan el mismo número de notas.

int main()
{
    int i, j, n, c;
    float s, nota;
    char nombre[15];

    printf("Introduce el numero de alumnos: ");
    scanf("%d", &n);


    for(i=1;i<=n;i++)
    {
        printf("Introduce el nombre del alumno: ");
        scanf("%s", &nombre);

        printf("Introduce el numero de notas: ");
        scanf("%d", &c);

        s = 0;
        for(j=1;j<=c;j++)
        {
            printf("Del alumno %s, introduce la nota %d: ", nombre,j);
            scanf("%f", &nota);
            s += nota;
        }
        printf("\n La nota media del alumno %s, es: %.2f\n", nombre, s/c);
    }
return 0;
}
