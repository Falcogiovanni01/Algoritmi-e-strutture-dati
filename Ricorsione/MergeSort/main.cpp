#include "iostream"
using namespace std;

void MergeSort(int vettore[] , int start, int end ); // Dichiarazione anticipata
void Merge(int vector[], int start , int mid, int end ); 

void  printVector(int vector[], int dim ) ; 

int main() {
    // int val = MergeSort([], 0,0); 
    // cout << "val = " << val;
    int vettore[] = {30 ,20 ,10,1} ; 

    int dim = sizeof(vettore) / sizeof(vettore[0]);
      cout << "Vettore prima di essere ordinato:\n";
    printVector(vettore, dim);
    MergeSort(vettore, 0, dim-1);
      cout << "Vettore dopo\n";
    printVector(vettore, dim);

}


void MergeSort(int vettore[] , int start, int end ) {
    
    if(start<end){
        int  mid = (end+start)/2 ; 
         MergeSort(vettore, start, mid ) ; 
          MergeSort(vettore, mid+1, end) ; 
            Merge(vettore,start, mid, end) ; 
       
    }
};

void Merge(int vettore[] , int start ,int mid,  int end){
    // create two vector, left and right : 
    int left = mid-start +1 ; 
    int right = end-mid ; 
    cout<< " dimensione left . "<< left ; 
    cout << " dimensione right : "<< right ; 
    int A_left [left] ; 
    int A_right [right ] ; 

    // RIMPO LEFT E RIGHT : quindi uso due vettori ausiliari
    // li riempio solamente e sotto li confronto 
    // per inserirli nel mio vettore originario già 
    // ordinati.
    for(int i =0 ; i<left ; i++){
        A_left[i] = vettore[start + i] ; 

    }
    for ( int j =0 ; j< right ; j++){
        A_right[j] = vettore[mid+1+j] ; 
    }
    cout << " vettore left : "<< " \n" ; 
   // printVector(A_left , left) ; 
    
    cout << " vettore right : "<< " \n" ; 
    //printVector(A_right , right) ; 
    int i =0 , j=0 ,k = start ; 
    while( i < left && j< right){ 
        if(A_left[i]< A_right[j]){
            vettore[k]= A_left[i] ;
            k++ ; 
            i++ ;  
        }else {
            vettore[k] = A_right[j] ; 
            k++ ; 
            j++ ;
        }
    }
    cout << " vettore post while . "<< endl ; 
    
    int dim = sizeof(vettore) / sizeof(vettore[0]);
    printVector(vettore, dim ); 
    


        // Copia degli elementi rimanenti di A_left (se ci sono)
    while (i < left) {
        vettore[k] = A_left[i];
        i++;
        k++;
    }
    cout << " vettore post secondo while :"<< endl ; 
    
    int dim1 = sizeof(vettore) / sizeof(vettore[0]);
    printVector(vettore, dim1 ); 
    
    // Copia degli elementi rimanenti di A_right (se ci sono)
    while (j < right) {
        vettore[k] = A_right[j];
        j++;
        k++;
    }
   cout<< " \n vettore pos terzo while"<<endl ; 
    int dim2 = sizeof(vettore) / sizeof(vettore[0]);
    printVector(vettore, dim2 ); 
    cout << endl ; 
    
    
}

void  printVector(int vector[] , int dim ){

    for( int i =0 ; i<dim ; i++){
        cout << " vettore : "<< vector[i] << "\n" ; 
    }
    cout << " \n "; 
}


/**
 * SE HAI DUBBI INSERISCIMI QUA : https://pythontutor.com/visualize.html#mode=edit
 * 
 def merge_sort(vettore, start, end):
    if start < end:
        mid = (start + end) // 2
        merge_sort(vettore, start, mid)
        merge_sort(vettore, mid + 1, end)
        merge(vettore, start, mid, end)


def merge(vettore, start, mid, end):
    # Creazione dei sotto-vettori per sinistra e destra
    left = mid - start + 1
    right = end - mid

    A_left = [0] * left
    A_right = [0] * right

    # Riempimento di A_left e A_right
    for i in range(left):
        A_left[i] = vettore[start + i]

    for j in range(right):
        A_right[j] = vettore[mid + 1 + j]

    i = j = 0
    k = start

    # Merge dei due sotto-vettori nell'array principale
    while i < left and j < right:
        if A_left[i] < A_right[j]:
            vettore[k] = A_left[i]
            i += 1
        else:
            vettore[k] = A_right[j]
            j += 1
        k += 1

    # Copia degli elementi rimanenti di A_left
    while i < left:
        vettore[k] = A_left[i]
        i += 1
        k += 1

    # Copia degli elementi rimanenti di A_right
    while j < right:
        vettore[k] = A_right[j]
        j += 1
        k += 1


def print_vector(vettore):
    for elemento in vettore:
        print(f"vettore: {elemento}")
    print("\n")


if __name__ == "__main__":
    vettore = [30, 20, 10, 1]
    dim = len(vettore)

    print("Vettore prima di essere ordinato:")
    print_vector(vettore)

    merge_sort(vettore, 0, dim - 1)

    print("Vettore dopo essere stato ordinato:")
    print_vector(vettore)
 */