#include <iostream>
#include <vector>
#include <limits>

using namespace std;

#define MAX 1000000

int min_sum(const vector<int>& vettore, int target, int indice, vector<vector<int>>& memo) {
    // Caso base: se il target è zero, non serve usare elementi
    if (target == 0) {
        return 0;
    }

    // Caso base: se il target è negativo o l'indice è fuori intervallo, restituiamo infinito
    if (target < 0 || indice < 0) {
        return MAX;
    }

    // Controllo se il risultato è già stato calcolato
    if (memo[indice][target] != -1) {
        return memo[indice][target];
    }

    // Calcolo del caso 'non take' (non utilizziamo l'elemento corrente)
    int non_take = min_sum(vettore, target, indice - 1, memo);

    // Calcolo del caso 'take' (utilizziamo l'elemento corrente, se possibile)
    int take = MAX;
    if (vettore[indice] <= target) {
        take = 1 + min_sum(vettore, target - vettore[indice], indice, memo);
    }

    // Calcolo del risultato minimo tra 'take' e 'non take'
    memo[indice][target] = min(take, non_take);
    return memo[indice][target]; //: alla fine indice target avrai la soluzione del problema
    // quindi per costruzione dell'algoritmo!.
}

int main() {
    vector<int> vettore = { 1, 5};
    int target = 10;
    int n = vettore.size();

    // Matrice per la memoization
    vector<vector<int>> memo(n, vector<int>(target + 1, -1));

    int result = min_sum(vettore, target, n - 1, memo);

    if (result == MAX) {
        cout << "Non è possibile raggiungere il target con i valori forniti." << endl;
    } else {
        cout << "Il minimo numero di elementi per raggiungere il target " << target << " è: " << result << endl;
    }

    vector<int> vett = {1, 3, 4, 5 };
    int target1 = 7;
    int dim = vett.size();
    vector<vector<int>> dp(dim, vector<int>(target1 + 1, -1));
    int result1 = min_sum(vett, target1, dim - 1, dp);

    if (result1 == MAX) {
        cout << "Non è possibile raggiungere il target con i valori forniti." << endl;
    } else {
        cout << "Il minimo numero di elementi per raggiungere il target " << target1<< " è: " << result1 << endl;
    }
    vector<int> vett2 = {3, 2, 5 };
    int target2 = 8;
    int dim2 = vett2.size();
    vector<vector<int>> dp2(dim2, vector<int>(target2 + 1, -1));
    int result2 = min_sum(vett2, target2, dim2 - 1, dp2);

    if (result2 == MAX) {
        cout << "Non è possibile raggiungere il target con i valori forniti." << endl;
    } else {
        cout << "Il minimo numero di elementi per raggiungere il target " << target2<< " è: " << result2 << endl;
    }

    vector<int> vett3 = { };
    int target3 = 10;
    int dim3 = vett3.size();
    vector<vector<int>> dp3(dim3, vector<int>(target3 + 1, -1));
    int result3 = min_sum(vett3, target3, dim3 - 1, dp3);

    if (result3 == MAX) {
        cout << "Non è possibile raggiungere il target con i valori forniti." << endl;
    } else {
        cout << "Il minimo numero di elementi per raggiungere il target " << target3<< " è: " << result3 << endl;
    }

    vector<int> vett4 = {1, 3, 5};
    int target4 = 0;
    int dim4 = vett4.size();
    vector<vector<int>> dp4(dim4, vector<int>(target4 + 1, -1));
    int result4 = min_sum(vett4, target4, dim4 - 1, dp4);

    if (result4 == MAX) {
        cout << "Non è possibile raggiungere il target con i valori forniti." << endl;
    } else {
        cout << "Il minimo numero di elementi per raggiungere il target " << target4<< " è: " << result4 << endl;
    }

    
    vector<int> vett5 = {10};
    int target5 = 10;
    int dim5 = vett5.size();
    vector<vector<int>> dp5( dim5, vector<int>(target5 + 1, -1));
    int result5 = min_sum(vett5, target5, dim5 - 1, dp5);

    if (result5 == MAX) {
        cout << "Non è possibile raggiungere il target con i valori forniti." << endl;
    } else {
        cout << "Il minimo numero di elementi per raggiungere il target " << target5<< " è: " << result5 << endl;
    }



    return 0;
}
