#include <stdio.h>

main()
{
    int p=0, i =0, n;
    printf("Introduce 10 numeros: ");
    do{
        i = i+1;

        scanf("%d", &n);
        if(n>0)
        {
            p += 1;
        }

    }
    while(i<=10);
    printf("Hay numeros positivos %d", p);

return 0;
}
