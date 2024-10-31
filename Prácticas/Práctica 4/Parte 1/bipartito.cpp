#include <bits/stdc++.h>
using namespace std;

// en este ejercicio hay que detectar si un grafo conexo es bipartito. Caso afirmativo : devolvemos una bipartición. Caso negativo : devolver un ciclo de longitud impar.

bool DFS_bipartito(vector<vector<int>> grafo, int raiz, int V, vector<int>& ciclo, vector<int>& biparticion_par, vector<int>& biparticion_impar){
    // visitados
    vector<bool> visitados(V, false);
    visitados[raiz] = true;

    // definimos la paridad :: 0 par , 1 impar. Para qué ? si hay adyacentes de la misma paridad, hay ciclo impar
    vector<int> paridad(V, -1);
    paridad[raiz] = 0;
    // capturamos el padre de cada uno
    vector<int> padres(V, -1);
    // definimos pila
    queue<int> pila;

    // apilamos raiz
    pila.push(raiz);

    // 
    while (!pila.empty())
    {
        // leé el valor
        int actual = pila.front();
        // pop
        pila.pop();

        // explorá
        for (auto vecino : grafo[actual])
        {
            // si no lo visité
            if (!visitados[vecino])
            {
                // marco como visitado
                visitados[vecino] = true;

                // paridad +1 del actual
                paridad[vecino] = (paridad[actual] + 1) % 2;

                // le guardamos el padre
                padres[vecino] = actual;
                // acá está el error
                cout << "el padre de " << actual << " es " << padres[vecino] << endl;
                cout << "la paridad de " << actual << " es " << paridad[vecino] << endl;
                // lo apilo
                pila.push(vecino);

            } 
            // si ya lo visité y tiene la misma paridad que el actual ==> ciclo impar
            else if (paridad[actual] == paridad[vecino])
            {
                // vecino -> v -> v -> ... -> actual ->  vecino
                ciclo.push_back(vecino); 

                int vertice_actual = actual;

                // ciclo infinito porque no anda bien padres
                // while (vertice_actual != vecino && vertice_actual != -1) {
                //     ciclo.push_back(vertice_actual);
                //     vertice_actual = padres[vertice_actual];
                // }

                ciclo.push_back(vecino); 
                // return false;  
            }  
        }
    }

    // si llegamos hasta acá es porque no hay ciclo ==> devolvemos la bipartición
    for (int i = 0; i < V; i++)
    {
        // devolvemos las dos
        if (paridad[i] == 0)
        {
            // el nodo i es par
            biparticion_par.push_back(i);
        } else
        {
            biparticion_impar.push_back(i);
        }
    }
    return false;
}



void agregar_arista(vector<vector<int>>& lista_adyacencia, int a, int b){
    lista_adyacencia[a].push_back(b);
    lista_adyacencia[b].push_back(a);
}

int main(){

    // # vertices
    int V = 5;

    // Grafo bipartito
    vector<vector<int>> aristas_bipartito = {{0, 1}, {0, 2}, {1, 3}, {2, 3}};

    // Grafo con ciclo impar
    vector<vector<int>> aristas_ciclo_impar = {{0, 1}, {1, 2}, {2, 0}, {2, 3}};


    // definimos lista adyacencias
    vector<vector<int>> lista_adyacencias(V);

    // agregamos
    for( auto &e : aristas_ciclo_impar) agregar_arista(lista_adyacencias, e[0], e[1]);

    // le pasamos ciclo y las potnciales biparticiones
    vector<int> ciclo;
    vector<int> biparticion_par;
    vector<int> biparticion_impar;
    bool res = DFS_bipartito(lista_adyacencias, 0, V, ciclo, biparticion_par, biparticion_impar);

    if (res == false)
    {
        cout << "El grafo es BIPARTITO y una bipartición del mismo es : ";
        for (int i = 0; i < biparticion_par.size(); i++)
        {
            cout << biparticion_par[i] << " "; 
        }
        cout << endl;
    } else
    {
        cout << "El grafo tiene un ciclo de longitud impar : ";
        for (int i = 0; i < ciclo.size(); i++)
        {
            cout << ciclo[i] << " "; 
        }
        cout << endl; 
    }
    
    

    return 0;
}
