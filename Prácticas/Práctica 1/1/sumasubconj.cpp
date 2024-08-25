#include <bits/stdc++.h>
using namespace std;

void subsetsum(int i, int size, int conj[], int suma, vector<int>& subconj){
	// si todo sale joya
	if (suma == 0){
		// imprimimos el subconjunto que suma de pe a pa
		cout << "[";
		for (int i = 0; i < subconj.size(); i++){
			cout << subconj[i] << " ";
		}
		cout << "]";
		return;
	}

	// si todo sale mal, es decir que no pudimos obtener un subconjunto que sume
	if (i == size){
		return;
	}

	// si queremos buscar, la lógica que seguimos es :
	// 1 ) no agregamos al elemento iésimo
	subsetsum(i+1, size, conj, suma, subconj);

	// 2 ) con la regla de factibilidad de backtracking, <==> el elemento es menor o igual a la suma
	if (conj[i] <= suma){
		// se agrega al subconj el elemento
		subconj.push_back(conj[i]);
		// recursión
		subsetsum(i+1, size, conj, suma - conj[i], subconj);
		// importante : tenemos que restaurar el subconj
		subconj.pop_back();
	}
}

int main(int argc, char const *argv[])
{
	int conjunto[]	= {1,2,3,4,5,6,7,8,9};
	int size = 9;
	int suma = 16;
	vector<int> subconj;
	subsetsum(0, size, conjunto, suma, subconj);
	cout << endl;
		
	return 0;
}
