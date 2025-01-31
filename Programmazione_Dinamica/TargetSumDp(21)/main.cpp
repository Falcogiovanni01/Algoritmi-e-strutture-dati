#include <iostream>
#include <vector>

using namespace std;

int dynamicProgramming(vector<int>& Arr, vector<vector<int>>& dp, int i, int target, int offset, int sum) {
    if (i < 0) {
        return (target == 0) ? 1 : 0;  // Se target è 0, è una soluzione valida
    }
    
    // Convertiamo il target in un indice valido per dp
    int index = target + offset;
    
    // Controllo per evitare accesso fuori limite
    if (index < 0 || index >= 2 * sum + 1) {
        return 0;
    }

    if (dp[i][index] != -1) {
        return dp[i][index];
    }

    // Proviamo sia la somma che la sottrazione
    int add = dynamicProgramming(Arr, dp, i - 1, target + Arr[i], offset, sum);
    int subtract = dynamicProgramming(Arr, dp, i - 1, target - Arr[i], offset, sum);

    dp[i][index] = add + subtract;
    return dp[i][index];
}

int countTargetExpressions(vector<int>& Arr, int target) {
    int sum = 0;
    for (int num : Arr) {
        sum += num;
    }

    // Se il target è fuori dal range possibile, non esistono soluzioni
    if (abs(target) > sum) {
        return 0;
    }

    int offset = sum;  // Offset per gestire target negativi
    vector<vector<int>> dp(Arr.size(), vector<int>(2 * sum + 1, -1));

    return dynamicProgramming(Arr, dp, Arr.size() - 1, target, offset, sum);
}

int main() {
    /**
     *  1-2-3-1 
     * 
     * somma totale = 7 
     * S1+S2 = sommatotale 
     * S1-S2 = target.
     * S1+S2-(S1-S2) = (sommatoria-target) ;
     * 2S2 = ( sommatoria - target ) ; 
     * S2 = ( sommatoria - target )/2 ; 
     *  
     * // tutti i valori che hanno S2 = ( 7-3)/ 2 = 2.
     * 1 -2 +3 +1  = 3 -2 +2 =3 
     * -1 +2 +3 -1 = 3 +2 -2 = 3.
     * 
     */
    vector<int> Arr = {5,2,3,1,1,1}; 
    int target = 3;

    int result = countTargetExpressions(Arr, target);
    cout << "Sono presenti " << result << " soluzioni" << endl;
    return 0;
}
