#include <stdio.h>
#include <stdlib.h>

int input(char s[20])
{
    int i;
    scanf("%s", s);
    for(i = 0; s[i] != '\0'; i++)
    {
    }
    return i;
}

int is_palindrome(char *s, int n)
{
    for(int i = 0; i < n; i++)
    {
        if(*(s+i) != *(s+n-1-i))
        {
            printf("%s is not a palindrome.\n", s);
            return 0;
        }
    }
    printf("%s is a palindrome.\n", s);
    return 0;
}

int main()
{
    char s[20];
    is_palindrome(s, input(s));
    return 0;
}
