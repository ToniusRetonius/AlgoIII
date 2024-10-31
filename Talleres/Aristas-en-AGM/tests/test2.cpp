#include <bits/stdc++.h>
using namespace std;

int V, E;
vector<vector<tuple<int,int>>> grafo;
int NO_LO_VI = 0, EMPECE_A_VER = 1, TERMINE_DE_VER = 2;
vector<int> estado;
vector<int> memo;
vector<int> padre;
vector<vector<int>> tree_edges;
vector<int> back_edges_con_extremo_inferior_en;
vector<int> back_edges_con_extremo_superior_en;
vector<tuple<int,int,int,int>> aristas;
vector<string> respuestas;
DSU dsu;

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

// para utilizar esto en multigrafos tengo que armarme un bool para decir si hay ciclo (ARREGLAR MULTIGRAFO)
// cuando intwente retornar marco bool y si encuentro otro que me lleva al mismo lugar ( vemos el bool ese y si es true ==> hay ciclo)
// hay una arista que use para ir a tal lugar ( con la arista no con el nodo) encontrar más de 1 camino para volver a un lugar ... 

// memo[v] = 

void dfs(int v, int p = -1) {
    estado[v] = EMPECE_A_VER;
    for (auto tupla : grafo[v]) {
        int u = get<0>(tupla);

        if (estado[u] == NO_LO_VI) {
            tree_edges[v].push_back(u);
            padre[u]=v;
            dfs(u, v);
        }
        else if (u != padre[v]) {
            if (estado[u] == EMPECE_A_VER) {
                back_edges_con_extremo_superior_en[v]++;
            }
            else // estado[u] == TERMINE_DE_VER
                back_edges_con_extremo_inferior_en[v]++;
        }
    }
    estado[v] = TERMINE_DE_VER;
}

int cubren(int v, int p) {
    if (memo[v] != -1) return memo[v];
    int res = 0;
    for (int hijo : tree_edges[v]) {
        if (hijo != p) {
            res += cubren(hijo, v);
        }
    }
    res += back_edges_con_extremo_superior_en[v];
    res -= back_edges_con_extremo_inferior_en[v];
    memo[v] = res;
    return res;
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

    
    // por cada arista 
    for (int e = 0; e < E;)
    {
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
                grafo[rep_a].emplace_back(rep_a, j);
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
            cout << "analizamos la arista " << j << " de peso " << get<2>(aristas[j]);
            int rep_a = dsu.encontrar_representante(get<0>(aristas[j]));
            int rep_b = dsu.encontrar_representante(get<1>(aristas[j]));
            
            cout << " donde las comp conexas son " << rep_a << " " << rep_b << endl;

            // todas las que son puentes son any
        }
        
        // limpiamos
        for (int j = e; j < i_repes; j++)
        {
            // representantes
            int rep_a = dsu.encontrar_representante(get<0>(aristas[j]));
            int rep_b = dsu.encontrar_representante(get<1>(aristas[j]));
            
            // cout << "Iteración " << j << " unimos " << rep_a << " y " << rep_b << endl;
            // unimos
            if (rep_a != rep_b) dsu.unir(rep_a, rep_b);

            // limpiamos G' 
            grafo[rep_a].clear();
            grafo[rep_b].clear();

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