#include <iostream>
#include <vector>
#include <queue>
#include <limits>
using namespace std;

class Pair
{
public:
    int v, wt;
    Pair(int v, int wt)
    {
        this->v = v;
        this->wt = wt;
    }
    bool operator<(const Pair &p2) const
    {
        return wt > p2.wt;
    }
};

void createGraph(vector<pair<int, int>> graph[], int numCities)
{
    cout << "Cost Matrix:\n"
         << endl;
    for (int i = 0; i < numCities; ++i)
    {
        for (int j = i + 1; j < numCities; ++j)
        {
            int cost;
            cout << "Enter the cost for  " << i + 1 << "-" << j + 1 << ": ";
            cin >> cost;
            // Add directed edges from i to j
            if (cost != -1)
            {
                graph[i].push_back({j, cost});
                graph[j].push_back({i, cost});
            }
        }
    }
}

int primsAlgo(vector<pair<int, int>> graph[], int numCities){
    vector<bool> vis(numCities, false);
    priority_queue<Pair> pq;
    pq.push(Pair(0, 0));
    int cost = 0;
    while(!pq.empty()){
        Pair curr = pq.top();
        pq.pop();
        int v = curr.v;
        int wt = curr.wt;
        if (!vis[v]){
            vis[v] = true;
            cost += wt;
            for (int i = 0; i < graph[v].size(); i++)
            {
                int u  = graph[v][i].first;
                int weight  = graph[v][i].second;
                if(!vis[u]){
                    pq.push(Pair( u, weight));
                }
            }
            
        }
    }
    return cost;
}

int main()
{
    int numCities;
    cout << "Enter the number of cities: ";
    cin >> numCities;

    vector<pair<int, int>> graph[numCities];
    createGraph(graph, numCities);

    int totalCost = primsAlgo(graph, numCities);
    cout << "Minimum total cost to connect all offices: " << totalCost << endl;
    return 0;
}