#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solveFerry(int n, int t, vector<int> &arr, int &minTime, int &minTrips) {
    int m = arr.size();
    int maxTrips = (m + n - 1) / n;  // Numero massimo possibile di viaggi
    vector<vector<int>> dp(m + 1, vector<int>(maxTrips + 1, 1e9));
    vector<vector<int>> trips(m + 1, vector<int>(maxTrips + 1, 1e9));

    dp[0][0] = 0;
    trips[0][0] = 0;

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= maxTrips; j++) {
            for (int k = 1; k <= n && i - k >= 0; k++) {
                int timeNeeded = max(dp[i - k][j - 1] + 2 * t, arr[i - 1] + t);

                if (timeNeeded < dp[i][j]) {
                    dp[i][j] = timeNeeded;
                    trips[i][j] = trips[i - k][j - 1] + 1;
                } else if (timeNeeded == dp[i][j]) {
                    trips[i][j] = min(trips[i][j], trips[i - k][j - 1] + 1);
                }
            }
        }
    }

    // Troviamo la soluzione ottimale
    minTime = 1e9;
    minTrips = 1e9;
    for (int j = 1; j <= maxTrips; j++) {
        if (dp[m][j] < minTime) {
            minTime = dp[m][j];
            minTrips = trips[m][j];
        }
    }
}

int main() {
        int n = 2 ; 
        int t = 10 ; 
        vector<int> arr = {0,10,20,30,40,50,60,70,80,90}; 
        // vector<int> arr = {0,10,30,40}; 
   
        int minTime, numTrips;
        solveFerry(n, t, arr, minTime, numTrips);
        cout << minTime << " " << numTrips << endl;
    

    return 0;
}
