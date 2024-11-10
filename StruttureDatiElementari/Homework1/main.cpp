#include <iostream>
using namespace std ; 
int maxArray(int vettore[], int inizio, int fine);
int main() {
  int vettore1[] = {1 ,2 ,3 ,40 ,3 ,2 ,1};
  int vettore2[] = {10 , 20 ,9 ,8, 7, 6 ,5, 3, 2, 1};
  int vettore3[] = {10, 20 ,40 ,50 ,80 ,90 ,100 ,22 ,1}; 
   
  int max1 = maxArray(vettore1,0,8) ; 
  cout<< "\n\n MASSIMO vettore 1 :"<<max1 ; 
  int max2 = maxArray(vettore2,0,9) ;
  cout<< "\n\n MASSIMO vettore 2 :"<<max2 ; 
  int max3 = maxArray(vettore3,0,8) ;
  cout<< "\n\n MASSIMO vettore 3 :"<<max3 ; 
  cout << endl << endl << endl ; 
  return 0;
}

int maxArray(int vettore[], int inizio, int fine){
  if(inizio == fine) {
    return vettore[inizio] ; 
  }
  int mid = inizio+(fine-inizio)/2 ; 
  if(vettore[mid]>vettore[mid+1]){
    maxArray(vettore, inizio, mid) ; 
  }else{
    maxArray(vettore,mid+1,fine) ; 
  }
}