using namespace std; 
#include "iostream"
int main(){
    int n = 5 ; 
    int variabileAppoggio =1 ;
    for( int i =0 ; i< n ; i++){
        variabileAppoggio = variabileAppoggio * (n-i); 
        // COSI FACENDO PRENDO TUTTI I CASI . 
        cout << endl << "i  : "<< i << " -- "; 
        cout <<"VARIABILE APPOGGIO: "<< variabileAppoggio << endl ; 
    }
    cout << "valore finale : "<< variabileAppoggio; 
}