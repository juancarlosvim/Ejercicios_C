#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define max 30

int main()
{
    char nombre[max], mayorN[max], menorN[max];
    float s, mayorS, menorS;
    int i;

    printf("Introduzca el nombre => ");
    fgets(nombre, max, stdin);
    printf("Introduzca el sueldo => ");
    scanf("%f", &s);
    strcpy(mayorN, nombre);
    strcpy(menorN, nombre);
    mayorS = s;
    menorS = s;

    for(i=2;i<=10;i++)
    {
        fflush(stdin);
        fgets(nombre, max, stdin);
        scanf("%f",&s);
        if(s>mayorS){
            strcpy(mayorN, nombre);
            mayorS = s;
        }
        else{
            if(s<menorS){
                strcpy(menorN, nombre);
                menorS = s;
            }
        }
    }

    printf("MayorN = %s\t MayorS = %f\n MenorN = %s\t MenorS = %f\n", mayorN, mayorS, menorN, menorS);
return (0);
}
