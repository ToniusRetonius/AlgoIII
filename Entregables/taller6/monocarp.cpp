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
    int impar_ab = 0;
    int impar_ba = 0; 

    /* resultados */
    int cambios;
    vector<int> res;

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
    
    /* si son des distinto tam las diferencias */
    if (ab.size() % 2 != ba.size() % 2)
    { 
       cout << -1 << endl;
       return 0;
    }

    /* si son iguales los string */
    if (ab.size() == 0 && ba.size() == 0)
    {   
        return 0;
    }

    /* ya tenemos los vectores de diferencias y son no nulos */
    int tam_ab = ab.size() % 2;
    int tam_ba = ba.size() % 2;

    if (tam_ab == tam_ba)
    {   
        /* caso vectores impares */
        if (tam_ab == 1)
        {
            impar_ab = ab[0];
            impar_ba = ba[0];
            
            ab.erase(ab.begin());
            ba.erase(ba.begin());
            
            res.push_back(impar_ab);
            res.push_back(impar_ab);
            res.push_back(impar_ab);
            res.push_back(impar_ba);
        }

        /* caso vectores pares */
        int tam_ab = ab.size() % 2;
        if (tam_ab == 0 && ab.size() > 1)
        {   
            /* juntamos ab con ba y... en caso de res ser != null, anexamos ab total a res */
            ab.insert(ab.end(), ba.begin(), ba.end());
            res.insert(res.end(), ab.begin(), ab.end());
        }
    }


    cambios = res.size() / 2;
    cout << cambios << endl;
    for (int i = 0; i < res.size() - 1; i += 2)
    {
        cout << res[i] << " " << res[i + 1]<< endl;
    }
    
    return 0;
}

