#include <stdio.h>
//T4_P37_V3. Algoritmo que lea un n�mero entero X y otro entero positivo y calcule la N-�sima
//potencia de X. Nota: imagina que no puedes usar la funci�n pow.
int main()
{
    int numero, elevado, i, contador=1;

    printf("Introduce el primer numero y el segundo sera elevado: ");
    scanf("%d%d", &numero, &elevado);

   for(i=0;i<elevado;i++)
   {
       contador *= numero;
   }

    printf("%d^%d = %d", numero, elevado, contador);

return 0;
}
