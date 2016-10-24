#include <stdio.h>

int main()
{
    printf("Tabla de valores de sizeof\n");

    printf("Dato       \tBytes\tBits\n");
    printf("char       \t%5d\t%4d\n",sizeof(char), sizeof(char)*8);
    printf("short       \t%5d\t%4d\n",sizeof(short), sizeof(short)*8);
    printf("int       \t%5d\t%4d\n",sizeof(int), sizeof(int)*8);
    printf("long       \t%5d\t%4d\n",sizeof(long), sizeof(long)*8);
    printf("float       \t%5d\t%4d\n",sizeof(float), sizeof(float)*8);
    printf("double       \t%5d\t%4d\n",sizeof(double), sizeof(double)*8);
    printf("long double   \t%5d\t%4d\n",sizeof(long double), sizeof(long double)*8);
return 0;
}
