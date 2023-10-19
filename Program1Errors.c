//find absolute relative and persentage error for round roundoff ans truncation.

#include <stdio.h>
#include <stdlib.h>
int main()
{
    double real;
    scanf("%lf", &real);

    int scale = real * 100000;
    int decimal = scale % 10;
    
    printf("Scale: %d\n", scale);
    printf("Decimal: %d\n", decimal);

    if(decimal >= 5){
        scale /=10;
        scale++;
    }
    printf("Scale: %d\n", scale);
    double approx = (1.0 * scale)/(1.0 * 10000);
    float absolute = (real - approx);

    printf("absolute error: %d\n", absolute);
    return 0;
}