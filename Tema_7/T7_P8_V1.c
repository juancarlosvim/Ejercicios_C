#include <stdio.h>

int main()
{
    int vectorA[15][2] = {{246, 6}, {255, 18}, {261, 21}, {275, 0}, {283, 45}, {294, 17}, {298, 19}, {306, 4}, {315, 163}, {326, 17},
    {335, 3}, {343, 81}, {356, 46}, {364, 18}, {375, 16}};
    int i, j, codigo, sw;

    printf("Datos de la tabla: \n");
    for(i=0;i<=14;i++) //muestra los datos del vectorA
    {
        for(j=0;j<=1;j++)
        {
            printf("%d", vectorA[i][j]);
            printf("\n");
        }
    }
    do{
        printf("Introduce el codigo de la pieza a buscar (FIN=0); \n");
        scanf("%d", &codigo);
        if(codigo==0){
            break;
        }
        sw =0;
        for(i=0;i<=14;i++)
        {
            if(codigo==vectorA[i][0])
            {
                sw =1;
                printf("Codigo: %d, existencias, %d", codigo, vectorA[i][1]);
            }
            if(sw==0){
                printf("No existe este codigo");
            }

        }

    }
    while(1);
return 0;
}
