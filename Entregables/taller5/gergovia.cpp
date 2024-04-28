#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

class Gergovia
{
public:
    int habitantes;
    vector<int> demanda;
    int caso;

    /* constructor */
    gergovia(int h, vector<int> dem, int c)
    {
        habitantes = h;
        demanda = dem;
        caso = c;
    }

    /* metodo */
    int caminos(){
        int i = 0; 
        int j = 0;
        int suma = 0;

        int actual_i = 0;
        int actual_j = 0;

        while (i < demanda.size())
        {
            if (actual_i <= 0)
            {
                /* actualizo la lista original */
                demanda[i] = actual_i;
                /* avanzo en i */
                i++;
                /* redefino actual_i */
                if (i < demanda.size())
                {
                    actual_i = demanda[i];
                
                }
                
            }
            /* si es mayor a cero actual_i y estamos en rango */
            else if (actual_i > 0) 
            {
                while (j < demanda.size()) 
                {
                    if (actual_j >= 0)
                    {
                        /* actualizo la lista original */
                        demanda[j] = actual_j;
                        j++;
                        if (j < demanda.size())
                        {
                            /* redefino actual_j */
                            actual_j = demanda[j]
                        }                        
                    }
                    else{
                        suma += abs(j - i);
                        actual_i--;
                        actual_j++;
                        demanda[i] = actual_i;
                        demanda[j] = actual_j;
                    }
                    
                }
                
            }
            
        }
        return suma
        

    }
};

int main()
{
    /* capturamos data */
    int habitantes;
    cin >> habitantes;

    while (habitantes > 0)
    {
        /* capturo la linea */
        /* declaro demanda y le doy tama;o */
        vector<int> demanda(habitantes);

        for (int i = 0; i < habitantes; i++)
        {
            /* capturo la linea de numeritos */
            cin >> demanda[i];
        }

        /* construyo mi clase Gergovia */
        Gergovia gergovia(habitantes, demanda);

        /* aca va el print de la funcion que resuelve el problema */

        /* actualizamos habitantes */
        cin >> habitantes;
    }
    
    return 0;
}



