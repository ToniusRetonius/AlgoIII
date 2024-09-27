#include <bits/stdc++.h>
using namespace std;

int potencialog(int a, int b){
    // caso base
    if (b == 1)
    {
        return a;
    }
    // sino
    else
    {
        if (b % 2 == 0)
        {
            // si el exponente es par =>
            return potencialog(a, b/2) * potencialog(a, b/2);
        }
        else
        {
            // si el exponente es impar =>
            return a * potencialog(a,b/2) * potencialog(a,b/2);
        }
        
    }
    
    
}



int main(){

    int a,b;
    cin >> a >> b;

    int res = potencialog(a,b);
    cout << res << endl;
    return 0;
}