#include <stdio.h>

int main()
{
     int dato = 15;
    int *apunta_a;
    int *apunta_b;

    apunta_a = &dato;
    apunta_b = &apunta_a;

    printf("El dato de apunta_a es %p\n", apunta_a);
    printf("La direccion de &apunta_a es %p\n", &apunta_a);
    printf("El dato que contiene apunta_a %d\n", *apunta_a);

    printf("El dato de apunta_b es %p\n", apunta_b);
    printf("La direccion de &apunta_b es %p\n", &apunta_b);
    printf("El dato que contiene apunta_b %p\n", *apunta_b);
}
