#include <bits/stdc++.h>
using namespace std;

// idea : por precond es bipartito y es árbol ==> capturamos las biparticiones, chequeamos si la arista con extremo en V1[i] tiene otro extremo en V2[j] para 1 <= j <= |V2|
// con BFS podemos definir por paridad las biparticiones
// n <= 10^5 = 100 000 , tenemos 2seg para hacerlo, como sabemos que en c++ podemos meter ~10^8 op. por segundo ==> 

// esta implementanción da time limit exceeded
long long int cant_nodos;

void biparticiones(vector<vector<long long int>>& lista_adyacencias, long long int raiz, long long int& pares, long long int& impares){
    // visitados
    vector<bool> visitados(cant_nodos+1, false);
    // no hay nodo 0
    visitados[0] = true;

    // para BFS usamos una fifo
    queue<long long int> cola;

    // pusheamos la raiz y la marcamos visitada
    cola.push(raiz);
    visitados[raiz] = true;

    // queremos armar las biparticiones por paridad
    vector<long long int> paridad(cant_nodos+1, -1);
    paridad[raiz] = 0;

    // mientras haya vertices que explorar
    while (!cola.empty())
    {
        // leemos actual
        long long int actual = cola.front();

        // desencolamos
        cola.pop();

        for (long long int vecino : lista_adyacencias[actual])
        {
            // si no lo visité
            if (!visitados[vecino])
            {
                // lo agrego
                cola.push(vecino);

                // visitado
                visitados[vecino] = true;

                // paridad
                paridad[vecino] = (paridad[actual] + 1) % 2;
            }   
        }
    }

    // ya terminamos de definir las paridades ==> armamos las biparticiones
    for (long long int i = 1; i <= cant_nodos; i++)
    {
        // si el vértice i es par ...
        if (paridad[i] == 0)
        {
            pares++;
        }else
        {
            impares++;
        }
    }
}

int main(){
    // capturamos #vértices
    cin >> cant_nodos;

    if (cant_nodos <= 1) {
        cout << 0 << endl;
        return 0;
    }
    
    // tenemos que ir capturando las aristas
    vector<vector<long long int>> lista_adyacencia(cant_nodos+1);

    // el bucle va hasta n-1 (consigna)
    for (long long int i = 1; i < cant_nodos; i++)
    {
        // a -> b
        long long int vertice_a, vertice_b;
        cin >> vertice_a >> vertice_b;
        // es grafo simple
        lista_adyacencia[vertice_a].push_back(vertice_b);
        lista_adyacencia[vertice_b].push_back(vertice_a);
    }
    
    // llamamos a biparticiones
    long long int pares = 0;
    long long int impares = 0;
    biparticiones(lista_adyacencia, 1, pares, impares);

    long long int res = (pares * impares) - (cant_nodos - 1);

    cout << res << endl;
    

    return 0;
}