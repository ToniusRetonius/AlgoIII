import java.util.Scanner;

public class Main {

    public static class Edificio {
        public int altura;
        public int ancho;
    
        public Edificio(int altura, int ancho){
            this.altura = altura;
            this.ancho = ancho;
        }
    
    }

    public static class SkyLine {
    
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
            
            /* lista de width acumulada vacia */
            int[] lista = new int[edificios.length];
        
            /* lista de width acumulada */
            for (int i = 0; i < edificios.length; i++)
                lista[i] = edificios[i].ancho;
                
                /* si estoy parado en el edificio i y encuentro uno más bajito j y al mismo tiempo :  */
                /* la width acumulada por el edificio en el que estoy parado sea menor a la suma entre la acumulada por el bajito  + el ancho del que estoy parado */
                for (int i = 1; i < edificios.length; i++) {
                    for (int j = 0; j < i; j++) {
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

            for (int i = 0; i < edificios.length; i++)
                lista[i] = edificios[i].ancho;
                
                for (int i = 1; i < edificios.length; i++) {
                    for (int j = 0; j < i; j++) {
                    /* lo mismo que la fn anterior pero busco uno mayor en altura */
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
    
    public static void main(String[] args) {
        /* Inicializo las variables útiles */
        int cantidadCasos;

        /* inicializo el scanner */
        Scanner scanner = new Scanner(System.in);
        
        /* La primera línea del input es la cantidad de casos de test */
        cantidadCasos = Integer.parseInt(scanner.nextLine());
        System.err.println(cantidadCasos);

        /* inicializamos el arreglo de todos los skylines */
        SkyLine[] totales = new SkyLine[cantidadCasos];
        
        for (int i = 0; i < cantidadCasos; i++) {
            /* La primera línea del input del caso, es la cantidad de edificios en el skyline */
            int cantidadEdificios = Integer.parseInt(scanner.nextLine());
            
            /* definimos las variables para capturar los datos */
            int[] alturas = new int[cantidadEdificios];
            int[] anchos = new int[cantidadEdificios];
            int caso = i + 1;
            
            /* instacia de la skyline actual */
            totales[i] =  new SkyLine(cantidadEdificios, caso);
            
            String datos_altura_linea = scanner.nextLine();
            String[] datos_altura = datos_altura_linea.split(" ");
            
            String datos_ancho_linea = scanner.nextLine();
            String[] datos_ancho = datos_ancho_linea.split(" ");
            
            
            /* Iteración sobre la cantidad de edificios que tenemos */
            for (int j = 0; j < cantidadEdificios; j++) {
                alturas[j] = Integer.parseInt(datos_altura[j]);
                anchos[j] = Integer.parseInt(datos_ancho[j]);
                Edificio edif = new Edificio(alturas[j], anchos[j]);
                totales[i].AgregarEdificio(edif);
            }

            
        }
        
        scanner.close();

        /* print */
        for (int j = 0; j < totales.length; j++) {
            String res;

            if (totales[j].esCreciente()) {
                res = "Increasing (" + totales[j].subsecCreciente() + "). " + "Decreasing (" + totales[j].subsecDecreciente() + ")."; 
            } else {
                res = "Decreasing (" + totales[j].subsecDecreciente() + "). " + "Increasing (" + totales[j].subsecCreciente() + ").";
            }
            
            System.err.println("Case " + totales[j].caso + ". " + res );
        }
    }
}

