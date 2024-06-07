#include <iostream>
#include <vector>

using namespace std;

int main()
{   
    /* capturamos input */
    int casos; 
    cin >> casos;
    
    vector<int> resultados;

    for (int i = 0; i < casos; i++)
    {
        /* cantidad de locks */
        vector<vector<int>> grafo;
        
        /* lock 0000 */
        vector<int> lock0;
        lock0.push_back(0000);
        grafo.push_back(lock0);

        /* input */
        int longitud;
        cin >> longitud;

        /* tengo toda la linea de input */
        for (int j = 0; j < longitud; i++)
        {
            vector<int> lockj;
            int lockk;
            cin >> lockk;
            lockj.push_back(lockk);
            grafo.push_back(lockj);
        }
        
        // Mostrar el contenido del grafo
        for (int m = 0; m < grafo.size(); m++) {
            for (int n = 0; n < grafo[m].size(); n++) {
                cout << grafo[m][n] << " ";
            }
            cout << endl;
        }
        
        

    }
    
    return 0;
}