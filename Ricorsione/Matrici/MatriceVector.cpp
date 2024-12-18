#include <iostream>
#include <vector>

using namespace std;

// Funzione per stampare la matrice
void printMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (const auto& element : row) {
            cout << element << "\t";
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

    // Creazione della matrice come vettore di vettori
    vector<vector<int>> matrix(rows, vector<int>(cols));

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
    printMatrix(matrix);

    // Modifica di un valore specifico
    cout << "SCEGLI i e j per modificare un valore: ";
    cin >> i >> j;

    if (i >= 0 && i < rows && j >= 0 && j < cols) {
        cout << "Inserisci il nuovo valore: ";
        cin >> value;
        matrix[i][j] = value;

        // Stampa della matrice aggiornata
        cout << "\nMatrice aggiornata:" << endl;
        printMatrix(matrix);
    } else {
        cout << "Indici fuori dal range della matrice!" << endl;
    }

    return 0;
}
