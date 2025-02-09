#include <bits/stdc++.h>
using namespace std;

bool check(char op) {
    return (op == '+' || op == '*');
}

void stampa_min_max(string espressione) {
    vector<int> numero;
    vector<char> simbolo;
    string tmp = "";

    for (int i = 0; i < espressione.length(); i++) {
        if (check(espressione[i])) {
            simbolo.push_back(espressione[i]);
            numero.push_back(stoi(tmp)); // converte la stringa in intero
            tmp = "";
        } else {
            tmp += espressione[i];
        }
    }
    numero.push_back(stoi(tmp)); // Aggiunge l'ultimo numero

    int length = numero.size();
    vector<vector<int>> min(length, vector<int>(length, INT_MAX));
    vector<vector<int>> max(length, vector<int>(length, INT_MIN)); // Cambiato da 0 a INT_MIN

    for (int i = 0; i < length; i++) {
        min[i][i] = max[i][i] = numero[i];
    }

    for (int L = 2; L <= length; L++) {
        for (int i = 0; i < length - L + 1; i++) {
            int j = i + L - 1;

            for (int k = i; k < j; k++) {
                int min1 = 0, max1 = 0;

                if (simbolo[k] == '+') { // Corretta la variabile simbolo[k]
                    min1 = min[i][k] + min[k + 1][j];
                    max1 = max[i][k] + max[k + 1][j];
                } else if (simbolo[k] == '*') {
                    min1 = min[i][k] * min[k + 1][j];
                    max1 = max[i][k] * max[k + 1][j];
                }

                min[i][j] = std::min(min[i][j], min1);
                max[i][j] = std::max(max[i][j], max1);
            }
        }
    }

    cout << "Valore minimo ottenibile: " << min[0][length - 1] << endl;
    cout << "Valore massimo ottenibile: " << max[0][length - 1] << endl;
}

int main() {
   // string espressione = "3*14+19+3*10";
    string espressione = "2+4*2*3+7";
    stampa_min_max(espressione);
    return 0;
}
