#include <stdio.h>

int main()
{
    int p=0, n, contador  = 0;

    printf("Introduce 10 numeros: ");
    while(contador<10)
    {
        scanf("%d", &n);

        if(n>0)
        {
            p += 1;

        }contador++;

    }
    printf("Hay %d numeros positivos", p);
    

return 0;
}
