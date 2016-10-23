#include <stdio.h>
#include <math.h>

int main()
{
    int numero, numerox,numeroc, i;
    float f;
    f = 0;
    printf("Introduce el grado del polinomio: \n");
    scanf("%d", &numero);
    printf("Introduce el valor de la variable: \n");
    scanf("%d", &numerox);
    printf("Introduce los coeficientes del polinomio: \n");
    for(i=numero;i>=0;i--)
    {
        printf("Coeficiente de x^%d: ", i);
        scanf("%d", &numeroc);
        f = f + numeroc * pow(numerox,i);
    }
    printf("f(x) = %.2f", f);
return 0;
}
