#include <bits/stdc++.h>
using namespace std;

// la implementación anterior nos da time limit exceeded, entonces la solución es mejorar la búsqueda.
// pasamos de la búsqueda lineal a la binaria

bool existe_distancia(vector<int>& slots, int distancia, int vacas){
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
            // si ya asignamos todas las vacas es porque se puede lograr poner a las vacas con distancia "distancia"
            if (asignadas >= vacas)
            {
                return true;
            }
        }
        i++;
    }

    // si llegamos hasta acá, no es posible
    return false;
}


int cows (vector<int>& slots, int vacas){
    int indice = slots.size() - 1;
    int dist_min = 1;
    int dist_max = slots[indice] - slots[0];
    int res = 0;

    // acǽ se implementa la búsqueda binaria
    // mientras la distancia mínima sea menor a la mǽxima existente entre dos slots ... 
    while (dist_min <= dist_max)
    {
        // distancia_media
        int dist_media = dist_min + (dist_max - dist_min) / 2;

        // chequeamos si se puede poner a las vacas en dicha distancia
        if (existe_distancia(slots, dist_media, vacas))
        {
            // si se puede .. joya, tal vez se pueda un numerito mǽs
            res = dist_media;
            dist_min = dist_media + 1;
        } else
        {
            // si no pudimos asignar las C vacas en la distancia pretendida :
            // buscamos si se puede en alguna distancia menor
            dist_max = dist_media - 1;
        }
    }
    

    return res;
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

        sort(slots.begin(), slots.end());
        
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