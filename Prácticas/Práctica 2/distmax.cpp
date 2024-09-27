#include <bits/stdc++.h>
using namespace std;

class Nodo {
public:
    int valor;
    Nodo* izq;
    Nodo* der;

    Nodo(int v) {
        valor = v;
        izq = NULL;
        der = NULL;
    }
};

class ArbolBinario {
public:
    Nodo* raiz;

    ArbolBinario() {
        raiz = NULL;
    }

    Nodo* agregarNodo(Nodo* nodo, int valor) {
        if (nodo == NULL) {
            return new Nodo(valor);
        }
        if (valor < nodo->valor) {
            nodo->izq = agregarNodo(nodo->izq, valor);
        } else {
            nodo->der = agregarNodo(nodo->der, valor);
        }
        return nodo;
    }

    void agregar(int valor) {
        raiz = agregarNodo(raiz, valor);
    }

    int dismax(Nodo* nodo, int& max_dist) {
        if (nodo == NULL) return 0; 

        int alt_izq = dismax(nodo->izq, max_dist);
        int alt_der = dismax(nodo->der, max_dist);

        max_dist = max(max_dist, alt_izq + alt_der);

        return 1 + max(alt_izq, alt_der);
    }

    int distanciaMaxima() {
        int max_dist = 0;
        dismax(raiz, max_dist);
        return max_dist;
    }
};

int main() {
    ArbolBinario arbol;

    arbol.agregar(1);
    arbol.agregar(7);

    int distancia = arbol.distanciaMaxima();
    cout << "La distancia máxima entre un par de nodos es: " << distancia << endl;

    return 0;
}
