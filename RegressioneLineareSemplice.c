#include <stdio.h>

void simple_linear_regression(int n, double x[], double y[], double* slope, double* intercept) {
    double sum_x = 0, sum_y = 0, sum_xy = 0, sum_x2 = 0;
    for(int i = 0; i < n; i++) {
        sum_x += x[i];
        sum_y += y[i];
        sum_xy += x[i] * y[i];
        sum_x2 += x[i] * x[i];
    }
    double x_mean = sum_x / n;
    double y_mean = sum_y / n;

    *slope = (sum_xy - n * x_mean * y_mean) / (sum_x2 - n * x_mean * x_mean);
    *intercept = y_mean - (*slope) * x_mean;
}

int main() {
    double x[] = {1, 2, 3, 4, 5};
    double y[] = {2, 4, 6, 8, 10}; // Perfettamente allineati, senza rumore
    int n = sizeof(x) / sizeof(x[0]);
    double slope, intercept;

    simple_linear_regression(n, x, y, &slope, &intercept);
    printf("Slope: %f, Intercept: %f\n", slope, intercept);

    return 0;
}
