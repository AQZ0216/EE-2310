#include <stdio.h>
#include <stdlib.h>

int main()
{
    int sub1;
    int sub2;
    int sub3;
    int sub4;
    int sub5;
    double aver;
    int g;
    scanf("%d%d%d%d%d",&sub1, &sub2, &sub3, &sub4, &sub5);
    aver = (sub1+sub2+sub3+sub4+sub5)/5.0;
    printf("Average = %.2f\n", aver);
    g = aver/10;
    switch(g)
    {
        case 10:
            printf("Grade = A+\n");
            break;
        case 9:
            printf("Grade = A+\n");
            break;
        case 8:
            printf("Grade = A\n");
            break;
        case 7:
            printf("Grade = B\n");
            break;
        case 6:
            printf("Grade = C\n");
            break;
        case 5:
            printf("Grade = D\n");
            break;
        default:
            printf("Grade = E\n");
            break;

    }
    return 0;
}
