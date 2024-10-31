#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>>& lista_adyancencia, int vertice, vector<bool>& visitados, vector<int>& padres, vector<int>& niveles, vector<int>& min_nivel_cubierto)
{
    // visitado
    visitados[vertice] = true;
    // para cada vecino
    for (auto vecino : lista_adyancencia[vertice])
    {
        //  si no lo visitamos
        if (!visitados[vecino])
        {
            // asignamos nivel
            niveles[vecino] = niveles[vertice] + 1;
            // asignamos padre
            padres[vecino] = vertice;
            // llamado recursivo
            dfs(lista_adyancencia, vecino, visitados,padres, niveles, min_nivel_cubierto);

            // actualizamos el min nivel cubierto del vértice en exploración 
            min_nivel_cubierto[vertice] = min(min_nivel_cubierto[vertice], min_nivel_cubierto[vecino]);
        }
        //  si ya lo visitamos y no es el padre :: es back-edge
        else if (vecino != padres[vertice])
        {
            // esta info es crucial para determinar si la arista es efectivamente un puente
            min_nivel_cubierto[vertice] = min(min_nivel_cubierto[vertice], niveles[vecino]);
            // esto se debe a que si se pudo llegar desde mi vecino a un nodo que ya fue visitado, es poque hay una arista que me cubre (vértice)
            // esta info será relevante después en el análisis de esta información
        }
    }
}

void cubren(int n, vector<int>& padres, vector<int>& niveles, vector<int>& min_nivel_cubierto, vector<bool>& puentes)
{
    for (int i = 0; i < n; i++)
    {
        if (min_nivel_cubierto[i] >= niveles[i] && padres[i] != -1)
        {
            // si no hay un camino alternativo desde el subárbol del vértice i que regrese a uno de sus ancestros sin pasar por i mismo
            // el único camino que conecta a i con sus ancestros pasa por i mismo
            // la eliminación de la arista que conecta a i con su padre haría que i se desconecte del resto del grafo ==> es puente
            puentes[i] = true;
        }
        //  como existe un camino alternativo ...
        else
        {
            puentes[i] = false;
        }      
    }   
}


void puentes(vector<vector<int>>& lista_adyacencia)
{
    int n = lista_adyacencia.size();
    vector<bool> visitados(n, false);
    vector<int> padres(n,-1);
    vector<int> niveles(n,0);
    vector<int> min_nivel_cubierto(n,0);

    for (int i = 0; i < lista_adyacencia.size(); i++)
    {
        if (!visitados[i])
        {
            dfs(lista_adyacencia, i, visitados, padres, niveles, min_nivel_cubierto);
        }
    }
    vector<bool> puentes(n);
    // llamamos a cubren
    cubren(n, padres, niveles, min_nivel_cubierto, puentes);
}

int main()
{
    // le pasamos una lista de adyacencia a puentes ::
    return 0;
}