#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

class Edificio {
public:
    int altura;
    int ancho;

    Edificio(int altura, int ancho) : altura(altura), ancho(ancho) {}
};

class SkyLine {
public:
    vector<Edificio> edificios;
    int caso;

    SkyLine() : caso(0) {} // Constructor predeterminado

    SkyLine(int cantidad, int caso) : caso(caso) {
        edificios.reserve(cantidad);
    }

    void AgregarEdificio(const Edificio& e) {
        edificios.push_back(e);
    }

    int subsecCreciente() {
        vector<int> lista(edificios.size(), 0);

        for (size_t i = 0; i < edificios.size(); i++)
            lista[i] = edificios[i].ancho;

        for (size_t i = 1; i < edificios.size(); i++) {
            for (size_t j = 0; j < i; j++) {
                if (edificios[i].altura > edificios[j].altura && lista[i] < lista[j] + edificios[i].ancho) {
                    lista[i] = lista[j] + edificios[i].ancho;
                }
            }
        }

        int max = 0;
        for (size_t i = 0; i < edificios.size(); i++) {
            if (lista[i] > max) {
                max = lista[i];
            }
        }

        return max;
    }

    int subsecDecreciente() {
        vector<int> lista(edificios.size(), 0);

        for (size_t i = 0; i < edificios.size(); i++)
            lista[i] = edificios[i].ancho;

        for (size_t i = 1; i < edificios.size(); i++) {
            for (size_t j = 0; j < i; j++) {
                if (edificios[i].altura < edificios[j].altura && lista[i] < lista[j] + edificios[i].ancho) {
                    lista[i] = lista[j] + edificios[i].ancho;
                }
            }
        }

        int max = 0;
        for (size_t i = 0; i < edificios.size(); i++) {
            if (lista[i] > max) {
                max = lista[i];
            }
        }
        return max;
    }

    bool esCreciente() {
        return subsecCreciente() >= subsecDecreciente();
    }
};

int main() {
    int cantidadCasos;
    cin >> cantidadCasos;

    vector<SkyLine> totales(cantidadCasos);

    for (int i = 0; i < cantidadCasos; i++) {
        int cantidadEdificios;
        cin >> cantidadEdificios;

        vector<int> alturas(cantidadEdificios);
        vector<int> anchos(cantidadEdificios);

        for (int j = 0; j < cantidadEdificios; j++) {
            cin >> alturas[j];
        }

        for (int j = 0; j < cantidadEdificios; j++) {
            cin >> anchos[j];
        }

        SkyLine skyline(cantidadEdificios, i + 1);

        for (int j = 0; j < cantidadEdificios; j++) {
            Edificio edif(alturas[j], anchos[j]);
            skyline.AgregarEdificio(edif);
        }

        totales[i] = skyline;
    }

    for (size_t j = 0; j < totales.size(); j++) {
        string res;

        if (totales[j].esCreciente()) {
            res = "Increasing (" + to_string(totales[j].subsecCreciente()) + "). " + "Decreasing (" + to_string(totales[j].subsecDecreciente()) + ").";
        } else {
            res = "Decreasing (" + to_string(totales[j].subsecDecreciente()) + "). " + "Increasing (" + to_string(totales[j].subsecCreciente()) + ").";
        }

        cout << "Case " << totales[j].caso << ". " << res << endl;
    }

    return 0;
}