#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_POINTS 100
#define SLOPE 2.0
#define INTERCEPT 1.0

int main() {
    srand(time(NULL)); // Inizializza il generatore di numeri casuali
    printf("x, y\n");
    for(int i = 0; i < NUM_POINTS; i++) {
        double x = (double)rand() / RAND_MAX * 100; // Genera un valore x casuale tra 0 e 100
        double noise = (double)rand() / RAND_MAX * 10 - 5; // Rumore casuale tra -5 e 5
        double y = SLOPE * x + INTERCEPT + noise; // Calcola y con rumore
        printf("%.2f, %.2f\n", x, y);
    }
    return 0;
}
