#include <bits/stdc++.h>
using namespace std;

// la idea de este va bien, pero TIME LIMIT EXCEEDED
// BOTTOM UP


bool criterio(tuple<int,int> a,tuple<int,int> b){ 
    return get<1>(a) < get<1>(b); 
}

int busyman(vector<tuple<int, int>>& actividades){
    //
    int cant_actividades = actividades.size();
    // inicializamos estructura toda en 1 pues como mínimo hacemos 1 cosa
    vector<int> estructura(cant_actividades, 1);

    // cómo la completamos ?
    for (int i = 1; i < cant_actividades; i++)
    {
        tuple<int, int> actual = actividades[i];
        for (int j = 0; j < i; j++)
        {
            tuple<int, int> previa = actividades[j];
            // si el inicio de la que queremos agregar no se superpone ...
            if (get<0>(actual) >= get<1>(previa))
            {
                estructura[i] = max(estructura[i], 1 + estructura[j]);
            }
        } 
    }
    // una vez completa la estructura le tenemos que tomar el mǽximo
    int max = 1;
    for (int i = 0; i < estructura.size(); i++)
    {
        if (max < estructura[i])
        {
            max = estructura[i];
        }
    }
    
    return max;
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

        // 
        int resultado = busyman(actividades);
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
