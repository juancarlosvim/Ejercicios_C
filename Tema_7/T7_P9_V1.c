#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main()
{
    int  vector[7], vectorB[10][5];
    int i, j, contador =0, sw;

    //srand(time(NULL));

    for(i=1;i<=7;i++)
    {

        for(j=1;j<=7;j++)
        {

            contador++;
            vectorB[j][i] = contador;
            //printf("\n%d", vectorB[i][j]);
        }
        puts("");
    }
    for(i=1;i<=7;i++)
    {
        for(j=1;j<=7;j++)
        {


            gotoxy(3*i,j);
            printf("%d", vectorB[j][i]);
        }
    }
    puts("");
//aleatorios

    srand(time(NULL));
    vector[1] = rand()%49+1;
    i= 2;
    do{
        vector[i] = rand()%49+1;
        sw = 0;
        for(j=i-1;j>=1;j--)
        {
            if(vector[i]==vector[j]){
                sw = 1;
                break;
            }
        }
        if(sw == 1){
            continue;
        }
        else{
            i+=1;
        }
    }
    while(i<=6);

    for(i=1;i<=6;i++)
    {
        printf("%2d", vector[i]);
    }

return 0;
}
