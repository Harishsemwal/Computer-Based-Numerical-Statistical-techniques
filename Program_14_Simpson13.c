// simpson 1/3 rule

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
    float even = 0.0;
    float odd = 0.0;
    float result = 0.0;
    for (int i = 1; i < n; i++)
    {
        if (i % 2 == 0)
            even += (f(a + h * i));
        else
            odd += (f(a + h * i));
    }
    even *= 2;
    odd *= 4;
    result = even + odd;
    result += (y0 + yn);

    result *= (h / 3.0);
    printf("%f\n", result);
}