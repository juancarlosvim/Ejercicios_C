#include <stdio.h>

int main()
{
    int n, mayor;
    printf("Introduce un numero: ");
    scanf("%d", &n);
    if(n==0){
        printf("No hay numeros:");
    }
    else{
        mayor = n;

    }
    do{
        scanf("%d", &n);
        if(n==0){
            printf("mayor %d", mayor);
        }
        else{
            if(n>mayor){
                mayor = n;
            }

        }
    }
    while(n!=0);


return 0;
}
