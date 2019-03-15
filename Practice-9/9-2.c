#include <stdio.h>
#include <stdlib.h>

int num_inv(int *a, int n)
{
    int sum = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = i+1; j < n; j++)
        {
            if(*(a+i)>*(a+j))
            {
                sum++;
            }
        }
    }
    return sum;
}

int main()
{
    int a[20];
    int n;
    int i;
    for(i = 0;a[i-1] != -1; i++)
    {
        scanf("%d", &a[i]);
    }
    n = i-1;
    printf("%d\n", num_inv(a, n));
    return 0;
}
