#include <bits/stdc++.h>
using namespace std;

// globales


// DSU
struct DSU
{
    // atributos
    vector<int> representantes;
    vector<int> rangos;

    // constructor
    void inicio(int tam)
    {
        // inicializamos representantes
        representantes.resize(tam+1);
        for(int i = 0; i < tam + 1; i++) representantes[i] = i;
        // inicializamos los rangos
        rangos.resize(tam+1, 0);
    }

    // método FIND(x) - con path compression (optimización para colocar a todos los vértices transitados como hijos directos del representante )
    int encontrar_representante(int a)
    {
        if(representantes[a] != a) representantes[a] = encontrar_representante(representantes[a]);
        return representantes[a];
    }

    // UNION(x,y) - con unión por rango (optimización para elegir la raíz de menor altura)
    void unir(int a, int b)
    {
        int rep_a = encontrar_representante(a);
        int rep_b = encontrar_representante(b);

        // si están en el mismo conjunto :: false
        if (rep_a == rep_b) return;

        // unimos por rangos
        if(rangos[rep_a] < rangos[rep_b]) representantes[rep_a] = rep_b;
        else if(rangos[rep_a] > rangos[rep_b]) representantes[rep_b] = rep_a;
        else 
        {
            representantes[rep_b] = rep_a;
            rangos[rep_a]++;
        }
    }
};

void puentes(vector<vector<int>>& lista_adyancencia, int vertice, vector<bool>& visitados, vector<int>& padres, vector<int>& niveles, vector<int>& min_nivel_cubierto, vector<string>& respuestas, vector<tuple<int, int, int, int>>& aristas)
{
    cout << "vertice visitado " << vertice << endl;
    // visitado
    visitados[vertice] = true;

    // para cada vecino
    for (auto vecino : lista_adyancencia[vertice])
    {
        //  si no lo visitamos
        if (!visitados[vecino])
        {
            cout << "no visitado " << vertice << endl;
            niveles[vecino] = niveles[vertice] + 1;
            // asignamos nivel
            // asignamos padre
            padres[vecino] = vertice;
            // llamado recursivo
            puentes(lista_adyancencia, vecino, visitados,padres, niveles, min_nivel_cubierto, respuestas, aristas);

            cout << "volvi de puentes " << vertice << endl;
            // actualizamos el min nivel cubierto del vértice en exploración 
            min_nivel_cubierto[vertice] = min(min_nivel_cubierto[vertice], min_nivel_cubierto[vecino]);

            cout << "minimo nivel cubierto por " << vertice << " es " << min_nivel_cubierto[vertice] << endl;
            if (min_nivel_cubierto[vecino] >= niveles[vertice])
            {
                // la eliminación de la arista que conecta a i con su padre haría que i se desconecte del resto del grafo ==> es puente
                respuestas[get<3>(aristas[vecino])] = "any";
                cout << "hay puente " << vertice << endl;
            }
        }
        //  si ya lo visitamos y no es el padre :: es back-edge
        else if (vecino != padres[vertice])
        {
            // esta info es crucial para determinar si la arista es efectivamente un puente
            // esto se debe a que si se pudo llegar desde mi vecino a un nodo que ya fue visitado, es poque hay una arista que me cubre (vértice)
            min_nivel_cubierto[vertice] = min(min_nivel_cubierto[vertice], niveles[vecino]);
        }
    }
}


// criterio de ordenamiento
bool criterio(tuple<int,int,int,int> a, tuple<int,int,int,int> b)
{
    return get<2>(a) < get<2>(b);
}


// kruskal_volado
void kruskal_volador(int E, vector<tuple<int, int, int, int>>& aristas, DSU dsu, vector<vector<int>>& lista_adyacencia, vector<string>& respuestas, vector<int>& min_nivel_cubierto, vector<int>& niveles, vector<int>& padres, vector<bool>& visitados)
{
    // para cada arista
    for (int i = 0; i < E;)
    {
        // definimos el rango de aristas del mismo peso [i;j]
        int j = i;

        while(j < aristas.size() && get<2>(aristas[i]) == get<2>(aristas[j])) j++;

        // Kruskal hecho y derecho
        for (int m = i; m < j; m++)
        {  
            // representantes
            int rep_a,rep_b;
            cout << "iteración de kruskal nro: "<< i <<" vértices : "<< get<0>(aristas[m]) + 1 <<" "<< get<1>(aristas[m]) + 1 << " de peso " << get<2>(aristas[m]) << endl;
            rep_a = dsu.encontrar_representante(get<0>(aristas[m]));
            rep_b = dsu.encontrar_representante(get<1>(aristas[m]));

            // si unen componentes distintas ==> agregamos al AGM (G') sólo nos queda ver si son "any" o no
            if(rep_a != rep_b)
            {
                lista_adyacencia[rep_a].push_back(rep_b);
                lista_adyacencia[rep_b].push_back(rep_a);
                
            }
            // caso contrario ==> la arista nunca estará en el AGM (G')
            else
            {
                respuestas[get<3>(aristas[m])] = "none";
            }
        }
        // ----------------------------------- los none van bien ----------------------------------- 
        //  cómo es mi grafo ?
        for (int l = 0; l < lista_adyacencia.size(); l++)
        {
            cout << "el grafo tiene los vértices : " << l + 1 << " con ";
            for (int j = 0; j < lista_adyacencia[l].size(); j++)
            {
                cout << lista_adyacencia[l][j] + 1 << " ";
            }
            cout << endl;
        }
        

        // acá viene lo áspero : para este G' queremos ver si son puentes
        for (int m = i; m < j; m++)
        {
            // representantes
            int rep_a,rep_b;
            rep_a = dsu.encontrar_representante(get<0>(aristas[m]));
            rep_b = dsu.encontrar_representante(get<1>(aristas[m]));
            
            cout << "representantes : " << rep_a + 1 << " " << rep_b + 1 << endl;
            // corremos puentes  ( acá se rompe : lo que sucede es que no logra capturar bien las aristas que son puentes)
            if (!visitados[rep_a]) puentes(lista_adyacencia, rep_a, visitados, padres, niveles, min_nivel_cubierto, respuestas, aristas);
        }

        
        // luego de decidir si efectivamente van en el AGM, se hace la unión y eliminamos G'
        for (int m = i; m < j; m++)
        {
            // representantes
            int rep_a,rep_b;
            rep_a = dsu.encontrar_representante(get<0>(aristas[m]));
            rep_b = dsu.encontrar_representante(get<1>(aristas[m]));
            
            // unimos
            cout << "unimos " << rep_a <<" con " << rep_b << endl;
            dsu.unir(rep_a, rep_b);

            // eliminamos G' ( el temporal )
            lista_adyacencia[rep_a] = vector<int>();
            lista_adyacencia[rep_b] = vector<int>();
        }

        // ahora analizamos desde la siguiente arista diferente del conjunto
        i = j;
    }   
}

int main()
{
    // capturamos V
    int V; cin >> V;

    // capturamos #Aristas
    int E; cin >> E;

    // como las aristas tendran la forma de <ai, bi, pi, i> ..
    vector<tuple<int, int, int, int>> aristas(E);

    // capturamos las aristas
    for (int i = 0; i < E; i++)
    {
        int ai,bi,pi; cin >> ai >> bi >> pi;
        ai--; bi--;
        tuple<int,int,int,int> arista = make_tuple(ai,bi,pi,i);
        aristas[i] = arista;
    }

    // las ordenamos ascendentemente
    sort(aristas.begin(), aristas.end(), criterio);

    // --------------------------------- ordenadas adecuadamente ---------------------------------
    // for (int i = 0; i < E; i++)
    // {
    //     cout << get<2>(aristas[i]) << endl;
    // }
    
    
    // creamos el DSU
    DSU dsu;
    dsu.inicio(V);

    // declaramos el vector de respuestas
    vector<string> respuestas(E, "at least one");

    // declaramos estructuras importantes
    vector<vector<int>> lista_adyacencia(V, vector<int>());
    vector<bool> visitados(V, false);
    vector<int> padres(V,-1);
    vector<int> niveles(V,0);
    vector<int> min_nivel_cubierto(V, INT16_MAX);

    // llamamos al algortimo que resuelve : kruskal_volador
    kruskal_volador(E, aristas, dsu, lista_adyacencia, respuestas, min_nivel_cubierto, niveles, padres, visitados);

    // imprimimos respuestas
    for (int i = 0; i < E; i++)
    {
        cout << respuestas[i] << endl;
    }

    return 0;
}

