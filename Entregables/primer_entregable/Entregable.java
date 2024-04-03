package primer_entregable;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

import taller1.Equipo;
import taller1.Jugador;

public class Entregable {
        public static void main(String[] lineas){
        /* Especifica la ruta del archivo */
        String rutaArchivo = "test.txt";
        
        /* como a priori la primer línea es la # casos... */
        String primeraLinea = "";
        int cant_equipos;
        int caso;
        Equipo[] equipos;

        try {
            /* el objeto FileReader en Java se usa para leer caracteres de un archivo de texto  */
            /* este objeto es el que crea un flujo de lectura */
            /* el tema es que este objeto sólo realiza la lectura y no la guarda temporalmente en ningún lado */
            FileReader fileReader = new FileReader(rutaArchivo);

            /* el objeto BufferedReader es el encargado de hacer una lectura de un flujo de lectura (puede hacerlo por líneas enteras) */
            /* es capaz de guardar esa información, pero necesita de un objeto que obtenga el flujo de lectura  */
            BufferedReader bufferedReader = new BufferedReader(fileReader);

            /* primer línea la paso a int */
            /* la variable caso será el nro de equipo */
            primeraLinea = bufferedReader.readLine();
            cant_equipos = Integer.parseInt(primeraLinea);
            caso = Integer.parseInt(primeraLinea);

            /* necesito guardarme los equipos en este arreglo de equipos */
            equipos = new Equipo[cant_equipos];

            /* recorro el .txt y me armo los equipos */
            for (int i = 0; i < cant_equipos; i++) {

                /* instancia de equipo (recibe su nro = caso) */
                equipos[i] = new Equipo(caso); 
                
                for (int j = 0; j < 10; j++) {
                    /* con .split( condición de split) separamos el nombre de las skills */
                    String[] datosJugador = bufferedReader.readLine().split(" "); 
                    
                    /* datos a capturar */
                    String nombre = datosJugador[0];
                    int ataque = Integer.parseInt(datosJugador[1]);
                    int defensa = Integer.parseInt(datosJugador[2]);
                    
                    /* instancia del jugador */
                    Jugador jugador = new Jugador(nombre, ataque, defensa);

                    /* una vez creado el jugador lo agrego al equipo */
                    equipos[i].agregarJugador(jugador); 

                    /* si ya está lleno el equipo, cambia de caso == nro */
                    if (j == 9) {
                        caso++;
                    }
                }
                equipos[i].imprimirJugadores();
            }


            /* se usa .close() para asegurarse que sólo cargamos el paquete de datos del buffer que nos interesaba */
            bufferedReader.close();
        
        } catch (IOException e) {
            // Maneja la excepción si ocurre un error de lectura
            System.out.println("Ocurrió un error al leer el archivo: " + e.getMessage());
            e.printStackTrace();
        }
    }
}
