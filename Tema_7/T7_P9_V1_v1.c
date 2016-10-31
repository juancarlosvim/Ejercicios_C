#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main()
{
    int vector[7], vectorA[11][6];
    int i, j, k, c=0;

    srand(time(NULL)); // generamos aleatorios
    vector[1] = rand()%49+1;

    for(i=2;i<=6;i++)
    {
        vector[i] = rand()%49+1;
        for(j=1;j<=i-1;j++)
        {
            if(vector[i]==vector[j]){
                j = i - 1;
                break;
            }
        }
    }
    gotoxy(1,14);
    printf("Los numeros aleatorios son: ");
    for(i=1;i<=6;i++)
    {
        gotoxy(i*4,15);
        printf("%d", vector[i]);
    }
    for(i=1;i<=5;i++)
    {
        for(j=1;j<=10;j++)
        {
            vectorA[i][j]= c;
            c = c+1;
            if(vectorA[i][j] !=0){
                gotoxy(i*4,j);
                printf("%d", vectorA[i][j]);
            }
            for(k=1;k<=6;k=k+1)
            {
                if(vectorA[i][j] == vector[k]){
                    gotoxy("i*4", j);
                    printf("XX");
                }
            }
        }
    }
    getch();
return 0;
}
