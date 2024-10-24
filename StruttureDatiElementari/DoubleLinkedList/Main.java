package DoubleLinkedList;

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
    private Node head;

    // mi ritorna un nodo
    public Node listSearch(int k) {
        Node x = this.head;
        // ALTERNATIVA
        /**
         * while(x != null && x.head != k){
         * x= x.next ;
         * }
         * return x ;
         * 
         */

        while (x != null) { // Controlla se x non è null
            if (x.elem == k) { // Se l'elemento corrente è uguale a k
                return x; // Restituisce il nodo trovato
            }
            x = x.next; // Passa al nodo successivo
        }
        return null; // Restituisce null se non trovato
    }

    // INSERIMENTO IN TESTA
    public void ListPrepend(int x) {
        Node newEntry = new Node(x);
        if (this.head != null) {
            this.head.prev = newEntry;
            newEntry.next = this.head;
        }
        // ALLA FINE LA TESTA PUNTA AL NUOVO NODO.
        this.head = newEntry;

        System.out.println("\nELEMENTO AGGIUNTO: " + x);
    }

    public void listDelete(int x) {
        // ELIMINO ELEMENTO X,
        Node old = this.listSearch(x); // è il puntatore al nodo.

        if (old != null) { // Controlla se il nodo esiste
            // HO TROVATO L'ELEMENTO, DEVO ELIMINARLO:
            if (old.prev != null) {
                // Collega il nodo precedente al successivo.
                old.prev.next = old.next;
                /**
                 * ES : 1->2->3
                 * old.prev.next = old.next;
                 * 
                 * supponiamo 2 sia old ,
                 * sto dicendo che
                 * old.prev , IL NODO 1.
                 * sto dicendo che 1.next = old.next,
                 * 1->3
                 * TI TROVI ?
                 */
            } else {
                // Se old è la testa, aggiorna la testa
                this.head = old.next;
            }

            if (old.next != null) {
                // Collega il nodo successivo al precedente
                old.next.prev = old.prev;
            }

            // Pulizia dei riferimenti
            old.prev = null;
            old.next = null;
            System.out.println("Elemento " + x + " eliminato.");
        } else {
            System.out.println("Elemento " + x + " non trovato.");
        }
    }

    public void printList() {
        Node current = head;
        while (current != null) {
            System.out.print(current.elem + " ");
            current = current.next;
        }
        System.out.println();
    }
}

public class Main {
    public static void main(String[] args) {
        // Creazione della lista
        LinkedList list = new LinkedList();

        // Inserimento di elementi
        list.ListPrepend(3);
        list.ListPrepend(2);
        list.ListPrepend(1);

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
