#include <stdio.h>
int miFuncion(float, float, float);

int main()
{
    int a1, an, d;
    printf("introduce tres valores: ");
    scanf("%d%d%d", &a1, &an, &d);

    printf("la suma de la progresion aritmética es: %d", miFuncion(a1,an,d));


return 0;
}

int miFuncion(float a1, float an, float d)
{
   if(a1>an)
   {
       return 0;
   }
   else{
    return(a1+miFuncion(a1+d,an,d));
   }


}
