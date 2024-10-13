#include <bits/stdc++.h>
using namespace std;

// recordar que este tipo de grafos deben ser dirigidos! ( no se puede capturar una dependencia de una adyancencia sin dirección)
// asumimos para esta implementación que recibimos un DAG

int vertices;

void sort_topologico_con_dfs(vector<vector<int>>& l_a, int raiz, vector<bool>& visitados, vector<int>& post_order)
{
    //
    stack<int> pila;
    //
    pila.push(raiz);

    //
    visitados[raiz] = true;

    // pila del sort
    stack<int> sort;

    while (!pila.empty())
    {
        //
        int actual = pila.top();

        //
        pila.pop();

        //
        for (int vecino : l_a[actual])
        {
            if (!visitados[vecino])
            {
                //
                pila.push(vecino);

                // 
                visitados[vecino] = true;
            }
        }

        // lo terminé de visitar ==> apilo
        sort.push(actual);
    }

    // desapilamos de sort y se lo mandamos a post-order
    while (!sort.empty()) {
        post_order.push_back(sort.top());
        sort.pop();
    }
}   

int main()
{
    // # vértices
    cin >> vertices;

    // lista de adyancencia
    vector<vector<int>> lista_adyacencia(vertices);

    for (int i = 0; i < vertices; i++)
    {
        // armo el digrafo
        int a,b; 
        cin >> a >> b;
        // de a --> b
        lista_adyacencia[a].push_back(b);
    }
    // declaramos visitados
    vector<bool> visitados(vertices, false);
    // declaramos el post-order
    vector<int> post_order;

    //
    sort_topologico_con_dfs(lista_adyacencia, 0, visitados, post_order);

    // lo devolvemos invertido
    for (int i = (vertices-1); i >= 0; i--)
    {
        cout <<  post_order[i] << " ";
    }
    
    cout << endl;

    return 0;
}