#include <iostream>
#include <vector>

using namespace std;

int INF = 1e9;

int N, P;
vector<int> p, suma_restante;
vector<int> mejor_solucion; int mejor_p;

vector<int> completar_solucion(vector<int>& solucion_parcial, int i) {
    vector<int> solucion = solucion_parcial;

    for (int j=i; j<N; j++)
        solucion.push_back(j);
    
    return solucion;
}

void CD(int i, int k, vector<int>& solucion_parcial) {
    
    int espacio_ocupado = P - k;
    
    //Si no hay capacidad o incluso sumando todo lo que sigue no llego
    //al mejor conocido, corto
    if (k < 0 || espacio_ocupado + suma_restante[i] <= mejor_p)
        return;

    //Si todo lo que queda entra en el CD, directamente lo propongo
    //como optimo (si había algo mejor corté en el if anterior)
    if (suma_restante[i] <= k) {
        mejor_solucion = completar_solucion(solucion_parcial, i);
        mejor_p = espacio_ocupado + suma_restante[i];
        return;
    }

    if (i == N) {
        //Si llegué acá esta solución es la mejor
        //(si no cortaba en el primer if)
        mejor_solucion = solucion_parcial; mejor_p = espacio_ocupado;
    } else {
        //Pongo el próximo elemento y hago llamado recursivo
        solucion_parcial.push_back(i);
        CD(i+1, k - p[i], solucion_parcial);

        //Quito el elemento y hago el otro llamado recursivo
        solucion_parcial.pop_back();
        CD(i+1, k, solucion_parcial);
    }
    return; 
}

int main() {
    cin >> N >> P;

    p.resize(N, -1);
    for (int i=0; i<N; i++) cin >> p[i];

    suma_restante.resize(N+1, 0);
    for (int i=N-1; i>=0; i--) suma_restante[i] = suma_restante[i+1] + p[i];

    mejor_solucion.resize(0); mejor_p = 0;

    vector<int> solucion_parcial(0);

    CD(0, P, solucion_parcial);

    cout << "La mejor solucion contiene " << mejor_solucion.size() << " elementos y pesa " << mejor_p << endl;
    cout << "----> ";

    for (size_t i=0; i<mejor_solucion.size(); i++) {
        cout << mejor_solucion[i] << " ";
    }
    cout << endl;

    return 0;
}
