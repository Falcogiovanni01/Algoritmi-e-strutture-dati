#include <bits/stdc++.h>
using namespace std;
// QUESTO è COPIATO DA TAKE U FORWARD. 
// RIPRENDE IL CONCETTO DI PARANTESEIZZAZIONE, VI CONSIGLIO DI VEDERVI LE SUE LEZIONI. 
// Function to calculate the minimum cost incurred
int findMinimumCost(int i, int j, vector<int> &cuts, vector<vector<int>> &dp) {
    // Base case: If i is greater than j, there are no cuts to consider.
    if (i > j) {
        return 0;
    }

    if (dp[i][j] != -1) {
        return dp[i][j];
    }

    int mini = INT_MAX;

    for (int ind = i; ind <= j; ind++) {
        // Calculate the cost for making a cut at position 'ind'.
        int ans = cuts[j + 1] - cuts[i - 1] +
                  findMinimumCost(i, ind - 1, cuts, dp) +
                  findMinimumCost(ind + 1, j, cuts, dp);

        mini = min(mini, ans);
    }

    return dp[i][j] = mini;
}

// Function to compute the minimum cost
int minimumCost(int n, int c, vector<int> &cuts) {
    // Modify the cuts array by adding 0 at the beginning and 'n' at the end.
    cuts.push_back(n);
    cuts.insert(cuts.begin(), 0);
    sort(cuts.begin(), cuts.end());

    // Create a DP table to store calculated values.
    vector<vector<int>> dp(c + 1, vector<int>(c + 1, -1));

    // Call the recursive function to find the minimum cost.
    return findMinimumCost(1, c, cuts, dp);
}

int main() {
    vector<int> cuts = {4, 5, 7, 8};
    int c = cuts.size();
    int n = 10;

    cout << "The minimum cost incurred is: " << minimumCost(n, c, cuts) << endl;

    return 0;
}


