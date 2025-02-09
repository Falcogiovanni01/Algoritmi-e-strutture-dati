#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

void solveFerryProblem(int n, int t, int m, vector<int>& arrivalTimes) {
    vector<int> dp(m + 1, INT_MAX);
    vector<int> trips(m + 1, 0);
    dp[0] = 0;
    trips[0] = 0;

    for (int i = 1; i <= m; ++i) {
        for (int j = max(0, i - n); j < i; ++j) {
        
            int currentTime = max(dp[j], arrivalTimes[i - 1]) + 2 * t;
            if (currentTime < dp[i]) {
                dp[i] = currentTime;
                trips[i] = trips[j] + 1;
            }
        }
    }

    cout << dp[m] - t << " " << trips[m] << endl;
}

int main() {
   
    int n = 2; 
    //2 10 3 
    int t = 10 ; 
    int m = 10;
    vector<int> arr = {0, 10, 20, 30, 40, 50, 60, 70, 80, 90};  // Orari di arrivo delle auto

    solveFerryProblem(n, t, m, arr);

    return 0;
}