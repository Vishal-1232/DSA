#include <iostream>
#include <vector>
using namespace std;

// used in Dynamic Graphs to check if nodes belongs to same component or not
class DisjointSet
{
    vector<int> rank, parent , size;

public:
    DisjointSet(int n)
    {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n+1);
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
            size[i] = 1;
        }
    }
    int findParent(int node)
    {
        if (node == parent[node])
        {
            return node;
        }

        return parent[node] = findParent(parent[node]); // Path Compression
    }
    void unionByRank(int u, int v)
    {
        int ultimateParent_u = findParent(u);
        int ultimateParent_v = findParent(v);

        if (ultimateParent_u == ultimateParent_v)
        {
            return; // node u and node v belongs to same component of graph therefore no need to do union
        }

        // smaller component(in rank) is attached to larger component(rank)
        if (rank[ultimateParent_u] < rank[ultimateParent_v])
        {
            parent[ultimateParent_u] = ultimateParent_v;
            // smaller component is attached into larger one therefore no height will increse
        }
        else if (rank[ultimateParent_u] > rank[ultimateParent_v])
        {
            parent[ultimateParent_v] = ultimateParent_u;
            // smaller component is attached into larger one therefore no height will increse
        }
        else // both components of graph have equal sizes
        {
            parent[ultimateParent_v] = ultimateParent_u;
            rank[ultimateParent_u]++; // height will increase
        }
    }
    void unionBySize(int u, int v)
    {
        int ulp_u = findParent(u);
        int ulp_v = findParent(v);
        if (ulp_u == ulp_v)
            return;
        if (size[ulp_u] < size[ulp_v])
        {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else
        {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

int main()
{
    DisjointSet ds(7);
    // ds.unionByRank(1, 2);
    // ds.unionByRank(2, 3);
    // ds.unionByRank(4, 5);
    // ds.unionByRank(6, 7);
    // ds.unionByRank(5, 6);
    // // check if 3 and 7 belongs to same component at this point of time
    // if (ds.findParent(3) == ds.findParent(7))
    // {
    //     cout << "Same component nodes\n";
    // }
    // else
    // {
    //     cout << "Different components node\n";
    // }
    // ds.unionByRank(3, 7);
    // // Again check if 3 and 7 belongs to same component at this point of time
    // if (ds.findParent(3) == ds.findParent(7))
    // {
    //     cout << "Same component nodes\n";
    // }
    // else
    // {
    //     cout << "Different components node\n";
    // }

    ds.unionBySize(1, 2);
    ds.unionBySize(2, 3);
    ds.unionBySize(4, 5);
    ds.unionBySize(6, 7);
    ds.unionBySize(5, 6);
    // check if 3 and 7 belongs to same component at this point of time
    if (ds.findParent(3) == ds.findParent(7))
    {
        cout << "Same component nodes\n";
    }
    else
    {
        cout << "Different components node\n";
    }
    ds.unionBySize(3, 7);
    // Again check if 3 and 7 belongs to same component at this point of time
    if (ds.findParent(3) == ds.findParent(7))
    {
        cout << "Same component nodes\n";
    }
    else
    {
        cout << "Different components node\n";
    }

    return 0;
}