import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
/**
 * gergovia
 */
public class Main {

    public static class Casas {

        public int habitantes;
        public int[] demanda_calle;
        public int caso;

        Casas(int cant_hab, int[] num, int c){
            this.habitantes = cant_hab;
            this.demanda_calle = num;
            this.caso = c;
        }

        int func(){
            int suma = 0;
            int actual_i = demanda_calle[0];
            int actual_j = demanda_calle[0];

            int i = 0;
            int j = 0;
            
            while (i < demanda_calle.length ) 
            {
                /* avanzo sii actual ya es 0 */
                if (actual_i <= 0) 
                {
                    demanda_calle[i] = actual_i;
                    i++;
                    if(i < demanda_calle.length)
                    {
                        actual_i = demanda_calle[i];
                    } 
                    
                }
                /* si es mayo a cero actual_i y estamos en rango*/
                else if (actual_i > 0) 
                {
                    /* recorro el arreglo en busqueda de algun negativo que lo haga pelota */
                    while (j < demanda_calle.length  && actual_i > 0) 
                    {
                        if (actual_j >= 0) 
                        {
                            demanda_calle[j] = actual_j;  
                            j++;
                            if(j < demanda_calle.length)
                            {
                                actual_j = demanda_calle[j];
                            }  
                        }
                        else
                        {
                            suma += Math.abs(j-i);
                            actual_i--;
                            actual_j++;
                            demanda_calle[i] = actual_i;
                            demanda_calle[j] = actual_j;
                        }
                        
                    }
                }
            }
            return suma;
        }  
    }

    public static void main(String[] args) {
        /* capturo el input */
        Scanner scanner = new Scanner(System.in);
        int habitantes = Integer.parseInt(scanner.nextLine());
        
        /* como a priori no se la # de casos  necesito ir agregando dinámicamente con */
        List<Casas> casos = new ArrayList<>();
        
        int caso = 0;
        
        while (habitantes > 0) {
            String demanda_a = scanner.nextLine();
            String[] demanda_b = demanda_a.split(" ");
            int[] demanda = new int[demanda_b.length];

            for (int i = 0; i < habitantes; i++) {
                demanda[i] = Integer.parseInt(demanda_b[i]);
            }

            /* capturada la data correctamente */
            Casas actual = new Casas(habitantes, demanda, caso);

            /* agrego a la lista dinámica */
            casos.add(actual);

            /* actualizo habitantes a la sig linea */
            habitantes = Integer.parseInt(scanner.nextLine());
            caso++;
        }
        scanner.close();

        for (int i = 0; i < casos.size(); i++) {
            Casas actual = casos.get(i);
            System.err.println(actual.func());
        }
    }
}