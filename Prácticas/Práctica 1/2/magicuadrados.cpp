#include <bits/stdc++.h>
using namespace std;

int suma_parcial(int cuadrado[3][3], int fila, int columna){
    int sumaparcial = 0;
    for (int i = 0; i <= columna; i++)
    {
        sumaparcial += cuadrado[fila][i];
    }
    return sumaparcial;
}
void magicuadrados (int i, int j, int& suma, int cuadrado[3][3]){
    // llegamos a completar el cuadrado de orden 3
    if (i == 3 && j == 2)
    {
        // chequeamos columnas 
        int columna1;
        for (int i = 0; i < 3; i++)
        {
            columna1 += cuadrado[0][i];
        }
        int columna2;
        for (int i = 0; i < 3; i++)
        {
            columna2 += cuadrado[1][i];
        }
        int columna3;
        for (int i = 0; i < 3; i++)
        {
            columna3 += cuadrado[2][i];
        }
        if (columna1 != columna2 || columna1 != columna3 || columna2 != columna3)
        {
            return;
        }
        
        // si llegamos hasta acá es porque todas las columnas suman los mismo .. chequeamos diagonales
        int diagonal1;
        for (int i = 0; i < 3; i++)
        {
            diagonal1 += cuadrado[i][i];
        }
        int diagonal2;
        for (int i = 0; i < 3; i++)
        {
            diagonal2 += cuadrado[i][2-i];
        }
        if (diagonal1 != diagonal2)
        {
            return;
        }

        // las diagonales son iguales : bárbaro => tenemos un magicuadrado pues por regla de factibilidad ya chequeamos las filas
        suma++;
    }

    // como las columnas son un array circular : 
    if (j == 3)
    {
        // pasamos a la siguiente fila
        i++;
        j = 0;
    }
    
    
    // para el caso que sigue, el valor de fila i, 0 <= i < 3  y el valor de columna j, 0 <= j < 3

    if (suma_parcial(cuadrado, i, j) <= 15) // 15 es el número mágico
    {
        for (int valor = 1; valor < 10; valor++)
        {
            // asignamos el valor
            cuadrado[i][j] = valor;
            // chequeamos si es magicuadrado
            magicuadrados(i, j++, suma, cuadrado);
            // desasignamos 
            cuadrado[i][j] = 0;
        }
        return;
    }
    

}

int main(int argc, char const *argv[])
{   
    int suma;
	int cuadrado[3][3];
    magicuadrados(0,0,suma, cuadrado);
    cout << "La cantidad de magicudrados de orden 3 es: " + suma << endl;
    return 0;
}


// segfault