#include <stdio.h>
#include <math.h>
int main()
{
    int n;
    printf("Enter the number of observations: ");
    scanf("%d", &n);
    double y[n][n];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            y[i][j] = 0;
    double xi[n];
    double x;
    printf("Enter row xi: \n");
    for (int i = 0; i < n; i++)
        scanf("%lf", &xi[i]);
    printf("Enter f(xi) row:\n");
    for (int i = 0; i < n; i++)
        scanf("%lf", &y[0][i]);

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            y[i][j] = y[i - 1][j + 1] - y[i - 1][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        printf("%.4lf\t", xi[i]);
        for (int j = 0; j < n - i; j++)
        {
            printf("%.4lf\t", y[j][i]);
        }
        printf("\n");
    }

    printf("\nEnter x: ");
    scanf("%lf", &x);

    double u = (x - xi[n / 2 - 1]) / (xi[1] - xi[0]);
    printf("%lf \n", u);
    double ans = y[0][n / 2 - 1];
    printf("%lf ", ans);
    double prod = u;
    int fact = 1;
    int c = 1;

    for (int i = 1; i < n; i++)
    {
        ans += prod * y[i][(n - i - 1) / 2] / fact;
        fact *= (i + 1);
        if (i % 2)
            prod = prod * (u - c);
        else
        {
            prod = prod * (u - c);
            c++;
        }
    }
    printf("\nTherefore, f(%.3lf) is %.3lf\n", x, ans);
    return 0;
}