// trapezodial
#include <stdio.h>
float f(float x)
{
    float y = 1.0 / (1 + x * x);
    return y;
}
int main()
{
    int a = 0, b = 1;
    // scanf("%d%d",&a,&b);
    int n = 6;
    // scanf("%d",&n);

    float h = (b - a) / (n * 1.0);
    float y0 = f(a);
    float yn = f(a + h * n);
    float result = 0.0;
    for (int i = 1; i < n; i++)
    {
        result += (f(a + h * i));
    }
    result *= 2;
    result += (y0 + yn);
    result *= (h / 2.0);
    printf("%f\n", result);
}