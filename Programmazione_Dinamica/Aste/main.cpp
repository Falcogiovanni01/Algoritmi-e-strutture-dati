#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Funzione ricorsiva con programmazione dinamica
int Aste(vector<vector<int>> &dp, const vector<int> &lunghezza, const vector<int> &prezzo, int indice, int asta) {
    // Caso base: se non ci sono più oggetti o la capacità dell'asta è esaurita
    if (indice == lunghezza.size() || asta == 0) {
        return 0;
    }

    // Se il valore è già stato calcolato, restituiscilo
    if (dp[asta][indice] != -1) {
        return dp[asta][indice];
    }

    // Caso in cui non prendo l'oggetto corrente
    int nonPrendo = Aste(dp, lunghezza, prezzo, indice + 1, asta);

    // Caso in cui prendo l'oggetto corrente (se possibile)
    int prendo = 0;
    if (asta >= lunghezza[indice]) {
        prendo = prezzo[indice] + Aste(dp, lunghezza, prezzo, indice + 1, asta - lunghezza[indice]);
    }

    // Salva e restituisci il massimo tra le due scelte
    dp[asta][indice] = max(prendo, nonPrendo);
    return dp[asta][indice];
}

// Funzione principale per risolvere il problema
int risolviAste(const vector<int> &lunghezza, const vector<int> &prezzo, int asta) {
    int n = lunghezza.size();
    // Inizializza la tabella DP con -1
    vector<vector<int>> dp(asta + 1, vector<int>(n, -1));
    return Aste(dp, lunghezza, prezzo, 0, asta);
}

int main() {
    // Input: lunghezze e prezzi degli oggetti, capacità massima dell'asta
    vector<int> lunghezza = {1, 3, 4, 5}; // Lunghezze degli oggetti
    vector<int> prezzo = {10, 40, 50, 70}; // Prezzi associati agli oggetti
    int asta = 7; // Capacità massima dell'asta

    // Risolvi il problema e stampa il risultato
    cout << "Valore massimo ottenibile: " << risolviAste(lunghezza, prezzo, asta) << endl;

    return 0;
}
