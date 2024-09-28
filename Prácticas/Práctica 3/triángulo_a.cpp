#include <bits/stdc++.h>
using namespace std;

// en el ejercicio 15 nos piden algoritmos de distintas complejidades para decidir si hay triángulos en un grafo

int main(){
    // # vertices
    int V = 6;

    // aristas
    vector<vector<int>> aristas = {{1,2},{2,3},{3,1},{4,5}};

    // a ) matriz de adyacencia
    vector<vector<int>> matriz_adyacencias(V, vector<int>(V, 0));

    // ponemos un 1 en aquellos lugares en que haya una arista entre los vértices
    for (auto &e : aristas) 
    {
        matriz_adyacencias[e[0]][e[1]] = 1;
        matriz_adyacencias[e[1]][e[0]] = 1;
    }

    // queremos entonces saber si hay triángulo en tiempo cúbico
    bool res = false;
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            // si encontramos un vecino, queremos saber si para ese vecino mi actual también lo tiene de vecino
            if (matriz_adyacencias[i][j] == 1)
            {
                for (int m = 0; m < V; m++)
                {
                    // si uno de sus vecinos está emparentado con i ==> triǽngulo
                    if (matriz_adyacencias[j][m] == 1)
                    {
                        if (matriz_adyacencias[i][m] == 1)
                        {
                            res = true;
                        }   
                    }   
                } 
            }   
        }  
    }
    cout << (res == true ? "Hay triángulo" : "No hay triángulo") << endl;
    return 0;
}