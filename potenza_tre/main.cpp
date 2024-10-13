#include<iostream>
using namespace std ; 
bool potenza_tre(int numero);
int main(){
   
    bool controlla = potenza_tre(10); 
    cout<< "\n è potenza di tre ? "<< controlla ; 
       bool controlla1 = potenza_tre(256); 
    cout<< "\n è potenza di tre ? "<< controlla1 ; 
        bool controlla12 = potenza_tre(1); 
    cout<< " \n è potenza di tre ? "<< controlla12 ; 
      bool controlla122 = potenza_tre(27); 
    cout<< "\n è potenza di tre ? "<< controlla122 ; 
       bool controlla123 = potenza_tre(2187); 
    cout<< "\n è potenza di tre ? "<< controlla123 ; 



}

bool potenza_tre(int numero ){
    if(numero == 1 ){
        return true ; 
    }
    if(numero %3 != 0){
        return false ; 
    }
    return potenza_tre(numero/3) ; 

}

