public class SkyLine {
    
    public Edificio[] edificios;
    public int caso;

    public SkyLine(int cantidad, int caso){
        this.edificios = new Edificio[cantidad];
        this.caso = caso;
        
    }

    public void AgregarEdificio(Edificio e){
        for (int i = 0; i < edificios.length; i++) {
            if (edificios[i] == null) { 
                edificios[i] = e;
                return; 
            }
        }
    }
    /* necesito un metodo capaz de hallar un subconjunto creciente en altura que maximice el ancho de los edificios */
    /* es decir que para subsecuencia de edificios aquellos que se encuentren creciendo en altura, sumen el ancho */
}   
