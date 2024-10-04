#include <bits/stdc++.h>
using namespace std;

int vertices = 10;
int contador = 0;

void dfs_puentes(vector<vector<int>>& lista_adyacencia, int raiz, vector<vector<int>>& backedges)
{
    // visitados
    vector<bool> visitados(vertices, false);

    // tiempo visita
    vector<int> inicio(vertices, -1);

    // tiempo final
    vector<int> fin(vertices, -1);

    // pila
    stack<int> pila;

    // pusheamos raiz
    pila.push(raiz);

    // visitada
    visitados[raiz] = true;

    while (!pila.empty())
    {
        // actual es ..
        int actual = pila.top();

        // le defino tiempo inicio
        inicio[actual] = contador;
        // pop
        pila.pop();

        for (int vecino : lista_adyacencia[actual])
        {
            if (!visitados[vecino])
            {
                //
                pila.push(vecino);

                // 
                visitados[vecino] = true;
            }
            // para capturar back edges
            else if (vecino != actual && inicio[vecino] < inicio[actual])
            {
                //
                vector<int> arista(2);
                arista[0] = actual;
                arista[1] = vecino;
                backedges.push_back(arista);
            }
            
        }
        cout << contador << endl;
        contador++;

    }
    

}

void agregar_arista(vector<vector<int>>& lista_adyacencia, int a, int b){
    lista_adyacencia[a].push_back(b);
    lista_adyacencia[b].push_back(a);
}

int main()
{

    // Grafo con ciclo impar
    vector<vector<int>> aristas = {{0, 3}, {0, 4}, {1, 4}, {1, 5}, {2,6}, {2,5}, {3,7}, {7, 4}, {4, 8}, {8, 5}, {5, 9}, {9, 6}};

    // definimos lista adyacencias
    vector<vector<int>> lista_adyacencias(vertices);

    // agregamos
    for( auto &e : aristas) agregar_arista(lista_adyacencias, e[0], e[1]);

    vector<vector<int>> backedges;

    dfs_puentes(lista_adyacencias, 0, backedges);

    for (int i = 0; i < backedges.size(); i++)
    {
        cout << "Hay una back edge de " << backedges[i][0] << " a " << backedges[i][1] << endl;
        
    }
    

    return 0;
}