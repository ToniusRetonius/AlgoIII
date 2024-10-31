#include <bits/stdc++.h>
using namespace std; 

class DisjointSet 
{
    //  atributos
    vector<int> rangos;
    vector<int> representante;
public:
    // constructor
    DisjointSet(int V) 
    {
        rangos.resize(V + 1, 0);
        representante.resize(V + 1);
        for(int i = 0; i < V + 1; i++)
        {
            representante[i] = i;
        }
    }
 
    int encontrar_representante(int v)
    {
 
        // En caso que nodo sea el representante
        if (v == representante[v]) return v;
 
        // Hago path compression
        return representante[v] = encontrar_representante(representante[v]);
    }
 
    void unir(int t_visitado, int v) 
    {
        int uRepresentative = encontrar_representante(t_visitado);
        int vRepresentative = encontrar_representante(v);
 
        // Si tienen el mismo representante, entonces pertenece al
        // mismo conjunto
        if (uRepresentative == vRepresentative) return;
 
        // Actualizamos el representante segun el caso del rangos
        if (rangos[uRepresentative] < rangos[vRepresentative]) 
        {
            representante[uRepresentative] = vRepresentative;
        } else if(rangos[uRepresentative] > rangos[vRepresentative]) 
        {
            representante[vRepresentative] = uRepresentative;
        } else 
        {
            representante[vRepresentative] = uRepresentative;
            rangos[uRepresentative]++;
        }
    }
};

int V, E, tiempo;
vector<tuple<int,int,int,int>> aristas;
vector<string> respuestas;
DisjointSet dsu(0);
vector<vector<int> > grafo;
vector<int> t_visitado, t_descubrimiento, low;

void tarjan(int actual, int p = -1, int profundidad = 0) 
{
	low[actual] = t_descubrimiento[actual] = profundidad;
	t_visitado[actual] = tiempo + 1;

	for (int i = 0; i < grafo[actual].size(); i++) 
    {
		if (grafo[actual][i] == p)continue;

		int id = grafo[actual][i];
        int a = dsu.encontrar_representante(get<0>(aristas[id]));
        int b = dsu.encontrar_representante(get<1>(aristas[id]));
        int vecino;
        if (a == actual)
        {
            vecino = b;
        } else
        {
            vecino = a;
        }
        
		if (t_visitado[vecino] > tiempo)
        {
			low[actual] = min(low[actual], t_descubrimiento[vecino]);
        }
        else 
        {
			tarjan(vecino, grafo[actual][i], profundidad + 1);
			low[actual] = min(low[actual], low[vecino]);
		}

		if (low[vecino] > t_descubrimiento[actual]) {
			respuestas[get<3>(aristas[grafo[actual][i]])] = "any";
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
    // capturamos la data
	cin >> V >> E;
	for (int i = 0; i < E; i++) 
    {
		int ai, bi, pi;
		cin >> ai >> bi >> pi;
		ai--; bi--;
		aristas.emplace_back(ai,bi,pi,i);
	}
    // ordenamos
	sort(aristas.begin(), aristas.end(), criterio);

    // asignación para este caso
    //  G'
	grafo.assign(V, vector<int> ());
	//  res
    respuestas.assign(E, "at least one");
	//  dsu
    dsu = DisjointSet(V);
	
    //  para Tarjan
    t_descubrimiento.resize(V); 
    low.resize(V); 
    t_visitado.resize(V);

    //  ahora para cada arista hacemos
    int e = 0;
	while(e < E)
    {
        //  el índice k me define el intervalo de repetidas [e:k]
		int k = e;
		while (k < aristas.size() && get<2>(aristas[k]) == get<2>(aristas[e])) k++;
		
        // krukal
        for (int j = e; j < k; j++) 
        {
			int rep_a = dsu.encontrar_representante(get<0>(aristas[j]));
			int rep_b = dsu.encontrar_representante(get<1>(aristas[j]));

            //  si conectan componentes diferentes..
			if (rep_a != rep_b) 
            {
				grafo[rep_a].push_back(j);
				grafo[rep_b].push_back(j);
			}
            // si no .. 
            else
            {
				respuestas[get<3>(aristas[j])] = "none";
            }
		}

		for (int j = e; j < k; j++) 
        {

			int rep_a = dsu.encontrar_representante(get<0>(aristas[j]));
			int rep_b = dsu.encontrar_representante(get<1>(aristas[j]));
			if (t_visitado[rep_a] <= tiempo) tarjan(rep_a);
			if (t_visitado[rep_b] <= tiempo) tarjan(rep_b);
		}
		for (int j = e; j < k; j++) 
        {
			
			int rep_a = dsu.encontrar_representante(get<0>(aristas[j]));
			int rep_b = dsu.encontrar_representante(get<1>(aristas[j]));
			
            //  unión
            dsu.unir(rep_a, rep_b);

            // limpieza
			grafo[rep_a].clear();
            grafo[rep_b].clear();
		}
		e = k;
		tiempo++;
	}

    //  imprimimos
	for (int i = 0; i < E; i++) cout << respuestas[i] << endl;

	return 0;
}
