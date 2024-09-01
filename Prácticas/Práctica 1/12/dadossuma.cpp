#include <iostream>
#include <vector>

using namespace std;

// Función recursiva con memorización para dados distinguibles
int dados(int n, int suma, int k, vector<vector<int>>& memo) {
    // es posibilidad
    if (n == 0 && suma == 0)
    {
        return 1;
    }    
    // te quedaste sin dados  o la suma es menor a 0
    if (n == 0 || suma < 0)
    {
        return 0;
    }
    // si ya la calculaste
    if (memo[n][suma] != -1)
    {
        return memo[n][suma];
    }
    
    // sino, le puedo restar alguno de los resultados del primer dado
    int res = 0;
    for (int i = 1; i <= k; i++)
    {
        res += dados(n - 1, suma - i, k, memo);
    }
    memo[n][suma] = res;
    
    return res;
}

int main() {
    int n = 3, suma = 6, k = 4;

    vector<vector<int>> memo(n + 1, vector<int>(suma + 1, -1));
    int result = dados(n, suma, k, memo);

    cout << result << endl;

    return 0;
}
