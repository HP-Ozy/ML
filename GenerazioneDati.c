
/*
Generazione di Dati: Scrivi un programma 
in C che genera dati casuali in due dimensioni (X, Y) secondo una distribuzione 
lineare con rumore.


Esempio di Utilizzo
Supponiamo che 
tu stia sviluppando un algoritmo di regressione 
lineare e desideri verificare che funzioni 
correttamente. Puoi utilizzare il codice sopra per
generare un set di dati sintetici, 
applicare il tuo algoritmo ai dati generati, 
e confrontare i parametri stimati 
(pendenza e intercetta) con quelli noti 
(2.0 e 1.0 rispettivamente) 
per valutare le prestazioni del tuo algoritmo.*/

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



/*

1. Simulazione di Dati per Test e Debug
Quando si sviluppano e testano algoritmi di regressione lineare o altri modelli statistici, è spesso utile avere un set di dati sintetici con caratteristiche note. Questo codice genera tali dati, permettendo di testare se l'algoritmo può recuperare i parametri della linea originale (pendenza e intercetta) anche in presenza di rumore.

2. Addestramento di Modelli di Machine Learning
Questo codice può essere utilizzato per generare dati sintetici da utilizzare nell'addestramento di modelli di machine learning. I dati sintetici con rumore aggiunto possono aiutare a valutare come i modelli gestiscono la variabilità e se possono generalizzare bene a nuovi dati.

3. Visualizzazione e Analisi dei Dati
Generare dati casuali con una relazione lineare e rumore aggiunto può essere utile per dimostrare concetti di base di statistica e analisi dei dati. Ad esempio, è possibile utilizzare questi dati per creare grafici di dispersione, calcolare regressioni lineari, e mostrare l'effetto del rumore sulle misurazioni.

4. Didattica e Esercitazioni
In un contesto educativo, questo codice può essere utilizzato per insegnare concetti di statistica, calcolo della regressione lineare, e l'effetto del rumore sui dati. Gli studenti possono analizzare i dati generati per esercitarsi nell'applicazione di tecniche statistiche e algoritmi di machine learning.

5. Test di Performance
Quando si sviluppano strumenti di analisi dei dati o software di statistica, è necessario verificare che il software funzioni correttamente con set di dati di diverse dimensioni. Questo codice fornisce un modo per generare rapidamente grandi quantità di dati con caratteristiche controllate.

Funzionamento del Codice
Il codice genera punti dati (x, y) secondo la formula 
𝑦
=
SLOPE
⋅
𝑥
+
INTERCEPT
+
noise
y=SLOPE⋅x+INTERCEPT+noise, dove il rumore è un valore casuale tra -5 e 5. Ecco una spiegazione dettagliata del funzionamento:

Inizializzazione del Generatore di Numeri Casuali: srand(time(NULL)); inizializza il generatore di numeri casuali usando il tempo corrente come seme, assicurando che i numeri casuali generati siano diversi ad ogni esecuzione del programma.
Ciclo per Generare Punti Dati: Il ciclo for viene eseguito NUM_POINTS volte (100 in questo caso), generando coppie di valori (x, y).
double x = (double)rand() / RAND_MAX * 100; genera un valore x casuale tra 0 e 100.
double noise = (double)rand() / RAND_MAX * 10 - 5; genera un rumore casuale tra -5 e 5.
double y = SLOPE * x + INTERCEPT + noise; calcola il valore di y usando la formula della retta con aggiunta di rumore.
Stampa dei Punti Dati: printf("%.2f, %.2f\n", x, y); stampa i valori x e y con due cifre decimali di precisione.

*/