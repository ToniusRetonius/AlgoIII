#include <bits/stdc++.h>

using namespace std;

vector<long long> respuestas;

int rolls_bet_nums_aux(long long a, long long b){
    if(a == b){
        return 0;
    }

    long long menor = 0;
    long long mayor = 0;
    
    if(a < b){
        menor = a;
        mayor = b;
    } else{
        menor = b;
        mayor = a;
    }

    long long res = min((mayor - menor),((menor + 10) - mayor));
    return res;
}


long long costo(long long a, long long b){
    
    long long res = 0;
    for(int i = 0; i < 4; i++){
      long long numero_a = a % 10;
      long long numero_b = b % 10;
        res += rolls_bet_nums_aux(numero_a,numero_b);
        a = a/10;
        b = b/10;
    }
    return res;
}
// ---------------------------------------- // la funcion de costo va bien
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

bool comparacion(int a, int b){
    return costo(0,a) <= costo(0,b);
}

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
        vector<vector<pair<long long, int>>> grafo (10000);

        // el 0000 no es vertice por tanto el primer caso es a mano
        sort(locks.begin(),locks.end(),comparacion);
        grafo[0].push_back(make_pair(costo(0, locks[0]),locks[0]));  // agrego al grafo las aristas
        grafo[locks[0]].push_back(make_pair(costo(0, locks[0]),0));

        // que pasa con las otras locks?
        for(int j = 0; j < locks.size();j++){ // ahora agrego las restantes
            for(int k = 0; k < j; k++){
               int cost = costo(locks[k], locks[j]);
               grafo[locks[j]].push_back(make_pair(cost,locks[k])); 
               grafo[locks[k]].push_back(make_pair(cost,locks[j])); 
            }
        }
        // ------------------------------------------ // hasta aca va bien
        prim_m_lg_n(cant_locks, grafo);
        casos--;
    }

    for (int i = 0; i < respuestas.size(); i++)
    {
        cout << respuestas[i] << endl;    
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