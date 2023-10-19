#include <stdio.h>
#include <math.h>
double func(double x)
{
    return x * x * x - 9 * x + 1;
}

double funcdas(double x)
{
    return 3 * x * x - 9;
}
int main()
{
    double x0 = 2.0;
    double x1;
    double prev;
    do
    {
        prev = x0;
        x1 = x0 - (func(x0) / funcdas(x0));
        x0 = x1;
    } while (fabs(x1 - prev) > (0.0001));

    printf("the approximate value : %lf", prev);
    return 0;
}