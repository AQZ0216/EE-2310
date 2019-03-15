#include <stdio.h>
#include <stdlib.h>

int a[20];
int n;

int bubble(int a[])
{
    int reg;
    int det = 1;
    for(int i = 0; i < n-1; i++)
    {
        if(a[i] < a[i+1])
        {
            reg = a[i];
            a[i] = a[i+1];
            a[i+1] = reg;
            det = 0;
        }
    }
    return det;
}

int main()
{
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    while(bubble(a) == 0)
    {

    }
    for(int i = 0; i < n; i++)
    {
        if(a[i] %2 != 0)
        printf("%d ", a[i]);
    }
    printf("\n");
    for(int i = 0; i < n; i++)
    {
        if(a[i] %2 == 0)
        printf("%d ", a[i]);
    }
    printf("\n");
    return 0;
}
