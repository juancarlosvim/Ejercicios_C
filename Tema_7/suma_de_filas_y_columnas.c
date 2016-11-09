#include <stdio.h>
#include <stdlib.h>

int main()
{
    int m[11][5];
    int i, j, sumaf=0, sumac=0;
    srand(time(NULL));

    for(i=1;i<=10;i++)
    {
        for(j=1;j<=4;j++)
        {
            m[i][j]= rand()%10+1;
            printf("%5d", m[i][j]);
        }

        puts("");
    }


    for(i=1;i<=10;i++)
    {
        sumaf=0;
        for(j=1;j<=4;j++)
        {
            sumaf += m[i][j];
        }
        printf(" - suma fila %2d es %3d\n",i,sumaf);
    }
    for(j=1;j<=4;j++)
    {
        sumac=0;
        for(i=1;i<=4;i++)
        {
            sumac += m[i][j];

        }
        printf(" - suma columna %2d es %3d\n",j,sumac);

    }
return 0;
}
