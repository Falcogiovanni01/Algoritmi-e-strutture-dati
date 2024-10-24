package Sentinella;

class Node {
    Node prev;
    int elem;
    Node next;

    public Node(int e) {
        elem = e;
        prev = null;
        next = null;
    }
}

class LinkedList {
    private Node sentinella; // Rappresenta la sentinella
    private Node head; // Rappresenta la testa

    public LinkedList() {
        sentinella = new Node(0); // Creiamo la sentinella con un valore fittizio
        head = null; // Inizialmente la lista è vuota
        sentinella.next = sentinella; // La sentinella punta a se stessa
        sentinella.prev = sentinella; // La sentinella punta a se stessa
    }

    // Inserimento in testa
    public void listPrepend(int x) {
        Node newEntry = new Node(x);
        
        // Se la lista è vuota, il nuovo nodo diventa sia head che sentinella.prev
        if (head == null) {
            head = newEntry; // La testa ora punta al nuovo nodo
            newEntry.next = sentinella; // Il nuovo nodo punta alla sentinella
            newEntry.prev = sentinella; // La sentinella punta al nuovo nodo
            sentinella.next = head; // La sentinella punta alla testa
            sentinella.prev = head; // La sentinella punta alla coda (che è la stessa della testa)
        } else {
            newEntry.next = head; // Il nuovo nodo punta alla testa attuale
            newEntry.prev = sentinella; // Il nuovo nodo punta alla sentinella
            head.prev = newEntry; // La testa attuale punta al nuovo nodo
            head = newEntry; // Aggiorna la testa
            sentinella.prev = head; // La sentinella punta alla nuova testa
        }

        System.out.println("\nELEMENTO AGGIUNTO: " + x);
    }

    // Ricerca di un nodo
    public Node listSearch(int k) {
        Node x = head; // Inizia dalla testa
        while (x != sentinella) { // Continua finché non arriviamo alla sentinella
            if (x.elem == k) {
                return x; // Restituisce il nodo trovato
            }
            x = x.next; // Passa al nodo successivo
        }
        return null; // Restituisce null se non trovato
    }

    // Eliminazione di un nodo
    public void listDelete(int x) {
        Node old = this.listSearch(x);
        if (old != null) {
            // Collega il nodo precedente al nodo successivo
            old.prev.next = old.next;
            old.next.prev = old.prev; // Collega il nodo successivo al nodo precedente
            
            // Se stiamo eliminando la testa, aggiorniamo head
            if (old == head) {
                head = old.next; // Aggiorna la testa
            }
            
            // Se stiamo eliminando l'unico nodo, resettiamo head
            if (head == sentinella) {
                head = null; // Lista vuota
                sentinella.next = sentinella; // La sentinella punta a se stessa
                sentinella.prev = sentinella; // La sentinella punta a se stessa
            } else {
                sentinella.prev = head; // Aggiorniamo la sentinella.prev se necessario
            }
        }
    }

    // Stampa della lista
    public void printList() {
        Node current = head; // Inizia dalla testa
        if (current == null) {
            System.out.println("La lista è vuota.");
            return;
        }
        while (current != sentinella) { // Continua finché non arriviamo alla sentinella
            System.out.print(current.elem + " ");
            current = current.next; // Passa al nodo successivo
        }
        System.out.println();
    }
}

public class Sentinella {
    public static void main(String[] args) {
        // Creazione della lista
        LinkedList list = new LinkedList();

        // Inserimento di elementi
        list.listPrepend(3);
        
        list.listPrepend(2);
        list.listPrepend(1);

        // Stampa della lista
        System.out.println("Lista dopo inserimento: ");
        list.printList();

        // Eliminazione di un elemento
        list.listDelete(2); // Eliminare il nodo con valore 2
        System.out.println("Lista dopo eliminazione di 2: ");
        list.printList();

        // Eliminazione della testa
        list.listDelete(1); // Eliminare il nodo con valore 1
        System.out.println("Lista dopo eliminazione di 1: ");
        list.printList();

        // Eliminazione dell'ultimo elemento
        list.listDelete(3); // Eliminare il nodo con valore 3
        System.out.println("Lista dopo eliminazione di 3: ");
        list.printList();
    }
}
