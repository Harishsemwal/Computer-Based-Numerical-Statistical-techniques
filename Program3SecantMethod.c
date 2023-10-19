#include <stdio.h>
#include <math.h>
float func(float x)
{
    return (x * x * x - 5 * x + 1.0);
}
int main()
{
    printf("Enter the initial points x0,x1\n");
    float x0, x1;
    scanf("%f %f", &x0, &x1);
    float x2 = x1;
    do
    {
        x1 = x2;
        x2 = x1 - ((x1 - x0) / (func(x1) - func(x0))) * func(x1);
        printf("%f\n", x2);
        x0 = x1;
    } while (fabs(x1 - x2) >= 0.00009);
    printf("%f", x2);
}