#include <bits/stdc++.h>
using namespace std;


void astrotrade(vector<int>& conjunto_p, int indice, int asteroides, int ganancia, vector<int>& soluciones){
    // si ya no hay más días
    if (indice == conjunto_p.size())
    {
        // agregas la solución y se termina
        soluciones.push_back(ganancia);
        return;
    }
    
    // no puedo tener asteroides negativos ni ganancia negativa
    if (asteroides < 0)
    {
        return;
    }

    // si tengo asteroides en mi poseción podría vender 
    if (asteroides > 0)
    {
        // decido no comprar ni vender
        astrotrade(conjunto_p, indice + 1, asteroides, ganancia, soluciones);   
        // decido comprar 
        astrotrade(conjunto_p, indice + 1, asteroides + 1, ganancia - conjunto_p[indice], soluciones);   
        // decido vender y tomar ganancias
        astrotrade(conjunto_p, indice + 1, asteroides - 1, ganancia + conjunto_p[indice], soluciones);   
    }
    // si no tengo asteroides en mi poseción
    else if (asteroides == 0)
    {
        // puedo decidir comprar
        astrotrade(conjunto_p, indice + 1, asteroides + 1, ganancia - conjunto_p[indice], soluciones);   
        // o puedo decidir no hacer nada
        astrotrade(conjunto_p, indice + 1, asteroides, ganancia, soluciones);   
        
    }
    
}

int main(){

    // definimos los conjuntos
    vector<int> conjunto1 = {3,2,5,6};
    vector<int> conjunto2 = {3,6,10};

    // declaramos el vector de soluciones
    vector<int> soluciones1;
    vector<int> soluciones2;

    // llamamos a las funciones
    astrotrade(conjunto1, 0, 0, 0, soluciones1);
    astrotrade(conjunto2, 0, 0, 0, soluciones2);

    // calculamos la máxima ganancia
    int max1 = soluciones1[0];
    int max2 = soluciones2[0];

    for (int i = 1; i < soluciones1.size(); i++)
    {
        if (max1 < soluciones1[i])
        {
            max1 = soluciones1[i];
        }
    }
    
    for (int i = 0; i < soluciones2.size(); i++)
    {
        if (max2 < soluciones2[i])
        {
            max2 = soluciones2[i];
        }
        
    }

    // vemos los resultados
    cout << max1 << endl;
    cout << max2 << endl;

    return 0;
}