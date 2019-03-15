#include <stdio.h>
#include <stdlib.h>

int main()
{
    int m, d;
    int sum;
    scanf("%d%d", &m,&d);
    switch(m)
    {
        case 1:
            sum = d;
            printf("%d", sum);
            break;
        case 2:
            sum = 31+d;
            printf("%d", sum);
            break;
        case 3:
            sum = 31+28+d;
            printf("%d", sum);
            break;
        case 4:
            sum = 31+28+31+d;
            printf("%d", sum);
            break;
        case 5:
            sum = 31+28+31+30+d;
            printf("%d", sum);
            break;
        case 6:
            sum = 31+28+31+30+31+d;
            printf("%d", sum);
            break;
        case 7:
            sum = 31+28+31+30+31+30+d;
            printf("%d", sum);
            break;
        case 8:
            sum = 31+28+31+30+31+30+31+d;
            printf("%d", sum);
            break;
        case 9:
            sum = 31+28+31+30+31+30+31+31+d;
            printf("%d", sum);
            break;
        case 10:
            sum = 31+28+31+30+31+30+31+31+30+d;
            printf("%d", sum);
            break;
        case 11:
            sum = 31+28+31+30+31+30+31+31+30+31+d;
            printf("%d", sum);
            break;
        case 12:
            sum = 31+28+31+30+31+30+31+31+30+31+30+d;
            printf("%d", sum);
            break;
    }
    return 0;
}
