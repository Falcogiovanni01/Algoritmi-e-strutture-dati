// LINK PROBLEM :https://takeuforward.org/data-structure/partition-equal-subset-sum-dp-15/
#include <iostream>
#include <vector>
#include <numeric> // Per std::accumulate
using namespace std;

// Funzione ricorsiva con memoization per verificare se esiste un sottoinsieme con somma "target"
bool partialSubset(vector<vector<int>>& dp, const vector<int>& vettore, int indice, int target) {
    // Caso base: se il target è 0, possiamo ottenere questa somma
    if (target == 0) return true;
    // Caso base: se il target è negativo o abbiamo finito gli elementi
    if (target < 0 || indice < 0) return false;
    // Se il risultato è già stato calcolato, lo restituiamo
    if (dp[indice][target] != -1) return dp[indice][target];

    // Opzione 1: includere l'elemento corrente
    bool take = partialSubset(dp, vettore, indice - 1, target - vettore[indice]);
    // Opzione 2: NON includere l'elemento corrente
    bool noTake = partialSubset(dp, vettore, indice - 1, target);

    // Memorizziamo il risultato per evitare ricalcoli
    dp[indice][target] = take || noTake;
    return dp[indice][target];
}

// Funzione principale per verificare se possiamo partizionare l'array
bool canPartition(vector<int>& arr) {
    // Calcoliamo la somma totale
    int totalSum = accumulate(arr.begin(), arr.end(), 0);

    // Se la somma totale è dispari, non possiamo dividerla in due parti uguali
    if (totalSum % 2 != 0) return false;

    int target = totalSum / 2;
    int n = arr.size();

    // Inizializziamo la matrice DP con -1 (non calcolato)
    vector<vector<int>> dp(n, vector<int>(target + 1, -1));

    // Avviamo la funzione ricorsiva partendo dall'ultimo elemento
    return partialSubset(dp, arr, n - 1, target);
}

// Funzione per testare il programma
int main() {
    vector<int> arr1 = {1, 5, 11, 5};
    vector<int> arr2 = {1, 2, 3, 5};

    cout << "Array 1: " << (canPartition(arr1) ? "True" : "False") << endl; // Output: True
    cout << "Array 2: " << (canPartition(arr2) ? "True" : "False") << endl; // Output: False

    return 0;
}
