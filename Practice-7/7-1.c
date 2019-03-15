#include <stdio.h>
#include <stdlib.h>

int GCD_generator(int n1, int n2)
{
	int a;
	int b;	
	a = n1;
    b = n2;
    while(a*b != 0)
    {
        if(a > b && b != 0)
        {
            a = a % b;
        }
        if(b > a && a != 0)
        {
            b = b % a;
        }
    }
    if(a == 0)
    {
        return b;
    }
    else
    {
        return a;
    }
}

	
int main()
{
    int n1;
    int n2;
    int GCD;
    int LCM;
    int a;
    int b;
    scanf("%d%d", &n1, &n2);
	GCD = GCD_generator(n1, n2);
    LCM = n1*n2/GCD;
    printf("GCD = %d\nLCM = %d\n", GCD, LCM);
    return 0;
}
