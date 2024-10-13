/**
 * Dato un array intero , 
 * trova il nums sottoserie con la somma più 
 * grande e restituire la sua somma.
 *  */
#include <iostream>
using namespace std ; 

int sums(int vettore[], int dimensione, int somma , int indice,  int sommaMax){
    if(indice <= dimensione-1){
     //   cout << "\n somma "<< somma << " \n indice  :"<< indice; 
       // cout << " \n \n";
        somma += vettore[indice] ;
     //   cout << " RESULT = "<< somma ; 
        if(somma <0){
           somma = 0 ;  // resetto e ricomincia .
        }
        if(somma>sommaMax){
            sommaMax = somma ; 
        }

        return sums(vettore,dimensione, somma, indice+1,sommaMax) ; 
      
    }else {

        return sommaMax ; 
    }
}




int main(){
                    // 0 1 2 3 4 5 6 7 8  9
    int vettore[] = { -2,1,-3,4,-1,2,1,-5,4} ;
    /* 6    */
    int dimensione = sizeof(vettore)/sizeof(vettore[0]) ; 
    int somma =0 ; 
    int sumMax =0 ;
    
    int result = sums ( vettore, dimensione, somma, 0, sumMax); 
    cout<< "\n risultato ? "<<result << endl ; 

     int vettore1[] = { 1,3,4,2,1,} ; //11
     
    int dimensione1 = sizeof(vettore1)/sizeof(vettore1[0]) ; 
    int result1 = sums ( vettore1, dimensione1, somma, 0, sumMax); 
    cout<< "\n risultato ? "<<result1 << endl ; 

         int vettore2[] = { 1,3,-4,2,1} ; //4
        
    int dimensione2 = sizeof(vettore2)/sizeof(vettore2[0]) ; 
    int result2 = sums ( vettore2, dimensione2, somma, 0, sumMax); 
    cout<< "\n risultato ? "<<result2 << endl ; 

       int vettore3[] = { 1} ; //1
     
    int dimensione3 = sizeof(vettore3)/sizeof(vettore3[0]) ; 
    int result3 = sums ( vettore3, dimensione3, somma, 0, sumMax); 
    cout<< "\n risultato ? "<<result3 << endl ; 
    
       int vettore4[] = { 0} ; //0
     
    int dimensione4= sizeof(vettore4)/sizeof(vettore4[0]) ; 
    int result4 = sums ( vettore4, dimensione4,0, 0, 0); 
    cout<< "\n risultato ? "<<result4 << endl ; 


}