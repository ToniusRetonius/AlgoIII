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
    public void imprimirJugadores() {
        System.out.println("Equipo " + this.numero + ":");
        for (Jugador jugador : jugadores) {
            if (jugador != null) {
                System.out.println(jugador.getNombre() + " - Ataque: " + jugador.getAtaque() + ", Defensa: " + jugador.getDefensa());
            }
        }
        System.out.println("-----------------------------------");
    }
    
}

