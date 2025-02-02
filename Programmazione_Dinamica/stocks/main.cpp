#include <bits/stdc++.h>
using namespace std;

int f(vector<vector<int>>& dp, vector<int>& arr, int buy, int indice) {
    if (indice == arr.size()) return 0; // Fine dell'array

    if (dp[indice][buy] != -1) return dp[indice][buy];

    float take = 0, notake = 0;

    if (buy == 0) { // Possiamo comprare
        take = f(dp, arr, 1, indice + 1) -arr[indice];  // Compra
        cout<< " take  : "<<take ; 
        notake = f(dp, arr, 0, indice + 1);               // Non compra
    } else { // Possiamo vendere
        take = arr[indice] + f(dp, arr, 0, indice + 1);  // Vendi
        notake = f(dp, arr, 1, indice + 1);              // Non vendere
    }

    return dp[indice][buy] = max(take, notake);
}

int main() {
    vector<int> arr = {7,1,5,3,6,4};
    int n = arr.size();

    vector<vector<int>> dp(n, vector<int>(2, -1));  // 2 per comprare o vendere
    
    int result = f(dp, arr, 0, 0);  // Iniziamo con buy = 0 (possiamo comprare)
    cout << "VALORE MASSIMO POSSIBILE: " << result << endl;

    return 0;
}
