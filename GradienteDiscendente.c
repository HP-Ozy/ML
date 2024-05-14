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


/*Teoria
1. Gradiente Discendente:
Il gradiente discendente è un metodo di ottimizzazione utilizzato per minimizzare una funzione costante iterativamente. Nella regressione lineare, la funzione costante (o di errore) spesso usata è la somma dei quadrati degli errori (SSE - Sum of Squared Errors):
𝐽
(
𝑚
,
𝑏
)
=
1
𝑛
∑
𝑖
=
1
𝑛
(
𝑦
𝑖
−
(
𝑚
𝑥
𝑖
+
𝑏
)
)
2
J(m,b)= 
n
1
​
 ∑ 
i=1
n
​
 (y 
i
​
 −(mx 
i
​
 +b)) 
2
 
dove 
𝑦
𝑖
y 
i
​
  sono i valori osservati, 
𝑥
𝑖
x 
i
​
  sono i valori delle variabili indipendenti, 
𝑚
m è la pendenza della linea, e 
𝑏
b è l'intercetta.

2. Aggiornamento dei Parametri:
L'aggiornamento dei parametri 
𝑚
m e 
𝑏
b avviene tramite:
𝑚
=
𝑚
−
𝛼
∂
𝐽
∂
𝑚
m=m−α 
∂m
∂J
​
 
𝑏
=
𝑏
−
𝛼
∂
𝐽
∂
𝑏
b=b−α 
∂b
∂J
​
 
dove 
𝛼
α è il tasso di apprendimento, e 
∂
𝐽
∂
𝑚
∂m
∂J
​
  e 
∂
𝐽
∂
𝑏
∂b
∂J
​
  sono le derivate parziali della funzione costante rispetto a 
𝑚
m e 
𝑏
b.

Componenti del Codice
1. Calcolo dell'Errore:

c
Copia codice
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
Questa funzione calcola e ritorna il valore medio dell'errore quadrato totale, che è la funzione costante 
𝐽
(
𝑚
,
𝑏
)
J(m,b).

2. Aggiornamento dei Parametri tramite Gradiente Discendente:

c
Copia codice
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
Questo blocco di codice aggiorna iterativamente i parametri 
𝑚
m e 
𝑏
b riducendo l'errore. Il tasso di apprendimento 
𝛼
α controlla la velocità di apprendimento.

3. Applicazione Iterativa del Gradiente Discendente:

c
Copia codice
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
In questo frammento, il ciclo for applica il gradiente discendente per un numero fissato di iterazioni per minimizzare l'errore. Alla fine del processo, stampa i valori finali di 
𝑚
m e 
𝑏
b.

Utilità
Questo esercizio è cruciale per comprendere come gli algoritmi di apprendimento ottimizzano i loro parametri per adattarsi meglio ai dati. È fondamentale nel machine learning, soprattutto nei problemi di apprendimento supervisionato. Implementarlo da zero, come in questo esempio, fornisce una comprensione profonda della sua meccanica e dei suoi effetti.





*/