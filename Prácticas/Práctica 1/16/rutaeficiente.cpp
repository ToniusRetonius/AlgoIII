#include <bits/stdc++.h>
using namespace std;


int main(){

    // 20 paradas : 0 Baires - 500 Mardel
    vector<int> rut = {0, 50, 100, 150, 200, 250};
    vector<int> ruta = {0,1,18, 29, 43, 56, 67, 85, 101, 133, 147, 162, 179, 196, 221, 245, 268, 290, 310, 380, 440, 500};
    // para en 0 - 85 - 179 - 268 - 310 - 380 - 440
    // para en 0 - 100 - 200
    // el auto puede hacer C km con el tanque lleno
    int tanque_lleno = 100;
    int c = tanque_lleno;

    // pero ..  arranca vacío por tanto hace la primer parada en Baires y la llegada
    int cant_paradas = 1;

    // la idea es
    int i = 1;
    while (i < ruta.size()-1)
    {
        // el tema es : llego a la siguiente con el combustible que tengo?
        
        // dónde está la siguiente ?
        int siguiente_parada = ruta[i+1];
        
        // dónde estoy ?
        int actual_parada = ruta[i];
        
        // y la anterior que ya la pasé?
        int anterior_parada = ruta[i-1];

        // si llegué hasta acá ==> gasté desde la anterior hasta esta
        c -= (actual_parada - anterior_parada);

        // tengo resto como para tirar la distancia entre la siguiente y la actual ?
        if (c > (siguiente_parada - actual_parada))
        {
            printf("En la parada %d mi nivel de combustible es %d y puedo llegar a la parada %d \n", actual_parada, c, siguiente_parada); 
        }
        // sino, tengo que cargar;
        else
        {
            printf("Estoy cargando nafta en la parada %i\n", actual_parada);
            c = tanque_lleno;
            cant_paradas++;
        }
        i++;
    }

    printf("La cantidad mínima de paradas que puede hacer en su viaje es: %i\n", cant_paradas);
    
    return 0;
}