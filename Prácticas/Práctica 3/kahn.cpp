#include <bits/stdc++.h>
using namespace std;

// Orden topológico con el Algortimo de Kahn
vector<int> algoritmoKahn(vector<vector<int> >& lista_adyacencia, int V)
{
    // Vector que guarda los grados de entrada de cada vértice
    vector<int> grados_entrada(V);
    for (int i = 0; i < V; i++) {
        // para cada vecino, ellos dependen de mí ==> le sumo una dependencia
        for (auto vecino : lista_adyacencia[i]) {
            grados_entrada[vecino]++;
        }
    }

    // Cola que almacena los nodos con grado de entrada == 0
    queue<int> cola;
    for (int i = 0; i < V; i++) {
        if (grados_entrada[i] == 0) {
            // pusheamos los vértices que no tienen dependencias
            cola.push(i);
        }
    }
    // vector que devuelve, en caso de no encontrar ciclos, una secuencia ordenada 
    vector<int> result;

    // la exploración de los vértices que no tienen dependencia
    while (!cola.empty()) {
        int actual = cola.front();
        cola.pop();
        // por no depender de nadie, se agregan a res
        result.push_back(actual);

        // le restamos a sus vecinos que dependían de él
        for (auto vecino : lista_adyacencia[actual]) {
            grados_entrada[vecino]--;

            // Si al bajarle el grado de entrada a uno de sus vecinos se hace 0 ==>
            if (grados_entrada[vecino] == 0)
                // tenemos un nuevo nodo para agregar a la cola
                cola.push(vecino);
        }
    }

    // Si nos quedan nodos colgados que no pudimos agregar a resultados, es porque hay una dependencia circular 
    if (result.size() != V) {
        cout << "Tiene ciclo!" << endl;
        return {};
    }

    return result;
}

// agregamos aristas
void agregar_arista(vector<vector<int>> &lista_adyacencias, int a, int b){
    // Agregamos la arista entre a y b (G es dirigido)
    lista_adyacencias[a].push_back(b); 
}

int main()
{
    // vértices
    int V = 6;

    // Aristas
    vector<vector<int> > aristas = { { 0, 1 }, { 1, 2 }, { 2, 3 },{ 3, 4 }, { 4, 5 }, };

    // lista de adyacencia
    vector<vector<int> > lista_adyacencia(V);

    // agregamos al grafo
    for (auto &e : aristas) agregar_arista(lista_adyacencia, e[0], e[1]);

    vector<int> res = algoritmoKahn(lista_adyacencia, V);

    if (res.size() != 0)
    {
        cout << "El orden topológico del grafo es : ";
        for (auto i : res) {
            cout << i << " ";
        }
        cout << endl;
    }
    

    return 0;
}
