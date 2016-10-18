#include <stdio.h>

int main()
{
    int n;
    int sw = 0;
    int mayor;

        scanf("%d", &n);
        if(n<0){
            sw = 1;
        }
        else{
            if(n==0){
                printf("No ha introducido numeros");
            }
            else{
              mayor = n;
            }
        }

        do{
            scanf("%d", &n);
            if(n<0){
                sw = 1;
            }
            else
            if(n ==0){
                printf("El mayor es %d\n", mayor);
                if(sw ==1){
                    printf("Hay numeros negativos");
                }
            }
            else
                if(n>mayor)
                {
                    mayor = n;
                }
        }
        while(n !=0);

}
