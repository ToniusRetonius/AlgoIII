#include <bits/stdc++.h>
using namespace std;

// idea : por precond es bipartito y es árbol ==> capturamos las biparticiones, chequeamos si la arista con extremo en V1[i] tiene otro extremo en V2[j] para 1 <= j <= |V2|
// con BFS podemos definir por paridad las biparticiones
// n <= 10^5 = 100 000 , tenemos 2seg para hacerlo, como sabemos que en c++ podemos meter ~10^8 op. por segundo ==> 

// esta implementanción da time limit exceeded
int cant_nodos;

void biparticiones(vector<vector<int>>& lista_adyacencias, int raiz, vector<int>& pares, vector<int>& impares){
    // visitados
    vector<bool> visitados(cant_nodos+1, false);
    // no hay nodo 0
    visitados[0] = true;

    // para BFS usamos una fifo
    queue<int> cola;

    // pusheamos la raiz y la marcamos visitada
    cola.push(raiz);
    visitados[raiz] = true;

    // queremos armar las biparticiones por paridad
    vector<int> paridad(cant_nodos+1, -1);
    paridad[raiz] = 0;

    // mientras haya vertices que explorar
    while (!cola.empty())
    {
        // leemos actual
        int actual = cola.front();

        // desencolamos
        cola.pop();

        for (int vecino : lista_adyacencias[actual])
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
    for (int i = 1; i <= cant_nodos; i++)
    {
        // si el vértice i es par ...
        if (paridad[i] == 0)
        {
            pares.push_back(i);
        }else
        {
            impares.push_back(i);
        }
    }
}

int cuantas_faltan(vector<vector<int>>& lista_adyacencia, vector<int>& pares, vector<int>& impares){
    // para el vertice par i-ésimo existe arista con todos los elementos de la bipartición impar ? no, sumo 1 entonces 
    
    // hay que optimizar esta función !!!!
    int contador = 0;

    for (int vertice_par : pares)
    {
        vector<bool> tiene_arista(cant_nodos+1, false);
        // llenamos con los true
        for (int i = 0; i < lista_adyacencia[vertice_par].size(); i++)
        {
            tiene_arista[lista_adyacencia[vertice_par][i]] = true;
        }

        // chequeamos si tiene con todos
        for ( int vertice_impar : impares)
        {
            if (!tiene_arista[vertice_impar])
            {
                contador++;
            }    
        }
    }
    return contador;
    
}


int main(){
    // capturamos #vértices
    cin >> cant_nodos;

    // tenemos que ir capturando las aristas
    vector<vector<int>> lista_adyacencia(cant_nodos+1);

    // el bucle va hasta n-1 (consigna)
    for (int i = 1; i < cant_nodos; i++)
    {
        // a -> b
        int vertice_a, vertice_b;
        cin >> vertice_a >> vertice_b;
        // es grafo simple
        lista_adyacencia[vertice_a].push_back(vertice_b);
        lista_adyacencia[vertice_b].push_back(vertice_a);
    }
    
    // for (int i = 1; i <= cant_nodos; i++)
    // {
    //    for (int j = 0; j < lista_adyacencia[i].size(); j++)
    //    {
    //         cout << "El vértice " << i << " tiene una arista con " << lista_adyacencia[i][j] << endl;
    //    }
    // }

    // ------------- correctamente capturada la data ------------- //
    
    // llamamos a biparticiones
    vector<int> pares;
    vector<int> impares;
    biparticiones(lista_adyacencia, 1, pares, impares);

    // cout << "La bipartición de los pares está formada por :" ;
    // for (int i = 0; i < pares.size(); i++)
    // {
    //    cout << pares[i] << " ";
    // }
    // cout << endl;
    // cout << "La bipartición de los impares está formada por : "; 
    // for (int i = 0; i < impares.size(); i++)
    // {
    //    cout << impares[i] << " ";
    // }
    // cout << endl;
    // ------------- correctamente capturadas las biparticiones ------------- //

    int res = cuantas_faltan(lista_adyacencia, pares, impares);

    cout << res << endl;
    

    return 0;
}