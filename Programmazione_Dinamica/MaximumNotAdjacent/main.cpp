#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;
/**
 * obiettivo : dato un vettore : 2,1,4,9 
 * calcola la somma massima evitando di prendere gli elementi adiacenti.
 * possibili casi : 
 * 1 ) 2+9 = 11 
 * 2 ) 2+4 = 6 
 * 3 ) 1+9 = 10 
 * 4 ) 4 
 * 
 * Soluzione :
 * prendo non prendo, 
 * prendo 9 e diminuisco di 2 n cosi parto da 1.
 * ora ho due scelte o prendo o non prendo 
 * non prendo 
 * n-1, quindi mi resta 2
 * e sono costretto a prendere 
 * se non prendo ritorno 9, quindi avrò 9 e 11 e salvo 11.
 * 
 * tornando indietro con le chiamate poi prendo 1 
 * e avrò 9 +1 = 10 , e salvo questo valore e cosi via.
 * 
 */



// Funzione ricorsiva con memoization
int maximumNonAdjacent(const vector<int>& A, vector<int>& dp, int n) {
    if (n <= 0) return 0; // Caso base: somma nulla se non ci sono elementi
    if (dp[n] != -1) return dp[n]; // Restituisci il valore già calcolato

    // Non includere l'elemento corrente
    int notPick = maximumNonAdjacent(A, dp, n - 1);
    // Includere l'elemento corrente
    int pick = maximumNonAdjacent(A, dp, n - 2) + A[n - 1];

    // Calcolare il massimo
    dp[n] = max(pick, notPick);
    return dp[n];
}

// Funzione principale per trovare la somma massima
int findMaxSum(const vector<int>& A) {
    int n = A.size();
    vector<int> dp(n + 1, -1); // Array per la memoization
    return maximumNonAdjacent(A, dp, n);
}

// Main
int main() {
    // Esempio di input
    vector<int> A = {2,1,4,9};
    
    // Calcolare il massimo
    int result = findMaxSum(A);

    // Output del risultato
    cout << "La somma massima della sottosequenza non adiacente è: " << result << endl;

    return 0;
}
