#include <bits/stdc++.h>
using namespace std;

// el tema de esta implementación es el segfault porque los valores de N < 201
// pero los de xi < 1e7
// esto nos presenta un problema en nuestro código cuando implementamos una matriz porque imaginate que el último negro en 1e5 tendríamos que tener una matriz absurdamente grande
// para resolver esto, en vez de pasar el VALOR del último negro o blanco pintado en la secuencia, simplemente le pasamos el índice donde está el dato

int matriz[205][205][205];

int bow(int i, int i_negro, int i_blanco, vector<int>& vector){
    // caso base : no hay más elementos en el vector
    if (i == vector.size())
    {
        return 0;
    }

    // si el resultado está en la matriz...
    if (matriz[i][i_negro][i_blanco] != -1)
    {
        return matriz[i][i_negro][i_blanco];
    }

    // caso recursivo 1 : actual mayor al valor indexado negro y mayor igual al valor indexado blanco
    if(vector[i] > vector[i_negro] && vector[i] >= vector[i_blanco]){
        // comparamos con no pintar a pintar de negro al actual ( fijarse que en mi versión sin PD le pasábamos el valor := vector[i] , ahora sólo el índice)
        return matriz[i][i_negro][i_blanco] = min(1 + bow(i+1, i_negro, i_blanco, vector), bow(i+1,i, i_blanco, vector));
    }
    // caso recursivo 2 : actual menor al blanco y menor igual al negro
    if (vector[i] < vector[i_blanco] && vector[i] <= vector[i_negro])
    {
        // comparamos con no pintar de blanco y pintar de blanco al actual
        return matriz[i][i_negro][i_blanco] = min(1 + bow(i+1, i_negro, i_blanco, vector), bow(i+1, i_negro, i, vector));
    }
    // caso recursivo 3 : puedo pintar de ambos
    if (vector[i] < vector[i_blanco] && vector[i] > vector[i_negro])
    {
        // comparamos con no pintar al minimo de pintarlo de alguno de los dos colores
        return matriz[i][i_negro][i_blanco] = min(1 + bow(i+1, i_negro, i_blanco, vector), min(bow(i+1, i_negro, i, vector), bow(i+1, i, i_blanco, vector)));
    }
    // caso 4 : no nos queda otra que no pintarlo
    else {
        return matriz[i][i_negro][i_blanco] = 1 + bow(i+1, i_negro, i_blanco, vector);
    }
}


int main(){

    int N;
    cin >> N;

    vector<int> resultados;

    while (N != -1)
    {
        vector<int> vector(N+2);

        for (int i = 0; i < N; i++)
        {
            cin >> vector[i];
        }

        // inicializamos en -1 la matriz
        memset(matriz, -1, sizeof(matriz));
        
        // le hardcodeamos los valores que hacen que funque como en nuestra versión anterior
        vector[N] = 1000005;
        vector[N+1] = -1;

        // capturamos res 
        int res = bow(0, N+1, N, vector);
        resultados.push_back(res);

        cin >> N;
    }

    // acá imprimimos los resultados
    for (int i = 0; i < resultados.size(); i++)
    {
        cout << resultados[i] << endl;
    }
    
    return 0;
}