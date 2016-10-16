//o) Calcular el producto de los N primeros números naturales (sin contar el cero), es decir el
//factorial de N (N!).
#include <stdio.h>

int main()
{
    int i=0 , n =0, producto=1;

    printf("Introduce un numero para calcular el producto de los N primeros numeros naturales: ");
    scanf("%d", &n);
    for(i=1;i<=n;i++)
    {
        producto= producto * i;


    }
    printf("El total del  prodcuto es %d", producto);

return 0;
}
