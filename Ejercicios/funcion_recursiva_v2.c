#include <stdio.h>

int sumaVector(int [], int);

int main()
{
    int vector[40];
    int i, n; // n son las posiciones del vector

    printf("Introduce el numero del componentes del vector: \n");
    scanf("%d", &n);
    //int vector[n+1];
    printf("Introduce las componentes del vector:  \n");
    for(i=1;i<=n;i++)
    {
        printf("componente %d= ",i);
        scanf("%d", &vector[i]);
    }
    printf("La suma del vector en funcion recursiva es %d", sumaVector(vector,n));
return 0;
}
int sumaVector(int vector[], int n)
{

    if(n==0){
        return 0;
    }
    else{
        return (vector[n] + sumaVector(vector,n-1));
    }


}
