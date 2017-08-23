package permutaciones;

import java.util.Arrays;

/**
 *
 * @author lpenaf
 */
public class Permutaciones {
    private int numValidas;
    private int numPermutaciones;
    
    public Permutaciones(){
        this.numValidas = 0;
        this.numPermutaciones = 0;
    }
    
    public int getNumValidas() {
        return numValidas;
    }
    
    public void genPermutaciones(int n){
        int[] permutacion = new int[n]; //Por default se inicializan con casillas en cero
        int[] ocupados = new int[n]; //Por default se inicializan con casillas en cero
        this.numValidas = 0;
        this.numPermutaciones = 0;
        genPermutaciones(n, 0, permutacion, ocupados);
    }
    
    private void genPermutaciones(int n, int k, int[] permutacion, int[] ocupados){
        if(k == n){
            this.numPermutaciones++;
            if(valida(n, permutacion)){
                this.numValidas++;
                print(permutacion);
            }
        }
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
    
    private boolean valida(int n, int[] permutacion){
        boolean isValid = true;
        int i, j;
        i = 1;
        
        while(i < n && isValid){
            j = i + 1;
            while(j <= n && isValid){
                isValid = (j - i) != Math.abs(permutacion[i - 1] - permutacion[j - 1]);
                j++;
            }
            i++;
        }
        return isValid;
    }
    
    private void print(int[] permutacion){
        System.out.println("Per: " + this.numPermutaciones + " - " + Arrays.toString(permutacion));
    }

    public static void main(String[] args) {
        Permutaciones per = new Permutaciones();
        long tIni,tFin;
        
        tIni = System.currentTimeMillis();
        per.genPermutaciones(8);
        tFin = System.currentTimeMillis();
        System.out.println(per.getNumValidas());
        System.out.println((tFin - tIni) / 1000.0);
    }   
}