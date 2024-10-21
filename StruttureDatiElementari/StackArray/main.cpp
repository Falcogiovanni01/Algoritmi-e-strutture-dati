/* IMPLEMENTIAMO UNO STACK TRAMITE UN VETTORE, 
COSA FA ? 
lo stack possiamo immaginarlo come una pila, 
inserisci elementi "UNO SOPRA L'ALTRO" 
 ed rimuovi l'elemento in "cima"
 es: 
 0 0 0 0 , 
 cosa fai = inserisco A
 A 0 0 0 
 rimuovo 
 0 0 0 0 , 
 inserisco A 
 a 0 0 0 
 b 
 a b 0 0 
 c 
 a b c 0 .
 posso rimuovere solo l'ultimo elemento,quindi segue una politica LIFO last in first out. 
 l'ultimo inserito è il primo ad uscire*/
 using namespace std ; 
 #include<iostream>

 int main(){

    // creamo una classe : 
     class Stack{
        private : 
        int dimensione ; // per comodità 
        int indice ; // sempre epr comodità è l'indice alla posizione x 
        int* vettore ; 

        public : 
        Stack(int dim){
            vettore = new int[dim] ; 
            dimensione = dim ; 
            indice  = -1 ; // ok ha una dimensione ma è ancora vuoto 
        }

        int size(){
            return indice+1 ; 
        }

        void empty(){
            if(indice <0){
                cout<< "\n stack vuoto " ; 
            }else {
                cout << "\n STACK HA "<< indice << " elementi " ;
            }
        }

        void push(int a){ // INSERIMENTO DI UN ELEMENTO
            if(indice == dimensione-1 ){
                cout << "\n ELEMENTO è PIENO " ; 
            }else {
                cout<< " \n elemento "<< a << " aggiunto alla posizione "<< indice+1 ; 
                indice ++ ;
                vettore[indice] = a ;  
            }

        }

        int pop(){ // RIMOZIONE :
        int valoreRimosso = 0 ; 
        if(indice<0){
            cout << "\n E' vuoto, non puoi togliere nulla" ; 
            valoreRimosso = -1 ; 
        }else{
            valoreRimosso = vettore[indice] ;
            indice-- ;  // LA FURBIZIA NEL MODIFICARE L'INDICIE è QUESTA, COSI FACENDO HAI TOLTO TUTTA UNA GESTIONE DA MEZZO
           
        }
             return valoreRimosso ; 

        }

    };

    // Esempio di utilizzo
    Stack stack(4); // Stack con capacità 4 elementi

    stack.push(10);
    stack.push(20);
    stack.push(30);

    stack.empty(); // Mostra il numero di elementi nello stack

    cout << "\n Elemento rimosso: " << stack.pop() << endl; // Rimuove l'elemento in cima (30)
    stack.empty(); // Mostra il numero di elementi rimasti nello stack

    stack.push(15);
    stack.push(25);
    stack.push(35);




 }