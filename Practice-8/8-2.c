#include <stdio.h>
#include <stdlib.h>

char a[20] = {};
int n;

int bubble(char a[])
{
    char reg;
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
    char temp;
    scanf("%d%c", &n, &temp);
    for(int i = 0; i < n; i++)
    {
        scanf("%c%c", &a[i], &temp);
    }
    while(bubble(a) == 0)
    {

    }
    for(int i = 0; i < n; i++)
    {
        if(a[i] %2 != 0)
        printf("%c ", a[i]);
    }
    printf("\n");
    for(int i = 0; i < n; i++)
    {
        if(a[i] %2 == 0)
        printf("%c ", a[i]);
    }
    printf("\n");
    return 0;
}
