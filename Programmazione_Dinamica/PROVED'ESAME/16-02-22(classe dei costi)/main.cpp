#include <iostream>
#include <vector>
#include <algorithm>
#include <climits> // Per INT_MIN

using namespace std;
/*- prendi la matrice dp : (costi+1)(budget+1) 
- le classi le interpreti come vettori, e dà li fai una matrice di classi. 
- ora ogni vettore hai una scelta,
 ora scorri sulla matrice dei costi e dà 
 li vai a prelevare gli elementi e man mano li salvi nel dp normale*/
// Funzione ricorsiva con memoization
int solve(vector<vector<int>>& dp, vector<vector<int>>& costi, int budget, int colonna) {
    // Base cases
    if (budget < 0) return INT_MIN; // Budget insufficiente (ritorna valore minimo)
    if (colonna >= costi.size()) return 0; // Tutte le classi sono state considerate

    // Controllo se il risultato è già calcolato
    if (dp[colonna][budget] != -1) return dp[colonna][budget];

    int massimo = INT_MIN;

    // Itera sui prodotti della classe corrente
    for (int prezzo : costi[colonna]) {
        massimo = max(massimo, solve(dp, costi, budget - prezzo, colonna + 1) + prezzo);
    }

    // Salva il risultato nella tabella dp
    dp[colonna][budget] = massimo;
    return massimo;
}

int main() {
    // Input: classi e budget
    vector<int> classe1 = {8, 6, 4};
    vector<int> classe2 = {5, 10};
    vector<int> classe3 = {1, 3, 3, 7};
    vector<int> classe4 = {50, 14, 23, 8};

    vector<vector<int>> costi = {classe1, classe2, classe3, classe4};
   

    int Budget = 100;

    // Inizializza la matrice dp con -1
    vector<vector<int>> dp(costi.size() + 1, vector<int>(Budget + 1, -1));

    // Calcola il risultato massimo
    int risultato = solve(dp, costi, Budget, 0);

    // Stampa il risultato
    if (risultato < 0) {
        cout << "denaro insufficiente" << endl;
    } else {
        cout << "Massimo denaro speso: " << risultato << endl;
    }

    return 0;
}
