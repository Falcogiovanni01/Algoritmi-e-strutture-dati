#include <iostream>
#include <vector>
using namespace std;

int countSubset(vector<vector<int>>& dp, vector<int>& Arr , int target, int indice) {
    if (target == 0) {
        return 1;  
    }

    if (indice < 0) {
        return 0;  // Se fuori dai limiti della griglia
    }

    if (dp[indice][target] != -1) {
        return dp[indice][target];  // Usa il valore memorizzato
    }

    // Muoversi a sinistra (colonna - 1)
    int noTake = countSubset(dp, Arr, target, indice - 1);

    int take = 0;
    if (target - Arr[indice] >= 0) {
        take = countSubset(dp, Arr, target - Arr[indice], indice - 1);
    }
    
    cout << "take: " << take << " | noTake: " << noTake
         << " | indice: " << indice << " | target: " << target << endl;

    dp[indice][target] = take + noTake;

    return dp[indice][target];
}

int main() {
    vector<int> Arr = {1, 2, 2, 3};
    int target = 0;

    // Creazione della matrice dp inizializzata a -1
    vector<vector<int>> dp(Arr.size(), vector<int>(target + 1, -1));

    int indice = Arr.size() - 1; // Corretto l'indice
    int result = countSubset(dp, Arr, target, indice);

    cout << "Total count of subsets: " << result << endl;

    return 0;
}
