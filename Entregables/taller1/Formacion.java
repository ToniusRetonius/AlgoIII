import java.util.Scanner;

public class Formacion {
    public static void main(String[] args) {
        /* como a priori la primer línea es la # casos... */
        String primeraLinea = "";
        int cant_equipos;
        int caso;
        Equipo[] equipos;

        try (Scanner scanner = new Scanner(System.in)) {
            /* primer línea la paso a int */
            /* la variable caso será el nro de equipo */
            primeraLinea = scanner.nextLine();
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
                    String[] datosJugador = scanner.nextLine().split(" "); 
                    
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
        } catch (NumberFormatException e) {
            // TODO Auto-generated catch block
            e.printStackTrace();
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

