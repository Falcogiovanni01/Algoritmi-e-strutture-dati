public class Alberi {
        /*
         * NON è PROPRIO CORRETTO, 
         * PERCHè NON GESTISCO LA GESTIONE DESTRA O SINSITRA, 
         * PERCHè è UNO DI PROVA, NEL MOMENTO IN CUI ENTRERò NEI DETTAGLI 
         * CON QUALCHE STRUTTURA PARTICOLARE MIGLIORERò IL CODICE.
         */

    public static void main(String[] args){

        System.out.println(" HELLO BYNARY SEARCH \n") ; 
      
        BinaryTree bt = new BinaryTree(10);
        bt.addLeft(15);
        bt.addRight(20);
       
        bt.addRight(30);
        bt.addLeft(25);
        bt.addRight(40);
        bt.addLeft(35);
        bt.addRight(45);
        bt.stampaAlbero();
    }
    
}
class Nodo{
    int key  ; 
    Nodo root; 
    Nodo left ;
    Nodo right; 

    Nodo(int k){
        key = k ; 
        root = null ; 
        left = null ; 
        right = null ; 

    }
}


class BinaryTree{
    private Nodo root ; 

    public BinaryTree(int K ) {
        root = new Nodo(K) ; 

    }

    public void addRight(int k) {
        Nodo newEntry = new Nodo(k); 
        System.out.println(" \n AGGIUNGIUTA IN CORSO ..." );
        
        if(root.right == null ) {
            
        root.right = newEntry ; 
        newEntry.root = root ; 
        } else {

            Nodo current = root ;
            while(current.right != null ) {
                // SCORRI A DESTRA.
                current = current.right ; 

            }
            current.right  = newEntry ; 
            newEntry.root = root ; 
        }

        System.out.println("\n AGGIUNTA ELEMENTO X = "+k);
    } 

    public void addLeft(int k) {

        Nodo newEntry = new Nodo(k); 
        System.out.println(" \n AGGIUNGIUTA IN CORSO ..." );
        
        if(root.left == null ) {
            
        root.left = newEntry ; 
        newEntry.root = root ; 
        } else {

            Nodo current = root ;
            while(current.left != null ) {
                // SCORRI A DESTRA.
                current = current.left ; 

            }
            current.left = newEntry ; 
            newEntry.root = root ; 
        }

        System.out.println("\n AGGIUNTA ELEMENTO X = "+k);
    } 


   
  
    // Metodo per stampare l'albero in maniera leggibile
    public void stampaAlbero() {
        stampaNodo(root, 0);
    }

    // Metodo ricorsivo per stampare l'albero con indentazione grafica
    private void stampaNodo(Nodo nodo, int livello) {
        if (nodo == null) return;

        // Stampa il sottoalbero destro
        stampaNodo(nodo.right, livello + 1);

        // Stampa il nodo corrente con indentazione
        System.out.println("    ".repeat(livello) + nodo.key);

        // Stampa il sottoalbero sinistro
        stampaNodo(nodo.left, livello + 1);
    }



}