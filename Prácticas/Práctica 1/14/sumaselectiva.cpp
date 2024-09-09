#include <bits/stdc++.h>
using namespace std;

bool descendente(int a, int b){
    return a > b;
}

int main(){

    vector<int> conjunto = {2, 14, 5, 13, 9, 21, 25, 22, 7, 41, 1, 12, 31, 48, 4};
    
    // k < #conjunto ==> k < 15
    int k;
    printf("Ingrese un valor para k, debe ser menor a 15: ");
    scanf("%i", &k);

    if (k > 15)
    {
        perror("El número ingresado es mayor a 15\n");
        exit(-1);
    }
    
    // nos piden maximizar la suma con k elementos del conjunto
    // ordenamos de mayor a menor
    sort(conjunto.begin(), conjunto.end(), descendente);

    // tomamos los primeros k-elementos y sumamos
    int suma = 0;
    vector<int> subconjunto(k);
    for (int i = 0; i < k; i++)
    {
        suma += conjunto[i];
        subconjunto[i] = conjunto[i];
    }
    
    printf("La suma máxima lograda con %i elementos es: %i\n", k, suma);
    printf("Los elementos del subconjunto que maximizan son : ");
    for (int i = 0; i < k; i++)
    {
        cout << subconjunto[i] << " ";
    }
    cout << endl;

    return 0;
}