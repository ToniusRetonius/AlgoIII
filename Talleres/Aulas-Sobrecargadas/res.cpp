#include <bits/stdc++.h>
using namespace std;

// Globales
int N,M;
vector<vector<int>> lista_ady;
vector<vector<int>> capacity;
vector<vector<int>> flujo;

int bfs(int s, int t, vector<int>& parent) {
    fill(parent.begin(), parent.end(), -1);
    parent[s] = -2;
    queue<pair<int, int>> q;
    q.push({s, INT32_MAX});

    while (!q.empty()) {
        int cur = q.front().first;
        int flow = q.front().second;
        q.pop();

        for (int next : lista_ady[cur]) {
            if (parent[next] == -1 && capacity[cur][next]) {
                parent[next] = cur;
                int new_flow = min(flow, capacity[cur][next]);
                if (next == t)
                    return new_flow;
                q.push({next, new_flow});
            }
        }
    }

    return 0;
}

int maxflow(int s, int t, int n) 
{
    int flow = 0;
    vector<int> parent(n);
    int new_flow;

    while (new_flow = bfs(s, t, parent)) {
        flow += new_flow;
        int cur = t;
        while (cur != s) {
            int prev = parent[cur];
            capacity[prev][cur] -= new_flow;
            capacity[cur][prev] += new_flow;
            // 
            flujo[prev][cur] += new_flow;
            flujo[cur][prev] -= new_flow;
            
            cur = prev;
        }
    }

    return flow;
}

int main()
{
    // capturamos N (cantidad de aulas) y M (cantidad de pares de aulas entre los cuales se puede mover el alumno) 
    cin >> N >> M;

    // armamos el grafo (tenemos fuente y sumidero y 2 veces n-aulas)
    lista_ady.resize(2+(2*N));
    for (int i = 1; i <= N; i++)
    {
        // fuente <--> aula_i
        lista_ady[0].push_back(i);
        lista_ady[i].push_back(0);

        // aula_i (capa 1) <--> aula_i (capa 2)
        lista_ady[i].push_back(i+N);
        lista_ady[i+N].push_back(i);

        // aula_i (capa 2) <--> sumidero
        lista_ady[i+N].push_back(1+(2*N));
        lista_ady[1+(2*N)].push_back(i+N);
    }

    // inicializamos capacity 
    capacity.resize(2+(2*N), vector<int>(2+(2*N)));
    
    // capturamos los ai y la sumatoria de ellos
    int suma_ai = 0;
    for (int i = 1; i <= N; i++)
    {
        int ai; cin >> ai;
        suma_ai += ai;

        // definimos la capacidad de s --> aula_i como ai 
        // definimos la capacidad del aula_i --> aula_i (capa segunda)
        capacity[0][i] = ai;
        capacity[i][i+N] = ai;
    }

    // capturamos los bi y la sumatoria de ellos
    int suma_bi = 0;
    for (int i = 1; i <= N; i++)
    {
        int bi; cin >> bi;
        suma_bi += bi;

        // definimos la capacidad aula_i (capa 2) --> sumidero
        capacity[i+N][1+(2*N)] = bi;
    }

    // nos pasan las aulas entre las cuales pueden moverse los alumnos
    for (int i = 0; i < M; i++)
    {
        int p,q; cin >> p >> q;

        // aula_p (capa 1) <--> aula_q (capa 2)
        lista_ady[p].push_back(N+q);
        lista_ady[N+q].push_back(p);

        // aula_q (capa 1) <--> aula_p (capa 2)
        lista_ady[q].push_back(N+p);
        lista_ady[N+p].push_back(q);

        // definimos la capacidad 
        capacity[p][N+q] = capacity[0][p];
        capacity[q][N+p] = capacity[0][q];
    }
    
    // definimos la matriz de flujo (inicializada en cero)
    flujo.resize(2+(2*N), vector<int>(2+(2*N), 0));


    // La respuesta es NO cuando las sumas ai_ bi son diferentes o si
    if (suma_ai != suma_bi || suma_bi != maxflow(0, 1+(2*N), 2+(2*N)))
    {
        cout << "NO" << endl;

    } 
    else
    {
        cout << "YES" << endl;

        // nos pide la matriz de flujo para los valores 
        for (int i = 1; i <= N; i++)
        {
            for (int l = N+1; l <= (2*N); l++)
            {
                if (l != 2*N)
                {
                    cout << flujo[i][l] << " ";
                }
                else
                {
                    cout << flujo[i][l] << endl;
                }
                
            }
            
        }
        
    } 
    return 0;
}