#include <iostream>
using namespace std;

bool palindromo(int vettore[], int dim) {

    for (int i = 0; i < dim / 2; i++) {
  
        if (vettore[i] != vettore[dim - 1 - i]) {
            return false; // Appena troviamo un elemento che non coincide, non è un palindromo
        }
    }
    return true; // Se tutti gli elementi corrispondono, è un palindromo
}

int main() {
    int vettore[] = {1, 2, 1, 2};      // Non palindromo
    int vettore1[] = {1, 2, 2, 1};     // Palindromo
    int vettore2[] = {1, 2, 1};        // Palindromo
    int vettore3[] = {3, 2, 1};        // Non palindromo

    // Passiamo la dimensione degli array insieme all'array stesso
    bool result = palindromo(vettore, sizeof(vettore) / sizeof(vettore[0]));
    bool result1 = palindromo(vettore1, sizeof(vettore1) / sizeof(vettore1[0]));
    bool result2 = palindromo(vettore2, sizeof(vettore2) / sizeof(vettore2[0]));
    bool result3 = palindromo(vettore3, sizeof(vettore3) / sizeof(vettore3[0]));

    // Stampa i risultati
    cout << "Il primo vettore è " << (result ? "palindromo" : "non palindromo") << endl;
    cout << "Il secondo vettore è " << (result1 ? "palindromo" : "non palindromo") << endl;
    cout << "Il terzo vettore è " << (result2 ? "palindromo" : "non palindromo") << endl;
    cout << "L'ultimo vettore è " << (result3 ? "palindromo" : "non palindromo") << endl;

    return 0;
}
