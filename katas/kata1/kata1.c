#include <stdio.h>
#include <stdlib.h>

int *anagramMappings(int *A, int ASize, int *B, int BSize, int *returnSize)
{
    for (int i = 0; i < ASize; i++)
    {
        for (int j = 0; j < BSize; j++)
        {
            if (A[i] == B[j])
            {
                returnSize[i] = j;
                printf("%d ", j);
            }
        }
    }
    printf("\n");
    return returnSize;
}

void assignValues(int sizeOfArray, int *array)
{
    for (int i = 0; i < sizeOfArray; i++)
    {
        scanf("%d", &array[i]);
    }
    printf("\n");
}

int main()
{
    int n;
    printf("Size of the array:\n");
    scanf("%d", &n);

    int A[n], B[n];

    //3,4,8,7
    //7,8,4,3

    printf("A values: \n");
    assignValues(n, A);

    printf("B values: \n");
    assignValues(n, B);

    int *P = (int *)malloc(sizeof(A));

    struct DataItem *dummyItem;

    anagramMappings(A, n, B, n, P);
    free(P);

    return 0;
}