#include <bits/stdc++.h>
using namespace std;

int main()
{
    // capturamos aulas
    int aulas;
    cin >> aulas;

    // armamos el multigrafo dirigido
    vector<vector<int>> lista_adyacencia(aulas+1);

    for (int i = 1; i <= aulas; i++)
    {
        int atajo; 
        cin >> atajo;
        lista_adyacencia[i].push_back(atajo);

        if (i != aulas)
        {
            lista_adyacencia[i].push_back(i+1);
            lista_adyacencia[i+1].push_back(i);
        }
        
    }

    // inicializamos distancias indefinidas
    vector<int> distancias(aulas+1, INT32_MAX);

    // la idea es BFS y comparar si encontramos una mejor
    vector<bool> visitados(aulas+1, false);

    // Se utiliza una cola fifo para ir pusheando los nodos a explorar
    queue<int> cola;  

    // pusheamos la raiz para explorarla
    cola.push(1);
    // la marcamos como que ya la pusheamos
    visitados[1] = true;

    // distancia
    distancias[1] = 0;

    // mientras hayan nodos por explorar ... 
    while (!cola.empty())
    {
        //
        int actual = cola.front();

        //
        cola.pop();

        // para cada vecino no visitado ...
        for (auto vecino : lista_adyacencia[actual])
        {
            if(!visitados[vecino])
            {
                // pusheamos a la cola
                cola.push(vecino);

                // marcamos visitado
                visitados[vecino] = true;

                // si no se le asignó distancia ... 
                if (distancias[vecino] == INT32_MAX) distancias[vecino] = distancias[actual] + 1;   
            }
        }
    }
    
    // si todo va bien -- acá ya tenemos las mejores distancias para llegar de 1 a todos
    for (int i = 1; i <= aulas; i++)
    {
        cout << distancias[i] << " ";
    }
    cout << endl;
    
    return 0;
}