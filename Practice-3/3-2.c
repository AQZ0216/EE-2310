#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    float a;
    float b;
    float c;
    float D;
    float x1;
    float x2;
    float i;
    scanf("%f%f%f", &a, &b, &c);
    D = b*b - 4*a*c;
    if(D > 0)
    {
        x1 = (-1*b+sqrt(D))/(2*a);
        x2 = (-1*b-sqrt(D))/(2*a);
        printf("Two distinct real roots: %.4f and %.4f\n", x1, x2);
    }
    else if(D == 0)
    {
        x1 = (-1*b+sqrt(D))/(2*a);
        x2 = (-1*b-sqrt(D))/(2*a);
        printf("Two equal roots: %.4f and %.4f\n", x1, x2);
    }
    else
    {
        x1 = (-1*b)/(2*a);
        x2 = (-1*b)/(2*a);
        i = (sqrt(-D))/(2*a);
        printf("Two distinct complex roots: %.4f + %.4fi and %.4f - %.4fi\n", x1, i ,x2 , i);
    }
    return 0;
}
