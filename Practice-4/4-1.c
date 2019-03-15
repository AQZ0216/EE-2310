#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    int i;
    int j = 0;
    scanf("%d",&n);
    for(i=2; i < n; i++)
    {
        if(n%i == 0)
        {
            j = 1;
        }
    }

    if(n == 2 || j == 0)
    {
        printf("%d is a prime.\n", n);
    }
    else
    {
        printf("%d is not a prime.\n", n);
    }
    return 0;
}
