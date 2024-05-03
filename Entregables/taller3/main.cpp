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

    DataSet(int caso, int t, int h, int f, vector<vector<int>>& bellotas) 
        : caso(caso), arboles(t), altura(h), costo_salto(f), bellotas(bellotas) {}

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
        return max;
    }
};

int main() {
    int cantidadCasos;
    cin >> cantidadCasos;

    vector<DataSet> totales;
    for (int i = 0; i < cantidadCasos; i++) {
        int t, h, f;
        cin >> t >> h >> f;

        vector<vector<int>> bellotas(t, vector<int>(h, 0));
        for (int j = 0; j < t; j++) {
            for (int k = 0; k < h; k++) {
                int num;
                cin >> num;
                bellotas[j][num - 1]++;
            }
        }
        totales.push_back(DataSet(i, t, h, f, bellotas));
    }

    for (int i = 0; i < totales.size(); i++) {
        int res = 0;
        for (int j = 0; j < totales[i].arboles; j++) {
            int max = totales[i].ardillitaloca(0, j, totales[i].altura - 1);
            res = std::max(max, res);
        }
        cout << res << endl;
    }

    return 0;
}
