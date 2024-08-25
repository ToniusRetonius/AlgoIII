#include <iostream>
#include <vector>

using namespace std;

int INF = 1e9;

int N, P;
vector<int> p, suma_restante;

int CD(int i, int k) {
    if (k < 0)
        return -INF; 

    if (k >= suma_restante[i])
        return suma_restante[i];

    else
        return max(CD(i+1, k - p[i]) + p[i], CD(i+1, k));
}

int main() {
    cin >> N >> P;

    p.resize(N, -1);
    for (int i=0; i<N; i++) cin >> p[i];

    suma_restante.resize(N+1, 0);
    for (int i=N-1; i>=0; i--) suma_restante[i] = suma_restante[i+1] + p[i];

    cout << CD(0, P) << endl;

    return 0;
}
