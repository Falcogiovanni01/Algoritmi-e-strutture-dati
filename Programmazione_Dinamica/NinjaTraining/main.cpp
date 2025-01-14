#include <iostream>
#include <vector>
#include <algorithm> // Per std::max
using namespace std;
/**
 * qui ho una matrice :
 *  vector<vector<int>> points = {
 *     {10, 40, 70},
 *       {20, 50, 80},
 *       {30, 60, 90}
 *   };
 *   ogni riga rappresenta un giorno :   
 *  // day 0
    // day 1 
    // day 2
  *  ogni colonna una task, 
  *  però la task che effettua il giorno x non può effettuarla anche il giorno x-1, dunque 
  *  calcola il massimo dei punteggi che può effettuare.
 */
// Funzione ricorsiva con memoization
int ninjaTraining(int day, int lastActivity, const vector<vector<int>>& points, vector<vector<int>>& dp) {
    if (day < 0) return 0; // Nessun giorno rimanente
    if (day == 0) { // Primo giorno, scegli l'attività con il massimo punteggio diverso dall'ultima
        int maxPoints = 0;
        for (int activity = 0; activity < 3; ++activity) {
            if (activity != lastActivity) {
                maxPoints = max(maxPoints, points[0][activity]);
            }
        }
        return maxPoints;
    }
    if (dp[day][lastActivity] != -1) return dp[day][lastActivity]; // Restituisci il valore calcolato

    int massimo = 0; // Calcolo del massimo punteggio
    for (int activity = 0; activity < 3; ++activity) {
        if (activity != lastActivity) { // Non ripetere l'attività precedente
            int pick = ninjaTraining(day - 1, activity, points, dp) + points[day][activity];
            massimo = max(massimo, pick);
        }
    }

    dp[day][lastActivity] = massimo; // Salva il risultato nella memoization
    return massimo;
}

// Funzione principale per calcolare i punti massimi
int findMaxMeritPoints(const vector<vector<int>>& points) {
    int n = points.size();
    vector<vector<int>> dp(n, vector<int>(4, -1)); // Array per memoization
    return ninjaTraining(n - 1, 3, points, dp); // 3 indica nessuna attività iniziale
}

// Main
int main() {
    // Esempio di input
    vector<vector<int>> points = {
        {10, 40, 70},
        {20, 50, 80},
        {30, 60, 90}
    };

    // Calcolo del massimo punteggio
    int result = findMaxMeritPoints(points);

    // Output del risultato
    cout << "Il massimo numero di punti di merito è: " << result << endl;

    return 0;
}
