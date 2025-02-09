#include <iostream>
#include <vector>
#include <algorithm>
#include <climits> // Per INT_MIN

using namespace std;
/*- prendi la matrice dp : (costi+1)(budget+1) 
- le classi le interpreti come vettori, e dà li fai una matrice di classi. 
- ora ogni vettore hai una scelta,
 ora scorri sulla matrice dei costi e dà 
 li vai a prelevare gli elementi e man mano li salvi nel dp normale
 
 
Vediamo nel dettaglio come calcolare la complessità temporale del tuo algoritmo. Il tuo ragionamento è buono, ma possiamo essere più precisi analizzando il comportamento del programma.

1. Struttura del problema
L'algoritmo esegue due operazioni principali:

Iterazione sui prodotti di una classe (ciclo for): Simula tutte le scelte possibili per ogni classe.
Chiamata ricorsiva: Per ogni scelta, passa alla classe successiva e aggiorna il budget.
Quindi, il comportamento complessivo è governato da due fattori:

Budget (B): Va da 0 a B.
Numero totale di prodotti (dimensione della matrice dei costi): Questo è dato dal numero di classi (C) e dal numero massimo di prodotti per classe (M).
2. Complessità dell'algoritmo
Analizziamo il comportamento.

Passo 1: Chiamate ricorsive
Ogni stato del problema è definito da due parametri:

Il budget residuo (da 0 a B).
La classe corrente (da 0 a C).
Quindi, il numero totale di stati possibili è al massimo B * C.

Passo 2: Ciclo for per ogni classe
Per ogni stato, eseguiamo un ciclo for sui prodotti della classe corrente. Se il numero massimo di prodotti in una classe è M, il ciclo itera al massimo M volte.

 complessità
Per ciascuno dei B * C stati, il ciclo for itera al massimo M volte. 
Quindi la complessità complessiva è:

O(B⋅C⋅M)
Dove:

𝐵
B è il budget massimo.
𝐶
C è il numero di classi.
𝑀
M è il numero massimo di prodotti per classe.
 
 */
// Funzione ricorsiva con memoization
int solve(vector<vector<int>>& dp, vector<vector<int>>& costi, int budget, int classi) {
    // Base cases
    if (budget < 0) return INT_MIN; // Budget insufficiente (ritorna valore minimo)
    if (classi >= costi.size()) return 0; // Tutte le classi sono state considerate

    // Controllo se il risultato è già calcolato
    if (dp[classi][budget] != -1) return dp[classi][budget];

    int massimo = INT_MIN;

    // Itera sui prodotti della classe corrente
    // for (int prezzo : costi[classi]) {
    //     massimo = max(massimo, solve(dp, costi, budget - prezzo, classi + 1) + prezzo);
    // }
    // ITERA SU OGNI ELEMENTO DELLA CLASSE "I-ESIMA CHE HO classi"
    for (int i = 0; i < costi[classi].size(); ++i) {
    int prezzo = costi[classi][i];
    massimo = max(massimo, solve(dp, costi, budget - prezzo, classi + 1) + prezzo);
    }
    // Salva il risultato nella tabella dp
    dp[classi][budget] = massimo;
    return massimo;
}

int main() {
    // Input: classi e budget
    vector<int> classe1 = {8, 6, 4};
    vector<int> classe2 = {5, 10};
    vector<int> classe3 = {1, 3, 3, 7};
    vector<int> classe4 = {50, 14, 23, 8};

    vector<vector<int>> costi = {classe1, classe2, classe3, classe4};   

    int Budget = 100;

    // Inizializza la matrice dp con -1
    vector<vector<int>> dp(costi.size() + 1, vector<int>(Budget + 1, -1));

    // Calcola il risultato massimo
    int risultato = solve(dp, costi, Budget, 0);

    // Stampa il risultato
    if (risultato < 0) {
        cout << "denaro insufficiente" << endl;
    } else {
        cout << "Massimo denaro speso: " << risultato << endl;
    }

    return 0;
}
