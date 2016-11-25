#include <stdio.h>
#include <string.h>
main()
{
    char apellido[20][20],aux[20],busca[20];
    int i,distancia,cen,sw,izq,der,inicio,fin;
    for (i=0;i<20;i++){
        printf("Introduce el apellido: ");
        gets(apellido[i]);
    }
    printf("\nLISTA DE APELLIDOS DESORDENADOS\n");
    for (i=0;i<20;i++){
        printf("%s\n", apellido[i]);
    }
    distancia=20;
    while (distancia!=1){
        if (distancia==1)
            break;
        distancia=distancia/2;
        sw=1;
        do{
                sw=0;
                for (i=0;i<20-distancia;i++){
                    if (strcmp(apellido[i],apellido[i+distancia])>0){
                        strcpy(aux,apellido[i+distancia]);
                        strcpy(apellido[i+distancia],apellido[i]);
                        strcpy(apellido[i],aux);
                        sw=0;
                    }
                }
                if (sw==0)
                    break;
        }while(1);
    }
    printf("\nLISTA DE APELLIDOS ORDENADOS\n");
    for (i=0;i<20;i++){
        printf("%s\n", apellido[i]);
    }
    do{
            printf("Introdce el apellido a buscar: ");
            gets(busca);
            if (strcmp(busca,"fin")==0)
                break;
            izq=0;
            der=20;
            do{
                cen=(izq+der)/2;
                if (strcmp(busca,apellido[cen])==0||(izq>=der)){
                    if (strcmp(busca,apellido[cen])==0){
                        inicio=cen;
                        fin=cen;
                        while (inicio>=0){
                            if (strcmp(busca,apellido[inicio])==0)
                                inicio=inicio-1;
                            else
                                break;
                        }
                        inicio=inicio+1;
                        while (fin<=19){
                            if (strcmp(busca,apellido[fin])==0)
                                fin=fin+1;
                            else
                                break;
                        }
                        fin=fin-1;
                        for (i=inicio;i<=fin;i++){
                            printf("Se encuentra en la posicion: %d\n", i);
                        }
                    }
                    else
                        printf("No encontrado\n");
                    break;
                }
                if (strcmp(busca,apellido[cen])>0)
                    izq=cen+1;
                else
                    der=cen-1;
            }while(1);
    }while (strcmp(busca,"fin")!=0);
return 0;
}
