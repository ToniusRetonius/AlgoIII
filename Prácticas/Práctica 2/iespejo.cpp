#include <bits/stdc++.h>
using namespace std;

// se quiere saber si el índice de arreglo que comienza en 1 coincide con el valor del número indexado allí

bool espejo(int inicio, int fin, vector<int> vec){

    // caso base, 1 elemento
    if (fin == inicio + 1)
    {
        // si el inicio que es nuestro índice es igual al vector en [inicio]
        if (inicio + 1 == vec[inicio])
        {
            return true;
        }else
        {
            return false;
        }
    }else
    {
        // tenemos que partir el vector y fijarnos qué onda el medio (como búsqueda binaria)
        int medio = (fin - inicio) / 2;

        if (vec[inicio + medio] == inicio + medio + 1)
        {
            // el del medio cumple ser espejo
            return true;
        }
        // como está en orden estrictamente creciente ==> 
        else if (vec[inicio + medio] > inicio + medio + 1)
        {
            // si el nro en el vector es mayor al que deseo encontrar ==> busco a su izq
            return espejo(inicio, inicio + medio, vec);

        }
        else if (vec[inicio + medio] < inicio + medio + 1)
        {
            // si el nro en el vector es más chico al que quiero encontrar ==> busco a su derecha
            return espejo(inicio + medio, fin, vec);
        }
    }
}


int main(){

    int n;
    cin >> n;

    vector<int> vector(n);

    for (int i = 0; i < n; i++)
    {
        cin >> vector[i];
    }
    
    string res = espejo(0, n, vector) ? "Verdadero" : "Falso";
    cout << res << endl;
    
    return 0;
}