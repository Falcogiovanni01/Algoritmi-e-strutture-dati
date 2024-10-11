#include <iostream>
using namespace std;

/**
 * Questo codice si occuperà di illustrare il funzionamento del heap sort.
 * SCOPO: ordinare un vettore 
 * COSA SI UTILIZZA PER FARLO: 
 * - ricorsione: tramite l'utilizzo del metodo divide et impera si 
 * dividerà il problema in sottoproblemi fino a ricondurci al caso base, 
 * si risolve e si combinano le soluzioni.
 * - heap: struttura dati utilizzata per effettuare l'ordinamento 
 * è una struttura ad albero, ce ne sono due (MAX e MIN)
 * noi useremo la MAX.
 * La max-heapify consiste nel avere l'elemento più grande nel nodo padre: 
 *    es: 10 
 *      9     8 
 *    7  6   5  2
 * 
 * Ma non è finita qui, questo è un albero ma POSIZIONALE: 
 * Quindi 10 è l'elemento 1, 9 l'elemento 2 ...quindi il vettore si presenterà in questo modo:
 *   10 9 8 7 6 5 2 
 * Il resto lo vedrete commentato nelle sottofunzioni.
 */

void maxHeapify(int vettore[], int indice, int dimensione);
void buildHeap(int vettore[], int dimensione);
void heap(int vettore[], int dimensione);
void printVector(int vettore[], int dimensione);

int main() {
    int vettore[] = {2, 5, 8, 6, 10, 9 , 1}; 
    // mi dovrò fermare prima o poi? prendo la dimensione del vettore: 
    int dimensione = sizeof(vettore) / sizeof(vettore[0]);

    cout << "Vettore non ordinato:\n"; 
    printVector(vettore, dimensione); 
    heap(vettore, dimensione); 
    
    cout << "\nVettore ordinato:\n"; 
    printVector(vettore, dimensione); 

    return 0; 
}

/**
 * La chiave principale è la funzione maxHeapify 
 * questa si occupa di creare l'heap.
 */
void maxHeapify(int vettore[], int indice, int dimensione) {
    int left = 2 * indice + 1; // Indice del figlio sinistro
    int right = 2 * indice + 2; // Indice del figlio destro
    int massimo = indice; // Inizializza il massimo come radice
    
    // Controlla se il figlio sinistro esiste e se è maggiore della radice
    if (left < dimensione && vettore[left] > vettore[massimo]) {
        massimo = left;
    }

    // Controlla se il figlio destro esiste e se è maggiore del massimo
    if (right < dimensione && vettore[right] > vettore[massimo]) {
        massimo = right;
    }

    // Se il massimo non è la radice, scambia e continua 
    if (massimo != indice) {
        
          int temp = vettore[indice];
        vettore[indice] = vettore[massimo];
         vettore[massimo]= temp;
        maxHeapify(vettore, massimo, dimensione);
    }
}

// Costruisci max-heap 
void buildHeap(int vettore[], int dimensione) {
    // Iniziamo dall'ultimo nodo genitore ( tenere in conto che poi con gli indici becchi tutti gli elementi.)
    for (int i = dimensione / 2 - 1; i >= 0; i--) {
        maxHeapify(vettore, i, dimensione);
    }
}

// Funzione di ordinamento
void heap(int vettore[], int dimensione) {
    // 1: costruisco l'heap 
    buildHeap(vettore, dimensione); 

    // 2: esegui l'ordinamento
    for (int i = dimensione - 1; i > 0; i--) {
        // Scambia il primo elemento con l'ultimo
        /**
         * avrai l'heap : 10 9 8 ... 1 
         * scambi il 10 con l 1 ... 1 9 8... 10 
         * e diminuisci la dimensione ed il gioco è fatto.
         */
         int temp = vettore[0];
        vettore[0] = vettore[i];
         vettore[i]= temp;
        maxHeapify(vettore, 0, i); // Ricostruisci l'heap
    }
}

void printVector(int vettore[], int dimensione) {
    for (int i = 0; i < dimensione; i++) {
        cout << " " << vettore[i]; 
    }
    cout << endl; // Aggiunto endl per una nuova linea
}
