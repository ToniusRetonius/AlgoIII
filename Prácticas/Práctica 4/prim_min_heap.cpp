#include <bits/stdc++.h>
using namespace std;

// prim
int prim(int V, vector<vector<pair<int, int>>>& lista_adyacencia) {
    
    // Crear una cola de prioridad de pares, se utilizará un vector de pares para almacenarlos, 'greater' es el comparador que define el min-heap
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min_heap;
    
    // visitados
    vector<bool> visitados(V, false);
    
    // res es el peso del AGM
    int res = 0;
    
    // Pusheamos < peso, nro de vértice > en este caso donde enraizamos el árbol
    min_heap.push({0, 0}); 
    
    // mientras haya algo en el heap ...
    while(!min_heap.empty()) {
        // tomamos la raiz (el vértice de menor peso)
        auto raiz_heap = min_heap.top();
        min_heap.pop();
        

        int peso = raiz_heap.first;  
        int vertice = raiz_heap.second;  

        // si ya lo visitamos ... continue
        if (visitados[vertice]) {
            continue;  
        }
        
        // como no lo visitamos y es el que minimiza :
        res += peso;  

        // lo marcamos 
        visitados[vertice] = true;  
        
        // qué pasa con sus vecinos ?
        for (const auto& vecino : lista_adyacencia[vertice]) {
            // si no lo visité
            if (!visitados[vecino.first]) 
            {
                // pusheamos al min-heap el <peso, nro de vértice>
                min_heap.push({vecino.second, vecino.first}); 
            }
        }
    }
    
    return res; 
}

int main() {
    int V;
    cin >> V;
    // Crear la lista de adyacencia
    vector<vector<pair<int, int>>> lista_adyacencia(V);
    while (1)
    {
        int vertice_a, vertice_b, peso;
        cin >> vertice_a;
        if ( vertice_a == -1) break;
        
        cin >> vertice_b >> peso;
        
        // agregamos la arista a la lista de adyacencia
        lista_adyacencia[vertice_a].emplace_back(vertice_b, peso);
        // es no dirigido ...
        lista_adyacencia[vertice_b].emplace_back(vertice_a, peso); 
    }

    int costo = prim(V, lista_adyacencia);
    cout << "El costo del AGM es: " << costo << endl;
    return 0;
}
// COMPLEJIDAD : O( E * LOG V) ya que |E| >= V-1 (por ser conexo)
// qué pasa si el grafo es denso ? es decir cuando |E| pertenece a‍ Ω(V^2). Vemos que la complejidad se podrá acotar superiormete por O( V^2 * LOG V)
// ** para esos casos nos va a interesas utilizar la matriz que es mejor que esto último