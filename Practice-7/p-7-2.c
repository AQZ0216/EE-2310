#include <stdio.h>

int check_palindrome(int n)
{
    int num;
    int a[10];
    int reverseNumber = 0;
    int i;
    int j;
    num = n;
    for(i = 0; n != 0; i++)
    {
        a[i] = n % 10;
        n = (n - n % 10)/10;
    }
    for(j = 0; j < i; j++)
    {
        reverseNumber = reverseNumber*10 + a[j];
    }
    if(num == reverseNumber)
    {
        return 1;
    }
    else
    {
        return 0;
    }

    /* Complete this function,
    if n is a palindrome, return 1, otherwise return 0.*/

}

/* DO NOT change any word in the main fuction*/

int main()
{
    int n;
    /* Input a number from user */
    scanf("%d", &n);
    /* Check if n is palindrome or not */
    if(check_palindrome(n)==1)
        printf("%d is a palindrome.\n", n);
    else
        printf("%d is not a palindrome.\n", n);
    return 0;
}
