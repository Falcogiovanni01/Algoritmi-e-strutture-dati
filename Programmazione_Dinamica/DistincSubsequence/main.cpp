#include <bits/stdc++.h>
using namespace std;
// *********** PROBLEMS *****************
//https://takeuforward.org/data-structure/distinct-subsequences-dp-32/

// Funzione ricorsiva con memoization
int countUtil(string &s1, string &s2, int ind1, int ind2, vector<vector<int>>& dp) {
    // Caso base: se s2 è completamente abbinata, conta come una soluzione valida
    if (ind2 < 0) return 1;
    
    // Caso base: se s1 è esaurita prima di s2, non può esserci un abbinamento valido
    if (ind1 < 0) return 0;

    // Se il valore è già stato calcolato, restituiscilo
    if (dp[ind1][ind2] != -1) return dp[ind1][ind2];

    // Opzione 1: Non prendere il carattere corrente di s1
    int notake = countUtil(s1, s2, ind1 - 1, ind2, dp);

    // Opzione 2: Prendere il carattere corrente solo se corrisponde
    int take = 0;
    if (s1[ind1] == s2[ind2]) {
        take = countUtil(s1, s2, ind1 - 1, ind2 - 1, dp);
    }
  

    // Salviamo il risultato nella tabella dp e lo restituiamo
    return dp[ind1][ind2] = (notake + take) ;
}

// Funzione principale per contare le sottosequenze distinte
int subsequenceCounting(string &s1, string &s2) {
    int lt = s1.size(), ls = s2.size();
    vector<vector<int>> dp(lt, vector<int>(ls, -1)); // Inizializza la tabella di memoization
    return countUtil(s1, s2, lt - 1, ls - 1, dp);
}

int main() {
    string s1 = "babgbag";
    string s2 = "bag";

    // Stampa il numero di sottosequenze distinte
    cout << "The Count of Distinct Subsequences is " << subsequenceCounting(s1, s2) << endl;
    return 0;
}
