#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, m, p, sum;
    int a[50][50];
    int b[50][50];
    scanf("%d%d%d", &n, &m, &p);
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < p; j++)
        {
            scanf("%d", &b[i][j]);
        }
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < p; j++)
        {
            sum = 0;
            for(int k = 0; k < m; k++)
            {
                sum += a[i][k]*b[k][j];
            }
            printf("%d ", sum);
        }
        printf("\n");
    }
    return 0;
}
