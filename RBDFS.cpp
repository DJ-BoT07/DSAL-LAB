#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

void dfs(int node, vector<int> adjList[], unordered_set<int> &visited)
{
    cout << node << " ";
    visited.insert(node);

    for (int i = 0; i < adjList[node].size(); i++)
    {
        int neighbour = adjList[node][i];
        if (visited.find(neighbour) == visited.end())
        {
            dfs(neighbour, adjList, visited);
        }
    }
}

void bfs(int node, vector<int> adjList[])
{
    queue<int> q;
    unordered_set<int> visited;
    q.push(node);
    visited.insert(node);

    while (!q.empty())
    {
        int current = q.front();
        cout << current << " ";
        for (int i = 0; i < adjList[current].size(); i++)
        {
            int neighbour = adjList[current][i];
            if (visited.find(neighbour) == visited.end())
            {
                q.push(neighbour);
                visited.insert(neighbour);
            }
        }
    }
}

int main()
{
    // Number of vertices and edges
    int num_vertices, num_edges;
    cout << "Enter number of vertices: ";
    cin >> num_vertices;
    cout << "Enter number of edges: ";
    cin >> num_edges;

    // Graph representation using adjacency list as array of vectors
    vector<int> adjList[num_vertices];

    // User input for edges
    cout << "Enter edges (format: vertex1 vertex2):" << endl;
    for (int i = 0; i < num_edges; ++i) {
        int vertex1, vertex2;
        cin >> vertex1 >> vertex2;
        adjList[vertex1].push_back(vertex2);
        adjList[vertex2].push_back(vertex1); // Assuming undirected graph
    }

    // Starting node for traversal
    int start_node = 0; // Assuming starting from vertex 0

    cout << "DFS Traversal: ";
    unordered_set<int> visited;
    dfs(start_node, adjList, visited); // Starting DFS from vertex 0
    cout << endl;

    cout << "BFS Traversal: ";
    bfs(start_node, adjList); // Starting BFS from vertex 0
    cout << endl;

    return 0;
}   
