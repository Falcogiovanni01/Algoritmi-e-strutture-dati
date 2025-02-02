#include <bits/stdc++.h>
using namespace std;

// Funzione ricorsiva con memoization
int lisMemoization(vector<int>& sortedY, vector<vector<int>>& dp, int i, int prevIndex) {
    // Caso base: se non ci sono più elementi
    if (i == sortedY.size()) return 0;

    // Se il valore è già stato calcolato, restituiscilo
    if (dp[i][prevIndex + 1] != -1) return dp[i][prevIndex + 1];

    // Non prendere il valore corrente
    int noTake = lisMemoization(sortedY, dp, i + 1, prevIndex);

    // Prendere il valore corrente solo se è maggiore dell'elemento precedente
    int take = 0;
    if (prevIndex == -1 || sortedY[i] > sortedY[prevIndex]) {
        take = 1 + lisMemoization(sortedY, dp, i + 1, i);
    }

    // Memorizzare il risultato nella tabella dp
    return dp[i][prevIndex + 1] = max(take, noTake);
}

int main() {
    vector<int> Arr1 = {8, 5, 3, 2};  // Basi lato A
    vector<int> Arr2 = {3, 4, 7, 6};  // Basi lato B corrispondenti

    int N = Arr1.size();

    // Creiamo coppie (xi, yi) e le ordiniamo per xi
    vector<pair<int, int>> pairs;
    for (int i = 0; i < N; i++) {
        pairs.push_back({Arr1[i], Arr2[i]});
    }
    sort(pairs.begin(), pairs.end()); // Ordinare per xi

    // Estrarre Arr2 riordinato secondo Arr1
    vector<int> sortedY;
    for (auto& p : pairs) {
        sortedY.push_back(p.second);
    }

    // Inizializziamo la tabella di memoization con -1
    vector<vector<int>> dp(N, vector<int>(N + 1, -1));

    // Calcoliamo la LIS con memoization
    int result = lisMemoization(sortedY, dp, 0, -1);

    cout << "Numero massimo di collegamenti non incrociati: " << result << endl;

    return 0;
}
