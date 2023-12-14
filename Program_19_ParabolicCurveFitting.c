#include<stdio.h>
#include<math.h>
int main()
{
    int n;
    scanf("%d", &n);
    float x[n], y[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &x[i], &y[i]);
    }
    float sum_x = 0, sum_x2 = 0, sum_x3 = 0, sum_x4 = 0, sum_y = 0, sum_xy = 0, sum_x2y = 0;
    for (int i = 0; i < n; i++)
    {
        sum_x += x[i];
        sum_x2 += (x[i] * x[i]);
        sum_x3 += (x[i] * x[i] * x[i]);
        sum_x4 += (x[i] * x[i] * x[i] * x[i]);
        sum_y += y[i];
        sum_xy += (x[i] * y[i]);
        sum_x2y += (x[i] * x[i] * y[i]);
    }
    int n1 = 3;
    float mat[n1][n1 + 1];
    mat[0][0] = sum_x2;
    mat[0][1] = sum_x;
    mat[0][2] = n;
    mat[0][3] = sum_y;
    mat[1][0] = sum_x3;
    mat[1][1] = sum_x2;
    mat[1][2] = sum_x;
    mat[1][3] = sum_xy;
    mat[2][0] = sum_x4;
    mat[2][1] = sum_x3;
    mat[2][2] = sum_x2;
    mat[2][3] = sum_x2y;

    // cout<<sum_xy<<endl;
    // upper tri
    for (int i = 0; i < n1; i++) // current row
    {
        for (int j = i + 1; j < n1; j++) // All rows below current row
        {
            float ratio = mat[j][i] / mat[i][i];
            for (int k = 0; k <= n1; k++) // column traversal of each row
            {
                mat[j][k] = mat[j][k] - ratio * mat[i][k];
            }
        }
    }

    // lower tri
    for (int i = n1 - 1; i >= 0; i--) // current row
    {
        for (int j = i - 1; j >= 0; j--) // All rows above current row
        {
            float ratio = mat[j][i] / mat[i][i];
            for (int k = 0; k <= n1; k++) // column traversal of each row
            {
                mat[j][k] = mat[j][k] - ratio * mat[i][k];
            }
        }
    }

    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j <= n1; j++)
        {
            printf("%f ", mat[i][j]);
        }
        printf("\n");
    }

    float sol[n1];
    for (int i = n1 - 1; i >= 0; i--)
    {
        sol[i] = mat[i][n1] / mat[i][i];
    }

    for (int i = 0; i < n1; i++)
    {
        printf("%f ", sol[i]);
    }
}