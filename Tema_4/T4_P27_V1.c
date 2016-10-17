#include <stdio.h>

int main()
{
    int n, mayor, menor;
    printf("Introduce un numero: ");
    scanf("%d", &n);
    if(n==0){
        printf("No hay numeros:");
    }
    else{
        mayor = n;
        menor = n;
    }
    do{
        scanf("%d", &n);
        if(n==0){
            printf("mayor %d, menor %d ", mayor, menor);
        }
        else{
            if(n>mayor){
                mayor = n;
            }
            else{
                if(n<menor && n!=0){
                    menor = n;
                }
            }
        }
    }
    while(n!=0);


return 0;
}
