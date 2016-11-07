#include <stdio.h>
#include <stdlib.h>

int main()
{
    int prediccion, inferior =1, superior =1000;
    char respuesta;
    printf("Piensa un numero del 1 al 1000 \n");
    printf("Escribe 'n' si es menor, 'm' si es mayor 's' si es crroecto el numero\n");

    do{
        prediccion=inferior+(superior-inferior)/2;
        printf("¿tu numero es %d?\n", prediccion);
        respuesta=getch();
        switch(respuesta)
        {
            case 's': printf("He acertado!, tu numero es %d", prediccion);
                        break;
            case 'n': superior=prediccion;
                        break;
            case 'm': inferior=prediccion;
                        break;
        }
    }while(respuesta!='s');

return 0;




}
