import java.io.BufferedReader;
import java.io.DataInputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;

public class Atacantes {
    
    public static void main(String[] lineas){
        
        /* como a priori la primer línea es la # casos... */
        String primeraLinea = "";
        int cant_equipos;
        int caso;
        Equipo[] equipos;
        
        try {
            /* Especifica la ruta del archivo */
            File file = new File("C:\\Users\\Toto\\Desktop\\Cs Computación\\Algoritmos III\\Entregables\\taller1-testFile\\test.txt");
            
            /* cosas sacadas de stackOverflow */
            FileInputStream ft = new FileInputStream(file);
            DataInputStream in = new DataInputStream(ft);
            
            /* el objeto BufferedReader es el encargado de hacer una lectura de un flujo de lectura (puede hacerlo por líneas enteras) */
            /* es capaz de guardar esa información, pero necesita de un objeto que obtenga el flujo de lectura  */
            BufferedReader br = new BufferedReader(new InputStreamReader(in));

            /* primer línea la paso a int */
            /* la variable caso será el nro de equipo */
            primeraLinea = br.readLine();
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
                    String[] datosJugador = br.readLine().split(" "); 
                    
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
                        equipos[i].formacion();
                        String[] atack = alfabeticamente(equipos[i].ataque());
                        String[] defence = alfabeticamente(equipos[i].defensa());

                        /* imprimimos los chaboncitos */
                        System.out.println("caso nro: " + caso );
                        System.out.print("(");
                        for (int k = 0; k < atack.length; k++) {
                            System.out.print(atack[k]);
                            if (k != atack.length - 1) {
                                System.out.print(",");
                            }
                        }
                        System.out.print(")\n");
                        System.out.print("(");
                        for (int m = 0; m < defence.length; m++) {
                            System.out.print(defence[m]);
                            if (m != defence.length - 1) {
                                System.out.print(",");
                            }
                        }
                        System.out.print(") \n");
                        caso--;
                    }
                }
                
            }


            /* se usa .close() para asegurarse que sólo cargamos el paquete de datos del buffer que nos interesaba */
            br.close();
        } catch (IOException e){
            System.err.println("Error!" + e.getMessage());
        }
    }

    /* sorting de nombres */
    public static String[] alfabeticamente(String[] lista){
        String temp;
        for (int i = 0; i < lista.length; i++) {
            for (int j = i + 1; j < lista.length; j++) {   
                /* usamos compareTo() */
                if (lista[i].compareTo(lista[j]) > 0) {
                    temp = lista[i];
                    lista[i] = lista[j];
                    lista[j] = temp;
                }
            }
        }
        return lista;
    }

}

