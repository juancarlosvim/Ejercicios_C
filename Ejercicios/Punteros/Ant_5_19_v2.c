#include <stdio.h>

void main(void)
{
    int a[10], *pa, *pe, x;
    a[0]=15;
    a[1]=16;
    a[2]=17;
    a[3]=18;

    pa = &a[0];
    printf("%p\n",a);
    x = *pa; //direccion
    printf("%d\n",x); //15
    pa = pa+1;
    printf("%p\n", pa); //direccion
    x = *pa; //aqui vale 16 porque la linea 15 esta pa en la direccion de memoria de a[1]
    printf("%d\n", x); //16
    x = *pa+1;
    printf("%d\n", x); //17
    x = *(pa+1);
    printf("%d\n", x); //17
    x = *(pa+1)+1;
    printf("%d\n", x); //18
    x = *(pa+1)+*pa;
    printf("%d\n", x); //33

    printf("%p\n", pa);
    pe = pa;
    printf("%p\n", pe);
    x=*pe;
    printf("%d\n", x);
}
