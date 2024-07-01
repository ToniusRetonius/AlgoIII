#include <bits/stdc++.h>

using namespace std;

using ll = long long;
const ll inf = 1e18;

int n, m;
vector<vector<pair<ll, int>>> g;

void prim_m_lg_n(){
    priority_queue<pair<ll, pair<int, int>>> q;
    vector<bool> visited(n, false);

    for(auto [w, v] : g[0]){
        q.push(make_pair(-w, make_pair(0, v)));
    }

    visited[0] = true;
    int edges = 0;
    ll s = 0;
    while(!q.empty()){
        ll w;
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
    if(edges == n-1){
        cout << s << endl;
    } else {
        cout << "IMPOSSIBLE" << endl;
    }
}

int main() {
    cin>>n>>m;
    
    g = vector<vector<pair<ll,int>>>(n);

    for(int i = 0; i < m; i++){
        int u,v; ll c;
        cin>>u>>v>>c;
        u--, v--;
        g[v].push_back({c,u});
        g[u].push_back({c,v});
    }
    prim_m_lg_n();
    return 0;
}