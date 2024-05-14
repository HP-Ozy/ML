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



/*Teoria
1. Modello Lineare:
La relazione lineare è una delle forme più semplici di relazioni tra variabili. In matematica, una relazione lineare tra due variabili si può esprimere come:
𝑦
=
𝑚
𝑥
+
𝑏
y=mx+b
dove 
𝑚
m è la pendenza della linea e 
𝑏
b è l'intercetta, ossia il valore di 
𝑦
y quando 
𝑥
x è zero.

2. Rumore:
Nel mondo reale, i dati raramente seguono perfettamente una formula matematica a causa di vari fattori che possono introdurre incertezze o variazioni casuali. Queste variazioni sono spesso modellate come "rumore". Aggiungendo rumore, il dataset simulato diventa più simile a quello che potresti incontrare nella pratica, rendendo i tuoi algoritmi di machine learning più robusti e capaci di gestire dati imperfetti.

Componenti del Codice
1. Librerie Standard:

c
Copia codice
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
Queste librerie forniscono funzioni standard per output di sistema, gestione della memoria e funzioni relative al tempo, rispettivamente. stdio.h per stampare i dati, stdlib.h per funzioni di generazione di numeri casuali, e time.h per ottenere il tempo corrente.

2. Generazione di Numeri Casuali:

c
Copia codice
srand(time(NULL)); // Inizializza il generatore di numeri casuali
Questa linea inizializza il generatore di numeri casuali basato sull'ora corrente. È importante inizializzare il generatore per evitare che produca la stessa sequenza di numeri ogni volta che il programma viene eseguito.

3. Ciclo for per Generare i Dati:

c
Copia codice
for(int i = 0; i < NUM_POINTS; i++) {
    double x = (double)rand() / RAND_MAX * 100; // Genera un valore x casuale tra 0 e 100
    double noise = (double)rand() / RAND_MAX * 10 - 5; // Rumore casuale tra -5 e 5
    double y = SLOPE * x + INTERCEPT + noise; // Calcola y con rumore
    printf("%.2f, %.2f\n", x, y);
}
In questo ciclo:

x è generato casualmente tra 0 e 100.
noise è generato come un valore casuale tra -5 e 5, che viene aggiunto a y per introdurre il rumore.
y è calcolato usando la formula della linea retta (m * x + b) più il rumore.
I dati generati vengono stampati in formato CSV.
Utilità
Questo programma è utile come esercizio per familiarizzare con la generazione di dati e per capire come il rumore influisce sui dati in scenari di machine learning. Potresti utilizzare questo codice per generare dati di test per esplorare come vari algoritmi di ML, come la regressione lineare, rispondono a differenti livelli di variazione nei dati.*/
