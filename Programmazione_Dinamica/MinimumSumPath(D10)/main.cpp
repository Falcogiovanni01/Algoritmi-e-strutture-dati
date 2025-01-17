#include <iostream>
#include <vector>
#include <climits> // Per INT_MAX
using namespace std;

/**
 * TRACCIA :
 * data una matrice N*M, 
 * traccia la somma minima, sapendo che puoi andare 
 * - se parti da 00 a destra e sotto
 * - se parti da n-1M-1 sopra e a sinistra
 * es :
 *  5 9 6
 *  11 5 2 
 * la somma minima è data da : 5+9+5+2 = 21
 */

int MinimumPathSum(vector<vector<int>>& matrix, vector<vector<int>>& dp, int riga, int colonna) {
    // Caso base: se siamo fuori dai limiti della matrice, ritorna un valore infinito
    if (riga < 0 || colonna < 0) {
        return INT_MAX;
    }

    // Caso base: se siamo alla cella iniziale (0, 0), ritorna il valore della cella stessa
    if (riga == 0 && colonna == 0) {
        return matrix[0][0];
    }

    // Se il risultato è già stato calcolato, restituiscilo
    if (dp[riga][colonna] != -1) {
        return dp[riga][colonna];
    }

    // Calcola i costi del percorso da sinistra e dall'alto
    int sinistra = MinimumPathSum(matrix, dp, riga, colonna - 1);
    int sopra = MinimumPathSum(matrix, dp, riga - 1, colonna);

    // Memorizza il risultato minimo tra sinistra e sopra e aggiungi il valore corrente della cella
    dp[riga][colonna] = min(sinistra, sopra) + matrix[riga][colonna];

    return dp[riga][colonna];
}

int main() {
    // Esempio di matrice
    vector<vector<int>> matrix = {
        {1, 3, 1},
        {1, 5, 1},
        {4, 2, 1}
    };

    int n = matrix.size();
    int m = matrix[0].size();

    // Inizializza una matrice DP con -1
    vector<vector<int>> dp(n, vector<int>(m, -1));

    // Trova il percorso minimo dall'ultima cella (n-1, m-1)
    int result = MinimumPathSum(matrix, dp, n - 1, m - 1);

    // Stampa il risultato
    cout << "Il costo minimo del percorso è: " << result << endl;

    return 0;
}
