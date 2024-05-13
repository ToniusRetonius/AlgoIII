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

    if (tam_ab != tam_ba)
    {
        cambios = -1;
    }

    if (tam_ab == tam_ba)
    {
        if (tam_ab == 1)
        {
            impar_ab = ab[ab.size() - 1];
            impar_ba = ba[ba.size() - 1];
            ab.pop_back();
            ba.pop_back();
            cambios = 2;
        }

        int tam_ab = ab.size() % 2;
        if (tam_ab == 0 && ab.size() > 0)
        {
            ab.insert(ab.end(), ba.begin(), ba.end());
            if (impar_ab != 0)
            {
                ab.push_back(impar_ab);
                ab.push_back(impar_ab);

                ab.push_back(impar_ab);
                ab.push_back(impar_ba);
                impar_ab = 0;
                impar_ba = 0;
            }
            cambios = ab.size() / 2 ;
        }
        if (impar_ab != 0)
        {
            ab.push_back(impar_ab);
            ab.push_back(impar_ab);

            ab.push_back(impar_ab);
            ab.push_back(impar_ba);
        }
    }

    if (cambios == 0 || cambios == -1)
    {
        cout << cambios << endl;
    }
    else
    {
        cout << cambios << endl;
        for (int i = 0; i < ab.size() - 1; i += 2)
        {
            cout << ab[i] << " " << ab[i + 1]<< endl;
        }
    }
    return 0;
}

