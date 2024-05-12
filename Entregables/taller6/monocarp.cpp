#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

int main()
{
    /* definimos las var a CAPTURAR */
    int n;
    string s;
    string t;

    /* capturamos */
    cin >> n;
    cin >> s;
    cin >> t;

    /* vectores de diferencias */
    vector<int> ba;
    vector<int> ab;
    vector<int> impares;

    /* resultados */
    int cambios = 0;
    vector<tuple<int,int>> res;

    for (int i = 0; i < n; i++)
    {
        if (s[i] != t[i])
        {
            if (s[i] == 'a')
            {
                ab.push_back(i + 1);
            }
            else
            {
                ba.push_back(i + 1);
            }            
        }
    }
    
    /* ya tenemos los vectores de diferencias */
    int tam_ab = ab.size() % 2;
    int tam_ba = ba.size() % 2;

    /* caso longitudes impar */
    if (tam_ab == 1 && tam_ba == 1)
    {   
        
    }
    
    /* caso longitudes par */
    if (tam_ab == 0 && tam_ba == 0)
    {   
        /* tomamos los valores de ab de a 2 y los ubicamos en res */
        for (int i = 0; i < ab.size() - 1; i++)
        {
            res.emplace_back(ab[i], ab[i + 1]);
        }

        /* tomamos los valores de ba de a 2 y los ubicamos en res */
        for (int i = 0; i < ba.size() - 1; i++)
        {
            res.emplace_back(ba[i], ba[i + 1]);
        }
    }

    return 0;
}

