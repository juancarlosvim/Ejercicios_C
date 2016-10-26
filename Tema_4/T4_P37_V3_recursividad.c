#include <stdio.h>
//T4_P37_V3. Algoritmo que lea un número entero X y otro entero positivo y calcule la N-ésima
//potencia de X. Nota: imagina que no puedes usar la función pow.
int potencia(int, int);
int main()
{
    int numero, elevado;

    printf("Introduce el primer numero y el segundo sera elevado: ");
    scanf("%d%d", &numero, &elevado);

    potencia(numero, elevado);



    printf("%d^%d = %d", numero, elevado, potencia(numero,elevado));

return 0;
}

int potencia(a, b)
{
    if(b==0)
    {
        return 1;
    }
    else{
        return (a*potencia(a,b-1));
    }
}
