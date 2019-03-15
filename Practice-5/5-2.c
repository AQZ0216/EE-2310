#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    int a[99];
    int num;
    int reverseNumber = 0;
    int i;
    int j;
    scanf("%d", &n);
    num = n;
    for(i = 0; num != 0; i++)
    {
        a[i] = num % 10;
        num = (num - num % 10)/10;
    }
    for(j = 0; j < i; j++)
    {
        reverseNumber = reverseNumber*10 + a[j];
    }
    if(n == reverseNumber)
    {
        printf("%d is a palindrome.\n", n);
    }
    else
    {
        printf("%d is not a palindrome.\n", n);
    }
    return 0;
}
