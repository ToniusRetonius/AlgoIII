#include<bits/stdc++.h>
using namespace std;
// Supposing the maximum nodes that can be present in Graph are 10^5 + 1
vector<int> nodeNeighbour[100002];
bool isVisited[100002];

void depthFirstSearch(int node)
{
	isVisited[node] = true;
	for(int n: nodeNeighbour[node])
	{
		if(!isVisited[n])
			depthFirstSearch(n);
	}
}

int main()
{
	// Number of nodes in our Graph
    int nodes;
    cin >> nodes;
	// Number of Edges in our Graph
	int edges;
    cin >> edges;
    for(int i = 0; i < nodes; i++)
    {
        isVisited[i + 1] = false;
    }
    
    // Our graph is ready by the end of this for loop
	// We have used Adjacency list to store the edges
    for(int i = 0; i < edges; i++)
    {
        int u, v;
        cin >> u >> v;
        nodeNeighbour[u].push_back(v);
        nodeNeighbour[v].push_back(u);
    }
	// Node from which we want to start Depth First Search
    int startNode;
    cin >> startNode;
    depthFirstSearch(startNode);
    int counter = 0;
    for(int i = 1; i <= nodes; i++) {
    	if(!isVisited[i])
    		counter++;
    }
    cout << counter << endl;
    return 0;
}