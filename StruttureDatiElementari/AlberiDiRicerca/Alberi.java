package AlberiDiRicerca;

/**
 * 
 * Un albero binario di ricerca soddisfa la seguente proprietà:
 * Sia x un nodo dell'albero.
 * Se y è nel sottoalbero di sinistra di x, allora key[y] ≤ key[x].
 * Se y è nel sottoalbero di destra di x, allora key[y] ≥ key[x].
 * 
 */
public class Alberi {

    public static void main(String[] args) {
        BinarySearchTree bst = new BinarySearchTree();
        bst.add(20);
        bst.add(10);
        bst.add(15);
        bst.add(25);
        bst.add(30);
        bst.add(5);

        System.out.println("Stampa dell'albero binario di ricerca:");
        bst.stampaAlbero();

        System.out.println("Stampa dell'albero binario di ricerca secondi il libro:");
        bst.inorderWalk();

        // bst.SearchElement(5);

        // bst.SearchElement(25);

        // bst.SearchElement(500);
        bst.iterativeBinarySearchTree(5) ;
        bst.iterativeBinarySearchTree(25) ;
        bst.iterativeBinarySearchTree(500) ;
    }
}

class Nodo {
    Integer key;
    Nodo parent;
    Nodo left;
    Nodo right;

    Nodo(int k) {
        key = k;
        parent = null;
        left = null;
        right = null;
    }
}

class BinarySearchTree {
    private Nodo root;

    // Costruttore di un albero binario di ricerca vuoto
    public BinarySearchTree() {
        root = null;
    }

    // Metodo per aggiungere un nodo all'albero mantenendo le proprietà di un albero
    // binario di ricerca
    public void add(int k) {
        Nodo newNode = new Nodo(k);

        if (root == null) {
            root = newNode;
        } else {
            Nodo current = root;
            Nodo parent = null;

            while (current != null) {
                parent = current;

                // Se il valore è minore, si va a sinistra
                if (k < current.key) {
                    current = current.left;
                } else {
                    // Altrimenti, si va a destra
                    current = current.right;
                }
            }

            // Associa il nuovo nodo al suo nodo padre
            if (k < parent.key) {
                parent.left = newNode;
            } else {
                parent.right = newNode;
            }

            newNode.parent = parent;
        }
    }

    // Metodo per stampare l'albero in maniera leggibile
    public void stampaAlbero() {
        stampaNodo(root, 0);
    }

    // Metodo ricorsivo per stampare l'albero con indentazione grafica
    private void stampaNodo(Nodo nodo, int livello) {
        if (nodo == null)
            return;

        // Stampa il sottoalbero destro con un livello maggiore
        stampaNodo(nodo.right, livello + 1);

        // Stampa il nodo corrente con indentazione
        System.out.println("    ".repeat(livello) + nodo.key);

        // Stampa il sottoalbero sinistro con un livello maggiore
        stampaNodo(nodo.left, livello + 1);
    }

    public void inorderWalk() {
        InorderTreeWalk(root);
    }

    public void InorderTreeWalk(Nodo bst) {

        if (bst != null) {
            InorderTreeWalk(bst.left);
            System.out.println(bst.key);
            InorderTreeWalk(bst.right);
        }
    }

    public Nodo RecursionSearchElement(Nodo n, int k) {

        if (n == null) {
            System.out.println("ERRORE ELEMENTO NON PRESENTE");
            return null;
        }
        if (n.key == k) {
            System.out.println(" ELEMENTO PRESENTE = " + n.key);
            return n;
        }

        if (k < n.key) {
            // VADO A SINSITRA :
            return RecursionSearchElement(n.left, k);
        } else {
            // vado a destra :
            return RecursionSearchElement(n.right, k);
        }

    }

    public void SearchElement(int k) {

        Nodo current = RecursionSearchElement(root, k);
        if (current != null) {
            System.out.println("\nINFORMAZIONI:");
            System.out.println("ELEMENTO TROVATO = " + current.key);
            System.out.println("padre = " + (current.parent != null ? current.parent.key : "null"));
            System.out.println("ELEMENTO figlio sinistro = " + (current.left != null ? current.left.key : "null"));
            System.out.println("ELEMENTO figlio destro = " + (current.right != null ? current.right.key : "null"));
        } else {
            System.out.println("ELEMENTO NON TROVATO");
        }

    }

    public Nodo iterativeBinarySearchTree( int k ){
        Nodo current = root ; 
        while (current != null && current.key != k) {
            if(k < current.key){
                current = current.left ; 
            } else {
                current = current.right ; 
            }
            
        }

        if (current != null) {

            System.out.println("ELEMENTO TROVATO: " + current.key);
        } else {

            System.out.println("ELEMENTO NON TROVATO");
       
        }



        return current ; 

    }

}
