#include <bits/stdc++.h>
using namespace std;

int bow(int i, int negro, int blanco, vector<int>& vector){
    // caso base : no hay más elementos en el vector
    if (i == vector.size())
    {
        return 0;
    }
    // caso recursivo 1 : actual mayor al negro y mayor igual al blanco
    if(vector[i] > negro && vector[i] >= blanco){
        // comparamos con no pintar a pintar de negro al actual
        return min(1 + bow(i+1, negro, blanco, vector), bow(i+1,vector[i], blanco, vector));
    }
    // caso recursivo 2 : actual menor al blanco y menor igual al negro
    if (vector[i] < blanco && vector[i] <= negro)
    {
        // comparamos con no pintar de blanco y pintar de blanco al actual
        return min(1 + bow(i+1, negro, blanco, vector), bow(i+1, negro, vector[i], vector));
    }
    // caso recursivo 3 : puedo pintar de ambos
    if (vector[i] < blanco && vector[i] > negro)
    {
        // comparamos con no pintar al minimo de pintarlo de alguno de los dos colores
        return min(1 + bow(i+1, negro, blanco, vector), min(bow(i+1, negro, vector[i], vector), bow(i+1,vector[i], blanco, vector)));
    }
    // caso 4 : no nos queda otra que no pintarlo
    else {
        return 1 + bow(i+1, negro, blanco, vector);
    }
}


int main(){

    int N;
    cin >> N;

    vector<int> resultados;

    while (N != -1)
    {
        vector<int> vector(N);

        for (int i = 0; i < N; i++)
        {
            cin >> vector[i];
        }

        // capturamos res
        // probando con algunos valores no funcionaba
        // con 1e9 y -1e9 va
        int res = bow(0,-1e9,1e9, vector);

        resultados.push_back(res);

        cin >> N;
    }

    // acá imprimimos los resultados
    for (int i = 0; i < resultados.size(); i++)
    {
        printf("Resultado del caso %i : %i\n", i, resultados[i]);
    }
    
    return 0;
}