
/*Esercizio 1: Misure di Tendenza Centrale e Dispersione
Calcolare la media, la mediana, la moda, la varianza e la deviazione standard di un dataset.*/

/*teoria: Foglio nel blocco blu*/


#include <stdio.h>
#include <math.h>




void calculate_statistics(int data[], int n) {



    double mean = 0, sum = 0, variance = 0, std_dev = 0;
    int i, j, mode = data[0], max_count = 0;

    // Calcolo della media
    for (i = 0; i < n; i++) {
        sum += data[i];
    }
    mean = sum / n;

    // Calcolo della varianza e della deviazione standard
    for (i = 0; i < n; i++) {
        variance += pow(data[i] - mean, 2);
    }
    variance /= n;
    std_dev = sqrt(variance);

    // Calcolo della mediana
    int temp;
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (data[i] > data[j]) {
                temp = data[i];
                data[i] = data[j];
                data[j] = temp;
            }
        }
    }
    double median = (n % 2 == 0) ? (data[n / 2 - 1] + data[n / 2]) / 2.0 : data[n / 2];

    // Calcolo della moda
    for (i = 0; i < n; ++i) {
        int count = 0;
        for (j = 0; j < n; ++j) {
            if (data[j] == data[i])
                ++count;
        }
        if (count > max_count) {
            max_count = count;
            mode = data[i];
        }
    }

    // Output dei risultati
    printf("Mean: %.2f\n", mean);
    printf("Median: %.2f\n", median);
    printf("Mode: %d\n", mode);
    printf("Variance: %.2f\n", variance);
    printf("Standard Deviation: %.2f\n", std_dev);
}

int main() {
    int data[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    int n = sizeof(data) / sizeof(data[0]);

    calculate_statistics(data, n);

    return 0;
}
