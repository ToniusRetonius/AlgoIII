#include <bits/stdc++.h>
using namespace std;

// solución programación dinámina

int pilacauta(vector<int>& pesos, vector<int>& soporte, int i, int carga){
    vector<int> resultados(pesos.size(), -1);
    if (resultados[i] == -1)
    { 
        if (i == pesos.size())
        {
            return 0;
        }
        if (carga <= 0)
        {
            return 0;
        }

        resultados[i] = max(pilacauta(pesos, soporte, i + 1, min(carga - pesos[i], soporte[i])) + 1, pilacauta(pesos, soporte, i + 1, carga));
    }
    return resultados[i];
}


int main(){

    // cajas : pesos
    vector<int> pesos = {19, 7, 5, 6, 1};

    // cajas : soporte
    vector<int> soporte = {15, 13, 7, 8, 2};

    int res = pilacauta(pesos, soporte, 0, 1000);
    
    cout << res << endl;

    return 0;
}