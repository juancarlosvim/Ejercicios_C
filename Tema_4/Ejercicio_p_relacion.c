#include <stdio.h>
int calculo();
int main()
{
    int m, n;
    printf("Introduce m, n: ");
    scanf("%d%d", &n, &m);
    calculo(n,m);

return 0;
}

int calculo(int n, int m)
{
    int resultado, i, total;
    for(i=1;i<=m;i++)
    {
        resultado = n* (n-1)*(n-2);
        total += m * i;
    }

    printf("%d", resultado);
}
