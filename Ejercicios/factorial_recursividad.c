#include <stdio.h>

int factorial(int); //Prototipo de funcion

int main()
{
    printf("%d\n", factorial(5)); //Valor inicial del numero


return 0;

}

int factorial(int x)
{
    if(x==1){
        return 1;
    }
    else{
      return x * factorial(x-1);
    }

}
