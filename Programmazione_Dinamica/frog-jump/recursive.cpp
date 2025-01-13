#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

/**
 * la rana può salire n gradini in 1 o 2 passi.
 * sapendo ciò calcolo l'energia che consuma : abs(height(n) - height(n-1))
 * ESSENDO CHE devo trovare il minimo, effettuo il minimo, dei valori ottenuti.
 */

// Funzione ricorsiva con memoizzazione
int energiaMinima(int n, vector<int>& dp, vector<int>& height) {
    // Caso base
    if (n == 0) return 0;

    // Controlla se il risultato è già stato calcolato
    if (dp[n] != -1) return dp[n];

    // Calcola il costo per saltare da n-1 a n
    int costo1 = energiaMinima(n - 1, dp, height) + abs(height[n] - height[n - 1]);

    // Calcola il costo per saltare da n-2 a n (se n-2 è valido)
    int costo2;
    if(n-2>0){ 

    costo2 =  energiaMinima(n - 2, dp, height) + abs(height[n] - height[n - 2]);
    }
    // Salva il minimo tra i due costi
    dp[n] = min(costo1, costo2);

    return dp[n];
}

int main() {
    int n;
    cout << "Inserisci il numero di gradini: ";
    cin >> n;

    vector<int> height(n);
    cout << "Inserisci le altezze di ogni gradino:\n";
    for (int i = 0; i < n; i++) {
        cin >> height[i];
    }

    // Inizializza il vettore dp con -1
    vector<int> dp(n, -1);

    // Calcola l'energia minima richiesta
    int energia = energiaMinima(n - 1, dp, height);
    cout << "Energia minima richiesta: " << energia << endl;

    return 0;
}
