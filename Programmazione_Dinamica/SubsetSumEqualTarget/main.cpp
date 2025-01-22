#include <iostream>
#include <vector>
using namespace std;
/**
 * A subset/subsequence is a contiguous or 
 * non-contiguous part of an array, where 
 * elements appear in the same order as the original array.
 * For example, for the array: [2,3,1] , 
 * the subsequences will be [{2},{3},{1},{2,3},{2,1},{3,1},{2,3,1}}
 *  but {3,2} is not a subsequence because its elements are not
 *  in the same order as the original array.
 */
bool subsetSum(vector<int>& array, int target) {
    // Creiamo un vettore DP con dimensione target + 1, inizializzato a false
    vector<bool> dp(target + 1, false);
    
    // Caso base: È sempre possibile ottenere la somma 0 con il sottoinsieme vuoto
    dp[0] = true;

    // Iteriamo sugli elementi dell'array
    for (int num : array) {
        // Aggiorniamo il vettore DP all'indietro per evitare sovrascrizioni
        for (int t = target; t >= num; --t) {
            dp[t] = dp[t] || dp[t - num];
        }
    }

    // Il risultato finale si trova in dp[target]
    return dp[target];
}

int main() {
    vector<int> array = {2, 3, 7, 8, 10}; // Esempio di input
    int target = 11;                      // Target desiderato

    if (subsetSum(array, target)) {
        cout << "Sì, esiste un sottoinsieme che somma a " << target << "." << endl;
    } else {
        cout << "No, non esiste un sottoinsieme che somma a " << target << "." << endl;
    }

    return 0;
}
