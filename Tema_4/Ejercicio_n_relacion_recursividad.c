#include <stdio.h>
int suma(int);
int main()
{
    printf("%d", suma(19));
return 0;
}

int suma(int a)
{
    if(a==1){
        return 1;
    }
    else{
        return a*a + suma(a-1);
    }
}
