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
    
    public int subsecCreciente(){
        
        int[] lista = new int[edificios.length];
    
        /* lista de width */
        for (int i = 0; i < edificios.length; i++)
            lista[i] = edificios[i].ancho;
            
            for (int i = 1; i < edificios.length; i++) {
                for (int j = 0; j < i; j++) {
                /* si estoy parado en el edificio i y encuentro uno más bajito j y que se cumpla que :   */
                if (edificios[i].altura > edificios[j].altura && lista[i] < lista[j] + edificios[i].ancho) {
                    lista[i] = lista[j] + edificios[i].ancho;
                }
            }
        }
    
        /* cuál es el max */
        int max = 0;
        for (int i = 0; i < edificios.length; i++) {
            if (lista[i] > max) {
                max = lista[i];
            }
        }
    
        return max;
        
    }
    public int subsecDecreciente(){
        
        int[] lista = new int[edificios.length];
    
        /* lista de width */
        for (int i = 0; i < edificios.length; i++)
            lista[i] = edificios[i].ancho;
            
            for (int i = 1; i < edificios.length; i++) {
                for (int j = 0; j < i; j++) {
                /* si estoy parado en el edificio i y encuentro uno más bajito j   */
                /* comparo lo que suma el que estoy parado    */
                if (edificios[i].altura < edificios[j].altura && lista[i] < lista[j] + edificios[i].ancho) {
                    lista[i] = lista[j] + edificios[i].ancho;
                }
            }
        }
    
        /* cuál es el max */
        int max = 0;
        for (int i = 0; i < edificios.length; i++) {
            if (lista[i] > max) {
                max = lista[i];
            }
        }
    
        return max;
        
    }

    public boolean esCreciente(){
        return subsecCreciente() >= subsecDecreciente();
    }
}   
