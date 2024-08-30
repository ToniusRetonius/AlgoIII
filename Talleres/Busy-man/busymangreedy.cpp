#include <bits/stdc++.h>
using namespace std;

// estilo GREEDY

bool criterio(tuple<int,int> a,tuple<int,int> b){ 
    return get<1>(a) < get<1>(b); 
}

int busyman(vector<tuple<int, int>> actividades){
    int res = 0;
    int f = -1;

    for (int i = 0; i < actividades.size(); i++)
    {
        int inicio = get<0>(actividades[i]);
        int fin = get<1>(actividades[i]);
        if (inicio >= f)
        {
            f = fin;
            res++;
        }
        
    }
    return res;
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

        int resultado = busyman(actividades);

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
