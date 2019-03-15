#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, m, p, sum;
	scanf("%d%d%d", &n, &m, &p);
	int *ptrA = (int *)malloc(n*m*sizeof(int));
	int *ptrB = (int *)malloc(m*p*sizeof(int));
	for(int i = 0; i < n * m; i++)
	{
		scanf("%d", ptrA + i);
	}
	for(int i = 0; i < m * p; i++)
	{
		scanf("%d", ptrB + i);
	}
	for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < p; j++)
        {
            sum = 0;
            for(int k = 0; k < m; k++)
            {
                sum += (*(ptrA + i*m+k)) * (*(ptrB + k*p+j));
            }
            printf("%d ", sum);
        }
        printf("\n");
    }
	free(ptrA);
	free(ptrB);
    return 0;
}
ji
