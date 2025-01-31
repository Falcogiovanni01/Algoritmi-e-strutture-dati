#include <iostream>
#include <vector>
using namespace std;

int countDifference(vector<vector<int>>& dp, vector<int>& Arr , int target, int indice, int diff, int k) {
    if (k == diff) {
        return 1;  
    }

    if (indice < 0) {
        return 0;  // Se fuori dai limiti della griglia
    }

    if (dp[indice][target] != -1) {
        return dp[indice][target];  // Usa il valore memorizzato
    }

    // Muoversi a sinistra (colonna - 1)
    int noTake = countDifference(dp, Arr, target, indice - 1, diff,k);

    int take = 0;
    if (target - Arr[indice] >= 0) {
        // INDICE = 1 : 1 -(2,n-1) 
        // indice 2 : 1+2 , ( 2+1 , n-1)
        int sum1 = 0 ; 
        int sum2 = 0 ; 
        
        for ( int i = 0; i< indice ; i++){

          sum1 += Arr[i] ;   

        }

         for ( int i = indice; i< Arr.size(); i++){
            
          sum2 += Arr[i] ;   
        }
        diff = abs(sum1-sum2) ; 
        
        cout<< " sum1 : "<< sum1 << "|| sum 2 : "<< sum2 <<" = diff " << diff<<" k = "<<k<< endl ; 

        take = countDifference(dp, Arr, target - Arr[indice], indice - 1,diff,k);


    }
    
    cout << "take: " << take << " | noTake: " << noTake
         << " | indice: " << indice << " | target: " << target << endl;

    dp[indice][target] = take + noTake;

    return dp[indice][target];
}

int main() {
    vector<int> Arr = {5, 2, 6, 4};
    int target = 3;
    
    // Creazione della matrice dp inizializzata a -1
    vector<vector<int>> dp(Arr.size(), vector<int>(target + 1, -1));
    int diff = 0 ; 
    int indice = Arr.size() - 1; // Corretto l'indice
    int result = countDifference(dp, Arr, target, indice,  diff, target);

    cout << "Total count of subsets: " << result << endl;

    return 0;
}
