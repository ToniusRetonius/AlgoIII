/* Aceptado por el VJudge */
import java.util.Scanner;

public class Main {
    
    public static void main(String[] args) {
        /* como a priori la primer línea es la # casos... */
        String primeraLinea = "";

        /* declaro variables útiles */
        int cant_equipos;
        int caso;
        Equipo[] equipos;

        /* el objeto SCANNER nos permite leer data que ingresa desde la consola */
        /* tiene métodos copados para analizar datos de entrada */
        /* el objeto scanner recibe un objeto de flujo ( por dónde recibimos la data, ej teclado == System.in) */

        Scanner scanner = new Scanner(System.in);
            /* primer línea la paso a int */
            /* la variable caso será el nro de equipo */
            primeraLinea = scanner.nextLine();
            cant_equipos = Integer.parseInt(primeraLinea);
            caso = 1;

            /* necesito guardarme los equipos en este arreglo de equipos */
            equipos = new Equipo[cant_equipos];

            /* recorro el array de equipos y me armo los equipos */
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
                        caso++;
                    }
                }                
            }

            for (int i = 0; i < equipos.length; i++) {
                /* ordeno según skills */
                equipos[i].formacion();

                /* defino alfabéticamente quién ataca y quién defiende */
                String[] atack = alfabeticamente(equipos[i].ataque());
                String[] defence = alfabeticamente(equipos[i].defensa());

                /* imprimimos los chaboncitos */
                System.out.println("Case " + equipos[i].numero + ":");
                System.out.println("(" + String.join(", ", atack) + ")");
                System.out.println("(" + String.join(", ", defence) + ")");
            }
        scanner.close();
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

    public static class Jugador{
    
        public String nombre;
        public int ataque;
        public int defensa;
    
        public Jugador(String nombre, int ataque, int defensa){
            this.nombre = nombre;
            this.ataque = ataque;
            this.defensa = defensa;
        }

    }
    
    public static class Equipo{
    
        public Jugador[] jugadores;
        public int numero;
    
        public Equipo(int nro){
            this.jugadores = new Jugador[10];
            this.numero = nro;
        }
    
        public void agregarJugador(Jugador jugador) {
            for (int i = 0; i < jugadores.length; i++) {
                if (jugadores[i] == null) { 
                    jugadores[i] = jugador;
                    return; 
                }
            }
        }

        public void swap(int i, int j) {
            Jugador tmp = jugadores[i];
            jugadores[i] = jugadores[j];
            jugadores[j] = tmp;
        }
        
        public void formacion() {
            for (int i = 0; i < 9; i++) {
                for (int j = i + 1; j < 10; j++) {
                    if (jugadores[i].ataque < jugadores[j].ataque) {
                        swap(i, j);
                    } else if (jugadores[i].ataque == jugadores[j].ataque) {
                        if (jugadores[i].defensa > jugadores[j].defensa) {
                            swap(i, j);
                        } else if (jugadores[i].defensa == jugadores[j].defensa) {
                            if (jugadores[i].nombre.compareTo(jugadores[j].nombre) > 0) {
                                swap(i, j);
                            }
                        }
                    }
                }
            }
    
        } 
    
        public String[] ataque(){
            String[] lista = new String[5];
            for (int i = 0; i < 5; i++) {
                lista[i] = jugadores[i].nombre;
            }
            return lista;
        }
        public String[] defensa(){
            String[] lista = new String[5];
            for (int i = 0; i < 5; i++) {
                lista[i] = jugadores[i + 5].nombre;
            }
            return lista;
        }
    }
}

