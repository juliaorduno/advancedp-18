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

long getLeastAmount(int n, int m, int **prices, int **coupons)
{
    long dp[n][m], temp;
    long minValue = 1000000;
    int current, discount, optionA, optionB;

    for (int j = 0; j < m; j++)
    {
        dp[0][j] = prices[0][j];
        if (minValue > dp[0][j])
        {
            minValue = dp[0][j];
        }
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            current = prices[i][j];
            discount = coupons[i - 1][j];
            temp = current - discount;

            if (temp < 0)
            {
                temp = 0;
            }
            optionA = temp + dp[i - 1][j];
            optionB = minValue + current;
            dp[i][j] = optionA < optionB ? optionA : optionB;
        }

        minValue = dp[i][0];

        for (int j = 1; j < m; j++)
        {
            if (minValue > dp[i][j])
            {
                minValue = dp[i][j];
            }
        }
    }

    return minValue;
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
        long minPrice = getLeastAmount(n, m, prices, coupons);
        free(prices);
        free(coupons);
        printf("%ld\n", minPrice);
    }
}