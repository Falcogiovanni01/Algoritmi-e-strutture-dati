#include <iostream>
using namespace std;

// Funzione per creare una matrice dinamica
int** createMatrix(int rows, int cols) {
    int** matrix = new int*[rows]; // Creazione di un array di puntatori
    for (int i = 0; i < rows; i++) {
        matrix[i] = new int[cols]; // Creazione di un array per ogni riga
    }
    return matrix;
}

// Funzione per liberare la memoria della matrice
void deleteMatrix(int** matrix, int rows) {
    for (int i = 0; i < rows; i++) {
        delete[] matrix[i]; // Libera ogni riga
    }
    delete[] matrix; // Libera l'array di puntatori
}

// Funzione per stampare la matrice
void printMatrix(int** matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
}

int main() {
    int rows, cols, i, j, value;

    // Input dimensioni della matrice
    cout << "Inserisci il numero di righe: ";
    cin >> rows;
    cout << "Inserisci il numero di colonne: ";
    cin >> cols;

    // Creazione della matrice
    int** matrix = createMatrix(rows, cols);

    // Inizializzazione della matrice
    cout << "Inserisci gli elementi della matrice:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << "Elemento [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }

    // Stampa della matrice
    cout << "\nMatrice iniziale:" << endl;
    printMatrix(matrix, rows, cols);

    // Modifica di un valore specifico
    cout << "SCEGLI i e j per modificare un valore: ";
    cin >> i >> j;

    if (i >= 0 && i < rows && j >= 0 && j < cols) {
        cout << "Inserisci il nuovo valore: ";
        cin >> value;
        matrix[i][j] = value;

        // Stampa della matrice aggiornata
        cout << "\nMatrice aggiornata:" << endl;
        printMatrix(matrix, rows, cols);
    } else {
        cout << "Indici fuori dal range della matrice!\n";
    }

    // Libera la memoria
    deleteMatrix(matrix, rows);

    return 0;
}
