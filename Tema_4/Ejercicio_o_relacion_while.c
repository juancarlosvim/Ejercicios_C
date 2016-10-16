//o) Calcular el producto de los N primeros números naturales (sin contar el cero), es decir el
//factorial de N (N!).
#include <stdio.h>

int main()
{
    int i =1, n, producto = 1;

    printf("Introduce un numero para calcular el producto de los N primeros numeros naturales: ");
    scanf("%d", &n);
    while(i<=n){

        producto = producto * i;
        i++;
    }
    printf("%d", producto);
return 0;
}
