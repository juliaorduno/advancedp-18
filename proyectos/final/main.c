#include <stdio.h>
#include <stdlib.h>

void getData(int n, int m, int **prices, int **coupons)
{
    for (int i = 0; i < n; i++)
    {
        prices[i] = (int *)malloc(m * sizeof(int));
        for (int j = 0; j < m; j++)
        {
            scanf(" %d", &prices[i][j]);
        }
    }

    for (int i = 0; i < n; i++)
    {
        coupons[i] = (int *)malloc(m * sizeof(int));
        for (int j = 0; j < m; j++)
        {
            scanf(" %d", &coupons[i][j]);
        }
    }
}

int getLeastAmount(int n, int m, int **prices, int **coupons)
{
    int minValue;
    int current, optionA, optionB, discount, currN;
    int currentPrice = 0;

    for (int i = 0; i < n - 1; i++)
    {
        minValue = 100;
        for (int j = 0; j < m; j++)
        {
            currN = i + 1;
            current = prices[i][j];
            discount = coupons[i][j];
            if (prices[currN][j] > discount)
            {
                optionA = current + prices[currN][j] - discount;
            }
            else
            {
                optionA = 0;
            }

            for (int k = 0; k < m; k++)
            {
                if (k == j)
                {
                    continue;
                }

                optionB = current + prices[currN][k];
                if (optionB < optionA)
                {
                    optionA = optionB;
                }
            }
            if (optionA < minValue)
            {
                minValue = optionA;
            }
        }
        currentPrice += minValue;
    }

    return currentPrice;
}

int main()
{
    int n, m;
    int t;
    scanf("%d", &t);

    for (int i = 0; i < t; i++)
    {
        n = 0;
        m = 0;
        scanf("%d %d", &n, &m);

        int **prices = (int **)malloc(n * sizeof(int *));
        int **coupons = (int **)malloc(n * sizeof(int *));

        getData(n, m, prices, coupons);
        int minPrice = getLeastAmount(n, m, prices, coupons);
        free(prices);
        free(coupons);
        printf("%d\n", minPrice);
    }
}