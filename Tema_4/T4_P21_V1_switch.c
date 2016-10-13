#include <stdio.h>

int main()
{
    int sp = 0, si =0, i, sw = -1; //sp suma de pares, si suma de impares

    for(i=1;i<=100;i+=1)
    {
        sw -= sw;
            if(sw == i)
            {
                sp += i;
            }
            else{
                si += i;
            }
    }
    printf("la suma de los pares es %d, impares %d", sp, si);

return 0;
}
