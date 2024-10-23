#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// se define el tamaño para el array de representantes
const int MAX = 1e6-1;
int representantes[MAX];

// se define la estructura de datos de la forma < costo, <vertice a, vertice b> >
const int vertices = 4, aristas = 5;
pair <long long, pair<int, int> > arista[MAX];

// estructura para almacenar el AGM
vector<pair<long long, pair<int, int>>> agm;

// función find para encontrar al representante de la componente conexa
int encontrar_representante(int a)                                                       
{
    while(representantes[a] != a)
    {
        representantes[a] = representantes[representantes[a]];
        a = representantes[a];
    }
    return a;
}

// la función union lo que hace es asignar a ambos el mismo representante de la componente
void unir(int a, int b)                                     
{
    int d = encontrar_representante(a);
    int e = encontrar_representante(b);
    representantes[d] = e;
}

long long kruskal()
{
    int a, b;
    long long costo, costo_min = 0;

    // para cada arista ( del conjunto de las aristas ordenadas ascendentemente por costo)
    for(int i = 0 ; i < aristas ; ++i)
    {
        a = arista[i].second.first;
        b = arista[i].second.second;
        costo = arista[i].first;

        // si estǽn en diferentes componentes conexas ==>
        if(encontrar_representante(a) != encontrar_representante(b))                                  
        {
            // le sumo el costo
            costo_min += costo;
            // unimos componentes
            unir(a, b);
            // pusheamos la arista al AGM
            agm.push_back({costo, {a,b}});
        }
    }
    return costo_min;
}

int main()
{
    int x, y;
    long long costo, costo_min;

    // cada vértice es su propio reprensentante inicialmente (cada uno es una componente conexa)
    for(int i = 0; i < MAX; i++)                                       
    {
        representantes[i] = i;
    }

    arista[0] = make_pair(10, make_pair(0, 1));
    arista[1] = make_pair(18, make_pair(1, 2));
    arista[2] = make_pair(13, make_pair(2, 3));
    arista[3] = make_pair(21, make_pair(0, 2));
    arista[4] = make_pair(22, make_pair(1, 3));

    // ordenamos las aristas
    sort(arista, arista + aristas);    

    // kruskal nos devuelve el min costo                                         
    costo_min = kruskal();

    cout << "Minimo costo: " << costo_min << endl;
    cout << "Aristas en el AGM:" << endl;

    // Imprimir las aristas del AGM
    for (const auto& edge : agm) {
        cout << "Costo: " << edge.first << " - Vertices: " << edge.second.first << " y " << edge.second.second << endl;
    }
    return 0;
}
// COMPLEJIDAD : O (|E| * LOG |V| + |E| * α(|V|)) es decir O(|E| * LOG |V|)