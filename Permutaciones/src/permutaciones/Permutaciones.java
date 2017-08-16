package permutaciones;

import java.util.Arrays;

/**
 *
 * @author lpenaf
 */
public class Permutaciones {

    public static void genPermutaciones(int n){
        int[] permutacion = new int[n]; //Por default se inicializan con casillas en cero
        int[] ocupados = new int[n];
        genPermutaciones(n, 0, permutacion, ocupados);
    }
    
    private static void genPermutaciones(int n, int k, int[] permutacion, int[] ocupados){
        if(k == n)
            System.out.println(Arrays.toString(permutacion));
        else
            for (int i = 0; i < n; i++) {
                if(ocupados[i] == 0) {
                    permutacion[k] = i + 1;
                    ocupados[i] = 1;
                    genPermutaciones(n, k + 1, permutacion, ocupados);
                    ocupados[i] = 0;
                }
            }
    }

    public static void main(String[] args) {
        Permutaciones.genPermutaciones(8);
    }   
}