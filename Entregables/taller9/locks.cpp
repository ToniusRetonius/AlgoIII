#include <bits/stdc++.h>

using namespace std;

vector<long long> respuestas;

long long costo(int a, int b){

    // los paso a str para poder indexar y ver la long
    string a_str = to_string(a); 
    string b_str = to_string(b);

    int a_len = a_str.size();
    int b_len = b_str.size();

    long long costo = 0;

    if (a_len == b_len)
    {
        for (int i = 0; i < a_len; i++)
        {
            int a_i = a_str[i];
            int b_i = b_str[i];
            costo += abs(a_i - b_i);
        }
    }
    if (a_len > b_len)
    {   
        // calcula para la #digitos en comun
        for (int i = 0; i < b_len; i++)
        {
            int a_i = a_str[i];
            int b_i = b_str[i];
            costo += abs(a_i - b_i);
        }
        // calcula para los que no son comunes a ambos
        for (int j = b_len; j < a_len; j++)
        {
            // conversion a int 
            int a_j = a_str[j] - '0';
            costo += a_j;
        }
    }
    if (a_len < b_len)
    {   
        // calcula para la #digitos en comun
        for (int i = 0; i < a_len; i++)
        {
            int a_i = a_str[i];
            int b_i = b_str[i];
            costo += abs(a_i - b_i);
        }
        // calcula para los que no son comunes a ambos
        for (int j = a_len; j < b_len; j++)
        {
            // conversion a int (esto es por el ASCII)
            int b_j = b_str[j] - '0';
            costo += b_j;
        }
    }
    return costo;
}


void prim_m_lg_n(int n, vector<vector<pair<long long,int>>> g){
    priority_queue<pair<long long, pair<int, int>>> q;
    vector<bool> visited(10000, false);

    for(auto [w, v] : g[0]){
        q.push(make_pair(-w, make_pair(0, v)));
    }

    visited[0] = true;
    int edges = 0;
    long long s = 0;
    while(!q.empty()){
        long long w;
        pair<int, int> e;
        tie(w, e) = q.top();
        q.pop();
        if(!visited[e.second]){
            visited[e.second] = true;
            for(auto [w2, v] : g[e.second]){
                q.push(make_pair(-w2, make_pair(e.second, v)));
            }
            s += -w;
            edges ++;
        }
    }
    respuestas.push_back(s);
}
// ---------------------- // prim funciona bien

bool comparacion(int a, int b){
    return costo(0,a) <= costo(0,b);
}
// ---------------------- // comparacion funciona bien
int main()
{
    // capturamos #casos
    int casos;
    cin >> casos;

    while (casos != 0)
    {
        // capturamos # locks
        int cant_locks;
        cin >> cant_locks;

        // capturamos las locks en un vector
        vector<int> locks;

        for (int i = 0; i < cant_locks; i++)
        {
            // declaro, capturo y pusheo
            int lock; cin >> lock; locks.push_back(lock);
        }

        // creamos la lista de adyacencia con pesos 
        vector<vector<pair<long long, int>>> grafo (10005);

        // 0000 es el primer caso y es particular : queremos el minimo al principio
        sort(locks.begin(),locks.end(),comparacion);
        grafo[0].push_back(make_pair(costo(0, locks[0]),locks[0])); 
        grafo[locks[0]].push_back(make_pair(costo(0, locks[0]),0));

        // que pasa con las otras locks?
        for (int m = 0; m < cant_locks; m++)
        {   
            // para cada lock queremos calcularle la arista
            for (int k = 0; k < cant_locks; k++)
            {
                if (m != k)
                {
                    // para todo vertice distinto de si :
                    // queremos que en la lista de adyacencias en la posicion que le corresponde
                    // agregar la arista con su peso
                    grafo[locks[m]].push_back(make_pair(costo(locks[m], locks[k]), locks[k]));
                }
            }
        }
        // ------------------------------------------ // hasta aca va bien
        
        casos--;
    }
    
    return 0;
}

        
// // deberia tener lista mi lista de adyacencia, veamos
// for (int i = 0; i < grafo[0].size(); i++)
// {
//      cout << grafo[0][i].first << " " << grafo[0][i].second << endl; 
//      cout << grafo[1155][i].first << " " << grafo[1155][i].second << endl; 
//      cout << grafo[2211][i].first << " " << grafo[2211][i].second << endl; 
// }