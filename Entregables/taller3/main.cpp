#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class DataSet {
public:
    int caso;
    int arboles;
    int altura;
    int costo_salto;
    vector<vector<int>> bellotas;
    int max;

    DataSet(int caso, int t, int h, int f, vector<vector<int>>& bellotas) 
        : caso(caso), arboles(t), altura(h), costo_salto(f), bellotas(bellotas), max(0) {}

    int ardillitaloca(int morfi_acumulado, int arbol, int altura) {
        int max = 0;
        
        if (altura == 0) {
            return (morfi_acumulado + bellotas[arbol][altura]);
        }
        
        if (altura < costo_salto) {
            return ardillitaloca(morfi_acumulado + bellotas[arbol][altura], arbol, altura - 1);
        }
        
        else {
            int morfi_insitu = ardillitaloca(morfi_acumulado + bellotas[arbol][altura], arbol, altura - 1);
            max = std::max(max, morfi_insitu);

            for (int i = 0; i < arboles; i++) {
                if (i != arbol) {
                    int morfi = ardillitaloca(morfi_acumulado + bellotas[arbol][altura], i, altura - costo_salto);
                    max = std::max(max, morfi);
                }
            }
        }
        this->max = max;
        return max;
    }
};

int main() {
    int cantidadCasos;
    cin >> cantidadCasos;

    

    return 0;
}
