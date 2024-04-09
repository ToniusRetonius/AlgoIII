import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        /* Inicializo las variables útiles */
        int cantidadCasos;

        /* inicializo el scanner */
        Scanner scanner = new Scanner(System.in);
        
        /* La primera línea del input es la cantidad de casos de test */
        cantidadCasos = scanner.nextInt();

        /* Consumir la nueva línea pendiente */
        scanner.nextLine();

        /* tenemos todos los skylines */
        SkyLine[] totales = new SkyLine[cantidadCasos];

        // Iteraciones sobre la cantidad de casos que tenemos (primera linea que nos pasan)

        for (int i = 0; i < cantidadCasos; i++) {
            /* La primera línea del input del caso es la cantidad de edificios en el skyline */
            int cantidadEdificios = scanner.nextInt();

            scanner.nextLine();
            
            /* definimos las variables para capturar los datos */
            int[] alturas = new int[cantidadEdificios];
            int[] anchos = new int[cantidadEdificios];
            int caso = i + 1;
            
            /* instacia de la skyline actual */
            totales[i] =  new SkyLine(cantidadEdificios, caso);
            
            String datos_altura_linea = scanner.nextLine();
            System.out.println(datos_altura_linea);
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

        /* para probar las guardas */

        /*  for (int i = 0; i < totales[0].edificios.length; i++) {
            System.out.print(totales[0].edificios[i].getAltura() + " ");
            System.out.print(totales[0].edificios[i].getAncho());
            System.out.print("\n");
            }  
        */
    

        scanner.close();
    }
}