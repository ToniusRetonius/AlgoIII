#include <bits/stdc++.h>
using namespace std;

void DFS(vector<vector<int>>& lista_adyacencia, vector<bool> visitados,  int raiz){
    // defino la pila
    stack<int> pila;

    // apilo la raiz
    pila.push(raiz);
    // la marco como visitada
    visitados[raiz] = true;

    // mientras la pila tenga nodos para visitar ...
    while (!pila.empty())
    {
        // leemos el valor del último nodo en pushear a la pila
        int actual = pila.top();
        // desapilamos
        pila.pop();

        // para este nodo ( actual ) queremos explorar sus adyacencia
        for(int vecino : lista_adyacencia[actual]){
            // si no lo visitamos al nodo, lo metemos en el stack
            if (visitados[vecino] == false)
            {
                // lo apilamos
                pila.push(vecino);
                // lo marcamos como visitado
                visitados[vecino] = true;
            }
        }
    }
}


// agregamos aristas
void agregar_arista(vector<vector<int>> &lista_adyacencias, int a, int b){
    // Agregamos la arista entre a y b (G es no dirigido)
    lista_adyacencias[a].push_back(b); 
    lista_adyacencias[b].push_back(a);
}

int main(){
    // # vértices
    int V = 4;

    // lista de adyacencia
    vector<vector<int>> lista_adyacencias(V);

    // Aristas
    vector<vector<int>> aristas = {{1,2},{2,3},{3,4}};

    // las agregamos al grafo representado como lista de adyacencia
    for (auto &e : aristas) agregar_arista(lista_adyacencias, e[0], e[1]);

    // declaramos las variables de interés
    vector<bool> visitados(V, false);
    int raiz = 0;

    // llamamos a la función
    DFS(lista_adyacencias, visitados, raiz);

    // si el grafo es disconexo ?
    // la idea ya la vimos en BFS : iteramos sobre cada nodo haciendo DFS con los no-visitados y aumentamos #componentes_conexas++

    return 0;
}
