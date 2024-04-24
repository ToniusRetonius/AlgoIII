/* liberia clasica de input output */
#include <iostream>

void suma(int n){
    int suma = 0;
    for (int i = 0; i < n; i++)
    {
        suma += i;
    }
    std::cout << suma << std::endl;
    
}

int main() {
    /* el objeto std :: cout esta definido en la libreria */
    /* es el standard output stream */
    std::cout << "Hello, World!" << std::endl;
    /*  tenemos << operador de insercion */
    /* std:endl es un valor para hacer un salto luego de la impresion */

    suma(15);
    return 0;
}
