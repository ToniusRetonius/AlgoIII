#include <bits/stdc++.h>
using namespace std;


bool existesuma(vector<int> conjunto, int indice, int suma, bool matriz[10][46]){
    // si el índice es < 0 es porque ya recorrimos todo y si la suma también es porque nos pasamos
    if (indice < 0 || suma < 0)
    {
        return false;
    }
    // si la suma es exactamente 0, entonces existe una solución que suma 
    if (suma == 0)
    {
        return true;
    }
    else
    {
        // si está en la matriz, sacamos el valor de la matriz : 
        if (matriz[indice][suma] != 0)
        {
            return matriz[indice][suma];
        }
        else
        {
            // sino, recursivamente buscamos si alguno suma, con el elemento en conjunto[indice] o sin y ponemos en la matriz el valor
            matriz[indice][suma] = existesuma(conjunto, indice - 1, suma, matriz) || existesuma(conjunto, indice - 1, suma - conjunto[indice], matriz);
            return matriz[indice][suma];
        }   
        
    }
}

int main()
{
    // si queremos implementar la memoización podemos : 
    vector<int> conjunto = {1,2,3,4,5,6,7,8,9};
    int indice = conjunto.size();
    bool matriz[indice][46];
    int suma = 5;

    bool res = existesuma(conjunto, indice - 1, suma, matriz );
    const char* resultado;
    if(res == true) {
        resultado = "VERDADERO";
    } else {
        resultado = "FALSO";
    } 
    cout << "Para la suma ingresada es : " << resultado << " la existencia de un subconjunto que sume" << endl;

    return 0;
}
