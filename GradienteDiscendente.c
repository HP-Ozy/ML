#include <stdio.h>

double compute_error(double b, double m, double x[], double y[], int n) {
    double total_error = 0.0;
    for (int i = 0; i < n; i++) {
        double x_i = x[i];
        double y_i = y[i];
        double current_error = y_i - (m * x_i + b);
        total_error += current_error * current_error;
    }
    return total_error / n;
}

void step_gradient(double b_current, double m_current, double x[], double y[], int n, double learning_rate, double* b_updated, double* m_updated) {
    double b_gradient = 0;
    double m_gradient = 0;
    double N = (double)n;
    
    for (int i = 0; i < n; i++) {
        double x_i = x[i];
        double y_i = y[i];
        b_gradient += -(2/N) * (y_i - ((m_current * x_i) + b_current));
        m_gradient += -(2/N) * x_i * (y_i - ((m_current * x_i) + b_current));
    }
    
    *b_updated = b_current - (learning_rate * b_gradient);
    *m_updated = m_current - (learning_rate * m_gradient);
}

int main() {
    double x[] = {0, 1, 2, 3, 4};
    double y[] = {0, 2, 4, 6, 8};
    int n = sizeof(x) / sizeof(x[0]);
    double learning_rate = 0.01;
    double b = 0; // y-intercept
    double m = 0; // slope
    int iterations = 1000;

    for (int i = 0; i < iterations; i++) {
        double b_new, m_new;
        step_gradient(b, m, x, y, n, learning_rate, &b_new, &m_new);
        b = b_new;
        m = m_new;
    }
    
    printf("After %d iterations, b = %f, m = %f\n", iterations, b, m);

    return 0;
}
