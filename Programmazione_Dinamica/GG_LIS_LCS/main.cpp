//https://www.geeksforgeeks.org/longest-common-increasing-subsequence-lcs-lis/
#include <bits/stdc++.h>
using namespace std;

int f(vector<vector<int>>& dp, vector<int>& arr1, vector<int>& arr2 ,int i, int j) {
  
    if(i<0 || j<0) return -1000000;

    if (dp[i][j] != 0) return dp[i][j];

    int take = 0, notake = 0;

    for(int k = arr2.size()-1 ; k > 0 ; k--){ // NOTA POTRESTI FARE DELLE MIGLIORIE. 
    // PERCHè ? 
    // ogni volta riparte da 0. invece dovrebbe ripartire dall ultimo elemeneto salvato.
    // quindi avrebbe + senso salvare un valore e andare avanti.
          cout<< " arr 1 : "<< arr1[i]<<" arr2 :"<<arr2[k]<< endl;
        if(arr1[i] == arr2[k]){
              //  cout<< " arr 1 : "<< arr1[i]<<" arr2 :"<<arr2[k]<< endl; 
            take = 1 + f(dp, arr1,arr2,i-1, k-1);
        }
    }
       notake = max(f(dp, arr1, arr2, i - 1, j), f(dp, arr1, arr2, i, j - 1));  // Caso in cui non prendiamo l'elemento

  

    return dp[i][j] = max(take, notake);
}

int main() {
    vector<int> arr1 = {3,4,9,10,1};

    vector<int> arr2 = {5,3,8,9,10,2,1};    
    
    int n1 = arr1.size();
    int n2 = arr2.size();

    vector<vector<int>> dp(n1, vector<int>(n2, 0));  // 2 per comprare o vendere
    
    int result = f(dp, arr1,arr2, n1-1, n2-1);  
    cout << "VALORE MASSIMO POSSIBILE: " << result << endl;

    return 0;
}
