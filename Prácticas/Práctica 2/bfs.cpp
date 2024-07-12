#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// Function to perform Breadth First Search on a graph
// represented using adjacency list
void bfs(vector<vector<int> >& adjList, int startNode, vector<bool>& visited)
{
    // Create a queue for BFS
    queue<int> q;

    // Mark the current node as visited and enqueue it
    visited[startNode] = true;
    q.push(startNode);

    // Iterate over the queue
    while (!q.empty()) {
        // Dequeue a vertex from queue and print it
        int currentNode = q.front();
        q.pop();
        cout << currentNode << " ";

        // Get all adjacent vertices of the dequeued vertex
        // currentNode If an adjacent has not been visited,
        // then mark it visited and enqueue it
        for (int neighbor : adjList[currentNode]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}

// Function to add an edge to the graph
void addEdge(vector<vector<int> >& adjList, int u, int v)
{
    adjList[u].push_back(v);
}

int main()
{
    // Number of vertices in the graph
    int vertices = 5;

    // Adjacency list representation of the graph
    vector<vector<int> > adjList(vertices);

    // Add edges to the graph
    addEdge(adjList, 0, 1);
    addEdge(adjList, 0, 2);
    addEdge(adjList, 1, 3);
    addEdge(adjList, 1, 4);
    addEdge(adjList, 2, 4);

    // Mark all the vertices as not visited
    vector<bool> visited(vertices, false);

    // Perform BFS traversal starting from vertex 0
    cout << "Breadth First Traversal starting from vertex " "0: ";
    bfs(adjList, 0, visited);

    return 0;
}
// https://www.geeksforgeeks.org/breadth-first-search-or-bfs-for-a-graph/
// O(|V| + |E|)
// The time complexity of BFS is O(V + E), where V is the number of vertices and E is the number of edges in the graph. 
// The space complexity of BFS is O(V), as it uses a queue to keep track of the vertices that need to be visited. 
// BFS is simple to implement and efficient for finding the shortest path in an unweighted graph. It also guarantees that all the vertices in the graph are visited. 
