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


/*Applicazioni Reali
Modelli Predittivi:
Questo codice può essere utilizzato per sviluppare modelli 
predittivi semplici che utilizzano una relazione lineare tra due variabili. Ad esempio, 
può essere impiegato per prevedere i prezzi delle case basandosi su variabili come la dimensione della casa.

Analisi dei Dati:
In analisi dei dati, la regressione lineare è uno strumento fondamentale per comprendere le relazioni tra variabili. 
Questo codice può aiutare a identificare la relazione tra variabili in un dataset e a quantificare la forza di queste relazioni.

Ottimizzazione:
L'algoritmo di discesa del gradiente utilizzato nel codice è un metodo di ottimizzazione fondamentale in molti campi, 
inclusi machine learning e intelligenza artificiale. È alla base di molti algoritmi di addestramento per reti neurali e altri modelli complessi.

Educazione:
Questo esempio di discesa del gradiente può essere utilizzato in contesti educativi per insegnare i principi di base dell'ottimizzazione 
e della regressione lineare. Gli studenti possono apprendere come i parametri di un modello possono essere ottimizzati iterativamente per 
ridurre l'errore.

Finanza:
In finanza, la regressione lineare viene utilizzata per modellare e prevedere i movimenti dei prezzi delle azioni o delle obbligazioni in 
base a variabili economiche. Questo codice potrebbe essere la base per costruire tali modelli predittivi.

Ingegneria:
In ingegneria, la regressione lineare può essere utilizzata per modellare e prevedere fenomeni fisici, 
come la relazione tra stress e deformazione nei materiali. Questo aiuta a progettare e ottimizzare strutture e materiali.

Esempio di Utilizzo
Supponiamo che tu stia lavorando su un progetto per prevedere le vendite future di un prodotto in base al budget pubblicitario. 
Puoi utilizzare dati storici di budget pubblicitario (𝑥x) e vendite (𝑦y) per addestrare un modello di regressione lineare. Questo modello ti permetterà di stimare le vendite future date nuove informazioni sul 
budget pubblicitario.

In conclusione, il codice fornito è un'implementazione semplice ma potente di un algoritmo di discesa del gradiente per la regressione lineare,
 con molteplici applicazioni in vari campi reali.*/