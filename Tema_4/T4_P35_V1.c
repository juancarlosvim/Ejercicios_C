#include <stdio.h>

int main()
{
    int a, b, c, m, aux;

    printf("Introduce dos numeros: ");
    scanf("%d%d", &a, &b);

    m = a * b;
    if(a<b){
        aux = a;
        a = b;
        b = aux;
    }
    do{

        c = a % b;
        a = b;
        b = c;


    }
    while(c!=0);
    {
        printf("M.C.D %d\n", a);
        m= m /a;
        printf("m.c.m %d\n", m);
    }
return 0;
}
