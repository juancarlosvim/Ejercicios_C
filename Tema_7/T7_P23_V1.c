#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numero, x, contador;
    srand(time(NULL));
    numero = rand()%1000+1;
    printf("Acierte el numero que he generado entre el 1 y el 1000\n");

    do{
        contador++;
        scanf("%d", &x);
        if(x==numero){
            printf("Has acertado");
            break;
        }
        else{
             if(x<numero){
                printf("Es mayor\n");
                contador++;
            }
            if(x>numero){
                printf("Es menor\n");
                contador++;
            }

        }

    }while(1);
return 0;
}
