public class Equipo{
    
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
    public int getNumero(){
        return this.numero;
    }

    public void formacion() {
        /* Insertion sort : primero ordeno descendentemente el ataque */
        for (int i = 1; i < jugadores.length; i++) {
            Jugador key = jugadores[i];
            int j = i - 1;
            
            while (j >= 0 && jugadores[j].getAtaque() < key.getAtaque()) {
                jugadores[j + 1] = jugadores[j];
                j--;
            }
            jugadores[j + 1] = key;
        }
        
        /* caso que el ataque es IGUAL , ordeno ascendentemente por defensa */
        for (int i = 1; i < jugadores.length; i++) {
            if (jugadores[i].getAtaque() == jugadores[i - 1].getAtaque()) {
                Jugador key = jugadores[i];
                int j = i - 1;
                
                while (j >= 0 && jugadores[j].getAtaque() == key.getAtaque() && jugadores[j].getDefensa() > key.getDefensa()) {
                    Jugador temp = jugadores[j + 1];
                    jugadores[j + 1] = jugadores[j];
                    jugadores[j] = temp;
                    j--;
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

