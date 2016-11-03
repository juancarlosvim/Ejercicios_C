#include <stdio.h>

int main()
{
    int v[11];
    int i, sw =0;

    for(i=1;i<=10;i++)
    {
        scanf("%d", &v[i]);
    }
    for(i=1;i<=5;i++)
    {
        if(v[i]!= v[11-i]){
            sw =1;
            break;
        }

    }
    if(sw==0){
        printf("Es capicua");
    }
    else{
        printf("No es capicua");
    }
return 0;
}
