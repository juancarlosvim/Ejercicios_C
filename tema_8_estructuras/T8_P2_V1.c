#include <stdio.h>

typedef struct
{
    char nombre[30];
    char sexo[30];
    float salario;
    char existe;
} empleado;


int main()
{
    empleado datos[6];
    int registro, MR, mr;
    float mayor, menor;

    do{
        printf("Numero de registro: \n");
        scanf("%d", &registro);

        if(registro<=0)
        {
            continue;
        }

        printf("Introduce el nombre del empleado => \n");
        fflush(stdin);
        gets(datos[registro].nombre);
        fflush(stdin);
        printf("Introduce el sexo del empleado => \n");
        gets(datos[registro].sexo);
        fflush(stdin);
        printf("Introduce el salario del empleado => \n");
        fflush(stdin);
        scanf("%f", &datos[registro].salario);

        datos[registro].existe='V';

        printf("\n");

        mayor =datos[registro].salario;
        menor =datos[registro].salario;




    }while(registro>0);

    for(registro=1;registro<=6;registro++)
    {
        if(datos[registro].existe=='V')
        {
            if(datos[registro].salario>mayor){
                mayor = datos[registro].salario;
                MR=registro;
            }

            if(datos[registro].salario<menor)
            {
                menor = datos[registro].salario;
                mr = registro;
            }
        }
    }

    printf("Empleado con mayor salario \n");
    printf("Nombre => %s", datos[MR].nombre);
    printf("Sexo => %s", datos[MR].sexo);
    printf("Salario => %.2f", datos[MR].salario);

    printf("\n");

    printf("Empleado con menor salario \n");
    printf("Nombre => %s", datos[mr].nombre);
    printf("Sexo => %s", datos[mr].sexo);
    printf("Salario => %.2f", datos[mr].salario);

return 0;
}
