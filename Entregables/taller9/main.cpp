#include <iostream>
#include <vector>
#include <string>
#include <climits>
#include <queue>
#include <tuple>
#include <bits/stdc++.h>

using namespace std;

vector<long long> resultados;

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

bool compare(int a, int b){
    return costo(0,a) <= costo(0,b);
}

void prim_m_lg_n(int n, vector<vector<pair<long long,int>>> grafo){
    priority_queue<pair<long long, pair<int, int>>> cola;
    vector<bool> visitados(10005, false);

    for(auto [peso, v] : grafo[0]){
        cola.push(make_pair(-peso, make_pair(0, v)));
    }

    visitados[0] = true;
    int aristas = 0;
    long long suma = 0;

    while(!cola.empty()){
        long long peso;
        pair<int, int> arista;
        tie(peso, arista) = cola.top();
        cola.pop();
        if(!visitados[arista.second]){
            visitados[arista.second] = true;
            for(auto [peso2, v] : grafo[arista.second]){
                cola.push(make_pair(-peso2, make_pair(arista.second, v)));
            }
            suma += -peso;
            aristas ++;
        }
    }
    resultados.push_back(suma);
}

int main()
{
    /* capturamos input */
    int casos; 
    cin >> casos;
    
    while (casos != 0)
    {
        // capturamos la linea 
        int cant_locks;
        cin >> cant_locks;

        vector<int> locks;

        // agregamos las que faltan al array
        for (int j = 0; j < cant_locks; j++)
        {
            int lock;
            cin >> lock;
            locks.push_back(lock);
        }
        sort(locks.begin(),locks.end(),compare);
        // grafo pesado 
        vector<vector<pair<long long, int>>> grafo(10005);

        // costo entre 0000 y el primer elem 
        long long cost = costo(0000, locks[0]);
        
        // pusheamos al grafo las aristas de 0 y del numerito
        grafo[0].push_back(make_pair(cost, locks[0]));
        grafo[locks[0]].push_back(make_pair(cost, 0));

        // tenemos que armar el total del grafo ahora
        for (int i = 0; i < locks.size(); i++)
        {
            for (int m = 0; m < i; m++)
            {
                // costo
                cost = costo(locks[m], locks[i]);
                // asignamos valor al grafo
                grafo[locks[i]].push_back(make_pair(cost, locks[m]));
                grafo[locks[m]].push_back(make_pair(cost, locks[i]));
            }
            
        }
        // como ya tenemos el grafo pesado armado, es hora de conseguir el AGM
        prim_m_lg_n(cant_locks, grafo);

        casos--;
    }

    // printeamos los resultados
    for (int l = 0; l < resultados.size(); l++)
    {
       cout << resultados[l] << endl;
    }
    return 0;
}
