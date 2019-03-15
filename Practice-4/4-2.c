#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    int p;
    int i;
    int j;
    scanf("%d%d", &n, &p);
    switch(p)
    {
        case 1:
            for(i = n; i >= 1; --i)
            {
                for(j=1; j <= i; j++)
                {
                    printf("%d", i);
                }
                printf("\n");
            }
            break;
        case 2:
             for(i = n; i >= 1; i--)
            {
                for(j=i; j >= 1; j--)
                {
                    printf("%d", j);
                }
                printf("\n");
            }
            break;
        case 3:
            printf("Unrecognized pattern!\n");
            break;
    }
    return 0;
}
