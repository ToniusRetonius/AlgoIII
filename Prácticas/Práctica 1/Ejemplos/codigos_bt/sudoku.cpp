#include <iostream>
#include "sudoku_helper.c"

using namespace std;

int nodos_visitados = 0;

int N;
Tablero tablero;

bool solve_sudoku_aux(int i, int j) {
    if (i==N)
        return verificar_tablero(tablero);

    int siguiente_j = (j == N-1 ? 0 : j + 1);
    int siguiente_i = (siguiente_j == 0 ? i + 1 : i);

    if (tablero[i][j] == UNDEFINED) {

        nodos_visitados ++;

        bool resuelto = false;
        for (int k=1; k<=N; k++) {
            tablero[i][j] = k;
            resuelto = solve_sudoku_aux(siguiente_i, siguiente_j);
            if (resuelto)
                break;
        }

        if (!resuelto)
            tablero[i][j] = UNDEFINED;

        return resuelto;

    } else {
        return solve_sudoku_aux(siguiente_i, siguiente_j);
    }
}

bool solve_sudoku() {
    return solve_sudoku_aux(0, 0);
}

int main() {
    cin >> N;

    if (sqrt(N)*sqrt(N) != N) {
        cout << "La cantidad de filas / columnas debe ser un cuadrado." << endl;
        return 0;
    }

    leer_tablero(N, tablero);

    bool resuelto = solve_sudoku();

    print_resultado(tablero, resuelto, nodos_visitados);

    return 0;
}
