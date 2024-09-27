#include <bits/stdc++.h>
using namespace std;

// nos ayuda a encontrar la menor distancia del nodo s a todos ( búsqueda por capas)
void BFS(vector<vector<int>>& lista_adyacencia, vector<bool> visitados, int root) 
{
    // Se utiliza una cola fifo para ir pusheando los nodos a explorar
    queue<int> cola;  

    // pusheamos la raiz para explorarla
    cola.push(root);
    // la marcamos como que ya la pusheamos
    visitados[root] = true;

    // mientras hayan nodos por explorar ... 
    while (!cola.empty()) {
        // leemos y desencolamos al nodo que queremos explorar
        int actual = cola.front();
        cola.pop();

        // explorarlo implica : mirar todos sus vecinos y pushear a la cola aquellos nodos que no teníamos agregados en la cola
        for (int vecinos : lista_adyacencia[actual]) {
            // si es un nodo que nunca nos apareció en la búsqueda de vecinos nuevos ... 
            if (visitados[vecinos] == false) {
                // lo agregamos a la cola para explorarlo luego
                cola.push(vecinos);
                // marcamos que a ese nodo ya lo agregamos, asi que no es novedad si nos topamos con él luego
                visitados[vecinos] = true;
            }
        }
    }
}

void agregar_arista(vector<vector<int>>& lista_adyacencia, int u, int v) 
{
    lista_adyacencia[u].push_back(v);
    lista_adyacencia[v].push_back(u); // no dirigido por eso también le definimos 
}

int main() 
{
    // # vertices
    int V = 4;

    // Lista de adyacencia
    vector<vector<int>> lista_adyacencia(V);

    // Aristas
    vector<vector<int>> aristas = {{1,2},{3,4},{1,4}};

    // las agregamos
    for(auto &e : aristas) agregar_arista(lista_adyacencia, e[0], e[1]);

    // para evitar pushear repetidas veces nodos a la cola, por tanto explorar repetidas veces, se usa este vector que mantiene control sobre los nodos ya pusheados
    vector<bool> visitados(lista_adyacencia.size(), false);
    
    // llamamos a BFS
    BFS(lista_adyacencia, visitados, 0);
    
    // si el grafo es disconexo ? 
    int comp_conexa = 0;
    for (int m = 0; m < V; m++)
    {
        // la solución es correr un BFS por cada nodo que no haya sido visitado y listo
        if (visitados[m] == false)
        {
            // encontramos una componente conexa
            comp_conexa++;
            BFS(lista_adyacencia, visitados ,visitados[m]);
        }
        
    }
    

    return 0;
}
