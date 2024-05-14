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



/*Nel secondo esempio pratico, il codice in C è progettato per implementare la regressione lineare semplice usando il metodo dei minimi quadrati. Vediamo in dettaglio la teoria dietro l'algoritmo e perché sono state fatte certe scelte nel codice.

Teoria
1. Regressione Lineare Semplice:
La regressione lineare è uno dei metodi più basilari ed efficaci per modellare una relazione tra una variabile dipendente 
𝑦
y e una variabile indipendente 
𝑥
x. L'obiettivo è trovare una linea retta,
𝑦
=
𝑚
𝑥
+
𝑏
y=mx+b
che meglio approssima i dati nel senso dei minimi quadrati. In questa equazione, 
𝑚
m rappresenta la pendenza della linea, e 
𝑏
b è l'intercetta con l'asse 
𝑦
y.

2. Metodo dei Minimi Quadrati:
Il metodo dei minimi quadrati è un approccio standard per la regressione lineare. Si cerca di minimizzare la somma dei quadrati delle differenze tra i valori osservati e quelli previsti dalla linea retta. Le formule per calcolare 
𝑚
m (pendenza) e 
𝑏
b (intercetta) da un set di dati sono:
𝑚
=
∑
(
𝑥
𝑖
−
𝑥
ˉ
)
(
𝑦
𝑖
−
𝑦
ˉ
)
∑
(
𝑥
𝑖
−
𝑥
ˉ
)
2
m= 
∑(x 
i
​
 − 
x
ˉ
 ) 
2
 
∑(x 
i
​
 − 
x
ˉ
 )(y 
i
​
 − 
y
ˉ
​
 )
​
 
𝑏
=
𝑦
ˉ
−
𝑚
𝑥
ˉ
b= 
y
ˉ
​
 −m 
x
ˉ
 
dove 
𝑥
ˉ
x
ˉ
  e 
𝑦
ˉ
y
ˉ
​
  sono le medie delle variabili 
𝑥
x e 
𝑦
y rispettivamente.

Componenti del Codice
1. Funzione per la Regressione Lineare:

c
Copia codice
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
Questa funzione calcola la pendenza 
𝑚
m e l'intercetta 
𝑏
b per un dataset utilizzando le formule dei minimi quadrati. Si utilizzano cicli e operazioni matematiche di base senza l'uso di librerie esterne, il che rende l'esempio utile per comprendere i principi fondamentali senza dipendenze.

2. Applicazione della Funzione:

c
Copia codice
int main() {
    double x[] = {1, 2, 3, 4, 5};
    double y[] = {2, 4, 6, 8, 10}; // Perfettamente allineati, senza rumore
    int n = sizeof(x) / sizeof(x[0]);
    double slope, intercept;

    simple_linear_regression(n, x, y, &slope, &intercept);
    printf("Slope: %f, Intercept: %f\n", slope, intercept);

    return 0;
}
Nel main, si definisce un semplice set di dati senza rumore per cui la relazione lineare è perfetta. La funzione simple_linear_regression è chiamata per calcolare e poi stampare la pendenza e l'intercetta.

Utilità
Questo esempio è utile per apprendere come implementare algoritmi di base senza l'ausilio di librerie complesse, fornendo una comprensione profonda del processo di calcolo nell'ambito della regressione lineare. È particolarmente indicato per chi inizia a esplorare il campo della data science e del machine learning per comprendere i meccanismi di base dell'apprendimento supervisionato.*/