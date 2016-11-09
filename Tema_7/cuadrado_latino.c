#include <stdio.h>
#include <conio.h>
#define n 10

int main()
{
    int i, j, b[n+1][n+1];
    for(i=1;i<=n;i++)
    {
        b[1][i]=i;
    }
    for(i=2;i<=n;i++)
    {
        for(j=2;j<=n;j++)
        {
            b[i][j]=b[i-1][j-1];
        }
        b[i][1]=b[i-1][n];
    }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
          gotoxy(j*3+15,i*2+3);
          printf("%d", b[i][j]);
        }
    }
return 0;
}
