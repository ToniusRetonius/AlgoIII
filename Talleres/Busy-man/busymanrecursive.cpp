#include <bits/stdc++.h>
using namespace std;

// la idea de este va bien, pero TIME LIMIT EXCEEDED
// RECURSIVE


bool criterio(tuple<int,int> a,tuple<int,int> b){ 
    return get<1>(a) < get<1>(b); 
}

int busyman(vector<tuple<int, int>>& actividades, int indice, int final){
    // si me paso
    if (indice == actividades.size())
    {
        return 0;
    }

    // no lo agregp
    int no_agrego = busyman(actividades, indice + 1, final);

    // lo agrego <==> el tiempo de inicio del actual es mayor al tiempo de finalización del anterior
    int agrego = 0;
    tuple<int, int> actual = actividades[indice];
    if (get<0>(actual) >= final)
    {
        // sumo 1 porque lo agrego, y el nuevo final es el que marca este que agregué
        agrego = 1 + busyman(actividades, indice + 1, get<1>(actual));
    }

    // queremos el maximo entre agregarlo y no agregarlo
    return max(no_agrego, agrego);
}

int main()
{
    // primero capturamos #cantidad de casos
    int cant_casos;
    cin >> cant_casos;

    // 
    vector<int> resultados;
    while (cant_casos > 0)
    {   
        // después tenemos #cantidad de actividades
        int cant_actividades;
        cin >> cant_actividades;

        // declaramos el vector de tuplas que tiene las actividades con sus tiempos asociados
        vector<tuple<int, int>> actividades(cant_actividades);

        // y después en base a este último, capturamos cada actividad con su inicio y fin asociado
        for (int j = 0; j < cant_actividades; j++)
        {
            int inicio, fin;
            cin >> inicio >> fin;
            actividades[j] = make_tuple(inicio, fin);
        }

        // ordenamos
        sort(actividades.begin(), actividades.end(), criterio);

        // capturamos el resultado
        int resultado = busyman(actividades, 0, -1);

        // 
        resultados.push_back(resultado);
        // restamos 
        cant_casos--;
    }

    // imprimimos
    for (int i = 0; i < resultados.size(); i++)
    {
        cout << resultados[i] << endl;
    }
    

    return 0;
}


