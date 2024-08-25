#include <bits/stdc++.h>
using namespace std;

struct Pago {
    int exceso;              
    int cantidadBilletes;       
};

void optipago(vector<int>& conjunto, int indice, int costo, vector<Pago>& soluciones, int billetes){
    
    // si el costo es 0 o menor a cero es porque ya conseguimos cierta combinación de billetes para pagar
    if (costo <= 0)
    {
        Pago solucion;
        solucion.exceso = costo;
        solucion.cantidadBilletes = billetes;
        soluciones.push_back(solucion);
        return;
    }

    // si me quedo sin valores
    if (indice < 0) {
        return;
    }

    // sino, tenemos que recursivamente hallar la manera de pagar : 
    // sin usar el billete
    optipago(conjunto, indice - 1, costo, soluciones, billetes);
    // usando el billete
    optipago(conjunto, indice - 1, costo - conjunto[indice], soluciones, billetes + 1);

}  


int main(){
    // los billetes que tengo en el bolsillo (es multiconjunto)
    vector<int> conjunto = {2,3,5,10,20,20};
    // costo del artículo
    int costo = 14;
    // indice
    int indice = conjunto.size() - 1;
    // juntamos todas las soluciones 
    vector<Pago> soluciones;

    // llamamos a optipagos
    optipago(conjunto, indice, costo, soluciones, 0);

    for (int i = 0; i < soluciones.size(); i++)
    {
        cout << "Esta solución tuvo exceso de " << soluciones[i].exceso << " y la cantidad de billetes utilizada fue: " <<  soluciones[i].cantidadBilletes << endl;
    }
    
    return 0;
}
// d )
// si uso un vector para guardar, por ejemplo en la iésima posición quiere decir que usando i-billetes tengo tal exceso
// para este ejemplo, tomamos el máximo de los resultado pues es el más cercano a cero el q nos interesa
// vector<int> resultados = {0, -6, -1, -1 }