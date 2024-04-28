#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

class Casas {
public:
    int habitantes;
    vector<int> demanda_calle;
    int caso;

    Casas(int cant_hab, vector<int>& num, int c) {
        this->habitantes = cant_hab;
        this->demanda_calle = num;
        this->caso = c;
    }

    int func() {
        int suma = 0;
        int actual_i = demanda_calle[0];
        int actual_j = demanda_calle[0];

        int i = 0;
        int j = 0;
        
        while (i < demanda_calle.size()) {
            /* avanzo solo si actual ya es 0 */
            if (actual_i <= 0) {
                demanda_calle[i] = actual_i;
                i++;
                if (i < demanda_calle.size()) {
                    actual_i = demanda_calle[i];
                } 
            }
            /* si es mayor a cero actual_i y estamos en rango */
            else if (actual_i > 0) {
                /* recorro el arreglo en búsqueda de algún negativo que lo haga pelota */
                while (j < demanda_calle.size() && actual_i > 0) {
                    if (actual_j >= 0) {
                        demanda_calle[j] = actual_j;  
                        j++;
                        if (j < demanda_calle.size()) {
                            actual_j = demanda_calle[j];
                        }  
                    }
                    else {
                        suma += abs(j - i);
                        actual_i--;
                        actual_j++;
                        demanda_calle[i] = actual_i;
                        demanda_calle[j] = actual_j;
                    }
                }
            }
        }
        return suma;
    }
};

int main() {
    vector<vector<int>> casos;
    int habitantes;
    int caso = 0;
    do {
        cin >> habitantes;
        if (habitantes != 0) {
            vector<int> demanda(habitantes);
            for (int i = 0; i < habitantes; i++) {
                cin >> demanda[i];
            }
            casos.push_back(demanda);
        }
    } while (habitantes != 0);

    for (int i = 0; i < casos.size(); i++) {
        Casas actual(casos[i].size(), casos[i], i);

        /* aca hago el print de cada caso */
        cerr << actual.func() << endl; 
    }

    return 0;
}
