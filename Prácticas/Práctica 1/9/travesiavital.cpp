#include <bits/stdc++.h>
using namespace std;

// la idea : EL NIVEL DE VIDA NECESARIO PARA LA CASILLA ACTUAL DEBE GARANTIZAR QUE AL MOVERNOS A LA SIGUIENTE CON EL VALOR ACTUAL NO CAIGA POR DEBAJO DE 1

int travesia(vector<vector<int>>& matriz, vector<vector<int>>& resultados, int i, int j){
    // finaliza
    if (i >= 3 || j >= 3)
    {
        // infinito
        return INT_MAX;
    }
    
    // última casilla
    if (i == 2 && j == 2)
    {
        return max(1, 1 - matriz[i][j]);
    }
    
    // si ya lo calculamos ... 
    if (resultados[i][j] != -1)
    {
        return resultados[i][j];
    }

    // nos movemos
    int derecha = travesia(matriz, resultados, i, j + 1);
    int izquierda = travesia(matriz, resultados, i + 1, j);

    // por enunciado b) 
    resultados[i][j] = max(1, min(derecha, izquierda) - matriz[i][j]);

    return resultados[i][j];
    
}

int main(){
    // matriz
    vector<vector<int>> matriz =
    {
        {-2, -3, 3},
        {-5, -10, 1},
        {10, 30, -5}
    };
    
    // inicializada con todo en -1
    vector<vector<int>> resultados(3, vector<int>(3, -1));

    // queremos el resultado de arrancar en [0][0]
    int res = travesia(matriz, resultados, 0, 0);

    // imprimimos
    cout << "Nivel de vida mínimo " << res << endl;

    return 0;
}