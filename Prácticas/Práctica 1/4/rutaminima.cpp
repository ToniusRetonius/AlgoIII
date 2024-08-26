#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<vector<int>> permutar(const vector<int>& conjunto) {
    vector<vector<int>> permutaciones;
    vector<int> temp = conjunto; 

    // Ordenamos el conjunto para asegurar que next_permutation funcione correctamente
    sort(temp.begin(), temp.end());

    // Generamos todas las permutaciones
    do {
        permutaciones.push_back(temp);
    }
    while (next_permutation(temp.begin(), temp.end()));

    return permutaciones;
}

void rutaminima(vector<vector<int>>& matriz, vector<vector<int>>& permutaciones){
    
}


int main() {
    // Conjunto
    vector<int> conjunto = {1, 2, 3, 4};

    // Llamamos a la función 
    vector<vector<int>> permutaciones = permutar(conjunto);

    for (int i = 0; i < permutaciones.size(); i++)
    {
        for (int j = 0; j < permutaciones[i].size(); j++)
        {
            cout << permutaciones[i][j] << " ";
        }
        cout << endl;
    }

    // las tenemos en nuestra poseción, ahora con la matriz
    vector<vector<int>> matriz = {
        {0, 1, 10, 10},
        {10, 0, 3, 15},
        {21, 17, 0, 2},
        {3, 22, 30, 0}
    };

    


    return 0;
}
