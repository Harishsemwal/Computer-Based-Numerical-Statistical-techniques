// runge kutta method

#include <stdio.h>
float f(float x, float y)
{
    return (y * y - x * x) / (y * y + x * x);
}
int main()
{
    float x0 = 0, y0 = 1; // initial points;
    // scanf("%d%d",x0,y0);
    float n = 2; // number of steps;
    // scanf("%d",&n);
    float xn = 0.4; // calculation point
    // scanf("%d",&xn);
    float h = (xn - x0) / (n * 1.0);
    float x = x0, y = y0;
    for (int i = 0; i < n; i++)
    {
        float k1 = h * f(x, y);
        float k2 = h * f(x + h / 2.0, y + k1 / 2.0);
        float k3 = h * f(x + h / 2.0, y + k2 / 2.0);
        float k4 = h * f(x + h, y + k3);
        x = x + h;
        y = y + (k1 + 2 * k2 + 2 * k3 + k4) / 6.0;
    }
    printf("\nValue of y at x = %0.2f is %0.3f", xn, y);
}