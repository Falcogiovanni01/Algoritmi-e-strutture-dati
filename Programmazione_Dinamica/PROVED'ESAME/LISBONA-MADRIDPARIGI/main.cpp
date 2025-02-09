/**
 * Per semplicità, si supponga di rappresentare ogni città con un carattere, utilizzando lettere 
maiuscole, lettere minuscole, cifre e lo spazio. Quindi, si possono avere al massimo 63 città diverse 
da visitare. E’ possibile visitare una città più di una volta. 
Ad esempio, se Parigi è rappresentata con 'a', Madrid con 'b', lcsbona con 'c' e Londra con 'd', allora 
il suggerimento di tua madre sarebbe 'abcd' e il suggerimento di tuo padre sarebbe 'acdb' (o 'dacb', 
nel secondo esempio). 
Il programma legge due sequenze di viaggio e deve fornire il numero massimo di città visitabili in 
modo da soddisfare al meglio i suggerimenti di entrambi i genitori.  
*/

#include <bits/stdc++.h>
using namespace std;
#include <vector>
// TABULATION
int LCS(string &s1, string &s2) {
    int n = s1.size(), m = s2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    // Costruzione della tabella DP
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[n][m];
}
// MEMOIZATION
int lcs(vector<vector<int>> &dp, string s1, string s2, int i, int j ) {
    if( i == 0 || j == 0 ){
        return 0; 
    }

    if(dp[i][j]!=-1 ){

        return dp[i][j]; 
    }
    
    if(s1[i-1]==s2[j-1]){
        dp[i][j] = 1 + lcs(dp, s1, s2, i - 1, j - 1);
    } else {
           dp[i][j] = max(lcs(dp, s1, s2, i - 1, j), lcs(dp, s1, s2, i, j - 1));
    }

    
    return dp[i][j];

}



int main() {
    string s = "abcd";
    string d = "acdb"; 

    vector<vector<int>> dp( s.size()+1, vector<int> (d.size()+1, -1)); 

    // Call the longestPalindromeSubsequence function and print the result
    cout << "The Length of Longest common Subsequence is " << lcs(dp, d , s, d.size(), s.size())<<endl;
    int ritorno = LCS(s,d);
     cout << "TABULATION " << ritorno ;
   
    return 0;
}


