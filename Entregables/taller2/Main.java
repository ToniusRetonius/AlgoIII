import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        /* Inicializo las variables útiles */
        int cantidadCasos;

        /* inicializo el scanner */
        Scanner scanner = new Scanner(System.in);
        
        /* La primera línea del input es la cantidad de casos de test */
        cantidadCasos = Integer.parseInt(scanner.nextLine());
        System.err.println(cantidadCasos);

        /* inicializamos el arreglo de todos los skylines */
        SkyLine[] totales = new SkyLine[cantidadCasos];
        
        for (int i = 0; i < cantidadCasos; i++) {
            /* La primera línea del input del caso, es la cantidad de edificios en el skyline */
            int cantidadEdificios = Integer.parseInt(scanner.nextLine());
            
            /* definimos las variables para capturar los datos */
            int[] alturas = new int[cantidadEdificios];
            int[] anchos = new int[cantidadEdificios];
            int caso = i + 1;
            
            /* instacia de la skyline actual */
            totales[i] =  new SkyLine(cantidadEdificios, caso);
            
            String datos_altura_linea = scanner.nextLine();
            String[] datos_altura = datos_altura_linea.split(" ");
            
            String datos_ancho_linea = scanner.nextLine();
            String[] datos_ancho = datos_ancho_linea.split(" ");
            
            
            // Iteración sobre la cantidad de edificios que tenemos
            for (int j = 0; j < cantidadEdificios; j++) {
                alturas[j] = Integer.parseInt(datos_altura[j]);
                anchos[j] = Integer.parseInt(datos_ancho[j]);
                Edificio edif = new Edificio(alturas[j], anchos[j]);
                totales[i].AgregarEdificio(edif);
            }

        }
        /* chequeamos que se capture bien la data >>>  */
        /*  for (int i = 0; i < totales.length; i++) {
            System.err.println("longitudes skylines " + totales[i].edificios.length);
            for (int j = 0; j < totales[i].edificios.length; j++) {
                System.err.println("altura edificio en la pos " + j + " "+ totales[i].edificios[j].getAltura());
                System.err.println("ancho edificio en la pos " + j + " "+ totales[i].edificios[j].getAncho());
            }
        }
        
        System.err.println("Cantidad de casos " + cantidadCasos); 
        */
        scanner.close();
    }
}