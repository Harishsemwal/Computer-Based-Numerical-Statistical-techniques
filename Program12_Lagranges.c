// lagranges interpolation
#include <stdio.h>
int main()
{
    int n;
    scanf("%d", &n);
    float x[n], y[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%f%f", &x[i], &y[i]);
    }
    float interpolationpoint;
    scanf("%f", &interpolationpoint);
    float ans = 0.0;
    for (int i = 0; i < n; i++)
    {
        float currsum = 1;
        for (int j = 0; j < n; j++)
        {
            if (i != j)
            {
                currsum = currsum * ((interpolationpoint - x[j]) / (x[i] - x[j]));
            }
            printf("%f\n", currsum);
        }
        ans = ans + y[i] * currsum;
    }
    printf("%f\n", ans);
}