#include <stdio.h>
#include <stdlib.h>

int main()
{
  int vector[20];
  int i, j, sw, aux;
  srand(time(NULL));
  for(i=0;i<20;i++) //generamos los 20 numeros aleatorios entre  y 90
  {
	  vector[i]=rand()%90+1;
	  printf("%d\n", vector[i]);
  }
  for(i=0;i<=19;i++) //metodo de la burbuja para que el vector salga ordenado
  {
	    sw=0;
	    for(j=20;j>=j+1;j--)
	    {
		     if(vector[j-1]>vector[j]){
			      sw=1;
			      aux= vector[j-1];
			      vector[j-1]= vector[j];
			      vector[j]=aux;
		      }
	    }
	    if(sw==0){
		    break;
	      }

  }
  printf("VECTOR ORDENADO\n");
  for(i=0;i<=19;i++)
  {
	  printf("%4d\t", vector[i]);
  }
  printf("\n");
  printf("los menores son: \n");
  for(i=0;i<=9;i++)
  {
	  printf("%4d\t", vector[i]);
  }
  printf("\n");
  printf("los mayores son: \n");
  for(i=10;i<=19;i++)
    {
        printf("%4d\t", vector[i]);
  }
return 0;
}
