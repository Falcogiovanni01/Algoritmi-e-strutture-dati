// vedremo le matrici "normali"
// come vengono costruite è come sarà possibile accedere: 
#include <iostream>
using namespace std ; 

void printMatrix( int matrice[][3], int riga, int colonna);

int main(){
    int i ,j ; 
    const int ROWS = 3;
    const int COLS = 3;
    int matrice[ROWS][COLS] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    printMatrix(matrice, ROWS, COLS);

    cout << " SCEGLI i e j " ; 
    cin >> i ; 
    cout <<" \n " ; 
    cin >> j ; 
    cout <<" SCELTO RIGA : "<<i<<" SCELGO COLONNA "<< j<< "\n";
    cout << " SCEGLI IL VALORE : "<< endl ; 
    int value ;
    cin >> value;

    if(value != 0 ) {

        matrice[i][j] = value;

        printMatrix(matrice, ROWS, COLS);

    }


}

void printMatrix( int matrice[][3], int riga, int colonna) {

    for( int i = 0 ; i<riga ; i ++ ) {

        for ( int j = 0 ; j < colonna ; j ++ ) {

            cout << matrice[i][j] << " \t "; 
        }
        cout << "\n";
    }

}