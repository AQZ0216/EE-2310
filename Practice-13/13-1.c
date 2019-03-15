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
void reverseDispList()
{
    int temp = 0;
    for(int i = 0; i < n/2; i++)
    {
        temp = *(ptr+i);
        *(ptr+i) = *(ptr+n-1-i);
        *(ptr+n-1-i) = temp;
    }
}
void displayList()
{
    for(int i = 0; i < n; i++)
    {
        printf("Data = %d\n", *(ptr+i));
    }
}
int NodeCount()
{

}

int main()
{
    //int n;
    scanf("%d", &n);
    createNodeList(n);
    printf("Total number of nodes = %d\n", n);
    printf("Data entered in the list are:\n");
    displayList();
    reverseDispList();
    printf("\nThe list in reverse are:\n");
    displayList();
}
