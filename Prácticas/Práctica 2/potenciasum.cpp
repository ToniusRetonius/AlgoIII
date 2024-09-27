#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> multiplicar_matrices(vector<vector<int>> a,vector<vector<int>> b){
    // devuelvo la matriz resultado de multiplicar a a x b
    vector<vector<int>> res(a.size(), vector<int> (a.size()));

    for (int i = 0; i < a.size(); i++)
    {
        for (int j = 0; j < a.size(); j++)
        {
            res[i][j] = 0;
            for (int k = 0; k < a.size(); k++)
            {
                res[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    return res;
}

vector<vector<int>> suma_matrices(vector<vector<int>> a,vector<vector<int>> b){
    // res es una matriz de a filas por a columnas (cuadrada)
    vector<vector<int>> res(a.size(), vector<int> (a.size()));

    for (int i = 0; i < a.size(); i++)
    {
        for (int j = 0; j < a.size(); j++)
        {
            // res es la suma de las componentes de a y b en ese lugar
            res[i][j] = a[i][j] + b[i][j];
        }
        
    }
    return res;
}


vector<vector<int>> potencia_sum(vector<vector<int>> a, int exponente){
    // caso base
    if (exponente == 1)
    {
        return a;
    }
    else
    {
        // exponente par
        if (exponente % 2 == 0)
        {
            return multiplicar_matrices(a, potencia_sum(a, exponente/2));
        }
        // exponente impar
        else
        {
            return multiplicar_matrices(a, multiplicar_matrices(a, potencia_sum(a, exponente/2)));
        }   
    }
}

void printM(const vector<vector<int>>& a) {
    for (const auto& fila : a) {
        for (int val : fila) {
            cout << val << " ";
        }
        cout << endl;
    }
}

int main(){
    int exp;
    cin >> exp;
    // matriz 4 x 4
    vector<vector<int>> A = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    }; 
    vector<vector<int>> res = {
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0}
    }; 
    
    // la idea está, me gustaría tener un array de matrices para ir guardando referencia a cada una calculada y luego sumarlas iterativamente
    vector<vector<vector<int>>> array_matrices(exp + 1, vector<vector<int>>(A.size(), vector<int>(A.size(), 0)));
    array_matrices[exp] = res; 

    // Sumar matrices iterativamente
    while (exp > 0) {
        array_matrices[exp - 1] = suma_matrices(array_matrices[exp], potencia_sum(A, exp));
        exp--;
    }

    printM(array_matrices[0]);
    return 0;
}