#include <bits/stdc++.h>

using namespace std;

// en este ejecicio tenemos que implementar una función que nos diga si un arreglo de tamaño potencia de 2 suma mǽs del lado izquierdo o si no.

bool izqdom(vector<int> vec, int inicio, int fin){

    // cuándo termina la recursión?
    // un solo elemento en el array [2] inicio = 0 y fin = 1 porque hay un elemento en el arreglo
    if (fin == inicio + 1)
    {
        return true;
    }else
    {
        // cuánto suma izq y cuǽnto derecha?
        int izq = 0;
        int der = 0;
        // en qué rango
        int rango = (fin - inicio) / 2;

        // sumamos a la izq
        for (int i = inicio; i < inicio + rango; i++)
        {
            izq += vec[i];
        }
        // sumamos a la derecha
        for (int i = rango; i < fin; i++)
        {
            der += vec[i];
        }
        
        // recursión
        int res = izqdom(vec, inicio, inicio + rango) && izqdom(vec, inicio + rango, fin);

        // es mayor entonces ?
        return izq > der && res;
        
    }
    
    
}

int main()
{   
    // pedimo una cantidad de números 
    int n;
    cin >> n;

    // me guardo los nros en un vector
    vector<int> vector(n);
    for (int i = 0; i < n; i++)
    {
        cin >> vector[i];
    }

    // acǽ llamo a la función
    bool res = izqdom(vector, 0, n);
    
    if (res)
    {
        cout << "Verdadero" << endl;
    }else
    {
        cout << "Falso" << endl;
    }
    
    
    return 0;
}
