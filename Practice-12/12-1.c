#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    struct student
    {
        int ID;
        char name[100];
        float score;
    };
    scanf("%d", &n);
    struct student *store = (struct student *) malloc(n*sizeof(struct student));
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &(*(store+i)).ID);
        scanf("%s", &(*(store+i)).name);
        scanf("%f", &(*(store+i)).score);
    }
    for(int i = 0; i < n; i++)
    {
        printf("%d ", (*(store+i)).ID);
        printf("%s ", (*(store+i)).name);
        printf("%.4f\n", (*(store+i)).score);
    }
    return 0;
}
