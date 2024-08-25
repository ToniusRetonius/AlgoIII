#include <iostream> 
#include <vector>

using namespace std;

bool suma_subcj(vector<int> conj, int i, int j){
    if (j == 0)
    {   
        // caso base true
        // existe un conj q suma
        return true;
    }
    if (i < 0 || j < 0)
    {
        // caso base false
        // es decir que ya probaste todo y no hallaste uno que sume exactamente k
        return false;
    }
    else
    {
        // paso recursivo
        return suma_subcj(conj, i-1, j) || suma_subcj(conj, i-1, j - conj[i]);
    }   
}

int main() {
    // asignar algunos valores, unos print y chequear
    vector<int> v = {1,2,3,4,5,6,7,8,9,10};

    bool res = suma_subcj(v, v.size(), 12);
    if (res)
    {
        cout << "Existe alguno" << endl;
    }
    else
    {
        cout << "No existe ninguno" << endl;
    }
    
    return 0;
}
