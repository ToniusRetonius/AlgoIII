#include <bits/stdc++.h>
using namespace std;





int main(){

    vector<int> conjunto = {7, 14, 3, 18, 11, 5, 16, 9};
    vector<int> conjunto2 = {7, 14, 3, 18, 11, 5, 16, 9};

    // ordenamos de menor a mayor
    sort(conjunto.begin(), conjunto.end());

    int suma_ordenada = conjunto[0];
    int costo_ordenada = 0;
    for (int i = 1; i < conjunto.size(); i++)
    {
        // vemos cuánto cuesta 
        suma_ordenada += conjunto[i];
        costo_ordenada += suma_ordenada;
    }
    
    // probemos la diferencia entre ordenar, y no ordenar

    int suma_desordenada = conjunto2[0];
    int costo_desordenada = 0;
    for (int i = 1; i < conjunto.size(); i++)
    {
        // vemos cuánto cuesta 
        suma_desordenada += conjunto2[i];
        costo_desordenada += suma_desordenada;
    }

    printf("La suma ordenada costó: %i\n", costo_ordenada);
    printf("La suma desordenada costó: %i\n", costo_desordenada);

    return 0;
}