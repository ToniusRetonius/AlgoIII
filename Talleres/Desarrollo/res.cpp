#include <bits/stdc++.h>
using namespace std;

// Globales
int V(500);
vector<vector<long long int>> matriz(500, vector<long long int>(500));
vector<int> cronologia(500);
vector<long long int> resultados;


int main() {
    // Capturamos la # esquinas (V)
    cin >> V;
    matriz.resize(V, vector<long long int>(V));

    // Armamos el digrafo como una matriz
    for (long long int i = 0; i < V; i++)
    {
        for (long long int j = 0; j < V; j++)
        {
            long long int dato; cin >> dato;
            matriz[i][j] = dato;
        }
        
    }
    cronologia.resize(V);

    // Nos falta capturar el orden inverso de creacion de esquinas
    for (long long int i = 0; i < V; i++)
    {
        int orden; cin >> orden;
        cronologia[i] = orden - 1;
    }
 
    // FW
    for(long long int k = V - 1; k >= 0; k--) 
    {
        long long int esquina = cronologia[k];
        for(long long int i = 0; i < V; i++) 
        {
            for(long long int j = 0; j < V; j++) 
            {
                matriz[i][j] = min(matriz[i][j], matriz[i][esquina] + matriz[esquina][j]);
            }
        }

        // sumatoria
        long long int res = 0;  
        for(long long int i = k; i < V; i++) 
        {
            for(long long int j = k; j < V; j++) 
            {
                res += matriz[cronologia[i]][cronologia[j]];
            }
        }
        resultados.push_back(res);  
    }

    // print inverso
    for(long long int i = V - 1; i >= 0; i--) 
    {
        cout << resultados[i] << " ";
    }
    cout << endl;

    return 0;
}
