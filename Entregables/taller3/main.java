import java.util.Scanner;
public class main {

    public static class dataSet {
        public int caso;
        public int arboles;
        public int altura;
        public int costo_salto;
        public int[][] bellotas;
        public int max; 

        dataSet(int caso, int t, int h, int f, int[][] bellotas){
            this.caso = caso;
            this.arboles = t;
            this.altura = h;
            this.costo_salto = f;
            /* matriz de arboles x altura  que cont # bellota en el arbol i en la altura j*/
            this.bellotas = bellotas;
            this.max = 0;
        }

        /* funcion que maximiza las bellotas recolectadas por la ardillita */
        int ardillitaloca(int morfi_acumulado, int arbol, int altura){
            int max = 0;
            /* caso base */
            if (altura == 0){
                return (morfi_acumulado + this.bellotas[arbol][altura]);
            }
            
            if (altura < this.costo_salto) {
                /* el arbol es el mismo porq no puede saltar a otro */
                /* si hay bellota, sumo las que haya */
                /* si no hay porque es 0 eso en la matriz, no hay drama */
                return ardillitaloca(morfi_acumulado + this.bellotas[arbol][altura], arbol, altura - 1);
            }
            
            else{
                /* queremos que se haga recursion sobre la altura - 1 */
                /* si hay bellotas, las come, sino 0 */
                int morfi_insitu = ardillitaloca(morfi_acumulado + this.bellotas[arbol][altura], arbol, altura - 1);
                max = Math.max(max, morfi_insitu);

                /* queremos que se haga recursion sobre la altura - costo_salto */
                /* este es el caso en el que la ardilla se mueve a otro arbol (salta)*/
                /* para eso usamos max, para verificar el valor maximo de morfi */
                for (int i = 0; i < arboles; i++) {
                    if (i != arbol) {
                        int morfi = ardillitaloca(morfi_acumulado + this.bellotas[arbol][altura], i, altura - this.costo_salto);
                        max = Math.max(max, morfi);
                    }
                }
            }
            this.max = max;    
            return max;
        }

        void max(){
            int max = 0;
            int res = 0;
            for (int i = 0; i < this.arboles; i++) {
                max = this.ardillitaloca(0, i, this.altura - 1);
                res = Math.max(max, res);
            }
            this.max = res;
        }
    }


    public static void main(String[] args) {
        /* Inicializo las variables útiles */
        int cantidadCasos;
        /* inicializo el scanner */
        Scanner scanner = new Scanner(System.in);
        
        /* La primera línea del input es la cantidad de casos */
        cantidadCasos = Integer.parseInt(scanner.nextLine());
        System.err.println(cantidadCasos);

        /* para esa cantidad tengo que inicializar un array de dataSet */
        int[] resultados = new int[cantidadCasos];

        /* cargo la info */

        for (int i = 0; i < resultados.length; i++) {
            /* capturamos t, h, f */
            /* 3 10 2 */
            String datos_t_h_f = scanner.nextLine();
            String[] thf = datos_t_h_f.split(" ");

            int t = Integer.parseInt(thf[0]);
            int h = Integer.parseInt(thf[1]);
            int f = Integer.parseInt(thf[2]);

            
            /* capturo las bellotas */
            int[][] bellotas = new int[t][h];
            
            /* t nos dice la cant de arboles, por ello iteramos para construir la matriz de bellotas */
            for (int j = 0; j < t; j++) {
                /* capturo la linea del arbol */
                /* 3 1 4 10 */
                String datos_arbol = scanner.nextLine();
                String[] arbol = datos_arbol.split(" ");
                
                /* armo la matriz */
                for (int k = 1; k < arbol.length; k++) {
                    /* puedo decidir guardarme cant total de bellotas en el arbol o no con el k = 1 */
                    int num = Integer.parseInt(arbol[k]);
                    /* a mi me interesa saber # de bellotas en la posicion i (= altura ) del arbol j */
                    bellotas[j][num - 1] = bellotas[j][num - 1] + 1;
                }

            }
            /* inicializo el dataset */
            dataSet caso = new dataSet(i, t, h, f, bellotas);
            caso.max();
            resultados[i] = caso.max;
        }

        /* el cero gede del final */
        String cero = scanner.nextLine();
        scanner.close();   

        for (int i = 0; i < cantidadCasos; i++) {
            System.err.println(resultados[i]);
        }
    }
}