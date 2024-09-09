#include <bits/stdc++.h>
using namespace std;

int parejas(vector<int> hombres, vector<int> mujeres){
    int i = 0;
    int j = 0;
    int res = 0;
    while (i < hombres.size() && j < mujeres.size())
    {
        if ((hombres[i] - mujeres[j] % 10) <= 1)
        {
            res++;
            i++;
            j++;
        }
        // si el tipo baila mejor
        if (hombres[i] > mujeres[j])
        {
            i++;
        }
        // si la mina baila mejor
        if (hombres[i] < mujeres[j])
        {
            j++;
        }
    }

    return res;
}


int main(){

    // desordenados a proṕosito
    vector<int> hombres = {1,4,2,6};
    vector<int> mujeres = {5,5,7,9,1};

    // los ordeno
    sort(hombres.begin(), hombres.end());
    sort(mujeres.begin(), mujeres.end());
    
    // res
    int res = parejas(hombres, mujeres);
    cout << "La cantidad máxima de parejas que se pueden formar son: " << res << endl;
    return 0;
}