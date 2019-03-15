#include <stdio.h>
#include <stdlib.h>

int prime(int n)
{
    if(n == 1)
    {
        return 0;
    }
    for(int i = 2; i < n; i++)
    {
        if(n % i == 0)
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    int n1;
    int n2;
    scanf("%d%d", &n1, &n2);
    for(int i = n1 ; i <= n2; i++)
    {
        if(prime(i) == 1)
        {
            printf("%d ", i);
        }
    }
    printf("\n");
    return 0;
}
