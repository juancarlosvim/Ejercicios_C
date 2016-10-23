+#include <stdio.h>
  +
  +int resdiv(int, int);
  +
  +int main(){
  +    
  +    int numero1, numero2;
  +    
  +    printf("Introduzca el dividendo y el divisor ");
  +    scanf("%d%d", &numero1, &numero2);
  +    resdiv(numero1, numero2);
  +    return 0;
  +}
  +
  +int resdiv(int a, int b){
  +    
  +    int resultado;
  +    
  +    if(a>=b){
  +
  +        a-=b;
  +        printf("%d y %d ",a ,b);
  +        resultado = resdiv(a, b);
  +
  +
  +    }else{
  +        return resultado;
  +    }
  +}
