package Vito;

import java.util.ArrayList;
import java.util.List;

public class Main {

    public static void main(String[] args) {
        // Input: 3 parenti e le loro strade
        int[] vettore = {2, 4}; // Le strade in cui vivono i parenti
        
        int[] vettore1 = {2, 4, 6}; // Le strade in cui vivono i parenti

        int[] vettore2 = {1, 5, 10}; // Le strade in cui vivono i parenti

        // Chiamata alla funzione principale
        int minimo = functionBasic(vettore);
        System.out.println("La distanza minima è: " + minimo);

        int minimo1 = functionBasic(vettore1);
        System.out.println("La distanza minima è: " + minimo1);

        
        
        int minimo2 = functionBasic(vettore2);
        System.out.println("La distanza minima è: " + minimo2);
    }

    // Funzione principale
    public static int functionBasic(int[] vettore) {
        int dim = vettore.length; // Dimensione del vettore
        List<Integer> vettoreStrade = new ArrayList<>(); // Per memorizzare le distanze

        functionBackTracking(vettore, dim, 0, vettoreStrade);
        return findMin(vettoreStrade); // Restituisce il minimo delle distanze
    }

    // Funzione di backtracking
    public static void functionBackTracking(int[] vettore, int dim, int j, List<Integer> vettoreStrade) {
        // Condizione di uscita: quando abbiamo esaminato tutte le posizioni
        if (j >= dim) {
            return; 
        }

        // Calcola la somma delle distanze dalla casa situata alla posizione corrente
        int somma = 0;
        for (int i = 0; i < dim; i++) {
            int distanza = Math.abs(vettore[j] - vettore[i]); // Calcola la distanza
            somma += distanza; // Somma delle distanze
        }

        // Aggiungi la somma delle distanze al vettore delle strade
        vettoreStrade.add(somma);

        // Prosegue con il prossimo indice
        functionBackTracking(vettore, dim, j + 1, vettoreStrade);
    }

    // Funzione per trovare il minimo in una lista di distanze
    public static int findMin(List<Integer> vettoreStrade) {
        int min = Integer.MAX_VALUE;
        for (int distanza : vettoreStrade) { // Itera attraverso la lista
            if (distanza < min) {
                min = distanza;
            }
        }
        return min;
    }
}
