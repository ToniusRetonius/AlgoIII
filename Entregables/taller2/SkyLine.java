public class SkyLine {
    
    public Edificio[] edificios;
    public int caso;

    public SkyLine(int cantidad, int caso){
        this.edificios = new Edificio[cantidad];
    }

    public void AgregarEdificio(Edificio e){
        for (int i = 0; i < edificios.length; i++) {
            if (edificios[i] == null) { 
                edificios[i] = e;
                return; 
            }
        }
    }
}
