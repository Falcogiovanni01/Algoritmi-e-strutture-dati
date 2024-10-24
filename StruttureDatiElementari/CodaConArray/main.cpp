#include <iostream>
using namespace std;

/* SEGUE LA POLITICA FIFO, 
PRIMO CHE ENTRA è PRIMO AD USCIRE.
A->B->C
avrò un puntatore head ad A e uno tail a C. 
tolgo head e avrò: B -> C 
*/

class Coda {
private:
    int* vettore; // Usato per la coda
    int dimensione; // Dimensione massima della coda
    int head; // Indice della testa della coda
    int tail; // Indice della coda

public:
    // Costruttore
    Coda(int dim) {
        dimensione = dim; 
        vettore = new int[dimensione]; 
        head = 0; 
        tail = 0; 
    }

    // Distruttore
    ~Coda() {
        delete[] vettore; // Dealloca l'array
    }

    // Controlla se la coda è vuota
    void empty() {
        if (head == tail) {
            cout << "\nLA CODA è VUOTA"; 
        } else {
            cout << "\nLa coda non è vuota";
        }
    }

    // Controlla se la coda è piena
    void full() {
        /** es :     0    1   2  3    4
             * vettore = [ 0 , 1 , 2, 3 , 5] ; 
             * tail = 4 
             * ma la dimensione = 5 
             * quindi : se 4+1 % 5 == 0 , quindi il resto è 0
             * allora è piena altrimenti no.
             * 
             */

        if ((tail + 1) % dimensione == head) {
            cout << "\nCODA è PIENA"; 
        } else {
            cout << "\nLa coda non è piena";
        }
    }

    // Ritorna la dimensione della coda
    int size() {
        int size = (tail - head + dimensione) % dimensione; 
        cout << "\nDIMENSIONE: " << size; 
        return size; 
    } 

    // Aggiunge un elemento alla coda
    void enqueue(int newEntry) { 
        if ((tail + 1) % dimensione == head) {
            cout << "\nNon posso aggiungere, la coda è piena!";
        } else {
            vettore[tail] = newEntry; 
            tail = (tail + 1) % dimensione; // Aggiorna l'indice tail
            cout << "\nAGGIUNTO: " << newEntry; 
        }
    }

    // Rimuove e ritorna l'elemento dalla testa della coda
    int dequeue() { 
        if (head == tail) {
            cout << "\nNon posso rimuovere, la coda è vuota!";
            return -1; // Restituisce un valore indicativo di errore
        } else {
            int rimosso = vettore[head];
            head = (head + 1) % dimensione; // Aggiorna l'indice head
            cout << "\nRIMOSSO: " << rimosso; 
            return rimosso; 
        }
    }
};

int main() {
    Coda coda(5); // Crea una coda con una dimensione massima di 5

    coda.empty(); // Controlla se la coda è vuota
    coda.full();  // Controlla se la coda è piena

    coda.enqueue(10); // Aggiunge 10 alla coda
    coda.enqueue(20); // Aggiunge 20 alla coda
    coda.enqueue(30); // Aggiunge 30 alla coda

    coda.size(); // Stampa la dimensione della coda
    coda.full(); // Controlla se la coda è piena

    coda.dequeue(); // Rimuove un elemento dalla coda
    coda.size(); // Stampa la dimensione della coda

    coda.enqueue(40); // Aggiunge 40 alla coda
    coda.enqueue(50); // Aggiunge 50 alla coda

    coda.size(); // Stampa la dimensione della coda
    coda.full(); // Controlla se la coda è piena

    // Provando a riempire la coda
    coda.enqueue(60); // Tentativo di aggiungere 60 alla coda, dovrebbe fallire

    return 0; // Termina il programma
}



 
