#include <stdio.h>

long factorial (int numero);

int main() {
    int n, m;
    long A, B, C;

    printf("Introduce M y N: ");
    scanf("%d %d", &m, &n);

    A = factorial(m);
    printf("A = %ld\n", A);
    //B = factorial(n);
    //printf("B = %ld\n", B);
    C = factorial(m-n);
    printf("C = %ld\n", C);
    printf("Variaciones = %ld \n", A / C);
    //printf("Combinaciones = %ld \n", A / (B*C));
}

long factorial (int numero) {
    int i;
    long factorial = 1;

    for (i=1;i<=numero;i++) {
        factorial *= i;
    }

    return factorial;
}
