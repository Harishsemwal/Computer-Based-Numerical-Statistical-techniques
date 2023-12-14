// curve fitting for a straight line
#include <stdio.h>
#include <conio.h>
#include <math.h>
int main()
{
    int n, i, x[20], y[20];
    float a, b, sumx = 0.0, sumy = 0.0, sumxy = 0.0, sumx2 = 0.0;
    printf("Enter the value of number of terms n:");
    scanf("%d", &n);
    printf("\nEnter the values of x:\n");
    for (i = 0; i <= n - 1; i++)
    {
        scanf(" %d", &x[i]);
    }
    printf("\n Enter the values of y:");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &y[i]);
    }
    for (i = 0; i <= n - 1; i++)
    {
        sumx = sumx + x[i];
        sumx2 = sumx2 + x[i] * x[i];
        sumy = sumy + y[i];
        sumxy = sumxy + x[i] * y[i];
    }
    a = ((sumx2 * sumy - sumx * sumxy) / (n * sumx2 - sumx * sumx));
    b = ((n * sumxy - sumx * sumy) / (n * sumx2 - sumx * sumx));
    printf("\n\nThe line is Y=%f +%f X", a, b);
    return (0);
}