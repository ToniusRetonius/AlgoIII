#include <bits/stdc++.h>
using namespace std;

void generar_subconjuntos(int indice, vector<int> conjunto ,vector<int>& subconjunto, vector<vector<int>>& subconjuntos, int k){
    
    // poda de optimalidad ya que sabemos que si el size es mayo nunca será óptimo del problema
    if (subconjunto.size() > k) return;
    
    // agregamos al subconjunto de size k al resultado
    else if (subconjunto.size() == k)
        {
            subconjuntos.push_back(subconjunto);
        }
    // si el subconjunto está en desarrollo ....
    else
    {   
        // para cada elemento del conj
        for (int i = indice; i < conjunto.size(); i++)
        {
            // agregamos el elemento en la posición i-ésima al subconjunto
            subconjunto.push_back(conjunto[i]);
            // iniciamos la recursión con él
            generar_subconjuntos(i + 1, conjunto, subconjunto, subconjuntos, k);
            
            // backtrack ( sin él )
            subconjunto.pop_back();
        }
    }
}

int maximiza(vector<vector<int>> matriz, vector<int> subconjuntomax){
    int max = 0;
    for (int i = 0; i < subconjuntomax.size(); i++)
    {
        for (int j = 0; j < subconjuntomax.size() && i != j; j++)
        {
            max += matriz[i][j];
        }
        
    }
    return max;
}

int main()
{
    vector<int> conjunto = { 1, 2, 3, 4 };
    vector<int> subconjunto;
    vector<vector<int>> res;
    generar_subconjuntos(0, conjunto, subconjunto, res, 3);

    vector<vector<int>> matriz = 
    {
        {0, 10, 10, 1},
        {10, 0, 5, 2},
        {10, 5, 0, 1},
        {1, 2, 1, 0},
    };
    
    int cant_conj = res.size();
    int maximo = 0;
    vector<int> conj_max;
    for (int i = 0; i < cant_conj; i++)
    {
        int max = maximiza(matriz,res[i]);
        if (maximo < max)
        {
            maximo = max;
            conj_max = res[i];
        }
    }

    // las soluciones candidatas son : 
    cout <<  "Las soluciones candidatas son :" << endl;
    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[i].size(); j++)
            cout << res[i][j] << " ";
        cout << endl;
    }

    // el óptimo es : 
    cout << "El óptimo es : ";
    for (int i = 0; i < conj_max.size(); i++)
    {
        cout << conj_max[i] << " ";
    }
    cout << endl;
    // y  maximiza :
    cout << "Y maximiza con :"  << maximo << endl;


    return 0;
}


