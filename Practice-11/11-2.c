#include <stdio.h>
#include <stdlib.h>

int main()
{
	int max = 0;
	int temp = 0;
	int startChar = 0;
	int k;
	char *ptrA = (char *) malloc(1000*sizeof(char));
	char *ptrB = (char *) malloc(1000*sizeof(char));
	scanf("%s%s", ptrA, ptrB);
    for(int i = 0; *(ptrA + i) != '\0'; i++)
    {
        for(int j = 0; *(ptrB + j) != '\0';j++)
        {
            for(k = 0; *(ptrA +i+k) == *(ptrB +j+k) && *(ptrA +i+k) != '\0'; k++)
            {
            }
            if(k > temp)
            {
                temp = k;
            }
        }
        if(temp > max)
        {
            max = temp;
            startChar = i;
        }
    }
    for(int i = 0; i < max; i++)
    {
        printf("%c", *(ptrA +startChar+i));
    }
    printf("\n");
	free(ptrA);
	free(ptrB);
    return 0;
}
