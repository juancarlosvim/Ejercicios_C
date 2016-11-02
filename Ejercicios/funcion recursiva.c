#include <stdio.h>

int sumaVector();

int main()
{
    int vector[15] = {};
    int i, n=15; // n son las posiciones del vector
    printf("Introduce 15 elementos: ");
    for(i=1;i<=15;i++)
    {
        scanf("%d", &vector[i]);
    }
    printf("La suma del vector en funcion recursiva es %d", sumaVector(vector,n));
return 0;
}
int sumaVector(int vector[], int n)
{

    if(n==0){
        return vector[0];
    }
    else{
        return (vector[n] + sumaVector(vector,n-1));
    }


}
