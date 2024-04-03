package taller1;
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

    public void formacion(){
        if (jugadores.length != 10) {
            return;
        }
        
        for (int i = 1; i < jugadores.length; i++) {
            Jugador key = jugadores[i];
            int j = i - 1;
            /* ordeno ataque */
            while (j >= 0 && jugadores[j].getAtaque() < key.getAtaque()) {
                jugadores[j + 1] = jugadores[j];
                j = j - 1;
            }
            while (j >= 0 && jugadores[j].getAtaque() == key.getAtaque()) {
                if (jugadores[j].getDefensa() < key.getDefensa()) {
                    jugadores[j + 1] = jugadores[j];
                    j = j - 1;
                } else {break;}
            }

            jugadores[j + 1] = key;
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

