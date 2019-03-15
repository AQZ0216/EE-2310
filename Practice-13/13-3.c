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

void MiddleNodeDeletion(int pos)
{

    if(pos < n)
    {
        for(int i = pos-1; i < n; i++)
            {
                *(ptr+i) = *(ptr+i+1);
            }
        n--;
        printf("\nDeletion completed successfully!!!\nThe new list are:\n");
        displayList();
    }
    else
    {
        printf("\nDeletion can not be possible from that position.\n");
    }
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
    MiddleNodeDeletion(temp);
}
