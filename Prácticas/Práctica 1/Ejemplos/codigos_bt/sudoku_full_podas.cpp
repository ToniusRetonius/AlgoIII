#include <iostream>
#include <utility>
#include "sudoku_helper.c"

using namespace std;

int nodos_visitados = 0;
int INF = 1e9;

int N; int sqrtN;
Tablero tablero;

pair<int, int> mejor_casillero_para_expandir() {
    int mejor_i, mejor_j, mejor_cnt; 
    mejor_i = mejor_j = -1; mejor_cnt = INF;

    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            if (tablero[i][j] == UNDEFINED) {
                vector<int> candidatos = candidatos_para(tablero,i,j);
                if (candidatos.size() < mejor_cnt) {
                    mejor_i = i; mejor_j = j; mejor_cnt = candidatos.size();
                }
            }
        }
    }

    return {mejor_i, mejor_j};
}

bool solve_sudoku() {
    pair<int, int> pos = mejor_casillero_para_expandir();
    int i = pos.first; int j = pos.second;

    if (i == -1) {
        return true;
    }

    nodos_visitados++;

    bool resuelto = false;
    for (int k : candidatos_para(tablero, i, j)) {
        tablero[i][j] = k;
        resuelto = solve_sudoku();
        if (resuelto)
            break;
    }

    if (!resuelto)
        tablero[i][j] = UNDEFINED;

    return resuelto;
}

int main() {
    cin >> N;

    if (sqrt(N)*sqrt(N) != N) {
        cout << "La cantidad de filas / columnas debe ser un cuadrado." << endl;
        return 0;
    }

    sqrtN = sqrt(N);

    leer_tablero(N, tablero);

    bool resuelto = solve_sudoku();

    print_resultado(tablero, resuelto, nodos_visitados);

    return 0;
}
