// regression
#include <stdio.h>
    int
    main()
{
    int n, i;
    float x[50], y[50], sumX = 0, sumX2 = 0, sumY = 0, sumXY = 0, a, b;
    printf("How many data points?\n");
    scanf("master%d", &n);
    printf("Enter data:\n");
    for (i = 1; i <= n; i++)
    {
        printf("x[%d]=", i);
        scanf("%f", &x[i]);
        printf("y[%d]=", i);
        scanf("%f", &y[i]);
    }
    for (i = 1; i <= n; i++)
    {
        sumX = sumX + x[i];
        sumX2 = sumX2 + x[i] * x[i];
        sumY = sumY + y[i];
        sumXY = sumXY + x[i] * y[i];
    }
    b = (n * sumXY - sumX * sumY) / (n * sumX2 - sumX * sumX);
    a = (sumY - b * sumX) / n;
    printf("Values are: a=%f and b = %f", a, b);
    printf("\nEquation of best fit is: y = %f + %fx", a, b);
    return (0);
}