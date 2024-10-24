#include <iostream>
using namespace std;

class Node {
public:
    int data;        // Dato contenuto nel nodo
    Node* next;     // Puntatore al nodo successivo

    Node(int value) : data(value), next(nullptr) {}
};

class CircularLinkedList {
private:
    Node* head;     // Puntatore alla testa della lista
    Node* tail;     // Puntatore alla coda della lista

public:
    CircularLinkedList() : head(nullptr), tail(nullptr) {}

    // Inserisce un nuovo nodo alla fine della lista
    void insert(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
            tail->next = head; // Collega tail a head per la circularità
        } else {
            tail->next = newNode; // Collega l'attuale tail al nuovo nodo
            tail = newNode;       // Aggiorna tail al nuovo nodo
            tail->next = head;    // Collega tail al head per la circularità
        }
    }

    // Rimuove un nodo dalla testa della lista
    int remove() {
        if (head == nullptr) {
            cout << "La lista è vuota, nulla da rimuovere." << endl;
            return -1; // Ritorna un valore segnaposto
        }

        Node* temp = head;
        int valoreRimosso = head->data;

        if (head == tail) {
            // Caso unico: solo un nodo nella lista
            delete head;
            head = nullptr;
            tail = nullptr;
        } else {
            head = head->next;     // Sposta head al nodo successivo
            tail->next = head;     // Collega tail al nuovo head
            delete temp;           // Elimina il nodo
        }

        return valoreRimosso;
    }

    // Mostra gli elementi della lista
    void display() {
        if (head == nullptr) {
            cout << "La lista è vuota." << endl;
            return;
        }

        Node* current = head;
        do {
            cout << current->data << " -> ";
            current = current->next;
        } while (current != head);
        cout << "(ritorna a " << head->data << ")" << endl;
    }

    // Distruttore per liberare la memoria
    ~CircularLinkedList() {
        if (head == nullptr) return; // La lista è vuota

        Node* current = head;
        Node* nextNode;

        // Liberiamo tutti i nodi
        do {
            nextNode = current->next; // Salva il puntatore al nodo successivo
            delete current;           // Elimina il nodo corrente
            current = nextNode;       // Passa al nodo successivo
        } while (current != head);
    }
};

class Queue {
private:
    CircularLinkedList cll; // Utilizziamo la lista circolare per implementare la coda

public:
    void enqueue(int value) { // Inserisce un elemento nella coda
        cll.insert(value);
        cout << "Elemento inserito nella coda: " << value << endl;
    }

    int dequeue() { // Rimuove un elemento dalla testa della coda
        int value = cll.remove();
        if (value != -1) {
            cout << "Elemento rimosso dalla coda: " << value << endl;
        }
        return value;
    }

    void display() { // Mostra gli elementi della coda
        cll.display();
    }
};

int main() {
    Queue queue;

    // Esempi di utilizzo della coda
    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);

    queue.display(); // Mostra gli elementi nella coda

    queue.dequeue(); // Rimuove il primo elemento (10)
    queue.display(); // Mostra gli elementi dopo la rimozione

    queue.enqueue(40);
    queue.enqueue(50);
    queue.display(); // Mostra gli elementi dopo l'inserimento di nuovi elementi

    queue.dequeue(); // Rimuove il primo elemento (20)
    queue.display(); // Mostra gli elementi dopo la rimozione

    return 0;
}
