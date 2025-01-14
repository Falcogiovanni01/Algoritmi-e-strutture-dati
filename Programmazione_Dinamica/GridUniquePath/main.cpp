/** 
 * data una matrice N*M
 * dalla posizione 00 arriva alla posozione NM ( noi faremo al contrario)
 * 
 * puoi spostarti o a destra o sotto 
 * ( noi partendo da NM ci sposteremo o sopra o a sinistra)
 * 
 */
#include <iostream>
#include <vector>
using namespace std;

int gridUniquePath(vector<vector<int>>& dp, int riga, int colonna) {
    if (riga == 0 && colonna == 0) {
        return 1;  // Una sola via possibile (partenza)
    }

    if (riga < 0 || colonna < 0) {
        return 0;  // Se fuori dai limiti della griglia
    }

    if (dp[riga][colonna] != -1) {
        return dp[riga][colonna];  // Usa il valore memorizzato
    }

    // Muoversi verso il basso (riga - 1)
    int bottom = gridUniquePath(dp, riga - 1, colonna);
    
    // Muoversi a sinistra (colonna - 1)
    int left = gridUniquePath(dp, riga, colonna - 1);

    // Salva il risultato nella matrice dp
    dp[riga][colonna] = bottom + left;
    return dp[riga][colonna];
}

int main() {
    int M = 3;  // Numero di righe
    int N = 3;  // Numero di colonne
    
    // Creazione della matrice dp inizializzata a -1
    vector<vector<int>> dp(M, vector<int>(N, -1));
    
    // Chiama il metodo per calcolare il numero di percorsi unici
    int result = gridUniquePath(dp, M-1, N-1);
    
    cout << "Il numero di percorsi unici dalla cella in basso a destra alla cella in alto a sinistra è: " << result << endl;

    return 0;
}
