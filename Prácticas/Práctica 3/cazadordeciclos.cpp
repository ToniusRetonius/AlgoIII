#include <bits/stdc++.h>
using namespace std;

// hay dos maneras de resolver este ejercicio :

// - Algoritmo de Kahn para orden topológico ( busca una secuencia lineal de los nodos del grafo de manera que si A->B el nodo A aparezca primero )
//  calcula el grado de entrada de cada nodo del grafo ---> crea una cola con aquellos de grado 0 ---> mientras la cola no esté vacía, se extrae un nodo y se lo agrega a RES 
//  ---> para cada adyacente  : se le reduce el grado de entrada en 1 y si llega a ser 0 ==> se agrega a la cola
//  si al finalizar el proceso, en RES no están todos los nodos, es porque hay ciclos.
// por qué vale esto ? la depencia circular que genera el ciclo hace que nunca se pueda agregar a la cola porque siempre alguien depende de él 

// KAHN ya lo tenemos en kahn.cpp

// - la otra manera es con DFS, si encontramos una BACK EDGE ( es decir un nodo que apunta a un ancestro ) ==> hay ciclo
// la idea es simple : si el nodo está en la pila, es porque es hijo de algún ancestro y si el actual lo tiene como hijo, entonces desde mi lugar se puede ir a visitar a un ancestro ==> ciclo

void DFS_detector_ciclos( vector<vector<int>>& lista_adyacencias, vector<int>& estado, int raiz, bool& res){
    // definimo la pila de exploración
    stack<int> pila;

    // agregamos a la raiz
    pila.push(raiz);

    // mientras haya que explorar ..
    while (!pila.empty())
    {
        // sacamos un elemento para explorar
        int actual = pila.top();
        
        // si su estado es : no explorado ==> explorando
        if (estado[actual] == 0)
        {
            estado[actual] = 1;
        }

        // si ya exploramos todos sus vecinos ==>
        bool vecinos_explorados = true;

        // vamos a ver quiénes dependen del actual
        for (int vecino : lista_adyacencias[actual])
        {
            // si el estado de exploración de mi vecino es : no explorado
            if (estado[vecino] == 0)
            {
                // si no lo visitamos, lo vamos a pushear a la pila
                pila.push(vecino);
                // y le definimos estado : explorando
                estado[vecino] = 1;
                //
                vecinos_explorados = false;
            }
            // si el estado de mi vecino es explorando ( es decir, se encuentra en la pila de exploración)
            else if (estado[vecino] == 1) 
            {
                res = true;
            }
        } 
        // si ya visité a todos mis vecinos, podemos dar paso al estado explorado y a quitarlo finalmente de la pila
        if (vecinos_explorados)
        {
            // estado
            estado[actual] = 2;
            // lo sacamos
            pila.pop();
        }  
    } 
}


void agregar_arista(vector<vector<int>>& lista_adyacencias, int a, int b){
    lista_adyacencias[a].push_back(b);
}

int main(){
    // # vértices
    int V = 10;

    // aristas
    vector<vector<int>> aristas = {{1,2},{2,3},{3,4},{4,2}};

    // inicializamos la lista de adyacencia
    vector<vector<int>> lista_adyacencias(V);

    // agregamos aristas
    for (auto &e : aristas) agregar_arista(lista_adyacencias, e[0], e[1]);

    // definimos el vector de estados de los vértices
    vector<int> estados(V, 0);

    // definimos res
    bool res = false;

    // definimos raiz
    int raiz = 1;

    // llamamos a la función
    DFS_detector_ciclos(lista_adyacencias, estados, raiz, res);

    cout << (res == true ? "Existe ciclo" : "No existe ciclo") << endl;

    return 0;
}