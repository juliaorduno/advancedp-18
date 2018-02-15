#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.1415926

// Merge sort obtained from https://www.geeksforgeeks.org/merge-sort/

void merge(double **arr, int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    double** L = (double**) malloc(n1*sizeof(double*));
    double** R = (double**) malloc(n2*sizeof(double*));

    for (i = 0; i < n1; i++){
        L[i] = malloc(2*sizeof(double));
        L[i] = arr[l + i];
    }
    for (j = 0; j < n2; j++){
        R[j] = malloc(2*sizeof(double));
        R[j] = arr[m + 1 + j];
    }

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i][0] >= R[j][0])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }

    free(L);
    free(R);
}

void mergeSort(double **arr, int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

// End of merge sort code

//Printers

void printArray(int *A, int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d\n", A[i]);
}

void printCoordinates(int n, double **coordinates)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%f ", coordinates[i][j]);
        }
        printf("\n");
    }
}

//End of printers

//Funtion to get ordered indices

void getPath(int n, double **coordinates, int *path, double **angles, double x, double y)
{
    double val = 180.0 / PI;
    double temp; 

    for (int i = 0; i < n; i++)
    {
        coordinates[i] = (double *)malloc(3 * sizeof(double));
        angles[i] = (double *)malloc(2 * sizeof(double));

        scanf("%lf", &temp);
        coordinates[i][0] = roundf(temp* 1000 / 1000);
        printf("%f", coordinates[i][0]);
        scanf("%lf", &temp);
        coordinates[i][1] = roundf(temp* 1000 / 1000);
        scanf("%lf", &coordinates[i][2]);

        angles[i][0] = atan((coordinates[i][1] + y) / (coordinates[i][0] + x)) * val;
        angles[i][1] = i;

        if (coordinates[i][0] < x)
        {
            angles[i][0] -= 180.0;
        }
    }

    printCoordinates(n, coordinates);
    mergeSort(angles, 0, n - 1);

    int index;
    for (int i = 0; i < n; i++)
    {
        index = (int)angles[i][1];
        path[i+1] = coordinates[index][2];
    }

    free(angles);
    free(coordinates);
}

int main()
{
    double x, y;
    int n;

    printf("%s\n", "Type x and y coordinates leaving a blank space between each number:");
    scanf("%lf", &x);
    scanf("%lf", &y);

    x = 0;
    y = 0;

    printf("%s\n", "Type number of friends, between 2 and 1000:");
    scanf("%d", &n);

    n = 3;

    printf("x: %f\ny: %f\nn: %d\n", x, y, n);

    double **coordinates = (double **)malloc(n * sizeof(double *));
    double **angles = (double **)malloc(n * sizeof(double *));
    int *path = (int *)calloc(n+2, (n + 2) * sizeof(int));

    getPath(n, coordinates, path, angles, x, y);

    printArray(path, n+2);

    return 0;
}