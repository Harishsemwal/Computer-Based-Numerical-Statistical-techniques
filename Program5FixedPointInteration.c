#include <stdio.h>
#include <math.h>
double func(double x)
{
    double res = (log10(x) + 7) / 2.0;
    return res;
}
int funcdiff(double x)
{
    double res = (1 / x) / 2.0;
    return res < 1;
}

int main()
{
    double x0 = 3.8, prev = x0;
    do
    {
        if (funcdiff(x0))
        {
            prev = x0;
            x0 = func(x0);
        }
        else
        {
            printf("No Solution...");
        }
    } while ((fabs(x0 - prev) > 0.0001));

    printf("the approximate values %d\n", prev);
}