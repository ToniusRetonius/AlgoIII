class DisjointSet {
    vector<int> rank, parent;
public:
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        for(int i = 0; i < n + 1; i++){
            parent[i] = i;
        }
    }
 
    int findSet(int node){
 
        // En caso que nodo sea el representante
        if (node == parent[node]) return node;
 
        // Hago path compression
        return parent[node] = findSet(parent[node]);
    }
 
    void unionByRank(int u, int v) {
        int uRepresentative = findSet(u);
        int vRepresentative = findSet(v);
 
        // Si tienen el mismo representante, entonces pertenece al
        // mismo conjunto
        if (uRepresentative == vRepresentative) return;
 
        // Actualizamos el representante segun el caso del rank
        if (rank[uRepresentative] < rank[vRepresentative]) {
            parent[uRepresentative] = vRepresentative;
        } else if(rank[uRepresentative] > rank[vRepresentative]) {
            parent[vRepresentative] = uRepresentative;
        } else {
            parent[vRepresentative] = uRepresentative;
            rank[uRepresentative]++;
        }
    }
};
