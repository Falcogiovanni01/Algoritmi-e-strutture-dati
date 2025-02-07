#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

pair<int, int> solve(vector<int>& tempi, int n, int t) {
    sort(tempi.begin(), tempi.end());
    int m = tempi.size();
    int posizione = 0, tempo_tot = 0;

    if (m % n == 0) {
        tempo_tot = tempi[n - 1] + 2 * t;
        posizione = n;
    } else {
        tempo_tot = tempi[m % n - 1] + 2 * t;
        posizione = m % n;
    }

    for (; posizione < m; posizione += n) {
        if (tempo_tot >= tempi[posizione + n - 1]) {
            tempo_tot += 2 * t;
        } else {
            tempo_tot = tempi[posizione + n - 1] + 2 * t;
        }
    }
    
    tempo_tot -= t;
    return {tempo_tot, (m + n - 1) / n};
}

int main() {
     int n = 2;  // Capacità del traghetto
    int t = 10;  // Tempo di attraversamento
    vector<int> arr = {0, 10, 20, 30, 40, 50, 60, 70, 80, 90};  // Orari di arrivo delle auto
    vector<vector<int>> dp(arr.size(), vector<int>(n + 1, -1));  // Memorizzazione dei risultati
    
        pair<int, int> sol = solve(arr, n, t);
        cout << sol.first << " " << sol.second << endl;
    
    
    return 0;
}
