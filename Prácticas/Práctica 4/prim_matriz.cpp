#include <bits/stdc++.h>
using namespace std;

#define V 5

// esta función actualiza el costo de incluir a cierto vértice (todavía no incluido) en el AGM y retorna su índice
int vertice_mas_liviano(int costos[], bool vertices_AGM[])
{
    // el mínimo es +INF
    int minimo = INT_MAX;
    // el índice del vértice que minimiza agregarlo
    int indice_del_minimo;

    // recorremos los vértices
    for (int v = 0; v < V; v++)
        // si no está en el árbol y el costo de agregarlo el menor que el mínimo ...
        if (vertices_AGM[v] == false && costos[v] < minimo) 
        {
            // actualizamos el valor mínimo
            minimo = costos[v];
            // y nos guardamos qué vértice es el que minimiza
            indice_del_minimo = v;
        }    

    return indice_del_minimo;
}

void prim(int grafo[V][V])
{
    // Padre de cada vértice
    int padres[V];

    // en costos nos guardamos el costo de agregar a cierto vértice al árbol
    int costos[V];

    // este arreglo es como si fuese el visitados, qué vértices están ya en el AGM
    bool vertices_AGM[V];

    // Inicializamos las estructuras
    for (int i = 0; i < V; i++)
    {
        // los costos +INF
        costos[i] = INT_MAX;
        // los vértices que están, todos false
        vertices_AGM[i] = false;
    }

    // el costo del primer vértice 
    costos[0] = 0;
  
    // el padre de la raiz es -1
    padres[0] = -1;

    // recorremos Vértices - 1 porque la raiz ya está en le árbol
    for (int i = 0; i < V - 1; i++) {
        
        // buscamos el vértice más liviano
        int vertice_minimo = vertice_mas_liviano(costos, vertices_AGM);

        // lo agregamos al árbol
        vertices_AGM[vertice_minimo] = true;

        // se recorre cada vértice
        for (int v = 0; v < V; v++)
        {
            // existe la arista entre el vértice que minimiza y el que estoy viendo y no está en el árbol ? Y si existe , es más barata que el último costo de agregarlo?
            // esto último quiere decir que, como ya agregué al mínimo, queremos actualizar los costos de agregar a los vértices que quedan :
            // esto se da porque ahora podríamos tener vértices alcanzables desde este nuevo agregado en los que el costo es menor que el último registrado
            if (grafo[vertice_minimo][v] && vertices_AGM[v] == false && grafo[vertice_minimo][v] < costos[v])
            {
                // se actualiza la data 
               padres[v] = vertice_minimo; 
               costos[v] = grafo[vertice_minimo][v];
            }
        }
    }
}

int main()
{
    // matriz de adyacencia
    int grafo[V][V] = { { 0, 2, 0, 6, 0 },{ 2, 0, 3, 8, 5 },{ 0, 3, 0, 0, 7 },{ 6, 8, 0, 0, 9 },{ 0, 5, 7, 9, 0 } };

    // prim
    prim(grafo);

    return 0;
}

// COMPLEJIDAD : O(V^2)