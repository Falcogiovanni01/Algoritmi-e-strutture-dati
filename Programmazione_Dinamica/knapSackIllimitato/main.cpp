#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/**
 * complessità :
 * temporale, devi vedere il numero di sottoproblemi
 * in questo caso coincide proprio con la dimensione della matrice dp
 * [numero di elementi wt ][W+1]
 * infatti in questo caso avrò una matrice del genere :
 *   0 1 2 3 4 5 6 7 8 9 10 
 * 2
 * 4
 * 6
 * quella spaziale, è la stessa + O(n) dovuto allo stack di ricorsione.
 */



// Funzione ricorsiva con memoization
int knapSack(vector<vector<int>>& dp, vector<int>& wt, vector<int>& val, int W, int index) {
    if (W == 0) // Se lo zaino è pieno
        return 0;
    if (index < 0) // Se non ci sono più oggetti da considerare
        return 0;
    if (dp[index][W] != -1) // Se lo stato è già stato calcolato
        return dp[index][W];
    
    // Se non prendo l'oggetto corrente 
    int noTake = knapSack(dp, wt, val, W, index - 1);
    
    // Se prendo l'oggetto corrente (solo se il peso lo permette)
    int take = 0;
    if (W >= wt[index]) // PER PRENDERLO INFINITE VOLTE NON INCREMENTO L INDICE.
        take = knapSack(dp, wt, val, W - wt[index], index) + val[index];
    
    // Salvo il massimo valore ottenuto nello stato corrente
    dp[index][W] = max(take, noTake);
    return dp[index][W];
}

// Funzione wrapper per inizializzare la matrice di memoization
int unboundedKnapsack(int W, vector<int>& wt, vector<int>& val, int n) {
    vector<vector<int>> dp(n, vector<int>(W + 1, -1)); // Inizializzo dp con -1
    return knapSack(dp, wt, val, W, n - 1);
}

int main() {
    vector<int> wt = {2, 4, 6}; // Pesi degli oggetti
    vector<int> val = {5, 11, 13}; // Valori degli oggetti
    int W = 10; // Capacità dello zaino
    int n = wt.size(); // Numero di oggetti

    // Calcolo e stampa del valore massimo
    cout << "Il valore massimo ottenibile è: " << unboundedKnapsack(W, wt, val, n) << endl;
    return 0;
}
