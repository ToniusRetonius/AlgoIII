#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{   
    /* input r : rooms , d : door, s : switches */
    int r, d, s;
    cin >> r >> d >> s;

    /* grafo */
    vector<vector<int>> habitaciones(d, vector<int>(0));
    vector<vector<int>> luces(s, vector<int>(0));

    /* res : si tiene un vacio es porq no hay respuesta*/
    vector<vector<int>> res;

    while (r != 0 && d != 0 && s != 0)
    {   
        /* construccion puertas grafo */
        while (d > 0)
        {   
            int i, j;
            cin >> i >> j;
            habitaciones[i].push_back(j);
            habitaciones[j].push_back(i);
            d--;
        }
        /* construccion switches digrafo*/
        while (s > 0)
        {
            int k, l;
            cin >> k >> l;
            luces[k].push_back(l);
            s--;
        }

        /* vector de luces */
        vector<int> luces(10, 0);
        luces[0] = 1;

        /* vector res i auxiliar */
        vector<int> resi;        

        /* blank */
        cin.ignore(); 
        /* siguientes */
        cin >> r >> d >> s;
    }

    return 0;
}
