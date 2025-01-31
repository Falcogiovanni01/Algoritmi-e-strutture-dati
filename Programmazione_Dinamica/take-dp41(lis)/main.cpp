#include <bits/stdc++.h>
using namespace std;

int f(vector<vector<int>>& dp, vector<int>& arr, int i, int prevIndex) {
    if (i == arr.size()) return 0; // Fine dell'array
    
    if (dp[i][prevIndex + 1] != -1) return dp[i][prevIndex + 1];

    // Non prendo l'elemento corrente
    int notake = f(dp, arr, i + 1, prevIndex);
    
    // Prendo l'elemento corrente solo se è maggiore del precedente nella LIS
    int take = 0;
    if (prevIndex == -1 || arr[i] > arr[prevIndex]) {
        take = 1 + f(dp, arr, i + 1, i);
    }

    return dp[i][prevIndex + 1] = max(take, notake);
}

int main() {
    vector<int> arr = {10, 9, 2, 5, 3, 7, 101, 18};
    int n = arr.size();

    vector<vector<int>> dp(n, vector<int>(n + 1, -1));
    
    int result = f(dp, arr, 0, -1);
    cout << "VALORE MASSIMO POSSIBILE (LIS): " << result << endl;

    return 0;
}
