#include <stdio.h>
#include <stdlib.h>
int *ptr;
int n;

void createNodeList(int n)
{
    ptr = (int *) malloc(n * sizeof(int));
    for(int i = 0; i < n; i++)
    {
        scanf("%d", ptr+i);
    }
}

void InsertNodeatEnd(int l)
{
    *(ptr+n) = l;
    n++;
}

void displayList()
{
    for(int i = 0; i < n; i++)
    {
        printf("Data = %d\n", *(ptr+i));
    }
}

int main()
{
    int temp;
    scanf("%d", &n);
    createNodeList(n);
    scanf("%d", &temp);
    printf("Data entered in the list are:\n");
    displayList();

    InsertNodeatEnd(temp);
    printf("\nData, after inserted in the list are:\n");
    displayList();
}
