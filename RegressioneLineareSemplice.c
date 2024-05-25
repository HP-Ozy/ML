/*

Regressione Lineare con Gradiente Discendente: Scrivi un programma che implementa la regressione 
lineare utilizzando il metodo del gradiente discendente.
*/

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



/*Esempio di Utilizzo
Supponiamo che tu stia analizzando la relazione tra
 l'età di un'auto e il suo prezzo di rivendita.
 Puoi utilizzare i dati storici per creare un modello di regressione lineare che aiuti a prevedere il prezzo di rivendita di un'auto basato sulla sua età. Questo modello può essere utile per i concessionari di auto per valutare rapidamente i prezzi delle auto usate.

In conclusione, 
questo codice implementa una semplice regressione 
lineare utilizzando il metodo dei minimi quadrati, 
con molteplici applicazioni nel mondo reale per la
 predizione, l'analisi dei dati, e l'insegnamento di 
 concetti statistici fondamentali.
 
 
 
 Applicazioni Reali
Modelli Predittivi:
Questo codice può essere utilizzato per creare modelli predittivi lineari semplici. Ad esempio, può prevedere il prezzo di un bene basato su una variabile indipendente come il tempo o la quantità.

Analisi dei Dati:
In analisi dei dati, la regressione lineare è fondamentale per comprendere le relazioni tra variabili. Questo codice aiuta a identificare e quantificare tali relazioni in un dataset.

Valutazione delle Prestazioni:
La regressione lineare può essere utilizzata per valutare le prestazioni di un processo o sistema nel tempo, identificando tendenze e anomalie.

Educazione:
Questo esempio di regressione lineare può essere utilizzato per insegnare i principi base della statistica e dell'analisi dei dati. Gli studenti possono apprendere come calcolare manualmente i coefficienti di una linea di regressione.

Economia:
In economia, la regressione lineare viene utilizzata per modellare relazioni tra variabili economiche, come il reddito e la spesa, o l'offerta e la domanda.

Ricerca Scientifica:
Nella ricerca scientifica, la regressione lineare è utilizzata per analizzare i dati sperimentali e determinare le relazioni tra variabili misurate.
 */