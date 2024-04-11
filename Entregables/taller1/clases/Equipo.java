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

    public void swap(int i, int j) {
        Jugador tmp = jugadores[i];
        jugadores[i] = jugadores[j];
        jugadores[j] = tmp;
    }
    
    public void formacion() {
        for (int i = 0; i < 9; i++) {
            for (int j = i + 1; j < 10; j++) {
                if (jugadores[i].getAtaque() < jugadores[j].getAtaque()) {
                    swap(i, j);
                } else if (jugadores[i].getAtaque() == jugadores[j].getAtaque()) {
                    if (jugadores[i].getDefensa() > jugadores[j].getDefensa()) {
                        swap(i, j);
                    } else if (jugadores[i].getDefensa() == jugadores[j].getDefensa()) {
                        if (jugadores[i].nombre.compareTo(jugadores[j].nombre) > 0) {
                            swap(i, j);
                        }
                    }
                }
            }
        }
    
        for (int i = 0; i < 4; i++) {
            for (int j = i + 1; j < 5; j++) {
                if (jugadores[i].nombre.compareTo(jugadores[j].nombre) > 0) {
                    swap(i, j);
                }
            }
        }
    
        for (int i = 5; i < 9; i++) {
            for (int j = i + 1; j < 10; j++) {
                if (jugadores[i].nombre.compareTo(jugadores[j].nombre) > 0) {
                    swap(i, j);
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

