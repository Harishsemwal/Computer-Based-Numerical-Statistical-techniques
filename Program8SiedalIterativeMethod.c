// Gauss siedal method

double eqx(double y, double z)
{
    return 1ll * ((17 - y + 2 * z) / 20.0);
}
double eqy(double x, double z)
{
    return 1ll * ((-18 - 3 * x + z) / 20.0);
}
double eqz(double x, double y)
{
    return 1ll * ((25 - 2 * x + 3 * y) / 20.0);
}

#include <stdio.h>
#include <math.h>
signed main()
{
    double x1, y1, z1;
    int c = 0;
    double prevX1 = 0.0, y = 0.0, z = 0.0;
    do
    {
        c++;
        prevX1 = x1;
        y = y1;
        z = z1;
        x1 = eqx(y, z);
        y1 = eqy(x1, z);
        z1 = eqz(x1, y1);
    } while (!(fabs(x1 - prevX1) <= 0.10000 && fabs(y1 - y) <= 0.10000 && fabs(z1 - z) <= 0.10000));
    printf("x %lf\n", x1);
    printf("y %lf\n", y1);
    printf("z %lf\n", z1);
    printf("Total no of iterations : %d", c);
}