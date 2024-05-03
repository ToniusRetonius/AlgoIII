#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    vector<long long> resultados;

    while (true) {
        int habitantes;
        cin >> habitantes;
        
        /* si es 0, break */
        if (habitantes == 0)
            break;
        
        vector<int> demanda(habitantes);
        
        /* capturo data */
        for (int i = 0; i < habitantes; i++)
            cin >> demanda[i];
        
        long long suma = 0;
        long long demanda_acumulada = 0;

        /* como la línea da 0, voy acumulando demanda y tomando valor absoluto*/
        for (int i = 0; i < habitantes; i++) {
            demanda_acumulada += demanda[i];
            suma += abs(demanda_acumulada);
        }
        /* acumulo las sumas */
        resultados.push_back(suma);
    }

    /*  Imprimo los resultados al final */
    for (int i = 0; i < resultados.size(); i++) {
        cout << resultados[i] << endl;
    }
    
    return 0;
}
