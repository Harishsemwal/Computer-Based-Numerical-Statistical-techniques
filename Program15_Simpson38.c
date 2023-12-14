// simpson 3/8
#include <stdio.h>
float f(float x)
{
    float y = 1.0 / (1 + x);
    return y;
}
int main()
{
    int a = 0, b = 6;
    // scanf("%d%d",&a,&b);
    int n = 6;
    // scanf("%d",&n);

    float h = (b - a) / (n * 1.0);
    float y0 = f(a);
    float yn = f(a + h * n);
    float mul_of_three = 0.0;
    float remaining = 0.0;
    float result = 0.0;
    for (int i = 1; i < n; i++)
    {
        if (i % 3 == 0)
            mul_of_three += (f(a + h * i));
        else
            remaining += (f(a + h * i));
    }
    mul_of_three *= 2;
    remaining *= 3;
    result = mul_of_three + remaining;
    result += (y0 + yn);

    result *= (3 * h / 8.0);
    printf("%f\n", result);
}