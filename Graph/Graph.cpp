#include <iostream>
#include <unordered_map>
#include <list>
using namespace std;

class Graph
{
private:
    int n;                             // no of nodes
    int m;                             // no of edges
    unordered_map<int, list<int>> adj; // Adjacency List
public:
    Graph()
    {
        cout << "Enter number of nodes : ";
        cin >> n;
        cout << "\nEnter number of edges : ";
        cin >> m;

        for (int i = 0; i < m; i++)
        {
            int u, v;
            cin >> u >> v;
            addEdge(u, v, 0); // creating undirected graph
        }
    }
    void addEdge(int u, int v, bool direction)
    {
        // dir-0 == Undirected Graph , dir-1 == Directed graph
        adj[u].push_back(v);
        if (direction == 0)
        {
            adj[v].push_back(u);
        }
    }
    void printAdjList()
    {
        for (auto it : adj)
        {
            cout << it.first << " -> ";
            for (auto j : it.second)
            {
                cout << j << ", ";
            }
            cout << endl;
        }
    }
};

int main()
{
    Graph g;
    g.printAdjList();
    return 0;
}