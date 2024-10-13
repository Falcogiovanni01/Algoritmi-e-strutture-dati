#include <iostream>
using namespace std;

bool palindromoRicorsivo(int vettore[], int posizioneIniziale, int posFinale){
    if(posizioneIniziale>=posFinale){
        return true ;
    }
    if(vettore[posizioneIniziale] != vettore[posFinale]){
     return false ; 
    }
       return palindromoRicorsivo(vettore, posizioneIniziale+1, posFinale-1) ; 
}


bool palindromo1( int vettore[],int dim){
   
    if(dim ==1 || dim == 0){
        return true ; 
    } 
    return palindromoRicorsivo(vettore, 0, dim-1) ; 
    
    }


int main() {
    int vettore[] = {1, 2, 1, 2};      // Non palindromo
    int vettore1[] = {1, 2, 2, 1};     // Palindromo
    int vettore2[] = {1, 2, 1};        // Palindromo
    int vettore3[] = {3, 2, 1};        // Non palindromo

    // Passiamo la dimensione degli array insieme all'array stesso
    bool result = palindromo1(vettore, sizeof(vettore) / sizeof(vettore[0]));
    bool result1 = palindromo1(vettore1, sizeof(vettore1) / sizeof(vettore1[0]));
    bool result2 = palindromo1(vettore2, sizeof(vettore2) / sizeof(vettore2[0]));
    bool result3 = palindromo1(vettore3,sizeof(vettore3) / sizeof(vettore3[0]));

    // Stampa i risultati
    cout << "Il primo vettore è " << (result ? "palindromo" : "non palindromo") << endl;
    cout << "Il secondo vettore è " << (result1 ? "palindromo" : "non palindromo") << endl;
    cout << "Il terzo vettore è " << (result2 ? "palindromo" : "non palindromo") << endl;
    cout << "L'ultimo vettore è " << (result3 ? "palindromo" : "non palindromo") << endl;

    return 0;
}
