#include <stdio.h>
int miFuncion(float, float, float);

int main()
{
    int a1, an, r;
    printf("introduce tres valores:(a1)(an)(r) ");
    scanf("%d%d%d", &a1, &an, &r);

    printf("la suma de la progresion geometrica es: %d", miFuncion(a1,an,r));


return 0;
}

int miFuncion(float a1, float an, float r)
{
   if(a1>an)
   {
       return 0;
   }
   else{
    return(a1+miFuncion(a1*r,an,r));
   }


}
