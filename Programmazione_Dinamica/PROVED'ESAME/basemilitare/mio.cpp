#include <bits/stdc++.h>
using namespace std;

// Funzione ricorsiva con memoization
int lisMio(vector<int>& y, vector<vector<int>>& dp, int i, int prevIndex) {
    if (i == y.size()) return 0;

    if (dp[i][prevIndex + 1] != -1) return dp[i][prevIndex + 1];

    // Non prendere y[i]
    int noTake = lisMio(y, dp, i + 1, prevIndex);

    // Prendere y[i] se è maggiore del precedente
    int take = 0;
    if (prevIndex == -1 || y[i] > y[prevIndex]) {
        take = 1 + lisMio(y, dp, i + 1, i);
    }

    return dp[i][prevIndex + 1] = max(take, noTake);
}

int main() {
    vector<int> Arr1 = {8, 5, 3, 2};  // Basi lato A
    vector<int> Arr2 = {3, 4, 7, 6};  // Basi lato B corrispondenti

    int N = Arr1.size();

    // Creiamo coppie (xi, yi) e le ordiniamo per xi
    vector<pair<int, int>> hash;
    for (int i = 0; i < N; i++) {
        hash.push_back({Arr1[i], Arr2[i]});
    }
    sort(hash.begin(), hash.end()); // Ordinare per xi

    // Estrarre Y ordinato
    vector<int> sortedY;
    for (auto& p : hash) {
        sortedY.push_back(p.second);
    }

    // Inizializziamo la tabella di memoization con -1
    vector<vector<int>> dp(N, vector<int>(N + 1, -1));

    // Calcoliamo la LIS con memoization
    int result = lisMio(sortedY, dp, 0, -1);
    
    cout << "Numero massimo di collegamenti non incrociati: " << result << endl;

    return 0;
}