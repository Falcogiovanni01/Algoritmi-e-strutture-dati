#include<iostream>
using namespace std;
// PER UNA GESTIONE MIGLIORE CREATI PROPRIO UNA CLASSE NODO, 
//E POI UTILIZZI QUELLA CLASSE PER SPECIFICARE LE ALTRE
class LinkedList {
private:
    int head;
    LinkedList* next;

public:
    LinkedList(int a) {
        head = a;
        next = nullptr;
    }

    // Inserisci all'inizio della lista (comportamento LIFO)
    LinkedList* add(int a) {
        LinkedList* nuovo = new LinkedList(a);
        nuovo->next = this;  // Il nuovo nodo punta alla vecchia testa (LIFO)
        cout << "\n AGGIUNTO ELEMENTO: " << nuovo->head << " ";
        return nuovo;  // Il nuovo nodo diventa la nuova testa
    }

    // Rimuovi l'elemento in cima
    LinkedList* remove() {
        if (this == nullptr) {
            cout << "\nNon c'è nulla da rimuovere!";
            return nullptr;
        }
        LinkedList* old = this->next;  // Il prossimo nodo diventa la nuova testa
        cout << "\n RIMOSSO ELEMENTO: " << this->head;
        delete this;  // Elimina l'elemento corrente
        return old;  // Restituisce il nuovo nodo di testa
    }

    // Mostra tutti gli elementi
    void printElements() {
        LinkedList* temp = this;
        cout << "\n ELEMENTI STACK: ";
        while (temp != nullptr) {
            cout << " <- " << temp->head ;
            temp = temp->next;
        }
        cout << "\n";
    }
};

class Stack {
private:
    LinkedList* list;
    int indice;  // Per contare il numero di elementi

public:
    Stack() {
        list = nullptr;  // Inizializza la lista come vuota
        indice = 0;
    }

    int size() {
        return indice;
    }

    void empty() {
        if (indice == 0) {
            cout << "\n Stack vuoto ";
        } else {
            cout << "\n STACK HA " << this->size() << " elementi ";
        }
    }

    void push(int a) {  // Inserimento di un elemento
       
        list = list ? list->add(a) : new LinkedList(a);  // Aggiungi elemento
        indice++;
    }

    int pop() {  // Rimozione dell'elemento in cima
        if (list == nullptr) {
            cout << "\nNon c'è nulla da rimuovere!";
            return -1;
        }
        list = list->remove();
        indice--;
        return 0;
    }

    void printStack() {
        if (list == nullptr) {
            cout << "\n Stack vuoto ";
        } else {
            list->printElements();
        }
    }
};

int main() {
    Stack stack;  // Inizializza lo stack

    stack.push(10);
    stack.push(20);
    stack.push(30);

    stack.empty();  // Mostra il numero di elementi nello stack
    stack.printStack();  // Stampa gli elementi nello stack

    cout << "\n Elemento rimosso: " << stack.pop() << endl;
    stack.empty();
    stack.printStack();

    stack.push(15);
    stack.push(25);
    stack.push(35);

    stack.printStack();

    stack.pop(); 
    cout<< " \n ho rimosso 35? \n"<< endl ; 
    stack.printStack();
}
