#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Funzione per calcolare il tempo minimo e il numero minimo di viaggi
pair<int, int> ferryLoading(int n, int t, vector<int>& arrivals) {
    int m = arrivals.size();
    vector<int> dp(m + 1, 0);
    
    for (int i = 0; i < m; i += n) {
        int batch_end = min(i + n, m) - 1; // L'ultima auto nel batch
        int last_time = arrivals[batch_end] + 2 * t; // Tempo necessario per questo batch
        dp[batch_end] = (i == 0 ? last_time : max(dp[i - 1], last_time));
    }
    
    int trips = (m + n - 1) / n; // Numero minimo di viaggi richiesti
    return {dp[m - 1], trips};
}

int main() {
    int n = 2 ; 
        int t = 10 ; 
        vector<int> arr = {0,10,20,30,40,50,60,70,80,90}; 
        // vector<int> arr = {0,10,30,40}; 
   
      
        auto result = ferryLoading(n, t, arr); 
          cout << result.first << " " << result.second << endl;
    
    return 0;
}
