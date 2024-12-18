#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
#define MASSIMO 0

int f (int i , vector<int> &vettore, int last, int massimo);

void printVector(vector<int> &vettore) ;

int main() {
    
  vector<int> vettore = {-2, 1, -3, 4, -1, 2, 1, -5, 4}; // 6= {4,-1,2,1}
  vector<int> vettore1 = {-1,2,-5,7};  // 7 = {7}
  vector<int> vettore2 = {-1,-3,4,2}; // 6 = {4,2}
  vector<int> vettore3 = {-1,-3,4,2,3}; //9 = {4,2,3}
  vector<int> vettore4 = {-1,-3,-4,-2}; // caso limite = return 0
  vector<int> vettore5 = {1,3,4,-7,2000}; // 2001 = {1,3,4,-7,2000}
  vector<int> vettore6 = {2, -1, 2, 3, -5, 4}; // 6 = {2,-1,2,3}
  vector<int> vettore7 = {2, 3,-1, -2, 5, 1, -6,8,-3,1}; // 10 = {2, 3,-1, -2, 5, 1, -6,8}
  
  printVector(vettore);
  int massimo = f(0,vettore,MASSIMO,0); 
  cout << " MASSIMO VETTORE : "<<massimo << endl;

  printVector(vettore1);
  int massimo1 = f(0, vettore1, MASSIMO, 0); 
  cout << " MASSIMO VETTORE 1 : "<<massimo1 << endl;
  
  printVector(vettore2);
  int massimo2 = f(0, vettore2, MASSIMO,0); 
  cout << " MASSIMO VETTORE 2 : "<<massimo2 << endl;

  printVector(vettore3);
  int massimo3 = f(0, vettore3, MASSIMO, 0); 
  cout << " MASSIMO VETTORE 3: "<<massimo3 << endl;

  printVector(vettore4);
  int massimo4 = f(0, vettore4, MASSIMO, 0); 
  cout << " MASSIMO VETTORE 4: "<<massimo4<< endl;

  printVector(vettore5);
  int massimo5 = f(0, vettore5, MASSIMO, 0); 
  cout << " MASSIMO VETTORE 5 : "<<massimo5 << endl;

  
  printVector(vettore6);
  int massimo6 = f(0, vettore6, MASSIMO, 0); 
  cout << " MASSIMO VETTORE 6: "<<massimo6<< endl;

  printVector(vettore7);
  int massimo7 = f(0, vettore7, MASSIMO, 0); 
  cout << " MASSIMO VETTORE 7 : "<<massimo7 << endl;



  return 0;
}

int f (int i , vector<int> &vettore,  int massimo, int sumCurrent) {
 
  for (int j = 0 ; j < vettore.size(); j++) { 

        sumCurrent += vettore[j];
        massimo = max ( massimo , sumCurrent) ;

      if( sumCurrent < 0 ) {

         sumCurrent = 0 ;
        }

    }

    return massimo;
}

void printVector(vector<int> &vettore) {

    for ( int i = 0 ; i < vettore.size() ; i++) {

        cout << vettore[i] << " "; 
    }
    cout <<" \n" ; 

}