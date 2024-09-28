#include <bits/stdc++.h>
using namespace std;

int main(){
    // # vertices
    int V = 7;

    // aristas
    vector<vector<int>> aristas = {{1,2},{2,3},{3,1},{4,5}, {4,6}, {1, 5}};

    // b ) lista de adyacencias
    vector<vector<int>> lista_adyacencias(V);

    // agregamos aristas
    for (auto &e : aristas) 
    {
        lista_adyacencias[e[0]].push_back(e[1]);
        lista_adyacencias[e[1]].push_back(e[0]);
    }

    // queremos entonces saber si hay triángulo en tiempo cuadrátrico
    for (int actual = 0; actual < V; actual++)
    {
        // declaramos el vector de marcados
        vector<bool> marcados(V, false);

        for (auto adyacente : lista_adyacencias[actual])
        {
            // agregamos a la lista de marcados a los adyacentes del actual
            marcados[adyacente] = true;

            for (auto vecino_de_marcado : lista_adyacencias[adyacente])
            {
                // si el vecino de marcado está en marcados ==> hay ciclo
                if (marcados[vecino_de_marcado] && vecino_de_marcado != actual)
                {
                    // encontramos el ciclo
                    cout << "Hay ciclo" << endl;
                    return 0;
                }
                
            }
        }
    }
    cout << "No hay ciclo" << endl;
    

    return 0;
}