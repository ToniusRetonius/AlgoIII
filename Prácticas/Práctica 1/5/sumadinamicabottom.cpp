#include <bits/stdc++.h>
using namespace std;

bool existesuma(vector<int>& conjunto, int& suma, int& tam){
    // inicializamos la matriz
    bool matriz [tam + 1][suma + 1];
    // 1 - con 0 se puede sumar 0
    matriz[0][0] = true;

    //  2 - con 0 elementos no podemos sumar nada
    for (int j = 1; j <= suma; j++) {
        matriz[0][j] = false;
    }
    
    // 3 - resolverla
    for (int i = 1; i <= tam; i++)
    {
        for (int j = 0; j <= suma; j++)
        {
            matriz[i][j] = ((matriz[i-1][j]) || ((j - conjunto[i] >= 0) && matriz[i-1][j-conjunto[i]]));
        }
        
    }
    // 4 -  la devolvemos completa
    return matriz[tam][suma];
}

int main()
{
    vector<int> conjunto = {1,2,3,4,5,6,7,8,9};
    int tam = conjunto.size();
    int suma = 10;
    bool res = existesuma(conjunto, suma , tam);

    const char* resultado = (res == true) ? "VERDADERO" : "FALSO"; 

    cout << "Se puede sumar " << suma << endl;
    cout << "La respuesta es " << resultado << endl; 


    return 0;
}
