#include <iostream>
#include <vector>

using namespace std;

int INF = 1e9;

int N, P;
vector<int> p;

int CD(int i, int k) {
    if (i == N)
        return (k < 0 ? -INF : 0);
    else
        return max(CD(i+1, k - p[i]) + p[i], CD(i+1, k));
}

int main() {
    cin >> N >> P;

    p.resize(N, -1);
    for (int i=0; i<N; i++) cin >> p[i];

    cout << CD(0, P) << endl;

    return 0;
}
