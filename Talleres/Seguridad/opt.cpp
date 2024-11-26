#include <bits/stdc++.h>
using namespace std;

//  NOS INTERESA ENCONTRAR EL COSTRO DE IR DESDE 0 AL VÉRTICE N-1
// Dijkstra works with Multigraphs, but you should not keep track of visited vertices, you have to examine them again because of the parallel edges. Moreover, whenever you find a self-loop you should move one without any calculations.


// globales
vector<vector<pair<long long int, int>>> lista_adyacencia;
long long int N, M;
// distancias
vector<long long int> dist_1;
vector<long long int> dist_2;


void dijkstra(long long int src, vector<long long int>& distancias)
{
    // cola de prioridad
    priority_queue<pair<long long int, long long int> , vector <pair< long long int, long long int>>, greater<pair<long long int, long long int >>> pq;
    
    // chequear este caso para loop 
    // encolamos el src
    pq.push(make_pair(0, src));
    distancias[src] = 0;
    

    // mientras tenga nodos en la pila
    while (!pq.empty())
    {
        // tomamos el de menor distancia
        long long int w = pq.top().second;
        
        // desencolamos
        pq.pop();

        // para cada uno de sus adyacentes ...
        for(auto &vecino : lista_adyacencia[w])
        {
            if(vecino.first == w) continue; // si es sí mismo

            long long int v = vecino.first;
            int peso = vecino.second;
            

            // existe camino más corto hacia v ?
            if(distancias[v] > distancias[w] + peso)
            {
                // actualizamos
                distancias[v] = distancias[w] + peso;

                pq.push(make_pair(distancias[v], v));
            }
        }
    }

}


int main()
{
    // capturamos N (cantidad de esquinas) y M (cantidad de calles)
    cin >> N >> M;

    // resize
    // lista_adyacencia.resize(N, vector<tuple<long long int, int>>(M));
    lista_adyacencia.resize(N);

    // capturamos v, w, c ( calle bidireccional entre v y w de largo c)
    for (long long int i = 0; i < M; i++)
    {
        int v,w,c; cin >> v >> w >> c;

        // construimos la lista de adyacencia (multigrafo no dirigido)
        lista_adyacencia[v].push_back(make_pair(w, c));
        lista_adyacencia[w].push_back(make_pair(v, c));
    }
    
    
    dist_1.resize(N, INT32_MAX);
    dist_2.resize(N, INT32_MAX);
    

    dijkstra(0, dist_1);
    dijkstra(N-1, dist_2);

    // queremos ver si d(s, v) + c(v → w) + d(w, t) = d(s, t)

    long long int suma = 0;
    for (long long int i = 0; i < N; i++)
    {
        for (auto& vecino : lista_adyacencia[i])
        {
            int v = i, w = vecino.first;
            int peso = vecino.second;

            if (dist_1[v] + peso + dist_2[w] == dist_1[N-1] || dist_1[w] + peso + dist_2[v] == dist_1[N-1])
            {
                suma += peso;
            }
        }
    }
    long long int res = suma;
    cout << res << endl;


    return 0;
}