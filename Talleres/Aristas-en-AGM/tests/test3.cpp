#include <bits/stdc++.h>
using namespace std;

// DSU
struct DSU
{
    // atributos
    vector<int> representantes;
    vector<int> rangos;

    // constructor
    void inciar(int tam)
    {
        // inicializamos representantes
        representantes.resize(tam);
        for(int i = 0; i < tam; i++) representantes[i] = i;
        // inicializamos los rangos
        rangos.resize(tam, 0);
    }

    // método FIND(x) - con path compression (optimización para colocar a todos los vértices transitados como hijos directos del representante )
    int encontrar_representante(int a)
    {
        if(representantes[a] != a) representantes[a] = encontrar_representante(representantes[a]);
        return representantes[a];
    }

    // UNION(x,y) - con unión por rango (optimización para elegir la raíz de menor altura)
    bool unir(int a, int b)
    {
        int rep_a = encontrar_representante(a);
        int rep_b = encontrar_representante(b);

        // si están en el mismo conjunto :: false
        if (rep_a == rep_b) return false;

        // unimos por rangos
        if(rangos[rep_a] < rangos[rep_b]) representantes[rep_a] = rep_b;
        else if(rangos[rep_a] > rangos[rep_b]) representantes[rep_b] = rep_a;
        else 
        {
            representantes[rep_b] = rep_a;
            rangos[rep_a]++;
        }
        return true;
    }
};

// globales
int V,E, tiempo;
vector<tuple<int,int,int,int>> aristas;
vector<string> respuestas;
DSU dsu;
// la idea del grafo es pasarle el índice por que sino perdemos la data
vector<vector<tuple<int,int>>> grafo;
vector<bool> visitados;
vector<int> descubrimiento, low, padres;

void dfs(int vertice) {
    // visitamos
    cout << "visitamos " << vertice << endl;
    visitados[vertice] = true;
    descubrimiento[vertice] = low[vertice] = tiempo++;

    for (tuple<int,int> tupla : grafo[vertice]) {
        int vecino = get<0>(tupla);
        int indice = get<1>(tupla);

        //  para cada vecino :: si no lo visité
        if (!visitados[vecino]) 
        {
            // asigno padre
            padres[vecino] = vertice;
            
            // recursión
            dfs(vecino);
            
            // definimos el mínimo nivel al que puede alcanzar
            low[vertice] = min(low[vertice], low[vecino]);
            
            // si puede llegar a un nivel 
            if (low[vecino] > descubrimiento[vertice]) {
                cout << "hay back edge entre " << vertice << " y " << vecino << endl;
                respuestas[indice] = "any";
            }
            else
            {
                respuestas[indice] = "at least one";
            }
            
        } else if (vecino != padres[vertice]) 
        {
            // si ya lo visité y no es el padre :: 
            low[vertice] = min(low[vertice], descubrimiento[vecino]);
        }
    }
}


// criterio de ordenamiento
bool criterio(tuple<int,int,int,int> a, tuple<int,int,int,int> b)
{
    return get<2>(a) < get<2>(b);
}

int main()
{
    // #vértices y # aristas
    cin >> V >> E;

    // capturamos las aristas
    aristas.resize(E);

    for (int i = 0; i < E; i++)
    {
        int ai,bi,pi;
        cin >> ai >> bi >> pi;
        aristas[i] = make_tuple(ai,bi,pi,i);
    }

    // ordenamos
    sort(aristas.begin(), aristas.end(), criterio);

    // declaramos res
    respuestas.assign(E, " ");

    // inicializamos el DSU
    dsu.inciar(V+1);

    // iniciamos el grafo
    grafo.resize(V+1, vector<tuple<int,int>>());

    // visitados
    visitados.resize(V+1, false);

    // 
    descubrimiento.resize(V+1, -1);

    // 
    low.resize(V+1,-1);

    // 
    padres.resize(V+1,-1);

    
    // por cada arista 
    for (int e = 0; e <= E;)
    {
        cout << e << endl;
        // capturamos el intervalo de pesos repetidos
        int i_repes = e;

        while(i_repes < E && get<2>(aristas[e]) == get<2>(aristas[i_repes])) i_repes++;

        // por cada arista del mismo peso
        for (int j = e; j < i_repes; j++)
        {
            // queremos ver si la arista une a representantes del mismo peso
            int rep_a = dsu.encontrar_representante(get<0>(aristas[j]));
            int rep_b = dsu.encontrar_representante(get<1>(aristas[j]));


            // si une a distintos ==> armamos un grafo en el que existe la arista del rep_a -- rep_b 
            if (rep_a != rep_b)
            {
                // armamos G' con < representante, indice > ( para no perderlo )
                grafo[rep_a].emplace_back(rep_b, j);
                grafo[rep_b].emplace_back(rep_a, j);
            }
            else
            {
                // si están en la misma componente ....
                respuestas[get<3>(aristas[j])] = "none";
            }
        }
        
        // una vez construido el grafo :: chequeamos puentes
        for (int j = e; j < i_repes; j++)
        {
            int rep_a = dsu.encontrar_representante(get<0>(aristas[j]));
            int rep_b = dsu.encontrar_representante(get<1>(aristas[j]));

            // si conectan componentes distintas
            if (rep_a != rep_b) dfs(rep_a);

        }
        
        // limpiamos
        for (int j = e; j < i_repes; j++)
        {
            // representantes
            int rep_a = dsu.encontrar_representante(get<0>(aristas[j]));
            int rep_b = dsu.encontrar_representante(get<1>(aristas[j]));
            
            // unimos
            if (rep_a != rep_b) dsu.unir(rep_a, rep_b);

            // G' 
            grafo[rep_a].clear();
            grafo[rep_b].clear();

            // 
            descubrimiento[rep_a] = -1;
            descubrimiento[rep_b] = -1;

            // 
            visitados[rep_a] = false;
            visitados[rep_b] = false;

            // 
            padres[rep_a] = -1;
            padres[rep_b] = -1;

            tiempo = 0;

        }
        e = i_repes; 
    }
    

    // imprimimos respuestas
    for (int i = 0; i < E; i++)
    {
        cout << respuestas[i] << endl;
    }
    
    return 0;
}