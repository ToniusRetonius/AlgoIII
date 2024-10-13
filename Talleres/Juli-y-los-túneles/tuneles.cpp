#include <bits/stdc++.h>
using namespace std;

int aulas;


int main()
{
    // capturamos aulas
    cin >> aulas;

    // armamos digrafo
    vector<vector<int>> lista_adyacencia(aulas+1);

    for (int i = 1; i <= aulas; i++)
    {
        int atajo; 
        cin >> atajo;
        lista_adyacencia[i].push_back(atajo);
        lista_adyacencia[i].push_back(i+1);
    }
    

    // ----------- digrafo armado ----------- //

    // estas son las distancias de recorrido trivial
    vector<int> distancias;
    for (int i = 1; i <= aulas; i++)
    {
        distancias[i] = i - 1;
    }

    // la idea es BFS y comparar si encontramos una mejor
    vector<bool> visitados(aulas, false);

    // Se utiliza una cola fifo para ir pusheando los nodos a explorar
    queue<int> cola;  

    // pusheamos la raiz para explorarla
    cola.push(1);
    // la marcamos como que ya la pusheamos
    visitados[1] = true;

    // distancia
    int distancia = 0;

    // mientras hayan nodos por explorar ... 
    while (!cola.empty()) {
        // leemos y desencolamos al nodo que queremos explorar
        int actual = cola.front();
        cola.pop();

        distancia++;

        // explorarlo implica : mirar todos sus vecinos y pushear a la cola aquellos nodos que no teníamos agregados en la cola
        for (int vecinos : lista_adyacencia[actual]) {
            // si es un nodo que nunca nos apareció en la búsqueda de vecinos nuevos ... 
            if (visitados[vecinos] == false) {
                // lo agregamos a la cola para explorarlo luego
                cola.push(vecinos);
                // marcamos que a ese nodo ya lo agregamos, asi que no es novedad si nos topamos con él luego
                visitados[vecinos] = true;

                // comparamos
                if (distancias[vecinos] < )
                {
                    /* code */
                }
                
            }
        }
    }

    
    
    
}