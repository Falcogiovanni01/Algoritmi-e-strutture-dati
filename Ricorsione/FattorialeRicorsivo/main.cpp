#include "iostream"
using namespace std;

int factorial(int number); // Dichiarazione anticipata

int main() {
    int val = factorial(5); 
    cout << "val = " << val;
}

int factorial(int number) {
    if (number == 1) { // va bene anche 0 perchè il fattoriale di 0 è 1.
        return 1;
    } else {
        return number * factorial(number - 1);
    }
};
