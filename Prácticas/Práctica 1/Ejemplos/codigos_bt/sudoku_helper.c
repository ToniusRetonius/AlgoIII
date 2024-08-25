#ifndef SUDOKU_HELPER_H_
#define SUDOKU_HELPER_H_

#include <iostream>
#include <vector>
#include <math.h>

using namespace std;
using Tablero = vector<vector<int> >;

int UNDEFINED = 0;

// Lee de consola un tablero de N*N
void leer_tablero(int N, Tablero& tablero) {
    tablero = Tablero(N, vector<int>(N));

    for (int i=0; i<N; i++)
        for (int j=0; j<N; j++)
            cin >> tablero[i][j];
}

// Imprime por consola el tablero.
// Intenta hacerlo bonito
void print_tablero(Tablero& tablero) {
    int N = tablero.size();
    int sqrtN = sqrt(N);

    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            if (j%sqrtN == 0 && j != 0) {
                cout << "| ";
            }
            cout << tablero[i][j] << " ";
        }
        cout << endl;
        if (i%sqrtN==sqrtN-1 && i != N-1) {
            for (int k=0; k<12*sqrtN - 15; k++) {
                cout << "-";
            }
            cout << endl;
        }
    }
}

// Verifica que las filas del tablero esten bien
bool verificar_filas(Tablero& tablero) {
    int N = tablero.size();

    for (int i=0; i<N; i++) {
        vector<bool> bitset(N+1, false); int cnt = 0;
        for (int j=0; j<N; j++) {
            if (!bitset[tablero[i][j]]) {
                bitset[tablero[i][j]] = true;
                cnt++;
            }
        }
        if (cnt < N)
            return false;
    }
    
    return true;
}

// Verifica que las columnas del tablero esten bien
bool verificar_columnas(Tablero& tablero) {
    int N = tablero.size();

    for (int i=0; i<N; i++) {
        vector<bool> bitset(N+1, false); int cnt = 0;
        for (int j=0; j<N; j++) {
            if (!bitset[tablero[j][i]]) {
                bitset[tablero[j][i]] = true;
                cnt++;
            }
        }
        if (cnt < N)
            return false;
    }
    
    return true;
}

// Verifica que los subcuadrados del tablero esten bien
bool verificar_subcuadrados(Tablero& tablero) {
    int N = tablero.size();
    int sqrtN = sqrt(N);

    for (int i=0; i<N; i += sqrtN) {
        for (int j=0; j<N; j += sqrtN) {
            vector<bool> bitset(N+1, false); int cnt = 0;
            for (int ii=0; ii<sqrtN; ii++) {
                for (int jj=0; jj<sqrtN; jj++) {
                    if (!bitset[tablero[i + ii][j + jj]]) {
                        bitset[tablero[i + ii][j + jj]] = true;
                        cnt++;
                    }
                }
            } 
            if (cnt < N)
                return false;
        }
    }
    
    return true;
}

// Verifica que el tablero sea correcto
bool verificar_tablero(Tablero& tablero) {
    return verificar_filas(tablero) && verificar_columnas(tablero) && verificar_subcuadrados(tablero);
}

void print_resultado(Tablero& tablero, bool resuelto, int nodos_visitados) {
    if (resuelto) {
        cout << endl;
        cout << "Se pudo resolver el sudoku:" << endl << endl;
        print_tablero(tablero);
    } else {
        cout << "No se encontro solucion" << endl;
    }

    cout << endl << "Se recorrieron " << nodos_visitados << " nodos." << endl;
}

void recorrer_fila(Tablero& tablero, vector<bool>& valido, int i) {
    for (int j=0; j<tablero.size(); j++)
        valido[tablero[i][j]] = false;
}

void recorrer_columna(Tablero& tablero, vector<bool>& valido, int j) {
    for (int i=0; i<tablero.size(); i++)
        valido[tablero[i][j]] = false;
}

void recorrer_subcuadrado(Tablero& tablero, vector<bool>& valido, int i, int j) {
    int sqrtN = sqrt(tablero.size());
    int primer_i = i - i%sqrtN; int primer_j = j - j%sqrtN;

    for (int ii=0; ii<sqrtN; ii++) 
        for (int jj=0; jj<sqrtN; jj++)
            valido[tablero[primer_i + ii][primer_j + jj]] = false; 
}

vector<int> candidatos_para(Tablero& tablero, int i, int j) {
    vector<bool> valido(tablero.size()+1, true);

    recorrer_fila(tablero, valido, i);
    recorrer_columna(tablero, valido, j);
    recorrer_subcuadrado(tablero, valido, i, j);

    vector<int> disponibles(0);
    for (int k=1; k<valido.size(); k++)
        if (valido[k])
            disponibles.push_back(k);

    return disponibles;
}

#endif
