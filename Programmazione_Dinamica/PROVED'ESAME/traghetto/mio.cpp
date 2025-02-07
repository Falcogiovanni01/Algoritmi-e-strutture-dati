#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int viaggi_minimi(vector<vector<int>>& dp, vector<int>& arr, int i, int portata, int tempoAndata, int t, int n) {
    // Se tutte le auto sono state considerate, non c'è bisogno di ulteriori viaggi
    if (i >= arr.size()) return 0;

    // Se la soluzione è già stata calcolata per questo stato (memorizzazione del risultato)
    if (dp[i][portata] != -1) return dp[i][portata];

    int carico = INT_MAX, viaggio = INT_MAX;

    // Caso 1: Se il traghetto non è pieno, posso caricare un'auto
    if (portata > 0) {
        // Calcolo il tempo per caricare l'auto i-esima
        int tempoAttuale = max(tempoAndata, arr[i]);  // Non si può partire prima che l'auto arrivi
        tempoAttuale += t;  // Tempo di attraversamento
        carico = viaggi_minimi(dp, arr, i + 1, portata - 1, tempoAttuale, t, n);
    }

    // Caso 2: Se il traghetto è pieno (portata == 0), devo fare un viaggio
    if (portata == 0) {
        // Aggiungi un viaggio di andata
        int tempoRitorno = tempoAndata + t;  // Tempo per tornare indietro

        viaggio = 1 + viaggi_minimi(dp, arr, i, n, tempoRitorno, t, n); // Aggiungi un viaggio di andata e ritorno
    }

    // Memorizza il risultato del minimo tra carico e viaggio
    return dp[i][portata] = min(carico, viaggio);
}

int main() {
    int n = 2;  // Capacità del traghetto
    int t = 10;  // Tempo di attraversamento
    vector<int> arr = {0, 10, 20, 30, 40, 50, 60, 70, 80, 90};  // Orari di arrivo delle auto
    vector<vector<int>> dp(arr.size(), vector<int>(n + 1, -1));  // Memorizzazione dei risultati
    int minTime = viaggi_minimi(dp, arr, 0, n, 0, t, n);

    // Trova l'ora finale in cui tutte le auto sono state trasportate
    int ultimoTempo = 0;
    for (int i = 0; i < arr.size(); i++) {
        ultimoTempo = max(ultimoTempo, arr[i]) + t;  // Ultimo tempo di attraversamento
    }

    cout << "Tempo finale: " << ultimoTempo << " minuti, Viaggi: " << minTime << endl;

    return 0;
}
