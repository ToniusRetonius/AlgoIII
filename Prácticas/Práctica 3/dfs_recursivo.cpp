#include <bits/stdc++.h>
using namespace std;

// agregamos aristas
void agregar_arista(vector<vector<int>> &lista_adyacencias, int a, int b){
    // Agregamos la arista entre a y b (G es no dirigido)
    lista_adyacencias[a].push_back(b); 
    lista_adyacencias[b].push_back(a);
}

// DFS recursivo
void DFSRecursivo(vector<vector<int>> &lista_adyacencias, vector<bool> &visitados, int actual){
    // Visitamos el actal
    visitados[actual] = true;

    // Hacemos un print 
    cout << actual << " ";

    // Visitamos recursivamente los vecinos del actual
    for (int i : lista_adyacencias[actual])
        if (visitados[i] == false)
            DFSRecursivo(lista_adyacencias, visitados, i);
}

int main(){
    // # Vértices
    int V = 5; 

    // Lista de adyacencias
    vector<vector<int>> lista_adyacencias(V);

    // Aristas
    vector<vector<int>> aristas={{1, 2},{1, 0},{2, 0},{2, 3},{2, 4}};

    // Agregamos las aristas al grafo
    for (auto &e : aristas) agregar_arista(lista_adyacencias, e[0], e[1]);

    // inicializamos visitados y raiz
    vector<bool> visitados(lista_adyacencias.size(), false);
    int raiz = 1; 

    cout << "DFS iniciado desde: " << raiz << endl;
    DFSRecursivo(lista_adyacencias, visitados, raiz); 
    cout << endl;

    // si el grafo es disconexo ?
    // la idea ya la vimos en BFS : iteramos sobre cada nodo haciendo DFS con los no-visitados y aumentamos #componentes_conexas++

    return 0;
}
