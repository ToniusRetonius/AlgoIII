#include <bits/stdc++.h>
using namespace std;
int borde = 10e5+1;

// DSU
struct DSU
{
    // atributos
    vector<int> representantes;
    vector<int> rangos;

    // constructor
    DSU(int tam)
    {
        // inicializamos representantes
        representantes.resize(tam);
        for(int i = 0; i < tam; i++) representantes[i] = i;
        // inicializamos los rangos
        rangos.resize(tam, 1);
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

// criterio de ordenamiento
bool criterio(tuple<int,int,int,int> a, tuple<int,int,int,int> b)
{
    return get<2>(a) < get<2>(b);
}

// globales
int V,E;
vector<string> respuestas(borde);
vector<tuple<int,int,int,int>> aristas(borde);
DSU dsu;
vector<vector<int>> lista_adyacencia[borde];


void kruskal_y_tarjan()
{
    int idx;
    // por cada arista ordenada queremos ver si está en el AGM, podría estar o no está definitivamente
    for (int i = 0; i < E; i++)
    {
        // mantenemos referencia a un intervalo [i:idx] para saber si tenemos un grupo frente a nosotros
        idx = i;
        while(idx < aristas.size() && get<2>(aristas[i]) == get<2>(aristas[idx])) idx++;
        
        // kruskal hecho y derecho
        for (int m = i; m < idx; m++)
        {
            // representantes
            int rep_a = dsu.encontrar_representante(get<0>(aristas[m]));
            int rep_b = dsu.encontrar_representante(get<1>(aristas[m]));

            // si conectan representantes distintos
            if (rep_a != rep_b) 
            {
                // los agregamos a nuestro grafo
                lista_adyacencia[rep_a].push_back(rep_b);
                lista_adyacencia[rep_b].push_back(rep_a);
            }
            else
            {
                
            }
            
        }
        
    }
    
}


int main()
{
    // capturamos V
    cin >> V;

    // capturamos #Aristas
    cin >> E;

    // como las aristas tendran la forma de <ai, bi, pi, i> ..
    aristas.resize(E);

    // capturamos las aristas
    for (int i = 0; i < E; i++)
    {
        int ai,bi,pi; cin >> ai >> bi >> pi;
        tuple<int,int,int,int> arista = make_tuple(ai,bi,pi,i);
        aristas[i] = arista;
    }

    // las ordenamos ascendentemente
    sort(aristas.begin(), aristas.end(), criterio);

    // declaramos las estructuras que quedan
    dsu = DSU(V);
    
    // res
    respuestas.assign(E, " ");

    // grafo
    lista_adyacencia.resize(V+1);
    
    // llamamos al algortimo que resuelve : 


    // imprimimos respuestas
    for (int i = 0; i < E; i++)
    {
        cout << respuestas[i] << endl;
    }

    return 0;
}


