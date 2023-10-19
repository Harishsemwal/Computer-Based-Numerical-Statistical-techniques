#include <stdio.h>
#include <math.h>
float fun(float x)
{
    return (x * x - 3.0);
}
int main()
{
    printf("Enter the initial points x0,x1\n");
    float x0, x1, x2 = 0.0, prevX2 = 0.0;
    scanf("%f %f", &x0, &x1);
    do
    {
        prevX2 = x2;
        x2 = (x0 + x1) / 2.0;
        if (fun(x2) * fun(x0) >= 0)
        {
            x0 = x2;
        }
        else
        {
            x1 = x2;
        }
        printf("%f %f\n", x0, x1);
    } while (fabs(prevX2 - x2) >= 0.00009);
    printf("%f", x2);
}