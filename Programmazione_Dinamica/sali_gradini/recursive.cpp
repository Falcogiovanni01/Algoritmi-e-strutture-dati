#include <iostream>
#include <vector>
using namespace std;

/**
 * la rana può salire n gradini in 1 o 2 passi.
 * sapendo ciò calcolo i modi possibili per effettuare questa salita.
 * ESSENDO CHE devo contare i modi, devo fare la somma !!!
 */


// Funzione ricorsiva con memoizzazione
int salireScale(int n, vector<int>& dp) {
    // Caso base
    if (n == 0) return 1;
    if (n == 1) return 1;

    // Controlla se il risultato è già stato calcolato
    if (dp[n] != -1) return dp[n];

    // Calcola il risultato per n-1 e n-2
    int dp1 = salireScale(n - 1, dp);
    int dp2 = (n - 2 >= 0) ? salireScale(n - 2, dp) : 0;

    // Salva il risultato nel vettore dp
    dp[n] = dp1 + dp2;
    return dp[n];
}

int main() {
    int n;
    cout << "Inserisci il numero di gradini: ";
    cin >> n;

    // Inizializza il vettore dp con -1
    vector<int> dp(n + 1, -1);

    // Calcola il numero totale di modi distinti
    int modi = salireScale(n, dp);
    cout << "Numero di modi distinti per salire " << n << " gradini: " << modi << endl;

    return 0;
}
