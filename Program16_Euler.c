// eulers method
#include <stdio.h>
float f(float x, float y)
{
    return (y * y - x * x);
}
int main()
{
    float x0 = 0, y0 = 1; // initial approximations
    float h = 0.1;        // interval width
    float x = 1;
    float xn, yn;
    do
    {
        yn = y0 + h * f(x0, y0);
        printf("%f %f\n", x0, yn);
        x0 += h;
        y0 = yn;
    } while (x0 < x);
}