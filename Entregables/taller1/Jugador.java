package taller1;
public class Jugador{
    
    public String nombre;
    public int ataque;
    public int defensa;

    public Jugador(String nombre, int ataque, int defensa){
        this.nombre = nombre;
        this.ataque = ataque;
        this.defensa = defensa;
    }

    /* quiero poder obtener nombre : para el alfabético */
    public String getNombre (){
        return nombre;
    }

    /* quiero poder obtener ataque : para el sorting    */
    public int getAtaque(){
        return ataque;
    }

    /* quiero poder obtener defensa : para el desempate */
    public int getDefensa(){
        return defensa;
    }
}