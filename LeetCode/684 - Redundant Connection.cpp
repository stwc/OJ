// Detect redundant connection(cycle) by using Union-Find Algorithm

class Solution
{
public:
    int parent[1001];

    vector<int> findRedundantConnection(vector<vector<int>> &edges)
    {
        for (int i = 0; i < edges.size() + 1; ++i)
            parent[i] = -1;
        for (int i = 0; i < edges.size(); ++i) {
            int u = edges[i][0];
            int v = edges[i][1];
            if (find(u) == find(v))
                return edges[i];
            else
                unionSets(u, v);
        }
        return vector<int>(0);
    }

    int find(int i)
    {
        if (parent[i] == -1)
            return i;
        return parent[i] = find(parent[i]);
    }

    // Without path compression
    void unionSets(int u, int v)
    {
        int a = find(u);
        int b = find(v);
        parent[a] = b;
    }
};
