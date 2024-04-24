#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

class Gergovia
{
public:
    int habitantes;
    vector<int> demanda;

    /* constructor */
    gergovia(int h, vector<int> dem)
    {
        habitantes = h;
        demanda = dem;
    }

    /* metodo */
    int caminos(){
        int i = 0; 
        int j = 0;
        int suma = 0;

        int actual_i = 0;
        int actual_j = 0;

        while (i < habitantes)
        {
            if (actual_i >= 0)
            {
                /* actualizo la lista original */
                demanda[i] = actual_i;
                /* avanzo en i */
                i++;
                /* redefino actual_i */
                actual_i = demanda[i];
            }
            else
            {
                while (j < habitantes && actual_j <= 0 ) 
                {
                    if (actual_j <= 0)
                    {
                        /* actualizo la lista original */
                        demanda[j] = actual_j;
                        if (actual_j == 0)
                        {
                            /* avanzo */
                            j++;
                            /* redefino actual_j */
                            actual_j = demanda[j]
                        }
                        
                        
                    }
                    
                }
                
            }
            
        }
        

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



