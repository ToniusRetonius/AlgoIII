#include <iostream>
#include <vector>
#include <string>
#include <climits>

using namespace std;

struct Arista {
    int nodo_a, nodo_b, peso;
    Arista(int a, int b, int p) : nodo_a(a), nodo_b(b), peso(p) {}
};

bool pertenece (Arista a, vector<Arista> grafo){
    for (int i = 0; i < grafo.size(); i++)
    {
        if (grafo[i].nodo_a == a.nodo_a  && grafo[i].nodo_b == a.nodo_b || grafo[i].nodo_a == a.nodo_b  && grafo[i].nodo_b == a.nodo_a)
        {
            return true;
        }
    }
    return false;
}

Arista costo_min (Arista a, vector<Arista> grafo){
    for (int i = 0; i < grafo.size(); i++)
    {
        if (grafo[i].nodo_a == a.nodo_a)
        {
            
        }
           
    }
    
}

int costo (int a, int b){
    // los paso a str para poder indexar y ver la long
    string a_str = to_string(a); 
    string b_str = to_string(b);

    int a_len = a_str.size();
    int b_len = b_str.size();

    int costo = 0;

    if (a_len == b_len)
    {
        for (int i = 0; i < a_len; i++)
        {
            int a_i = a_str[i];
            int b_i = b_str[i];
            costo += abs(a_i - b_i);
        }
    }
    if (a_len > b_len)
    {   
        // calcula para la #digitos en comun
        for (int i = 0; i < b_len; i++)
        {
            int a_i = a_str[i];
            int b_i = b_str[i];
            costo += abs(a_i - b_i);
        }
        // calcula para los que no son comunes a ambos
        for (int j = b_len; j < a_len; j++)
        {
            // conversion a int 
            int a_j = a_str[j] - '0';
            costo += a_j;
        }
    }
    if (a_len < b_len)
    {   
        // calcula para la #digitos en comun
        for (int i = 0; i < a_len; i++)
        {
            int a_i = a_str[i];
            int b_i = b_str[i];
            costo += abs(a_i - b_i);
        }
        // calcula para los que no son comunes a ambos
        for (int j = a_len; j < b_len; j++)
        {
            // conversion a int (esto es por el ASCII)
            int b_j = b_str[j] - '0';
            costo += b_j;
        }
    }
    return costo;
}

int main()
{   
    /* capturamos input */
    int casos; 
    cin >> casos;
    
    vector<long long> resultados;

    while (casos != 0)
    {
    
        // grafo pesado 
        vector<Arista> grafo;
        
        // capturamos la linea 
        int cant_locks;
        cin >> cant_locks;

        vector<int> locks;

        // agregamos el 0000
        locks.push_back(0);

        // agregamos las que faltan al array
        for (int j = 0; j < cant_locks; j++)
        {
            int lock;
            cin >> lock;
            locks.push_back(lock);
        }

        // tenemos que armarnos el grafo pesado
        for (int i = 0; i < locks.size(); i++)
        {
            for (int m = 0; m < locks.size(); i++)
            {
                if (i != m)
                {   
                    // instanciamos la arista
                    Arista arista = Arista(locks[i], locks[m],costo(locks[i], locks[m]));
                    // la pusheamos
                    grafo.push_back(arista);
                }
            }   
        }
        // ahora que tenemos el grafo completo (todos sus vertices estan conectados entre si)
        // tenemos que definir el AGM 
        // Algoritmo de Prim
        
        // inicializamos el AGM
        vector<Arista> AGM;

        // partimos de aquella de menor peso
        Arista min = grafo[0];
        for (int i = 1; i < grafo.size(); i++)
        {
            if (min.peso > grafo[i].peso)
            {
                min = grafo[i];
            }
        }
        // primer arista (nodo_a, nodo_b, peso)
        AGM.push_back(min);
        // mientras queden vertices, seguimos
        for (int i = 0; i < grafo.size(); i++)
        {
            // si la arista no esta en agm
            if (!pertenece(grafo[i], AGM))
            {   
                // buscamos la minima 
                Arista min = grafo[i];
                // encontra aquel nodo con el que se conecta que sea minimo el costo
                for (int n = 0; n < grafo.size(); n++)
                {
                    if (min.peso > grafo[n].peso)
                    {
                        min = grafo[n];
                    }
                    AGM.push_back(min);
                }
            }
            
        }
        
        
        // la idea es ir tomando las aristas de menor peso y agregarlas en cada paso
        // obtenemos el vector<Aristas> que es AGM
        // recorremos y sumamos el peso 
        // pusheamos res a resultados
    }

    // printeamos los resultados
    for (int l = 0; l < resultados.size(); l++)
    {
       cout << resultados[l] << endl;
    }
    
    return 0;
}

