#include <bits/stdc++.h>
using namespace std;

// esta función nos dice si para la distancia i se pueden poner las C vacas
bool sepuede(vector<int>& slots, int distancia, int vacas){
    int actual = slots[0];
    int i = 1;
    // actual está asignada
    int asignadas = 1;

    while (i < slots.size())
    {   
        // si la distancia de poner la vaca en el actual con algún otro valor cumple con el pedido de distancia
        if (slots[i] - actual >= distancia)
        {
            // actual es donde tengo una vaca ( si se cumple la distancia, reasigno)
            actual = slots[i];
            asignadas++;
        }
        i++;
    }
    // si ya asignamos todas las vacas es porque se puede lograr poner a las vacas con distancia "distancia"
    if (asignadas >= vacas)
    {
        return true;
    }

    // si llegamos hasta acá, no es posible
    return false;
}


int cows (vector<int>& slots, int vacas){
    int distancia = 0;
    int indice = slots.size() - 1;
    int max_dist = slots[indice] - slots[0];

    // vamos a chequear si se puede mantener la distancia i
    for (int i = 1; i <= max_dist; i++)
    {
        // si se puede poner las vacas con distancia i ... actualizamos distancia
        if(sepuede(slots, i, vacas)){
            distancia = i;
        }
    }
    return distancia;
}



bool criterio(int a, int b){
    return a < b;
}

int main(){
    int t, N, C;
    cin >> t;

    vector<int> resultados;

    while (t > 0)
    {
        cin >> N;
        cin >> C;

        vector<int> slots; 

        for (int j = 0; j < N; j++)
        {
            int slot;
            cin >> slot;
            slots.push_back(slot);
        }

        sort(slots.begin(), slots.end(), criterio);
        
        int res = cows(slots, C);

        resultados.push_back(res);

        t--;    
    }
    

    // imprimimos resultados
    for (int i = 0; i < resultados.size(); i++)
    {
        printf("%d\n", resultados[i]);
    }

    return 0;
}