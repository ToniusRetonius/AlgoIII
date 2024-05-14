#include <iostream>
#include <vector>

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
    vector<int> ab;
    vector<int> ba;

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
        cout << 0 << endl;
        return 0;
    }

    /* si es impar enchufamos el ult valor de ab a ambos */
    if (ab.size() % 2 == 1 )
    {
        int ult = ab.back();
        ab.push_back(ult);
        ba.push_back(ult);
    }
    
    for (int i = 0; i < ab.size(); i++)
    {
        res.push_back(ab[i]);
    }
    for (int i = 0; i < ba.size(); i++)
    {
        res.push_back(ba[i]);
    }

    /* print */
    cout <<  res.size() / 2 << endl;
    for (int i = 0; i < res.size(); i = i + 2)
    {
        cout << res[i] << ' ' << res[i + 1] << endl;
    }
    
    return 0;
}

