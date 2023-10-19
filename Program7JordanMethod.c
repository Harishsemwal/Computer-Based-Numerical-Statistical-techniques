// gauss jordan
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

    // upper tri
    for (int i = 0; i < n; i++) // current row
    {
        for (int j = i + 1; j < n; j++) // All rows below current row
        {
            float ratio = arr[j][i] / arr[i][i];
            for (int k = i; k <= n; k++) // column traversal of each row
            {
                arr[j][k] = arr[j][k] - ratio * arr[i][k];
            }
        }
    }

    // lower tri
    for (int i = n - 1; i >= 0; i--) // current row
    {
        for (int j = i - 1; j >= 0; j--) // All rows above current row
        {
            float ratio = arr[j][i] / arr[i][i];
            for (int k = i; k <= n; k++) // column traversal of each row
            {
                arr[j][k] = arr[j][k] - ratio * arr[i][k];
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
    for (int i = n - 1; i >= 0; i--)
    {
        sol[i] = arr[i][n] / arr[i][i];
    }

    for (int i = 0; i < n; i++)
    {
        printf("%f ", sol[i]);
    }
}