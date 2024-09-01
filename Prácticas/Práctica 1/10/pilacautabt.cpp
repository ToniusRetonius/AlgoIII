#include <bits/stdc++.h>
using namespace std;

// solución bactracking

void pilacauta(vector<int>& pesos, vector<int>& soporte, int i,int soportado, vector<vector<int>>& resultados, vector<int> res){
    // finaliza si
    if (i == pesos.size())
    {
        resultados.push_back(res);
        return;
    }

    // si me quedo sin capacidad para sostener
    if (soportado == 0)
    {
        resultados.push_back(res);
        return;
    }
    
    // no agregamos al elemento

    // para el primer caso es particular al agregarlo
    if (i == 0)
    {
        res.push_back(i + 1);
        pilacauta(pesos, soporte, i + 1, soporte[i], resultados, res);
        res.pop_back();
    }


    else
    {
        pilacauta(pesos, soporte, i+1, soportado, resultados, res);
        // si agrego la caja, es porque la pila se la banca
        if (soportado - pesos[i] >= 0)
        {
            soportado -= pesos[i];
            // agrego esta caja al resultado
            res.push_back(i + 1);
            // actualizo soportado con el mínimo entre el que tengo, o el de la próxima caja
            soportado = min(soportado, soporte[i]);
            // recursión
            pilacauta(pesos, soporte, i+1, soportado, resultados, res);
            // 
            res.pop_back();
        }
        
    }
}


int main(){

    // cajas : pesos
    vector<int> pesos = {19, 7, 5, 6, 1};

    // cajas : soporte
    vector<int> soporte = {15, 13, 7, 8, 2};

    vector<vector<int>> resultados;
    vector<int> res;

    pilacauta(pesos, soporte, 0, 15, resultados, res);

    int max_len = 0;
    cout <<  "Las soluciones óptimas son :" << endl;
    for (int i = 0; i < resultados.size(); i++) {
        if (max_len < resultados[i].size())
        {
            max_len = resultados[i].size();
        }
    }
    for (int i = 0; i < resultados.size(); i++) {
        if (resultados[i].size() == max_len)
        {
            for (int j = 0; j < resultados[i].size(); j++)
                cout << resultados[i][j] << " ";
            cout << endl;
        }
    }
    
    return 0;
}