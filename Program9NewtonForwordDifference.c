#include <stdio.h>

void generateForwardDifferenceTable(double y[], double forwardTable[][100], int n)
{
    for (int i = 0; i < n; i++)
    {
        forwardTable[i][0] = y[i];
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            forwardTable[j][i] = forwardTable[j + 1][i - 1] - forwardTable[j][i - 1];
        }
    }
}

double evaluateInterpolation(double x, double x0, double forwardTable[][100], double h, int n)
{
    double result = forwardTable[0][0];
    double term = (x0 - x) / h;
    double act = term;
    int fact = 1;

    for (int i = 1; i < n; i++)
    {
        double val = (term * forwardTable[0][i]) / fact;
        result += val;
        fact *= (i + 1);
        term = term * (act - i);
    }
    return result;
}

int main()
{
    int n;
    printf("Enter the number of data points and the point of calculation: ");
    scanf("%d", &n);
    printf("\n");

    double x[100], y[100], x0, h, result;

    printf("Enter the point at which you want to calculate the interpolation: ");
    scanf("%lf", &x0);

    printf("Enter the data points (x, y):\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%lf %lf", &x[i], &y[i]);
    }

    double forwardTable[100][100] = {0};

    generateForwardDifferenceTable(y, forwardTable, n);

    printf("Complete Forward Difference Table:\n");
    printf("    x      y");

    for (int i = 0; i < n - 1; i++)
    {
        printf("      Δ^%d y", i + 1);
    }

    printf("\n");

    for (int i = 0; i < n; i++)
    {
        printf("%.4lf      ", x[i]);
        for (int j = 0; j < n - i; j++)
        {
            printf("%.4lf      ", forwardTable[i][j]);
        }
        printf("\n");
    }

    h = x[1] - x[0];
    result = evaluateInterpolation(x[0], x0, forwardTable, h, n);
    printf("\nInterpolated value at x = %.2lf is %.6lf\n", x0, result);

    return 0;
}