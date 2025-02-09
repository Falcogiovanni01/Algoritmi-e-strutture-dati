#include <bits/stdc++.h>
using namespace std;

bool check(char op) {
    return (op == '+' || op == '*');
}

unordered_map<string, pair<int, int>> memo;

pair<int, int> solve(vector<int>& numero, vector<char>& simbolo, int i, int j) {
    string key = to_string(i) + "," + to_string(j);
    if (memo.find(key) != memo.end()) return memo[key];
    
    if (i == j) return {numero[i], numero[i]};
    
    int minVal = INT_MAX, maxVal = INT_MIN;
    
    for (int k = i; k < j; k++) {
        auto left = solve(numero, simbolo, i, k);
        auto right = solve(numero, simbolo, k + 1, j);
        
        int min1, max1;
        if (simbolo[k] == '+') {
            min1 = left.first + right.first;
            max1 = left.second + right.second;
        } else { // '*'
            min1 = left.first * right.first;
            max1 = left.second * right.second;
        }
        
        minVal = min(minVal, min1);
        maxVal = max(maxVal, max1);
    }
    
    return memo[key] = {minVal, maxVal};
}

void stampa_min_max(string espressione) {
    vector<int> numero;
    vector<char> simbolo;
    string tmp = "";

    for (char c : espressione) {
        if (check(c)) {
            simbolo.push_back(c);
            numero.push_back(stoi(tmp));
            tmp = "";
        } else {
            tmp += c;
        }
    }
    numero.push_back(stoi(tmp));
    
    memo.clear();
    auto res = solve(numero, simbolo, 0, numero.size() - 1);
    
    cout << "Valore minimo ottenibile: " << res.first << endl;
    cout << "Valore massimo ottenibile: " << res.second << endl;
}

int main() {
    string espressione = "2+4*2*3+7";
    stampa_min_max(espressione);
    return 0;
}
