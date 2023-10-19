// gauss elimination
#include <stdio.h>
int main()
{
    int n;
    printf("Enter the value of n \n");
    scanf("%d", &n);
    float arr[n][n + 1];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            scanf("%f", &arr[i][j]);
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (j > i)
            {
                float ratio = arr[j][i] / arr[i][i];
                for (int k = 0; k <= n; k++)
                {
                    arr[j][k] = arr[j][k] - (ratio * arr[i][k]);
                }
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            printf("%f ", arr[i][j]);
        }
        printf("\n");
    }

    float sol[n];
    sol[n - 1] = arr[n - 1][n] / arr[n - 1][n - 1];

    for (int i = n - 2; i >= 0; i--)
    {
        float sum = 0;
        for (int j = i + 1; j < n; j++)
        {
            sum += (arr[i][j] * sol[j]);
        }
        sol[i] = (arr[i][n] - sum) / arr[i][i];
    }
    for (int i = 0; i < n; i++)
    {
        printf("%f ", sol[i]);
    }
}